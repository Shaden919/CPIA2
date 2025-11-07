#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Définition de la structure d’un article
typedef struct {
    long ref;
    float prix;
    long quant;
    char designation[20];
} typeArticle;

// Tableau de pointeurs vers les articles
typeArticle *stock[MAX];
int NbArticles = 0; // nombre d’articles existants

// Prototypes
void afficheArticle(typeArticle *a);
int rechercher(long r, typeArticle *t[], int nb);
void modifier(typeArticle *a);
void ajouterPlusieurs(); // nouvelle fonction

int main() {
    int n;
    long reference;

    do {
        printf("\n-------------------- MENU -------------------------\n");
        printf("0 : Quitter l'application\n");
        printf("1 : Ajouter plusieurs articles\n");
        printf("2 : Afficher tout le stock\n");
        printf("3 : Modifier la quantité d’un article\n");
        printf("---------------------------------------------------\n");
        printf("Votre choix : ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                ajouterPlusieurs();
                break;

            case 2:
                if (NbArticles == 0) {
                    printf("Aucun article dans le stock.\n");
                    break;
                }
                for (int k = 0; k < NbArticles; k++)
                    afficheArticle(stock[k]);
                break;

            case 3:
                printf("Donner la référence de l'article à modifier : ");
                scanf("%ld", &reference);
                int k = rechercher(reference, stock, NbArticles);
                if (k < 0)
                    printf("Article non trouvé.\n");
                else
                    modifier(stock[k]);
                break;

            case 0:
                printf("Fermeture du programme...\n");
                break;

            default:
                printf("Choix invalide !\n");
        }
    } while (n != 0);

    return 0;
}

// Fonction pour ajouter plusieurs articles avec calloc
void ajouterPlusieurs() {
    int n;
    printf("Combien d’articles voulez-vous ajouter ? ");
    scanf("%d", &n);

    // Vérifie qu’on ne dépasse pas la taille maximale du stock
    if (NbArticles + n > MAX) {
        printf("Trop d’articles. Capacité maximale atteinte.\n");
        return;
    }

    // Allocation mémoire d’un bloc de n articles, initialisé à zéro
    typeArticle *nouveaux = (typeArticle*)calloc(n, sizeof(typeArticle));
    if (!nouveaux) {
        printf("Erreur d’allocation mémoire !\n");
        exit(1);
    }

    // Lecture des articles un par un
    for (int i = 0; i < n; i++) {
        printf("\n=== Article %d ===\n", i + 1);
        printf("Référence : ");
        scanf("%ld", &nouveaux[i].ref);
        printf("Désignation : ");
        scanf("%s", nouveaux[i].designation);
        printf("Prix : ");
        scanf("%f", &nouveaux[i].prix);
        printf("Quantité : ");
        scanf("%ld", &nouveaux[i].quant);

        // Ajout de l’adresse de chaque article dans le tableau principal
        stock[NbArticles++] = &nouveaux[i];
    }

    printf("\n%d article(s) ajouté(s) avec succès.\n", n);
    //  On ne fait pas de "free(nouveaux)" ici, car les pointeurs
    // dans stock pointent encore vers cette mémoire.
}

//  Afficher un article
void afficheArticle(typeArticle *a) {
    printf("\nRéférence : %ld\n", a->ref);
    printf("Désignation : %s\n", a->designation);
    printf("Prix : %.2f\n", a->prix);
    printf("Quantité : %ld\n", a->quant);
    printf("-----------------------------------\n");
}

// Rechercher un article par sa référence
int rechercher(long r, typeArticle *t[], int nb) {
    for (int i = 0; i < nb; i++) {
        if (t[i]->ref == r)
            return i;
    }
    return -1;
}

//  Modifier la quantité d’un article
void modifier(typeArticle *a) {
    long nouvQuant;
    printf("Quantité actuelle : %ld\n", a->quant);
    printf("Nouvelle quantité : ");
    scanf("%ld", &nouvQuant);
    a->quant = nouvQuant;
    if (nouvQuant == 0) {
        printf("Article supprimé.\n");
        stock[rechercher(a->ref, stock, NbArticles)] = NULL; // Définit la référence à NULL
        NbArticles--; // Diminue le nombre d'articles
    }
    printf(" Quantité mise à jour avec succès.\n");
}
