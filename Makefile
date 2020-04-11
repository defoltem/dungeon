all:
	g++ -g -Wall -lncurses -o game main.cpp cret/hero.cpp cret/creatures.cpp cret/enemy.cpp cret/inventory/object.cpp cret/inventory/food.cpp cret/inventory/weapon.cpp
