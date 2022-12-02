
#include<iostream>
#include<string>
#include <SFML/Window.hpp>
#include "./build/GameObject.h"
#include "./build/GoodPlayer.h"

int main()
{
	sf::Window window(sf::VideoMode(800, 600), "My window");
	std::unique_ptr<GoodPlayer> gp;
	gp = std::unique_ptr<GoodPlayer>(new GoodPlayer());
	gp->setResistance(100.f);
	std::cout << gp->f_Resistance << std::endl;
	system("pause");
	return 0;
};