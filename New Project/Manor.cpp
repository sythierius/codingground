/*********************************************************************
** Program Filename: Manor.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Abstract class used to develop child classes (rooms) in the manor
** Input:  None
** Output: None
*********************************************************************/
#include "Manor.hpp"

using std::cout;
using std::endl;

void Manor::clearScreen()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "\n \n \n \n" << endl; 
	}
}