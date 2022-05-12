#include "genPrefList.h"
#include "Bicycle.h"
#include "User.h"
#include <fstream>

int main(int argc, char* argv[]) {
	int numVis, rows, collums;
	std::ifstream inFile;
	inFile.open("teste.txt");

	//Lendo o numero de pessoas, linhas e colunas do mapa
	inFile >> numVis; inFile >> rows;  inFile >> collums;
	
	//Alocando a matriz que representa o mapa
	char** matrix = new char* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new char[collums];
	}

	//Alocando vetor de usuarios e bicicletas com Id setado
	std::vector<Bicycle> bikes;
	std::vector<User> users;
	for (int i = 0; i < numVis; i++) {
		Bicycle btmp(i);
		User utmp(i);
		bikes.push_back(btmp);
		users.push_back(utmp);
	}

	//Lendo o mapa do arquivo de entrada
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collums; j++) {
			inFile >> matrix[i][j];
			char charAtPoint = matrix[i][j];
			if (isdigit(charAtPoint)){
				int buff = charAtPoint - '0';
				//Salva coordenada bicicleta
				coord tmp(i, j);
				bikes[buff].setLoc(tmp);
			}
		}
	}
	
	//Adicionando a preferencia das pessoas e gerando a preferencia das bicicletas
	for (int i = 0; i < numVis; i++) {
		for (int j = 0; j < numVis; j++) {
			int pref;
			inFile >> pref;
			users[j].addToPrefList(pref);
		}
		coord tmp = bikes[i].getLoc();
		std::vector<people>* buff = genPrefList(matrix, rows, collums, tmp, numVis);
		bikes[i].genPrefList(buff);
		if (!bikes[i].genRankList()) {
			std::cout << "Erro na geracao da lista de rankings \n";
		}
	}


	
	return 0;
}