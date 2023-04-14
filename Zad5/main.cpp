#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
int64_t silnia (__int64_t n);
long double silnia(int n);
int64_t silnia2 (__int64_t n, int &error);
int64_t silnia3 (__int64_t n, int *error);
float newton (__int64_t n, __int64_t k);
int main() {
    int error;
    __int64_t n, sil;
    cout << "Liczymy silnie. Podaj n= ";
    cin >> n;
    sil = silnia2(n, error);
    if (error == 0)
        cout << "silnia wynosi: " << sil << endl;
    else
        if (error == 1)
            cout << "n nie moze byc mniejsze niz 1!";
        else
            cout << "n nie moze byc wieksze niz 20!";
    return 0;
}


__int64_t silnia (__int64_t n)
{
    __int64_t si = 1;
    for (; n > 1; n--)
        si *= n;
    return si;
}

long double silnia (int n)
{
    __int64_t si = 1;
    for (; n > 1; n--)
        si *= n;
    return si;
}

__int64_t silnia2 (__int64_t n, int &error)
{
    __int64_t si;
    if (n < 0)
        error = 1;
    else
        if (n > 20)
            error = 2;
        else
        {
            error = 0;
            for (si = 1; n > 1; n--)
                si*=n;
        }
    return si;
}

__int64_t silnia3 (__int64_t n, int *error)
{
    __int64_t si;
    if (n < 0)
        *error = 1;
    else
    if (n > 20)
        *error = 2;
    else
    {
        *error = 0;
        for (si = 1; n > 1; n--)
            si*=n;
    }
    return si;
}

float newton (__int64_t n, __int64_t k, int &error)
{
    float newt;
    int kod = 0;
    if (n < 0)
        error = 1;
    else
        if (n > 20)
            error = 2;
        if (k < 0)
            error += 10;
        else
            if (k > 20)
                error += 20;
            newt = silnia2(n, kod)/(silnia2(k, kod) * silnia2(n-k, kod));
    return newt;
}
