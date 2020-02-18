#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


/*
TODO Implement 3x3 Check
*/

int board[9][9];

void printBoard()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
			{
				std::cout << " ";
			}
			std::cout << board[i][j];
		}
		if (i == 2 || i == 5)
		{
			std::cout << "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n" << "----------------------" << "\n";

}



void clearRow(int row)
{
	for (int i = 0; i < 9; i++)
	{
		board[row][i] = 0;
	}
}

int getXYCoord(int x)
{
	if (x < 3)
	{
		return 0;
	}
	if (x < 6)
	{
		return 1;
	}
	if (x < 9)
	{
		return 2;
	}
}


bool checkSubArray(int tryNum, int xPos, int yPos)
{
	int count = 0;
	int xEnd = xPos * 3 + 2;
	int yEnd = yPos * 3 + 2;

	
	for (int i = yPos * 3; i <= yEnd; i++)
	{
		for (int j = xPos * 3; j <= xEnd; j++)
		{

			board[i][j] = 1;
			count++;
			std::cout << count << "\n";
			std::cout << "xpos: " << xPos << "\n";
			std::cout << "ypos: " << yPos << "\n";
			printBoard();

			if (board[i][j] == tryNum)
			{
				std::cout << "Already in subarray";
				return false;
			}
		}

	}
	

	return true;
	
}

bool checkRow(int row, int tryNum, int n)
{

	for (int i = 0; i < n; i++)
	{
		if (board[row][i] == tryNum)
		{
			return false;
		}
	}
	return true;

}

bool checkCol(int col, int tryNum, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (board[i][col] == tryNum)
		{
			return false;
		}
	}
	return true;
}


void initBoard()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = 0;
		}
	}
		
}

void fillBoard()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int count = 0;


			int tryNum = (rand() % 9) + 1;
			// check the rules, and if need be pick a new number
			//
			while (!checkRow(i, tryNum, 9) || !checkCol(j, tryNum, 9))
			{
				tryNum = (rand() % 9) + 1;
				count++;
				if (count == 20)
				{
					clearRow(i);
					j = 0;
					count = 0;
				}
				std::cout << tryNum << "\n";
				std::cout << count << std::endl;

			}
			printBoard();

			board[i][j] = tryNum;

			//printBoard();

		}
	}
}





int main()
{
	initBoard();
	printBoard();

	checkSubArray(2, 2, 2);


	/*fillBoard();
	printBoard();*/
	
	
}