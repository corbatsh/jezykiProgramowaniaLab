#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 10 //tymczasowe
using namespace std;
bool czyJest(int tablica[], int n, int szukana);
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

    //zakładając istnienie takiej n-elementowej tablicy zawierającej dane, wczytać wartość szukaną i przeszukując
    // tablice wypisywać indeksy pod którymi ta szukana występuje. Gdy nie występuje w ogóle w tablicy, to wypisuje
    // stosowny komunikat

    //poniżej testowany algorytm

    cout << "Podaj szukana wartosc: ";
    cin >> szukana;
    if (czyJest(t, N, szukana))
        cout << "Znalazlem";
    else
        cout << "Nie znalazlem";
    //koniec algorytmu

    //tu ewentualnie wyniki, komunikaty...

    return 0;
}

bool czyJest(int tablica[], int n, int szukana)
{
    bool znaleziono = 0;
    int i = 0;
    do
    {
        if (tablica[i] == szukana)
        {
            znaleziono = 1;
            i = n;
        }
        i++;
    } while (i <= n);
}