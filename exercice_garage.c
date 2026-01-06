#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Définition de la Structure et de l'alias avec typedef
typedef struct StructVehicule {
    char type[30];    // ex: voiture, moto
    char marque[30];
    char modele[30];
    int annee;
} Vehicule;

// 2. Fonction de Saisie (utilise un pointeur vers Vehicule)
void saisirVehicule(Vehicule *v) {
    printf("\n--- Saisie du véhicule ---\n");
    printf("Type (voiture/moto/etc.) : ");
    scanf("%s", v->type);
    printf("Marque : ");
    scanf("%s", v->marque);
    printf("Modèle : ");
    scanf("%s", v->modele);
    printf("Année de fabrication : ");
    scanf("%d", &v->annee);
}

// 3. Fonction d'Affichage (prend un Vehicule par valeur)
void afficherVehicule(Vehicule v) {
    printf("\n[Véhicule] %d %s %s (%s)", 
           v.annee, v.marque, v.modele, v.type);
}

// 4. Programme Principal
int main() {
    int nbVehicules;

    printf("Combien de véhicules souhaitez-vous entrer dans le garage ? ");
    scanf("%d", &nbVehicules);

    // Déclaration du tableau de Vehicule (allocation dynamique)
    Vehicule* garage = (Vehicule*)malloc(nbVehicules * sizeof(Vehicule));

    if (garage == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    // Boucle de saisie utilisant la fonction par adresse
    for (int i = 0; i < nbVehicules; i++) {
        printf("\nVéhicule n°%d", i + 1);
        saisirVehicule(&garage[i]); // Passage de l'adresse
    }

    // Boucle d'affichage utilisant la fonction par valeur
    printf("\n\n--- Inventaire du Garage ---");
    for (int i = 0; i < nbVehicules; i++) {
        afficherVehicule(garage[i]); // Passage de la valeur
    }

    // Libération de la mémoire
    free(garage);
    printf("\n\nProgramme terminé.\n");

    return 0;
}
