#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_STUDENTS 5
#define NUM_TESTS 13

struct Student {
    char name[11];
    int scores[NUM_TESTS];
    float average;
};

int main() {
    struct Student students[NUM_STUDENTS];
    float totalAverage = 0.0;
    int i, j;

    for (i = 0; i < NUM_STUDENTS; i++) {
        scanf("%s", students[i].name);
        for (j = 0; j < NUM_TESTS; j++) {
            scanf("%d", &students[i].scores[j]);
        }

        int sum = 0;
        for (j = 0; j < NUM_TESTS; j++){
            sum += students[i].scores[j];
        }
        students[i].average = sum / (float)NUM_TESTS;
        totalAverage += students[i].average;
    }
        totalAverage /= NUM_STUDENTS;

        float highestAverage = 0;
        int highestIndex = 0;
        for (i = 0; i < NUM_STUDENTS; i++) {
            if (students[i].average > highestAverage) {
                highestAverage = students[i].average;
                highestIndex = i;
            }

        }
        students[highestIndex].name[0] = toupper(students[highestIndex].name[0]);
        printf("Steg 1 - Elev med högst medelpoäng:\n"); 
        printf("%s\n", students[highestIndex].name);

        int printed = 0;
        int underAveragePrinted = 0;
        for (i = 0; i < NUM_STUDENTS; i++) {
            if (students[i].average < totalAverage) {
               if (!underAveragePrinted) {
                printf("Steg 2 - Elever med medelpoäng under gruppens totala medel (i ordningen de matades in):\n");
                underAveragePrinted = 1;
               } 
               students[i].name[0] = toupper(students[i].name[0]);
                printf("%s\n", students[i].name);
                printed = 1;
            }
        }

        return 0;
}