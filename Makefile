non-gravitar: Bullet.o Bunker.o Camera.o CleverBunker.o DoubleShootBunker.o Engine.o Game.o LifePointsBar.o NonGravitar.o Object.o Planet.o Scene.o SolarSystem.o Spaceship.o TankBunker.o ThreeDirectionBunker.o TwoDirectionBunker.o
	g++ -o NonGravitar Bullet.o Bunker.o Camera.o CleverBunker.o DoubleShootBunker.o Engine.o Game.o LifePointsBar.o NonGravitar.o Object.o Planet.o Scene.o SolarSystem.o Spaceship.o TankBunker.o ThreeDirectionBunker.o TwoDirectionBunker.o -lsfml-graphics -lsfml-window -lsfml-system

Bullet.o: Bullet.cpp
	g++ -c Bullet.cpp

Bunker.o: Bunker.cpp
	g++ -c Bunker.cpp

Camera.o: Camera.cpp
	g++ -c Camera.cpp

CleverBunker.o: CleverBunker.cpp
	g++ -c CleverBunker.cpp

DoubleShootBunker.o: DoubleShootBunker.cpp
	g++ -c DoubleShootBunker.cpp

Engine.o: Engine.cpp
	g++ -c Engine.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

LifePointsBar.o: LifePointsBar.cpp
	g++ -c LifePointsBar.cpp

NonGravitar.o: NonGravitar.cpp
	g++ -c NonGravitar.cpp

Object.o: Object.cpp
	g++ -c Object.cpp

Planet.o: Planet.cpp
	g++ -c Planet.cpp

Scene.o: Scene.cpp
	g++ -c Scene.cpp

SolarSystem.o: SolarSystem.cpp
	g++ -c SolarSystem.cpp

Spaceship.o: Spaceship.cpp
	g++ -c Spaceship.cpp

TankBunker.o: TankBunker.cpp
	g++ -c TankBunker.cpp

ThreeDirectionBunker.o: ThreeDirectionBunker.cpp
	g++ -c ThreeDirectionBunker.cpp

TwoDirectionBunker.o: TwoDirectionBunker.cpp
	g++ -c TwoDirectionBunker.cpp

run:
	make && ./NonGravitar

debug:
	g++ -g *.cpp -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o NonGravitar *.exe