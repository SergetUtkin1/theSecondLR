#include "MoneyObj.h"

MoneyObj::MoneyObj(double val, int cnt)
{
	value = val;
	count = cnt;
	name = (value < 1 ? to_string((int)(value * 100)) + " Копеек" : to_string((int)value) + " Руб");
}

void MoneyObj::showAllAttributes()
{
	cout << "name = " << name << "\n";
	cout << "value = " << value << "\n";
	cout << "count = " << count << "\n";
	cout << "sum = " << getSum() << "\n";
}

string MoneyObj::getName()
{
	return name;
}

double MoneyObj::getSum()
{
	return count * value;
}

int MoneyObj::getCount()
{
	return count;
}

double MoneyObj::getValue()
{
	return value;
}

void MoneyObj::setCount(int cnt)
{
	count = cnt;
}

double operator+ (MoneyObj m1, MoneyObj m2)
{
	return m1.getSum() + m2.getSum();
}

double operator+ (double m1, MoneyObj m2)
{
	return m1 + m2.getSum();
}