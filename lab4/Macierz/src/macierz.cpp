#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <exception>

using namespace std;

#include "macierz.hpp"


//operatory

Matrix* Matrix ::operator+(Matrix &m2){

    if((w != m2.w) || (k != m2.k)){
        cout<< ("Bląd rozmiaru macierzy.") <<endl;

    }
    Matrix *wynik = new Matrix(w,k);
    double wart = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
            wart = this->get(i, j) + m2.get(i, j);
			wynik->set(i, j, wart);
        }
    }
    return wynik;
}

Matrix* Matrix ::operator-(Matrix &m2){
    if((w != m2.w) || (k != m2.k)){
        cout<< ("Bląd rozmiaru macierzy.") <<endl;
    }
    Matrix *wynik= new Matrix(w, k);
    double wart = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
           wart = this->get(i, j) - m2.get(i, j);
        
			wynik->set(i, j, wart);
        }
    }
    return wynik;
}

Matrix* Matrix ::operator* (Matrix &m2){
    if(k != m2.w){
        cout<< ("Bląd rozmiaru macierzy.") <<endl;
    }
    Matrix* wynik = new Matrix(w, m2.k);
	double wart;
	for (int i = 0; i < w; i++){
		for (int j = 0; j < m2.k; j++){
			wart = 0;
			for (int s = 0; s < k; s++){
				wart += get(i, s) * m2.get(s, j);
			}
			wynik->set(i, j, wart);
		}
	}
    return wynik;
}

bool Matrix::operator==(Matrix &m2){
	if(this->w == m2.w && this->k == m2.k){
		for (int i = 0; i < m2.w; i++){
			for (int j = 0; j < m2.k; j++){
				if (this->get(i, j) != m2.get(i, j)) return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
}
double* Matrix::operator[](int i){
	if (i >= this->w) {
		cout << "Błąd przy pobieraniu listy elementow" << endl;
        
	}
	return this->macierz[i];
}

bool Matrix::operator!=(Matrix &m2){
	if (this->w != m2.w || this->k != m2.k){
		return true;
	}
	for (int i = 0; i < m2.w; i++){
		for (int j = 0; j < m2.k; j++){
			if (this->get(i, j) == m2.get(i, j)){
				return false;
			}
		}
	}
	return true;
}


void Matrix::operator++(int){
    double wart = 0;
	for (int i = 0; i < this->w; i++){
		for (int j = 0; j < this->k; j++){
			wart = this->get(i, j) + 1.0;
			this->set(i, j, wart);
		}
	}
}

void Matrix::operator--(int){
    double wart = 0;
	for (int i = 0; i < this->w; i++){
		for (int j = 0; j < this->k; j++){
			wart = this->get(i, j) - 1.0;
			this->set(i, j, wart);
		}
	}
}

//
// dodatkowy konstruktor jako argument przyjmujący ścieżkę do pliku o podanym wcześniej formacie i na jego podstawie tworzący nową macierz na podstawie przekazanego pliku
Matrix::Matrix(string filename){
try{
    fstream file;
    file.open(filename, ios::in);
    if(file.good()){
    	file >> w;
        file >> k;
        macierz = new double * [w];
        for(int i = 0; i < w; i++){
            macierz[i] = new double [k];
            for(int j = 0; j < k; j++){
                file >> macierz[i][j];
            }
        }
        file.close();
        }
        else {
            throw runtime_error("Bląd podczas tworzenia macierzy.");
        }
    }
    catch(const std::exception &e){
        cerr << e.what() <<endl;
    }
}

 // przyjmujący dwa argumenty typu int tworzący macierz o podanych wymiarach zainicjalizowaną zerami 
Matrix::Matrix(int n, int m){
    w = n;
    k = m;
    macierz = new double * [n];
    for(int i = 0; i < n; i++){
        macierz[i] = new double [m];
        for(int j = 0; j < m; j++){
            macierz[i][j] = 0;
        }
    }
}
// przyjmujący jeden argument typu int tworzący macierz kwadratową o podanym rozmiarze zainicjalizowaną zerami
Matrix::Matrix(int n){
    w = n;
    k = n;
    macierz = new double * [n];
    for(int i = 0; i < n; i++){
		macierz[i] = new double [n];
        for(int j = 0; j < n; j++){
            macierz[i][j] = 0;
        }
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < w; i++){
        delete [] macierz[i];
	}
    delete [] macierz;
}

// set(n, m, val) - metoda ustawiająca wartość elementu (n, m) na val
double Matrix::set(int n, int m, double val){
try{
    if((n < 0) || (n >= w) || (m < 0) || (m >= k)){
     throw runtime_error("Bląd podczas ustawiania wartosci elementu.");
    }
    return macierz[n][m] = val;
}
catch(const exception &e){
    cerr << e.what() << endl;
}
}
// get(n, m) - metoda pobierająca element (n, m)
double Matrix::get(int n, int m){

    if(n < w && n >= 0 && m < k && m >= 0){
    return macierz[n][m];
	}
    else 
        throw runtime_error("Bląd podczas pobierania elementow.");

    }
/*
 // add(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą sumą bieżącej macierzy oraz macierzy przekazanej jako argument
Matrix* Matrix::add(Matrix &m2){
try{
    if((w != m2.w) || (k != m2.k)){
        throw runtime_error("Bląd podczas dodawania.");
    }
    Matrix *wynik = new Matrix(w,k);
    double wart = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
            wart = this->get(i, j) + m2.get(i, j);
			wynik->set(i, j, wart);
        }
    }
    return wynik;
    }
    catch(const exception &e){
        cerr << e.what() << endl;
    }
    
}
// subtract(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą różnicą bieżącej macierzy oraz macierzy przekazanej jako argument
Matrix* Matrix::subtract(Matrix &m2){
try{
    if((w != m2.w) || (k != m2.k)){
        throw runtime_error("Bląd podczas odejmowania.");
    }
    Matrix *wynik= new Matrix(w, k);
    double wart = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
           wart = this->get(i, j) - m2.get(i, j);
        
			wynik->set(i, j, wart);
        }
    }
    return wynik;
    }
    catch(const exception &e){
        cerr << e.what() << endl;
    }
}
    
// multiply(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą iloczynem bieżącej macierzy oraz macierzy przekazanej jako argument
Matrix* Matrix::multiply(Matrix &m2){
try{
    if(k != m2.w){
        throw runtime_error("Bląd podczas mnozenia.");
    }
    Matrix* wynik = new Matrix(w, m2.k);
	double wart = 0;
	for (int i = 0; i < this->w; i++){
		for (int j = 0; j < m2.k; j++){
			wart = 0;
			for (int k = 0; k < this->k; k++){
				wart += this->get(i, k) * m2.get(k, j);
			}
			wynik->set(i, j, wart);
		}
	}
    return wynik;
    }
    catch(const exception &e){
        cerr << e.what() << endl;
    }
}
*/
// cols() - metoda zwracająca liczbę kolumn macierzy
int Matrix::cols(){
    return k;
}

// rows() - metoda zwracająca liczbę wierszy macierzy
int Matrix::rows(){
    return w;
}

// print() - metoda wyświetlająca macierz na ekranie
void Matrix::print(){
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
            cout << macierz[i][j] << " ";
		}
    cout << endl;
    }
}

// store(std::string filename, std::string path) - metoda zapisująca macierz w pliku; w pliku powinny być zapisane wymiary macierzy (liczba kolumn i liczba wierszy w pierwszym wierszu pliku) oraz jej zawartość (każdy wiersz macierzy w osobnym wierszu pliku)
bool Matrix::store(string filename, string path){
    try{
    fstream file;
    file.open((path + filename).c_str(), ios::out);
    if(file.good()){
        file << w << " " << k << endl;
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < k; j++)
                file << macierz[i][j] << " ";
            file << endl;
        }
        file.close();
        }
        else
            throw runtime_error("Bląd zapisu.");
    }
    catch(const exception &e) {
        cerr << e.what() <<endl;
    }
        return false;
}

	void Matrix::wyp_macierz(){
		for (int i = 0; i < w; i++){
			for (int j = 0; j < k; j++){
				macierz[i][j] = (double)(rand() % 6);
			}
		}	
	}
