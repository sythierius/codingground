/*********************************************************************
** Program Filename: StorageRoom.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Child class of Manor. One of the many rooms in the manor that the player navigates.
** Input:  Menu choices
** Output: Descriptions of the room and menus to interact with the room
*********************************************************************/
#include "StorageRoom.hpp"

using std::cout;
using std::endl;
using std::cin;


void StorageRoom::setNavNodes(Manor *n, Manor *s, Manor *e, Manor *w)
{
	room.north = n;
	room.south = s;
	room.east = e;
	room.west = w;
}

void StorageRoom::enter(Magician *player)
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
		cout << "Location: Storage Room" << endl;
		cout << "Turns remaining: " << player->getRemainingTurns() << endl;
		cout << "Carry weight: " << player->getCarryWeight() << "/30"<< endl;
		cout << endl;
		
		// Room Description
		cout << "                      The Storage Room:" << endl;
		cout << "  A useful room full of extra magical ingredients and supplies" << endl;
		cout << " to keep the manor running, as well as boxes of family memorabilia." << endl;
		cout << " To the (E) is the Main Hall, and to the (S) lies the Laundry Room." << endl;
		cout << endl;
		
		// Story
		cout << " Syth entered the storage room and was overwhelmed by the amount" << endl;
		cout << "  of junk piled into the room. His parents would force Syth to" << endl;
		cout << "  clean and organize the room when he misbehaved. The worst part" << endl;
		cout << "  of the task was that it could never actually be accomplished." << endl;
		cout << "  The storage room simply had too many things in it to ever be" << endl;
		cout << " organized. Syth looked through old boxes and found a big, framed" << endl;
		cout << "    picture of himself at his 13th birthday with his friends." << endl;
		
		// Menu for Room
		cout << endl;
		cout << "What should the magician do?" << endl;
		cout << "1. Move (E) to the Main Hall" << endl;
		cout << "2. Move (S) to the Laundry Room" << endl;
		cout << "3. Examine the photograph" << endl;
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
			
			case 3: // Examine photograph
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				int itemChoice;
				
				cout << endl;
				cout << "  Syth remembered the birthday well. He had a great party" << endl;
				cout << " for his 13th birthday, but did little on his 14th and 15th" << endl;
				cout << "     birthdays. He missed his friends badly right now." << endl;
				cout << endl;
				cout << "Do you want to pick up the photograph?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cin >> input;
				
				// Item Choice Input validation
				do
				{
					itemChoice = input;
					if (static_cast<double>(itemChoice) == input && cin.fail() == false && itemChoice > 0 && itemChoice <= 2)
					{
						flag = true;
					}
					else
					{
						flag = false;
						cin.clear();
						cin.ignore(1000,'\n');
						cout << "Invalid selection. Please enter an integer 1-2." << endl;
						cin >> input;
					}
				} while (flag == false);
			
				if (itemChoice == 1)
				{
					cout << " Syth acquired the photograph and stashed it in his satchel." << endl;
					player->addItem("Birthday Photo", 3);
				}
				
				cin.clear();
				cin.ignore(1000,'\n');
				
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