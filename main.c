#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    switchCase();
}


void switchCase() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Tag 6\n"
           "Option (2): Tag 7\n"
           "Option (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: day6(); switchCase(); break;
        case 2: day7(); switchCase(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); switchCase(); break;
    }
}
