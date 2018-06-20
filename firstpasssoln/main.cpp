#include "stringsub.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  try
  {
    if(argc = 3)
    {
  string old_string = argv[1];
  string new_string = argv[2];
  string filename   = argv[3];
  //cout <<"1:"<<old_string<<endl;
  //cout <<"2:"<<new_string<<endl;
  //cout <<"3:"<<filename<<endl;

  //(old_string,new_string,filename)
  stringsub ss(old_string, new_string, filename);
  }
}
  catch(...)
  {
    cerr<<"invalid agrument"<<endl;
  }


return 0;
}
