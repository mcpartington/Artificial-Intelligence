//===================================================================
// AUTHOR:  Maxwell Partington
// CLASS:   CS 571
// PROJECT: Final Project
// DATE:    12/10/14 
// FILE:	puzzle.cpp
//===================================================================
#include "puzzle.h"

#include <iostream>
#include <vector> 
using namespace std; 

//===================================================================
// PURPOSE: This is the default puzzle constructor. 
// PARAMS:  None. 
//===================================================================
puzzle::puzzle(){}//end puzzle
//===================================================================

//===================================================================
// PURPOSE: This is the puzzle destructor, it destroys the object when
//			appropriate. 
// PARAMS:  None. 
//===================================================================
puzzle::~puzzle(){}//end ~puzzle
//===================================================================

//===================================================================
// PURPOSE: This is the funtion that will run the entire puzzle. 
// PARAMS:  None. 
//===================================================================
void puzzle::runPuzzle()
{	
	// Calls the ready function for the user to initiate the program. 
	if(ready() == 1)
	{
		int totalCost = 0; 
		// User input to continue the best search algorithm. 
		char userInput; 

		// A vector to hold all of the visited nodes/states. 
		vector <state> allStates;

		// A vector to hold all of the possible moves. 
		vector <move> allPossibleMoves;

		// A vector to hold all of the valid moves from one state. 
		vector <move> validMoves;  

		// A vector to hold all of the moves actually made. 
		vector <move> movesMade;

		// A move object to initate the vector that gathers all of 
		// the possible moves the boat, cannibals, and missionaries
		// can take. 
		move gather; 

		// A move object to initiate the vector that will hold all
		// of the valid moves, and call the move functions. 
		move moves; 

		// This will hold the best move for each state to move to. 
		move bestMove; 

		allPossibleMoves = gather.allMoves(); 

		// The initial node. 
		state current(0,3,0,3,true); 

		// Push the start state to the allStates vector. 
		allStates.push_back(current); 

		// Evaluate our move to next state:
		//	- Check if the current state is the goal state and that the user wants to continue. 
		//	- Check best node to move to by expanding all possible states.
		//  - Choose the node with the least cost. 
		//	- Move to that node. 
		//	- Add the state/move to our list of states/moves. 
		while((!goalState(current)) && (userInput != 'n'))
		{
			cout << "\n======================================================="<< endl; 

			// Current State
			current.printCurrentState(0); 

			// Get all valid moves from current state.
			cout << "\nGathering valid states..." << endl; 
			validMoves = moves.validMovesFromState(current, allPossibleMoves);

	 		// Evaluate each move for the cost to move to the next state.
	 	    bestMove = moves.checkCost(current, allStates, validMoves, totalCost, movesMade);
			
			// Print out the move we will make to the next state. 
			bestMove.printMove(); 

			// Update current state with next state of cheapest move. 
			current = moves.updateCurrent(current, bestMove);

			// Print the state to be expanded. 
			cout << "\nExpanding:"; 
			current.printCurrentState(1); 

			// // Update all states.
			allStates.push_back(current);

			// Update the moves list history.
			movesMade.push_back(bestMove); 	
			cout << "\n=======================================================" << endl; 

			//------------------------------------------
			// Check that the user wants to keep going. 
			cout << "\nWould you like to continue? (y/n): "; 
			cin >> userInput; 

			if((userInput != 'n') && (userInput != 'y'))
			{
				cout << "Incorrect input. Please enter: y/n. Continuing..." << endl; 
				userInput = 'y'; 
			}
			else if(userInput == 'n')
			{
				goodBye(); 
			}
			//------------------------------------------
		}//end while 

		// If we have found the goal state, print out path to solution.
		cout << "\n*We have found our goal!* Here is our path:" << endl;
		printPuzzleResults(movesMade, allStates, totalCost); 
	} 
	else 
	{
		exit(1); 
	}
}//end runPuzzle
//===================================================================

//===================================================================
// PURPOSE: This function is used to check if the current state is
//			the goal state: [MMM CCC B|       ]. 
// PARAMS:  The state we are currently at. 
//===================================================================
bool puzzle::goalState(state current)
{
	if ((current.getMLeft() == 3) && (current.getCLeft() == 3) && 
		(current.getMRight() == 0) && (current.getCRight() == 0))
	{
		return true;
	}
	return false; 
}//end goalState
//===================================================================

//===================================================================
// PURPOSE: This function will print out the results from running the
//			program. 
// PARAMS:  The move vector that holds every mode the program made. 
//			The state vector that holds the states the program went
//			to. 
//			The total cost for every move.  
//===================================================================
void puzzle::printPuzzleResults(vector <move> moves, vector <state> all, int cost)
{
	cout << "\n=======================================================" << endl;
	cout << "The following are the states taken to get to the goal state:" << endl;  
	
	for(int i = 0; i < all.size(); i++)
	{
		if (i < 9)
		{
			cout << i+1 << " ";
		}
		else
		{
			cout << i+1; 
		}
		all[i].printCurrentState(1); 
	}//end for 

	cout << "--------------------------------------------------------" << endl; 
	cout << "Total cost of moves from start to finish: " << cost << endl; 
	cout << "Total number of moves: " << (moves.size()+1) << endl; 
	cout << "=======================================================\n" << endl; 
}//end printPuzzleResults
//===================================================================

//===================================================================
// PURPOSE: This function will print out the welcome screen when the
//			program is executed. 
// PARAMS:  None. 
//===================================================================
void puzzle::printWelcomeScreen()
{
	cout << "\n=======================================================" << endl; 
	cout << "|  |\\  /|               |----                         |" << endl;
	cout << "|  | \\/ |               |                             |" << endl;
	cout << "|  |    |issionaries &  |____ annibals                |" << endl; 
	cout << "=======================================================" << endl; 
	cout << "| By: Maxwell Partington                              |" << endl;  
	cout << "=======================================================" << endl; 
	cout << "|The goal of this program is to compute the best      |" << endl; 
	cout << "|path to move all of the cannibals and the            |" << endl;
	cout << "|missionaries from one side of the river to           |" << endl; 
	cout << "|the other. Our start and goal states are as follows: |" << endl; 
	cout << "|Start State: [             |   : B|   M M M C C C ]] |" << endl; 
	cout << "|Goal State:  [ M M M C C C |B  :  |               ]] |" << endl; 
	cout << "|                                                     |" << endl; 
	cout << "|To save space, we will represent the missionaries and|" << endl;
	cout << "|cannibals with numbers. Example: [ 3 3 -1- | 0 0 ]   |" << endl; 
	cout << "|represents the goal state. The \'-1-\' represents the  |" << endl;
	cout << "|boats position. It is on the left shore when it is to|" << endl;
	cout << "|the left of the \'|\', and it is on the right shore    |" << endl;
	cout << "|when it is to the right of the \'|\'. Enjoy!           |" << endl; 
	cout << "=======================================================" << endl; 
}//end printWelcomeScreen 
//===================================================================

//===================================================================
// PURPOSE: This function will print out the goodbye screen when the
//			program is finished, or when the user quits early. 
// PARAMS:  None. 
//===================================================================
int puzzle::goodBye()
{
	cout << "\n=======================================================" << endl; 
	cout << "I hope you've enjoyed watching this program find the" << endl; 
	cout << "best way to move the missionaries and cannibals safely " << endl; 
	cout << "from one side of the river to the other. Take care!" << endl; 
	cout << "\n\n P.S. If you've skipped and exited early, please run the" << endl; 
	cout << " program again to see the full solution. Bye! :)" << endl; 
	cout << "=======================================================\n" << endl; 
	exit(1);
}//end goodbye
//===================================================================

//===================================================================
// PURPOSE: The function was written to have a buffer between the
//			welcome screen and starting the program. It is to give
//			the user time to start the path calculation themselves,
//			instead of starting it automatically. 
// PARAMS:  None. 
//===================================================================
int puzzle::ready()
{	
	// The answer from the user. 
	char answer;

	// Prompt the user. 
	cout << "\nHello! Are you ready to begin? (y/n): "; 
	cin >> answer;

	// If they answer 'y', start the program. 
	if(answer == 'y')
	{
		return 1;
	}
	// If they answer 'n', exit the program via the "goodbye" function. 
	else if(answer == 'n')
	{
		goodBye(); 
		return 0; 
	}
	// If the input is invalid, tell the user, restart the function. 
	else if ((answer != 'y') && (answer != 'n'))
	{
		cout << "Invalid input." << endl; 
		ready(); 
		return 0; 
	}
	return 0; 
}//end ready
//===================================================================

//===================================================================
// PURPOSE: This function is to get the total cost value. 
// PARAMS:  None. 
//===================================================================
int puzzle::getTotalCost()
{
	return totalCost; 
}//end getTotalCost
//===================================================================

//===================================================================
// PURPOSE: This function is for setting the total cost if necessary. 
// PARAMS:  None. 
//===================================================================
void puzzle::setTotalCost(int cost)
{
	totalCost = cost; 
}//end setTotalCost 
//===================================================================
