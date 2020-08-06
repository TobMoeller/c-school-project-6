#include <stdio.h>
#include <windows.h>
#include <string.h>

void neuerKasten(int kasten[4][5]);
void handleFlasche(int kasten[4][5], char menu[100], int replace, int insert);
void kastenZeichnen(int kasten[4][5], char border[34]);

void day14() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Tag 14 Mitschrift\n"
           "Option (2): Uebung 1\n"
           "Option (3): Uebung 2\n"
           "Option (4): Uebung 2, Version 2\n"
           "Option (0): Exit Tag\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: day14Mitschrift(); day14(); break;
        case 2: uebung14_1(); day14(); break;
        case 3: uebung14_2(); day14(); break;
        case 4: uebung14_2_2(); day14(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day14(); break;
    }
}

void day14Mitschrift() {
    // -- 2-dimensionale char arrays --
    system("chcp.com 1252");
    system("cls");

    // Beispiel: durchnummerierte Wochentage

    // Deklaration
    char wochentag[7][20]; // 7 Tage, 20 Zeichen Platz für jeden Tag (faule Abschätzung)
    // Notiz am Rande: wochentag (ohne []) ist die Abkürzung für wochentag[0][0]

    // Initialisierung mittels Literal

    strcpy(wochentag[0], "Montag"); // wochentag[0] ist die Abkürzung für &wochentag[0][0]
    strcpy(wochentag[1], "Dienstag");
    strcpy(wochentag[2], "Mittwoch");
    strcpy(wochentag[3], "Donnerstag");
    strcpy(wochentag[4], "Freitag");
    strcpy(wochentag[5], "Samstag");
    strcpy(wochentag[6], "Sonntag\n");

    // Kontrollausgabe
    for (int i = 0; i < 7; i++) printf("\n%s", wochentag[i]);
    for (int i = 0; wochentag[2][i] != '\0'; i++) printf("%c", wochentag[2][i]);
    // eigene Experimente
    char testStrings[5][20] = {"test1", "test2", "test3", "test4", "test5"};
    for (int i = 0; i < 5; i++) printf("\n%s", testStrings[i]);
    char *testStrings2[20] = {"test1", "test2", "test3", "test4", "test5"};
    for (int i = 0; i < 10; i++) printf("\n%s", testStrings2[i]);
    printf("\nSize: %d", (sizeof(*testStrings2) / sizeof(*testStrings2[0])));

    // Initialisierung / Zuweisung eines Strings mittels User-Eingabe
    printf("\nEingabe: ");
    fflush(stdin);
    scanf("%[^\n]", wochentag[0]); // oder scanf("%[^\n]", &wochentag[0][0]);
    // Kontrollausgabe
    for (int i = 0; i < 7; i++) printf("\n%s", wochentag[i]);

    /*
        Ergänzung zu beliebig dimensionalen Arrays (>2)
            Erläuterung der Sinnhaftigkeit an Beispiel:
            1) ein einzelner Schüler => 0-dimensional (man kann nichts zählen)
            2) eine Klasse von Schülern => 1-dimensional (Schüler1, Schüler2, ...)
            3) eine Schule mit Klassen => 2-dimensional (Klasse1, Klasse2, ...)
            4) eine Stadt mit Schulen => 3-dimensional
            5) eine Land mit Städten => 4-dimensional
            ...
            => aus Sicht von 5)
                schuler[1][2][3][4] = Schüler Nummer 4 in Klasse 3 der Schule 2 aus Stadt 1
    */
}

void uebung14_1() {
    /*
        Entwickeln Sie ein Sitzplatz-Reservierungsprogramm für ein Theater. Das Theater hat 90 Plätze, die wie folgt angeordnet sind.
                 Reihe 1 xxxxxxxxxxxxxx
                 Reihe 2 xxxxxxxxxxxxxx
                 Reihe 3 xxxxxxxxxxxxxx
                 Reihe 4 xxxxxxxxxxxxxx
                 Reihe 5 xxxxxxxxxxxxxx
                 Reihe 6 xxxxxxxxxxxxxx
        •	Der Benutzer soll angeben können, welchen Platz (Reihe und Platznummer) er reservieren möchte.
        •	Prüfen Sie bei der Platzreservierung, ob der Platz noch frei ist.
        Entwickeln Sie einen Programmablaufplan, ein Struktogramm oder Pseudocode und implementieren Sie es in C.

        PSEUDOCODE
            Programm platzreservierung {
                sitzplatz[6][15] = {...}
                Eingabe: auswahlReihe
                Eingabe: auswahlPlatz
                wenn (sitzplatz[auswahlReihe][auswahlPlatz] == 0) {
                    sitzplatz[auswahlReihe][auswahlPlatz] = 1
                } sonst {
                    Ausgabe: "Der Platz ist bereits belegt"
                }
            }

    */

    int sitzplatz[6][15];
    int auswahlReihe;
    int auswahlPlatz;

    for (int i=0;i<6;i++) {
        for(int j=0;j<15;j++) {
            sitzplatz[i][j] = 1;
        }
    }

    printf("In welcher Reihe moechten Sie sitzen? (1-6):\t");
    fflush(stdin);
    scanf("%d", &auswahlReihe);

    printf("Auf welchem Platz moechten Sie sitzen? (1-15):\t");
    fflush(stdin);
    scanf("%d", &auswahlPlatz);


    if (sitzplatz[auswahlReihe-1][auswahlPlatz-1]==0) sitzplatz[auswahlReihe-1][auswahlPlatz-1]=1;
    else printf("Sitzplatz ist schon belegt!");

}

void uebung14_2() {
    /*
        Sie sind Mitarbeiter der Firma HardUndSoft GmbH & Co. KG, die im Auftrag von Kunden Hardware und Software entwickelt.

        Ein Kunde möchte ein Robotersystem haben, dass volle Flaschen aus einem Kasten herausholt und leere Flaschen wieder in den Kasten zurückstellt. Sie sollen die Software für das Robotersystem schreiben. Die Software soll folgende Funktionalität erfüllen:
        1.	eine volle Flasche herausnehmen
        2.	eine leere Flasche in den Kasten zurückstellen

        In der ersten Ausbaustufe soll das Programm ohne Roboter getestet werden. Dazu sollen sie ein Menü erstellen, über das die Funktionalitäten 1. und 2. getestet werden können. Aus Ausgabe soll die Position im Kasten auf der Console ausgegeben werden.
        Der Projektleiter erklärt weiterhin, dass der Roboter in der ersten Phase nur Kästen der Größe 4 * 5 Flaschen bearbeiten kann.

        Entwickeln Sie einen Programmablaufplan, ein Struktogramm oder Pseudocode und implementieren Sie es in C.
    */

    system("chcp.com 1252");
    system("cls");
    // Kasten
    char border[34] = "\n-------------------------------\n";
    int kasten[4][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int programmWahl;
    char menu[100] = "";

    do {
        system("cls");
        // Kasten zeichnen
        printf("\nComputer: %s\n\n", menu);
        for (int i = 0; i < 4; i++) {
            printf("%s", border);
            printf("|");
            for (int j = 0; j < 5; j++) {
                char flasche;
                switch (kasten[i][j]) {
                    case 0: flasche = 'x';break; //voll
                    case 1: flasche = 'o';break; //leereFlasche
                    default: flasche = ' ';break; //leererSchacht
                }
                printf(" (%c) |", flasche);
            }
        }
        printf("%s", border);
        // Eingabe User
        printf(
           "\nWas möchtest du tun?"
           "\n(1) Flasche entnehmen"
           "\n(2) Flasche zurückstellen"
           "\n(0) Programm beenden\n"
        );

        fflush(stdin);
        scanf("%d", &programmWahl);

        switch (programmWahl) {

            case 1: {
                int erfolg = 0;
                for (int i = 0; i < 4 && erfolg != 1; i++) {
                    for (int j = 0; j < 5 && erfolg != 1; j++) {
                        if (kasten[i][j] == 0) {
                            kasten[i][j] = 2;
                            erfolg = 1;
                        }
                    }
                }
                if (erfolg) {
                    strcpy(menu, "Hier ist Ihre Flasche: (x)");
                } else {
                    strcpy(menu, "Es ist leider keine volle Flasche mehr vorhanden.");
                }
            }; break;

            case 2: {
                int erfolg = 0;
                for (int i = 0; i < 4 && erfolg != 1; i++) {
                    for (int j = 0; j < 5 && erfolg != 1; j++) {
                        if (kasten[i][j] > 1) {
                            kasten[i][j] = 1;
                            erfolg = 1;
                        }
                    }
                }
                if (erfolg) {
                    strcpy(menu, "Vielen Dank für Ihre Flasche.");
                } else {
                    strcpy(menu, "Es ist leider kein freier Schacht mehr vorhanden.");
                }
            }; break;

            case 0: programmWahl = 0; break;

            strcpy(menu, "Bitte machen Sie eine korrekte Eingabe!"); break;
        }

    } while (programmWahl != 0);

}

void uebung14_2_2() {
    system("chcp.com 1252");
    system("cls");
    // Kasten
    char border[34] = "\n-------------------------------\n";
    int kasten[4][5];
    int programmWahl;
    char menu[100] = "Ich bin ein Bierautomat";
    // Initialisierung kasten
    neuerKasten(kasten);
    // Funktionaler Teil in Schleife
    do {
        system("cls");
        // GUI/Kasten zeichnen
        printf("\n-- %s --\n\n", menu);
        kastenZeichnen(kasten, border);
        // Auswahl Programmpunkt User
        programmWahl = inputUser();
        switch (programmWahl) {
            case 1: handleFlasche(kasten, menu, 0, 2); break; // Entnahme Flasche (array, text, gesucht, ersetzt durch)
            case 2: handleFlasche(kasten, menu, 2, 1); break; // Rückgabe leere Flasche
            case 3: neuerKasten(kasten); strcpy(menu, "Zisch, ein neuer Kasten"); break;
            case 0: system("cls"); break;
            default: strcpy(menu, "Bitte machen Sie eine korrekte Eingabe!"); break;
        }
    } while (programmWahl != 0);
}

void neuerKasten(int kasten[4][5]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            kasten[i][j] = 0;
        }
    }
}

void handleFlasche(int kasten[4][5], char menu[100], int replace, int insert) {
    int erfolg = 0;
    for (int i = 0; i < 4 && erfolg != 1; i++) {
        for (int j = 0; j < 5 && erfolg != 1; j++) {
            if (kasten[i][j] == replace) {
                kasten[i][j] = insert;
                erfolg = 1;
            }
        }
    }
    if (erfolg) {
        if (replace == 2) strcpy(menu, "Vielen Dank für Ihre Flasche.");
        else strcpy(menu, "Hier ist Ihre Flasche: (x), plopp");
    } else {
        if (replace == 2) strcpy(menu, "Es ist leider kein freier Schacht mehr vorhanden.");
        else strcpy(menu, "Es ist leider keine volle Flasche mehr vorhanden.");
    }
}

void kastenZeichnen(int kasten[4][5], char border[34]) {
    for (int i = 0; i < 4; i++) {
        printf("%s", border);
        printf("|");
        for (int j = 0; j < 5; j++) {
            char flasche;
            switch (kasten[i][j]) {
                case 0: flasche = 'x';break; //voll
                case 1: flasche = 'o';break; //leereFlasche
                default: flasche = ' '; kasten[i][j] = 2; break; //leererSchacht
            }
            printf(" (%c) |", flasche);
        }
    }
    printf("%s", border);
}

int inputUser() {
    int programmWahl;
    printf(
       "\nWas möchtest du tun?"
       "\n(1) Flasche entnehmen"
       "\n(2) Flasche zurückstellen"
       "\n(3) Neuer Kasten"
       "\n(0) Programm beenden\n"
    );
    fflush(stdin);
    scanf("%d", &programmWahl);
    return programmWahl;
}








