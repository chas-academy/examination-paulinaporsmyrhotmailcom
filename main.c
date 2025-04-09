#include <stdio.h>
#include <ctype.h>

#define NUM_STUDENTS 5
#define NUM_TESTS 13

int main(){
    char names[NUM_STUDENTS][11];
    int scores[NUM_STUDENTS][NUM_TESTS];
    float avg_scores[NUM_STUDENTS];
    float total_avg_score = 0.0;
    int i, j;

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter student %d data (name followed by 13 test scores):\n", i + 1);
        scanf("%s", names[i]);

        int sum = 0;
        for (j = 0; j < NUM_TESTS; j++) {
            scanf("%d", &scores[i][j]);
            sum += scores[i][j];
        }
        avg_scores[i] = sum / (float)NUM_TESTS;
        total_avg_score += avg_scores[i];
    }

    int highestIndex = 0;
    for (i = 1; i < NUM_STUDENTS; i++ ) {
        if (avg_scores[i] > avg_scores[highestIndex]) {
            highestIndex = i;
        }
    }

    names[highestIndex][0] = toupper(names[highestIndex][0]);
    printf("%s\n", names[highestIndex]);

    float group_avg_score = total_avg_score / NUM_STUDENTS;

    int any_below_avg = 0;
    for (i = 0; i < NUM_STUDENTS; i++){
        if (avg_scores[i] < group_avg_score){
            names[i][0] = toupper(names[i][0]);
            printf("%s\n", names[i]);
            any_below_avg = 1;
        }
    }
        if (!any_below_avg) {
            printf("\n");
        }

        return 0;
}



