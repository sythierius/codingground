PROGS := demonmanor

all: $(PROGS)

demonmanor: Manor.o Magician.o Library.o ParentRoom.o PlayerRoom.o SittingRoom.o StorageRoom.o Study.o Kitchen.o LaundryRoom.o MainHall.o DiningRoom.o Wall.o launcher.o
	g++ -g Manor.o Magician.o Library.o ParentRoom.o PlayerRoom.o SittingRoom.o StorageRoom.o Study.o Kitchen.o LaundryRoom.o MainHall.o DiningRoom.o Wall.o launcher.o -o demonmanor 
	
Manor.o: Manor.cpp Manor.hpp
	g++ -c Manor.cpp
	
Magician.o: Magician.cpp Magician.hpp
	g++ -c Magician.cpp
	
Library.o: Library.cpp Library.hpp
	g++ -c Library.cpp
		
ParentRoom.o: ParentRoom.cpp ParentRoom.hpp
	g++ -c ParentRoom.cpp
		
PlayerRoom.o: PlayerRoom.cpp PlayerRoom.hpp
	g++ -c PlayerRoom.cpp
		
SittingRoom.o: SittingRoom.cpp SittingRoom.hpp
	g++ -c SittingRoom.cpp
		
StorageRoom.o: StorageRoom.cpp StorageRoom.hpp
	g++ -c StorageRoom.cpp
		
Study.o: Study.cpp Study.hpp
	g++ -c Study.cpp
		
Kitchen.o: Kitchen.cpp Kitchen.hpp
	g++ -c Kitchen.cpp
		
LaundryRoom.o: LaundryRoom.cpp LaundryRoom.hpp
	g++ -c LaundryRoom.cpp
		
MainHall.o: MainHall.cpp MainHall.hpp
	g++ -c MainHall.cpp
		
DiningRoom.o: DiningRoom.cpp DiningRoom.hpp
	g++ -c DiningRoom.cpp
	
Wall.o: Wall.cpp Wall.hpp
	g++ -c Wall.cpp
	
launcher.o: launcher.cpp
	g++ -c launcher.cpp

clean:
	rm -f $(PROGS) *.o *~
