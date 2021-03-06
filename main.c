#include<stdio.h>
#include<stdlib.h>
#include"game.h"
#include"add_word_to_dic.h"

void settings(){
    FILE* file = fopen("./settings.bin", "rb+");

    int stngs[2];
    fread(stngs, sizeof(stngs[0]), 2, file);
    fclose(file);

    printf("Current settings:\n");
    printf("Rounds: %d\n", stngs[0]);
    printf("Letters: %d\n", stngs[1]);

    printf("\nChange settings?\n\n");
    printf("1. Yes\n");
    printf("2. No\n");

    unsigned int settings_option;
    scanf("%d", &settings_option);

    switch(settings_option){
        case 1:
            printf("Number of rounds: ");
            scanf("%d", &stngs[0]);
            printf("Number of letters: ");
            scanf("%d", &stngs[1]);
            fwrite(stngs, sizeof(stngs[0]), 2, file);
            break;
        case 2: break;
        default:
            printf("\nWrong input. Try again.\n\n");
            settings();
            break;
    }
    fclose(file);
}   

int main(){
    while(1){
        unsigned int option;

        printf("\nChoose an option:\n\n");
        printf("1. Start new game\n");
        printf("2. Settings\n");
        printf("3. Enter a new word\n");
        printf("4. Quit\n");

        scanf("%d", &option);
        getchar();
        switch(option){
            case 1:
                start_game();
                break;
            case 2:
                puts(""); 
                settings(); 
                break;
            case 3:
                puts(""); 
                add_word_to_dictionary();
                break;
            case 4: 
                printf("\nHave a nice day!");
                exit(0);
            default: 
                printf("\nWrong input. Try again.\n");
                break;
        }
    }
    return 0;
}