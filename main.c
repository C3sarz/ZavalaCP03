
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
    int columns = 0;
    char * line[32];
    fscanf(fp, "%d", &rows);
    for(int i = 0;i<rows;i++){
        if(fscanf(fp, "%s", line) != EOF) {
            token = strtok(str, s);








        }
    }
    fclose(fp);
    return 0;
    // 2d tut: https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
    //tokens: https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
}