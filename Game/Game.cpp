#include <iostream>

bool play = true;
int playerArmor = 5;
int playerHealth = 10;
int playerInput = 0;
int trollHealth = 5;
int trollStamina = 5;

class Player {

	int playerHealth;
	int playerArmor;

public:

	//set the health and stamina
	Player()
	{
		playerHealth = 10;
		playerArmor = 5;
	}

	int getArmor()
	{
		std::cout << "player armor: " << playerArmor << "\n";
		return playerArmor;
	}

	int getHealth()
	{
		return playerHealth;
	}
};

class Troll {
	int stamina = 5;
	int health = 10;

public:
	//constructor
	Troll() {
		stamina = 5;
		health = 10;
	}
	int getHealth() {
		return health;
	}

	int getStamina() {
		return stamina;
	}
};


//when player attacks, take away some of the troll stamina and health
void Attack(Troll* troll)
{
	if (troll->getStamina() > 0)
	{
		trollStamina--;
	}

	if (troll->getHealth() > 2)
	{
		trollHealth -= 2;
	}
	
	if (troll->getHealth() == 1)
	{
		trollHealth--;
	}

}

//when player defends take away some of the troll stamina and a little bit of player health
int Defend(int& trollStamina)
{
	//take away stamina
	trollStamina -= 3;

	//clamp the value at 0 
	if (trollStamina < 0)
	{
		trollStamina = 0;
	}

	return 0;
}

int main()
{
	Player player;
	Troll troll;

	while (play)
	{
		std::cout << "\n--------------- Player -------------------------\n";
		player.getArmor();
		std::cout << "[health] " << playerHealth << "\n";
		std::cout << "--------------- Troll -------------------------\n";
		std::cout << "[stamina] " << trollStamina << "\n";
		std::cout << "[health] " << trollHealth << "\n\n";

		std::cout << "A wild troll has appeared! (1) attack (2) defend (9) quit\n";
		std::cin >> playerInput;

		switch (playerInput)
		{
		case 1:
			Attack(troll);
			break;
		case 2:
			Defend(trollStamina);
			break;
		default:
			"Oops you did nothing, the troll attacked you!\n";
			playerHealth--;
		}

	}
	return 0;
}
