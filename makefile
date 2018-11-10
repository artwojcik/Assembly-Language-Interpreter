CFLAGS = -O -Wall -Wextra
CC = g++ -std=c++11
SRC = main.cpp utility.cpp SAL.cpp ADD.cpp DEC.cpp JZS.cpp HLT.cpp JMP.cpp JVS.cpp LDA.cpp LDB.cpp LDI.cpp ST.cpp XCH.cpp Computer.cpp INT.cpp 
OBJ = $(SRC:.cpp = .o)
awojci5: $(OBJ)
	$(CC) $(CFLAGS) -o awojci5 $(OBJ)
clean:
	rm -f core *.o 

run:
	clear
	./awojci5

valgrind:
	clear 
	valgrind ./awojci5