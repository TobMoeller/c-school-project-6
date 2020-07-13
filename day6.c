

#include <stdio.h>
#include <stdlib.h>

void day6() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Saftladen\n"
           "Option (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: saftLaden(); day6(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day6(); break;
    }
}

void saftLaden() {
    float apfelNetto = 0.3, birneNetto = 0.25, apfelsaftNetto = 1.03, birnensaftNetto = 1.25;
    float apfelsaftMenge, birnensaftMenge, nettoPreis7, nettoPreis19, rechnungsBetrag;
    int apfelMenge, birneMenge;

    printf("Anzahl Aepfel: ");
    scanf("%d", &apfelMenge);
    printf("Anzahl Birnen: ");
    scanf("%d", &birneMenge);
    printf("Menge Apfelsaft (l): ");
    scanf("%f", &apfelsaftMenge);
    printf("Menge Birnensaft (l): ");
    scanf("%f", &birnensaftMenge);

    nettoPreis7 = apfelMenge * apfelNetto + birneMenge * birneNetto;
    nettoPreis19 = apfelsaftMenge * apfelsaftNetto + birnensaftMenge * birnensaftNetto;

//    printf("\nNetto7: %f, Netto19: %f", nettoPreis7, nettoPreis19);

    if (apfelMenge >= 5 && (nettoPreis7 + nettoPreis19) > 10) nettoPreis7 -= apfelMenge * apfelNetto * 0.05;

    rechnungsBetrag = nettoPreis7 * 1.07 + nettoPreis19 * 1.19;

    printf("\nRechnungsbetrag: %.2f", rechnungsBetrag);
}

float preisBerechnen(float produktMenge, float produktPreis) {

}

