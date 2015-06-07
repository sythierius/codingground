/*********************************************************************
** Program Filename: MainHall.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Child class of Manor. One of the many rooms in the manor that the player navigates.
** Input:  Menu choices
** Output: Descriptions of the room and menus to interact with the room
*********************************************************************/
#include "MainHall.hpp"

using std::cout;
using std::endl;
using std::cin;


void MainHall::setNavNodes(Manor *n, Manor *s, Manor *e, Manor *w)
{
	room.north = n;
	room.south = s;
	room.east = e;
	room.west = w;
}

void MainHall::enter(Magician *player)
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
		cout << "Location: The Main Hall" << endl;
		cout << "Turns remaining: " << player->getRemainingTurns() << endl;
		cout << "Carry weight: " << player->getCarryWeight() << "/30"<< endl;
		cout << endl;
		
		// Room Description
		cout << "                         The Main Hall:" << endl;
		cout << " The spiral staircase leads down to the (NE) corner of the room." << endl;
		cout << "  The Main Hall is a magnificent open room that connects to the" << endl;
		cout << "   Dining Room to the (E) and the Storage Room to the (W). The " << endl;
		cout << "    laundry room in the (S) is adjacent to the Storage Room." << endl;
		cout << endl;
		
		// Story
		cout << "  Syth entered the Main Hall. The light coming through the windows" << endl;
		cout << "  beside the large mahogany arch door on the south end of the room " << endl;
		cout << " shone brilliantly over the waxed marble floor. Syth thought of the" << endl;
		cout << "  parties that his parents would host in the room. There was never" << endl;
		cout << "  anyone his age. Due to the open nature of the room, Syth decided" << endl;
		cout << "   this would likely be a suitable room to perform the summoning." << endl;
		cout << "     The large circular rug near the door would be a good spot." << endl;
		
		// Menu for Room
		cout << endl;
		cout << "What should the magician do?" << endl;
		cout << "1. Move (N) upstairs to the Sitting Room" << endl;
		cout << "2. Move (S) to the Laundry Room" << endl;
		cout << "3. Move (E) to the Dining Room" << endl;
		cout << "4. Move (W) to the Storage Room" << endl;
		cout << "5. Perform the Summoning Ritual " << endl;
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
			case 5: // Perform ritual
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				int choice;
				
				// End ritual if player doesn't have required items
				if (player->finalFlagCheck() == false)
				{
					cout << endl;
					cout << "Syth does not yet have all the required ingredients." << endl;
					cout << "Press enter to continue..." << endl;
					cin.get();
					break;
				}
				
				// Clear the screen
				this->clearScreen();
				
				// Perform ritual
				cout << endl;
				cout << "  Syth dragged the large black rug into the center of the room" << endl;
				cout << "   and drew a large circle in the middle with the chalk, then " << endl;
				cout << "   placed and lit the candles around the circle. He sprinkled " << endl;
				cout << " the herbs around the circle and placed the runes in the center." << endl;
				cout << "            This was it. Time to perform the ritual." << endl;
				cout << "  Syth raised the knife to his palm, which trembled and hovered" << endl;
				cout << "     over the runes, and he began to recite the incantation:" << endl;
				cout << endl;
				
				cout << "1. Appello daemon et servus meus erit" << endl; // imp
				cout << "2. Sit servus meus parva daemonium" << endl; // lesser demon
				cout << "3. Pervenire magnifica demonium veniat pacifice" << endl; // greater demon
				cout << "4. Wuss out (Cancel)" << endl;
				cin >> input;
				
				// Incantation Input validation
				do
				{
					choice = input;
					if (static_cast<double>(choice) == input && cin.fail() == false && choice > 0 && choice <= 4)
					{
						flag = true;
					}
					else
					{
						flag = false;
						cin.clear();
						cin.ignore(1000,'\n');
						cout << "Invalid incantation. Please enter an integer 1-4." << endl;
						cin >> input;
					}
				} while (flag == false);
			
				this->clearScreen();
			
				// Endings
				if (choice == 1) // Summon Imp
				{
					cout << "   Syth makes an incision into his palm and the blood drips over" << endl;
					cout << "             the runes as he recites the incantation:" << endl;
					cout << "               Appello daemon et servus meus erit." << endl;
					cout << " A small figure emerges from the circle. The imp looks up at Syth." << endl;
					cout << endl;
					cout << " Imp: Are you my new master?" << endl;
					cout << "Syth: I guess, but I was thinking of being your friend instead." << endl;
					cout << " Imp: I've never had a friend. Only masters." << endl;
					cout << "Syth: I know how you feel. Let's get you some clothes and food." << endl;
					cout << " Imp: Thank you, master." << endl;
					cout << "Syth: It's Sythierius. I'll call you Chet. Nice to meet you, Chet." << endl;
					cout << endl;
					cout << " Syth and Chet had a great time until his parents got home. While" << endl;
					cout << "  his parents were very angry at first, they calmed down and were " << endl;
					cout << " actually impressed by his abilities and allowed Syth to keep Chet." << endl;
					cout << endl;
					cout << " Congratulations on navigating Sceptine Manor and completing the game!" << endl;
				}
				if (choice == 2) // Summon Lesser Demon
				{
					cout << "       Syth slashes into his palm and the blood drips over" << endl;
					cout << "             the runes as he recites the incantation:" << endl;
					cout << "                 Sit servus meus parva daemonium." << endl;
					cout << "  A large figure emerges from the circle. The demon looks at Syth." << endl;
					cout << endl;
					cout << "Demon: You... A child... Summoned me?" << endl;
					cout << " Syth: Yes, I want a friend. If you want to leave, I'd understand." << endl;
					cout << "Demon: A friend... I suppose I can do that. Is this your first summon?" << endl;
					cout << " Syth: Great! I'm glad you're friendly. Yes, this is my first summon." << endl;
					cout << "Demon: I could tell. There's a slight break in your circle." << endl;
					cout << " Syth: It's good you're friendly then. Let's go have fun!" << endl;
					cout << endl;
					cout << "  Syth and the lesser demon had a great time. The demon left back to" << endl;
					cout << " his realm shortly before Syth's parents arrived back from their trip." << endl;
					cout << " They never suspected a thing, and Syth would summon the demon several" << endl;
					cout << " more times in the future when his parents would leave for their trips." << endl;
					cout << endl;
					cout << " Congratulations on navigating Sceptine Manor and completing the game!" << endl;
				}
				if (choice == 3) // Summon Greater Demon
				{
					cout << "       Syth slashes into his palm and the blood drips over" << endl;
					cout << "             the runes as he recites the incantation:" << endl;
					cout << "           Pervenire magnifica demonium veniat pacifice." << endl;
					cout << "   A giant, grotesque figure emerges from the circle and laughs." << endl;
					cout << endl;
					cout << "Demon: HAHAHA! BABY MEAT!" << endl;
					cout << " Syth: Demon, I would like a friend. Will you be my friend?" << endl;
					cout << "Demon: HAHAHA! AMATEUR! YOU LOOK DELICIOUS!" << endl;
					cout << " *The Demon notices a break in the circle and steps out towards Syth*" << endl;
					cout << " Syth: Back, Demon! Please return to your realm!" << endl;
					cout << "Demon: YOU TALK TOO MUCH." << endl;
					cout << " Syth: AAAGGGGGHHHHHHHHH! NOOOOO!" << endl;
					cout << endl;
					cout << "      Syth was torn to shreds and devoured by the greater demon." << endl;
					cout << " His parents came home to blood and bones scattered all over the marble" << endl;
					cout << " floor. They found the Demonology tome in his satchel and began to cry." << endl;
					cout << "        They had told him not to, but he had done it anyway." << endl;
					cout << endl;
					cout << " Congratulations on navigating Sceptine Manor and completing the game!" << endl;
				}
				if (choice == 4) // wuss out
				{
					cout << endl;
					cout << "Syth hesitates and steps away." << endl;
					cin.clear();
					cin.ignore(1000,'\n');
					cout << "Press enter to continue..." << endl;
					cin.get();
					break;
				}
				
				cin.clear();
				cin.ignore(1000,'\n');
				cout << endl;
				cout << "Press enter to end the game..." << endl;
				cin.get();
				
				// Perform game exit sequence
				selection = 99;
				return;
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
	} while (selection!=1 && selection!=2 && selection!=3 && selection!=4 && selection!=99); // end menu
}