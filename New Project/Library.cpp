/*********************************************************************
** Program Filename: Library.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Child class of Manor. One of the many rooms in the manor that the player navigates.
** Input:  Menu choices
** Output: Descriptions of the room and menus to interact with the room
*********************************************************************/
#include "Library.hpp"

using std::cout;
using std::endl;
using std::cin;

void Library::setNavNodes(Manor *n, Manor *s, Manor *e, Manor *w)
{
	room.north = n;
	room.south = s;
	room.east = e;
	room.west = w;
}

void Library::enter(Magician *player)
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
		cout << "Location: Library" << endl;
		cout << "Turns remaining: " << player->getRemainingTurns() << endl;
		cout << "Carry weight: " << player->getCarryWeight() << "/30"<< endl;
		cout << endl;
		
		// Room Description
		cout << "                                The Library:" << endl;
		cout << "       The library has bookshelves lining the (W), (S), and (E) walls." << endl;
		cout << "   Light shines in through windows above the bookshelves at the (E) and (S)." << endl;
		cout << endl;
		
		// Story
		cout << " Sythierius (Syth) had studied diligently to become a magician since he was born, " << endl;
		cout << "      but what he really wanted was to escape the manor and make friends." << endl;
		cout << "       He had never asked to be a magician. It was just common practice " << endl;
		cout << "              for sorcerers and sorceresses to raise magicians." << endl;
		cout << "         Syth sighed and gazed at the plethora of tomes in the room," << endl;
		cout << "                  until one caught his eye. Demonology." << endl;
		cout << "  His parents had told him Demonology was to be learned at age 21 and no earlier." << endl;
		cout << "Syth: If they do not permit me to leave and make a friend, I will summon one here." << endl;
		
		if (player->getBookFlag() == false)
		{
			cout << "           Syth acquired the tome and stashed it in his satchel." << endl;
			player->addItem("Demonology Tome", 4);
			player->setBookFlag(true);
		}
		
		// Menu for Room
		cout << endl;
		cout << "What should the magician do?" << endl;
		cout << "1. Move (N) to the Study" << endl;
		cout << "2. Read Demonology Tome" << endl;
		cout << "3. Manage Inventory" << endl;
		cin >> input;
				
		// Menu Selection Input validation
		do
		{
			selection = input;
			if (static_cast<double>(selection) == input && cin.fail() == false && selection > 0 && selection <= 3)
			{
				flag = true;
			}
			else
			{
				flag = false;
				cin.clear();
				cin.ignore(1000,'\n');
				cout << "Invalid selection. Please enter an integer 1-3." << endl;
				cin >> input;
			}
		} while (flag == false);
	
		switch (selection)
		{
			case 1: // Move
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
			
			case 2: // Read book
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				player->readBook();
				break;
			}
			
			case 3: // Manage inventory
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				player->manageInventory();
				break;
			}
		}	
	} while (selection!=1); // end menu
}