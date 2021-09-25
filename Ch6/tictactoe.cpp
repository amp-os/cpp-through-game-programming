// Noughts and Crosses

#include <iostream>
#include <string>

void printInstructions();
char askYesNo(std::string question);
int askNumber(int high, int low = 0);
char humanPiece();
char opponent(char piece);
void printBoard(const char* board);
char winner(const char* board);
bool isLegal(const char* board, int move);
int humanMove(const char* board);
int computerMove(char* board, const char computer);
void announceWinner(char winner, char computer, char human);

int main()
{
	// Set up game
	std::cout << "WELCOME TO NOUGHTS AND CROSSES\n\n";
	printInstructions();
	char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	
	// Determine who is first	
	char human = humanPiece();
	char computer = opponent(human);
	char turn = 'X';
	
	printBoard(board);
	std::cout << "\n" << std::endl;
	
	while (winner(board) == '0')
	{
		if (turn == human)
		{
			board[humanMove(board)] = human;
		}
		else
		{
			board[computerMove(board, computer)] = computer;
		}
		turn = opponent(turn);
		printBoard(board);
		std::cout << "\n" << std::endl;
	}
	
	announceWinner(winner(board), computer, human);
	
	return 0;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
		std::cout << "\nI win!\n";
	else if (winner == human)
		std::cout << "\nYou win!\n";
	else
		std::cout << "\nTie game!\n";
}

int computerMove(char* board, const char computer)
{
	int move = 0;
	bool solved = false;
	while (!solved && move < 9)
	{
		if (isLegal(board, move))
		{
			board[move] = computer;
			solved = winner(board) == computer;
			board[move] = ' ';
		}
		if (!solved)
			move++;
	}
	if (!solved)
	{
		move = 0;
		while (!solved && move < 9)
		{
			if (isLegal(board, move))
			{
				board[move] = opponent(computer);
				solved = winner(board) == opponent(computer);
				board[move] = ' ';
			}
			if (!solved)
				move++;
		}
	}
	if (!solved)
	{
		int bestMove[9] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
		move = 0;
		while(!solved && move < 9)
		{
			if (isLegal(board, bestMove[move]))
			{
				move = bestMove[move];
				solved = true;
			} else
			{
				move++;
			}
		}
	}
	return move;
}

int askNumber(int high, int low)
{
	int answer;
	bool first = true;
	std::cout << "Enter a number between " << low << " and " << high << ": ";
	do
	{
		if (!first)
			std::cout << "I didn't get that, try again: ";
		std::cin >> answer;
		first = false;
	} while ((answer < low) || (answer > high));
	return answer;
}

bool isLegal(const char* board, int move)
{
	return board[move] == ' ';
}

int humanMove(const char* board)
{
	std::cout << "\nYour move.\n";
	int	position;
	do
	{
		position = askNumber(9, 1) - 1;
	} while (!isLegal(board, position));
	
	return position;
}

char winner(const char* board)
{
	const int winning[8][3] = {	{0, 1, 2},
								{3, 4, 5},
								{6, 7, 8},
								{0, 4, 8},
								{2, 4, 6},
								{0, 3, 6},
								{1, 4, 7},
								{2, 5, 8}};
	const int totalWinning = 8;
	for (int i = 0; i < totalWinning; i++)
	{
		if ((board[winning[i][0]] != ' ') &&
			(board[winning[i][0]] == board[winning[i][1]]) &&
			(board[winning[i][1]] == board[winning[i][2]]))
			return board[winning[i][0]];
	}
	
	bool tie = true;
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
			tie = false;
	}
	if (tie)
		return 'T';
	return '0';
}

char opponent(char piece)
{
	if (piece == 'X')
		return 'O';
	return 'X';
}

char humanPiece()
{
	if(askYesNo("Do you need to go first?") == 'y')
		return 'X';
	return 'O';
}

char askYesNo(std::string question)
{
	char answer;
	std::cout << question << " (y/n): ";
	do
	{
		if (answer)
			std::cout << "I didn't get that, try again (y/n): ";
		std::cin >> answer;
	} while ((answer != 'y') && (answer != 'n'));
	return answer;
}

void printInstructions()
{
	std::cout << "Select a square by using the numbers 1-9:\n\n";
	char instructionBoard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	printBoard(instructionBoard);
	std::cout << std::endl;
}

void printBoard(const char* board)
{
	bool firstRow = true;
	for(int i = 0; i < 3; i++)
	{
		if (!firstRow)
			std::cout << "\n---------\n";
		firstRow = false;
		bool firstCol = true;
		for(int j = 0; j < 3; j++)
		{
			if (!firstCol)
				std::cout << " | ";
			std::cout << board[(3 * i) + j];
			firstCol = false;
		}
	}
}