#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool czyJest (int tablica[], int n, int szukana);
int minimum (int t[], int n);
void minMax1 (int t[], int n, int &min, int &max);
void minMax2 (int t[], int n, int *min, int *max);
void selectionSort (int t[], int n);
int szukaj (int t[], int n, int a, int b, int znalezione[]);

int main() {
    int i, szukana, n, *t, minim, maksim, *znalezione, iloscZnalezionych, a, b; //inne zmienne w miarę potrzeby
    int resultSize = 0;
    cout << "Program testuje algorytm ............" << endl;
    cout << "Ile elementow? ";
    cin >> n;
    t = new int[n+1]; // dane w tablicy od indeksu 1 do n
    znalezione = new int[n+1]; // Dynamically allocate memory for znalezione array
    //poniżej generowanie danych
    srand(time(NULL));
    for (i = 1; i <= n; i++) { // dane w tablicy od indeksu 1 do n
        //cout << "t[" << i << "]=";
        // cin >> t[i];
       //t[i] = rand() % 32700;
          t[i]=i;
        //  t[i]=-i;
        //  t[i]=5;
        cout << "t[" << i << "]=" << t[i] << endl;
    }
    cout << "Podaj przedzial od do: " << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    iloscZnalezionych = szukaj(t, n, a, b, znalezione);
    if (iloscZnalezionych)
    {
        cout << "znalezione: "<< iloscZnalezionych << endl;
        for (int i = 1; i <= iloscZnalezionych; i++)
        {
            cout << "znaleziona[" << i << "]" << znalezione[i] << endl;
        }
    }
    else
        cout << "Brak znalezionych";




    delete[] znalezione; // Free the dynamically allocated memory

    cout << "Wartosc minimalna w tablicy to: " << minimum(t,n) << endl;

    cout << "wywolano minMax1:" << endl;
    minMax1 (t, n, minim, maksim);
    cout << "min=" << minim << " max=" << maksim << endl;

    cout << "wywolano minMax2:" << endl;
    minMax2 (t, n, &minim, &maksim);
    cout << "min=" << minim << " max=" << maksim << endl;

    // bardzo fajna rzecz wyżej - dzięki tej referencji możemy korzystać z wcześniej użytych parametrów, które mamy w funkcji minMax

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

int minimum (int t[], int n)
{
    int min;
    min = t[1]; // dane w tablicy od indeksu 1 do n
    for (int i = 2; i <= n; i++)
    {
        if (t[i] < min)
            min = t[i];
    }
    return min;
}

void minMax1 (int t[], int n, int &min, int &max) //przekazanie tego przez referencje da nam korzysc taka, że pracujemy na oryginalnych adresie lokalnym minMax w main
{
    min = t[1]; // dane w tablicy od indeksu 1 do n
    max = t[1];
    for (int i = 2; i <= n; i++) {
        if (t[i] < min)
            min = t[i];
        else if (t[i] > max)
            max = t[i];
    }
}

void minMax2 (int t[], int n, int *min, int *max) //przekazanie tego przez wskaźnik da nam korzysc taka, że pracujemy na oryginalnych lokalnych minMax w main
{
    *min = t[1]; // dane w tablicy od indeksu 1 do n
    *max = t[1];
    for (int i = 2; i <= n; i++) {
        if (t[i] < *min)
            *min = t[i];
        else if (t[i] > *max)
            *max = t[i];
    }
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

int szukaj(int t[], int n, int a, int b, int znalezione[])
{
    int licznik = 0;
    for (int i = 0; i <= n; i++)
    {
        if (t[i] >= a && t[i] <= b)
        {
            licznik++;
            znalezione[licznik] = t[i]; // wazna jest tutaj inkrementacja licznika przed wsadzeniem do znalezionych
        }
    }
    return licznik;
}

// opt = O(N^2)
// ocz = O(N^2)
// pes = O(N^2)
