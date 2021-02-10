#include <SFML/Graphics.hpp>
#include <random>
#include "structs.h"
#include <vector>

sf::Vector2f normalize(sf::Vector2f vec);

class Animal
{

public:
	sf::RectangleShape rect;
	sf::Vector2f velocity, range, maxSpeed, location, size;
	float health = 100;

	//manual constructor
	virtual void construct();

	void move();

	virtual bool isCarnivore();

	bool intersecting(Animal* animal2);

	bool isNear(Animal * animal2);

	virtual void seekFood(Animal* target);

};

class Herbivore : public Animal
{
	void construct();
};

class Carnivore : public Animal
{
	void construct();

	bool isCarnivore();

	void seekFood(Animal* target);
};