#include "Purse.h"

Purse::Purse()
{
	for (int i = 0; i < VecOfMoney.size(); i++)
	{
		requester(VecOfMoney[i]);
	}
	sum = getSumOfPurse();
}

double Purse::getSumOfPurse()
{
	double temp = 0;
	for (int i = 0; i < VecOfMoney.size(); i++)
	{
		temp = temp + VecOfMoney[i];
	}
	return temp;
}

vector<MoneyObj> Purse::getVecOfAttr()
{
	MoneyObj OneKop{ 0.01, 0 };
	MoneyObj FiveKop{ 0.05, 0 };
	MoneyObj TenKop{ 0.1, 0 };
	MoneyObj FiftyKop{ 0.5, 0 };

	MoneyObj OneRub{ 1, 0 };
	MoneyObj TwoRubs{ 2, 0 };
	MoneyObj FiveRubs{ 5, 0 };
	MoneyObj TenRubs{ 10, 0 };
	MoneyObj FiftyRubs{ 50, 0 };
	MoneyObj OneHundredRubs{ 100, 0 };
	MoneyObj FiveHundredRubs{ 500, 0 };
	MoneyObj OneThousand{ 1000, 0 };
	MoneyObj FiveThousand{ 5000, 0 };
	return { OneKop, FiveKop, TenKop, FiftyKop, OneRub, TwoRubs, FiveRubs, TenRubs, FiftyRubs, OneHundredRubs, FiveHundredRubs, OneThousand, FiveThousand };
}

vector<MoneyObj> Purse::getCurVecOfAttr()
{
	return VecOfMoney;
}

void Purse::setVecOfAttr(vector<MoneyObj> vec)
{
	if (VecOfMoney.size() == vec.size())
	{
		for (int i = 0; i < VecOfMoney.size(); i++)
		{
			VecOfMoney[i] = vec[i];
		}
		sum = getSumOfPurse();
	}
	else
	{
		cout << "Некорректный вектор";
	}
}

void Purse::showAllAttributes()
{
	cout<< "Сумма: " << sum << "\n";
	for (int i = 0; i < VecOfMoney.size(); i++)
	{
		VecOfMoney[i].showAllAttributes();
	}
}

void Purse::requester(MoneyObj& m)
{
	int cnt = 0;
	cout << "Введите кол-во " << m.getName() << ": ";
	cin >> cnt;
	m.setCount(cnt);
}

Purse operator- (Purse p1, int sum)
{
	vector<MoneyObj> vec = p1.getCurVecOfAttr();
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		while ((sum - vec[i].getValue() >= 0) && (vec[i].getCount() > 0))
		{
			sum = sum - vec[i].getValue();
			vec[i].setCount(vec[i].getCount() - 1);
		}
	}

	if (sum == 0)
	{
		p1.setVecOfAttr(vec);
	}
	else
	{
		cout << "Невозможно цельно вычесть данную сумму";
	}

	return p1;
}

Purse operator/ (Purse p1, int sum)
{
	if (sum != 0)
	{
		vector<MoneyObj> vec = p1.getCurVecOfAttr();
		int temp = (p1.getSumOfPurse() / sum) * (sum - 1);
		p1 = p1 - temp;
	}
	else
	{
		cout << "На 0 делить нельзя";
	}
	return p1;
}
