#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
int64_t silnia(__int64_t);
int main() {
    cout << silnia(5);
    return 0;
}


__int64_t silnia(__int64_t n)
{
    __int64_t si = 1;
    for (; n > 1; n--)
        si *= n;
    return si;
}
