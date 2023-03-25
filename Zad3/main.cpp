#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 10 //tymczasowe
using namespace std;

int main() {
    int t[N]; //będą zmiany na float
    int i, szukana, min, ind; //inne zmienne w miarę potrzeby
    bool znaleziono;

    cout << "Program testuje algorytm ............" << endl;

    //poniżej generowanie danych
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        //cout << "t[" << i << "]=";
        //cin >> t[i];
        //t[i] = rand() % 32700;

        //t[i]=i;
          t[i]=-i;
        //  t[i]=5;
        //cout << "tpyrka[" << i << "]=" << t[i] << endl;
    }

    //poniżej testowany algorytm

    //cout << "podaj szukana: ";
    //cin >> szukana;
    //znaleziono = false;
    //i = 0;
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
//    do
//    {
//        if (t[i] == szukana)
//            i = N; // jesli znajdzie to zmieni wartosc i na N, czyli wypisze ze znajdzie
//        i++; // doda jeden na ostatnim indexie przez co wyjdzie za zakres i bedzie 11, wypisze ze nie ma
//    } while (i < N);
//    if(i == N)
//        cout << "Nie ma";
//    else
//        cout << "Jest";

//Jest tablica z danymi, trzeba wyszukac wartosc najmniejsza i wypisać ją wraz z indeksem
//zakładamy, że elementy się nie powtarzają
//    i = 0;
//    min = t[i];
//    ind = i;
//    do
//    {
//      i++;
//        if (t[i] < min)
//        {
//            min = t[i];
//            ind = i;
//        }
//    } while (i < N);

//    min = t[0];
//    for (i = 1; i < N; i++) // optymistyczny wariant bedzie taki, że 1 liczba będzie najmniejsza O(N)
//    {                       // pesymistyczny wariant to taki, że będzie to ciąg malejący O(N)
//        if(min > t[i])      // oczekiwany wariant to taki, że O(N)
//        {
//            min = t[i];
//            ind = i;
//        }
//    }
//    cout << "Najmniejszy element to " << min << " z indeksem " << ind;

    for (int nr = 1; nr < N; nr++)
    {
        ind = nr;
        min = nr;
        for (i = nr+1; i < N; i++) {
            if (min > t[i]) {
                min = t[i];
                ind = i;
            }
        }
        t[ind] = t[nr];
        t[nr] = min;
    }

    for (int i = 1; i < N-1; i++)
    {
        cout << t[i] << endl;
    }

    /*
     * Do powyzszego zadania mamy zlozonosci obliczeniowe:
     * opt: O(N^2)
     * ocz: O(N^2)
     * pes: O(N^2)
     * Ta metoda ma bardzo małe odchyłki między optymistycznym a pesymistycznym
     */

    //Z.D zadanie jak wyzej - jest czy nie ma, ale wiemy, że tablica jest posortowana rosnąco.
    //koniec algorytmu

    /*
     * 1 indeks tablicy to lewa strona, ostatni indeks to prawa strona.
     * brac srednia z tego i na tej podstawie wyliczamy srodkowy indeks, przy okazji
     * sprawdzamy czy szukana jest rowna srodkowemu. Jesli jest wiekszy to indeks przesuwamy w prawo
     * jesli jest mniejszy to przesuwamy w lewo. W przedbiegach można sprawdzić czy szukana jest mniejsza niz 1 indeks
     * lub czy jest wieksza niz ostatni indeks
     */

    /*
     * ZD:
     * Zakładając, że elementy mogą się powtarzać, wyszukaj i wypisz wartość najmniejszą wraz z indeksami, pod
     * którymi występuje i analogicznie największą z indeksami.
     */
    //tu ewentualnie wyniki, komunikaty...

    return 0;
}