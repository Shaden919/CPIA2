#include "CLobjet.hpp"
#include "iostream"
using namespace std;


CLobjet::CLobjet(float masse = 10, float vitesse = 5)
{
    if (masse <= 0 || vitesse <= 0)
    {
        cout << "La masse et la vitesse ne peuvent être null" << endl;
        return;
    }
    *m_masse = masse;
    *m_vitesse = vitesse;
    *m_energieC = 0.5 * (*m_masse) * (*m_vitesse) * (*m_vitesse);
}

CLobjet::~CLobjet()
{
    delete[] m_masse;
    delete[] m_vitesse;
    delete[] m_energieC;
}

float CLobjet::masse(float masse) {
    if (masse <= 0)
    {
        cout << "La masse ne peut être null ou negatif" << endl;
        return 0.0;
    }
    
    *m_masse = masse;
}

float CLobjet::vitesse(float vitesse) {
    if (vitesse <= 0)
    {
        cout << "La vitesse ne peut être null ou negatif" << endl;
        return 0.0;
    }
    *m_vitesse = vitesse;
}

float CLobjet::energieC() const {
    return *m_energieC;
}

void CLobjet::calculer() {
    *m_energieC = 0.5 * (*m_masse) * (*m_vitesse) * (*m_vitesse) ;
}

