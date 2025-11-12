#include <iostream>
#include "SVC_Facture.hpp"

using namespace std;
using namespace NS_SVC;

int main()
{
	NS_SVC::SVC_Facture facture;

	facture.calculer_et_editer_facture(100.00, 10.00, 2 , 3);
	
	cout << "end" << endl;
}