#include <stdio.h>
#include <stdlib.h>

struct Grade
{
    int eng;
    int math;
    int sci;
};

int main() {
    int n_student;
    float avgGrades[3] = {0.};

    printf("Number of students: ");
    scanf("%d", &n_student);

    struct Grade *studentGrades = (struct Grade *) malloc(n_student * sizeof(struct Grade));
    if(!studentGrades) {
        printf("Memory allocation failed.");
        return 1;
    }

    for(int i=0; i<n_student; i++) {
        printf("Student %d: \n", i+1);
        printf("English: ");
        scanf("%d", &studentGrades[i].eng);
        avgGrades[0] += studentGrades[i].eng;
        printf("Math: ");
        scanf("%d", &studentGrades[i].math);
        avgGrades[1] += studentGrades[i].math;
        printf("Science: ");
        scanf("%d", &studentGrades[i].sci);
        avgGrades[2] += studentGrades[i].sci;
        printf("\n");
    }

    printf("Avg grades: ");
    for(int i=0; i<3; i++) {
        avgGrades[i] /= (float)n_student;
        printf("%.2f ", avgGrades[i]);
    }

    return 0;
}