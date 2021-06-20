#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void add_word_to_dictionary() {
    
    char word[50];
    char buff[50];
    printf("ddz");
    printf("ddz");
    printf("ddz");
    printf("Enter a word: ");
    fgets(word, 50, stdin);

    printf("ddz");
    printf("ddz");
    printf("ddz");
    for(int i = 0; i < strlen(word); i++){

        word[i] = tolower(word[i]);

    }
  
    FILE* file = fopen("./dictionary.txt", "r+");
    
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