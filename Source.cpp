#define _CRT_SECURE_NO_WARNINGS
#include "UserInterface.h"
#include "ActionData.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

//відкриття файла
bool OpenFile(vector<vector<char>>& line, int& n) {
	char fileName[61] = "2.csv";
	//cout << "Enter fole name: ";
	//cin.getline(fName, 61);
	char element;
	FILE * fRead;
	if ((fRead = fopen(fileName, "r")) == NULL) {
		cerr << "Помилка!!!" << endl;
		return false;
	}
	element = getc(fRead);
	while (element != EOF) {
		if (element == '\n') {
			n++;
			line.push_back(vector<char>());
		}
		else
			line[n].push_back(element);
		element = getc(fRead);
	}
	fclose(fRead);
	return true;
}
//запис даних в файл
void WriteDataFile(vector<vector<char>> line, int n) {
	FILE * fWrite;
	char fileName[61] = "2.csv";
	//cout << "Enter fole name: ";
	//cin.getline(fName, 61);
	if ((fWrite = fopen(fileName, "w")) == NULL) {
		cerr << "Помилка";
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			putc(line[i][j], fWrite);
		}
		putc('\n', fWrite);
	}
	fclose(fWrite);

}

int main() {
	setlocale(LC_CTYPE, "ukr");
	vector<vector <char>> line;
	line.push_back(vector<char>());
	int n = 0;
	int menu = -1;
	if (OpenFile(line, n)) {//якщо файл існує
		OutputLine(line, n);//вивід даних з файла
		while (menu != 0) {
			cout << "1-Видалення даних про задану персону\n2-Додання даних про нову персону\n3-Сортування даних в алфавітному порядку(прізвище)\n4-Сортування даних за кількістю братів і сестер\n5-Редагування даних\n0-вихід\n";
			cin >> menu;
			switch (menu){
			case 1:
			DeletePerson(line, n);
			break;
			case 2:
			AddPerson(line, n);
			break;
			case 3:
			SortAlphabet(line, n);
			break;
			case 4:
			SortNumber(line, n);
			break;
			case 5:
			ChangeData(line, n);
			break;
			case 0:
				exit(0);
			default:
				cout << "Помилка"<<endl;
				break;
			}
			OutputLine(line, n);
			WriteDataFile(line, n);
		}
	}
	system("pause");
	return 0;
}
