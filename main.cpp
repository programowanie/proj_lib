#include "lib.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{	
	long int _seedValue = atoi(argv[1]);
	long int* seedValue = &_seedValue;
	srand(time(seedValue));

	Player firstPlayer = Player();
	Player secondPlayer = Player();

	Player* winner = game(&firstPlayer, &secondPlayer);

	cout << "~~~~ ZWYCIEZCA\t\t" << winner->name() 
	<< "\t\tZWYCIEZCA ~~~~" << endl;
}