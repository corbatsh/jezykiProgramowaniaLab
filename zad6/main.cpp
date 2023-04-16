#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool czyJest (int tablica[], int n, int szukana);
void selectionSort (int t[], int n);
int main() {
    int i, szukana, n, *t; //inne zmienne w miarę potrzeby
    cout << "Program testuje algorytm ............" << endl;
    cout << "Ile elementow? ";
    cin >> n;
    t = new int[n+1]; // dane w tablicy od indeksu 1 do n
    //poniżej generowanie danych
    srand(time(NULL));
    for (i = 1; i <= n; i++) { // dane w tablicy od indeksu 1 do n
        cout << "t[" << i << "]=";
        // cin >> t[i];
        t[i] = rand() % 32700;
        //  t[i]=i;
        //  t[i]=-i;
        //  t[i]=5;
        cout << "t[" << i << "]=" << t[i] << endl;
    }

    //poniżej testowany algorytm

    cout << "Podaj szukana wartosc: ";
    cin >> szukana;
    if (czyJest(t, n, szukana))
        cout << "Znalazlem" << endl;
    else
        cout << "Nie znalazlem" << endl;

    cout << "posortowano:" << endl << endl;

    selectionSort(t, n);

    for (i = 1; i <= n; i++) { // dane w tablicy od indeksu 1 do n
        cout << "t[" << i << "]=" << t[i] << endl;
    }
    //tu ewentualnie wyniki, komunikaty...

    return 0;
}

bool czyJest (int tablica[], int n, int szukana)
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
    } while (i <= n); // dane w tablicy od indeksu 1 do n
    return znaleziono;
}
void selectionSort (int t[], int n) //zachowuje sie bardzo stabilnie - posortowana tablica jak i losowa mają podobne złożoności. Małe rozrzuty czasowe
{
    int indeks, min, i, nr;
    for (nr = 1; nr < n; nr++)
    {
        min = t[nr];
        indeks = nr;
        for (i = nr+1; i <= n; i++)
            if (t[i] < min)
            {
                min = t[i];
                indeks = i;
            }
        t[indeks] = t[nr];
        t[nr] = min;
    }
}

// opt = O(N^2)
// ocz = O(N^2)
// pes = O(N^2)
