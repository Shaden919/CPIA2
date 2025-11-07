#include <iostream>
#include "Fraction.hpp"
using namespace std;

int PGCD(int a, int b);

Fraction::Fraction(){
    this->numerateur = 1;
    this->denominateur = 1;
    cout << "Constructeur appelé" << endl;
}
Fraction::Fraction(int numerateur, int denominateur){
    this->numerateur = numerateur;
    this->denominateur = denominateur;
    cout << "Constructeur appelé" << endl;
}
Fraction::~Fraction(){
    cout << "Destructeur appelé" << endl;
}
void Fraction::setNumerateur(int numerateur){
    this->numerateur = numerateur;
}
void Fraction::setDenominateur(int denominateur){
    this->denominateur = denominateur;
}
void Fraction::simplify() {
    int pgcd = PGCD(this->numerateur,this->denominateur);
    this->numerateur = this->numerateur / pgcd;
    this->denominateur = this->denominateur / pgcd;
}
int Fraction::getNumerateur(){
    return numerateur;
}
int Fraction::getDenominateur(){
    return denominateur;
}
Fraction Fraction::add(Fraction fraction) const{
    Fraction tmpFra;

    tmpFra.numerateur = this->numerateur * fraction.denominateur + this->denominateur * fraction.numerateur;
    tmpFra.denominateur = this->denominateur * fraction.denominateur;
    
    return tmpFra;
}
Fraction Fraction::minus(Fraction fraction) const{
    Fraction tmpFra;

    tmpFra.numerateur = this->numerateur * fraction.denominateur - this->denominateur * fraction.numerateur;
    tmpFra.denominateur = this->denominateur * fraction.denominateur;
    
    return tmpFra;
}
Fraction Fraction::multiply(Fraction fraction) const{
    Fraction tmpFra;

    tmpFra.numerateur = this->numerateur * fraction.numerateur;
    tmpFra.denominateur = this->denominateur * fraction.denominateur;
    
    return tmpFra;
}
Fraction Fraction::divide(Fraction fraction){
    Fraction tmpFra;

    tmpFra.numerateur = this->numerateur * fraction.denominateur;
    tmpFra.denominateur = this->denominateur * fraction.numerateur;
    
    return tmpFra;
}

int PGCD(int a, int b) {
    if (b == 0) return a;
    return PGCD(b, a % b);
}