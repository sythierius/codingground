/*********************************************************************
** Program Filename: MainHall.hpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Child class of Manor. One of the many rooms in the manor that the player navigates.
** Input:  Menu choices
** Output: Descriptions of the room and menus to interact with the room
*********************************************************************/
#ifndef MAINHALL_HPP
#define MAINHALL_HPP

#include <iostream>
#include "Manor.hpp"
#include "Magician.hpp"

class MainHall : public Manor
{
	private:
		struct Exits
		{
			Manor *north,
				  *south,
				  *east,
				  *west;
		};
		Exits room;
	public:
		virtual void enter(Magician *player);  
		void setNavNodes(Manor *n, Manor *s, Manor *e, Manor *w);
};
#endif