//===================================================================
// AUTHOR:  Maxwell Partington
// CLASS:   CS 571
// PROJECT: Final Project
// DATE:    12/10/14 
// FILE:	move.cpp
//===================================================================
#include "move.h"
#include "state.h"

#include <iostream>
#include <vector> 
using namespace std; 

//===================================================================
// PURPOSE: This is the default move constructor. 
// PARAMS:  None. 
//===================================================================
move::move(){
}//end move
//===================================================================

//===================================================================
// PURPOSE: This is the move constructor. 
// PARAMS:  The number of missionaries for the move. 
//			The number of cannibals for the move. 
//			The side of the river the boat will be on. 
//			True = Right, False = Left
//===================================================================
move::move(int numOfM, int numOfC, bool theBoat)
{
	missionaries = numOfM;
	cannibals = numOfC;
	boat = theBoat; 
}//end move
//===================================================================

//===================================================================
// PURPOSE: This is the move destructor, it destroys the object when
//			appropriate. 
// PARAMS:  None. 
//===================================================================
move::~move(){}//end ~move
//===================================================================

//===================================================================
// PURPOSE: This function will search through the vector of all possible
//			moves to gather the moves that are only valid from the
//			current state.  
// PARAMS:  The state we are in currently. 
//			The vector of all possible moves. 
//===================================================================
vector <move> move::validMovesFromState(state current, vector <move> moves)
{	
	// A vector of possible moves for the current state. 
	vector <move> possible; 
	for (int i = 0; i < moves.size(); i++)
	{	
		// A state object that will hold the next possible state. 
		state next; 
		// If the boat is on the right, and the next move has the 
		// boat on the left, create a new state based on that move,
		// check that it is valid, and then push the move to the possible
		// moves vector.
		if((current.getBoat() == true) && (moves[i].getBoat() == 0))
		{	
			next = state((current.getMLeft()+moves[i].getMissionaries()), 
						 (current.getMRight()-moves[i].getMissionaries()),
						 (current.getCLeft()+moves[i].getCannibals()), 
				  		 (current.getCRight()-moves[i].getCannibals()), 
				  		 false);
			if(validMove(next) == true)
			{	
				possible.push_back(moves[i]); 
			} 
		}
		// If the boat is on the left, and the next move has the 
		// boat on the right, create a new state based on that move,
		// check that it is valid, and then push the move to the possible
		// moves vector.
		else if ((current.getBoat() == false) && (moves[i].getBoat() == 1))
		{
			next = state((current.getMLeft()-moves[i].getMissionaries()), 
						 (current.getMRight()+moves[i].getMissionaries()),
						 (current.getCLeft()-moves[i].getCannibals()), 
				  		 (current.getCRight()+moves[i].getCannibals()), 
				  		 true); 
			if(validMove(next) == true)
			{	
				possible.push_back(moves[i]); 
			} 
		}
	}//end for 
	return possible;  
}//end validMovesFromState
//===================================================================

//===================================================================
// PURPOSE: This function will create all of the possible moves, and
//			push them to a vector to be return, and used in the main
//			puzzle program. 
// PARAMS:  None. 
//===================================================================
vector <move> move::allMoves()
{
	// The vector that will hold all of the possible moves. 
	vector <move> moves; 

	// Move 1 M and 0 C to the right.
	moves.push_back(move(1, 0, true));

	// Move 2 M and 0 C to the right.
	moves.push_back(move(2, 0, true));

	// Move 0 M and 1 C to the right.
	moves.push_back(move(0, 1, true));

	// Move 0 M and 2 C to the right.
	moves.push_back(move(0, 2, true));

	// Move 1 M and 1 C to the right.
	moves.push_back(move(1, 1, true));

	// Move 1 M and 0 C to the left.
	moves.push_back(move(1, 0, false));

	// Move 2 M and 0 C to the left.
	moves.push_back(move(2, 0, false));

	// Move 0 M and 1 C to the left.
	moves.push_back(move(0, 1, false));

	// Move 0 M and 2 C to the left.
	moves.push_back(move(0, 2, false));

	// Move 1 M and 1 C to the left.
	moves.push_back(move(1, 1, false));

	return moves; 
}//end allMoves
//===================================================================

//===================================================================
// PURPOSE: This function is designed to make sure the state passed
//			in is valid.
//			Valid means:
//				There is never more cannibals than missionaries on one side.
//				There is never less than 0 missionaries or cannibals on either side. 
//				There is never more than 3 missionaries or cannibals on either side. 
// PARAMS:  The state we are checking to be valid. 
//===================================================================
bool move::validMove(state current)
{	
	if((current.getMLeft() > 3) || (current.getCLeft() >3) || (current.getMRight() > 3) || (current.getCRight() > 3 ))
	{
		return false; 
	}
	else if((current.getMLeft() < 0) || (current.getCLeft() < 0) || (current.getMRight() < 0) || (current.getCRight() < 0))
	{
		return false; 
	}
	else if((current.getMLeft() == current.getCLeft()) && (current.getMRight() == current.getCRight()))
	{
		return true; 
	}
	else if((current.getMLeft() > current.getCLeft()) && (current.getMRight() > current.getCRight()))
	{
		return true; 
	}
	else if((current.getMLeft() < current.getCLeft()) && (current.getMRight() ==3))
	{
		return true; 
	}
	else if((current.getMLeft() == 3 ) && (current.getMRight() < current.getCRight()))
	{
		return true; 
	}
	 else if((current.getMLeft() < current.getCLeft()) && (current.getMRight() > current.getCRight()))
	{
		return false; 
	}
	else if((current.getMLeft() > current.getCLeft()) && (current.getMRight() < current.getCRight()))
	{
		return false; 
	}
	else
	{
		return false; 
	}
}//end validMove
//===================================================================

//===================================================================
// PURPOSE: This function will check the cost of all of the possible
//			moves from the state we are in.  
// PARAMS:  The state we want to check the moves for. 
//			The vector of all possible states. 
//			The vector of all valid moves for that state. 
//			The totalCost of all moves made in the program. 
//			The vector of all moves made thus far in the program. 
//===================================================================
move move::checkCost(state current, vector <state> allStates, vector <move> validMoves, int &totalCost, vector <move> movesMade)
{	
	//Local Variables
	// The move determined to be of the least cost. 
	move best;
	// The next state to be looked at. 
	state nextState;
	// A default cheapest cost.
	int cheapestCost = 100; 
	// The cost of the actual move. 
	int cost = 0; 


	cout << "\nAll valid states in the frontier:" << endl; 
	// We loop through all of the valid moves and check each ones cost. 
	for (int i = 0; i < validMoves.size(); i++)
	{
		// Each boat movement costs at least one. 
		cost = 1; 

		// If the boat is on the right
		if (current.getBoat() == true)
		{	
			// We add up how many cannibals and missionaries are left
			// on the right side of the river. We will need to move all
			// of them, so the cost is the total number of people left to move. 
			cost+= ((current.getMRight() - validMoves[i].getMissionaries()) + (current.getCRight() - validMoves[i].getCannibals())); 
			
			// Update the current state to the next possible state. 
			nextState = updateCurrent(current, validMoves[i]);

			// Check all of the previously visited states, and if
			// it has been visited, add one more to the cost. 
			for (int i = 0; i < allStates.size(); i++)
			{
				if ((nextState.getMLeft() == allStates[i].getMLeft()) &&
					(nextState.getMRight() == allStates[i].getMRight()) &&
					(nextState.getCLeft() == allStates[i].getCLeft()) &&
					(nextState.getCRight() == allStates[i].getCRight()) &&
					(nextState.getBoat() == allStates[i].getBoat()))
				{
					cost++; 
				}
			}//end for 

			// Print out the next state. 
			cout << "\t\t[ " << nextState.getMLeft() << " " << nextState.getCLeft() << " -" << true;
			cout << "- | " << nextState.getMRight() << " " << nextState.getCRight()  << " ] "; 

			// Check the next states g,h,f values. 
			checkValues(movesMade, current, cost);
		}
		else if(current.getBoat() == false)
		{
			// We add up how many cannibals and missionaries are left
			// on the right side of the river. We will need to move all
			// of them, so the cost is the total number of people left to move. 
			cost+= ((current.getMRight() + validMoves[i].getMissionaries()) + (current.getCRight() + validMoves[i].getCannibals())); 

			// Update the current state to the next possible state. 
			nextState = updateCurrent(current, validMoves[i]);

			// Check all of the previously visited states, and if
			// it has been visited, add one more to the cost. 
			for (int i = 0; i < allStates.size(); i++)
			{

				if ((nextState.getMLeft() == allStates[i].getMLeft()) &&
					(nextState.getMRight() == allStates[i].getMRight()) &&
					(nextState.getCLeft() == allStates[i].getCLeft()) &&
					(nextState.getCRight() == allStates[i].getCRight()) &&
					(nextState.getBoat() == allStates[i].getBoat()))
				{
					cost++; 
				}
			}//end for 

			// Print out the next state. 
			cout << "\t\t[ " << nextState.getMLeft() << " " <<  nextState.getCLeft() << " | -" << true;
			cout << "- " << nextState.getMRight()  << " " << nextState.getCRight()  << " ] "; 
			
			// Check the next states g,h,f values. 
			checkValues(movesMade, current, cost);
		}

		// If the cost found is less than the cheapest cost found, 
		// update the cheapest to the new cost. Add that value to the
		// total cost for the program. The best move is updated to 
		// the cheapest valid move. 
		if (cost <= cheapestCost)
		{
			cheapestCost = cost;
			totalCost+=cheapestCost;  
			best = validMoves[i];
		}
	}//end for 
	return best; 
}//end checkCost
//===================================================================

//===================================================================
// PURPOSE: This function creates a new state based on the current state
//			we are given, and the next move desired. 
// PARAMS:  The current state we are looking at. 
//			The move the system will make from the current state.  
//===================================================================
state move::updateCurrent(state current, move next)
{
	// A new state to hold the next state values. 
	state nextBestState; 

	// If the boat is on the right side, update the next state's values
	// accordingly. 
	if(current.getBoat() == true)
	{	
		nextBestState = state((current.getMLeft()+next.getMissionaries()), 
				 	(current.getMRight()-next.getMissionaries()),
				 	(current.getCLeft()+next.getCannibals()), 
		  		 	(current.getCRight()-next.getCannibals()), 
		  		 	false);
	}
	// If the boat is on the left side, update the next state's values
	// accordingly. 
	else
	{
		nextBestState = state((current.getMLeft()-next.getMissionaries()), 
				 	(current.getMRight()+next.getMissionaries()),
				 	(current.getCLeft()-next.getCannibals()), 
		  		 	(current.getCRight()+next.getCannibals()), 
		  		 	true); 
	}
return nextBestState; 
}//end updateCurrent
//===================================================================

//===================================================================
// PURPOSE: This function computes the h,g,f values of the program. 
//			h: My guess of how many moves are left based on the current state. 
//			g: The number of moves made thus far. 
//			f: h + g
// PARAMS:  The vector of all of the moves made already. 
//			The state we are currently in. 
//===================================================================
void move::checkValues(vector <move> movesMade, state current, int cost)
{
	// Local variables
	int h = 0; 
	int g = 1;
	int f = 0; 

	// The following are all values that I have determined
	// to be the amount need to finish the program based 
	// on the current state. 

	h = cost; 
	g = movesMade.size();
	f = g + h;  

	cout << "  Values g: \'" << g << "\' h: \'" << h << "\' f: \'"  << f << "\'" << endl; 
}//end CheckValues
//===================================================================


//===================================================================
// PURPOSE: This function will print out the move that is going
//			to be made next in a clear fashion. 
// PARAMS:  None. 
//===================================================================
void move::printMove()
{
	if (this->getBoat() == true)
	{	
		cout << "\nMoving " << this->getMissionaries() << " missionary(ies) and " << this->getCannibals() << " cannibal(s) to the right shore." << endl;
	}
	else if (this->getBoat() == false)
	{
		cout << "\nMoving " << this->getMissionaries() << " missionary(ies) and " << this->getCannibals() << " cannibal(s) to the left shore." << endl;
	}
}//end printMove
//===================================================================

//===================================================================
// PURPOSE: This function will retreive the number of missionaries in
//			the move. 
// PARAMS:  None. 
//===================================================================
int move::getMissionaries()
{
	return missionaries; 
}//end getMissionaries 
//===================================================================

//===================================================================
// PURPOSE: This function will set the number of missionaries in the 
//			move if necessary. 
// PARAMS:  The number of missionaries desired. 
//===================================================================
void move::setMissionaries(int numOfM)
{
	missionaries = numOfM; 
}//end setMissionaries
//===================================================================

//===================================================================
// PURPOSE: This function will retrieve the number of cannibals in
//			the move if necessary. 
// PARAMS:  None. 
//===================================================================
int move::getCannibals()
{
	return cannibals;
}//end getCannibals
//===================================================================

//===================================================================
// PURPOSE: This function will set the number of cannibals in the
//			move if necessary. 
// PARAMS:  The number of cannibals desired. 
//===================================================================
void move::setCannibals(int numOfC)
{
	cannibals = numOfC; 
}//end setCanninbals
//===================================================================

//===================================================================
// PURPOSE: This function will retrieve the side of the river the
//			boat is on. 
// PARAMS:  None. 
//===================================================================
bool move::getBoat()
{
	return boat; 
}//end getBoat
//===================================================================

//===================================================================
// PURPOSE: This function will set the boat to the side of the river
//			desired. 
// PARAMS:  The side of the river the boat is to be on. 
//===================================================================
void move::setBoat(bool theBoat)
{
	boat = theBoat; 
}//end setBoat
//===================================================================
