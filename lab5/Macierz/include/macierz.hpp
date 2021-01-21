#include <iostream>


class Matrix {
	
	private:
		int w;
		int k;
		double **macierz;

	public:

		double set(int n, int m, double val);
		double get(int n, int m);

		Matrix(int w, int k);
		Matrix(int w, int k, double *macierz);
		Matrix(int n);

		Matrix* operator+(Matrix &m2);
		Matrix* operator-(Matrix &m2);
		Matrix* operator*(Matrix &m2);

		bool operator==(Matrix &m2);
		double* operator[](int);
		bool operator!=(Matrix &m2);
		void operator++(int);
		void operator--(int);
/*
		Matrix* add(Matrix &m2)noexcept(false);	
		Matrix* subtract(Matrix &m2)noexcept(false);
		Matrix* multiply(Matrix &m2)noexcept(false);
*/
		int cols();
		int rows();
		void print();
		void wyp_macierz();
   		Matrix(std::string filename)noexcept(false);
		bool store(string filename, string path)noexcept(false);
	~Matrix();
};
