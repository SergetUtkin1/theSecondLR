#include <iostream>
#include <vector>
#include <string>
#include "MoneyObj.h"
#include "Purse.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Purse mpurse;
	mpurse.showAllAttributes();
	cout << "--------------------- \n Введите кол-во рублей, которое необходимо вычесть: ";
	double temp;
	cin >> temp;
	mpurse = mpurse - temp;
	mpurse.showAllAttributes();
	cout << "--------------------- \n Введите число, во сколько раз необходимо сократить сумму: ";
	cin >> temp;
	mpurse = mpurse / temp;
	mpurse.showAllAttributes();
}