#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nom[10];
    int pin;
    float mesures[10];
    int erreurs[10];
    float moy_inst;
} capteur;

int nb_capteurs = 1;

int main() {
    int n;
    capteur * capteurs = calloc(nb_capteurs, sizeof(capteur));
    strcpy(capteurs[0].nom, "Humidite");
    capteurs[0].pin = 1;
    if (capteurs == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }
    do
    {
        printf("\n-------------------- MENU -------------------------\n");
        printf("0 : Quitter l'application\n");
        printf("1 : Ajouter un ou plusieurs capteurs\n");
        printf("2 : Afficher les dernière mesures\n");
        printf("3 : Afficher tous les capteurs\n");
        printf("---------------------------------------------------\n");
        printf("Votre choix : ");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            printf("Fermeture du programme...\n");
            break;
        case 1:
            int nb_ajouts;
            printf("Combien de capteurs voulez-vous ajouter? ");
            scanf("%d", &nb_ajouts);
            capteur * tmp = realloc(capteurs, (nb_ajouts));
            if (tmp == NULL) {
                printf("Erreur d'allocation mémoire.\n");
                return 1;
            }
            capteurs = tmp;
            for (int i = nb_capteurs; i < nb_ajouts; i++) {
                printf("%i", nb_capteurs); 
                printf("%i", nb_ajouts);
                printf("\n--- Ajout du capteur %d ---\n", i + 1);
                printf("Fonction : ");
                scanf("%s", capteurs[i].nom);
                printf("PIN : ");
                scanf("%d", &capteurs[i].pin);
            }
            nb_capteurs += nb_ajouts;
            break;
        case 2:
            for (int i = 0; i < 10; i++) {
                if (capteurs[i].nom[0]!= '\0') {
                    printf("\n--- Mesures du capteur %s ---\n", capteurs[i].nom);
                    for (int j = 0; j < 10; j++) {
                        printf("Mesure %d : %.2f ", j + 1, capteurs[i].mesures[j]);
                        if (capteurs[i].erreurs[j] == 1) {
                            printf("(erreur)\n");
                        } else {
                            printf("\n");
                        }
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < nb_capteurs; i++) {
                printf("\n--- Capteur %d ---\n", i + 1);
                printf("Nom : %s\n", capteurs[i].nom);
                printf("PIN : %d\n", capteurs[i].pin);
                printf("Moyenne instantanée : %.2f\n", capteurs[i].moy_inst);
                printf("Mesures :\n");
                for (int j = 0; j < 10; j++) {
                    printf("Mesure %d : %.2f ", j + 1, capteurs[i].mesures[j]);
                    if (capteurs[i].erreurs[j] == 1) {
                        printf("(erreur)\n");
                    } else {
                        printf("\n");
                    }
                }
                printf("Erreurs :\n");
            }
        default:
        printf("choix invalide!\n");
            break;
        }
    } while (n != 0);
    
}