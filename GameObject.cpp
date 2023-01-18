#include "GameObject.h"

//Default constructor.
GameObject::GameObject() {};

//Override constructor to specify location on the screen.
GameObject::GameObject(sf::Vector2f v2f_locationIn) {
	this->v2f_location = v2f_locationIn;
}

//Override the constructor to specify location, sprite and  texture.
GameObject::GameObject(sf::Vector2f v2f_locationIn, sf::Vector2f v2f_originIn)
{
	this->v2f_location = v2f_locationIn;

	this->v2f_origin = v2f_originIn;
}

//Set the location of the game object.
void GameObject::SetLocation(sf::Vector2f v2f_locationIn)
{
	this->v2f_location = v2f_locationIn;
}

//Get the location of the game object.
sf::Vector2f GameObject::getLocation()
{
	return v2f_location;
}

//Get the sprite after loading it in.
sf::Sprite GameObject::gameObjectSprite(std::string s_imageLocation)
{
	tex.loadFromFile(s_imageLocation);
	sprite.setTexture(tex);
	return sprite;
}

float GameObject::groundSpeedInput()
{
	return 0.0f;
}



