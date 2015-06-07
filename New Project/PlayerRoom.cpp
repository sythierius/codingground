/*********************************************************************
** Program Filename: PlayerRoom.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Child class of Manor. One of the many rooms in the manor that the player navigates.
** Input:  Menu choices
** Output: Descriptions of the room and menus to interact with the room
*********************************************************************/
#include "PlayerRoom.hpp"

using std::cout;
using std::endl;
using std::cin;


void PlayerRoom::setNavNodes(Manor *n, Manor *s, Manor *e, Manor *w)
{
	room.north = n;
	room.south = s;
	room.east = e;
	room.west = w;
}

void PlayerRoom::enter(Magician *player)
{
	// Declare variables
	double input;
	int selection;
	bool flag;
	
	// Clear Screen
	this->clearScreen();
	
	// Decrease Turn Count
	player->decreaseTurns();
	
	// Check if player is out of turns
	if (player->getRemainingTurns() <= 0)
	{
		cout << endl;
		cout << " You have run out of turns! Syth's parents come home," << endl;
		cout << "     and he is unable to complete the summoning." << endl;
		cout << endl;
		cout << "Press enter to end the game..." << endl;
		cin.get();
		return;
	}
	
	// Loop for Room
	do
	{
		// Print status
		cout << "Location: Syth's Room" << endl;
		cout << "Turns remaining: " << player->getRemainingTurns() << endl;
		cout << "Carry weight: " << player->getCarryWeight() << "/30"<< endl;
		cout << endl;
		
		// Room Description
		cout << "                            Sythierius' Room:" << endl;
		cout << "   Syth's room is much like a standard bedroom, with his bed/nightstand" << endl;
		cout << " at the (SW) corner. The dresser is next to the nightstand. To the (N) is" << endl;
		cout << " a door leading to his parent's room, and to the (E) is the Sitting Room." << endl;
		cout << endl;
		
		// Story
		cout << "  Syth entered his room and plopped himself on his harpy feather bed." << endl;
		cout << "  He thought about the few times he was allowed to have friends stay" << endl;
		cout << "    the night. They would talk and laugh all night about the most" << endl;
		cout << "     random things, people they liked, books they enjoyed, their" << endl;
		cout << " favorite creatures. Syth sighed and thought about summoning the demon." << endl;
		cout << "   It wouldn't be the same, but it would be better than nothing. Syth" << endl;
		cout << "  glanced at his nightstand and saw the candle atop it, and remembered" << endl;
		cout << "     he had many spare candles in the bottom drawer of his dresser." << endl;
		
		// Menu for Room
		cout << endl;
		cout << "What should the magician do?" << endl;
		cout << "1. Move (N) to Syth's parent's room" << endl;
		cout << "2. Move (E) to the Sitting Room" << endl;
		cout << "3. Examine the dresser" << endl;
		cout << "4. Read Demonology Tome" << endl;
		cout << "5. Manage Inventory" << endl;
		cin >> input;
				
		// Menu Selection Input validation
		do
		{
			selection = input;
			if (static_cast<double>(selection) == input && cin.fail() == false && selection > 0 && selection <= 5)
			{
				flag = true;
			}
			else
			{
				flag = false;
				cin.clear();
				cin.ignore(1000,'\n');
				cout << "Invalid selection. Please enter an integer 1-5." << endl;
				cin >> input;
			}
		} while (flag == false);
	
		switch (selection)
		{
			case 1: // Move north
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				while(player->getCarryWeight() > 30)
				{
					cout << endl;
					cout << "You are over-encumbered! Please manage your inventory." << endl;
					cout << "Press enter to continue..." << endl;
					cin.get();
					player->manageInventory();
				}
				
				room.north->enter(player);
				break;
			}
			
			case 2: // Move east
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				while(player->getCarryWeight() > 30)
				{
					cout << endl;
					cout << "You are over-encumbered! Please manage your inventory." << endl;
					cout << "Press enter to continue..." << endl;
					cin.get();
					player->manageInventory();
				}
				
				room.east->enter(player);
				break;
			}
			
			case 3: // Examine dresser
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				cout << endl;
				cout << "  Syth opened the bottom drawer of his mahogany dresser." << endl;
				cout << " Inside were many candles and other various knick knacks." << endl;
				
				if (player->getCandleFlag() == false)
				{
					cout << " Syth acquired the candles and stashed them in his satchel." << endl;
					player->addItem("Candles", 3);
					player->setCandleFlag(true);
				}
				
				cout << "Press enter to continue..." << endl;
				cin.get();
				
				break;
			}
			
			case 4: // Read book
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				player->readBook();
				break;
			}
			
			case 5: // Manage Inventory
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				player->manageInventory();
				break;
			}
		}	
	} while (selection!=1 && selection!=2); // end menu
}