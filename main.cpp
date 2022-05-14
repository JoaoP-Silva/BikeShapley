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
		std::vector<int> pref;
		for (int j = 0; j < numVis; j++) {
			int tmp;
			inFile >> tmp;
			pref.push_back(tmp);
		}
		genPrefList_User(pref);
		for (int j = 0; j < numVis; j++) {
			users[i].addToPrefList(pref[j]);
		}
		coord tmp = bikes[i].getLoc();
		std::vector<people>* buff = genPrefList_Bicycle(matrix, rows, collums, tmp, numVis);
		bikes[i].genPrefList(buff);
		if (!bikes[i].genRankList()) {
			std::cout << "Erro na geracao da lista de rankings \n";
		}
	}

	//Lista de pessoas para realizar as propostas
	std::vector<User> proposeList;
	for (int i = 0; i < numVis; i++) {
		proposeList.push_back(users[i]);
	}

	/*Algoritmo de Gale-Shapley*/
	while (!proposeList.empty()) {
		int user = proposeList[0].getId();
		int propose = users[user].getItemFromPref();
		int response = bikes[propose].tryMatch(user);
		//Se a pessoa ja propos para todas as bicicletas, ela e retirada da lista de propostas
		if (propose == -1) {
			proposeList.erase(proposeList.begin());
		}
		//Se a bicicleta proposta nao tinha par, aceita a proposta
		else if (response == -2) {
			users[user].setMatch(bikes[propose].getId());
			proposeList.erase(proposeList.begin());
		}
		//Se a bicicleta aceitou a proposta mas tinha um par antes, atualiza o vetor de propostas
		else if (response > -1) {
			proposeList.erase(proposeList.begin());
			User rejected = users[response];
			users[response].setMatch(-1);
			proposeList.push_back(rejected);
			users[user].setMatch(bikes[propose].getId());
		}
	}

	//Imprime os resultados
	for (int i = 0; i < numVis; i++) {
		char letter = users[i].getId() + '0' + 1 + '0';
		int match = users[i].getMatch();
		std::cout << letter << " " << match << "\n";
	}
	
	return 0;
}