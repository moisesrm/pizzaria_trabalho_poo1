CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ../../class/Produto.h
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit

produtotest: ProdutoTest.cpp $(OBJM)
	$(CXX) $(CXXFLAGS) -o $@ ProdutoTest.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

# Default compile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@