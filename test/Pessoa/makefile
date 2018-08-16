CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ../../class/Pessoa.h
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit

pessoatest: PessoaTest.cpp $(OBJM)
	$(CXX) $(CXXFLAGS) -o $@ PessoaTest.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

# Default compile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@