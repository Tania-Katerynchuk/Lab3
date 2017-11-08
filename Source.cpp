#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

#include <string>
#include <vector>

using namespace std;
void DeletePerson(vector<vector <char>>& line, int& n);
bool OpenFile(vector<vector<char>>& line,int& n);

//�������� �����
bool OpenFile(vector<vector<char>>& line,int& n) {
	char fileName[61] = "2.csv";
	//cout << "Enter fole name: ";
	//cin.getline(fName, 61);
	char element;
	FILE * fRead;
	if ((fRead = fopen(fileName, "r")) == NULL) {
		cerr << "�������!!!" << endl;
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
//����� ������ � ����
void WriteLeftLine(vector<char> line, char fileName[61]) {
	FILE * fWrite;
	if ((fWrite = fopen(fileName, "w")) == NULL) {
		cerr << "�������";
		exit(1);
	}
	for (int i = 0; i < line.size(); i++) {
		putc(line[i], fWrite);
	}
	fclose(fWrite);
	
}

void OutputLine(vector<vector <char>> line,int n) {
	cout << "���� �i������� ��� ���������� i�������i�.\n���� �����:" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "��i����� |I�'� |�� �������i |��������� |����i������� ������ |�����i |�i���i��� ����i� i ������|" << endl;
	cout << "________________________________________________________________________________" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			if (line[i][j] == ';') {
				cout << " |";

			}
			else
				cout << line[i][j];
		}
		cout <<" |"<< endl;
		cout << "________________________________________________________________________________" << endl;
		
	}
}

void DeletePerson(vector<vector <char>>& line, int& n) {
	char namePerson[20];
	cin>>namePerson;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			if (line[i][j] == ';') {
				int f=0;
				for (int k = 0; k < 5; k++) {
					
					if (namePerson[k] == line[i][k]) {
						f++;
					}
				}
				if (f == j - 1) {
					line[i].clear();
					for (int k = i; k < n; k++) {
						line[i] = line[i + 1];
					}
					line[n - 1].clear();
					n--;
				}
				
				break;
			
			}
		}
	}
}

void ThrowData(vector<vector <char>>& line, int& n, string data) {
	for (int i = 0; i < data.size(); i++) {
		line[n].push_back(data[i]);
	}
}


void AddPerson(vector<vector <char>>& line, int& n) {
	line.push_back(vector<char>());
	string data;
	cout << "����i�� ��i����e: ";
	cin >> data;
	ThrowData(line, n,data);
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





int main() {
	setlocale(LC_CTYPE, "ukr");
	vector<vector <char>> line;
	line.push_back(vector<char>());
	//³�������� ����
	int n = 0;
	int menu=0;
	if (OpenFile(line,n)) {
		OutputLine(line,n);//���� ����� � �����
		cout << "1-��������� ����� ��� ������ �������\n2-������� ����� ��� ���� �������\n";
		AddPerson(line, n);
		OutputLine(line, n);
		/*switch menu {
		case 1:
			cout<<"������ ��i����� ������� ���i ��� �� ������ ��������: "
			DeletePerson(line, n);
			OutputLine(line, n);
			break;
		case 2:
			(line, n);
			OutputLine(line, n);
			break;
		}*/
		
		
	}

	system("pause");
	return 0;
}
