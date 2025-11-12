#include "COMP_Calcul.hpp"
#include <iostream>

using namespace std;

namespace NS_COMP
{
	COMP_Calcul::COMP_Calcul(double puht, double tva, double qtArticle)
	{
		cout << "Construction du composant Calcul" << endl;
		this->puht = puht;
		this->tva = tva;
		this->qteArticle = qtArticle;
	}
	double* COMP_Calcul::calculer(void)
	{
		double ptttc;
		double montantTVA;
		double ptht;
		double* data;

		ptht = this->qteArticle * this->puht;
		montantTVA = (ptht * this->tva) / 100;
		ptttc = montantTVA + ptht;

		data = new double[3];
		data[0] = ptht;
		data[1] = montantTVA;
		data[2] = ptttc;

		return data;
	}
}