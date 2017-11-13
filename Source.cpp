#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

#include <string>
#include <vector>

using namespace std;
void DeletePerson(vector<vector <char>>& line, int& n);
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
	cout << "Файл вiдкрився для зчитування iнформацiї.\nВміст файла:" << endl;
	fclose(fWrite);
	
}

void OutputLine(vector<vector <char>> line,int n) {
	
	cout << "________________________________________________________________________________" << endl;
	cout << "Прiзвище |Iм'я |По батьковi |Факультет |Спецiальність батька |матерi |Кiлькiсть братiв i сестер|" << endl;
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
	cout << "Введiть прiзвищe: ";
	cin >> data;
	ThrowData(line, n,data);
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



void SortLine(vector<vector <char>>& line, int& n) {
	
	
	for (int i = 0; i < n - 1; i++) {
		for (int k = 0; k < n - i - 1; k++) {
			bool chekingName=false;
			for (int iSymbol = 0; iSymbol < 10; iSymbol++) {
				if (line[k][iSymbol] != ';' || line[k + 1][iSymbol] != ';') {
					if (line[k][iSymbol] > line[k + 1][iSymbol]) {
						chekingName = true;
						cout << line[k][iSymbol]<<'>' << line[k + 1][iSymbol]<< endl;
						break;
					}
					if (line[k][iSymbol] == line[k + 1][iSymbol]) {
						cout << line[k][iSymbol] << '=' << line[k + 1][iSymbol] << endl;
						if (line[k][iSymbol + 1] > line[k + 1][iSymbol + 1]) {
							chekingName = true;
							cout << line[k][iSymbol + 1]<< ">" << line[k + 1][iSymbol + 1]<<endl;
							break;

						}
						if (line[k][iSymbol + 1] < line[k + 1][iSymbol + 1]) {
							chekingName = false;
							cout << line[k][iSymbol + 1]<< "<" << line[k + 1][iSymbol + 1]<< endl;
							break;

						}
					}
				}
			}
			cout << chekingName << endl;
			if (chekingName) {
				char auxiliary1[100];
				char auxiliary2[100];
				int n1 = line[k].size(), n2 = line[k+1].size();
				for (int j = 0; j < n1; j++) {
					auxiliary1[j] = line[k][j];
				}
				for (int j = 0; j < n2; j++) {
					auxiliary2[j] = line[k+1][j];
				}
				line[k].clear();
				line[k+1].clear();

				for (int j = 0; j < n1; j++) {
					line[k+1].push_back(auxiliary1[j]);
				}
				for (int j = 0; j < n2; j++) {
					line[k].push_back(auxiliary2[j]);
				}
			}

		}
	}
}

//bool ChekingName(vector<vector <char>> line, int k) {
//	int iSymbol=0;
//	while (line[k][iSymbol] != ';' || line[k+1][iSymbol] != ';') {
//		if (line[k][iSymbol] > line[k+1][iSymbol] || (line[k][iSymbol] == line[k+1][iSymbol] && line[k][iSymbol + 1] > line[k+1][iSymbol + 1]))
//			return true;
//
//		iSymbol++;
//	}
//	return false;
//
//
//}




int main() {
	setlocale(LC_CTYPE, "ukr");
	vector<vector <char>> line;
	line.push_back(vector<char>());
	//Відкриваємо файл
	int n = 0;
	int menu=0;
	if (OpenFile(line,n)) {
		OutputLine(line,n);//вивід даних з файла
		cout << "1-Видалення даних про задану персону\n2-Додання даних про нову персону\n";
		SortLine(line, n);
		OutputLine(line, n);
		/*switch menu {
		case 1:
			cout<<"Введіть прiзвище персони данi якої ви хочете видалити: "
			DeletePerson(line, n);
			OutputLine(line, n);
			break;
		case 2:
			AddPerson(line, n);
			OutputLine(line, n);
			break;
		}*/
		
		
	}

	system("pause");
	return 0;
}
