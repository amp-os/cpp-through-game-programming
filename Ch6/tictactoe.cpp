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
int cornerOpening(const char* board);

enum {	TOP_LEFT = 0,
		TOP_CENTRE,
		TOP_RIGHT,
		MIDDLE_LEFT,
		MIDDLE_CENTRE,
		MIDDLE_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_CENTRE,
		BOTTOM_RIGHT,
		TOTAL_SQUARES};
		
const char NO_ONE = '0';

int main()
{
	// Set up game
	std::cout << "WELCOME TO NOUGHTS AND CROSSES\n\n";
	printInstructions();
	char board[TOTAL_SQUARES] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	
	// Determine who is first	
	char human = humanPiece();
	char computer = opponent(human);
	char turn = 'X';
	
	printBoard(board);
	std::cout << "\n" << std::endl;
	
	// Game loop
	while (winner(board) == NO_ONE)
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

int movesMade(const char* board)
{
	int numMoves = 0;
	for (int i = 0; i < TOTAL_SQUARES; i++)
	{
		if (board[i] != ' ')
			numMoves++;
	}
	return numMoves;
}

int openingPosition(const char* board)
{
	if (movesMade(board) != 1) // if this is not the first move
		return -1; // early escape
	
	int pos;
	const int numCorners = 4;
	int corners[numCorners] = {TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT};
	for (int i = 0; i < TOTAL_SQUARES; i++)
	{
		if (board[i] != ' ')
			pos = i;
	}
	return pos;
}

int computerMove(char* board, const char computer)
{
	int move = 0;
	bool solved = false;
	while (!solved && move < TOTAL_SQUARES)
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
		while (!solved && move < TOTAL_SQUARES)
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
		int bestDefense[TOTAL_SQUARES] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
		int* bestMove = bestDefense;
		
		int defaultOpening[TOTAL_SQUARES] = {0, 8, 2, 6, 4, 1, 3, 5, 7};
		
		// Defend against the corners opening
		
		if (computer == 'O') // if the computer moves second
		{
			static int pos;
			if (movesMade(board) == 1) // if it is the first turn
				pos = openingPosition(board); // get the first move
			if (movesMade(board) == 3) // if it is the computer's second move
			{
				switch (pos)
				{
					case TOP_LEFT:
						bestMove[1] = TOP_CENTRE;
						bestMove[2] = MIDDLE_LEFT;
						break;
					case TOP_RIGHT:
						bestMove[1] = TOP_CENTRE;
						bestMove[2] = MIDDLE_RIGHT;
						break;
					case BOTTOM_LEFT:
						bestMove[1] = BOTTOM_CENTRE;
						bestMove[2] = MIDDLE_RIGHT;
						break;
					case BOTTOM_RIGHT:
						bestMove[1] = BOTTOM_CENTRE;
						bestMove[2] = MIDDLE_LEFT;
						break;
					default:
						break; // do not change defense
				}
			}
		}
		else if (computer == 'X') // Play corners opening
		{
			bestMove = defaultOpening;
		}
		
		move = 0;
		while(!solved && move < TOTAL_SQUARES)
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
	const int totalWinning = 8;
	const int winning[totalWinning][3] = {	{0, 1, 2},
											{3, 4, 5},
											{6, 7, 8},
											{0, 4, 8},
											{2, 4, 6},
											{0, 3, 6},
											{1, 4, 7},
											{2, 5, 8}};

	for (int i = 0; i < totalWinning; i++)
	{
		if ((board[winning[i][0]] != ' ') &&
			(board[winning[i][0]] == board[winning[i][1]]) &&
			(board[winning[i][1]] == board[winning[i][2]]))
			return board[winning[i][0]];
	}
	
	bool tie = true;
	for (int i = 0; i < TOTAL_SQUARES; i++)
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
	char instructionBoard[TOTAL_SQUARES] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	printBoard(instructionBoard);
	std::cout << "\n" << std::endl;
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