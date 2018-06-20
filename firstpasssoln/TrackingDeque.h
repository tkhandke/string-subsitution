#include <iostream>
#include <deque>
using namespace std;

template<class MyType>
class TrackingDeque: public deque<MyType>
{
	public:
		TrackingDeque();
		~TrackingDeque();
    void push_back(const MyType&);
		void push_front(const MyType&);
    void pop_back();
    void pop_front();

  private:
    int max_size;
};

template<class MyType>
TrackingDeque<MyType>::TrackingDeque()
{
     max_size= 0;
}

template<class MyType>
TrackingDeque<MyType>::~TrackingDeque()
{
  cout<<"-->"<<max_size<<"<--"<<endl;
}

template<class MyType>
void TrackingDeque<MyType>:: push_back(const MyType& value)
{
deque<MyType>::push_back(value);
++max_size;
}

template<class MyType>
void TrackingDeque<MyType>:: push_front(const MyType& value)
{
  deque<MyType>::push_front(value);
  ++max_size;
}


template<class MyType>
void TrackingDeque<MyType>:: pop_back()
{
  deque<MyType>::pop_back();
  --max_size;
}


template<class MyType>
void TrackingDeque<MyType>:: pop_front()
{
  deque<MyType>::pop_front();
  --max_size;
}

/*int main()
{
  TrackingDeque<char> mybuffer;
  mybuffer.push_front('A');
  mybuffer.push_back('B');
  cout << "Front of deque is: " << mybuffer.front() << endl;
  mybuffer.pop_front();
  cout << "Front of deque is: " << mybuffer.front() << endl;
  mybuffer.pop_front();
return 0;
}
*/
