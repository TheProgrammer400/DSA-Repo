#include<stdio.h>
#include<stdlib.h>

void addChar(char **arr, char letter, int *index, int *capacity){
    (*arr)[(*index)++] = letter;
    (*capacity)++;

    /* have to write double pointer (**arr) as we are using 'realloc' in the function
    'realloc' changes the original pointer inside the function, 
    so the change won't be reflected in the main function */

    *arr = (char *)realloc(*arr, sizeof(char) * (*capacity));
    (*arr)[*index] = '\0';  // Ensure the string is null-terminated
}

int main(){
    char *arr;
    int capacity = 2;  // Start with space for one character + null terminator
    int index = 0;

    arr = (char *)malloc(sizeof(char) * capacity);
    arr[0] = '\0';  // Initialize with an empty string

    addChar(&arr, 'h', &index, &capacity);
    addChar(&arr, 'e', &index, &capacity);

    printf("%s\n", arr);
    free(arr);
    return 0;
}
