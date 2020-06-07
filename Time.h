#pragma once

class Time
{
private:
	int h;//часы
	int m;//минуты
	int s;//секунды

public:
	Time();
	Time(int s);
	Time(int m, int s);
	Time(int h, int m, int s);

	Time operator+ (Time t2);
	Time operator- (Time t2);
	Time operator* (Time t2);
	bool operator> (Time t2);
	bool operator< (Time t2);
	bool operator== (Time t2);
	bool operator!= (Time t2);
	Time operator() (int h1, int m1, int s1, int h2, int m2, int s2);

	void printTo12() const;
	void printTo24() const;

	~Time();
};

Time::Time()
{
	this->h = 0;
	this->m = 0;
	this->s = 0;
}

inline Time::Time(int s) : Time()
{
	this->s = s;
}

inline Time::Time(int m, int s) : Time(s)
{
	this->m = m;
}

inline Time::Time(int h, int m, int s) : Time(m, s)
{
	this->h = h;
}

inline Time Time::operator+(Time t2)
{
	Time t;
	t.h = this->h + t2.h;
	t.m = this->m + t2.m;
	t.s = this->s + t2.s;
	return t;
}

inline Time Time::operator-(Time t2)
{
	Time t;
	t.h = abs(this->h - t2.h);
	t.m = abs(this->m - t2.m);
	t.s = abs(this->s - t2.s);
	return t;
}

inline Time Time::operator*(Time t2)
{
	Time t;
	t.h = this->h * t2.h;
	t.m = this->m * t2.m;
	t.s = this->s * t2.s;
	return t;
}

inline bool Time::operator>(Time t2)
{
	cout << boolalpha;
	return (this->h * 3600 + this->m * 60 + this->s) > (t2.h * 3600 + t2.m * 60 + t2.s);
}

inline bool Time::operator<(Time t2)
{
	cout << boolalpha;
	return (this->h * 3600 + this->m * 60 + this->s) < (t2.h * 3600 + t2.m * 60 + t2.s);
}

inline bool Time::operator==(Time t2)
{
	cout << boolalpha;
	return (this->h * 3600 + this->m * 60 + this->s) == (t2.h * 3600 + t2.m * 60 + t2.s);
}

inline bool Time::operator!=(Time t2)
{
	cout << boolalpha;
	return (this->h * 3600 + this->m * 60 + this->s) != (t2.h * 3600 + t2.m * 60 + t2.s);
}

inline Time Time::operator()(int h1, int m1, int s1, int h2, int m2, int s2)
{
	Time t1, t2, t;
	t1.h = h1;
	t1.m = m1;
	t1.s = s1;
	t2.h = h2;
	t2.m = m2;
	t2.s = s2;
	t = t1 - t2;
	return t;
}

inline void Time::printTo12() const
{
	int t, sek, min, hou;
	t = this->s + this->m * 60 + this->h * 3600;
	hou = t / 3600;
	min = (t - hou * 3600) / 60;
	sek = t - hou * 3600 - min * 60;
	cout << "\n\n";
	cout << " Введенное время в 12 часовом формате: ";
	if (hou > 24)
	{
		int d;
		d = hou / 24;
		hou = hou - d * 24;
	}
	if (hou >= 0 && hou < 12)
	{
		hou < 10 ? cout << "0" << hou : cout << hou;
		cout << ":";
		min < 10 ? cout << "0" << min : cout << min;
		cout << ":";
		sek < 10 ? cout << "0" << sek : cout << sek;
		cout << " AM" << endl;
		cout << endl;
	}
	else
	{
		if (hou >= 12 && hou < 24)
		{
			if (hou > 12)
				(hou - 12) < 10 ? cout << "0" << hou - 12 : cout << hou - 12;
			else
				cout << hou;
			cout << ":";
			min < 10 ? cout << "0" << min : cout << min;
			cout << ":";
			sek < 10 ? cout << "0" << sek : cout << sek;
			cout << " PM" << endl;
			cout << endl;
		}
	}

}

inline void Time::printTo24() const
{
	int t, sek, min, hou;
	t = this->s + this->m * 60 + this->h * 3600;
	hou = t / 3600;
	min = (t - hou * 3600) / 60;
	sek = t - hou * 3600 - min * 60;
	cout << "\n\n";
	cout << " Введенное время в 24 часовом формате: ";
	if (hou > 24)
	{
		int d;
		d = hou / 24;
		hou = hou - d * 24;
	}
	hou < 10 ? cout << "0" << hou : cout << hou;
	cout << ":";
	min < 10 ? cout << "0" << min : cout << min;
	cout << ":";
	sek < 10 ? cout << "0" << sek : cout << sek << endl;
	cout << endl;
}

Time::~Time()
{
}
