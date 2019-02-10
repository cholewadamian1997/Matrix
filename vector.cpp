#include "vector.hpp"

//KOSTRUKTOR DEFAULTOWY
Vector::Vector(){
    vector_size = 2;
    fields = new int [vector_size];
    if (fields == NULL){
        cout << "BŁAD PAMIECI";
    }
    for (int i = 0; i < vector_size; i++)
        fields[i] = 0;
}

// KOSTRUKTOR
Vector::Vector(int new_size){
    if (new_size <= 0)
       cout << endl << "Rozmiar musi byc dodatni" << endl;

    vector_size = new_size;
    fields = new int [vector_size];
    if (fields == NULL){
        cout << "BLAD PAMIECI";
    }
    for(int i=0; i < vector_size; i++)
        fields[i] = 0;
}

//KONSTRUKTOR KOPIUJACY
Vector::Vector(const Vector &v1){
    vector_size = v1.vector_size;
    for (int i = 0; i < vector_size; i++)
        fields[i] = v1.fields[i];
}

//DESTRUKTOR
Vector::~Vector(){
    delete[] fields;
}

//PRZECIAZENIE OPERATOROW
istream& operator>>(istream& in, Vector& v1){

    for(int i=0; i < v1.vector_size; i++)
        in >> v1.fields[i];
    return in;
}

ostream& operator<<(ostream& out, Vector &v1){
    out << "[";

    for(int i=0; i < v1.vector_size - 1; i++){
        cout.width(3);
        out << v1.fields[i] << " ";
    }

    cout.width(3);
    out << v1.fields[v1.vector_size - 1];
    cout.width(3);
    cout << "]";
    return out;
}

Vector &Vector::operator=(const Vector &v1){
    for (int i=0; i < vector_size; i++)
        fields[i] = v1.fields[i];
    return *this;
}

Vector Vector::operator+(const Vector &v1){
    Vector v2(vector_size);
    for(int i=0; i < vector_size; i++)
        v2.fields[i] = v1.fields[i] + fields[i];

    return v2;
}

Vector Vector::operator-(const Vector &v1){
    Vector v2(vector_size);
    for(int i=0; i < vector_size; i++)
        v2.fields[i] = fields[i] - v1.fields[i];

    return v2;
}

Vector Vector::operator*(const int value){
    Vector v(vector_size);
    for(int i=0; i < vector_size; i++)
        v.fields[i] = fields[i] * value;

    return v;
}

int Vector::operator*(const Vector &v1){
    int x=0;
    for(int i=0; i < vector_size; i++)
        x += fields[i] + v1.fields[i];

    return x;
}

bool Vector::operator==(const Vector &v1){
    for (int i=0; i < vector_size; i++)
        if (fields[i] != v1.fields[i])
            return false;

    return true;
}

bool Vector::operator!=(const Vector &v1){
    for (int i=0; i < vector_size; i++)
        if (fields[i] != v1.fields[i])
            return true;

    return false;
}

Vector &Vector::operator+=(const Vector &v1){
    for (int i=0; i < vector_size; i++)
        fields[i] += v1.fields[i];

    return *this;
}

Vector &Vector::operator-=(const Vector &v1){
    for (int i=0; i < vector_size; i++)
        fields[i] -= v1.fields[i];

    return *this;
}

Vector &Vector::operator*=(const int value){
    for (int i=0; i < vector_size; i++)
        fields[i] *= value;

    return *this;
}

int Vector::operator[](const int index){
    if(index < 0 || index > vector_size - 1)
    {
        cout << "Nie ma pola o takim ideksie" << endl;
        return 0;
    }

    for(int i=0; i < vector_size; i++)
        if (i == index)
            return fields[i];
}
