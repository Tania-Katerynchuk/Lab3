#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

#include <string>
#include <vector>

using namespace std;

bool OpenFile(vector<vector<char>>& line,int& n);

//відкриття файла
bool OpenFile(vector<vector<char>>& line,int& n) {
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
	cout << line[1][0];
	return true;
}
//запис стрічки в файл
void WriteLeftLine(vector<char> line, char fileName[61]) {
	FILE * fWrite;
	if ((fWrite = fopen(fileName, "w")) == NULL) {
		cerr << "Помилка";
		exit(1);
	}
	for (int i = 0; i < line.size(); i++) {
		putc(line[i], fWrite);
	}
	fclose(fWrite);
	
}

void OutputLine(vector<vector <char>> line,int n) {
	cout << "Файл вiдкрився для зчитування iнформацiї.\nВміст файла:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			if (line[i][j] == ';') {
				cout << "|";

			}
			else
				cout << line[i][j];
		}
		cout <<"|"<< endl;
		
	}

}



int main() {
	setlocale(LC_CTYPE, "ukr");
	vector<vector <char>> line;
	line.push_back(vector<char>());
	//vector < vector <double> > tmp1(sizeMatrix, vector<double>(sizeMatrix);
	//Відкриваємо файл
	int n = 0;
	OpenFile(line,n);
	//if (OpenFile(line,n)) {
		OutputLine(line,n);//вивід даних з файла
		
	//}
	system("pause");
	return 0;
}
