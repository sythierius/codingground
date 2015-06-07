/*********************************************************************
** Program Filename: Manor.hpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Abstract class used to develop child classes (rooms) in the manor
** Input:  None
** Output: None
*********************************************************************/
#ifndef MANOR_HPP
#define MANOR_HPP

#include <iostream>
#include <string>
#include "Magician.hpp"

using std::string;

class Manor
{
	private:
	protected:
	public:
		virtual void enter(Magician *player) = 0; 
		void clearScreen();
};
#endif