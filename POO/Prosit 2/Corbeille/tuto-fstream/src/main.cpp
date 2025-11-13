#include <iostream>
#include <fstream>
#include <string>
#include <limits>  // pour utiliser numeric_limits<int>::max()
 
using namespace std;
 
int main()
{
        string toto = "toto.txt";
        ifstream fichier_toto(toto.c_str(), ios::in);
        
        if(fichier_toto.fail())
                cout << "Le fichier " << toto << " n'existe pas !" << endl;
 
        ifstream fichier("test.txt", ios::in);
 
        if(!fichier.fail())
        {
                cout << "Le fichier test.txt existe bien et est correctement ouvert !" << endl;
                cout << "A l'ouverture du fichier, le curseur de trouve a l'octet " << fichier.tellg() << "." << endl << endl;
                cout << "Le fichier contient : " << endl << endl;
 
                string ligne;
                while(getline(fichier, ligne))
                        cout << ligne << endl;
 
                cout << endl << "Une fois tout le fichier lu, le \"eofbit\" est passe a "  << boolalpha << fichier.eof() << "." << endl;
/* boolalpha sert à afficher en toutes lettres un booléen */
                
                cout << endl << "Pour revenir au debut du fichier, on peut tenter un \"fichier.seekg(0, ios::beg\". Est-ce que ca a fonctionne ?" << endl;
                
                fichier.seekg(0, ios::beg);
 
                cout << endl << "On se trouve au " << fichier.tellg() << "ieme octet." << endl;
 
                if((int)fichier.tellg() != 0)
                {
                        cout << "Oh non, ca n'a pas fonctionne ! Je vais tenter de faire un \"fichier.clear()\"." << endl;
                        fichier.clear();
                        fichier.seekg(0, ios::beg);
                        cout << endl << "On se trouve au " << fichier.tellg() << "ieme octet." << endl;
                }
 
                int nbLignes = 0;
                while(fichier.ignore(numeric_limits<int>::max(), '\n'))
                        nbLignes++;
 
                cout << "Le fichier contient " << nbLignes << " lignes." << endl;
 
                cout << "Comme on a parcouru a nouveau le fichier, le \"eofbit\" est passe a " << boolalpha << fichier.eof() << "." << endl;
 
                fichier.close();        
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
        return 0;
}