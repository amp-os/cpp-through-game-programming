// Overloading inheritance

#include <iostream>

class Enemy
{
private:
	int m_Damage;
public:
	Enemy(int damage = 10);
	void virtual Taunt() const; // must be overridden
	void virtual Attack() const;
};

Enemy::Enemy(int damage)
	: m_Damage(damage)
{}

void Enemy::Taunt() const
{
	std::cout << "They enemy says he will fight you.\n";
}

void Enemy::Attack() const
{
	std::cout << "Attack! Inflicts " << m_Damage << " damage points.\n";
}

class Boss : public Enemy
{
public:
	Boss(int damage = 30);
	void virtual Taunt() const;
	void virtual Attack() const;
};

Boss::Boss(int damage)
	: Enemy(damage) // call base class constructor
{}

void Boss::Taunt() const
{
	std::cout << "The boss says he gun win, bruh.\n";
}

void Boss::Attack() const
{
	Enemy::Attack();
	std::cout << "And he laughs heartily at you.\n"; 
}

int main()
{
	std::cout << "Enemy object:\n";
	Enemy anEnemy;
	anEnemy.Taunt();
	anEnemy.Attack();
	
	std::cout << "\n\nBoss object:\n";
	Boss aBoss;
	aBoss.Taunt();
	aBoss.Attack();
	
	return 0;
}