#include<iostream>
#include<iomanip>
using namespace std;

class Matrix {
	int *p ;
	int row;
	int col;
public:
	Matrix(int row, int col) {
		this->row = row;
		this->col = col;
		p = new int[row * col];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				this->p[i*col+j] = i+j;
			}

		}
	}

	
	int get(int r, int c) {
		if (r > row && c > col)
		{
			cout << "Your are out of bound" << endl;
			exit(0);

		}
		int temp = 0;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (r == i && c == j )
				{
					temp = p[i * col + j];
				}
				
			}

		}
		return temp;

	}

	void set(int r, int c, int v) {
		if (r > row && c > col)
		{
			cout << "Your are out of bound" << endl;
			exit(0);

		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (r == i && c == j)
				{
					p[i * col + j] = v;
				}

			}

		}

	}

	void print() {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				int index = i * col + j;
				cout<<setw(5)<<p[index]<<" ";
			}

		cout << endl;
		}

	}
	void transpose(void) {
		int* temp = new int[this->row * this->col];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				
				temp[j * row + i] = p[i * col + j];
			 

			}

		}
		for (int i = 0; i < row*col; i++)
		{
			p[i] = temp[i];
		}
		int t = row;
		row = col;
		col = t;

	}

	void printSubMatrix(int r1, int r2, int c1, int c2) {

		if (r1 < 0 && r2 < 0 && c1 < 0 && c2 < 0) {
			cout << "Does not accept negative values" << endl;
			exit(0);
		}
		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (i >= r1 && i <= r2 && j >= c1 && j <= c2)
				{

					int index = i * col + j;
					cout << setw(5) << p[index] << " ";

				}
			}

			cout << endl;
		}
		
	}
	void makeEmpty(int n) {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (i < n)
				{
					p[i * col + j] = 0;
				}
			}

		}
	}

	void add(Matrix first, Matrix second) {
		if (second.row != first.row && second.col != first.col)
		{
			cout << "Both the matrix are not same to be add" << endl;
			exit(0);
		}
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{

				p[i * col + j] = first.p[i * col + j] + second.p[i * col + j];
			}

		}
		
	}

	~Matrix(){
		delete [] p;
	}
};

int main() {
	Matrix m(3,3);
	m.makeEmpty(2);
	m.print();
	m.transpose();
	m.print();
	m.printSubMatrix(1,2,1,2);
	



	
}