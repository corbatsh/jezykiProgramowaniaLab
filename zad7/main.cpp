#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void losuj_tab(int tablica[], int rozmiar);
void czytaj_tab(int tablica[], int rozmiar);
void wypisz_tab(int tablica[], int rozmiar);
float suma_tab(int tablica[], int rozmiar);
float srednia_tab(int tablica[], int rozmiar);
void sumasrednia_tab(int tablica[], int rozmiar, int &suma, float &srednia);

bool czyJest (int tablica[], int n, int szukana);
int minimum (int t[], int n);
void minMax1 (int t[], int n, int &min, int &max);
void minMax2 (int t[], int n, int *min, int *max);
void selectionSort (int t[], int n);
int szukaj (int t[], int n, int a, int b, int znalezione[]);

int main() {
    return 0;
}

void losuj_tab(int tablica[], int rozmiar)
{

}
void czytaj_tab(int tablica[], int rozmiar)
{

}
void wypisz_tab(int tablica[], int rozmiar)
{

}
float suma_tab(int tablica[], int rozmiar)
{

}
float srednia_tab(int tablica[], int rozmiar)
{

}
void sumasrednia_tab(int tablica[], int rozmiar, int &suma, float &srednia)
{

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