############################################
# AUTHOR:  Maxwell Partington 
# CLASS:   CS 571
# PROJECT: FINAL
# DATE:    12/10/14
############################################
CC = g++                # use g++ for compiling c++ code or gcc for c code
CFLAGS = -g -Wall       # compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
LIB = -lm               # linked libraries      
LDFLAGS = -L.           # link flags
PROG = final            # target executable (output)
OBJ = mandc.o puzzle.o move.o state.o          # object files for the target. 
SRC = mandc.cpp puzzle.cpp move.cpp state.cpp    # .c or .cpp source files.  

all : $(PROG)

$(PROG): $(OBJ)
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)


# cleanup
clean:
	/bin/rm -f *.o $(PROG)
# DO NOT DELETE