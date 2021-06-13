#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void start_game(){
    srand(time(0));
    FILE* file = fopen("./settings.bin", "r");
    int stngs[2];
    fread(stngs, sizeof(stngs[0]), 2, file);
    char* letters = (char*)malloc(sizeof(char)*stngs[1]);
    for(int round = 0; round < stngs[0]; round++){
    
        printf("Your letters:");

        for(int i = 0; i < stngs[1]; i++){
            letters[i] = (rand() % ('z' - 'a' + 1)) + 'a';
            printf("%c ", letters[i]);
        }

        //GO60
        

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
}