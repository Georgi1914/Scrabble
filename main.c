#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void menu(int option){
    printf("Choose an option:\n");
    printf("1. Start new game\n");
    printf("2. Settings\n");
    printf("3. Enter a new word\n");
    printf("4. Quit\n");

    scanf("%d", &option);

    switch(option){
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: 
            printf("\nHave a nice day!");
            exit(0);
        default: 
            printf("\nWrong input. Try again.");
            menu(option);
            break;
    }
}

int main(){

    unsigned int option;
    menu(option);
  
    return 0;
}