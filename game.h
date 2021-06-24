#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Trie.h"

void start_game(){
    srand(time(0));
    int stngs[2]; //stngs[0] is the number of rounds; stngs[1] is the number of letters per round
    char* letters = (char*)malloc(sizeof(char)*stngs[1]);
    char* word = (char*)malloc(sizeof(char)*stngs[1]);
    char letterBag[] = "AAAAAAAAABBCCDDDDEEEEEEEEEEEEFFGGGHHIIIIIIIIIJKLLLLMMNNNNNNOOOOOOOOPPQRRRRRRSSSSTTTTTTUUUUVVWWXYYZ";
    struct node_t root = init_trie();
    int points = 0;
    FILE* file = fopen("./settings.bin", "r");
    fread(stngs, sizeof(stngs[0]), 2, file);
    for(int round = 0; round < stngs[0]; round++){
    
        printf("Your letters: ");

        for(int i = 0; i < stngs[1]; i++){
            letters[i] = letterBag[rand() % strlen(letterBag)];
            printf("%c ", letters[i]);
        }
        puts("");
        do{
            scanf("%s", word);
            getchar();

            if(!is_valid(word, &root, letters)){
                printf("Invalid word. Try again!");
                break;
            }
        }while(!is_valid(word, &root, letters));
        printf("Valid - %d\n", is_valid(word, &root, letters));
        printf("Points for this word: %d\n", strlen(word));
        points += strlen(word);
        puts("\n");
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