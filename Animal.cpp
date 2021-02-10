#include "Animal.h"

sf::Vector2f normalize(sf::Vector2f vec)
{
	float mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));

	sf::Vector2f normal;

	normal.x = vec.x / mag;
	normal.y = vec.y / mag;

	return normal;
}

//manual constructor
void Animal::construct()
{
	location.x = std::rand() % SCREENX;
	location.y = std::rand() % SCREENY;
	size = sf::Vector2f(20, 20);

	rect = sf::RectangleShape(size);
	rect.setPosition(location);
}
void Animal::move()
	{
		if (location.x < 0)
		{
			location.x = 0;
			velocity.x *= -1;
		}
		else if (location.x > SCREENX)
		{
			location.x = SCREENX;
			velocity.x *= -1;
		}

		if (location.y < 0)
		{
			location.y = 0;
			velocity.y *= -1;
		}
		else if (location.y > SCREENY)
		{
			location.y = SCREENY;
			velocity.y *= -1;
		}

		location.x += velocity.x;
		location.y += velocity.y;

		rect.setPosition(location);
	}
bool Animal::isCarnivore()
{
	return false;
};
bool Animal::intersecting(Animal* animal2)
	{
		float disX = location.x - animal2->location.x;
		float disY = location.y - animal2->location.y;

		if (abs(disX) < range.x && abs(disY) < range.y)
		{
			return true;
		}
		return false;
	}
bool Animal::isNear(Animal* animal2)
	{
		float disX = location.x - animal2->location.x;
		float disY = location.y - animal2->location.y;

		if (abs(disX) < range.x * 6 && abs(disY) < range.y * 6)
		{
			return true;
		}
		return false;
	}
void Animal::seekFood(Animal* target)
	{
		
	};


void Herbivore::construct()
	{
		Animal::construct();
		range = sf::Vector2f(5, 5);
		maxSpeed = sf::Vector2f(2, 2);

		velocity.x = 2;
		velocity.y = 2;

		rect.setFillColor(sf::Color::Blue);
	}

void Carnivore::construct()
	{
		Animal::construct();
		range = sf::Vector2f(10, 10);
		maxSpeed = sf::Vector2f(5, 5);

		velocity.x = 5;
		velocity.y = 5;
		rect.setFillColor(sf::Color::Red);
	}
bool Carnivore::isCarnivore()
	{
		return true;
	}
void Carnivore::seekFood(Animal* target)
	{
		Animal food = *target;

		food.location.x -= location.x;
		food.location.y -= location.y;

		sf::Vector2f targetVel = normalize(food.location);

		targetVel.x *= maxSpeed.x;
		targetVel.y *= maxSpeed.x;

		velocity = targetVel;
	}
