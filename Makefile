non-gravitar: FuelBar.o FuelInfo.o Lives.o Score.o Main.o Bullet.o BunkerBullet.o SpaceshipBullet.o Bunker.o Camera.o CleverBunker.o DoubleShootBunker.o Engine.o FixedCamera.o FollowCamera.o Fuel.o BigFuel.o SmallFuel.o Game.o LifePointsBar.o Surface.o NonGravitar.o Object.o Planet.o Scene.o SolarSystem.o Spaceship.o TankBunker.o ThreeDirectionBunker.o TwoDirectionBunker.o Line.o Segment.o TractorBeam.o MovingLight.o Info.o
	g++ -o NonGravitar $^ -lsfml-graphics -lsfml-window -lsfml-system

Main.o: Main.cpp
	g++ -c Main.cpp

Info.o: engine/Info.cpp
	g++ -c engine/Info.cpp

Bullet.o: game/bullets/Bullet.cpp
	g++ -c game/bullets/Bullet.cpp

BunkerBullet.o: game/bullets/BunkerBullet.cpp
	g++ -c game/bullets/BunkerBullet.cpp

SpaceshipBullet.o: game/bullets/SpaceshipBullet.cpp
	g++ -c game/bullets/SpaceshipBullet.cpp

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

Fuel.o: game/fuel/Fuel.cpp
	g++ -c game/fuel/Fuel.cpp

BigFuel.o: game/fuel/BigFuel.cpp
	g++ -c game/fuel/BigFuel.cpp

SmallFuel.o: game/fuel/SmallFuel.cpp
	g++ -c game/fuel/SmallFuel.cpp

Game.o: engine/Game.cpp
	g++ -c engine/Game.cpp

LifePointsBar.o: game/bunkers/LifePointsBar.cpp
	g++ -c game/bunkers/LifePointsBar.cpp

MovingLight.o: game/spaceship/MovingLight.cpp
	g++ -c game/spaceship/MovingLight.cpp

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

TractorBeam.o: game/spaceship/TractorBeam.cpp
	g++ -c game/spaceship/TractorBeam.cpp

TwoDirectionBunker.o: game/bunkers/TwoDirectionBunker.cpp
	g++ -c game/bunkers/TwoDirectionBunker.cpp

Line.o: engine/geometry/Line.cpp
	g++ -c engine/geometry/Line.cpp

Segment.o: engine/geometry/Segment.cpp
	g++ -c engine/geometry/Segment.cpp

FuelInfo.o: game/info/FuelInfo.cpp
	g++ -c game/info/FuelInfo.cpp

Lives.o: game/info/Lives.cpp
	g++ -c game/info/Lives.cpp

Score.o: game/info/Score.cpp
	g++ -c game/info/Score.cpp

FuelBar.o: game/info/FuelBar.cpp
	g++ -c game/info/FuelBar.cpp

run:
	make && ./NonGravitar

debug:
	g++ -g Main.cpp game/info/FuelBar.cpp game/info/Score.cpp game/info/Lives.cpp game/info/FuelInfo.cpp engine/Info.cpp game/bullets/Bullet.cpp game/bunkers/Bunker.cpp engine/Camera.cpp game/bunkers/CleverBunker.cpp game/bunkers/DoubleShootBunker.cpp engine/Engine.cpp game/cameras/FixedCamera.cpp game/cameras/FollowCamera.cpp engine/Game.cpp game/bunkers/LifePointsBar.cpp game/scenes/Surface.cpp game/NonGravitar.cpp engine/Object.cpp game/scenes/Planet.cpp engine/Scene.cpp game/scenes/SolarSystem.cpp game/spaceship/Spaceship.cpp game/bunkers/TankBunker.cpp game/bunkers/ThreeDirectionBunker.cpp game/bunkers/TwoDirectionBunker.cpp engine/geometry/Line.cpp engine/geometry/Segment.cpp game/spaceship/TractorBeam.cpp game/fuel/SmallFuel.cpp game/fuel/BigFuel.cpp game/fuel/Fuel.cpp game/bullets/BunkerBullet.cpp game/bullets/SpaceshipBullet.cpp game/spaceship/MovingLight.cpp -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf *.o NonGravitar *.exe a.out a.out.dSYM non-gravitar