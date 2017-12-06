// Kyle Rooney COP2000 Homework 5
// This program displays a predetermined set of numbers that has a number missing.
// The player must find the missing number based on the numbers on the board.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int beginGame(int playedBoard[]);   
void instructions();                
void displayBoard(int board[][3]);  
bool testWinner(int, int, int[]);    

int main()
{
	int board0[4][3] = { { 38, 11, 83, },         
	{ 63, 9, 72 },
	{ 99, 18, 99 },
	{ 95, NULL, 59 } };

	int board1[4][3] = { { 28, 10, 55, },       
	{ 22, 4, 40 },
	{ 76, 13, 58 },
	{ 20, NULL, 11 } };

	int board2[4][3] = { { 11, 2, 20, },        
	{ 50, 5, 41 },
	{ 86, 14, 77 },
	{ 80, NULL, 44 } };

	int ansBoard[3] = { 14, 2, 8 };             
	int playedBoard[3] = { NULL };              
	int ans;                                    
	int wins = 0;                               
	int numGuesses = 0;                            
	int boardNumber;                               
	bool winner;                                

	cout << setprecision(2) << fixed << showpoint; 

	instructions();           

	do
	{
		boardNumber = beginGame(playedBoard);  
		numGuesses = 0; 

		do  
		{
			switch (boardNumber)  
			{
			case 0:
				displayBoard(board0);
				break;
			case 1:
				displayBoard(board1);
				break;
			case 2:
				displayBoard(board2);
				break;
			}


			cout << "Enter Guess or 0 to Exit ";

			cin >> ans;      

			while (ans < 0)  
			{
				cout << "Sorry, invalid number. Guess a number greater than 0, or enter 0 to Exit";
				cin >> ans;
			}

			if (ans == 0)
			{
				cout << "Thank you for playing, have a nice day! :) ";
				return 0;
			}

			winner = testWinner(ans, boardNumber, ansBoard);

			{
				if (winner)
				{   
					wins += 1;
					playedBoard[boardNumber] = 1;

					if (wins == 3)
					{
						cout << "*** You are the number guessing champion!! CONGRATULATIONS!! *** " << endl;
						system("pause");
						return 0;
					}
					cout << "Do you wish to play Again? Enter 0 to Exit, or any number to continue...\n";
					cin >> ans;

					if (ans == 0)
					{
						cout << "Thank you for playing, have a nice day! :) ";
						return 0;
					}


				}
				else
				{
					numGuesses += 1;
				}
			}

		} while (winner != true && numGuesses < 3);

		if (numGuesses == 3)
		{
			cout << "You have run out of guesses! :( \n";
			cout << "Do you wish to play again? Enter 0 to Exit, or any number to continue...\n";
			cin >> ans;

			if (ans == 0)
			{
				cout << "Thank you for playing, have a nice day! :) ";
				return 0;
			}
		}



	} while (wins < 3);

}

int beginGame(int playedBoard[])
{
	int randomNum;
	srand(time(0));

	do
	{
		randomNum = (rand() % (2 - 0 + 1)) + 0;
		
		if (playedBoard[randomNum] == NULL)
			return randomNum;
	}
	while (playedBoard[randomNum] != NULL);

}

void displayBoard(int board[][3])
{
	int row = 4;
	int col = 3;

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			if (board[x][y] == NULL)   
				cout << setw(8) << "?";
			else
				cout << setw(8) << board[x][y];
		}
		cout << endl;
	}
}

bool testWinner(int ans, int boardNumber, int ansBoard[])
{
	
	if (ans == ansBoard[boardNumber])
	{
		cout << "You are a number genius!\n" << endl;
		return true;
	}
	else
	{
		cout << "Sorry, that number was incorrect.\n" << endl;
		return false;
	}
}

void instructions()
{
	cout << " ******************************************************************" << endl;
	cout << "                           MISSING NUMBERS GAME                    " << endl;
	cout << "                              A fun brain game....                 " << endl;
	cout << "                                                                   " << endl;
	cout << "     Please Enter a whole number to guess the missing number...    " << endl;
	cout << "         Program Developed by : \"Kyle Rooney\"             " << endl;
	cout << " ******************************************************************" << endl;
}