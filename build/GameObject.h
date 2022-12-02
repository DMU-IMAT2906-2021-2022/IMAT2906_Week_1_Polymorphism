#pragma once
#include<string>
#include"SFML/System.hpp"
#include"SFML/Graphics.hpp"
class GameObject {
private:
	std::string s_ObjectName;
	sf::Vector2f sfV2_position;

public:
	float f_Speed, f_Resistance, f_Attack;

	GameObject() {
		f_Speed = 0;
		f_Resistance = 0;
		f_Attack = 0;
	};
	~GameObject() {};

	//Overloading constructor.
	GameObject(float f_SpeedIn, float f_ResistanceIn, float f_AttackIn) {
		f_Speed = f_SpeedIn;
		f_Resistance = f_ResistanceIn;
		f_Attack = f_AttackIn;
	};

	//Setting the name of the object.
	void setName(std::string s_ObjectNameIn) {
		s_ObjectName = s_ObjectNameIn;
	};

	//Virtual member function that allows overloading for polymorphism.
	virtual float attack() {
		f_Attack = f_Speed + f_Resistance;
		return f_Attack;
	};

	//Setters
	void setSpeed(float f_SpeedIn) {
		f_Speed = f_SpeedIn;
	}

	//Setters
	void setResistance(float f_ResistanceIn) {
		f_Resistance = f_ResistanceIn;
		std::cout << "Resistance" << std::endl;
	}

	//Setters
	void setAttack(float f_AttackIn) {
		f_Attack = f_AttackIn;
	}

};
