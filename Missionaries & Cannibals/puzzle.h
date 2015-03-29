//===================================================================
// AUTHOR:  Maxwell Partington
// CLASS:   CS 571
// PROJECT: Final Project
// DATE:    12/10/14 
// FILE:	puzzle.h 
//===================================================================
#ifndef PUZZLE_H
#define PUZZLE_H
#include "state.h"
#include "move.h"
#include <vector> 
//===================================================================
// PURPOSE: The purpose of this class is to hold all of the functions
//			that will be required to run the actual program and print
//			various screens for the user. 
// PARAMS:  None. 
//===================================================================
class puzzle
{
	private:
		// Private Variables
		int totalCost;

	public:
		// Constructor
		puzzle();

		// Destructor
		~puzzle();  
		
		// Class Functions 
		void runPuzzle(); 
		void printWelcomeScreen(); 
		int goodBye(); 
		void printPuzzleResults(vector <move> moves, vector <state> all, int cost); 	
		bool goalState(state current); 
		int getTotalCost();
		void setTotalCost(int cost);
		int ready(); 
};// end puzzle 
//===================================================================
#endif
