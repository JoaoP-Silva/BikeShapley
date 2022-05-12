#include "genPrefList.h"
#include <fstream>

int main(int argc, char* argv[]) {
	int numVis, rows, collums;
	std::ifstream inFile;
	inFile.open("teste.txt");
	//Lendo o numero de pessoas, linhas e colunas do mapa
	inFile >> numVis; inFile >> rows;  inFile >> collums;
	
	//Alocando a matriz que representara o mapa
	char** matrix = new char* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new char[collums];
	}

	//Vetor de bicicletas
	std::vector<coord> bicycles;
	//Lendo o mapa do arquivo de entrada
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collums; j++) {
			inFile >> matrix[i][j];
			char charAtPoint = matrix[i][j];
			if (isdigit(charAtPoint)){
				//Salva coordenada bicicleta
				coord tmp(i, j);
				bicycles.push_back(tmp);
			}
		}
	}
	std::vector<people>* teste;
	teste = genPrefList(matrix, rows, collums, bicycles[1], numVis);
	for (int i = 0; i < teste->size(); i++) {
		std::cout << "Pessoa: " << (char)teste->at(i).first << " encontrada no passo:" << teste->at(i).second << "\n";
	}
	
	return 0;
}