non-gravitar: Main.o Bullet.o Bunker.o Camera.o CleverBunker.o DoubleShootBunker.o Engine.o FixedCamera.o FollowCamera.o Game.o LifePointsBar.o Surface.o NonGravitar.o Object.o Planet.o Scene.o SolarSystem.o Spaceship.o TankBunker.o ThreeDirectionBunker.o TwoDirectionBunker.o Line.o Segment.o
	g++ -o NonGravitar $^ -lsfml-graphics -lsfml-window -lsfml-system

Main.o: Main.cpp
	g++ -c Main.cpp

Bullet.o: game/bullets/Bullet.cpp
	g++ -c game/bullets/Bullet.cpp

Bunker.o: game/bunkers/Bunker.cpp
	g++ -c game/bunkers/Bunker.cpp

Camera.o: engine/Camera.cpp
	g++ -c engine/Camera.cpp

CleverBunker.o: game/bunkers/CleverBunker.cpp
	g++ -c game/bunkers/CleverBunker.cpp

DoubleShootBunker.o: game/bunkers/DoubleShootBunker.cpp
	g++ -c game/bunkers/DoubleShootBunker.cpp

Engine.o: engine/Engine.cpp
	g++ -c engine/Engine.cpp

FixedCamera.o: game/cameras/FixedCamera.cpp
	g++ -c game/cameras/FixedCamera.cpp

FollowCamera.o: game/cameras/FollowCamera.cpp
	g++ -c game/cameras/FollowCamera.cpp

Game.o: engine/Game.cpp
	g++ -c engine/Game.cpp

LifePointsBar.o: game/bunkers/LifePointsBar.cpp
	g++ -c game/bunkers/LifePointsBar.cpp

Surface.o: game/scenes/Surface.cpp
	g++ -c game/scenes/Surface.cpp

NonGravitar.o: game/NonGravitar.cpp
	g++ -c game/NonGravitar.cpp

Object.o: engine/Object.cpp
	g++ -c engine/Object.cpp

Planet.o: game/scenes/Planet.cpp
	g++ -c game/scenes/Planet.cpp

Scene.o: engine/Scene.cpp
	g++ -c engine/Scene.cpp

SolarSystem.o: game/scenes/SolarSystem.cpp
	g++ -c game/scenes/SolarSystem.cpp

Spaceship.o: game/spaceship/Spaceship.cpp
	g++ -c game/spaceship/Spaceship.cpp

TankBunker.o: game/bunkers/TankBunker.cpp
	g++ -c game/bunkers/TankBunker.cpp

ThreeDirectionBunker.o: game/bunkers/ThreeDirectionBunker.cpp
	g++ -c game/bunkers/ThreeDirectionBunker.cpp

TwoDirectionBunker.o: game/bunkers/TwoDirectionBunker.cpp
	g++ -c game/bunkers/TwoDirectionBunker.cpp

Line.o: engine/geometry/Line.cpp
	g++ -c engine/geometry/Line.cpp

Segment.o: engine/geometry/Segment.cpp
	g++ -c engine/geometry/Segment.cpp

run:
	make && ./NonGravitar

debug:
	g++ -g Main.cpp game/bullets/Bullet.cpp game/bunkers/Bunker.cpp engine/Camera.cpp game/bunkers/CleverBunker.cpp game/bunkers/DoubleShootBunker.cpp engine/Engine.cpp game/cameras/FixedCamera.cpp game/cameras/FollowCamera.cpp engine/Game.cpp game/bunkers/LifePointsBar.cpp game/scenes/Surface.cpp game/NonGravitar.cpp engine/Object.cpp game/scenes/Planet.cpp engine/Scene.cpp game/scenes/SolarSystem.cpp game/spaceship/Spaceship.cpp game/bunkers/TankBunker.cpp game/bunkers/ThreeDirectionBunker.cpp game/bunkers/TwoDirectionBunker.cpp engine/geometry/Line.cpp engine/geometry/Segment.cpp -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf *.o NonGravitar *.exe a.out a.out.dSYM non-gravitar