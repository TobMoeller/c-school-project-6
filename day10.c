#include <stdio.h>

void day10() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Berechne Pruefziffer mit String Eingabe\n"
           "Option (2): Tag 10 Testfunktion\n"
           "Option (3): String Vergleich 2\n"
           "Option (4): Taschenrechner\n"
           "Option (5): Taschenrechner 2\n"
           "Option (0): Exit Tag 8\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: berechnePruefziffer5(); day10(); break;
        case 2: tag10Test(); day10(); break;
        case 3: stringVergleichNachStruktogramm(); day10(); break;
        case 4: taschenrechner(); day10(); break;
        case 5: taschenrechner2(); day10(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day10(); break;
    }
}


void berechnePruefziffer5() {
    int pruefSumme = 0, pruefZiffer;
    const int max = 15;
    char artikelNummer[max];

    scanf("%*[^\n]");
    scanf("%*c");

    while (strlen(artikelNummer) != 12) {
        printf("\nBitte geben Sie eine 12 stellige Artikelnummer ein:\t");
        fgets(artikelNummer, max, stdin);
        fflush(stdin);
        int charCheck = 1;
        for (int i = 0; i < strlen(artikelNummer) && charCheck != 0; i++) {
            if ((artikelNummer[i] - 48) > 9) charCheck = 0;
        }
        if(charCheck != 0 && artikelNummer[12] == '\n') artikelNummer[12] = '\0';
        else printf("Ihre Eingabe war nicht korrekt.");
    }

    printf("\n");

    for(int i = 0; i < 12; i += 2) {
        pruefSumme = pruefSumme + artikelNummer[i] - 48 + (artikelNummer[i+1] - 48)* 3;
        printf("%d%d", artikelNummer[i] - 48, artikelNummer[i+1] - 48);
    }

    if(pruefSumme % 10 == 0) pruefZiffer = 0;
    else pruefZiffer = 10 - pruefSumme % 10;

    printf("%d lautet die vollstaendige EAN", pruefZiffer);
    printf("\nDie Pruefziffer ist: %d\n\n", pruefZiffer);
    return 0;
}

void tag10Test() {
    printf("\nsize of int %d", sizeof(int));
    printf("\nsize of int %d", sizeof(float));
    printf("\nsize of int %d", sizeof(double));
    printf("\nsize of int %d", sizeof(long));
    printf("\nsize of int %lld", sizeof(long long));

    float werte3[] = {1.3, -2.9};
    float werte[7] = {2.3, 3.4, 4.5, 5.6, 6.7};
    float werte1[] = {1.1, 2.2};

    int anzahlElemente = sizeof(werte) / sizeof(float);

    for (int i = 0; i < anzahlElemente; i++) {
        printf(" %f ", werte[i]);
    }
}

void stringVergleichNachStruktogramm() {
    int laengeArray1 = 0, laengeArray2 = 0;
    char array1[40];
    char array2[50];

    scanf("%*[^\n]");
    scanf("%*c");
    printf("Array 1 eingeben: ");
    fgets(array1, 40, stdin);
    printf("Array 2 eingeben: ");
    fgets(array2, 50, stdin);

    printf("\nArray 1: %s\nArray 2: %s", array1, array2);
    while (array1[laengeArray1] != '\n') {
        laengeArray1 ++;
    }
    while (array2[laengeArray2] != '\n') {
        laengeArray2 ++;
    }
    printf("\nLaenge 1: %d, Laenge 2: %d", laengeArray1, laengeArray2);

    char array3[laengeArray1 + laengeArray2 + 1];
    int i = 0, j = 0;
    if (laengeArray1 > laengeArray2) {
//        int i = 0;
        while (i < laengeArray1) {
            array3[i] = array1[i];
            i++;
        }
//        int j = 0;
        while (j < laengeArray2) {
            array3[i] = array2[j];
            i++;
            j++;
        }
    } else {
//        int i = 0;
        while (i < laengeArray2) {
            array3[i] = array2[i];
            i++;
        }
//        int j = 0;
        while (j < laengeArray1) {
            array3[i] = array1[j];
            i++;
            j++;
        }
    }

    array3[i++] = '\0';
    printf("\nAusgabe: %s", array3);
}

void taschenrechner() {
    int zahl1, zahl2, ergebnis;
    char zeichen;

    printf("Zahl1 eingeben: ");
    scanf("%d", &zahl1);
    printf("Zahl2 eingeben: ");
    scanf("%d", &zahl2);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Operator eingeben: ");
    scanf("%c", &zeichen);

    switch(zeichen) {
        case '+': ergebnis = zahl1 + zahl2; break;
        case '-': ergebnis = zahl1 - zahl2; break;
        case '*': ergebnis = zahl1 * zahl2; break;
        case '/': if (zahl2 != 0) ergebnis = zahl1 / zahl2; break;
        case '%': if (zahl2 != 0) ergebnis = zahl1 % zahl2; break;
        default: printf("fehlerhafte Eingabe");
    }
    printf("\nErgebnis: %d", ergebnis);
}

void taschenrechner2() {
    float zahl1, zahl2, ergebnis;
    char zeichen;

    printf("Zahl1 eingeben: ");
    scanf("%f", &zahl1);
    printf("Zahl2 eingeben: ");
    scanf("%f", &zahl2);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Operator eingeben: ");
    scanf("%c", &zeichen);

//    printf("%d", (int) zahl2);
    int ausgabe = 1;
    switch(zeichen) {
        case '+': ergebnis = zahl1 + zahl2; break;
        case '-': ergebnis = zahl1 - zahl2; break;
        case '*': ergebnis = zahl1 * zahl2; break;
        case '/':
            if ((int) zahl2 != 0) ergebnis = zahl1 / zahl2;
            else {printf("\nNicht durch null"); ausgabe = 0;} break;
        case '%':
            if (zahl1 >= 0 && (int) zahl2 > 0) ergebnis = (int) zahl1 % (int) zahl2;
            else {printf("\nFehlerhafte Eingabe"); ausgabe = 0;} break;
        default: printf("fehlerhafte Eingabe");
    }
    if (ausgabe) printf("\nErgebnis: %.2f", ergebnis);
}



