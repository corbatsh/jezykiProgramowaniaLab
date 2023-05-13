#include <iostream>
#define N 4
using namespace std;

struct date
{
    int dzien;
    int mies;
    int rok;
};

struct towar
{
    char nazwa[20];
    float cena;
    int sztuk;
    date dataprod;
};

int main() {
    towar magazyn[N], x;
    int i, licznik;
    float cena_min, cena_max;
    cout << "Program testuje wyszukiwanie w tablicy struktur rekordowych" << endl;

    for (i = 0; i<N; i++)
    {
        cout << endl << "Podaj element nr " << i << " : " << endl;
        cout << "Nazwa: ";
        gets(magazyn[i].nazwa);
        cout << "Cena: ";
        cin >> magazyn[i].cena;
        cout << "Sztuk: ";
        cin >> magazyn[i].sztuk;
        getchar();
    }

    cout << endl << "Podaj szukany zakres cen. Dolna wartosc ceny: ";
    cin >> cena_min;
    cout << "Gorna wartosc ceny: ";
    cin >>cena_max;

    licznik = 0;
    for (i = 0; i < N; i++)
    {
        if(magazyn[i].cena >= cena_min && magazyn[i].cena <= cena_max)
        {
            cout << "Znalazlem pod indeksem " << i << " towar: " << magazyn[i].nazwa << " z cena" << magazyn[i].cena;
            licznik++;
        }
    }

    return 0;
}
