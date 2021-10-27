// Inheritance demo

#include <iostream>

class Enemy
{
protected:
	int m_Damage;
	
public:
	Enemy();
	void Attack() const;
};

Enemy::Enemy()
	: m_Damage(10)
{
	std::cout << "Enemy constructor called.\n";
}

void Enemy::Attack() const
{
	std::cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
	int m_DamageMultiplier;
	
public:
	Boss();
	void SpecialAttack() const;
};

Boss::Boss()
	: m_DamageMultiplier(3)
{
	std::cout << "Boss constructor called.\n";
}

void Boss::SpecialAttack() const
{
	std::cout << "Special Attack inflicts " << m_DamageMultiplier * m_Damage;
	std::cout << " damage points!\n";
}

int main()
{
	std::cout << "Creating enemy...\n";
	Enemy enemy1;
	enemy1.Attack();
	
	std::cout << "Creating boss...\n";
	Boss boss1;
	boss1.Attack();
	boss1.SpecialAttack();
	
	return 0;
}