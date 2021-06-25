#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Trie.h"

void start_game(){
    srand(time(0));
    int stngs[2]; //stngs[0] is the number of rounds; stngs[1] is the number of letters per round
    FILE* file = fopen("./settings.bin", "r");
    fread(stngs, sizeof(stngs[0]), 2, file);
    char* letters = (char*)malloc(sizeof(char)*stngs[1]);
    char* word = (char*)malloc(sizeof(char)*stngs[1]);
    struct node_t root = init_trie();
    int points = 0;
    int random;
    char letterBag[101];
    for(int round = 0; round < stngs[0]; round++){

        strcpy(letterBag, "AAAAAAAAABBCCDDDDEEEEEEEEEEEEFFGGGHHIIIIIIIIIJKLLLLMMNNNNNNOOOOOOOOPPQRRRRRRSSSSTTTTTTUUUUVVWWXYYZ##");
    
        printf("\nYour letters: ");

        for(int i = 0; i < stngs[1]; i++){
            do{
                random = rand() % strlen(letterBag);
            }while(letterBag[random] == '0');
            letters[i] = letterBag[random];
            letterBag[random] = '0';
            printf("%c ", letters[i]);
        }
        puts("");
        do{
            scanf("%s", word);
            getchar();

            if(!is_valid(word, &root, letters)){
                printf("Invalid word. Try again!\n");
            }
        }while(!is_valid(word, &root, letters));
        printf("Points for this word: %d\n", strlen(word));
        points += strlen(word);
    }

    printf("\nPoints for entire game: %d\n", points);

    int option;
        do{
            printf("Play again?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &option);
        }while(option != 1 && option != 2);
        if(option == 1){
            start_game();
        }
}