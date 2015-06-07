/*********************************************************************
** Program Filename: ParentRoom.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Child class of Manor. One of the many rooms in the manor that the player navigates.
** Input:  Menu choices
** Output: Descriptions of the room and menus to interact with the room
*********************************************************************/
#include "ParentRoom.hpp"

using std::cout;
using std::endl;
using std::cin;

void ParentRoom::setNavNodes(Manor *n, Manor *s, Manor *e, Manor *w)
{
	room.north = n;
	room.south = s;
	room.east = e;
	room.west = w;
}

void ParentRoom::enter(Magician *player)
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
		cout << "Location: Syth's Parent's Room" << endl;
		cout << "Turns remaining: " << player->getRemainingTurns() << endl;
		cout << "Carry weight: " << player->getCarryWeight() << "/30"<< endl;
		cout << endl;
		
		// Room Description
		cout << "                   Sythierius' Parent's Room:" << endl;
		cout << "  A grandiose bedroom full of magical gadgets and memorabilia." << endl;
		cout << " The bed is at the (NW) corner. To the (S) is a door to Syth's" << endl;
		cout << "          room. To the (E) is the massive Sitting Room." << endl;
		cout << endl;
		
		// Story
		cout << " Syth didn't enter his parent's room often, so he was still taken" << endl;
		cout << "   aback at the multitude of interesting objects on the shelves" << endl;
		cout << "  in the room. His parents had been many places on their travels." << endl;
		cout << "    No doubt, every object had an interesting story behind it." << endl;
		cout << "  Syth was jealous of all that his parent's had done, and wanted" << endl;
		cout << "  desperately to venture out into the world. Instead, the world" << endl;
		cout << "  he knew was the one his mind had painted about the stories he " << endl;
		cout << " read. Syth noticed a crate of runes beneath one of the shelves." << endl;
		
		// Menu for Room
		cout << endl;
		cout << "What should the magician do?" << endl;
		cout << "1. Move (E) to the Sitting Room" << endl;
		cout << "2. Move (S) to Syth's room" << endl;
		cout << "3. Examine the crate of runes" << endl;
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
			case 1: // Move east
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
			
			case 2: // Move south
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
				
				room.south->enter(player);
				break;
			}
			
			case 3: // Examine crate of runes
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				cout << endl;
				cout << "  Syth opened the crate of runes and the Demonology tome." << endl;
				cout << " He compared the pictures in the book to the runes he laid" << endl;
				cout << "  out onto the floor. Syth identified the correct runes." << endl;
				
				if (player->getRuneFlag() == false)
				{
					cout << " Syth acquired the runes and stashed them in his satchel." << endl;
					cout << "         His satchel was noticeably heavier." << endl;
					player->addItem("Runes", 10);
					player->setRuneFlag(true);
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