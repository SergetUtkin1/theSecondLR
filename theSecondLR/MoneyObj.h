#pragma once
#include <iostream>
#include <string>

using namespace std;

class MoneyObj
{
	friend double operator + (MoneyObj m1, MoneyObj m2);
	friend double operator + (double m1, MoneyObj m2);
public:

	MoneyObj(double val, int cnt);

	void showAllAttributes();

#pragma region getters
	string getName();

	double getSum();

	int getCount();

	double getValue();
#pragma endregion

#pragma region setters
	void setCount(int cnt);
#pragma endregion

private:
	string name;
	double value;
	int count;
};
