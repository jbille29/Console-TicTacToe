/*
	Simple Console Tic Tac Toe
	---------------------------
	
	Valid board assignments
		   2|1|0
		 ---------
		   5|4|3
		 ---------
		   8|7|6
*/

// Preprocessor directives
#include <iostream>
#include <string>

// Function prototypes
unsigned short int GetPlayerInput(bool turn);
void UpdateBoard();
bool CheckWin(unsigned short int playerState);

// Global variables
std::string blankSpace[9]  = " ";

// Main funciton;
int main()
{
	
	bool turn = true;
	unsigned short int playerState1 = 0b000000000000;
	unsigned short int playerState2 = 0b000000000000;

	// game loop
	while(true)
	{
		
		unsigned short int newState = GetPlayerInput(turn);
		UpdateBoard();
		
		if(turn)
		{
			playerState1 |= newState;		// update player state
			if(CheckWin(playerState1))
			{
				std::cout << "Player 1 Wins!\n";
				break;						// if player wins, break from game loop
			}
		}
		else
		{	
			playerState2 |= newState;		// update player state
			if(CheckWin(playerState2))		
			{
				std::cout << "Player 2 Wins!\n";
				break;
			}
		}
		
		turn ? turn = false : turn = true; // change player turn
		
	}
	
	return 0;
}

/*
** GetPlayerInput: 	Take bool value turn, updates gameBoard string for visual
** 					returns a unsigned short in to hold the state of the player.
*/
unsigned short int GetPlayerInput(bool turn)
{
	int position;
	std::string gamePiece;
	
	if(turn)
	{
		std::cout << "Player 1: ";
		gamePiece = "X";
	}
	else
	{
		std::cout << "Player 2: ";
		gamePiece = "O";
	}
	
	std::cin >> position;					// get player input
	blankSpace[position] = gamePiece;
	
	unsigned short int newState = 0b0000000000000001 << (position + 4);
	return newState;
	
}

/*
	UpdateBoard: Prints the game board to the console.
*/
void UpdateBoard()
{
	for(int i = 0; i < 9; i++)
	{
		std::cout << blankSpace[i] << + "|" + blankSpace[i++] \
			+ "|" + blankSpace[i++] << "\n";
			
		if(i == 2 || i == 5) 
			std::cout << "------\n";
	}		
}

/*
** CheckWin: 	Takes the playerState, and returns true if they have won.
*/
bool CheckWin(unsigned short int playerState)
{
	switch(playerState)
	{
		//case876543210
		case 0b000000000111: // top horz
		case 0b000000111000: // mid horz
		case 0b000111000000: // bot horz
		case 0b000001001001: // left vert
		case 0b000010010010: // mid vert
		case 0b000100100100: // right vert
		case 0b000100010001: // dia
		case 0b000001010100: // dia
			return true;
		default:
			return false;
	}
		
}
