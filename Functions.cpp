#include"FunctionsForGame.h"
void ship::getShip(char* board) { // получаем координаты коробля от пользователя и сохраняем на его поле
	char ch;
	int res;
	bool isRight = false;
	do {
		drawBoard(board);
		do {			
			cout << "\nWrite, please, coordination of the  " << name << ": "; cin >> X >> Y;
		} while (X > 8 && X < 0 && Y > 8 && Y < 0);
		if (hp > 1) {
			do {
				cout << "What the dir you want to choice: up or right?(write u or r): "; cin >> ch;
			} while (ch != 'r' && ch != 'u');
		
		switch (ch)// смотрим куда направлен корабль: вверх или вбок
		{
		case 'u': dirY = true; break;
		case 'r': dirY = false; break;
		}
	    }
		
		if (X < 9 || X > 0 && Y < 9 || Y > 0) {
			res = 11 * Y + 12 + X;
			int empty = 0;
			int res2 = res;
			if (hp == 1) {//было 570 стало:
				dirY = true;
			}
			if (board[res] == '*') {
				isRight = false;
				cout << "\nError(31)!!!!!!!!!!!!!!\n";
			}
			else {
				if (dirY == true) {
					res += 12;
					for (int i = 1; i < 3 * (hp + 2) + 1; ++i) {
						if (board[res] == ' ') {
							++empty;
						}
						if (i % 3 == 0) {
							res -= 8;
						}
						--res;
					}
					if (empty < 3 * (hp + 2)) {
						cout << "\nError(47)!!!!!!\n";
						isRight = false;
					}
					else {
						isRight = true;
					}
				}
				else {
					res += 12 + hp - 1;
					for (int i = 1; i < 3 * (hp + 2) + 1; ++i) {
						if (board[res] == ' ') {
							++empty;
						}
						if (i % (hp + 2) == 0) {
							res -= 9 - hp;
						}
						--res;
					}
					if (empty < 3 * (hp + 2)) {
						cout << "\nError(66)!!!!!!\n";
						isRight = false;
					}
					else {
						isRight = true;
					}
				}
			}
			if (isRight == true) {//установка коробля:
				if (hp > 1) {
					if (dirY == true) {
						for (int i = 0; i < hp; i++) {
							if (board[res2] != '*') {
								if (Y < 9) {
									board[res2] = '*';
									res2 -= 11;
								}								
							}
							else {
								isRight = false;
							}
						}
					}
					else {
						for (int i = 0; i < hp; i++) {
							if (board[res2] != '*') {
								if (X < 9) {
									board[res2++] = '*';
								}
							}
							else {
								cout << "Error";
								isRight = false;
							}
						}
					}
				}
				else {
					board[res2] = '*';
				}
			}

			else {
				isRight = false;
			}
		}
	} while (isRight != true);
}


void GenericPlayer::Win(int i) {
	cout << "The " << i << "'st player win.\n";
}
void GenericPlayer::Lose(int i) {
	cout << "The " << i << "st player lose.\n";
}
void drawBoard(char* board) {//рисование поля для расстановки кораблей и вывод поле для стрельбы:
	int j = 0;
	int t = 0;
	int h = 11;
	cout << "|012345678|";
	for (int i = 0; i < 81; i++) {// 9 * 9
		if (i == 0) {
			cout << "\n" << j;
		}
		++h;
		cout << board[h];
		++j;
		if (i == 80) {
			break;
		}
		if (j % 9 == 0) {
			++t;
			h += 2;
			cout << endl << t;
		}
	}
	cout << "\n|012345678|\n";
}
void Hitting(char* board, char* sboard, int x, int y, bool* hit, bool* isG) {//функция проверки на наличие попадания, промоха или стрельбу в ту же самую точку:
	int res;
	res = 11 * y + 12 + x;
	if (sboard[res] == '-' || sboard[res] == '#') {
		*hit = true;
		*isG = false;
		cout << "\n*Please, don't shoot to point which you shoot them!*\n";
	}
	else if (board[res] == '*' && sboard[res] == ' ') {
		sboard[res] = '#';
		*hit = true;
		*isG = true;
		cout << "\n*You have a hit!*\n";
	}
	else if(board[res] != '*'){
		sboard[res] = '-';
		*hit = false;
		cout << "\n*You haven't any hit!*\n";
	}
}
void setBoard(char* board) {//устанавливает поле для расстановки кораблей или для стрельбы:
	for (int i = 0; i < 121; i++) {
		board[i] = ' ';
	}
}
void proverka(ship s, char* board, char* sboard, int X, int Y, int* coun, bool* isG) {//проверяет на уничтожение корабля:
	int res, res2;
	res = 11 * Y + 12 + X;
	res2 = 11 * s.Y + 12 + s.X;
	int HP = s.hp;
	int y = 0;
	int x = 0;
	int x2;
	int y2;
	if (s.hp == 1) {
		if (sboard[res] == '#' && board[res] == '*' && res == res2) {
			--HP;
		}
		if (HP == 0) {
			x = res2;
			x += 12;
			for (int i = 1; i < 10; ++i) {
				if (board[x] != '*') {
					sboard[x] = '-';
						if (i % 3 == 0) {
							x -= 8;
						}
						
				}
				--x;
			}
			cout << "Torp ship is Destroy!\n";
			if (*isG == true) {
				--*coun;
			}
		}
	}
	else if (s.hp > 1) {
		if (s.dirY == true) {
			y = res2;
			y2 = res;
			if (y2 < res2) {
				for (int i = 0; i < s.hp; i++) {
					if (y2 == res2) {
						break;
					}
					y2 += 11;
				}
			}
			for (int i = 0; i < s.hp; i++) {
				if (sboard[y] == '#' && board[y] == '*' && y == y2) {//(board[y] == sboard[y]
					--HP;
				}
				y -= 11;
				y2 -= 11;
			}
			if (HP == 0) {
				y = res2;
				y += 12;
				for (int i = 1; i < 3*(s.hp + 2) + 1; ++i) {
					if (board[y] != '*') {
						sboard[y] = '-';
						if (i % 3 == 0) {
							y -= 8;
						}
					}
					--y;
				}
				if (*isG == true) {
					--*coun;
				}
				switch (s.hp)
				{
				case 2: cout << "Asmin ship is destroy!\n"; break;
				case 3: cout << "Creiser is destroy!\n"; break;
				case 4: cout << "Avionosetz is destroy!\n"; break;
				}
			}
		}

		else {
			x = res2;
			x2 = res;
			if (x2 - res2 < s.hp) {
				for (int i = 0; i < s.hp; i++) {
					if (res2 == x2) {
						break;
					}
					--x2;
				}
			}
			for (int i = 0; i < s.hp; i++) {
				if (sboard[x] == '#' && board[x] == '*' && x == x2) {//board[x] == sboard[x]
					--HP;
				}
				++x;
				++x2;
			}
			if (HP == 0) {
				x = res2;
				x += 12 + s.hp - 1;
				for (int i = 1; i < 3 * (s.hp + 2) + 1; ++i) {
					if (board[x] != '*') {
						sboard[x] = '-';
						if (i % (s.hp + 2) == 0) {
							x -= 9 - s.hp;
						}
					}
					--x;
				}
				if (*isG == true) {
					--*coun;
				}
				switch (s.hp)
				{
				case 2: cout << "Asmin ship is destroy!\n"; break;
				case 3: cout << "Creiser is destroy!\n"; break;
				case 4: cout << "Avionosetz is destroy!\n"; break;
				}
			}
		}
	}

}
bool isDestoyed(char* sboard) {//проверка на уничтоженные корабли:
	int ships = 0;
	for (int i = 0; i < 121; i++) {
		if (sboard[i] == '#') {
			++ships;
		}
	}
	if (ships == 18) {
		return true;
	}
	return false;
}