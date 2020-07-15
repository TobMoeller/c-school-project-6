#include <stddef.h>

void day8() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Zaehlergesteuerte Schleife\n"
           "Option (2): Array schleifengesteuert ausgeben\n"
           "Option (3): Kleinste Zahl\n"
           "Option (4): Berechne Pruefziffer\n"
           "Option (0): Exit Tag 8\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: forSchleife(); day8(); break;
        case 2: arraySchleife(); day8(); break;
        case 3: kleinsteZahl(); day8(); break;
        case 4: berechnePruefziffer(); day8(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day8(); break;
    }
}

void forSchleife() {
    for (int i = 0; i < 10; i++) {
        printf("\n%d", i);
    }
}

void arraySchleife() {
    char testArray[50] = {'t', 'e', 's', 't'};
//    char testArray[50] = {"test"};

    for (int i = 0; i < 6; i++) {
        if (testArray[i]) printf("%c", testArray[i]);
        else printf(":leer:");
    }
    printf("%d", sizeof(testArray));
}

void kleinsteZahl() {
    int testArray[10] = {1, 2, 7, 100, -50, -2, 50, 33, -12, 60};
    int kleinsteZahl = testArray[0];
    int position = 0;
    size_t length1 = sizeof(testArray);
    size_t length2 = sizeof(testArray) / sizeof(testArray[0]);
    int length3 = sizeof(testArray);
    int length4 = sizeof(testArray) / sizeof(testArray[0]);

    printf("%zd", sizeof(testArray));
    printf("l1: %d, l2: %d, l3int: %d, l4int: %d, ", length1, length2, length3, length4);

    for (int i = 0; i < 10; i++) {
        if (kleinsteZahl > testArray[i]) {
            kleinsteZahl = testArray[i];
            position = i;

        }
    }
    printf("\nKleinste Zahl: %d, Index: %d", kleinsteZahl, position);
}

void berechnePruefziffer() {
    int pruefSumme = 0, pruefZiffer;
//    int artikelNummer[12] = {4, 0, 1, 6, 1, 3, 8, 1, 0, 0, 6, 0};
    int artikelNummer[12] = {4, 0, 1, 6, 1, 3, 8, 1, 0, 0, 6, 3};
    printf("\nEAN: ");

    for (int i = 0; i < 12; i+=2) {
        pruefSumme += artikelNummer[i] + artikelNummer[i + 1] * 3;
        printf("%d%d", artikelNummer[i], artikelNummer[i+1]);
    }

    if (pruefSumme % 10 == 0) {
        pruefZiffer = 0;
    } else {
        pruefZiffer = 10 - pruefSumme % 10;
    }

    printf("%d", pruefZiffer);
    printf("\nPruefsumme: %d", pruefSumme);
}
