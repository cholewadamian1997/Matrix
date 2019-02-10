#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

using namespace std;

class Vector
{
    private:
        int vector_size;
        int * fields;

    public:

        Vector();
        Vector(int new_size);
        Vector(const Vector &v1);
        ~Vector();
        friend istream& operator >>(istream& in, Vector& v1);
        friend ostream& operator <<(ostream& out, Vector& v1);
        Vector &operator=(const Vector &v1);
        Vector operator+(const Vector &v1);
        Vector operator-(const Vector &v1);
        Vector operator*(const int value);
        int operator*(const Vector &v1);
        bool operator==(const Vector &v1);
        bool operator!=(const Vector &v1);
        Vector &operator+=(const Vector &v1);
        Vector &operator-=(const Vector &v1);
        Vector &operator*=(const int value);
        int operator*=(const Vector &v1);
        int operator[](const int index);

};
#endif // VECTOR_H
