#include <stdio.h>

void day9() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Berechne Pruefziffer mit String Eingabe\n"
           "Option (2): Wetter Erfassung\n"
           "Option (3): Pruefzahl\n"
           "Option (4): String Tests\n"
           "Option (5): Strings zusammenfuegen\n"
           "Option (0): Exit Tag\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: berechnePruefziffer4(); day9(); break;
        case 2: wetterErfassung(); day9(); break;
        case 3: pruefZahl(); day9(); break;
        case 4: stringTests(); day9(); break;
        case 5: stringEingabeZusammenhaengen(); day9(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day9(); break;
    }
}

void berechnePruefziffer4() {
    int pruefSumme = 0, pruefZiffer = 0;
    char ean[13];

    printf("\nEAN (ohne Pruefziffer) eingeben: ");
    scanf_s("%12s", ean);
    scanf("%*[^\n]");
    scanf("%*c");

    for (int i = 0; i < 13; i++) {
        printf("\n%d: %c, check: %d", i, ean[i], ean[i]=='\0');
    }

    for (int i = 0; i < 12; i++) {
        if (i%2 == 0) pruefSumme += ean[i] - 48;
        else pruefSumme += (ean[i] - 48) * 3;
    }

    if (pruefSumme % 10 != 0) pruefZiffer = 10 - pruefSumme % 10;
    printf("\n%s", ean);

    printf("\nPruefziffer: %d\nPruefsumme: %d", pruefZiffer, pruefSumme);
}


void wetterErfassung() {
    float woche[7] = {5.7, 3.6, 2.1, 0.0, 1.2, 0.9, 0.2};
    float groessterNiederschlag = 0, niedrigsterNiederschlag = 0, durchSchnitt;

    for (int i = 0; i < 7; i++) {
        if (groessterNiederschlag < woche[i]) groessterNiederschlag = woche[i];
        if (niedrigsterNiederschlag > woche[i]) niedrigsterNiederschlag = woche[i];
        durchSchnitt += woche[i];
    }
    durchSchnitt = durchSchnitt / 7;
    printf("\nDer durchschnittliche Niederschlag betraegt: %.2f"
           "\nDer niedrigste Niederschlag betraegt: %.2f"
           "\nDer hoechste Niederschlag betraegt: %.2f"
           , durchSchnitt, niedrigsterNiederschlag, groessterNiederschlag);
}

void pruefZahl() {
    int sum1 = 0, sum2 = 0, pruefZahl = 0, cardLaenge = 6;
    int cardNumber[] = {6, 2, 5, 8, 4, 3};

    for (int i = 0; i < cardLaenge; i += 2) {
        int zahl = cardNumber[i] * 2;

        if (zahl <= 9) sum1 += zahl;
        else sum1 += zahl / 10 + zahl % 10;

        sum2 += cardNumber[i + 1];
    }
    pruefZahl = sum1 + sum2;
    printf("\nPruefzahl: %d", pruefZahl);
}

void stringTests() {
    char testString[] = "test";
    printf("%d %d", testString[3], testString[4]);
    printf("%d", strlen(testString));
    printf("%d", sizeof(testString) / sizeof(testString[0]));

}

void stringEingabeZusammenhaengen() {

    char stringEingabe1[40];
    char stringEingabe2[50];
    scanf("%*[^\n]");
    scanf("%*c");
    fgets(stringEingabe1, 40, stdin);
    fgets(stringEingabe2, 50, stdin);

    int laengeE1 = strlen(stringEingabe1);
    int laengeE2 = strlen(stringEingabe2);

    char stringFinal[laengeE1 + laengeE2 - 1];
    printf("\nString: %s", stringFinal);

    printf("\n%d", sizeof(stringFinal)/sizeof(stringFinal[0]));
    printf("\n%d", laengeE1 + laengeE2 - 2);

    if (laengeE1 > laengeE2) {
        strncpy(stringFinal, stringEingabe1, laengeE1 - 1);
        stringFinal[laengeE1-1] = '\0';
//        printf("\nString: %s", stringFinal);
        strncat(stringFinal, stringEingabe2, laengeE2 - 1);
    } else {
        strncpy(stringFinal, stringEingabe2, laengeE2 - 1);
        stringFinal[laengeE2-1] = '\0';
//        printf("\nString: %s", stringFinal);
        strncat(stringFinal, stringEingabe1, laengeE1 - 1);
    }

    printf("\nString: %s", stringFinal);
}
