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

//w trakcie tworzenia funkcji nie wiemy co tam trafi, więc poniższe parametry nazywa się parametrami
// formalnymi. Mogą być tutaj przekazywane zmienne, stałe, definiowane lub wyrażenia. Tutaj są to
// parametry przekazywane przez wartość.
float pole_prostokata(float a, float b)
{
    return a*b;
}

void pole_obw1(float a, float b, float &p, float &o)
{
    p=a*b;
    o=2*a+2*b;
}

//kolejna wersja
bool pole_obw2(float a, float b, float &p, float &o)
{
    if (a <= 0 || b<=0)
        return false;
    p=a*b;
    o=2*a+2*b;
    return true;
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
    // parametry aktualne, to te które są w trakcie wywoływania funkcji czyli te co tam zadeklarujemy
    // aa i bb są parametrami aktualnymi. Przekazujemy je tutaj przez wartość.
    if (pole > 25)
        cout << "Za duzy" << endl;
    else
        if (pole <= 0)
            cout << "To nie jest prostokat" << endl;
        else
            cout << "To dobry prostokat o polu " << pole << endl;
    pole_obw1(aa, bb, pole, obwod);
    cout << "Pole = " << pole << endl;
    cout << "Obw = " << obwod << endl;
    // funkcja ktora przyjmuje za parametry adres zmiennych (ampersand) odwoluja sie do adresu
    // zmiennej ktora zostanie tam przekazana i wlasnie na niej pracuja, a nie jak przy zwyklej
    // zmiennej, czyli nie kopiuja. Nazywa sie to przekazywanie przez referencje

    // kolejna wersja
    if( pole_obw2(aa, bb, pole, obwod) )
    {
        cout << "Pole = " << pole << endl;
        cout << "Obw = " << obwod << endl;
    }
    else
        cout << "Co najmniej jeden bok zly";
    // te funkcje nie maja uprawnien do pracy z interfejsem (klawiatura, ekran itp..)
    // gdyby tak było, nie mają przyszłości. Nie zastosuję ich w żadnych innych programach
    return 0;
}
