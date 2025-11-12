#include "COMP_Imprimante.hpp"
#ifndef __IOSTREAM_H
#include <iostream>
#endif

using namespace std;

namespace NS_COMP
{
	COMP_Imprimante::COMP_Imprimante(void)
	{
		cout << "Construction du composant Imprimante" << endl;
	}
	void COMP_Imprimante::imprimer(double* data, int qteFacture)
	{
		int i;

		for (i = 0;i < qteFacture;i++)
		{
			cout << "--------------------------------------------------------------" << "\n";
			cout << "--------------------------FACTURE-----------------------------" << "\n";
			cout << "--------------------------------------------------------------" << "\n";
			cout << "\n";
			cout << "Montant total ht : " << data[0] << "\n";
			cout << "Montant total tva : " << data[1] << "\n";
			cout << "Montant total ttc : " << data[2] << "\n";
			cout << endl;
		}
	}
}
