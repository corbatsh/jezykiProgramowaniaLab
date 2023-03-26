#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
float pole_prostokata(float a, float b);
void pole_obw1(float a, float b, float &p, float &o);
bool pole_obw2(float a, float b, float &p, float &o);
int pole_obw3(float a, float b, float &p, float &o);
int pole_obw4(float a, float b, float *p, float *o);
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

int main() {

    float aa, bb, pole, obwod; //*pole, *obwod;
    float *pole2, *obwod2;
    pole2 = new float;
    obwod2 = new float;
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
        cout << "Co najmniej jeden bok zly" << endl;
    // te funkcje nie maja uprawnien do pracy z interfejsem (klawiatura, ekran itp..)
    // gdyby tak było, nie mają przyszłości. Nie zastosuję ich w żadnych innych programach

    //3 sposob bazujacy na kodach

    cout << endl << "switch:" << endl << endl;

    switch( pole_obw3(aa, bb, pole, obwod) )
    {
        case 0:
            cout << "Pole = " << pole << endl;
            cout << "Obw = " << obwod << endl;
            break;
        case 1:
            cout << "Bok a jest nieprawidlowy" << endl;
            break;
        case 2:
            cout << "Bok b jest nieprawidlowy" << endl;
            break;
        case 3:
            cout << "Oba boki sa nieprawidlwe" << endl;
            break;
    }

    cout << endl << "switch2:" << endl << endl;
    switch( pole_obw4(aa, bb, &pole, &obwod) ) //..., pole, obwod) )
    {
        case 0:
            cout << "Pole = " << pole << endl; //*pole
            cout << "Obw = " << obwod << endl; //*obwod
            break;
        case 1:
            cout << "Bok a jest nieprawidlowy" << endl;
            break;
        case 2:
            cout << "Bok b jest nieprawidlowy" << endl;
            break;
        case 3:
            cout << "Oba boki sa nieprawidlwe" << endl;
            break;
    }

    cout << endl << "switch na wskaznikach:" << endl << endl;

    switch( pole_obw4(aa, bb, pole2, obwod2) )
    {
        case 0:
            cout << "Pole = " << pole << endl;
            cout << "Obw = " << obwod << endl;
            break;
        case 1:
            cout << "Bok a jest nieprawidlowy" << endl;
            break;
        case 2:
            cout << "Bok b jest nieprawidlowy" << endl;
            break;
        case 3:
            cout << "Oba boki sa nieprawidlwe" << endl;
            break;
    }

    return 0;
}

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

int pole_obw3(float a, float b, float &p, float &o)
{
    int kod = 0;
    if (a <= 0 )
        kod++;
    if (b <= 0)
        kod+=2;
    p=a*b;
    o=2*a+2*b;
    return kod;
}

int pole_obw4(float a, float b, float *p, float *o)
{
    int kod = 0;
    if (a <= 0 )
        kod++;
    if (b <= 0)
        kod+=2;
    *p=a*b;
    *o=2*a+2*b;
    return kod;
}
