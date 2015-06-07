/*********************************************************************
** Program Filename: Magician.hpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: This class holds all variables relating to the main character, including collected items.
** Input:  Menu choices
** Output: Prints inventory management to screen
*********************************************************************/
#ifndef MAGICIAN_HPP
#define MAGICIAN_HPP

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Magician
{
	private:
		int remainingTurns;
		double carryWeight; 
		bool chalkFlag,
			 candleFlag,
			 knifeFlag,
			 herbFlag,
			 runeFlag,
			 bookFlag;
	protected:
		struct Item
		{
			string label; 
			double weight;
			Item(string name, double w)
			{
				label = name;
				weight = w;
			}
		};
		vector<Item> itemList;
	public:
		Magician();
		void manageInventory();
		void viewItems();
		void addItem(string name, double w);
		void removeItem(int itemNum);
		void decreaseTurns();
		void readBook();
		bool finalFlagCheck();
		
		void setChalkFlag(bool f);
		void setCandleFlag(bool f);
		void setKnifeFlag(bool f);
		void setHerbFlag(bool f);
		void setRuneFlag(bool f);
		void setBookFlag(bool f);
		
		int getRemainingTurns();
		double getCarryWeight();
		bool getChalkFlag();
		bool getCandleFlag();
		bool getKnifeFlag();
		bool getHerbFlag();
		bool getRuneFlag();
		bool getBookFlag();
};
#endif