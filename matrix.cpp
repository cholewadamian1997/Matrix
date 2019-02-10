#include "matrix.hpp"

//KOSTRUKTOR DEFAULTOWY
Matrix::Matrix(){
    vector_size = 2;
    number_of_vectors = 2;

    vectors = new Vector*[number_of_vectors];
    for (int i = 0; i < number_of_vectors; i++)
        vectors[i] = new Vector(vector_size);
}

// KONSTRUKTOR
Matrix::Matrix(int v_size,int num_vectors)  {
    vector_size = v_size;
    number_of_vectors = num_vectors;

    vectors = new Vector*[number_of_vectors];
    if ( vectors == NULL)
        delete vectors;

    for (int i = 0; i < number_of_vectors; i++)
        vectors[i] = new Vector(vector_size);
}

// KONSTRUKTOR KOPIUJACY
Matrix::Matrix(const Matrix &M1){
    vector_size = M1.vector_size;
    number_of_vectors = M1.number_of_vectors;

    vectors = new Vector*[number_of_vectors];
    for (int i = 0; i < number_of_vectors; i++){
        vectors[i] = new Vector(vector_size);
        *(vectors[i]) = *(M1.vectors[i]);
    }
}

//PRZECIAZENIA OPERATOROW

istream& operator>>(istream &in, Matrix &M1){
    for (int i=0; i < M1.number_of_vectors; i++)
        in >> *(M1.vectors[i]);

    return in;
}

ostream& operator<<(ostream &out,const Matrix &M1){
    for (int i=0; i < M1.number_of_vectors -1; i++)
        out << *(M1.vectors[i]) << endl;

    out << *(M1.vectors[M1.number_of_vectors -1]);
    return out;
}

Matrix &Matrix::operator=(const Matrix &M1){
    for(int i = 0; i < M1.number_of_vectors; i++)
        *(vectors[i]) = *(M1.vectors[i]);

    return *this;
}

Matrix Matrix::operator+(const Matrix &M1){
    Matrix M2(vector_size, number_of_vectors);
    for(int i=0; i < number_of_vectors; i++)
        *(M2.vectors[i]) = *(vectors[i]) + *(M1.vectors[i]);

    return M2;
}

Matrix Matrix::operator-(const Matrix &M1){
    Matrix M2(vector_size, number_of_vectors);
    for (int i = 0; i<number_of_vectors; i++)
        *(M2.vectors[i]) = *(vectors[i]) - *(M1.vectors[i]);

    return M2;
}


Matrix Matrix::operator*(const int value){
    Matrix M2(vector_size, number_of_vectors);
    for (int i = 0; i < number_of_vectors; i++)
        *(M2.vectors[i]) = *(vectors[i]) * value;

    return M2;
}

bool Matrix::operator==(const Matrix &M1){
    for(int i =0; i < number_of_vectors; i++)
        if (*(vectors[i]) != *(M1.vectors[i]))
            return false;

    return true;
}

bool Matrix::operator!=(const Matrix &M1){
    for(int i=0; i < number_of_vectors; i++)
        if( *(vectors[i]) == *(M1.vectors[i]))
            return false;

    return true;
}

Matrix &Matrix::operator+=(const Matrix &M1){
    for (int i = 0; i < number_of_vectors; i++)
        *(vectors[i]) += *(M1.vectors[i]);

    return *this;
}

Matrix &Matrix::operator-=(const Matrix &M1){
    for (int i = 0; i < number_of_vectors; i++)
        *(vectors[i]) -= *(M1.vectors[i]);

    return *this;
}

Matrix &Matrix::operator*=(const int value){
    for (int i = 0; i < number_of_vectors; i++)
        *(vectors[i]) *= value;

    return *this;
}

Vector Matrix::operator[](const int index){
    for (int i = 0; i < number_of_vectors; i++)
        if ( i == index)
            return *(vectors[i]);
}
