

#include <stdio.h>
#include <stdlib.h>
double einheitAbfrage(char einheit[]);
double calculatePorto(double laenge, double breite, double hoehe, double gewicht);

void day6() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Saftladen\n"
           "Option (2): Aufzug\n"
           "Option (3): Paket Check\n"
           "Option (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: saftLaden(); day6(); break;
        case 2: aufzug(); day6(); break;
        case 3: paketCheck(); day6(); break;
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

void aufzug() {
    int gewicht =0, aufzug=0;
    float hoehe;
    char kettensaege[100] = "\nBitte nehmen Sie eine Kettensaege zum zerkleinen und teilen. ";

    printf_s("Geben Sie das Gewicht ein\n");
    scanf_s("%d", &gewicht);
    printf_s("Geben Sie die Hoehe ein\n");
    scanf_s("%f", &hoehe);

    if (gewicht > 500 || hoehe > 2.5) {
        printf_s("%s", kettensaege);
    } else if (gewicht<=50 && hoehe<=1.5 ) {
        printf_s("nimm Aufzug = 123");
    } else if ( gewicht<=125 && hoehe<=2){
        printf_s("nimm Aufzug 2 oder 3");
    } else if ( gewicht<=125 && hoehe<=2.50){
        printf_s("nimm Aufzug 2 ");
    } else if ( gewicht<=500 && hoehe<=2) {
        printf_s( "only elevator 3 biatch!");
    } else {
        printf_s("%s", kettensaege);
    }
}

void paketCheck() {
    double laenge = einheitAbfrage("die Laenge");
    double breite = einheitAbfrage("die Breite");
    double hoehe = einheitAbfrage("die Hoehe");
    double gewicht = einheitAbfrage("das Gewicht");

    double porto = calculatePorto(laenge, breite, hoehe, gewicht);
    if (porto == 0) printf("\nIhr Paket ist zu gross. Kontaktieren Sie eine Spedition.");
    else if (porto == 1) printf("\nAuf Ihr Paket passt kein Label, bitte waehlen Sie einen groesseren Karton.");
    else printf("\nDie Portkosten fuer Ihr Paket betragen %.2lf Euro.", porto);
}

double einheitAbfrage(char einheit[]) {
    double menge;
    printf("Bitte geben Sie %s ein: ", einheit);
    scanf("%lf", &menge);
    return menge;
}

double calculatePorto(double laenge, double breite, double hoehe, double gewicht) {
    if (laenge > 120 || breite > 60 || hoehe > 60 || gewicht > 31.5) return 0;
    else if (gewicht > 15) return 11.99;
    else if (gewicht > 7) return 6.99;
    else if (gewicht > 3 || laenge > 60 || breite > 30 || hoehe > 30) return 5.79;
    else if (gewicht > 1.5 || laenge > 30) return 4.79;
    else if (laenge > 15 || breite > 10) return 3.49;
    else return 1;
}
