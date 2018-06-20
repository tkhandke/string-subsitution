#include "StreamSource.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 4)
  {
    cout<<"Not enough arguments: "<< (argc-1) <<endl;
    return -1;
  }
  StreamSource ss ((string)argv[1], (string)argv[2], (string)argv[3]);
  //(search string,replace string, filename);
  return 0;
}
