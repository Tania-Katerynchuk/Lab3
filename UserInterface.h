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
	cout << "��i����� |I�'� |�� �������i |��������� |��. ������ |�����i |�-�� ����i� i ������" << endl;
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
	cout << "����i�� ��i����e: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "����i�� i�'�: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "����i�� �� �������i: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "���������: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "����i�� ����i����i��� ������: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "����i�� ����i����i��� �����i: ";
	cin >> data;
	ThrowData(line, n, data);
	line[n].push_back(';');
	cout << "����i�� �i���i��� ������ i ����i�: ";
	cin >> data;
	ThrowData(line, n, data);
	n++;
}
void InputChange(vector<vector <char>>& line, int n, int& numberChange, string& newData1) {
	cout << "��i ���i �� ������ ��i����:\n1-��i�����\n2-I�'�\n3-�� �������i\n4-���������\n5-����i����i��� ������\n6-����i����i��� �����i\n7-�-�� ����i� i ������\n";
	cin >> numberChange;
	numberChange = numberChange - 1;
	cout << "����i�� ���i ���i: ";
	cin >> newData1;
}