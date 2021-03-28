IDIR =./include
SDIR =./src
ODIR =./obj
CC=g++
CFLAGS=-I$(IDIR) -g


_DEPS = romanos.hpp catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = romanos.o testa_romanos.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: all trabalho cpplint valgrind check   run

trabalho: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

clean:
	rm -f $(ODIR)/*.o 

check: 
	cppcheck --enable=warning  $(SDIR)/testa_romanos.cpp
	cppcheck --enable=warning  $(SDIR)/romanos.cpp

valgrind:
	valgrind --leak-check=full  ./trabalho 

cpplint:
	- cpplint $(IDIR)/romanos.hpp
	- cpplint $(SDIR)/testa_romanos.cpp
	- cpplint $(SDIR)/romanos.cpp

run:
	./trabalho	
