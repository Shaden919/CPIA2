#include "CLpoint.hpp"
#include "CLpoint3D.hpp"
#include "parcour.hpp"
#include "parcour2D.hpp"
#include "parcour3D.hpp"
#include <iostream>
using namespace std;

int main()
{
    int pause;

    CLpoint* p1;
    CLpoint* p2;
    CLpoint* p3;
    Parcour* parcours;

    p1 = new CLpoint(0.0, 0.0);
    p2 = new CLpoint(1.0, 1.0);
    p3 = new CLpoint(2.0, 2.0);
    parcours = new Parcour2D(3);

    parcours->ajouterPoint(p1);
    parcours->ajouterPoint(p2);
    parcours->ajouterPoint(p3);

    cout << parcours->calculDistance() << endl;
    parcours->message();

    p1 = new CLpoint3D(0.0, 0.0, 0.0);
    p2 = new CLpoint3D(1.0, 1.0, 1.0);
    p3 = new CLpoint3D(2.0, 2.0, 2.2);
    parcours = new Parcour3D(3);

    parcours->ajouterPoint(p1);
    parcours->ajouterPoint(p2);
    parcours->ajouterPoint(p3);

    cout << parcours->calculDistance() << endl;
    parcours->message();

    p1 = new CLpoint(0.0,0.0);
    p2 = new CLpoint3D(1.0, 1.0, 1.0);

    (p1 = p2)->afficherCoordo();

    cin >> pause;
    return 0;
}