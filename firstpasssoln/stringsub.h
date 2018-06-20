#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <cstring>
#include "TrackingDeque.h"
using namespace std;

class stringsub
{
public:
  stringsub(string,string,string);
  ~stringsub();
  void scenario();
  void replace_equal();
  void replace_small();
  void replace_big();
  void trun_str();
  bool checking( int case1);
  void resubstitute();
  void traverse();
  void substitute();
private:
  string file_name;
  string replace_str;
  string search_str;
  int search_size;
  int replace_size;
  int match;
  int flag;
  int getpos;
	int putpos;
  int count;
  char ch;
  fstream ifile;

};
