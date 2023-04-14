#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#define N 10
/*
 * 1 indeks tablicy to lewa strona, ostatni indeks to prawa strona.
 * brac srednia z tego i na tej podstawie wyliczamy srodkowy indeks, przy okazji
 * sprawdzamy czy szukana jest rowna srodkowemu. Jesli jest wiekszy to indeks przesuwamy w prawo
 * jesli jest mniejszy to przesuwamy w lewo. W przedbiegach można sprawdzić czy szukana jest mniejsza niz 1 indeks
 * lub czy jest wieksza niz ostatni indeks
 */

/*
 * ZD:
 * Zakładając, że elementy mogą się powtarzać, wyszukaj i wypisz wartość najmniejszą wraz z indeksami, pod
 * którymi występuje i analogicznie największą z indeksami.
 */

int srednia(int a, int b);
using namespace std;
int main() {

    int lewaStrona = 0, prawaStrona = N-1, t[N], szukana = 59, i = 0, index = 0, srodkowyIndeks, minValue, minIndex, maxValue, maxIndex;
    for (; i < N; i++)
    {
        t[i] = i + 50;
        cout << t[i];
    }
    //zadanie 1

    if (szukana >= t[0] && szukana <= t[N-1])
    {
        srodkowyIndeks = srednia(lewaStrona, prawaStrona);
        cout << endl << "srodkowy index: " << srodkowyIndeks << endl;
        do
        {
            if(t[srodkowyIndeks] < szukana)
            {
                lewaStrona = srodkowyIndeks;
                srodkowyIndeks = srednia(lewaStrona, prawaStrona);
            }
            else if (t[srodkowyIndeks] > szukana)
            {
                prawaStrona = srodkowyIndeks;
                srodkowyIndeks = srednia(lewaStrona, prawaStrona);
            }
            else
            {
                cout << "Znaleziono szukana pod indeksem " << srodkowyIndeks;
                break;
            }

            cout << endl << "srodkowy index: " << srodkowyIndeks << " lewa strona: " << lewaStrona << " prawa strona " << prawaStrona << endl;
            index++;

        }
        while (index < N);
    }

    // Zadanie 2
    minValue = t[0];
    maxValue = t[0];
    for (i = 1; i < N; i++)
    {
        if(t[i] < minValue)
            minValue = t[i];
        if(t[i] > maxValue)
            maxValue = t[i];
    }

    for (i = 0; i < N; i++)
    {
        if(t[i] == minValue)
            cout << endl << "znaleziono najmniejsza wartosc pod indeksem " << i;
        if(t[i] == maxValue)
            cout << endl << "znaleziono najwieksza wartosc pod indeksem " << i;
    }
    return 0;
}
int srednia(int a, int b) {
    return (a+b+1)/2;
};
