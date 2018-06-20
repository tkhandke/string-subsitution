#ifndef STREAMSOURCE_H
#define	STREAMSOURCE_H

#include "streamWrapper.h"
#include <cstring>
#include <unistd.h>
using namespace std;

class StreamSource
{
public:
	StreamSource(string, string, string);
	~StreamSource();
	StreamSource& get(char& ch);
	void found_partial_match_(char ch);
	bool get_current_replacing();
	void change();
	void change_size();
	bool eof();

	private:
		char ch;
		int  replacement_count;
		int  search_count;
		int  search_str_Len;
		int search_origin;
		int matching_count;
		string search_str;
		string replace_string;
		string file_name;
		bool search_flag;
		bool replace_flag;
		streamWrapper ifile;

};
#endif
