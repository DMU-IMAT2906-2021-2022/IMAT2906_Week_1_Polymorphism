
#include<iostream>
#include<string>

class Vector {
	protected:
		float x;
		float y;
	
	public:
		//Default class defintion.
		Vector() {};

		//Constructor overload.
		Vector(float x, float y) {
			this->x = x;
			this->y = y;
		};

		//Changing the position of the vector. 
		void changePosition(const float &x, const float &y) {
			this->x = this->x + x;
			this->y = this->y + y;
		};

		//Outputing the vector as a built in string.
		void outputVector() {
			std::cout << "The position of the starship is " << x << "and" << y << std::endl;
		}
};


class GameObject {
	public:	
		std::string s_ObjectName;
		float f_Speed, f_Resistance;
		float f_Attack;
		Vector position;
	
	public:
		GameObject() {};
		~GameObject() {};

		//Overloading constructor.
		GameObject(float f_SpeedIn, float f_ResistanceIn) {
			f_Speed = f_SpeedIn;
			f_Resistance = f_ResistanceIn;
		};

		//Setting the name of the object.
		void setName(std::string s_ObjectName) {
			this->s_ObjectName = s_ObjectName;
		};

		//Virtual member function that allows overloading for polymorphism.
		virtual float attack(){
			this->f_Attack = f_Speed + f_Resistance;
			return f_Attack;
		};
};

class GoodPlayer : public GameObject {
	protected:
		std::string s_Allegiance;
	public:
		//Overloading the GoodPlayer class.
		GoodPlayer(float f_Speed, float f_Resistance) {
			this->f_Speed = f_Speed;
			this->f_Resistance = f_Resistance;
		};

		GoodPlayer(float f_Attack) {
			this->f_Attack = f_Attack;
		};

		//Function to set the allegiance of the player.
		void setAllegiance(std::string s_Allegiance){
			this->s_Allegiance = s_Allegiance;
		}

		//overriding the attack member function. The override keyword shows to other programmers 
		//that this is an overridden method. If the method is different then an error is thrown.
		float attack () override {
			this->f_Attack = f_Speed - (f_Resistance * 0.5f);
			return f_Attack;
		};

};


int main()
{
	
	GoodPlayer gp(100.f, 10.f);
	gp.setName("Good Player One");
	gp.setAllegiance("Highest");


	system("pause");
	return 0;
};