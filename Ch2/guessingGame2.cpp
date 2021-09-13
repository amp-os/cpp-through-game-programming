// Guess the number

#include <iostream>

int main()
{	
	std::cout << "\nNow you think of a number between 1-100..." << std::endl;
	
	int lowestGuess = 0;
	int highestGuess = 100;
	int count = 0;
	char success = 'n';
	
	do
	{
		int bestGuess = lowestGuess + ((highestGuess - lowestGuess) / 2);
		std::cout << "\nIs the number " << bestGuess << "? (y/n) ";
		std::cin >> success;
		count++;
		
		if (success == 'y') {
			std::cout << "\nI knew it!" << std::endl;
			std::cout << "It only took me " << count << " tries." << std::endl;
		}
		else
		{
			enum highLow {TOO_HIGH = 1, TOO_LOW};
			int myHighLow;
			
			do
			{
				std::cout << "Okay then, was I\n";
				std::cout << "TOO HIGH? - press " << TOO_HIGH;
				std::cout << "\nor\nTOO LOW? - press " << TOO_LOW << std::endl;
				
				std::cin >> myHighLow;
				
				switch (myHighLow)
				{
					case TOO_HIGH:
						highestGuess = bestGuess - 1;
						break;
					case TOO_LOW:
						lowestGuess = bestGuess + 1;
						break;
					default:
						std::cout << "I didn't quite get that..." << std::endl;
				}
				if (lowestGuess - highestGuess > 0)	
				{
					std::cout << "I think someone's cheating... GOODBYE." << std::endl;
					success = 'y';
					break;
				}
			} while (myHighLow != TOO_HIGH && myHighLow != TOO_LOW);
		}
	
	} while (success != 'y');
	
	return 0;
}