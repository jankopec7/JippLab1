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

		Matrix* add(Matrix &m2);	
		Matrix* subtract(Matrix &m2);
		Matrix* multiply(Matrix &m2);

		int cols();
		int rows();
		void print();
		void wyp_macierz();
   		Matrix(std::string filename);
		bool store(string filename, string path);
	~Matrix();
};
