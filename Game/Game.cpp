#include <iostream>

bool play = true;
int playerArmor = 5;
int playerHealth = 10;
int playerInput = 0;
int trollHealth = 5;
int trollStamina = 3;

//when player attacks, take away some of the troll stamina and health
void Attack(int* trollHealth, int* trollStamina)
{
	if ((*trollStamina) > 0)
	{
		(*trollStamina)--;
	}

	if ((*trollHealth) > 2)
	{
		(*trollHealth) -= 2;
	}
	
	if ((*trollHealth) == 1)
	{
		(*trollHealth)--;
	}

}

//when player defends take away some of the troll stamina and a little bit of player health
int Defend()
{
	return 0;
}

int main()
{
	//create some pointers to the troll health and stamina
	int* trollHealth_ptr = &trollHealth;
	int* trollStamina_ptr = &trollStamina;


	while (play)
	{
		std::cout << "\n--------------- Player -------------------------\n";
		std::cout << "[armor] " << playerArmor << "\n";
		std::cout << "[health] " << playerHealth << "\n";
		std::cout << "--------------- Troll -------------------------\n";
		std::cout << "[stamina] " << trollStamina << "\n";
		std::cout << "[health] " << trollHealth << "\n\n";

		std::cout << "A wild troll has appeared! (1) attack (2) defend (9) quit\n";
		std::cin >> playerInput;

		switch (playerInput)
		{
		case 1:
			Attack(trollHealth_ptr, trollStamina_ptr);
			break;
		case 2:
			Defend();
			break;
		default:
			"Oops you did nothing, the troll attacked you!\n";
			playerHealth--;
		}

	}
	return 0;
}
