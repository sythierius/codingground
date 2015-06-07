/*********************************************************************
** Program Filename: launcher.cpp
** Author: Charles Bennett
** Date: 5/31/15
** Description: Main function. Creates objects for each room and establishes their pointer variables, then starts the game.
** Input:  cin. Menu selections.
** Output: cout. Print menu and prompts to console.
*********************************************************************/
#include "Manor.hpp"
#include "DiningRoom.hpp"
#include "Kitchen.hpp"
#include "LaundryRoom.hpp"
#include "Library.hpp"
#include "Magician.hpp"
#include "MainHall.hpp"
#include "ParentRoom.hpp"
#include "PlayerRoom.hpp"
#include "SittingRoom.hpp"
#include "StorageRoom.hpp"
#include "Study.hpp"
#include "Wall.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// MAIN
int main()
{
	// Create Magician (syth)
	Magician *syth = new Magician;
	
	// Create room objects
	DiningRoom *dining = new DiningRoom;
	Kitchen *kitch = new Kitchen;
	LaundryRoom *laundry = new LaundryRoom;
	Library *lib = new Library;
	MainHall *hall = new MainHall;
	ParentRoom *parent = new ParentRoom;
	PlayerRoom *playRoom = new PlayerRoom;
	SittingRoom *sitting = new SittingRoom;
	StorageRoom *storage = new StorageRoom;
	Study *stud = new Study;
	Wall *wall = new Wall;
			
	// Link room objects by setting NavNodes (N, S, E, W)
	dining->setNavNodes(wall, kitch, wall, hall);	
	kitch->setNavNodes(dining, wall, wall, wall);
	laundry->setNavNodes(storage, wall, hall, wall);
	lib->setNavNodes(stud, wall, wall, wall);
	hall->setNavNodes(sitting, laundry, dining, storage); // NOTE DIRECTIONS AND SEE MAP
	parent->setNavNodes(wall, playRoom, sitting, wall);
	playRoom->setNavNodes(parent, wall, sitting, wall);
	sitting->setNavNodes(hall, playRoom, stud, parent); // NOTE DIRECTIONS AND SEE MAP
	storage->setNavNodes(wall, laundry, hall, wall);
	stud->setNavNodes(wall, lib, wall, sitting);
	
	// Print backstory
	lib->clearScreen();
	cout << " In this game, you play Sythierius Sceptine, a 15 year old apprentice magician." << endl;
	cout << "     His parents are currently out of the city on an errand for the king." << endl;
	cout << "    Sythierius is left alone in the Sceptine Manor, and is incredibly bored," << endl;
	cout << "       that is, until he finds a book that details how to summon a demon." << endl;
	cout << endl;
	cout << " You must guide Sythierius around the manor and gather ingredients to perform" << endl;
	cout << " the summoning, so that Sythierius has a playmate and can relieve his boredom." << endl;
	cout << endl;
	cout << "Press enter to continue..." << endl;
	cin.get(); // Pause screen

	// Start game in Library room
	lib->enter(syth);
	
	
} // End Main