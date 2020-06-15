#pragma once
#include<iostream>
#include<ctime>
numeric_limits<streamsize>;
using namespace std;

template<class T>
class Array2D
{
private:
	int row, col;
	T**arr = nullptr;

public:
	Array2D(int, int);
	void setRandom(int min = 0, int max = 9);
	
	Array2D<T> &operator+(const Array2D &arr2);
	Array2D<T>& operator-(const Array2D& arr2);
	Array2D<T>& operator*(const Array2D& arr2);
	Array2D<double>& operator/(Array2D& arr2);
	Array2D<T> &operator=(const Array2D &obj);

	T maxElem ();
	T minElem ();
	Array2D (const Array2D& obj);
	double determinal(const Array2D& arr2);
	Array2D &invers(Array2D &arr2);
	T *operator[](int ind);
	void print();

	template <typename T1> friend istream& operator>> (istream &in, Array2D<T1> &a);
	template <typename T1> friend ostream& operator<< (ostream &out, const Array2D<T1> &a);
	~Array2D();



};

template<class T>
Array2D<T>::Array2D(int r, int c):row(r),col(c)
{
	arr = new T*[row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new T[col];
	}
}

template<class T>
inline void Array2D<T>::setRandom(int min, int max)
{
	cout << "All" << endl;
	srand(time(NULL));
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}


template<>
inline void Array2D<double>::setRandom(int min, int max)
{
	cout << "Double" << endl;
	srand(time(NULL));
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % ((max - min + 1)*(int)pow(10, 2)) / pow(10, 2) + min;
		}
	}
}

template<class T>
inline Array2D<T> &Array2D<T>::operator+(const Array2D &arr2)
{
	if (this->row != arr2.row || this->col != arr2.col)
	{
		cout << "Сложение матриц невозможно!" << endl;
		exit(0);
	}
	Array2D arrSum (this->row, this->col);
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			arrSum[i][j] = this->arr[i][j] + arr2.arr[i][j];
		}
	}
	*this = arrSum;
	return *this;
}

template<class T>
inline Array2D<T>& Array2D<T>::operator-(const Array2D& arr2)
{
	if (this->row != arr2.row || this->col != arr2.col)
	{
		cout << "Вычетание матриц невозможно!" << endl;
		exit(0);
	}
	Array2D arrSub(this->row, this->col);
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			arrSub[i][j] = this->arr[i][j] - arr2.arr[i][j];
		}
	}
	*this = arrSub;
	return *this;
}

template<class T>
inline Array2D<T>& Array2D<T>::operator*(const Array2D& arr2)
{
	if (this->row != arr2.row || this->col != arr2.col)
	{
		cout << "Умножение матриц невозможно!" << endl;
		exit(0);
	}
	Array2D arrMult(this->row, this->col);
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			int summ = 0;
			for (size_t k = 0; k < this->col; k++)
			{
				summ += (this->arr[i][k] * arr2.arr[k][j]);
			}
			arrMult[i][j] = summ;
		}
	}
	*this = arrMult;
	return *this;
}

template<>
inline Array2D<double>& Array2D<double>::operator/(Array2D& arr2)
{
	if (this->row != arr2.row || this->col != arr2.col || determinal(arr2) == 0)
	{
		cout << "Деление матриц невозможно!" << endl;
		exit(0);
	}
	invers(arr2);
	Array2D<double> arrDel(this->row, this->col);
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			double summ = 0;
			for (size_t k = 0; k < this->col; k++)
			{
				summ += (this->arr[i][k] * arr2.arr[k][j]);
			}
			arrDel[i][j] = summ/determinal(arr2);
		}
	}
	*this = arrDel;
	return *this;
}

template<class T>
Array2D<T> &Array2D<T>::operator=(const Array2D<T> &obj)
{
	if (this != &obj)
	{
		for (size_t i = 0; i < this->row; i++)
		{
			delete[]arr[i];
		}
		delete[]arr;
		row = obj.row;
		col = obj.col;
		arr = new T * [row];
		for (size_t i = 0; i < row; i++)
		{
			arr[i] = new T[col];
		}
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				arr[i][j] = obj.arr[i][j];
			}
		}
		return *this;
	}
	else
		return *this;
	
}

template<class T>
inline T Array2D<T>::maxElem()
{
	T max = this->arr[0][0];
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			if (this->arr[i][j] > max)
			{
				max = this->arr[i][j];
			}
				
		}
	}
	return max;
}

template<class T>
inline T Array2D<T>::minElem()
{
	T min = this->arr[0][0];
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			if (this->arr[i][j] < min)
			{
				min = this->arr[i][j];
			}

		}
	}
	return min;
}

template<class T>
inline Array2D<T>::Array2D(const Array2D &obj)
{
	this->row = obj.row;
	this->col = obj.col;
	this->arr(this->row, this->col);
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			this->arr[i][j] = obj[i][j];
		}
	}
}

template<class T>
inline double Array2D<T>::determinal(const Array2D& arr2)
{
	double det(0);
	if (arr2.col == 2 && arr2.row == 2)
		det = (arr2.arr[0][0] * arr2.arr[1][1]) - (arr2.arr[0][1] * arr2.arr[1][0]);
	if (arr2.col == 3 && arr2.row == 3)
		det = (arr2.arr[0][0] * arr2.arr[1][1] * arr2.arr[2][2]) + (arr2.arr[0][1] * arr2.arr[1][2] * arr2.arr[2][0]) +
		(arr2.arr[1][0] * arr2.arr[2][1] * arr2.arr[0][2]) - (arr2.arr[0][2] * arr2.arr[1][1] * arr2.arr[2][0]) -
		(arr2.arr[0][1] * arr2.arr[1][0] * arr2.arr[2][2]) - (arr2.arr[1][2] * arr2.arr[2][1] * arr2.arr[0][0]);
	return det;
}

template< class T>
inline Array2D<T> &Array2D<T>::invers(Array2D &arr2)
{
	if(determinal(arr2) == 0)
	{
		cout << " Обратного массива не существует!" << endl;
		exit(0);
	}
	if (arr2.col == 2 && arr2.row == 2 && determinal(arr2) != 0)
	{
		swap(arr2.arr[0][0], arr2.arr[1][1]);
		arr2.arr[0][1] = -1 * arr2.arr[0][1];
		arr2.arr[1][0] = -1 * arr2.arr[1][0];
		Array2D arrInv(arr2.row, arr2.col);
		for (size_t i = 0; i < arr2.row; i++)
		{
			for (size_t j = 0; j < arr2.col; j++)
			{
				arrInv[i][j] = arr2.arr[i][j];
			}
		}
		arr2 = arrInv;
		return arr2;
	}
}

template<class T>
inline T * Array2D<T>::operator[](int ind)
{
	return arr[ind];
}

template<typename T>
ostream& operator<< (ostream &out, const Array2D<T> &a)
{
	for (size_t i = 0; i < a.row; i++)
	{
		for (size_t j = 0; j < a.col; j++)
		{
			out << a.arr[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

template<class T>
istream& operator>> (istream &in, Array2D<T> &a) 
{
	for (size_t i = 0; i < a.row; i++)
	{
		for (size_t j = 0; j < a.col; j++)
		{
			in >> a.arr[i][j];
		}
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return in;
}

template<class T>
inline void Array2D<T>::print()
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T>
Array2D<T>::~Array2D()
{
	for (size_t i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}







//Array2D<int> arr1(2, 2);
//arr1.setRandom();
//cin >> arr1;
//arr1.print();
//cout << arr1 << endl;
//cout << endl;
//Sleep(500);
//Array2D<double> arr2(2, 2);
//arr2.setRandom();
//cout << arr2 << endl;
//cout << endl;
/*Array2D<int> arr3(2, 2);
arr3 = arr1 - arr2;
arr3.print();*/
//cout << endl;
/*Array2D<int> arr4(2, 2);
arr4 = arr1/arr2;
arr4.print();*/
//double det = arr2.determinal(arr2);
//cout << "Det = " << det << endl;
//arr2.invers(arr2);
//cout << endl;
//arr2.print();
//double det2= arr2.determinal(arr2);
//cout << "Det2 = " << det2 << endl;
//Array2D<double> arr4(2, 2);
//arr4 = arr1/arr2;
//arr4.print();
//cout << " Max = " << arr1.maxElem() << endl;
//cout << " Min = " << arr2.minElem() << endl;