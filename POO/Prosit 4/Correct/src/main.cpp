#include <iostream>
#include <cmath>
using namespace std;



//-------------------------------------------------------
class CLpoint {
private:
double _x;
double _y;
double _z;
static int _cpte;
int _id;
void ini_obj(double, double);
protected:
char typePoint;
public:
CLpoint(void);
CLpoint(double, double);
virtual void afficherCoordo(void);
double getX(void);
double getY(void);
double getZ(void);
void setX(double);
void setY(double);
void setZ(double);
int getID(void);
};
//-------------------------------------------------------
class CLpoint3D : public CLpoint {
private:
void ini_obj(double);
public:
CLpoint3D(void);
CLpoint3D(double, double, double);
void afficherCoordo(void);
};
//-------------------------------------------------------
class CLParcours {
protected:
CLpoint* parcours;
int taille;
int index;
double distance;
public:
CLParcours(int);
void ajouterPoint(CLpoint*);
virtual double calculDistance(void) = 0;
virtual void message(void) = 0;
};
class CLparcours2D : public CLParcours {
public:
CLparcours2D(int);
void message(void);
double calculDistance(void);
};
class CLparcours3D : public CLParcours
{
public:
CLparcours3D(int);
double calculDistance(void);
void message(void);
};
//------------------------------------------------------
int CLpoint::_cpte = 0;
CLpoint::CLpoint(void)
{
this->ini_obj(0.0, 0.0);
}
CLpoint::CLpoint(double _x, double _y)
{
this->ini_obj(_x, _y);
}
void CLpoint::ini_obj(double _x, double _y)
{
this->setX(_x);
this->setY(_y);
this->setZ(0.0);
CLpoint::_cpte++;
this->_id = CLpoint::_cpte;
this->typePoint = '1';
}
void CLpoint::afficherCoordo(void)
{
cout << "\nLes coordonnees du point : " << this << ", d'ID : " << this->getID() << " et de type : " << this->typePoint << ", sont ("
<< this->getX() << ":" << this->getY() << ")";
}
int CLpoint::getID(void){return this->_id;}
double CLpoint::getX(void){return this->_x;}
double CLpoint::getY(void){return this->_y;}
double CLpoint::getZ(void){return this->_z;}
void CLpoint::setX(double _x) { if (_x < 0) { this->_x = 0.0; } else { this->_x = _x; } }
void CLpoint::setY(double _y) { if (_y < 0) { this->_y = 0.0; } else { this->_y = _y; } }
void CLpoint::setZ(double _z) { if (_y < 0) { this->_z = 0.0; } else { this->_z = _z; } }
//-----------------------------------------------------
CLpoint3D::CLpoint3D(void)
{
this->ini_obj(0.0);
}
CLpoint3D::CLpoint3D(double _x, double _y, double _z) : CLpoint(_x, _y)
{
this->ini_obj(_z);
}
void CLpoint3D::ini_obj(double _z)
{
this->setZ(_z);
this->typePoint = '2';
}
void CLpoint3D::afficherCoordo(void)
{
CLpoint::afficherCoordo();
cout << "(" << this->getZ() << ")"<< endl;
}
//-----------------------------------------------------
CLParcours::CLParcours(int taille)
{
this->taille = taille;
this->index = 0;
this->parcours = new CLpoint[this->taille];
this->distance = 0.0;
}
void CLParcours::ajouterPoint(CLpoint* point)
{
this->parcours[this->index] = *point;
this->index++;
}
CLparcours2D::CLparcours2D(int taille) : CLParcours(taille){}
double CLparcours2D::calculDistance(void)
{
int i;
for (i = 0; i < CLParcours::taille - 1; i++)
{
CLParcours::distance += sqrt(pow(CLParcours::parcours[1].getX() - CLParcours::parcours[0].getX(), 2) +
pow(CLParcours::parcours[1].getY() - CLParcours::parcours[0].getY(), 2));
}
return CLParcours::distance;
}
void CLparcours2D::message(void)
{
cout << "Calcul d'un parcours de type 2D" << endl;
}
CLparcours3D::CLparcours3D(int taille) : CLParcours(taille) {}
double CLparcours3D::calculDistance(void)
{
int i;
for (i = 0; i < CLParcours::taille - 1; i++)
{
CLParcours::distance += sqrt(pow(CLParcours::parcours[1].getX() - CLParcours::parcours[0].getX(), 2) +
pow(CLParcours::parcours[1].getY() - CLParcours::parcours[0].getY(), 2) + pow(CLParcours::parcours[1].getZ() -
CLParcours::parcours[0].getZ(), 2));
}
return CLParcours::distance;
}
void CLparcours3D::message(void)
{
cout << "Calcul d'un parcours de type 3D" << endl;
}
//-------------------------------------------------------
int main()
{
CLpoint* p1;
CLpoint* p2;
CLpoint* p3;
CLParcours* parcours;
p1 = new CLpoint(0.0, 0.0);
p2 = new CLpoint(1.0, 1.0);
p3 = new CLpoint(2.0, 2.0);
parcours = new CLparcours2D(3);
parcours->ajouterPoint(p1);
parcours->ajouterPoint(p2);
parcours->ajouterPoint(p3);
cout << parcours->calculDistance() << endl;
parcours->message();
p1 = new CLpoint3D(0.0, 0.0, 0.0);
p2 = new CLpoint3D(1.0, 1.0, 1.0);
p3 = new CLpoint3D(2.0, 2.0, 2.2);
parcours = new CLparcours3D(3);
parcours->ajouterPoint(p1);
parcours->ajouterPoint(p2);
parcours->ajouterPoint(p3);
cout << parcours->calculDistance() << endl;
parcours->message();
p1 = new CLpoint(0.0,0.0);
p2 = new CLpoint3D(1.0, 1.0, 1.0);
(p1 = p2)->afficherCoordo();
return 0;
}