#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
/*
Init Board
Print Board
Check Row
Check Column
Check subArray
Random
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

//int getRand()
//{
//	srand(time(0));
//	return rand() % 9;
//}

void clearRow(int row)
{
	for (int i = 0; i < 9; i++)
	{
		board[row][i] = 0;
	}
}

bool checkRow(int row, int tryNum)
{

	for (int i = 0; i < 9; i++)
	{
		if (board[row][i] == tryNum)
		{
			return false;
		}
	}
	return true;

}

bool checkCol(int col, int tryNum)
{
	for (int i = 0; i < 9; i++)
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
			while (!checkRow(i, tryNum) || !checkCol(j, tryNum))
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
	fillBoard();
	printBoard();
	
	
}