#pragma once
#include <iostream>
#include <stdio.h>
#include "ActionData.h"
#include <string>
#include <vector>

using namespace std;
void ThrowData(vector<vector <char>>& line, int& n, string data);
void OutputLine(vector<vector <char>> line, int n);
void AddPerson(vector<vector <char>>& line, int& n);
void InputChange(vector<vector <char>>& line, int n, int& numberChange, string& newData1);
void OutputLine(vector<vector <char>> line, int n) {
	cout << "________________________________________________________________________________" << endl;
	cout << "Прiзвище |Iм'я |По батьковi |Факультет |Сп. батька |матерi |К-ть братiв i сестер" << endl;
	cout << "________________________________________________________________________________" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			if (line[i][j] == ';') {
				cout << " |";

			}
			else
				cout << line[i][j];
		}
		cout << " |" << endl;
		cout << "________________________________________________________________________________" << endl;

	}
}



void AddPerson(vector<vector <char>>& line, int& n) {
	line.push_back(vector<char>());
	string data;
	cout << "Введiть прiзвищe: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "Введiть iм'я: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "Введiть по батьковi: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "Факультет: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "Введiть спецiальнiсть батька: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "Введiть спецiальнiсть матерi: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "Введiть кiлькiсть сестер i братiв: ";
	cin >> data;
	ThrowData(line, n, data);
	n++;
}
void InputChange(vector<vector <char>>& line, int n, int& numberChange, string& newData1) {
	cout << "Якi данi ви хочете змiнити:\n1-Прiзвище\n2-Iм'я\n3-По батьковi\n4-Факультет\n5-Спецiальнiсть батька\n6-Спецiальнiсть матерi\n7-К-ть братiв i сестер\n";
	cin >> numberChange;
	numberChange = numberChange - 1;
	cout << "Введiть новi данi: ";
	cin >> newData1;
}