//===================================================================
// AUTHOR:  Maxwell Partington
// CLASS:   CS 571
// PROJECT: Final Project
// DATE:    12/10/14 
// FILE:	move.h 
//===================================================================
#ifndef MOVE_H
#define MOVE_H

#include "state.h" 
#include <vector>
using namespace std;

//===================================================================
// PURPOSE: This class is designed to hold the data needed to indicate
//			what the next move of the program will be. The functions
//			inclued will perform functions on the given variables 
//			as well as print out various data. 
// PARAMS:  None. 
//===================================================================
class move
{
	private:
		// Class Variables
		int missionaries;
		int cannibals; 
		bool boat;

	public:
		// Constructors
		move();
		move(int numOfM, int numOfC, bool theBoat);

		// Destructor
		~move();

		// Functions 
		bool validMove(state current);
		vector <move> validMovesFromState(state current, vector <move> everyMove); 
		vector <move> allMoves(); 
		move checkCost(state current, vector <state> states, vector <move> validMoves, int &totalCost, vector <move> movesMade);
		state updateCurrent(state current, move next);  
		void printMove(); 
		void checkValues(vector <move> movesMade, state current, int cost);


		// Getters and Setters
		int getMissionaries();
		void setMissionaries(int numOfM);
		int getCannibals(); 
		void setCannibals(int numOfC);
		bool getBoat();
		void setBoat(bool boat); 

};// end move 
//===================================================================
#endif
