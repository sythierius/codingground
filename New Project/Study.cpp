/*********************************************************************
** Program Filename: Study.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Child class of Manor. One of the many rooms in the manor that the player navigates.
** Input:  Menu choices
** Output: Descriptions of the room and menus to interact with the room
*********************************************************************/
#include "Study.hpp"

using std::cout;
using std::endl;
using std::cin;

void Study::setNavNodes(Manor *n, Manor *s, Manor *e, Manor *w)
{
	room.north = n;
	room.south = s;
	room.east = e;
	room.west = w;
}

void Study::enter(Magician *player)
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
		cout << "Location: Study" << endl;
		cout << "Turns remaining: " << player->getRemainingTurns() << endl;
		cout << "Carry weight: " << player->getCarryWeight() << "/30"<< endl;
		cout << endl;
		
		// Room Description
		cout << "                           The Study:" << endl;
		cout << " The study has 3 desks, two against the (E) wall and one on the (N)." << endl;
		cout << "A table sits in the middle of the room, and a chalkboard at the (N)." << endl;
		cout << " The exit to the (W) leads to the Sitting Room. The Library is (S)." << endl;
		cout << endl;
		
		// Story
		cout << "Syth entered the Study and saw the various books cluttered on the" << endl;
		cout << "    center table. Mostly magical healing and alchemy books." << endl;
		cout << "    His mother was a sorceress with a focus on healing, and" << endl;
		cout << "       his father's passion as a sorcerer was in alchemy." << endl;
		cout << " Their advanced skills were what made the king request their aid." << endl;
		cout << "  Syth's favorite subject so far had been Biomagistry, which was" << endl;
		cout << "     the study of magic's influence on life. Syth noticed the" << endl;
		cout << "       chalkboard by his desk on the north side of the room." << endl;
		
		// Menu for Room
		cout << endl;
		cout << "What should the magician do?" << endl;
		cout << "1. Move (W) to the Sitting Room" << endl;
		cout << "2. Move (S) to the Library" << endl;
		cout << "3. Examine the chalkboard" << endl;
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
			case 1: // Move west
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
				
				room.west->enter(player);
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
			
			case 3: // Examine chalkboard
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				cout << endl;
				cout << " On the chalkboard was a drawing Syth had done earlier" << endl;
				cout << "  of a Unicorn, one of his favorite magical creatures." << endl;
				cout << "  Beneath the chalkboard were several pieces of chalk." << endl;
				
				if (player->getChalkFlag() == false)
				{
					cout << " Syth acquired the chalk and stashed it in his satchel." << endl;
					player->addItem("Chalk", 1);
					player->setChalkFlag(true);
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