// RPG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается
// выполнение программы.
//


#include "pch.h"
#include "Game.h"
#pragma warning(disable : 4996)
#include <stdio.h>
#include <fstream>


int main() {


	json config;
	std::ifstream s;
	s.open("config.json");
	s>>config;

	initscr();
	Game game(config);

	game.start();
	return 0;
}
