CXX = g++
CXXFLAGS = -c -g -std=c++11

PROG = a.out
HDRS = StreamSource.h TrackingDeque.h streamWrapper.h
SRCS = main.cpp StreamSource.cpp streamWrapper.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROG) : $(OBJS)
	$(CXX)  $(OBJS) -o $(PROG)


streamwrapper.o:streamWrapper.cpp
		$(CXX) $(CXXFLAGS) streamWrapper.cpp

main.o :main.cpp
		$(CXX) $(CXXFLAGS) main.cpp

change.o : StreamSource.cpp
		$(CXX) $(CXXFLAGS) StreamSource.cpp

clean :
		rm -f core $(PROG) *.o
