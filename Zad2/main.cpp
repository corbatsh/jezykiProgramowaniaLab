#include <iostream>

using namespace std;

int main() {
    int i, j, *k, *l, n;
    float x, *y, *tab1, *tab2;

    k=new int; //dynamiczne przydzielenie pamięci
    cin >> *k; //przypisanie wartosci adresowi na ktory wskazuje k
    l = k; // wskazanie wskaznikowi l takiego samego adresu na jaki wskazuje wskaznik k
    *l = *l + 10; // wskaznik l wskazuje na ten sam adres co wskaznik k, wiec dodanie do tego 10 spowoduje
                    // ze wypisanie obydwoch wskaznikow skutkuje tym samym. One wskazują na ten sam adres
    cout << "*k=" << *k << endl;
    cout << "*l" << *l << endl;

    x=5.5;
    y = &x; // przypisanie adresu zmiennej x do wskaznika y
    cout << "*y=" << *y << endl;

    delete k; // adres zostaje, ale wskazniki nie wskazuja juz na niego, dlatego wypisanie tych wskaznikow skutkuje
                // wypisaniem losowej wartosci
    cout << "po delete *k=" << *k << endl;
    cout << "po delete *l=" << *l << endl;

    cout << "ile elementow? ";
    cin >> n;
    tab1 = new float[n];
    for (i=0; i<n; i++)
        tab1[i] = i;

    for(i=0; i<n; i++)
        cout << *tab1++ << endl;
    /* wypisz wskazywana przez tab1 i po procesie zinkrementuj to co jest zwiazane z inkrementacja
    po procesie zinkrementuj nie adres a tab1 czyli zinkrementuje indeks.
     Po ostatnim wypisie wyjdzie poza adres, wiec powtorne wypisanie wypisze losowa liczbe
    */
    cout << "Kolejny listing:" << endl;
    for (i=0; i<n; i++)
        cout << *tab1++ << endl; // wyjscie poza zakres, bo wyszlo juz wczesniej

        cout << "test";
    return 0;
}
