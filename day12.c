#include <stdio.h>
#include <string.h>

void day12() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Tag 12 Mitschrift\n"
           "Option (2): Schulnoten\n"
           "Option (0): Exit Tag 8\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: day12Mitschrift(); day12(); break;
        case 2: schulNoten(); day12(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day12(); break;
    }
}


void day12Mitschrift() {

    // Mehrdimensionale Arrays
    // Bsp.: Ein Ladenbesitzer m�chte f�r 5 L�den jeweils alle 12 Monatsums�tze abspeichern

    float umsatz[5][12];

    // Initialisierung und Kontrollausgabe
    for (int laden = 0; laden < 5; laden++) {
        for (int monat = 0; monat < 12; monat++) {
            umsatz[laden][monat] = 100;
            printf("umsatz[%d][%d]=%.2f\n", laden, monat, umsatz[laden][monat]);
        }
    }

    // Die �u�ere und innere Schleife kann getauscht werden
    for (int monat = 0; monat < 12; monat++) {
        for (int laden = 0; laden < 5; laden++) {
            umsatz[laden][monat] = 100;
            printf("umsatz[%d][%d]=%.2f\n", laden, monat, umsatz[laden][monat]);
        }
    }
}


/*
    Aufgabenstellen
        Das Programm f�hrt zun�chst ein 2-dimensionales Array f�r 10 Sch�ler und PRO Sch�ler f�r 5 Noten ein.
        (F�r jeden der 10 Sch�ler k�nnen also 5 Noten abgespeichert werden)

        Anschlie�end startet eine (verschachtelte) Eingabe-Schleife, bei der der User f�r alle Sch�ler jeweils die entsprechenden
        Noten eingeben kann.
            Hinweis: Der User soll bei jeder Eingabe per Text informiert werden, welcher Sch�ler und die wievielte Note eingegeben werden soll

        Nach dieser Eingabe-Schleife hat der User die M�glichkeit 2 Integer-Werte einzugeben x und y einzugeben.
        Anschlie�end wird die y-te Note des x-ten Sch�lers ausgegeben. FALLS 1<=x<=10 und 1<=y<=5, ansonsten soll eine Fehlermeldung erscheinen
            Hinweis: Achten Sie bitte darauf, dass der User von den Noten 1 bis 5 und von den Sch�lern 1 bis 10 spricht, Sie aber intern von 0 bis...


        Nach dieser Ausgabe endet das Programm

    PSEUDO L�sung:
    Programm schulNoten
        schuelerNote[10][5]
        f�r (schueler = 0; schueler < 10; schueler++)
            f�r (note = 0; note < 5; note++)
                Ausgabe: "Eingabe Note " note + 1 "f�r Sch�ler " schueler + 1
                Eingabe: schuelerNote[schueler][note]
        (Ausgabe: "Bitte gib den Sch�ler und die gew�nschte Note ein") // in Aufgabe nicht gew�nscht
        Eingabe: x, y
        Wenn (1 <= x <= 10 && 1 <= y <= 5)
            Ausgabe: schuelerNote[x-1][y-1]
        Sonst
            Ausgabe: "Die Eingabe war fehlerhaft"
    Ende Programm

*/


void schulNoten() {
    // Experimente
    char *schuelerArray[20] = {
        "Guenther1",
        "Guenther2",
        "Guenther3",
        "Guenther4",
        "Guenther5",
        "Guenther6",
        "Guenther7",
        "Guenther8",
        "Guenther9",
        "Guenther10",
    };
//    printf("\n%s\n%s", schuelerArray[0], schuelerArray[1]);

    char schuelerArray2[10][30];

//    for (int i = 0; i < 10; i++) {
//        char tempSchueler[10];
//        sprintf(tempSchueler, "Guenther%d", i+1);
//        strcpy(schuelerArray2[i], tempSchueler);
//        printf("%s\n", schuelerArray2[i]);
//    }

    // tats�chliche Aufgabe
    int schuelerNote[10][5];
    // Eingabeschleife
    for (int schueler = 0; schueler < 10; schueler++) {

        char tempSchueler[10];
        sprintf(tempSchueler, "Guenther%d", schueler+1);
        strcpy(schuelerArray2[schueler], tempSchueler);

        for (int note = 0; note < 5; note++) {
            printf("\nBitte geben Sie die %dte Note von Schueler %s ein", note+1, schuelerArray2[schueler]);
//            fflush(stdin);
//            scanf("%d", &schuelerNote[schueler][note]);
            schuelerNote[schueler][note] = note+1;
        }
        printf("\n");
    }

    // Abfrage der gew�nschten Note
    int korrekteAbfrage = 1;
    do {
        int schueler, note;

        printf("\nWelcher Schueler?");
        fflush(stdin);
        scanf("%d", &schueler);
        printf("\nWelcher Note?");
        fflush(stdin);
        scanf("%d", &note);

        if (1 <= schueler && schueler <= 10 && 1 <= note && note <= 5) {
            printf("\nDie gewuenschte Note von Schueler %s lautet: %d", schuelerArray2[schueler-1], schuelerNote[schueler-1][note-1]);
            korrekteAbfrage = 0;
        } else printf("\nIhre Eingabe war nicht korrekt.");

    } while (korrekteAbfrage == 1);
}






