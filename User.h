#ifndef USER_H
#define USER_H

#include <vector>
#include "DataTypes.h"

class User {
private:
	int _id;
	std::vector<int> _prefList;
	std::vector<int>::iterator it;
	int prefFlag;
	
public:
	User();
	User(int Id);

	void setId(int Id);
	int getId();
	void addToPrefList(int Item);
	int getItemFromPref();
};
#endif // !USER_H

