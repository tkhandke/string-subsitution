CXX = g++
CXXFLAGS = -c -g -std=c++11

PROG = a.out
HDRS = stringsub.h TrackingDeque.h
SRCS = main.cpp stringsub.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROG) : $(OBJS)
	$(CXX)  $(OBJS) -o $(PROG)

main.o :main.cpp
		$(CXX) $(CXXFLAGS) main.cpp

stringsub.o : stringsub.cpp
		$(CXX) $(CXXFLAGS) stringsub.cpp

clean :
		rm -f core $(PROG) *.o
