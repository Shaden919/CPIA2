#include <stdio.h>
#include <stdlib.h>


/**/
void SaisieTableau(int *tab, int t) {
    printf("Veuillez saisir les %d nombres:\n", t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &tab[i]);
    }
    printf("\n");
}

void AfficheTableau(int *tab, int t) {
    for (int i = 0; i < t; i++) {
        printf("%d ", *(tab + i));
    }
    printf("\n");
}

void InverseTableau(int * tab,int t) {
    printf("inversement du tableau...\n");
    for (int i = 0;i < (t)/2 ; i++) {
        int tmp = tab[i];
        tab[i] = *(tab + t -1 -i);
        tab[t -1 -i] = tmp;
    }
    printf("le tableau a été inversé!\n");
} 

typedef struct 
{
    char  nom[20];
    float moy[3];
    int age;
} etudiant ;

void calculer_moy_generale(etudiant * x) {
    float moyg;
    float tmp = 0.0;
    for (int i = 0; i < 3;i++) {
        tmp = tmp + x->moy[i];
    }
    moyg = tmp/3.0;
    printf("la moyenne générale de %s est %.2f \n",x->nom,moyg);
    }

void saisir_donnees(etudiant * x) {
    printf("Quelle est son nom :\n");
    scanf("%s",x->nom);
    printf("Quelle est son age :\n");
    scanf("%d",&x->age);
    printf("Quelle est sa moyenne :\n");
    for (int i = 0;i < 3 ; i++) {
        printf("Moyenne %d : ",i+1);
        scanf("%f",&x->moy[i]);
    }
}

void afficher_etudiant(etudiant * x) {
    printf("Nom : %s\n",x->nom);
    printf("Age : %d\n",x->age);
    printf("Moyennes : "); 
    for (int i = 0;i < 3 ; i++) {
        printf("%.2f,",x->moy[i]);
    }
    printf("\n");
    
}

int main() {

    /* int taille;
    printf("Veuillez saisir la taille du tableau: ");
    scanf("%d", &taille);
    int tab[taille];
    SaisieTableau(tab, taille);
    AfficheTableau(tab, taille);
    InverseTableau(tab, taille);
    AfficheTableau(tab, taille); */

    /*etudiant etut1;
    etudiant *p = &etut1;
    saisir_donnees(p);
    afficher_etudiant(p);
    calculer_moy_generale(p);*/

    int nb_etudiants;
    printf("Combien d'étudiants voulez-vous enregistrer ? ");
    scanf("%d", &nb_etudiants);

    // 1. Using calloc to allocate memory for an array of students
    // We use calloc because it initializes the memory to zero, which is safer.
    etudiant *classe = (etudiant*) calloc(nb_etudiants, sizeof(etudiant));

    // Always check if allocation was successful
    if (classe == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1; // Exit with an error code
    }

    printf("\n--- Saisie des données pour %d étudiant(s) ---\n", nb_etudiants);
    for (int i = 0; i < nb_etudiants; i++) {
        printf("\n--- Étudiant %d ---\n", i + 1);
        // We pass the address of the i-th student in the array
        saisir_donnees(&classe[i]); 
    }

    printf("\n--- Affichage des données de la classe ---\n");
    for (int i = 0; i < nb_etudiants; i++) {
        printf("\n--- Étudiant %d ---\n", i + 1);
        afficher_etudiant(&classe[i]);
        calculer_moy_generale(&classe[i]);
    }

    // 2. Using realloc to add more students
    int nb_ajout;
    printf("\nCombien d'étudiants voulez-vous ajouter ? ");
    scanf("%d", &nb_ajout);

    if (nb_ajout > 0) {
        int new_total = nb_etudiants + nb_ajout;
        // It's safer to reallocate into a temporary pointer
        etudiant *temp = (etudiant*) realloc(classe, new_total * sizeof(etudiant));

        if (temp == NULL) {
            printf("Erreur de réallocation mémoire.\n");
            // If realloc fails, the original 'classe' pointer is still valid
            free(classe);
            return 1;
        }
        // If successful, update the main pointer
        classe = temp;

        printf("\n--- Saisie des données pour les %d nouveaux étudiant(s) ---\n", nb_ajout);
        for (int i = nb_etudiants; i < new_total; i++) {
            printf("\n--- Étudiant %d ---\n", i + 1);
            saisir_donnees(&classe[i]);
        }
        nb_etudiants = new_total; // Update the total count
    }

    printf("\n--- Affichage final de toute la classe (%d étudiant(s)) ---\n", nb_etudiants);
    for (int i = 0; i < nb_etudiants; i++) {
        printf("\n--- Étudiant %d ---\n", i + 1);
        afficher_etudiant(&classe[i]);
    }

    // 3. Using free to release the memory
    // This is the most important step to prevent memory leaks!
    printf("\nLibération de la mémoire...\n");
    free(classe);
    classe = NULL; // Good practice to avoid using a dangling pointer

    return 0;

}