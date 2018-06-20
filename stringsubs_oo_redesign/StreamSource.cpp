#include "StreamSource.h"
using namespace std;

//constructor and initaiztion list
StreamSource::StreamSource(string old_str, string new_str, string filename):
replace_string(new_str),search_str(old_str),file_name(filename),
replacement_count(0),matching_count(0),search_str_Len(0),search_count(0)
{
	//opening file in constructor
	ifile.open(file_name,std::ios::in | std::ios::out);
	change();
}

//destructor
StreamSource::~StreamSource()
{
		char *del_temp = new char [file_name.size() + 1];
		strcpy(del_temp, file_name.c_str());
		truncate(del_temp,(ifile.put_pos));
		delete del_temp;
}

StreamSource& StreamSource::get(char& ch)
{
	if(replacement_count > 0)
		{
			ch = replace_string[replace_string.size() - replacement_count--];
			//flag of getting char from replace str
			replace_flag = true;
		}
		else if(search_count > 0)
		{
			ch = search_str[search_str_Len  - search_count--];
			//flag of getting char from  search str
			search_flag = true;
		}
		else
		{
			ifile.get(ch);
			//no char match so no geting
			replace_flag = search_flag =false;
		}
		return *this;
}//end of get


void  StreamSource::found_partial_match_(char ch)
{
	if(search_flag)
		{
			++search_origin;
		}
		else
		{
			search_str_Len = matching_count;
			search_origin = 0;
			ifile.push_front_q(ch);
		}
		ifile.put(search_str[search_origin]);
		//start str  search again
		search_count = search_str_Len - 1 - search_origin;
}//end of found_partial_match_

bool StreamSource::get_current_replacing()
{
	return replace_flag;
}//end of get_current_replacing

void StreamSource::change()
{
	matching_count=0;
	int search_str_Len = search_str.size();

		while(!get(ch).eof())
		{
			if(ch == search_str[matching_count] && !(get_current_replacing()))
			{
				++matching_count;
				if(matching_count < search_str_Len)
				{
					continue;
				}
			}
			if(matching_count == search_str_Len) //string length  exact matched
			{
				change_size();
			}
			else if(matching_count > 0) //partial match
			{
				found_partial_match_(ch);
			}
			else
			{
				ifile.put(ch);
			}
			matching_count=0;
		}//end of while
}//end of change

void StreamSource::change_size()
{
	replacement_count = replace_string.size();
}//end of change_size

bool StreamSource::eof()
{
	if(replace_flag || search_flag)
	{
		return false;
	}
	else
	{
		return ifile.eof1(); //this eof1 in streamWrapper
	}
}//end of eof
