//===================================================================
// AUTHOR:  Maxwell Partington
// CLASS:   CS 571
// PROJECT: Final Project
// DATE:    12/10/14 
// FILE:	state.h 
//===================================================================
#ifndef STATE_H
#define STATE_H


//===================================================================
// PURPOSE: The state class is the state at which the system is in. 
//			Meaning, it is an indicator of how many people are standing
//			on both sides of the river at all times. 
// PARAMS:  None. 
//===================================================================
class state
{
	private:
		// Class Variables
		int missionaries_left;
		int missionaries_right;
		int cannibals_left;
		int cannibals_right;  
		bool boat; 

	public:
		// Constructors
		state();
		state(int mLeft, int mRight, int cLeft, int cRight, bool theBoat); 

		// Destructor
		~state();  

		void printCurrentState(int final);

		// Getters and Setters
		int getMLeft(); 
		void setMLeft(int numOfM);
		int getMRight();
		void setMRight(int numOfM);
		int getCLeft();
		void setCleft(int numOfC);
		int getCRight(); 
		void setCRight(int numOfM);
		bool getBoat();
		void setBoat(bool theBoat);  

};// end state 
//===================================================================
#endif
