// Critter game

#include <iostream>

class Critter
{
private:
	int m_Boredom;
	int m_Hunger;
	
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);

private:
	int GetMood() const;
	void PassTime(int time = 1);	
};

Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger), m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return m_Hunger + m_Boredom;
}

void Critter::Eat(int food)
{
	std::cout << "Munch munch.\n";
	m_Hunger = (m_Hunger - food) < 0 ? 0 : m_Hunger - food;
	PassTime();
}

void Critter::Play(int fun)
{
	std::cout << "Wheee!\n";
	m_Boredom = (m_Boredom - fun) < 0 ? 0 : m_Boredom - fun;
	PassTime();
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	std::cout << "I'm a critter and I feel ";
	int mood = GetMood();
	if (mood > 15)
		std::cout << "mad.\n";
	else if (mood > 10)
		std::cout << "frustrated.\n";
	else if (mood > 5)
		std::cout << "okay.\n";
	else
		std::cout << "happy.\n";
	PassTime();
}

int main()
{
	Critter crit;
	crit.Talk();
	
	int choice;
	do
	{
		std::cout << "\nCritter Caretaker\n\n";
		std::cout << "0 - Quit\n";
		std::cout << "1 - Listen to your critter\n";
		std::cout << "2 - Feed your critter\n";
		std::cout << "3 - Play with your critter\n";
		
		std::cout << "Choice: ";
		std::cin >> choice;
		
		switch (choice)
		{
			case 0:
				std::cout << "Good-bye.\n";
				break;
			case 1:
				crit.Talk();
				break;
			case 2:
				crit.Eat();
				break;
			case 3:
				crit.Play();
				break;
			default:
				std::cout << "\nSorry, but " << choice << " is not a valid option.\n";
		}
	} while (choice != 0);
	
	return 0;
}