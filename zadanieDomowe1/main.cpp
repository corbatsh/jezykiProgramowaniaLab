#include <iostream>

using namespace std;
int main() {
    /*
     * Zadanie domowe:
     * Zakładając istnienie n-elementowej tablicy z danymi, wczytać wartość szukaną i jednokrotnym komunikatem
     * stwierdzić czy szukana występuje w tablicy czy nie.
     */
    cout << "Zadanie domowe" << endl << endl;
    int n = 10, szukana, *tablica;
    bool znaleziono = false;
    tablica = new int [n];
    cout << "wprowadz liczbe szukana z zakresu 0-9" << endl;
    cin >> szukana;

    for (int i = 0; i < n; i++)
    {
        *tablica = i;
        if(*tablica == szukana)
        {
            cout << endl << "znaleziono szukana pod indeksem [" << i << "]" << endl;
            znaleziono = true;
        }
        tablica++;
    }

    if (!znaleziono)
        cout << "nie znaleziono szukanej";

    return 0;
}
