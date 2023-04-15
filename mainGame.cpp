#include"FunctionsForGame.h"
using namespace std;
int main() {
	GenericPlayer p1;
	GenericPlayer p2;

	ship torp[4];
	ship asmins[2];
	ship creiser[2];
	ship avionosetz;


	ship torp2[4];
	ship asmins2[2];
	ship creiser2[2];
	ship avionosetz2;

	char board[11][11];

	char board2[11][11];

	char shootBoard[11][11];

	char shootBoard2[11][11];

	int count1 = 9;
	int count2 = 9;
	char playAgain;
	do {
		setBoard((char*)board);
		setBoard((char*)board2);
		setBoard((char*)shootBoard);
		setBoard((char*)shootBoard2);


		for (int i = 0; i < 4; i++) {
			torp[i].getHP(1);
			torp[i].getName("Torp ship");
		}
		for (int i = 0; i < 2; i++) {
			asmins[i].getHP(2);
			asmins[i].getName("asmin");
		}
		for (int i = 0; i < 2; i++) {
			creiser[i].getHP(3);
			creiser[i].getName("creiser");
		}
		avionosetz.getHP(4);
		avionosetz.getName("avionosetz");

		for (int i = 0; i < 4; i++) {
			torp2[i].getHP(1);
			torp2[i].getName("Torp ship");
		}
		for (int i = 0; i < 2; i++) {
			asmins2[i].getHP(2);
			asmins2[i].getName("asmin");
		}
		for (int i = 0; i < 2; i++) {
			creiser2[i].getHP(3);
			creiser2[i].getName("creiser");

		}
		avionosetz2.getHP(4);
		avionosetz2.getName("avionosetz");

		cout << "The first Player is set ships!\n";
		for (int i = 0; i < 4; i++) {
			torp[i].getShip((char*)board);
		}
		for (int i = 0; i < 2; i++) {
			asmins[i].getShip((char*)board);
		}
		for (int i = 0; i < 2; i++) {
			creiser[i].getShip((char*)board);
		}
		avionosetz.getShip((char*)board);
		cout << "\n\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThe second Player is set ships!\n";
		for (int i = 0; i < 4; i++) {
			torp2[i].getShip((char*)board2);
		}
		for (int i = 0; i < 2; i++) {
			asmins2[i].getShip((char*)board2);
		}
		for (int i = 0; i < 2; i++) {
			creiser2[i].getShip((char*)board2);
		}
		avionosetz2.getShip((char*)board2);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		char ch;
		bool h = true;
		bool h2 = true;
		bool isDestro = false;
		bool isGood = true;
		do {
			cout << "\nDo you want to play the first?(y/n): "; cin >> ch;
		} while (ch != 'y' && ch != 'n');
		if (ch == 'y') {
			do {
				do {
					h = true;
					int x1, y1;
					drawBoard((char*)shootBoard);
					cout << "\n***********\n";
					cout << "*count: " << count2 << " *";
					cout << "\n***********\n";
					do {
						cout << "player 1, write, please, coordination for fire: "; cin >> x1 >> y1;
					} while (x1 > 8 && x1 < 0 && y1 > 8 && y1 < 0);
					Hitting((char*)board2, (char*)shootBoard, x1, y1, &h, &isGood);
					for (int i = 0; i < 4; i++) {
						proverka(torp2[i], (char*)board2, (char*)shootBoard, x1, y1, &count2, &isGood);
					}
					for (int i = 0; i < 2; i++) {
						proverka(asmins2[i], (char*)board2, (char*)shootBoard, x1, y1, &count2, &isGood);
					}
					for (int i = 0; i < 2; i++) {
						proverka(creiser2[i], (char*)board2, (char*)shootBoard, x1, y1, &count2, &isGood);
					}
					proverka(avionosetz2, (char*)board2, (char*)shootBoard, x1, y1, &count2, &isGood); // 18
					isDestro = isDestoyed((char*)shootBoard);
					if (isDestro == true)
					{
						p2.Win(1);
						p1.Lose(2);
						h = false;
						break;
					}
				} while (h == true);
				if (isDestro == true) {
					break;
				}
				do {
					int x2, y2;
					drawBoard((char*)shootBoard2);
					cout << "\n***********\n";
					cout << "*count: " << count1 << " *";
					cout << "\n***********\n";
					do {
						cout << "player 1, write, please, coordination for fire: "; cin >> x2 >> y2;
					} while (x2 > 8 && x2 < 0 && y2 > 8 && y2 < 0);
					Hitting((char*)board, (char*)shootBoard2, x2, y2, &h2, &isGood);
					//проверка
					for (int i = 0; i < 4; i++) {
						proverka(torp[i], (char*)board, (char*)shootBoard2, x2, y2, &count1, &isGood);
					}
					for (int i = 0; i < 2; i++) {
						proverka(asmins[i], (char*)board, (char*)shootBoard2, x2, y2, &count1, &isGood);
					}
					for (int i = 0; i < 2; i++) {
						proverka(creiser[i], (char*)board, (char*)shootBoard2, x2, y2, &count1, &isGood);
					}
					proverka(avionosetz, (char*)board, (char*)shootBoard2, x2, y2, &count1, &isGood); // 18
					isDestro = isDestoyed((char*)shootBoard2);
					if (isDestro == true)
					{
						p1.Win(2);
						p2.Lose(1);
						h2 = false;
						break;
					}

				} while (h2 == true);
				if (isDestro == true) {
					break;
				}
			} while (true);
		}
		else if (ch == 'n') {
			do {
				do {
					h2 = true;
					int x2, y2;
					drawBoard((char*)shootBoard2);
					cout << "\n***********\n";
					cout << "*count: " << count1 << " *";
					cout << "\n***********\n";
					do {
						cout << "player 1, write, please, coordination for fire: "; cin >> x2 >> y2;
					} while (x2 > 8 && x2 < 0 && y2 > 8 && y2 < 0);
					Hitting((char*)board, (char*)shootBoard2, x2, y2, &h2, &isGood);
					//проверка
					for (int i = 0; i < 4; i++) {
						proverka(torp[i], (char*)board, (char*)shootBoard2, x2, y2, &count1, &isGood);
					}
					for (int i = 0; i < 2; i++) {
						proverka(asmins[i], (char*)board, (char*)shootBoard2, x2, y2, &count1, &isGood);
					}
					for (int i = 0; i < 2; i++) {
						proverka(creiser[i], (char*)board, (char*)shootBoard2, x2, y2, &count1, &isGood);
					}
					proverka(avionosetz, (char*)board, (char*)shootBoard2, x2, y2, &count1, &isGood); // 18
					isDestro = isDestoyed((char*)shootBoard2);
					if (isDestro == true)
					{
						p1.Win(2);
						p2.Lose(1);
						h2 = false;
						break;
					}

				} while (h2 == true);
				if (isDestro == true) {
					break;
				}
				do {
					h = true;
					int x1, y1;
					drawBoard((char*)shootBoard);
					cout << "\n***********\n";
					cout << "*count: " << count2 << " *";
					cout << "\n***********\n";
					do {
						cout << "player 1, write, please, coordination for fire: "; cin >> x1 >> y1;
					} while (x1 > 8 && x1 < 0 && y1 > 8 && y1 < 0);
					Hitting((char*)board2, (char*)shootBoard, x1, y1, &h, &isGood);
					for (int i = 0; i < 4; i++) {
						proverka(torp2[i], (char*)board2, (char*)shootBoard, x1, y1, &count2, &isGood);
					}
					for (int i = 0; i < 2; i++) {
						proverka(asmins2[i], (char*)board2, (char*)shootBoard, x1, y1, &count2, &isGood);
					}
					for (int i = 0; i < 2; i++) {
						proverka(creiser2[i], (char*)board2, (char*)shootBoard, x1, y1, &count2, &isGood);
					}
					proverka(avionosetz2, (char*)board2, (char*)shootBoard, x1, y1, &count2, &isGood); // 18
					isDestro = isDestoyed((char*)shootBoard);
					if (isDestro == true)
					{
						p2.Win(1);
						p1.Lose(2);
						h = false;
						break;
					}
				} while (h == true);
			} while (true);
		}
		cout << "Do you want to play again?(y/n): "; cin >> playAgain;
	} while (playAgain!='n' && playAgain!='N');
	return 0;
}