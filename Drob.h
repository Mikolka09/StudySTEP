#pragma once

using namespace std;

class Drob
{
private:
	int m_ch;//чеслитель
	int m_zn;//знаменатель
	int m_c;//целая часть
public:
	Drob();
	Drob(int ch, int zn, int c);

	Drob FSD(int ch, int zn, int c);
	Drob sumDrob(Drob d2);
	Drob dellDrob(Drob d2);
	Drob subDrob(Drob d2);
	Drob multDrob(Drob d2);
	bool moreDrob( Drob d2);
	bool lessDrob(Drob d2);
	bool equalDrob(Drob d2);
	bool inequalDrob(Drob d2);
	Drob operator+(Drob d2);
	Drob operator-(Drob d2);
	Drob operator*(Drob d2);
	Drob operator/(Drob d2);
	bool operator>(Drob d2);
	bool operator<(Drob d2);
	bool operator==(Drob d2);
	bool operator!=(Drob d2);

	void print() const;

};

Drob::Drob()
{
	m_ch = 0;
	m_zn = 1;
	m_c = 0;
}

Drob::Drob(int ch, int zn, int c)
{
	if (zn == 0)
	{
		cout << "Ошибка!!! Знаменатель не может равнятся нулю!!!" << endl;
		exit (0);
	}
	else
	{
		if (ch != 0 && zn != 0 && ch < 0 && zn > 0)
		{
			m_ch = abs(ch);
			m_zn = zn;
			m_c = -1 * c;
		}
		else
		{
			if (ch != 0 && zn != 0 && ch < 0 && zn < 0)
			{
				m_ch = abs(ch);
				m_zn = abs(zn);
				m_c = c;
			}
			else
			{
				if (ch != 0 && zn != 0 && ch > 0 && zn < 0)
				{
					m_ch = ch;
					m_zn = abs(zn);
					m_c = -1 * c;
				}
				else
				{
					m_ch = ch;
					m_zn = zn;
					m_c = c;
				}
			}
		}
	}
}

int NOD(int a, int b)
{
	for (int i = abs(a); i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
			return i;
	}
}

Drob Drob::FSD(int ch, int zn, int c)
{
	Drob fsd;
	int nod = NOD(ch, zn);
	if (nod != 1)
	{
		ch /= nod;
		zn /= nod;
	}
	int cel = ch / zn;
	if (cel)
	{
		fsd.m_c = c + cel;
		fsd.m_ch = abs(ch) % zn;
		fsd.m_zn = zn;
	}
	else
	{
		fsd.m_c = c;
		fsd.m_ch = ch;
		fsd.m_zn = zn;
	}
	return fsd;
}

Drob Drob::sumDrob(Drob d2)
{
	Drob sum;
	sum.m_c = m_c + d2.m_c;
	sum.m_ch = m_ch * d2.m_zn + m_zn * d2.m_ch;
	sum.m_zn = m_zn * d2.m_zn;
	sum = sum.FSD(sum.m_ch, sum.m_zn, sum.m_c);
	return sum;
}

Drob Drob::dellDrob(Drob d2)
{
	Drob del;
	del.m_c = 0;
	del.m_ch = (m_c * m_zn + m_ch) * d2.m_zn;
	del.m_zn = m_zn * (d2.m_c * d2.m_zn + d2.m_ch);
	del = del.FSD(del.m_ch, del.m_zn, del.m_c);
	return del;
}

Drob Drob::subDrob(Drob d2)
{
	Drob sub;
	sub.m_c = 0;
	sub.m_ch = ((m_c * m_zn + m_ch) * d2.m_zn) - ((d2.m_c * d2.m_zn + d2.m_ch) * m_zn);
	sub.m_zn = m_zn * d2.m_zn;
	if (sub.m_ch == 0)
	{
		return sub;
	}
	sub = sub.FSD(sub.m_ch, sub.m_zn, sub.m_c);
	return sub;
}

Drob Drob::multDrob(Drob d2)
{
	Drob mult;
	mult.m_c = 0;
	mult.m_ch = (m_c * m_zn + m_ch) * (d2.m_c * d2.m_zn + d2.m_ch);
	mult.m_zn = m_zn * d2.m_zn;
	mult = mult.FSD(mult.m_ch, mult.m_zn, mult.m_c);
	return mult;
}

bool Drob::moreDrob(Drob d2)
{
	cout << boolalpha;
	return m_c + (double)m_ch / m_zn > d2.m_c + (double)d2.m_ch / d2.m_zn;
}

bool Drob::lessDrob(Drob d2)
{
	cout << boolalpha;
	return m_c + (double)m_ch / m_zn < d2.m_c + (double)d2.m_ch / d2.m_zn;
}

bool Drob::equalDrob(Drob d2)
{
	cout << boolalpha;
	return m_c + (double)m_ch / m_zn == d2.m_c + (double)d2.m_ch / d2.m_zn;
}

bool Drob::inequalDrob(Drob d2)
{
	cout << boolalpha;
	return m_c + (double)m_ch / m_zn != d2.m_c + (double)d2.m_ch / d2.m_zn;
}

inline Drob Drob::operator+(Drob d2)
{
	Drob sum;
	sum.m_c = m_c + d2.m_c;
	sum.m_ch = m_ch * d2.m_zn + m_zn * d2.m_ch;
	sum.m_zn = m_zn * d2.m_zn;
	sum = sum.FSD(sum.m_ch, sum.m_zn, sum.m_c);
	return sum;
}

inline Drob Drob::operator-(Drob d2)
{
	Drob sum;
	sum.m_c = m_c + d2.m_c;
	sum.m_ch = m_ch * d2.m_zn + m_zn * d2.m_ch;
	sum.m_zn = m_zn * d2.m_zn;
	sum = sum.FSD(sum.m_ch, sum.m_zn, sum.m_c);
	return sum;
}

inline Drob Drob::operator*(Drob d2)
{
	Drob mult;
	mult.m_c = 0;
	mult.m_ch = (m_c * m_zn + m_ch) * (d2.m_c * d2.m_zn + d2.m_ch);
	mult.m_zn = m_zn * d2.m_zn;
	mult = mult.FSD(mult.m_ch, mult.m_zn, mult.m_c);
	return mult;
}

inline Drob Drob::operator/(Drob d2)
{
	Drob del;
	del.m_c = 0;
	del.m_ch = (m_c * m_zn + m_ch) * d2.m_zn;
	del.m_zn = m_zn * (d2.m_c * d2.m_zn + d2.m_ch);
	del = del.FSD(del.m_ch, del.m_zn, del.m_c);
	return del;
}

inline bool Drob::operator>(Drob d2)
{
	cout << boolalpha;
	return m_c + (double)m_ch / m_zn > d2.m_c + (double)d2.m_ch / d2.m_zn;
}

inline bool Drob::operator<(Drob d2)
{
	cout << boolalpha;
	return m_c + (double)m_ch / m_zn < d2.m_c + (double)d2.m_ch / d2.m_zn;
}

inline bool Drob::operator==(Drob d2)
{
	cout << boolalpha;
	return m_c + (double)m_ch / m_zn == d2.m_c + (double)d2.m_ch / d2.m_zn;
}

inline bool Drob::operator!=(Drob d2)
{
	cout << boolalpha;
	return m_c + (double)m_ch / m_zn != d2.m_c + (double)d2.m_ch / d2.m_zn;
}

void Drob::print() const
{
	if (m_ch == 0 && m_c == 0)
		cout << "0" << endl;
	else
	{
		if (m_ch == 0 && m_c != 0)
			cout << m_c << endl;
		else
		{
			if (m_c)
				cout << m_c << ".";
			cout << m_ch << "/" << m_zn << endl;
		}
	}
}
