#ifndef USER_H
#define USER_H

#include <vector>
#include "DataTypes.h"

class User {
private:
	//Id do usuario
	int _id;
	//Lista de preferencias do usuario (Id das bicicletas)
	std::vector<int> _prefList;
	std::vector<int>::iterator it;
	//Flag indicar que alguma proposta ja foi feita
	int prefFlag;
	//Casamento realizado
	int _match;
	
public:
	User();
	User(int Id);

	//Metodos de acesso
	void setId(int Id);
	void setMatch(int Id);
	int getId();
	void addToPrefList(int Item);

	//Metodos gerais
	//Recebe o proximo item a ser proposto
	int getItemFromPref();
	int getMatch();
	void printPrefList();
};
#endif // !USER_H

