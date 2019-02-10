#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include "vector.hpp"

using namespace std;

class Matrix
{
    private:

        int vector_size;
        int number_of_vectors;
        Vector **vectors;

    public:

        Matrix();                                     //KOSTRUKTOR DEFAULTOWY
        Matrix(int v_size, int num_vectors);  //KONSTRUKTOR
        Matrix(const Matrix &M1);                     //KOSTRUKTOR KOPIUJACY
        friend istream& operator>>(istream &in, Matrix &M1);
        friend ostream& operator<<(ostream &out,const Matrix &M2);
        Matrix &operator=(const Matrix &M1);
        Matrix operator+(const Matrix &M1);
        Matrix operator-(const Matrix &M1);
        Matrix operator*(const int value);
        bool operator==(const Matrix &M1);
        bool operator!=(const Matrix &M1);
        Matrix &operator+=(const Matrix &M1);
        Matrix &operator-=(const Matrix &M1);
        Matrix &operator*=(const int value);
        Vector operator[](const int index);

};
#endif // MATRIX_H
