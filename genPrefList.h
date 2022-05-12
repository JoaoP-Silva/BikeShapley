#ifndef GENPREFLIST_H
#define GENPREFLIST_H

#include <iostream>
#include <vector>
#include <set>
#include <ctype.h>
#include <queue>
#include "DataTypes.h"

/*Funcao: genPrefListRecursive(...){}
*	Descricao: Funcao recursiva para gerar a lista de preferencias de uma bicicleta qualquer(lista e alocada na variavel prefList).
*	Entrada:	char** matrix - Ponteiro para matriz de caracteres.
*				int maxRow/ int maxCollum - Inteiro com as dimensoes da matriz, num max de linhas e colunas.
*				coord point - Variavel do tipo coord, par (linha, coluna) da coordenada do passo recursivo que esta sendo feito.
*				std::set<coord>& visited - Referência de set de coordenadas que salva todas as coordenadas que já foram visitadas.
*				std::queue<coordAt>& q - Referência de fila de coordenadas a serem analisadas, com uma variavel inteira relacionada ao
*				passo que a coordenada foi encontrada.
*				std::vector<people>* prefList: Lista de duplas(Id pessoa, distancia encontrada) para salvar a preferencia da bicicleta.
*				unsigned int numPeople: Inteiro positivo com o numero de pessoas que tem no problema.
* 
*	Retorna: void
*/
void genPrefListRecursive(char** matrix, int maxRow, int maxCollum, coord point, std::set<coord>& visited, std::queue<coordAt>& q, std::vector<people>* prefList, unsigned int numPeople) {
	int level = 0;
	//Caso a fila ja tinha sido iniciada, o level é atualizado
	if (q.size() > 0) {
		level = q.front().second + 1;
		q.pop();
	}
	std::set<coord>::iterator it;
	int x = point.first; int y = point.second;
	char charAtPoint = matrix[x][y];
	if (charAtPoint >= 'a' && charAtPoint <= 'j') {
		int tmp = charAtPoint - '0' - 1 - '0';
		//Caso ja tenha sido adicionado algum item ao vetor resultante, insere o proximo item de forma ordenada
		if (!prefList->empty()) {
			std::vector<people>::iterator prefIt = prefList->end();
			for (int i = prefList->size() - 1; i >= 0; i--) {
				if (prefList->at(i).second == level && prefList->at(i).first < tmp  || level > prefList->at(i).second) {
					prefList->insert(prefIt, std::pair<unsigned int, unsigned int>(tmp, level));
					break;
				}
				prefIt--;
				if (prefIt == prefList->begin()) {
					prefList->insert(prefIt, std::pair<unsigned int, unsigned int>(tmp, level));
				}
			}
		}
		else {
			prefList->push_back(std::pair<unsigned int, unsigned int>(tmp, level));
		}
		if (prefList->size() == numPeople) {
			return;
		}
	}
	//Testa se pode aplicar BFS em cada uma das direcoes possiveis
	if (y > 0 && (matrix[x][y - 1] != '-')) {
		coord newCoord(x, y - 1);
		it = visited.find(newCoord);
		if (it == visited.end()) {
			visited.insert(newCoord);
			coordAt auxToNew(newCoord, level);
			q.push(auxToNew);
		}
	}
	if (y < maxCollum - 1 && (matrix[x][y + 1] != '-')) {
		coord newCoord(x, y + 1);
		it = visited.find(newCoord);
		if (it == visited.end()) {
			coordAt auxToNew(newCoord, level);
			q.push(auxToNew);
		}
	}
	if (x > 0 && (matrix[x - 1][y] != '-')) {
		coord newCoord(x - 1, y);
		it = visited.find(newCoord);
		if (it == visited.end()) {
			coordAt auxToNew(newCoord, level);
			q.push(auxToNew);
		}
	}
	if (x < maxRow -1 && (matrix[x + 1][y] != '-')) {
		coord newCoord(x + 1, y);
		it = visited.find(newCoord);
		if (it == visited.end()) {
			coordAt auxToNew(newCoord, level);
			q.push(auxToNew);
		}
	}
	coord next = q.front().first;
	genPrefListRecursive(matrix, maxRow, maxCollum, next, visited, q, prefList, numPeople);
}

/*Funcao: genPrefList(char** matrix, int maxRow, int maxCollum, coord init, unsigned int numPeople){}
*	Descricao: Funcao a ser chamada no main para gerar a lista de preferencias de uma bicicleta qualquer.
*	Entrada:	char** matrix - Ponteiro para matriz de caracteres.
*				int maxRow/ int maxCollum - Inteiro com as dimensoes da matriz, num max de linhas e colunas.
*				coord init - Variavel do tipo coord, par (linha, coluna) da coordenada da bicicleta que sera gerada a lista.
*				unsigned int numPeople: Inteiro positivo com o numero de pessoas que tem no problema
*	
*	Retorna: Um vetor do tipo std::vector<people> ordenado, com pares (Id pessoa, distancia bicicleta).
*/
std::vector<people>* genPrefList(char** matrix, int maxRow, int maxCollum, coord init, unsigned int numPeople){
	std::vector<people>* prefList = new std::vector<people>;
	std::set<coord> visited;
	visited.insert(init);
	std::queue<coordAt> q;
	unsigned int level = 0;
	genPrefListRecursive(matrix, maxRow, maxCollum, init, visited , q, prefList, numPeople);
	return(prefList);
}


#endif