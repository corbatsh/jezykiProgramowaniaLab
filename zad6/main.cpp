#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool czyJest(int tablica[], int n, int szukana);
int main() {
    int i, szukana, n, *t; //inne zmienne w miarę potrzeby
    cout << "Program testuje algorytm ............" << endl;
    cout << "Ile elementow? ";
    cin >> n;
    t = new int[n];
    //poniżej generowanie danych
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        cout << "t[" << i << "]=";
        cin >> t[i];
        //t[i] = rand() % 32700;

        //  t[i]=i;
        //  t[i]=-i;
        //  t[i]=5;
        //cout << "tpyrka[" << i << "]=" << t[i] << endl;
    }

    //poniżej testowany algorytm

    cout << "Podaj szukana wartosc: ";
    cin >> szukana;
    if (czyJest(t, n, szukana))
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
    return znaleziono;
}