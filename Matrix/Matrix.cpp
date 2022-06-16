#ifdef MATRIX_EXPORTS
#define MATRIX_API __declspec(dllexport)
#else
#define MATRIX_API __declspec(dllimport)
#endif // MATHWIN32DLL_EXPORTS

#include "Matrix.h"

using namespace std;

class Matrix
{
public:
	int columns;
	int rows;
	vector<vector<double>> imatrix;
	friend ostream& operator<<(ostream&, Matrix);
	friend ofstream& operator<<(ofstream&, Matrix&);
	friend Matrix operator+(Matrix, Matrix);
	friend Matrix operator-(Matrix, Matrix);
	friend Matrix operator*(Matrix, double);
	friend Matrix operator&(Matrix, Matrix);
	friend double operator%(Matrix, Matrix);
	friend double operator^(Matrix, Matrix);
	friend istream& operator>>(istream&, Matrix&);


	Matrix() //конструктор по умолчанию
	{}

	Matrix(int col, int row) // конструктор с задаными размерами матрицы
	{
		double temp_double;
		columns = col;
		rows = row;
		cout << "Введите матрицу " << row << " на " << col << endl;
		for (double i = 0; i < row; ++i)
		{
			vector<double> temp;
			for (double j = 0; j < col; ++j)
			{
				cin >> temp_double;
				temp.push_back(temp_double);

			}
			imatrix.push_back(temp);

		}
	}


	friend ostream& operator<<(ostream& out, Matrix matrix) // перегрузка оператора вывода
	{
		for (double i = 0; i < matrix.rows; ++i)
		{
			for (double j = 0; j < matrix.columns; ++j)
			{
				out << matrix.imatrix[i][j] << " ";
			}
			out << endl;

		}
		return out;
	}

	friend Matrix operator+(Matrix A, Matrix B) //сложение матриц
	{
		try
		{

			if ((A.rows != B.rows) || (A.columns != B.columns))
			{
				throw(1);
			}
		}
		catch (int a)
		{
			cout << "Матрицы различаются по размерам";
			exit(1);
		}
		Matrix temp;
		vector<vector<double> > temp_array1;
		temp.columns = A.columns;
		temp.rows = A.rows;
		for (double i = 0; i < A.rows; i++)
		{
			vector<double> temp_array2;
			for (double j = 0; j < A.columns; j++)
			{
				temp_array2.push_back(A.imatrix[i][j] + B.imatrix[i][j]);
			}
			temp_array1.push_back(temp_array2);
		}

		temp.imatrix = temp_array1;
		return temp;
	}
	friend Matrix operator-(Matrix A, Matrix B) //разность матриц
	{
		try
		{

			if ((A.rows != B.rows) || (A.columns != B.columns))
			{
				throw(1);
			}
		}
		catch (int a)
		{
			cout << "Матрицы различаются по размерам";
			exit(1);
		}
		Matrix temp;
		vector<vector<double> > temp_array1;
		temp.columns = A.columns;
		temp.rows = A.rows;
		for (double i = 0; i < A.rows; i++)
		{
			vector<double> temp_array2;
			for (double j = 0; j < A.columns; j++)
			{
				temp_array2.push_back(A.imatrix[i][j] - B.imatrix[i][j]);
			}
			temp_array1.push_back(temp_array2);
		}

		temp.imatrix = temp_array1;
		return temp;
	}

	friend Matrix operator*(Matrix A, double B) //умножение матрицы на число
	{
		Matrix temp;
		vector<vector<double> > temp_array1;
		temp.columns = A.columns;
		temp.rows = A.rows;
		for (double i = 0; i < A.rows; i++)
		{
			vector<double> temp_array2;
			for (double j = 0; j < A.columns; j++)
			{
				temp_array2.push_back(A.imatrix[i][j] * B);
			}
			temp_array1.push_back(temp_array2);
		}

		temp.imatrix = temp_array1;
		return temp;
	}

	friend Matrix operator*(Matrix A, Matrix B)//умножение матриц
	{
		try
		{

			if (A.columns != B.rows)
			{
				throw(1);
			}
		}
		catch (int a)
		{
			cout << "Матрицы не связанные";
			exit(1);
		}
		Matrix c;
		vector<vector<double> > product;

		for (double i = 0; i < A.rows; i++)
		{
			vector<double> temp_r;
			for (double j = 0; j < B.columns; j++)
			{
				double T = 0;
				for (double g = 0; g < A.columns; g++)
				{
					T += A.imatrix[i][g] * B.imatrix[g][j];
				}
				temp_r.push_back(T);
			}
			product.push_back(temp_r);
		}
		c.rows = A.rows;
		c.columns = B.columns;
		c.imatrix = product;
		return c;
	}

	friend Matrix operator&(Matrix A, Matrix B)//произведение адамара
	{
		try
		{

			if ((A.rows != B.rows) || (A.columns != B.columns))
			{
				throw(1);
			}
		}
		catch (int a)
		{
			cout << "Матрицы различаются по размерам";
			exit(1);
		}
		Matrix temp;
		vector<vector<double> > temp_array1;
		temp.columns = A.columns;
		temp.rows = A.rows;
		for (double i = 0; i < A.rows; i++)
		{
			vector<double> temp_array2;
			for (double j = 0; j < A.columns; j++)
			{
				temp_array2.push_back(A.imatrix[i][j] * B.imatrix[i][j]);
			}
			temp_array1.push_back(temp_array2);
		}

		temp.imatrix = temp_array1;
		return temp;
	}
	double trace()//след матрицы
	{
		double T = 0;
		for (double i = 0; i < this->columns; i++)
		{

			T += this->imatrix[i][i];

		}
		return T;
	}

	double det()//определитель матрицы
	{
		try
		{

			if (this->rows != this->columns)
			{
				throw(1);
			}
		}
		catch (int a)
		{
			cout << "Матрица не квадратная";
			exit(1);
		}
		const double EPS = 1E-9;
		double
			n = this->columns;
		vector < vector<double> > a(n, vector<double>(n));
		a = this->imatrix;

		double det = 1;
		for (double i = 0; i < n; ++i) {
			double k = i;
			for (double j = i + 1; j < n; ++j)
				if (abs(a[j][i]) > abs(a[k][i]))
					k = j;
			if (abs(a[k][i]) < EPS) {
				det = 0;
				break;
			}
			swap(a[i], a[k]);
			if (i != k)
				det = -det;
			det *= a[i][i];
			for (double j = i + 1; j < n; ++j)
				a[i][j] /= a[i][i];
			for (double j = 0; j < n; ++j)
				if (j != i && abs(a[j][i]) > EPS)
					for (double k = i + 1; k < n; ++k)
						a[j][k] -= a[i][k] * a[j][i];
		}
		return det;
	}

	friend double operator%(Matrix A, Matrix  B)//скалярное произведение векторов
	{
		try
		{

			if ((A.columns != B.columns) && (A.rows == 1 == B.rows))
			{
				throw(1);
			}
		}
		catch (int a)
		{
			cout << "Введенные данные не корректны для данного вычисления";
			exit(1);
		}
		double res = 0;
		for (int i = 0; i < A.columns; i++)
		{
			res += A.imatrix[0][i] * B.imatrix[0][i];
		}

		return res;
	}

	double ev_norm_vector()//норма вектора эвклида
	{

		double a = 0;
		int sum = 0;
		for (int i = 0; i < this->imatrix[0].size(); i++)
		{
			sum += this->imatrix[0][i] * this->imatrix[0][i];
		}
		a = sqrt(sum);

		return a;
	}

	double max_norm_vector()//m-норма вектора
	{
		double a = 0;
		for (int i = 0; i < this->imatrix[0].size(); i++)
		{
			if (a < this->imatrix[0][i])
			{
				a = this->imatrix[0][i];
			}

		}


		return a;
	}

	double freb_norm_matrix()//норма фробениуса
	{
		double a;
		int sum = 0;
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				sum += this->imatrix[i][j] * this->imatrix[i][j];
			}
		}
		a = sqrt(sum);
		return a;
	}

	friend double operator^(Matrix A, Matrix B)//угол между вектроми
	{
		double res = 0;
		for (int i = 0; i < A.columns; i++)
		{
			res += A.imatrix[0][i] * B.imatrix[0][i];
		}

		return res / (A.ev_norm_vector() * B.ev_norm_vector());
	}

	double rank()//ранк матрицы
	{
		const double EPS = 1E-9;
		int n = this->rows;
		int m = this->columns;
		vector<vector<double>>a = this->imatrix;
		int rank = max(n, m);
		vector<char> line_used(n);
		for (int i = 0; i < m; ++i) {
			int j;
			for (j = 0; j < n; ++j)
				if (!line_used[j] && abs(a[j][i]) > EPS)
					break;
			if (j == n)
				--rank;
			else {
				line_used[j] = true;
				for (int p = i + 1; p < m; ++p)
					a[j][p] /= a[j][i];
				for (int k = 0; k < n; ++k)
					if (k != j && abs(a[k][i]) > EPS)
						for (int p = i + 1; p < m; ++p)
							a[k][p] -= a[j][p] * a[k][i];
			}
		}
		return rank;
	}

	void trans()//транспанирование матрицы
	{
		try
		{

			if (this->rows != this->columns)
			{
				throw(1);
			}
		}
		catch (int a)
		{
			cout << "Матрица не квадратная";
			exit(1);
		}

		vector<vector<double>> a = this->imatrix;
		vector<vector<double>> temp;
		for (int i = 0; i < this->rows; i++) {
			vector <double> b;
			for (int j = 0; j < this->columns; j++) {
				b.push_back(a[j][i]);
			}
			temp.push_back(b);
		}
		this->imatrix = temp;
	}

	Matrix add()
	{
		vector<vector<double>> a = this->imatrix;
		vector<double> temp2;
		vector<vector<double>> minor_matrix;
		int size = this->columns;
		Matrix A;
		int row = 0;
		int col = 0;
		for (int q = 0; q < size * size; q++)
		{
			vector<vector<double>> opred_minora;

			for (int i = 0; i < size; i++)//создание новой матрицы
			{
				if (i == col) continue;
				vector<double> temp;

				for (int j = 0; j < size; j++)
				{
					if (j == row)continue;
					else temp.push_back(a[i][j]);
				}
				opred_minora.push_back(temp);

			}

			A.imatrix = opred_minora;
			A.columns = size - 1;
			A.rows = size - 1;

			double temp_double = A.det();
			temp_double = temp_double * pow(-1, row + 1 + col + 1);
			temp2.push_back(temp_double);
			row++;
			if (row == size) {
				minor_matrix.push_back(temp2);
				temp2.clear();
				col++;

				row = 0;
			}
			if (col == size) break;

		}
		A.columns = size;
		A.rows = size;
		A.imatrix = minor_matrix;
		return A;


	}

	Matrix poisk_obrat()
	{
		vector<vector<double> > temp_array1;
		Matrix temp = this->add();
		temp.trans();
		double B = 1 / this->det();
		for (double i = 0; i < temp.rows; i++)
		{
			vector<double> temp_array2;
			for (double j = 0; j < temp.columns; j++)
			{
				temp_array2.push_back(temp.imatrix[i][j] * B);
			}
			temp_array1.push_back(temp_array2);
		}
		temp.imatrix = temp_array1;
		return temp;


	}

	void zapis_bin(const char* Fname)
	{
		double x;
		vector<vector<double>> a = this->imatrix;
		ofstream out(Fname, ios::binary);
		int n = this->rows;
		int m = this->columns;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				x = a[i][j];
				out.write((char*)&x, sizeof(x));

			}

		}
		out.close();





	}

	void read_bin(const char* Fname, int n, int m)
	{
		double x;
		vector<vector<double>> a;
		ifstream in(Fname, ios::binary);
		for (int i = 0; i < n; i++)
		{
			vector<double> b;
			for (int j = 0; j < m; j++)
			{

				in.read((char*)&x, sizeof(x));
				b.push_back(x);

			}
			a.push_back(b);

		}
		in.close();
		this->imatrix = a;
		this->columns = m;
		this->rows = n;

	}

	friend ofstream& operator<<(ofstream& in, Matrix& a)
	{
		vector<vector<double>> A = a.imatrix;
		int i, j;

		for (i = 0; i < a.rows; i++) {
			for (j = 0; j < a.columns; j++) {
				in << A[i][j];
				if (j != a.columns - 1) in << " ";

			}
			in << endl;
		}


		return in;
	}

	friend istream& operator>>(istream& out, Matrix& a)
	{
		vector<vector<double>> vec2;
		vector<double> vec;
		string word, line;
		int size;
		int row = 0;
		while (getline(out, line))
		{
			row++;
			stringstream ss(line);
			while (ss >> word)
			{
				vec.push_back(stod(word));
			}
			vec2.push_back(vec);
			size = vec.size();
			vec.clear();


		}
		a.imatrix = vec2;
		a.columns = size;
		a.rows = row;




		return out;

	}




};
