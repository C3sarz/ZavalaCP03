
/**********************************************
* Name: Cesar Zavala *
* Date: 10/26/2019 *
* Assignment: Project 3 – Number Sorting *
***********************************************
* Reads a file and sorts the numbers in it. *
***********************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

///Removes spaces from a string.
void removeSpaces(char *str, int length) {
    int count = 0;
    for (int i = 0; i < length; i++)
        if (str[i] != ' ' && str[i] != '\r' && str[i] != '\n')
            str[count++] = str[i]; // here count is
    str[count] = '\0';
}

///Swaps two ints.
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

///Swaps the contents and sizes of two arrays.
void swapArrays(int *array1, int length1, int *array2, int length2) {
    int temp[length1];
    for (int i = 0; i < length1; i++) {
        temp[i] = array1[i];
    }
    free(array1);
    array1 = malloc(length2 * sizeof(int));
    for (int i = 0; i < length2; i++) {
        array1[i] = array2[i];
    }
    free(array2);
    array2 = malloc(length1 * sizeof(int));
    for (int i = 0; i < length1; i++) {
        array2[i] = temp[i];
    }
}

///Main function that handles IO.
int main(int argc, char *argv[]) {

    if (argc < 2) { //
        printf("Please input the file path!\n");
        return 0;
    }
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File invalid or doesn't exist\n");
        exit(0);
    }
    int rows = 0;
    const char delimiter[2] = ":,";
    int columns = 0;
    char *line = malloc(50 * sizeof(char));
    fscanf(fp, "%d", &rows);
    int columnsPerRow[rows];
    int *listArray[rows];
    fgets(line, 50, fp);
    for (int i = 0; i < rows; i++) {
        if (fgets(line, 50, fp) != NULL) {
            char *token = malloc(30 * sizeof(char));
            token = strtok(line, delimiter);
            removeSpaces(token, strlen(token));
            columns = atoi(token);
            columnsPerRow[i] = columns;
            listArray[i] = malloc(columns * sizeof(int));

            int count = 0;
            for (int c = 0; c < columns; c++) {
                token = strtok(NULL, delimiter);
                removeSpaces(token, strlen(token));
                listArray[i][count] = atoi(token);
                count++;
            }
        }
    }//end list creation
    fclose(fp);

    ///Input printing
    printf("Input:\n");
    for (int i = 0; i < rows; i++) {
        printf("| ");
        for (int j = 0; j < columnsPerRow[i]; j++) {
            printf("%d, ", listArray[i][j]);
        }
        printf("|\n");
    }

    //start row sorting

    for (int r = 0; r < rows; r++) {
        for (int i = 0; i < columnsPerRow[r] - 1; i++) {
            int min = i;

            for (int j = i + 1; j < columnsPerRow[r]; j++) {
                if (listArray[r][j] < listArray[r][min]) min = j;
            }
            swap(&listArray[r][min], &listArray[r][i]);
        }
    }

    //end row sorting

    //start per row length sorting

    for (int i = 0; i < rows - 1; i++) {
        int min = i;

        for (int j = i + 1; j < rows; j++) {
            if (columnsPerRow[j] < columnsPerRow[min]) min = j;
        }
        swapArrays(listArray[min], columnsPerRow[min], listArray[i], columnsPerRow[i]);
        swap(&columnsPerRow[min], &columnsPerRow[i]);
    }

    //end per row length sorting

    /// Output printing
    printf("\nOutput:\n");
    for (int i = 0; i < rows; i++) {
        printf("| ");
        for (int j = 0; j < columnsPerRow[i]; j++) {
            printf("%d, ", listArray[i][j]);
        }
        printf("|\n");
    }
    printf("\n--No runtime errors--\n");    ///DEBUG
    return 0;
}