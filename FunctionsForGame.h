#pragma once
#include<iostream>
#include<string>
using namespace std;
class ship {
public:
	int hp;
	int X; int Y;
	bool dirY;
	string name;
	void getHP(int H) {
		hp = H;
	}
	void getName(string n) {
		name = n;
	}
	void getShip(char* board);
};
class GenericPlayer {
public:
	void Win(int i);
	void Lose(int i);
};
void Hitting(char* board, char* sboard, int x, int y, bool* hit, bool* isG);
void drawBoard(char* board);
void setBoard(char* board);
void proverka(ship s, char* board, char* sboard, int x, int y, int* coun, bool* isG);
bool isDestoyed(char* sboard);