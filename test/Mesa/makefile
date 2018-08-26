CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ../../class/Mesa.h
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit

mesatest: MesaTest.cpp $(OBJM)
	$(CXX) $(CXXFLAGS) -o $@ MesaTest.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

# Default compile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@