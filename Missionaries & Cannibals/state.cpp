//===================================================================
// AUTHOR:  Maxwell Partington
// CLASS:   CS 571
// PROJECT: Final Project
// DATE:    12/10/14 
// FILE:	state.cpp
//===================================================================
#include "state.h"
#include "move.h"
#include <iostream>
using namespace std; 

//===================================================================
// PURPOSE: This is the default state constructor. 
// PARAMS:  None. 
//===================================================================
state::state(){}//end state
//===================================================================

//===================================================================
// PURPOSE: This is the state constructor. 
// PARAMS:  The number of missionaries on the left.
//			The number of missionaries on the right. 
//			The number of cannibals on the left. 
//			The number of cannibals on the right. 
//			The side that the boat is on. True = right, False = left. 
//===================================================================
state::state(int mLeft, int mRight, int cLeft, int cRight, bool theBoat)
{
		missionaries_left = mLeft;
		missionaries_right = mRight;
		cannibals_left = cLeft;
		cannibals_right = cRight;  
		boat = theBoat; 
}//end state
//===================================================================

//===================================================================
// PURPOSE: This is the state destructor, it destroys the object when
//			appropriate. 
// PARAMS:  None. 
//===================================================================
state::~state(){}//end ~state
//===================================================================

//===================================================================
// PURPOSE: This function will print out the desired state. 
// PARAMS:  This number indicates if what we need to print out before
//			the state information. 
//			1 - "Current State"
//			2 - "State" 
//===================================================================
void state::printCurrentState(int final)
{
	if (final == 0)
	{
	cout << "\nCurrent State:  "; 
	}
	else if (final == 1)
	{
		cout << " State:"; 
	}
	// If the boat is on the right, print it with -1- to the right of |
	if (this->getBoat() == true)
	{
		cout << "[ " << this->getMLeft() << " " << this->getCLeft() << " | -" << true << "- " <<  this->getMRight() << " " << this->getCRight() << " ]" << endl; 
	}
	// If the boat is on the left, print it with -1- to the left of |
	else if (this->getBoat() == false)
	{
		cout << "[ " << this->getMLeft() << " " << this->getCLeft() << " -" << true << "- | "<< this->getMRight() << " " << this->getCRight() << " ]"<< endl; 
	}
}//end printCurrentState
//===================================================================

//===================================================================
// PURPOSE: This function retrieves the number of missionaries on the 
//			left side of the river. 
//===================================================================
int state::getMLeft() 
{
	return missionaries_left; 
}//end getMLeft
//===================================================================

//===================================================================
// PURPOSE: This function will set the number of missionaries on the 
//			left to the number passed in.  
// PARAMS:  The number of missionaries to set. 
//===================================================================
void state::setMLeft(int numOfM)
{
	missionaries_left = numOfM; 
}//end setMLeft
//===================================================================

//===================================================================
// PURPOSE: This function retrieves the number of missionaries on the 
//			right side of the river. 
//===================================================================
int state::getMRight()
{
	return missionaries_right; 
}//end getMRight
//===================================================================

//===================================================================
// PURPOSE: This function will set the number of missionaries on the 
//			right to the number passed in.  
// PARAMS:  The number of missionaries to set. 
//===================================================================
void state::setMRight(int numOfM)
{
	missionaries_right = numOfM; 
}//end setMRight
//===================================================================

//===================================================================
// PURPOSE: This function retrieves the number of cannibals on the 
//			left side of the river. 
//===================================================================
int state::getCLeft()
{
	return cannibals_left; 
}//end getCLeft
//===================================================================

//===================================================================
// PURPOSE: This function will set the number of cannibals on the 
//			left to the number passed in.  
// PARAMS:  The number of cannibals to set. 
//===================================================================
void state::setCleft(int numOfC)
{
	cannibals_left = numOfC;
}//end setCLeft
//===================================================================

//===================================================================
// PURPOSE: This function retrieves the number of cannibals on the 
//			right side of the river. 
//===================================================================
int state::getCRight()
{
	return cannibals_right; 
}//end getCRight
//===================================================================

//===================================================================
// PURPOSE: This function will set the number of cannibals on the 
//			right to the number passed in.  
// PARAMS:  The number of cannibals to set. 
//===================================================================
void state::setCRight(int numOfC)
{
	cannibals_right = numOfC; 
}//end setCRight
//===================================================================

//===================================================================
// PURPOSE: This function will retreive what side of the river the
//			boat is on. 
// PARAMS:  None. 
//===================================================================
bool state::getBoat()
{
	return boat; 
}//end getBoat
//===================================================================

//===================================================================
// PURPOSE: This function will set what side of the river the
//			boat is on. 
// PARAMS:  The side of the river the boat is to be on. True = right, 
//			False = left.
//===================================================================
void state::setBoat(bool theBoat)
{
	boat = theBoat; 
}//end setBoat
//===================================================================
