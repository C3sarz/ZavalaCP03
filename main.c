
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

void removeSpaces(char * )

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
    char * line = malloc(30* sizeof(char));
    fscanf(fp, "%d", &rows);
    int * listArray[rows];
    fgets(line,30,fp);
    for(int i = 0;i<rows;i++){
        if(fgets(line,30,fp) != NULL) {
            char * token = malloc(30* sizeof(char));
            token = strtok(line, delimiter);
            while( token != NULL ) {
                printf( " %s\n", token );   //DEBUG------

                token = strtok(NULL, delimiter);
            }









        }
    }
    fclose(fp);
    printf("No errors");
    return 0;
    // 2d tut: https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
    //tokens: https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    //jagged arrays https://stackoverflow.com/questions/1083658/do-jagged-arrays-exist-in-c-c
}