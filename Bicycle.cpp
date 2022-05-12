#include "Bicycle.h"
#include <iostream>
//Construtores
Bicycle::Bicycle() : _id(-1), _prefList(NULL), _loc(std::pair<int, int>(-1, -1)), _match(-1) {}
Bicycle::Bicycle(int Id, coord Loc) { this->_id = Id; this->_loc = Loc; this->_match = -1; }
Bicycle::Bicycle(int Id) { this->_id = Id; this->_match = -1;}

//Metodos de acesso
int Bicycle::getId() { return this->_id; }
coord Bicycle::getLoc() { return this->_loc; }
int Bicycle::getMatch() { return this->_match; }
void Bicycle::setId(int Id) { this->_id = Id; }
void Bicycle::setLoc(coord Loc) { this->_loc = Loc; }
void Bicycle::setMatch(int m) { this->_match = m; }

//Metodos gerais
bool Bicycle::genPrefList(std::vector<people>* prefList) {
	if (prefList->empty()) {
		return 0;
	}
	else {
		for (int i = 0; i < prefList->size(); i++) {
			_prefList.push_back(prefList->at(i).first);
		}
		delete prefList;
		return 1;
	}
}

int Bicycle::getPrefListAt(int i) { return this->_prefList[i]; }

bool Bicycle::genRankList() {
	if (_prefList.empty()) {
		return 0;
	}
	else {
		for (int i = 0; i < _prefList.size(); i++) {
			_rankList.push_back(-1);
		}
		for (int i = 0; i < _prefList.size(); i++) {
			_rankList[_prefList[i]] = i;
			//std::cout << "Bike:" << this->_id << " tem a pessoa " << _prefList[i] << " com rank" << i << "\n";
		}
		return 1;
	}
}

int Bicycle::getRankListAt(int i) { return this->_rankList[i]; }