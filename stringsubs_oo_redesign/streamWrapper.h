#ifndef STREAMWRAPPER_H
#define STREAMWRAPPER_H

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "TrackingDeque.h"
using namespace std;

class streamWrapper : public fstream
{
public:
  streamWrapper();
  ~streamWrapper();
  streamWrapper& get(char& ch);
	void put(char ch);
  void push_front_q(char ch);
	bool eof1();
  int put_pos;
private:
  int  get_pos;
	bool internally_hit_eof;
	TrackingDeque<char> deck;
  char ch;
};
#endif
