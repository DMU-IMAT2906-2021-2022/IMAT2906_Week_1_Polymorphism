#include<iostream>
#include<string>
#include "GameObject.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


sf::Color colour = sf::Color::Green;
sf::Vector2f v2fMove(0.0f, 0.0f);

int main()
{

	sf::RenderWindow window(sf::VideoMode(1540, 900, 32), "Lab Week 1 - Polymorphism"); //Draw an SFML window.
	sf::Texture playerTexture,turretTexture;
	sf::Sprite playerSprite, turretSprite;

	//Game object creation example.
	GameObject* go_bigTank = new GameObject(sf::Vector2f(450.f, 450.f), sf::Vector2f(250.f, 250.f));
	

	const float f_FPS = 60.0f; //The desired FPS. (The number of updates each second).
	bool b_redraw = true;      //Do I redraw everything on the screen?

	window.setFramerateLimit(f_FPS);
	sf::Clock clock;

	if (!playerTexture.loadFromFile("tankBlue.png"))
	{
		std::cout << "No files." << std::endl;
	}
	else if (playerTexture.loadFromFile("tankBlue.png")) {
		turretTexture.loadFromFile("tankBlue_barrel.png");
	}

	//Origin of the sprite, position on the screen and initial rotation.
	playerSprite.setOrigin(sf::Vector2f(250.f, 250.f));
	playerSprite.setPosition(sf::Vector2f(500.f, 500.f));
	turretSprite.setOrigin(sf::Vector2f(4.f, 0.f));
	turretSprite.setPosition(250.f+21.f,250.f+21.f);

	//Set the texture of the sprite.
	turretSprite.setTexture(turretTexture);
	playerSprite.setTexture(playerTexture);

	while (window.isOpen())
	{
		//Wait until 1/60th of a second has passed, then update everything.
		if (clock.getElapsedTime().asSeconds() >= 1.0f / f_FPS)
		{
			std::cout << v2fMove.y << std::endl;
			b_redraw = true; //We're ready to redraw everything
			clock.restart();

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
					playerSprite.move(sf::Vector2f(0, -1.f));
					turretSprite.move(sf::Vector2f(0, -1.f));
				}
				if (event.key.code == sf::Keyboard::S)
				{
					playerSprite.move(sf::Vector2f(0, 1.f));
					turretSprite.move(sf::Vector2f(0, 1.f));
				}
				if (event.key.code == sf::Keyboard::A)
				{
					turretSprite.rotate(1.f);
				}
				if (event.key.code == sf::Keyboard::D)
				{
					turretSprite.rotate(-1.f);					
				}
			}
		}

		//Draw to the window
		if (b_redraw)
		{
			b_redraw = false;
			window.clear();

			//Draw the sprite
			window.draw(playerSprite);
			window.draw(turretSprite);
			window.display();
		}
	}
};
