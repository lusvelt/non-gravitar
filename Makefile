non-gravitar: NonGravitar.o GameController.o Spaceship.o
	g++ NonGravitar.o GameController.o Spaceship.o -o NonGravitar -lsfml-graphics -lsfml-window -lsfml-system && ./NonGravitar

NonGravitar.o: NonGravitar.cpp
	g++ -c NonGravitar.cpp

GameController.o: GameController.cpp
	g++ -c GameController.cpp

Spaceship.o: Spaceship.cpp
	g++ -c Spaceship.cpp

Bunker.o: Bunker.cpp
	g++ -c Bunker.cpp

Fuel.o: Fuel.cpp
	g++ -c Fuel.cpp

Planet.o: Planet.cpp
	g++ -c Planet.cpp

SolarSystem.o: SolarSystem.cpp
	g++ -c SolarSystem.cpp

clean:
	rm *.o