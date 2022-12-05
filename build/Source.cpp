#include<iostream>
#include<string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

sf::Color colour = sf::Color::Green;
sf::Vector2f v2fMove(0.0f, 0.0f);

int main()
{
	struct
	{
		float topLeft;
		float bottomRight;
		float width;
		float height;
	}spriteLocation;


	sf::RenderWindow window(sf::VideoMode(1540, 900, 32), "Lab Week 1 - Polymorphism"); //Draw an SFML window.
	sf::Texture texture;
	sf::Sprite sprite;

	//Construct the sprite 
	spriteLocation.topLeft = 0.f;
	spriteLocation.bottomRight = 100.f;
	spriteLocation.width = 100.f;
	spriteLocation.height = 100.f;

	const float f_FPS = 60.0f; //The desired FPS. (The number of updates each second).
	bool b_redraw = true;      //Do I redraw everything on the screen?

	window.setFramerateLimit(f_FPS);
	sf::Clock clock;

	if (!texture.loadFromFile("Spaceship_01_BLUE.png", sf::IntRect(0, 0, 500, 500)))
	{
		std::cout << "No ship found" << std::endl;
	}
	else if (texture.loadFromFile("Spaceship_01_BLUE.png", sf::IntRect(0, 0, 500, 500))) {
	}

	sprite.setOrigin(sf::Vector2f(250.f, 250.f));

	//sprite.setTextureRect(sf::IntRect(spriteLocation.topLeft, spriteLocation.bottomRight, spriteLocation.width, spriteLocation.height));//Set the initial position of the sprite.

	while (window.isOpen())
	{
		//Wait until 1/60th of a second has passed, then update everything.
		if (clock.getElapsedTime().asSeconds() >= 1.0f / f_FPS)
		{
			b_redraw = true; //We're ready to redraw everything
			clock.restart();
			sprite.move(v2fMove);
		}
		//Check if the window is open or closed.
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			//Move the sprite based on the key pressed.
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					v2fMove = sf::Vector2f(0.0f, -1.f);
				}
				if (event.key.code == sf::Keyboard::S)
				{
					v2fMove = sf::Vector2f(0.0f, 1.f);
				}
				if (event.key.code == sf::Keyboard::A)
				{
					sprite.rotate(1.f);
				}
				if (event.key.code == sf::Keyboard::D)
				{
					sprite.rotate(-1.f);					
				}

			}
		}

		//Draw to the window
		if (b_redraw)
		{
			b_redraw = false;
			window.clear();

			//Draw the sprite
			//sprite.setTexture(texture);
			sprite.setScale(sf::Vector2f(0.25f, 0.25f));
			sprite.setTexture(texture);
			window.draw(sprite);
			window.display();
		}
	}
};
