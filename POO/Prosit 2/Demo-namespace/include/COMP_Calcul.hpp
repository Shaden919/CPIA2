#pragma once
namespace NS_COMP
{
	class COMP_Calcul
	{
	private:
		double puht;
		double tva;
		double qteArticle;
	public:
		COMP_Calcul(double, double, double);
		double* calculer(void);
	};
}