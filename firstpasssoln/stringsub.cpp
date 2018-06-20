#include "stringsub.h"
using namespace std;

	stringsub::stringsub(string old_str, string new_str, string filenm)
:file_name(filenm),search_str(old_str),replace_str(new_str),match(0),getpos(0)
,putpos(0),flag(0),
search_size(search_str.size()),replace_size(replace_str.size())
{
  //constructor and inilization list
	ifile.open(file_name,std::ios::out|std::ios::in); //opening file
	scenario();
}
stringsub::~stringsub()
{
  //destructor
}
void stringsub::scenario()
{
	if(search_str.size() == replace_str.size())
  {
    replace_equal();
  }
	else if(search_str.size() > replace_str.size())
  {
    replace_small();
  }
	else if(search_str.size() < replace_str.size())
  {
    replace_big();
  }
}//end of scenario

void stringsub::replace_equal()
{
	if (ifile.is_open()) //check whether file is open
	{
		getpos=putpos=ifile.tellg(); //get pos of current char
		while(ifile)
		{
			flag=0;
			ch=ifile.get();
			if(ch==search_str[0])   //if the first char matches
			{

				if(search_str.size()==1) //if the size  is 1
				{
          //replace char
					ch=replace_str[0];

					putpos=getpos;
					ifile.clear();

          //get pos of next char
					ifile.seekp(putpos);

          //write to file
					ifile<<ch;
				}
				else
				{
					if(checking(1))
					{
						substitute(); //calling replace func
					}
					if(match < search_size)
					{
						resubstitute(); //calling resubstitute func
					}
				}
			}//end of if
			if(!flag)//flag  to move  getpos
			{
				++getpos;
			}
			ifile.seekg(getpos);
			ifile.seekp(getpos);
		}//end of while
		ifile.clear();
	}
	match=0;
}//end of replace_equal

bool stringsub::checking(int case1)
{
  	int temp=0;//for traversing across serach string
	if(case1==1)
	{
		putpos=getpos;
	}
  while(ch == search_str[temp] && match < search_size)
  {
    ++temp;
    ++match;
    ++getpos;
    ch=ifile.get();
  }
	if (match == search_size)
	{
		return true;
	}
	else
  {
		return false;
	}
}//end of checking

void stringsub::substitute()
{
	int a=0;//for traversing across replacing string
	while(replace_size)
	{
    //iterating
	  ch=replace_str[a];
	  ifile.clear();
    //get next char to be replace
	  ifile.seekp(putpos);
    //writing to file
	  ifile<<ch;
    //appending null char at the end
	  ch='\0';
	  ++putpos;
	  ++a;//incrementing pos
    //decremeting size
	  --replace_size;
	}
	match=0;
	flag=1;
	return;
}//end of substitute

void stringsub::resubstitute()
{
	int b=0;
	while (match)
	{
		ifile.clear();
    //get pos of next char to be replace
		ifile.seekp(putpos);
		ch=search_str[b];
    //writing to file
		ifile<<ch;
    //adding null
		ch='\0';
    //incrementing pos
    //decrementing size
		++putpos;
		--match;
		++b;
	}
	flag=1;
	match=0;
	return;
}//end of resubstitute

void stringsub::replace_small()
{
	match=0;
	if (ifile.is_open())//file open
	{
    //tell pos of current char
		getpos=putpos=ifile.tellg();
		while(ifile.good())
		{
			flag=0;
			ch=ifile.get();
			if(ch==search_str[0])   //if the first char  matches
			{
				if(checking(0))
				{
					substitute();
          //adjusting new size
					replace_size=replace_str.size();
					count=0;
				}
				if(match < search_size)
				{
					resubstitute();
				}
			}
			traverse();
			++count;
		}
		trun_str();
	}
}//end of replace small

void stringsub::traverse()
{
  //sets pos to next char in input stream
	ifile.seekg(getpos);

	ch=ifile.get();

  //sets pos to next char in replace stream
	ifile.seekp(putpos);

  //writing to file
	ifile<<ch;
  //insering null at the end
	ch='\0';

	if(!flag)
	{
	  ++getpos;
	  ++putpos;
	}
	ifile.seekg(getpos);
}//end of traverse

void stringsub::trun_str()
{
  //creating temp buffer
	char *trun_buffer = new char [file_name.size() + 1];

	strcpy(trun_buffer, file_name.c_str());

//putting extra in buffer
	if(count==1)
	{
		truncate(trun_buffer,(putpos));
	}
	else
	{
		truncate(trun_buffer,(putpos-1));
	}
	delete trun_buffer;
}//end of trun_str

void stringsub::replace_big()
{
	match=0;
  //creating deque buffer
	TrackingDeque<char> deque_buffer;
  //difference between the strings
	int diff = replace_size - search_size;
	if (ifile.is_open())
	{
    //tells pos of current char
		getpos=putpos=ifile.tellg();

		while(ifile.good())
		{
			flag=0;
			ch=ifile.get();
			if(ch==search_str[0])   //if the first char matches
			{
				if(checking(0))
				{
					int di=diff;
          //iterating by difference in size
					while(di)
					{
            //pushing in buffer
						deque_buffer.push_back(ch);
						++getpos;

						ifile.seekg(getpos);
						ch=ifile.get();
						--di;
					}
					substitute();
					replace_size = replace_str.size();
					count=0;
				}
				if(match < search_size)
				{
					resubstitute();
				}
			}
      //if buffer no empty
			if(!deque_buffer.empty())
			{
				if(!flag)
				{
					++getpos;
					++putpos;
				}
        //getting the char at front
				ch=deque_buffer.front();
        //popping front char
				deque_buffer.pop_front();

        //sets pos to next char in input stream
				ifile.seekg(getpos);
        //pushing the current char so only one deque element is used
				deque_buffer.push_back(ifile.get());
        //sets pos to next char in output stream
				ifile.seekp(putpos);
				ifile<<ch;
			}
			else
			{
					traverse();
			}
			++count;
		}//end of while
		if(count!=1)
		{
			ifile.clear();
			ifile.seekp(putpos);
			ifile<<ch;
		}
	}
}//end of replace_big
