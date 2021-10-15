// Friend function demo

#include <iostream>
#include <string>

class Critter
{
	friend void Peek(const Critter& aCritter);
	friend std::ostream& operator<<(std::ostream& os, const Critter& aCritter);
public:
	Critter(const std::string& name = "");
	
private:
	std::string m_Name;
};

Critter::Critter(const std::string& name) :
	m_Name(name)
{}

void Peek(const Critter& aCritter);
std::ostream& operator<<(std::ostream& os, const Critter& aCritter);

int main()
{
	Critter crit("Poochie");
	
	std::cout << "Calling Peek() to access crit's private data member m_Name:\n";
	Peek(crit);
	
	std::cout << "\nSending crit object to cout with the << operator:\n";
	std::cout << crit << std::endl;
	
	return 0;
}

void Peek(const Critter& aCritter)
{
	std::cout << aCritter.m_Name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Critter& aCritter)
{
	os << "Critter Object - ";
	os << "m_Name: " << aCritter.m_Name;
	return os;
}