#include <cstdlib>
#include "matrix.hpp"

using namespace std;

int main()
{
    int col, row;

    cout << "PODAJ WYMIARY" << endl;
    cout << "Ilość kolumn: ";
    cin >> col;
    cout << "Ilość wierszy: ";
    cin >> row;
    system("clear");

    Matrix M1(col, row);
    cout << "Podaj elementy pierwszej macierzy (wierszami) :" << endl;
    cin >> M1;
    system("clear");

    Matrix M2(col, row);
    cout << "Podaj elementy drugiej macierzy (wierszami) :" << endl;
    cin >> M2;
    system("clear");

    cout << "Macierz nr 1" << endl << M1 << endl << endl;
    cout << "Macierz nr 2" << endl << M2 << endl;

    int menu = 0;

    while(menu != 6){
        cout << endl <<  "Jaką operacje chcesz wybrac ?" << endl;
        cout << "1. Dodaj macierze" << endl
             << "2. Odejmij macierze" << endl
             << "3. Pomnoż macierz przez skalar" << endl
             << "4. Odczytaj zadany  wektor macierzy" << endl
             << "5. Sprawdz czy macierze sa równe" << endl
             << "6. WYjdz z programu" << endl;

        cout << endl << ": " ;
        cin >> menu;

        if (menu > 6 || menu < 0)
            cout << "NIE MA TAKIEJ OPCJI" << endl;

        system("clear");

        switch(menu){
            case 1:{
                    cout << "WYBRALES DODAWANIE AMCIERZY" << endl;
                    Matrix M3(col, row);
                    M3 = M1 + M2;
                    cout << M1 << endl << "  + " << endl << M2 << endl << "  = " << endl << M3 << endl;
                    break;
                }
            case 2:{
                    cout << "WYBRALES ODEJMOWANIE MACIERZY" << endl;
                    int x;
                    Matrix M3(col, row);
                    cout << "M1 - M2 czy M2 - M1 ? Wybierz 1 lub 2" << endl;
                    cin >> x;

                    if (x == 1)
                    {
                        M3 = M1 - M2;
                        cout << M1 << endl << "  - " << endl << M2 << endl << "  = " << endl << M3 << endl;
                        break;
                    }
                    else if ( x == 2)
                    {
                        M3 = M2 - M1;
                        cout << M2 << endl << "  - " << endl << M1 << endl << "  = " << endl << M3 << endl;
                        break;
                    }
                    else
                    {
                        cout << "NIE MA TAKIEJ OPCJI";
                        break;
                    }
                }
            case 3:{
                    cout << "WYBRALES MNORZENIE MACIERZY PRZEZ SKALAR" << endl;
                    int x, scalar;
                    cout << "Podaj skalar" << endl;
                    cin >> scalar;
                    cout << "Która macierz pomnożyc 1 czy 2 ?" << endl;
                    cin >> x;

                    Matrix M3(col, row);

                    if (x == 1)
                    {
                        M3 = M1 * scalar;
                        cout << M1 << endl << "  *  " << endl << "  " <<scalar << endl << "  = " << endl << M3 << endl;
                        break;
                    }
                    else if (x == 2)
                    {
                        M3 = M2 * scalar;
                        cout << M2 << endl << "  * " << endl << scalar << endl << "  = " << endl << M3 << endl;
                        break;
                    }
                    else
                    {
                        cout << "NIE MA TAKIEJ OPCJI";
                        break ;
                    }
                }
            case 4:{
                    cout << "WYBRALES ODCZYT WEKTORA Z MACIERZY" << endl;
                    int x , num;
                    cout << "Z której macierzy chcesz odczytac wektor: 1 czy 2" << endl;
                    cin >> x;
                    cout << "Podaj wiersz (nr. wektora) : " << endl;
                    cin >> num;

                    if (x == 1)
                    {
                        Vector v1 = M1[num];
                        cout << v1 << endl;
                        break;
                    }
                    else if (x == 2)
                    {
                        Vector v1 = M2[num];
                        cout << v1 << endl;
                        break;
                    }
                    else
                    {
                        cout << "NIE MA TAKIEJ OPCJI";
                        break;
                    }
                }
            case 5:{
                    cout << "WYBRALES PORÓWNYWANIE MACIERZY" << endl;
                    if (M1 == M2)
                    {
                        cout << "TAK, M1 = M2" << endl;
                        break;
                    }
                    else
                    {
                        cout << "NIE, M! != M2" << endl;
                        break;
                    }
                }
            default:{
                    break;
                }
        }
    }
    return 0;
}

