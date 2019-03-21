non-gravitar: Camera.o Engine.o Game.o NonGravitar.o Object.o Scene.o SolarSystem.o Spaceship.o
	g++ -o NonGravitar Camera.o Engine.o Game.o NonGravitar.o Object.o Scene.o SolarSystem.o Spaceship.o -lsfml-graphics -lsfml-window -lsfml-system

Camera.o: Camera.cpp
	g++ -c Camera.cpp

Engine.o: Engine.cpp
	g++ -c Engine.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

NonGravitar.o: NonGravitar.cpp
	g++ -c NonGravitar.cpp

Object.o: Object.cpp
	g++ -c Object.cpp

Scene.o: Scene.cpp
	g++ -c Scene.cpp

SolarSystem.o: SolarSystem.cpp
	g++ -c SolarSystem.cpp

Spaceship.o: Spaceship.cpp
	g++ -c Spaceship.cpp

debug:
	g++ -g *.cpp -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o NonGravitar *.exe