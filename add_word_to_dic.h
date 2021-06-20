#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_word_to_dictionary() {
    
    char word[50];
    char buff[50];
    printf("Enter a word: ");
    fgets(word, 50, stdin);
  
    FILE* file = fopen("./dictionary.txt", "r+");
    if(file == NULL) puts("nebaca");
    while (fgets(buff, 50, file) != NULL) {

        if(!strcmp(buff, word)){
            printf("The word already exists in the dictionary!\n");
            return;
        }
    }

    if (file != NULL) {
        fputs(word, file);
        //fputs("\n", file);
        printf("Successfully added the word!\n");
    }
    else {
        printf("Failed to open the file\n");
    }
    fclose(file); 
}