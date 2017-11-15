#pragma once
#include "UserInterface.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
void DeletePerson(vector<vector <char>>& line, int& n);
bool ChekingName(vector<vector <char>> line, int k);
void ExchangeLine(vector<vector <char>>& line, int k);
int SearchName(vector<vector <char>> line, int n);
void AddPerson(vector<vector <char>>& line, int& n);
void InputChange(vector<vector <char>>& line, int n, int& numberChange, string& newData1);

int SearchName(vector<vector <char>> line, int n) {
	cout << "¬ведiть прiзвище: ";
	string namePerson1;
	cin >> namePerson1;
	char *namePerson = new char[namePerson1.size()];
	for (int i = 0; i < namePerson1.size(); i++) {
		namePerson[i] = namePerson1[i];
	}
	int iName = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			if (line[i][j] == ';') {
				int nName = 0,k=0;
				while (k<j || k<namePerson1.size()) {
					if (namePerson[k] == line[i][k]) {
						nName++;
					}
					k++;
				}
				if (nName == k) {
					iName = i;
				}
				break;
			}
		}
	}
	free(namePerson);
	return iName;
}

void DeletePerson(vector<vector <char>>& line, int& n) {
	int iName = SearchName(line, n);
	line[iName].clear();
	for (int k = iName; k < n; k++) {
		line[iName] = line[iName + 1];
	}
	line[n - 1].clear();
	n--;
}
void SortAlphabet(vector<vector <char>>& line, int& n) {
	for (int i = 0; i < n - 1; i++) {
		for (int k = 0; k < n - i - 1; k++) {
			if (ChekingName(line, k)) {
				ExchangeLine(line, k);
			}
		}
	}
}

void ExchangeLine(vector<vector <char>>& line, int k) {
	char auxiliary1[100];
	char auxiliary2[100];
	int n1 = line[k].size(), n2 = line[k + 1].size();
	for (int j = 0; j < n1; j++) {
		auxiliary1[j] = line[k][j];
	}
	for (int j = 0; j < n2; j++) {
		auxiliary2[j] = line[k + 1][j];
	}
	line[k].clear();
	line[k + 1].clear();

	for (int j = 0; j < n1; j++) {
		line[k + 1].push_back(auxiliary1[j]);
	}
	for (int j = 0; j < n2; j++) {
		line[k].push_back(auxiliary2[j]);
	}
}

bool ChekingName(vector<vector <char>> line, int k) {
	int iSymbol = 0;
	while (line[k][iSymbol] != ';' || line[k + 1][iSymbol] != ';') {
		if (line[k][iSymbol] > line[k + 1][iSymbol]) {
			return true;
		}
		else if (line[k][iSymbol] == line[k + 1][iSymbol]) {
			if (line[k][iSymbol + 1] > line[k + 1][iSymbol + 1]) {
				return true;

			}
			if (line[k][iSymbol + 1] < line[k + 1][iSymbol + 1]) {
				return false;
			}
		}
		else {
			return false;
		}
		iSymbol++;
	}
	return false;
}

void SortNumber(vector<vector <char>>& line, int& n) {
	int *number = new int[n];
	int amount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			if (line[i][j] == ';') {
				amount++;
			}
			else if (amount == 6) {
				number[i] = line[i][j] - 48;
				amount = 0;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (number[j] > number[j + 1]) {
				ExchangeLine(line, j);
				int element = number[j];
				number[j] = number[j + 1];
				number[j + 1] = element;
			}
		}
	}
	free(number);
}

void ThrowData(vector<vector <char>>& line, int& n, string data) {
	for (int i = 0; i < data.size(); i++) {
		line[n].push_back(data[i]);
	}
}




void ChangeData(vector<vector <char>>& line, int n) {
	int personChenge = SearchName(line, n), numberChange, nChenge = 0;
	string newData1;
	InputChange(line, n, numberChange, newData1);
	char *newData = new char[newData1.size()];
	for (int i = 0; i < newData1.size(); i++) {
		newData[i] = newData1[i];
	}
	for (int j = 0; j < line[personChenge].size(); j++) {
		if (line[personChenge][j] == ';') {
			nChenge++;
		}
		else if (nChenge == numberChange) {
			int n1 = line[personChenge].size();
			char * auxiliary = new char[n1];
			for (int i = 0; i < n1; i++) {
				auxiliary[i] = line[personChenge][i];
			}
			line[personChenge].clear();
			for (int i = 0; i < j; i++) {
				line[personChenge].push_back(auxiliary[i]);
			}
			for (int i = 0; i < newData1.size(); i++) {
				line[personChenge].push_back(newData[i]);
			}
			for (int i = j + 1; i < n1; i++) {
				if (auxiliary[i] == ';') {
					j = i;
					break;
				}
			}
			for (int i = j; i < n1; i++) {
				line[personChenge].push_back(auxiliary[i]);
			}
			break;
		}
	}
}
