non-gravitar: Bullet.o Bunker.o Camera.o Engine.o Game.o NonGravitar.o Object.o Scene.o SolarSystem.o Spaceship.o
	g++ -o NonGravitar Bullet.o Bunker.o Camera.o Engine.o Game.o NonGravitar.o Object.o Scene.o SolarSystem.o Spaceship.o -lsfml-graphics -lsfml-window -lsfml-system

Bullet.o: Bullet.cpp
	g++ -c Bullet.cpp

Bunker.o: Bunker.cpp
	g++ -c Bunker.cpp

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

run:
	make && ./NonGravitar

debug:
	g++ -g *.cpp -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o NonGravitar *.exe