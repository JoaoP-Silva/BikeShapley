#include "User.h"
#include <iostream>
//Construtores
User::User() : _id(-1), _prefList(NULL), it(_prefList.begin()), prefFlag(0), _match(-1) {}
User::User(int Id) { this->_id = Id; this->prefFlag = false; this->_match = -1; }

//Metodos de acesso
int User::getId() { return this->_id; }
void User::setId(int Id) { this->_id = Id; }
int User::getMatch() { return this->_match; }
void User::setMatch(int m) { this->_match = m; }


//Metodos gerais
void User::addToPrefList(int Item) { _prefList.push_back(Item); }

int User::getItemFromPref() {
	if (prefFlag == 0 && (!_prefList.empty())) {
		it = _prefList.begin();
		int data = *it;
		it++;
		prefFlag = 1;
		return data;
	}
	else if (prefFlag == 1) {
		if (it == _prefList.end()) {
			prefFlag = -1;
			return -1;
		}
		int data = *it;
		it++;
		return data;
	}
	else {
		return -1;
	}

}

void User::printPrefList() {
	for (int i = 0; i < this->_prefList.size(); i++) {
		std::cout << "Preferencia " << i << " da pessoa" << this->_id << " = " << _prefList[i] << "\n";
	}
}
