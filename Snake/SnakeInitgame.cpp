#include"MC.h"
#include"SnakeInitgame.h"
#include"SnakeGameSystem.h"

extern bool gameOver;

extern bool print;


void SnakeInitgame::playgameSnake(){

	system("color e");

	char ch;
	char ch1;

	string s = " \t==Welcome==";

	cout << endl;
	for (int i = 0; i < s.size(); i++){
		Sleep(150);
		printf("%c", s[i]);
	}
	cout << endl;

	s = " \tThis is my snake game";
	for (int i = 0; i < s.size(); i++){
		Sleep(150);
		printf("%c", s[i]);
	}
	cout << endl;

	s = " \tJust Play and enjoy..... ";
	for (int i = 0; i < s.size(); i++){
		Sleep(150);
		printf("%c", s[i]);
	}
	cout << endl;
	cout << endl;

	do{
		system("color e");
		cout << endl;
		s = " **Menu**";
		system("cls");
		for (int i = 0; i < s.size(); i++){
			Sleep(150);
			printf("%c", s[i]);
		}
		cout << endl;
		s = " \t1.Play game.....";
		for (int i = 0; i < s.size(); i++){
			Sleep(150);
			printf("%c", s[i]);
		}
		cout << endl;

		s = " \t2.Instructions....";
		for (int i = 0; i < s.size(); i++){
			Sleep(150);
			printf("%c", s[i]);
		}
		cout << endl;
		cout << endl;
		mc:
		s = " Enter your choice: ";
		for (int i = 0; i < s.size(); i++){
			Sleep(150);
			printf("%c", s[i]);
		}
		cout << flush;
		cin >> ch1;
		cout << endl;

		SnakeGameSystem obj;
		
		if (ch1 == '1'){
			do{
				cout << " 1.Easy..." << endl;
				cout << " 2.Med ium" << endl;
				cout << " 3.Hard..." << endl;
				system("color c");
				cout << endl;
				cout << " Think Twice before You choose..." << endl;
				cout << endl;
				cout << " Enter the level of difficulty: " << flush;
				int ip;
				cin >> ip;
				system("color e");
				if (ip == 1){
					obj.gameSnake(100, 1);
				}
				else if (ip == 2){
					obj.gameSnake(75, 2);
				}
				else if (ip == 3){
					obj.gameSnake(50, 3);
				}
				else{
					system("color f");
					cout << " Invalid input...." << endl;
				}
				cout << endl;
				cout << " Do you want to play match <y/n>: " << flush;
				gameOver = false;
				print = false;
				obj.SetupSnake();
				cin >> ch;
			} while ((ch == 'y') || (ch == 'Y'));
		}
		else if(ch1 == '2'){
			vector<string> Instrct;
			ifstream file;
			string line;

			file.open("instrctSnake.txt");
			if (file.fail()){
				perror("instrctSnake.txt");
				system("PAUSE");
				exit(1);
			}

			while (getline(file, line)){
				Instrct.push_back(line);
			}
			file.close();
			for (int i = 0; i < Instrct.size(); i++){
				printf(" %s\n", Instrct[i].c_str());
			}
			system("color a");
		}
		else {
			cout << " InvalidInput!!" << endl << endl;
			goto mc;
		}
		cout << endl;
		cout << " Do you Want to go to main menu <y/n>: " << flush;
		gameOver = false;
		print = false;
		obj.SetupSnake();

		cin >> ch;
	} while ((ch == 'y') || (ch == 'Y'));

	system("color d");
	cout << endl;
	cout << " **Thank You for Playing ...**" << endl;
	cout << " **Good Bye.......**" << endl;
	cout << " **Have a nice day....**" << endl;
	cout << endl;
	cout << " ";
	cout << "Press any key to exit..." << flush;
	ch = _getch();
}

