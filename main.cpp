#include "Animal.h"

void addAnimal(int amount, std::vector<Animal*> &animals, int type)
{
	if (type == HERBIVORE)
	{

		for (int i = 0; i < amount; i++)
		{

			animals.push_back(new Herbivore());
		}
	}

	else if (type == CARNIVORE)
	{
		for (int i = 0; i < amount; i++)
		{

			animals.push_back(new Carnivore());
		}
	}
}

void hunt(Animal* i, std::vector<Animal*> &animals)
{
	for (int j = 0; j < animals.size(); j++)
	{
		if (i != animals[j])
		{
			if (i->intersecting(animals[j]))
			{
				if (!animals[j]->isCarnivore())
				{
					animals.erase(animals.begin() + j);
					//return after an animal has been hunted
					return;
				}
			}

			if (i->isNear(animals[j]))
			{
				if (!animals[j]->isCarnivore())
				{
					i->seekFood(animals[j]);
				}
			}
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREENX, SCREENY), "Ecosystem Simulation");
	window.setFramerateLimit(60);

	std::vector <Animal*> animals;
	addAnimal(3, animals, CARNIVORE);
	addAnimal(40, animals, HERBIVORE);

	for (auto* i : animals)
	{
		i->construct();
	}

	while (window.isOpen())
	{
		window.clear();

		for (auto* i : animals)
		{
			window.draw(i->rect);
			i->move();
			if (i->isCarnivore())
			{
				hunt(i, animals);
			}
		}

		window.display();
	}

	return 0;
}