// Multidimensional arrays

#include <iostream>

int main()
{
	const int ROWS = 3;
	const int COLUMNS = 3;
	
	char board[ROWS][COLUMNS] = {	{'O', 'X', 'O'},
									{' ', 'X', 'X'},
									{'X', 'O', 'O'} };
	std::cout << "Here's the board:\n\n";
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
	
	std::cout << "\nX takes the last space:\n\n";
	board[1][0] = 'X';
	
	std::cout << "Here's the board now:\n\n";
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
	
	std::cout << "\nX wins!" << std::endl;
	
	return 0;
}