#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 10 //tymczasowe
using namespace std;

int main() {
    int t[N]; //będą zmiany na float
    int i, szukana, min, minIndex; //inne zmienne w miarę potrzeby
    bool znaleziono;

    cout << "Program testuje algorytm ............" << endl;

    //poniżej generowanie danych
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        //cout << "t[" << i << "]=";
        //cin >> t[i];
        //t[i] = rand() % 32700;

        //t[i]=i;
          t[i]=-i;
        //  t[i]=5;
        //cout << "tpyrka[" << i << "]=" << t[i] << endl;
    }

    //poniżej testowany algorytm

    //cout << "podaj szukana: ";
    //cin >> szukana;
    //znaleziono = false;
    //i = 0;
    //1 sposob
//    do
//    {
//        if (t[i] == szukana)
//            znaleziono = true;
//        i++;
//    } while (!znaleziono && i < N);
//
//    if (!znaleziono)
//        cout << "nie wystapila szukana liczba";
//    else
//        cout << "wystapila szukana liczba";

    //2 sposob
//    do
//    {
//        if (t[i] == szukana)
//            i = N; // jesli znajdzie to zmieni wartosc i na N, czyli wypisze ze znajdzie
//        i++; // doda jeden na ostatnim indexie przez co wyjdzie za zakres i bedzie 11, wypisze ze nie ma
//    } while (i < N);
//    if(i == N)
//        cout << "Nie ma";
//    else
//        cout << "Jest";

//Jest tablica z danymi, trzeba wyszukac wartosc najmniejsza i wypisać ją wraz z indeksem
//zakładamy, że elementy się nie powtarzają
    i = 0;
    min = t[0];
    minIndex = i;
    do
    {
        if (t[i] < min)
        {
            min = t[i];
            minIndex = i;
        }
        i++;

    } while (i < N);
    cout << "Najmniejszy element to " << min << " z indeksem " << minIndex;

    // zadanie jak wyzej - jest czy nie ma, ale wiemy, że tablica jest posortowana rosnąco.
    //koniec algorytmu

    /*
     * 1 indeks tablicy to lewa strona, ostatni indeks to prawa strona.
     * brac srednia z tego i na tej podstawie wyliczamy srodkowy indeks, przy okazji
     * sprawdzamy czy szukana jest rowna srodkowemu. Jesli jest wiekszy to indeks przesuwamy w prawo
     * jesli jest mniejszy to przesuwamy w lewo. W przedbiegach można sprawdzić czy szukana jest mniejsza niz 1 indeks
     * lub czy jest wieksza niz ostatni indeks
     */

    //tu ewentualnie wyniki, komunikaty...

    return 0;
}