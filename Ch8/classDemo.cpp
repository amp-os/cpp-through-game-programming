// Class demo

#include <iostream>

class Critter
{
private:
	int m_Hunger;
	int m_Boredom;
public:
	Critter(int hunger = 0, int boredom = 5);
	void Greet();
	void SetHunger(int h);
	int GetHunger() const;
};

Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger), m_Boredom(boredom)
{
	std::cout << "New critter created" << std::endl;
}

int Critter::GetHunger() const
{
	return m_Hunger;
}

void Critter::SetHunger(int h)
{
	if (h < 0)
		std::cout << "Can't set critter's hunger to less than zero.\n";
	else
		m_Hunger = h;
}

void Critter::Greet()
{
	std::cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n";
	if (m_Boredom > 5)
		std::cout << "I'm bored.\n";
	else
		std::cout << "I'm content.\n";
}

int main()
{
	Critter	crit1;
	Critter crit2;
	
	crit1.SetHunger(9);
	crit1.Greet();
	
	crit2.SetHunger(-5);
	crit2.Greet();
	
	Critter crit3(7, 6);
	crit3.Greet();
	
	return 0;
}