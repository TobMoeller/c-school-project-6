#include <stdio.h>
#include <windows.h>

void day13() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Tag 13 Mitschrift\n"
           "Option (2): Uebung 1\n"
           "Option (3): Uebung 1, zweite Variante\n"
           "Option (4): Uebung 2\n"
           "Option (0): Exit Tag 8\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: day13Mitschrift(); day13(); break;
        case 2: uebung13_1(); day13(); break;
        case 3: uebung13_1_2(); day13(); break;
        case 4: uebung13_2(); day13(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day13(); break;
    }
}


void day13Mitschrift() {
    /*
        -- Interaktive Arraylänge --

        Vorbemerkung:
            Gelegentlich kann zum Zeitpunkt der Programmierung noch nicht entschieden werden, wie lange ein Array sein muss, um alle benötigten Werte abspeichern zu können.
            (Bsp. Dem User wird die Angabe, wie viele Werte er speichern möchte, selbst überlassen)
        Achtung!
            Nach aktuellem ANSI C-Standard ist das setzen einer Arraylänge mittels einer Variable nicht mehr zulässig.
            (Der Compiler lässt dies aktuell aber noch zu)
    */

    system("chcp.com 1252");
    system("cls");

    int anzahlFelder;
    printf("Geben Sie an, wie viele Integer Sie abspeichern möchten: ");
    fflush(stdin);
    scanf("%d", &anzahlFelder);

    int intArray[anzahlFelder];

    for (int i = 0; i < anzahlFelder; i++) {
        printf("\nGeben Sie die %d. Zahl ein: ", i + 1);
        fflush(stdin);
        scanf("%d", &intArray[i]);
    }

    for (int i = 0; i < anzahlFelder; i++) {
        printf("\nDie %d. Zahl lautet: %d", i + 1, intArray[i]);
    }
}


void uebung13_1() {
    /*
    Legen Sie ein char-Array an und füllen sie es mit einer Zeichenkette, die ein Benutzer eingibt.
    Lesen Sie anschließend von Benutzer ein Zeichen ein und prüfen Sie, ob dieses Zeichen in der Zeichenkette vorkommt. Geben Sie die Antwort auf der Console aus.

    Entwickeln Sie einen Programmablaufplan, ein Struktogramm oder ein Pseudocode und implementieren Sie es in C.

    PSEUDOCODE:

    Programm zeichenKette {
        Eingabe: zeichenkette[50]
        Eingabe: zeichen
        für (i = 0; i<50; i++) {
            wenn (zeichen == zeichenkette[i]) {
                pruefZeichen = i;
            }
        }
        wenn (pruefZeichen) {
            Ausgabe: "Das Zeichen ist enthalten"
        } sonst {
            Ausgabe: "Das Zeichen ist nicht enthalten"
        }
    }
    */
    char pruefZeichen, charArray[50];
    int i = 0;
//    char charArray[50] = "das ist eine Zeichenkette x";

    printf("Geben Sie die zu pruefende Zeichenkette an: ");
    fflush(stdin);
    scanf("%s", charArray);

    printf("Geben Sie das zu pruefende Zeichen an: ");
    fflush(stdin);
    scanf("%c", &pruefZeichen);

    for (i = 0; i < 50; i++) {
//        printf("%c", charArray[i]);
        if (charArray[i] == pruefZeichen) {
            printf("\nDas Zeichen findet sich im Array");
            break;
        }
    }

    if (i == 50) printf("\nDas Zeichen ist nicht im Array enthalten.");
}

void uebung13_1_2() {
    char pruefZeichen, charArray[50];
    int pruefZiffer = 0;

    printf("Geben Sie die zu pruefende Zeichenkette an: ");
    fflush(stdin);
    scanf("%s", charArray);

    printf("Geben Sie das zu pruefende Zeichen an: ");
    fflush(stdin);
    scanf("%c", &pruefZeichen);

    while (pruefZeichen != '\0' && pruefZeichen != charArray[pruefZiffer]) pruefZiffer++;

    if (pruefZiffer < strlen(charArray)) printf("Das Zeichen \'%c\' ist im Array enthalten.", pruefZeichen);
    else printf("Das Zeichen ist nicht im Array enthalten");
}


void uebung13_2() {
    /*
        Erstellen Sie ein char-Array und füllen Sie es mit Zeichen. Lassen Sie einige Zellen frei, indem Sie ein ‘\0‘ eingeben.
        Lesen Sie nun Zeichen von der Console ein und legen Sie die Zeichen in die noch freien Zellen des Arrays ab.
        Geben Sie eine Meldung aus, wenn das Array voll ist. Überlegen Sie sich welche Funktionalität das Menü haben muss.

        Entwickeln Sie einen Programmablaufplan , oder ein Struktogramm oder ein Pseudocode und implementieren Sie es in C.

        PSEUDOCODE:
        program fillChain{
            MAX = 10
            array[MAX] = {...}
            for (i = 0; i < MAX; i++) {
                if (array[i] == ENDE) {
                    Eingabe: zeichen
                    array[i] = zeichen
                }
            }
            Ausgabe: Array ist voll
        }
    */

    char charArray[26] = "abc\0ef\0hijklm\0opqrstuvw\0yz";
    int arrayLength = sizeof(charArray) / sizeof(charArray[0]);

    for (int i = 0; i < arrayLength; i++) {
        if (charArray[i] == '\0') {
            char localChar;
            printf("Zeichen: ");
            fflush(stdin);
            scanf("%c", &localChar);
            charArray[i] = localChar;
        }
    }

    printf("\nDas Array ist nun voll, es hat folgender Inhalt: \n\"");
    for (int i = 0; i < arrayLength; i++) {
        printf("%c", charArray[i]);
    }
    printf("\"\n");
}

