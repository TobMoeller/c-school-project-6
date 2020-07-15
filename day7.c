#include <stdio.h>
#include <stdlib.h>

void day7() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Else ohne geschweifte Klammern\n"
           "Option (2): While Schleife\n"
           "Option (3): While Schleife 2\n"
           "Option (4): Spiele Marktanalyse\n"
           "Option (5): Fuss Schleife\n"
           "Option (0): Exit Tag 7\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: elseOhneKlammern(); day7(); break;
        case 2: whileSchleile(); day7(); break;
        case 3: whileSchleife2(); day7(); break;
        case 4: spieleMarkt(); day7(); break;
        case 5: fussSchleife(); day7(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day7(); break;
    }
}


void elseOhneKlammern() {
    // Demonstration einer if/else Beziehung ohne geschweifte Klammern
    int alter = 9;
    if( alter >= 8)
       if ( alter >= 10)
          printf("Alter >= 10");
    else
       printf("Alter kleiner als 8");

}

void whileSchleile() {
    // Einfache Beispielaufgabe einer kopfgesteuerten Schleife
    int i, zahl;

    printf("Zahl eingeben: ");
    scanf("%d", &zahl);

    while (i <= zahl) {
        printf("%d", i);
        i++;
    }
}

void whileSchleife2() {
    // Einfache Beispielaufgabe einer kopfgesteuerten Schleife
    int oben, zahl, summe;
    summe = 0;
    oben = 10;
    zahl = 3;
    while (zahl <= oben) {
        summe=summe+zahl;
        zahl=zahl+1;
    }
    printf("%d \n", summe);
}

void spieleMarkt() {
    // Es sollen Umfrageergebnisse eingegeben werden zu welchen der Anteil der Zielgruppe ausgegeben wird
    int age, hasPc, sex, matches=0, sumSurvey = 0, continueSurvey = 1;
    float shareOfTargetGroup;

    while (continueSurvey == 1) {
        age = spieleMarktAbfrage("Ihr Alter ein");
        hasPc = spieleMarktAbfrage("an, wie viele PCs Sie besitzen");
        sex = spieleMarktAbfrage("Ihr Geschlecht an [1=m/2=w/3=d]");
        continueSurvey = spieleMarktAbfrage("eine 1 fuer einen weiteren Eintrag und eine 0 zum Beenden ein");

        if (age < 21 && hasPc > 0 && sex == 1) matches++;
        sumSurvey++;
    }
    shareOfTargetGroup = (float) matches / sumSurvey * 100;
    printf("\nDer Zielgruppenanteil betraegt: %.2f %%", shareOfTargetGroup);
}

int spieleMarktAbfrage(char einheit[]) {
    // Auslagern der Abfrage
    int menge;
    printf("Bitte geben Sie %s: ", einheit);
    scanf("%d", &menge);
    return menge;
}

void fussSchleife() {
    // Der Benutzer soll 10 Ganzzahlen eingeben, welche in einer fussgesteuerten Schleife addiert werden
    int zahl, summe = 0, zaehler = 0;
    do {
        printf("Zahl: ");
        scanf("%d", &zahl);
        summe += zahl;
        zaehler++;
    } while (zaehler < 10);
    printf("\nDie Summe ist: %d", summe);
}
