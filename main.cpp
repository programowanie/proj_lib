#include "lib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{	
	srand((argc == 2) ? atoi(argv[1]) : time(NULL));

	Player firstPlayer = Player();
	Player secondPlayer = Player();

	Player* winner = game(&firstPlayer, &secondPlayer);

	cout << "~~~~ ZWYCIEZCA\t\t" << winner->name() 
	<< "\t\tZWYCIEZCA ~~~~" << endl;
}