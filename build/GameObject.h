#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <string>
class GameObject {
private:
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


	//*****To be overridden********//
	virtual float groundSpeed() {
		return groundSpeed;
	}

	//*****To be overridden********//
	virtual void groundSpeed(float tankSpeedIn) {
		this->groundSpeed;
	}

	//*****To be overridden********//
	virtual float tankSpeed() {
		return tankSpeed;
	}

	//*****To be overridden********//
	virtual void tankSpeed(float tankSpeedIn) {
		this->tankSpeed;
	}
};
