
#include "streamWrapper.h"
using namespace std;

//constructor and iniliaztion list
streamWrapper::streamWrapper():put_pos(0),get_pos(0),
internally_hit_eof(false)
{

}

//destructor
streamWrapper::~streamWrapper()
{
	fstream::close();
}


streamWrapper& streamWrapper::get(char &ch)
{
	if(!deck.empty())
	{
		ch=deck.front();
		deck.pop_front();
		return *this;
	}

	fstream::seekg(get_pos);
	ch=fstream::get();

	if(fstream::eof())
	{
		fstream::clear();
		internally_hit_eof = true;
	}

	get_pos++;
	return *this;
}


void streamWrapper::put(char ch)
{

	if(put_pos >= get_pos && !internally_hit_eof)
	{
		fstream::seekg(get_pos);
		deck.push_back(fstream::get());

		if(fstream::eof())
		{
			fstream::clear();
			internally_hit_eof = true;
		}
		get_pos++;
	}
	fstream::seekp(put_pos);
	fstream::put(ch);
	put_pos++;

}


void streamWrapper::push_front_q(char ch)
{
	deck.push_front(ch);
}


bool streamWrapper::eof1()
{
	if(!deck.empty())
	{
		return false;
	}
	else
	{
		return internally_hit_eof;
	}
}
