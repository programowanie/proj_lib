#pragma once
#include <string>

using namespace std;

class Player
{	
	string _name;
	int _sobriety, _accuracy, _speed, _agility;

public:

	Player();
	//getery
	string name(){return _name;};
	int sobriety(){return _sobriety;};
	int accuracy(){return _accuracy;};
	int speed(){return _speed;};
	int agility(){return _agility;};
	//setery
	void setSobriety(int newSobriety);
	void setAccuracy(int newAccuracy);
	void setSpeed(int newSpeed);
	void setAgility(int newAgility);

};

Player game(Player*, Player*); //przyjmie dwoch graczy i wykona symulacje