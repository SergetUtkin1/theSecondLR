#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "MoneyObj.h"

using namespace std;

class Purse
{
	friend Purse operator- (Purse p1, int sum);
	friend Purse operator/ (Purse p1, int sum);
public:
	Purse();

#pragma region getters
	double getSumOfPurse();

	vector<MoneyObj> getVecOfAttr();

	vector<MoneyObj> getCurVecOfAttr();
#pragma endregion

#pragma region setters
	void setVecOfAttr(vector<MoneyObj> vec);
#pragma endregion

	void showAllAttributes();
private:


	void requester(MoneyObj& m);


	double sum = getSumOfPurse();
	vector<MoneyObj> VecOfMoney = getVecOfAttr();
};
