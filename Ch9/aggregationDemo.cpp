// Aggregation Demo

#include <iostream>
#include <string>
#include <vector>

class Critter
{
public:
	Critter(const std::string& name = "");
	const std::string& GetName() const;
private:
	std::string m_Name;
};

Critter::Critter(const std::string& name):
	m_Name(name)
{}

inline const std::string& Critter::GetName() const
{
	return m_Name;
}

class Farm
{
public:
	Farm(int spaces = 1);
	void Add(const Critter& aCritter);
	void RollCall() const;
private:
	std::vector<Critter> m_Critters; // Note creates copies as is a vector of objects not pointers
};

Farm::Farm(int spaces)
{
	m_Critters.reserve(spaces);
}

void Farm::Add(const Critter& aCritter)
{
	m_Critters.push_back(aCritter);
}

void Farm::RollCall() const
{
	for (std::vector<Critter>::const_iterator iter = m_Critters.begin();
		iter != m_Critters.end(); ++iter)
	{
		std::cout << iter->GetName() << " here.\n";
	}
}

int main()
{
	Critter crit("Poochie");
	std::cout << "My critter's name is " << crit.GetName() << std::endl;
	
	std::cout << "\nCreating critter farm.\n";
	Farm myFarm(3);
	
	std::cout << "\nAdding a critter to the farm.\n";
	myFarm.Add(Critter("Moe"));
	
	std::cout << "\nCall roll...\n";
	myFarm.RollCall();
	
	std::cout << "\nAdding a critter to the farm.\n";
	myFarm.Add(crit);
	
	std::cout << "\nAdding a critter to the farm.\n";
	myFarm.Add(Critter("Larry"));
	
	std::cout << "\nCall roll...\n";
	myFarm.RollCall();
	
	return 0;
}