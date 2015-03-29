//===================================================================
// AUTHOR:  Maxwell Partington
// CLASS:   CS 571
// PROJECT: Final Project
// DATE:    12/10/14 
// FILE:    m_&_c.cpp
// COMPILE: Use the "Makefile" included in the directory by typing in
//			"make" when you are in the "mandc" directory. 
// RUN: 	./final, iterate by entering correct input. 
//===================================================================
#include <iostream> 
#include <vector> 
using namespace std; 

#include "puzzle.h"

//===================================================================
// PURPOSE: This is the main control of the program. This function 
//			will call of the appropriate puzzle functions, the functions
//			that will compute the best path algorithm (A*) and the
//			appropriate functions to print out all the necessary data. 
// PARAMS:  None. 
//===================================================================
int main()
{	
	// Creates a new puzzle object. 
	puzzle mNcPuzzle; 
	
	// Prints the main welcome screen.
	mNcPuzzle.printWelcomeScreen(); 
	
	// This will determine the trace of decisions made by the program. 
	//		- Which states are in the frontier? 
	//		- What are their g, h and f values? 
	//		- Which one will we expand next?	
	mNcPuzzle.runPuzzle();

	// Final screen for the program. 
	mNcPuzzle.goodBye(); 

	// Destroy the created puzzle object. 
	mNcPuzzle.~puzzle(); 

	return 0; 
}//end main()
//===================================================================
