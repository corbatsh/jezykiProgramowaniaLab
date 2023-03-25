#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//void gotoxy(int x, int y)
//{
//    COORD c;
//    c.X = x;
//    c.Y = y;
//    SetConsoleCursorPosition (GetSTDHandle (STD_OUTPUT_HANDLE), c);
//}
//
//void klawisz()
//{
//    cout << "Nacisnij jakis klawisz" << endl;
//    system("pause>>null");
//}

float pole_prostokata(float a, float b)
{
    return a*b;
}

int main() {

    float aa, bb, pole, obwod;
//    gotoxy(15,2);
    cout << "Program funkcje 1" << endl;
//    klawisz();
    cout << "Pole prost. o bokach 2,5 i 4 wynosi " << pole_prostokata(2.5, 4) << endl;
    cout << "bok a= ";
    cin >> aa;
    cout << "bok b= ";
    cin >> bb;
//    poniżej efektywne wywołanie
    pole = pole_prostokata(aa,bb);
    if (pole > 25)
        cout << "Za duzy" << endl;
    else
        if (pole <= 0)
            cout << "To nie jest prostokat" << endl;
        else
            cout << "To dobry prostokat o polu " << pole << endl;

    return 0;
}
