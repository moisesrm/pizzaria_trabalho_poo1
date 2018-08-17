CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ../../class/Cliente.h
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit

clientetest: ClienteTest.cpp $(OBJM)
	$(CXX) $(CXXFLAGS) -o $@ ClienteTest.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

# Default compile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@