#pragma once
#include <string>

using namespace std;


class Player
{	
	string _name;
	int _sobriety, _accuracy, _canFilling, _drinkingSpeed;

	static string namesOne[5];
	static string namesTwo[5];
	static int _counter;

public:

	Player();

	//getery
	string name(){return _name;};
	int sobriety(){return _sobriety;};
	int accuracy(){return _accuracy;};
	int canFilling(){return _canFilling;};
	int drinkingSpeed(){return _drinkingSpeed;};
	
	//setery
	void setSobriety(int newSobriety);
	void setAccuracy(int newAccuracy);
	void setCanFilling(int newCanFilling);

	void showStatistics();

};

//przyjmie dwoch graczy i wykona symulacje
Player* game(Player*, Player*); 
