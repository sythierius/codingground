/*********************************************************************
** Program Filename: Magician.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: This class holds all variables relating to the main character, including collected items.
** Input:  Menu choices
** Output: Prints inventory management to screen
*********************************************************************/
#include "Magician.hpp"

using std::cout;
using std::endl;
using std::cin;

Magician::Magician()
{
	remainingTurns = 26;
	carryWeight = 0;
	chalkFlag = false;
	candleFlag = false;
	knifeFlag = false;
	herbFlag = false;
	runeFlag = false;
	bookFlag = false;
}

void Magician::manageInventory()
{
	double input;
	int selection;
	bool flag = false;
	
	do
	{
		this->viewItems();
		
		cout << endl;
		cout << "Would you like to remove an item?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No (exit inventory)" << endl;
		cin >> input;
		
		// Menu Selection Input validation
		do
		{
			selection = input;
			if (static_cast<double>(selection) == input && cin.fail() == false && selection > 0 && selection <= 2)
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
	
		switch (selection)
		{
			case 1: // Remove item
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				int itemNum;
				
				cout << "Which item do you wish to remove? (Input item number)" << endl;
				cin >> input;
		
				// Item Number Input validation
				do
				{
					itemNum = input;
					if (static_cast<double>(itemNum) == input && cin.fail() == false && itemNum > 0 && itemNum <= itemList.size())
					{
						flag = true;
					}
					else
					{
						flag = false;
						cin.clear();
						cin.ignore(1000,'\n');
						cout << "Invalid item number. Please enter an integer 0-" << itemList.size() << endl;
						cin >> input;
					}
				} while (flag == false);
				
				this->removeItem(itemNum);
				break;
			}
			
			case 2: // Exit
			{
				cin.clear();
				cin.ignore(1000,'\n');
				
				break;
			}
		}
	} while (selection != 2);
}

void Magician::viewItems()
{
	int size = itemList.size();
	
	if (size = 0)
	{
		cout << endl;
		cout << "There are no items in the satchel." << endl;
	}
	else
	{
		cout << endl;
		cout << "Carry weight: " << carryWeight << "/30" << endl;
		cout << "Satchel Contents:" << endl;
		
		for (int i = 0; i < itemList.size(); i++)
		{
			cout << endl;
			cout << "Item Number: " << i << endl;
			cout << "  Item Name: " << itemList[i].label << endl;
			cout << "     Weight: " << itemList[i].weight << endl;
		}
	}
}

void Magician::addItem(string name, double w)
{
	itemList.push_back(Item(name, w));
	carryWeight += w;
}

void Magician::removeItem(int itemNum)
{
	int size = itemList.size();
	
	if (size = 0 || itemList[itemNum].label == "Demonology Tome")
	{
		cout << endl;
		cout << "You cannot remove that item." << endl;
	}
	else
	{
		if (itemList[itemNum].label == "Chalk")
		{
			this->setChalkFlag(false);
		}
		
		if (itemList[itemNum].label == "Candle")
		{
			this->setCandleFlag(false);
		}
		
		if (itemList[itemNum].label == "Knife")
		{
			this->setKnifeFlag(false);
		}
		
		if (itemList[itemNum].label == "Herbs")
		{
			this->setHerbFlag(false);
		}
		
		if (itemList[itemNum].label == "Runes")
		{
			this->setRuneFlag(false);
		}
		
		carryWeight -= itemList[itemNum].weight;
		itemList.erase(itemList.begin() + itemNum);
	}
}

void Magician::decreaseTurns()
{
	remainingTurns--;
}

void Magician::readBook()
{
	cout << endl;
	cout << "             Page 394 - Summoning Demons" << endl;
	cout << endl;
	cout << "  Summoning a demon is a task to be performed only by " << endl;
	cout << " experienced magic users. This chapter has incantations" << endl;
	cout << "      to summon three different types of demons." << endl;
	cout << endl;
	cout << "                  Required Ingredients" << endl;
	cout << "   To summon a demon, you will need five ingredients:" << endl;
	cout << "1. Chalk: To draw a summoning circle" << endl;
	cout << "2. Candles: Set around the perimeter of circle and lit" << endl;
	cout << "3. Herbs: Preferably aromatic, placed around circle" << endl;
	cout << "4. Summoning Runes: Placed in center of circle" << endl;
	cout << "5. Blood of summoner: Dripped onto runes" << endl;
	cout << "         (Pictures of each ingredient are here)" << endl;
	cout << endl;
	cout << "                     Incantations" << endl;
	cout << "1. The Imp: A weak demon, good for errands/chores" << endl;
	cout << "   Incantation: Appello daemon et servus meus erit" << endl;
	cout << endl;
	cout << "2. Lesser Demon: A strong demon, suitable for labor" << endl;
	cout << "   Incantation: Sit servus meus parva daemonium" << endl;
	cout << endl;
	cout << "3. Greater Demon: Used for wars *WARNING - VERY DEADLY*" << endl;
	cout << "   Incantation: Pervenire magnifica demonium veniat pacifice" << endl;
	cout << endl;
	cout << "Press enter to continue..." << endl;
	cin.get(); // Pause screen
}

bool Magician::finalFlagCheck()
{
	if (candleFlag == true && chalkFlag == true && herbFlag == true && knifeFlag == true && runeFlag == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Magician::setChalkFlag(bool f)
{
	chalkFlag = f;
}

void Magician::setCandleFlag(bool f)
{
	candleFlag = f;
}

void Magician::setKnifeFlag(bool f)
{
	knifeFlag = f;
}

void Magician::setHerbFlag(bool f)
{
	herbFlag = f;
}

void Magician::setRuneFlag(bool f)
{
	runeFlag = f;
}

void Magician::setBookFlag(bool f)
{
	bookFlag = f;
}
		
int Magician::getRemainingTurns()
{
	return remainingTurns;
}

double Magician::getCarryWeight()
{
	return carryWeight;
}

bool Magician::getChalkFlag()
{
	return chalkFlag;
}

bool Magician::getCandleFlag()
{
	return candleFlag;
}

bool Magician::getKnifeFlag()
{
	return knifeFlag;
}

bool Magician::getHerbFlag()
{
	return herbFlag;
}

bool Magician::getRuneFlag()
{
	return runeFlag;
}

bool Magician::getBookFlag()
{
	return bookFlag;
}