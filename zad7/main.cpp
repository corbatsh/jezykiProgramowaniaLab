#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void losuj_tab(int tablica[], int rozmiar);
void czytaj_tab(int tablica[], int rozmiar);
void wypisz_tab(int tablica[], int rozmiar);
int suma_tab(int tablica[], int rozmiar);
float srednia_tab(int tablica[], int rozmiar);
void sumasrednia_tab(int tablica[], int rozmiar, int &suma, float &srednia);

bool czyJest (int tablica[], int n, int szukana);
int minimum (int t[], int n);
void minMax1 (int t[], int n, int &min, int &max);
void minMax2 (int t[], int n, int *min, int *max);
void selectionSort (int t[], int n);
int szukaj (int t[], int n, int a, int b, int znalezione[]);

int main() {
    int i, szukana, n, *t, *znal, maksim, minim, a, b, ile, su;
    float sr;
    char znak;
    cout << "TEST FUNKCJIN TABLICOWYCH" << endl << endl;
    cout << "Ile elementow? ";
    cin >> n;
    t = new int[n+1]; //dane w tablicy od ind. 1 do n
    znal = new int[n+1];
    do {
       cout << endl << endl << "NACISNIJ ENTER" << endl;
       cout << "1. LOSOWANIE TABLICY" << endl;
       cout << "2. CZYTANIE TABLICY Z KLAWIATURY" << endl;
       cout << "3. WYPISANIE ELEMENTOW TABLICY" << endl;
       cout << "4. SUMA ELEMENTOW TABLICY" << endl;
       cout << "5. SREDNIA ELEMENTOW TABLICY" << endl;
       cout << "6. SUMA I SREDNIA ELEMENTOW TABLICY 2 w 1" << endl;
       cout << "7. WARTOSC MINIMALNA Z TABLICY" << endl;
       cout << "8. MINIMUM I MAKSIMUM" << endl;
       cout << "9. WYSZUKIWANIE PRZEDZIALU WARTOSCI W TABLICY" << endl;
       cout << "c. SPRAWDZENIE CZY SZUKANA ISTNIEJE W TABLICY" << endl;
       cout << "s. SORTOWANIE ROSNACE - PROSTE WYBIERANIE" << endl;
       cout << "0. KONIEC PRACY" << endl;
       cin >> znak;
        getchar();
       switch (znak)
       {
           case '1':
               losuj_tab(t, n);
               cout << endl << "WYLOSOWALEM" << endl;
               break;
           case '2':
               cout << endl;
               czytaj_tab(t, n);
               cout << endl << "WCZYTALEM" << endl;
               break;
           case '3':
               wypisz_tab(t, n);
               break;
           case '4':
               cout << endl << "Suma elementow= " << suma_tab(t, n) << endl;
               break;
           case '5':
               cout << "Srednia elementow " << endl << srednia_tab(t, n) << endl << endl;
               break;
           case '6':
               sumasrednia_tab(t, n, su, sr);
               cout << "Suma elementow= " << su << "   Srednia elementow= " << sr << endl;
               break;
           case '7':
               cout << "Wartosc minimalna to " << minimum(t, n) << endl;
               break;
           case '8':
               minMax1(t, n, minim, maksim);
               cout << "Wywolano fun. minMax1" << endl;
               cout << "min= " << minim << "    max= " << maksim << endl;
               break;
           case '9':
               cout << "Podaj szukany przedzial <a, b>, a: ";
               cin >> a;
               cout << "b: ";
               cin >> b;
               if (ile == szukaj(t, n, a, b, znal))
               {
                   cout << "znaleziono " << ile << "elementow" << endl;
                   for (i = 1; i <= ile; i++)
                       cout << znal[i] << endl;
               }
               else
                   cout << "Brak znalezionych" << endl;
               getchar();
               break;
           case 'c':
               cout << "Podaj szukana wartosc: " << endl;
               cin >> szukana;
               if (czyJest(t, n, szukana))
                   cout << "Znalazlem" << endl;
               else
                   cout << "Nie znalazlem szukanej" << endl;
               getchar();
               break;
           case 's':
               selectionSort(t, n);
               cout << "Posortowano" << endl;
               break;
           case '0':
               cout << "DO WIDZENIA" << endl;
               break;
           default:
               cout << "ZLY WYBOR!" << endl;
       }
        getchar();
    } while (znak != '0');
    cout << endl << "NACISNIJ KLAWISZ BY ZAKONCZYC" << endl;
    return 0;
}

void losuj_tab(int tablica[], int rozmiar)
{
    srand(time(NULL));
    for (int i = 1; i <= rozmiar; i++)
        tablica[i] = rand() % 1001;
}
void czytaj_tab(int tablica[], int rozmiar)
{
    for (int i = 1; i <= rozmiar; i++)
    {
        cout << "Podaj " << i << " liczbe" << endl;
        cin >> tablica[i];
    }
    getchar();
}
void wypisz_tab(int tablica[], int rozmiar)
{
    for (int i = 1; i <= rozmiar; i++)
    {
        cout << i << ": " << tablica[i] << endl;
    }
}
int suma_tab(int tablica[], int rozmiar)
{
    int suma = 0;
    for (int i = 1; i <= rozmiar; i++)
    {
        suma += tablica[i];
    }
    return suma;
}
float srednia_tab(int tablica[], int rozmiar)
{
    int suma = 0;
    float srednia;
    for (int i = 1; i <= rozmiar; i++)
    {
        suma += tablica[i];
    }
    srednia = suma / rozmiar;
    return srednia;
}
void sumasrednia_tab(int tablica[], int rozmiar, int &suma, float &srednia)
{
    for (int i = 1; i <= rozmiar; i++)
    {

    }
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