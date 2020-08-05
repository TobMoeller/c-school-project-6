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
           "Option (3): Tag 8\n"
           "Option (4): Tag 9\n"
           "Option (5): Tag 10\n"
           "Option (6): Tag 11\n"
           "Option (7): Tag 12\n"
           "Option (8): Tag 13\n"
           "Option (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: day6(); switchCase(); break;
        case 2: day7(); switchCase(); break;
        case 3: day8(); switchCase(); break;
        case 4: day9(); switchCase(); break;
        case 5: day10(); switchCase(); break;
        case 7: day12(); switchCase(); break;
        case 8: day13(); switchCase(); break;
        case 9: test(); switchCase(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); switchCase(); break;
    }
}

void test() {
    int i = 7;
    if (!(4 < i < 6)) printf("false");
    else printf("true");
}
