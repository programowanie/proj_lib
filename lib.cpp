#include "lib.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <unistd.h>

const int N = 2 ;

using namespace std;

string Player::namesOne[5] = { "Szymon", "Pawel", "Mateusz", "Dorian", "Mariusz"};
string Player::namesTwo[5] = {"Artur", "Krzysiek", "Michal", "Wojtek", "Tomek"};
int Player::_counter = 0;

void Player::setSobriety(int newSobriety)
{
	_sobriety = newSobriety;
}
void Player::setAccuracy(int newAccuracy)
{
	_accuracy = newAccuracy;
}
void Player::setCanFilling(int newCanFilling)
{
	_canFilling = newCanFilling;
}

void Player::showStatistics()
{
	cout << "~~" << _name << "~~\ttrzezwosc: |" 
	<< _sobriety << "|\tcelnosc: |" << _accuracy 
	<< "|\tszybkosc picia: |" << _drinkingSpeed 
	<< "| (lyki/trafienie)\tnapelnienie puszki: |" << _canFilling
	<< "| (lyki)" << endl;
}
Player::Player()
{	

	if(_counter%2)
	{
		_name = namesOne[rand()%5];
	}
	else
	{
		_name = namesTwo[rand()%5];
	}
	
	_sobriety = rand()%91 + 5;
	_accuracy = rand()%91 + 5;
	_canFilling = 30;
	_drinkingSpeed = rand()%6 +5;
	_counter++;
}

Player* game(Player* theFirst, Player* theSecond)
{
	cout << endl << "Puszka na srodku! Rozpoczyna sie walka!" << endl;
	sleep(N);

	theFirst->showStatistics();
	sleep(N);
	theSecond->showStatistics();
	sleep(N);

	while(theFirst->sobriety() > 0 &&
		theSecond->sobriety() > 0 && 
		theFirst->canFilling() > 0 &&
		theSecond->canFilling() > 0 &&
		theFirst->accuracy() > 0 &&
		theSecond->accuracy() > 0)
	{	
		bool ifThrow = rand()%101 < theFirst->accuracy();
		cout << theFirst->name()
		<< ((ifThrow) ? (" trafia w puszke i pije!") : (" pudluje!")) << endl;
		sleep(N);

		if(ifThrow)
		{	
			theFirst->setSobriety(theFirst->sobriety() - theFirst->drinkingSpeed());
			theFirst->setAccuracy(theFirst->accuracy() - ((100 - theFirst->sobriety()) * 0.2));
			theFirst->setCanFilling(theFirst->canFilling() - theFirst->drinkingSpeed());
			if(theFirst->canFilling() <=0)
			{
				cout << theFirst->name() << " wypil swoje piwo i zostal zwyciezca!" << endl;
				sleep(N);
				
				return theFirst;
			}
			if(theFirst->sobriety() > 0 &&
				theFirst->canFilling() > 0 &&
				theFirst->accuracy() > 0 ) 
			{
				theFirst->showStatistics();
				sleep(N);
			}
			else
			{
				cout << theFirst->name() << " jest zbyt pijany by grac! Zwyciezca to "
				<< theSecond->name() << "!" << endl;
				sleep(N);

				return theSecond;
			}
		}

		ifThrow = rand()%101 < theSecond->accuracy();
		cout << theSecond->name()
		<< ((ifThrow) ? (" trafia w puszke i pije!") : (" pudluje!")) << endl;
		sleep(N);

		if(ifThrow)
		{
			theSecond->setSobriety(theSecond->sobriety() - theSecond->drinkingSpeed());
			theSecond->setAccuracy(theSecond->accuracy() - ((100 - theSecond->sobriety()) * 0.2));
			theSecond->setCanFilling(theSecond->canFilling() - theSecond->drinkingSpeed());
			if(theSecond->canFilling() <= 0)
			{
				cout << theSecond->name() << " wypil swoje piwo i zostal zwyciezca!" << endl;
				sleep(N);

				return theSecond;
			}
			if(theSecond->sobriety() > 0 &&
				theSecond->canFilling() > 0 &&
				theSecond->accuracy() > 0 ) 
			{
				theSecond->showStatistics();
				sleep(N);

			}
			else
			{
				cout << theSecond->name() << " jest zbyt pijany by grac! Zwyciezca to "
				<< theFirst->name() << "!" << endl;
				sleep(N);

				return theFirst;
			}
		}
	}
}