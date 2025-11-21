#include "instrument.hpp"
#include "saxophone.hpp"
#include "piano.hpp"
#include <iostream>
using namespace std;

int main() {
    Instrument* I;
    int i = 0;
    while (i = 0)
    {
        cout << "quel instrument jouer ? Saxophone(1)/Piano(2)\n";
        cin >> i;
    }
    switch (i)
    {
    case 1:
        I = new Saxophone;
        break;
    case 2:
        I = new Piano;
        break;
    }
    I->jouer();

    return 0;
}