#include <iostream>
#include <cmath>
using namespace std;

class MatrixSquare
{
private:
	int** Values;
	int m_rows, m_columns;
public:

	MatrixSquare(int rows, int columns, int** arr)
	{
		m_rows = rows;
		m_columns = columns;

		Values = new int* [m_rows];
		for (int i = 0; i < rows; i++)
		{
			Values[i] = new int[m_columns];
			for (int j = 0; j < columns; j++)
				Values[i][j] = pow(arr[i][j], 2);
		}
	}

	void Print()
	{
		cout << "\n Square A+B:\n";
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				cout << Values[i][j] << " ";
			}
			cout << endl;
		}
	}
};

class Matrix
{
	int m_row, m_column;
	int** Value;
public:
	Matrix() {}
	Matrix(int row, int column)
	{
		m_row = row;
		m_column = column;
		Value = new int* [row];
		for (int i = 0; i < row; i++) Value[i] = new int[column];

	};
	Matrix(const Matrix&);
	int getRow() { return(m_row); };
	int getColumn() { return(m_column); };
	int& operator() (int, int);
	
	friend istream& operator>>(istream& in, Matrix& m1);
	friend ostream& operator<<(ostream& out, Matrix& m1);
	friend Matrix operator-(Matrix& m1, Matrix& m2);
	friend void operator--(Matrix& m, int);
	friend bool operator==(Matrix& m1, int);
	~Matrix();

	int ToDouble()
	{
		int sum = 0;
		for (int i = 0; i < getRow(); i++)
			for (int j = 0; j < getColumn(); j++)
			{
				sum += Value[i][j];
			}
		return sum;
	}

	MatrixSquare* Square()
	{
		return new MatrixSquare(m_row, m_column, Value);
	}

	bool operator!=(Matrix& m)
	{
		int flag = 0;
		for (int i = 0; i < m.getRow(); i++)
			for (int j = 0; j < m.getColumn(); j++)
			{
				if (Value[i][j] > m.Value[i][j] || Value[i][j] < m.Value[i][j])
					flag++;
			}
		if (flag > 0) return true;
		else return false;
	}
	Matrix& operator=(const Matrix& m)
	{		
		m_row = m.m_row;
		m_column = m.m_column;

		Value = new int* [m_row];

		for (int i = 0; i < m_row; i++)
		{
			Value[i] = new int[m_column];
			for (int j = 0; j < m_column; j++)
				Value[i][j] = m.Value[i][j];
		}

		return *this;
	}

	Matrix operator+(Matrix& m) 
	{
		{
			Matrix sum(m.getRow(), m.getColumn());
			for (int i = 0; i < m.getRow(); i++)
				for (int j = 0; j < m.getColumn(); j++)
					sum.Value[i][j] = Value[i][j] + m.Value[i][j];
			return(sum);
		}
	}
	Matrix& operator++(int)
	{
		for (int i = 0; i < getRow(); i++)
			for (int j = 0; j < getColumn(); j++)
				Value[i][j]++;
		return *this;
	}
	friend class MatrixSquare;
	operator Matrix() { return Matrix(m_row, m_column); }
};

int& Matrix::operator()(int row, int col)
{                            
	return (Value[row][col]);  
}

Matrix::Matrix(const Matrix& m): m_row(m.m_row),m_column(m.m_column) //копирующий конструктор - создает копию матрицы m
{
	Value = new int* [m_row];
	for (int i = 0; i < m_row; i++)  Value[i] = new int[m_column];
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_column; j++)
			Value[i][j] = m.Value[i][j];
	} 
}

istream& operator>>(istream& istr, Matrix& m) // перегрузка оператора ввода матрицы
{
	for (int i = 0; i < m.getRow(); i++)
		for (int j = 0; j < m.getColumn(); j++)
			istr >> m(i, j);
	return(istr);
}

ostream& operator<<(ostream& ostr, Matrix& m) //перегрузка оператора вывода матрицы
{
	for (int i = 0; i < m.getRow(); i++)
	{
		for (int j = 0; j < m.getColumn(); j++)
			ostr <<"\t" << m(i, j);
		ostr << "\n";
	}
	ostr << "\n* * * * * * * * * * * * * * *" << "\n";
	return(ostr);
}

Matrix operator-(Matrix& m1, Matrix& m2)
{
	Matrix temp(m1.getRow(), m1.getColumn());
	for (int i = 0; i < m1.getRow(); i++)
		for (int j = 0; j < m1.getColumn(); j++)
			temp(i, j) = m1(i, j) - m2(i, j);
	return(temp);
}

void operator--(Matrix& m, int)
{
	for (int i = 0; i < m.getRow(); i++)
		for (int j = 0; j < m.getColumn(); j++)
			 m(i, j)--;
}

bool operator==(Matrix& m1, int n)
{
	for (int i = 0; i < m1.getRow(); i++)
		for (int j = 0; j < m1.getColumn(); j++)
			if(m1(i,j)!= n)
			return false;
	return true;
}

Matrix::~Matrix() //деструктор
{
	for (int i = 0; i < m_row; i++)
		delete[] Value[i]; 
	delete[] Value;
}

int main()
{
	int m, n;
	cout << "enter number of rows and columns of matrix: "; cin >> m >> n;
	Matrix a(m, n);
	cout << "enter matrix A:\n";  cin >> a;
	Matrix b(m, n);
	cout << "enter matrix B:\n";  cin >> b;
	Matrix c(m, n);
	a++; 
	cout<<"Matrix A decrement:\n" << a;
	b--;
	cout <<"Matrix B increment:\n" << b;
	if (a == 0)
		cout << "Matrix A is null.\n";
	else cout << "Matrix A is not null.\n";
	if (a != b)
		cout << "Matrix A is not equal B.\n";
	else cout << "Matrix B is equel A.\n";
	c = a + b;
	cout <<"Matrix A+B:\n" << c;
	cout << "c to sum: " << c.ToDouble() << endl;
	c = a - b;
	cout << "Matrix A-B:\n" << c;
	MatrixSquare* ms = c.Square();
	ms->Print();
	
	return 0;
}