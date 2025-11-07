#include <stdio.h>
#if !defined(DEF_LISTDATA)
#define DEF_LISTDATA


class ListData
{
private:
    float m_list[1024];
    int m_size;
public:
    ListData();
    ~ListData();
    void AddData(int value);//ajouter des données 
    void PrintData() const;
    float SomData() const;//Calcul de la somme des donnée
    float MoyData() const;//Calcul de la moyenne des données
    float MinData() const,MaxData() const; //Calcul de la valeur minimum & maximum contenue dans les données
    float VariationMax() const;//Connaitre l'espace de variation max entre les données
};

#endif // DEF_LISTDATA
 