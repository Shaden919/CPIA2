#include "SVC_Facture.hpp"
#ifndef __IOSTREAM_H
#include <iostream>
#endif

using namespace std;

NS_SVC::SVC_Facture::SVC_Facture(void)
{
	cout << "Construction du service Facture" << endl;
	this->Ocalcul = NULL;
	this->oImprimante = NULL;
}

void NS_SVC::SVC_Facture::calculer_et_editer_facture(double puht, double tva, double nbArticle, int qteFacture)
{
	double* data;

	this->Ocalcul = new	NS_COMP::COMP_Calcul(puht, tva, nbArticle);
	this->oImprimante = new	NS_COMP::COMP_Imprimante();

	data = this->Ocalcul->calculer();
	this->oImprimante->imprimer(data, qteFacture);

	delete data;
	delete this->Ocalcul;
	delete this->oImprimante;
}
