#pragma once
#include "GameObject.h"
class GoodPlayer : public GameObject {
protected:
	std::string s_Allegiance;
	GameObject* go;

public:

	GoodPlayer() {
		go = new GameObject();
		std::cout << "Constructor" << std::endl;
	};
	//Overloading the GoodPlayer class.
	GoodPlayer(float f_SpeedIn, float f_ResistanceIn) {

		//go = new GameObject();
		go->setSpeed(f_SpeedIn);
		go->setResistance(f_ResistanceIn);
	};
	~GoodPlayer() {};

	GoodPlayer(float f_AttackIn) {
		go->setAttack(f_AttackIn);
	};

	//overriding the attack member function. The override keyword shows to other programmers 
	//that this is an overridden method. If the method is different then an error is thrown.
	float attack() override {
		return go->f_Resistance;
	};

};
