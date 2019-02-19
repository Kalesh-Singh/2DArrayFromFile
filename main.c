#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int COLS = 4;
const int MAX_LINE = 100;

int getNumLines(FILE *fp) {
    rewind(fp);
    int lines = 0;
    while (!feof(fp)) {
        char line[MAX_LINE];
        fgets(line, MAX_LINE, fp);
        if (strcmp(line, "") != 0
            && strcmp(line, "\n") != 0
            && strcmp(line, "\r") != 0) {    // If line is not empty
            lines++;
        }
    }
    return lines;
}

void printMatrix(int matrix[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    FILE *fp = fopen("arrayFile.txt", "r");
    const int ROWS = getNumLines(fp);

    rewind(fp);
    int tasks[ROWS][COLS];

    int *ptr = tasks[0];
    while (!feof(fp)) {
        int temp;
        fscanf(fp, "%d", &temp);
        *ptr++ = temp;
    }

    printMatrix(tasks, ROWS);

    return 0;
}