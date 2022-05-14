#ifndef BICYCLE_H
#define BICYCLE_H

#include <vector>
#include "DataTypes.h"

class Bicycle {
private:
	//int _id: Identificacao da bicicleta.
	int _id;
	//int _match: Identificacao da pessoa que foi alocada
	int _match;
	//std::vector<int> _prefList: Lista de preferencias da bicicleta.
	std::vector<int> _prefList;
	//std::vector<int>::iterator _prefIt;//
	//std::vector<int> _rankList: Lista de rankings da bicicleta.
	std::vector<int> _rankList;
	coord _loc;
public:
	Bicycle();
	Bicycle(int Id);
	Bicycle(int Id, coord Loc);

	//Metodos de acesso
	void setId(int Id);
	int getId();
	void setLoc(coord Loc);
	coord getLoc();
	int getMatch();

/*Funcao: bool genPrefList(std::vector<people>* prefList)
*	Descricao: Gera a lista de preferencias a partir de um vetor de pessoas.
*	Entrada:	std::vector<people>* prefList - Vetor ordenado pela preferencia
				de pessoas(int, int) que no primeiro valor do par, contem o _Id da pessoa.
				
*
*	Retorna:	True - Caso o vetor tenha sido gerado
*				False - Caso o vetor nao tenha sido gerado
*/
	bool genPrefList(std::vector<people>* prefList);
	//Retorna um item na posicao i da lista de preferencias
	int getPrefListAt(int i);
	//Gera a lista de rankings
	bool genRankList();
	//Retorna o ranking da pessoa i
	int getRankListAt(int i);
	//Tenta um casamento, se aceita retorna o item que estava casado anteriormente, senao retorna -1
	int tryMatch(int _m);
};

#endif