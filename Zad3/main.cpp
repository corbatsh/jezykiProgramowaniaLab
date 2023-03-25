#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 10 //tymczasowe
using namespace std;

int main() {
    int t[N]; //będą zmiany na float
    int i, szukana; //inne zmienne w miarę potrzeby
    bool znaleziono;

    cout << "Program testuje algorytm ............" << endl;

    //poniżej generowanie danych
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        cout << "t[" << i << "]=";
        cin >> t[i];
        //t[i] = rand() % 32700;

        //  t[i]=i;
        //  t[i]=-i;
        //  t[i]=5;
        //cout << "tpyrka[" << i << "]=" << t[i] << endl;
    }

    //poniżej testowany algorytm

    cout << "podaj szukana: ";
    cin >> szukana;
    znaleziono = false;
    i = 0;
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
    do
    {
        if (t[i] == szukana)
            i = N;
        i++;
    } while (i < N);
    if(i == N)
        cout << "Nie ma";
    else
        cout << "Jest";
    //koniec algorytmu

    //tu ewentualnie wyniki, komunikaty...

    return 0;
}