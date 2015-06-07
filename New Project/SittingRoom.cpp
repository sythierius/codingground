/*********************************************************************
** Program Filename: SittingRoom.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Child class of Manor. One of the many rooms in the manor that the player navigates.
** Input:  Menu choices
** Output: Descriptions of the room and menus to interact with the room
*********************************************************************/
#include "SittingRoom.hpp"

using std::cout;
using std::endl;
using std::cin;


void SittingRoom::setNavNodes(Manor *n, Manor *s, Manor *e, Manor *w)
{
	room.north = n;
	room.south = s;
	room.east = e;
	room.west = w;
}

void SittingRoom::enter(Magician *player)
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
		cout << "Location: Sitting Room" << endl;
		cout << "Turns remaining: " << player->getRemainingTurns() << endl;
		cout << "Carry weight: " << player->getCarryWeight() << "/30"<< endl;
		cout << endl;
		
		// Room Description
		cout << "                        The Sitting Room:" << endl;
		cout << "  The sitting room is the large central room of the second floor." << endl;
		cout << " To the (E) is the Study, and to the (W) is Syth's parent's room." << endl;
		cout << "   To the (S), connected to his parent's room, lies Syth's room." << endl;
		cout << "   To the (N) is a stairway leading downstairs to the Main Hall." << endl;
		cout << endl;
		
		// Story
		cout << " Syth entered the huge Sitting Room and took a seat on one of the" << endl;
		cout << "   Chimera hide couches. The room was full of extravagant decor" << endl;
		cout << " and furniture on top of luxurious rugs. This room had always been" << endl;
		cout << " Syth's favorite room to relax in while studying. The large stained" << endl;
		cout << " glass window to the south painted the room with an array of color." << endl;
		cout << "  Syth looked at the detailed dragon whelp statue on the table in" << endl;
		cout << "   front of him and remembered playing with it as a small child." << endl;
		
		// Menu for Room
		cout << endl;
		cout << "What should the magician do?" << endl;
		cout << "1. Move (N) downstairs to the Main Hall" << endl;
		cout << "2. Move (S) to Syth's room" << endl;
		cout << "3. Move (E) to the Study" << endl;
		cout << "4. Move (W) to Syth's parent's room" << endl;
		cout << "5. Examine the dragon whelp statue" << endl;
		cout << "6. Read Demonology Tome" << endl;
		cout << "7. Manage Inventory" << endl;
		cin >> input;
				
		// Menu Selection Input validation
		do
		{
			selection = input;
			if (static_cast<double>(selection) == input && cin.fail() == false && selection > 0 && selection <= 7)
			{
				flag = true;
			}
			else
			{
				flag = false;
				cin.clear();
				cin.ignore(1000,'\n');
				cout << "Invalid selection. Please enter an integer 1-7." << endl;
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
			
			case 3: // Move east
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
			
			case 4: // Move west
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
			case 5: // Examine dragon statue
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				int itemChoice;
				
				cout << endl;
				cout << "  The baby dragon looked too adorable to be a ferocious" << endl;
				cout << " beast, but that never stopped Syth from portraying it as" << endl;
				cout << "  a monster for knights and mages to battle as a child." << endl;
				cout << endl;
				cout << "Do you want to pick up the dragon statue?" << endl;
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
					cout << " Syth acquired the dragon whelp statue and stashed it in his satchel." << endl;
					player->addItem("Dragon Whelp Statue", 3);
				}
				
				cin.clear();
				cin.ignore(1000,'\n');
				
				cout << "Press enter to continue..." << endl;
				cin.get();
				
				break;
			}
			
			case 6: // Read book
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				player->readBook();
				break;
			}
			
			case 7: // Manage Inventory
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				player->manageInventory();
				break;
			}
		}	
	} while (selection!=1 && selection!=2 && selection!=3 && selection!=4); // end menu
}