#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <string>
class GameObject {
protected:
	sf::Vector2f v2f_location;
	sf::Vector2f v2f_origin;
	sf::Sprite sprite;
	sf::Texture tex;
	sf::Image image;
	float tankSpeed = 0;
	float groundSpeed = 0;

public:
	//Default constructor.
	GameObject();

	//Override constructor to specify location on the screen.
	GameObject(sf::Vector2f v2f_locationIn);

	//Override the constructor to specify location, sprite and  texture.
	GameObject(sf::Vector2f v2f_locationIn, sf::Vector2f v2f_originIn);

	//Set location.
	void SetLocation(sf::Vector2f v2f_locationIn);

	//Get location.
	sf::Vector2f getLocation();

	//Get the sprite of the tank.
	sf::Sprite gameObjectSprite(std::string s_imageLocation);

	//*****To be overridden********//
	virtual float groundSpeedInput();

	//*****To be overridden********//
	virtual int groundSpeedIn(float tankSpeedIn) {
		this->groundSpeed = tankSpeedIn;
		return tankSpeed;
	};

	//*****To be overridden********//
	virtual float tankSpeedIn() {
		return tankSpeed;
	};

	//*****To be overridden********//
	virtual void tankSpeedIn(float tankSpeedIn) {
		this->tankSpeed = tankSpeedIn;
	};
};
