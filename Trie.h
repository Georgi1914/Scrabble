#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Structure initialization
struct node_t
{
    char c;
    int isWord;
    struct node_t *children[26];
};

// Getting word from file
void get_word(char *word, FILE *file)
{
    char ch = '\0';
    int i = 0;

    for (i = 0; ((ch = fgetc(file)) != EOF) && (ch != '\n'); i++)
    {
        word[i] = ch;
    }

    word[i] = '\0';
}

// Creating a new node by allocating memory
struct node_t *get_node()
{
    struct node_t *new_node = (struct node_t *)calloc(1, sizeof(struct node_t));

    new_node->isWord = 0;

    for (int i = 0; i < 26; i++)
    {
        new_node->children[i] = NULL;
    }

    return new_node;
}

// Inserting new node to the trie
void insert(struct node_t *root, char *dict)
{
    char word[100];
    struct node_t *curr = root;
    int letter_num;
    int j = 0;

    FILE *file = fopen(dict, "r");
    rewind(file);

    while (!feof(file))
    {

        get_word(word, file);

        for (int i = 0; word[i] != '\0'; i++)
        {
            letter_num = word[i] - 'a';

            if (curr->children[letter_num] == NULL)
            {
                curr->children[letter_num] = get_node();
                curr->children[letter_num]->c = word[i];
            }

            curr = curr->children[letter_num];
        }
        curr->isWord = 1;
    }

    fclose(file);
}

// Printing the trie
void print_trie(struct node_t *root)
{

    if (root == NULL)
    {
        printf("The trie is empty!");
        return;
    }

    printf("%c", root->c);

    if (root->isWord)
    {
        printf("\n");
    }

    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            print_trie(root->children[i]);
        }
    }
}

int is_empty(struct node_t *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
            return 0;
    }
    return 1;
}

// Clearing the allocated memory
void clear(struct node_t *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            clear(root->children[i]);
        }
    }

    if (is_empty(root))
    {
        free(root);
    }
}

// Word validation
int is_valid(char *word, struct node_t *root, char *letters){
    for(int i = 0; i < strlen(letters) - 1; i++){
        letters[i] = tolower(letters[i]);
    }

    for(int i = 0; i < strlen(word); i++){
        int ok = 0;
        printf("I: %d\n", i);
        for(int j = 0; j < strlen(letters); j++){
            //printf("word = %c\nletter = %c\n", word[i], letters[i]);
            if(word[i] == letters[j]){
                printf("J == %d\n", j);
                ok = 1;
                letters[j] = '0';
                break;
            }
        }
        printf("letter: %c\n", word[i]);
        if(ok == 0){
            printf("Invalid letter: %c", word[i]);
            return 0;
        }
    }
    printf("valid word");
    return 1;

    // int length = strlen(word);
    // struct node_t *curr = root;
  
    // for (int i = 0; i < length; i++)
    // {
    //     int index = word[i] - 'a';

    //     if (!curr->children[index]){
    //         return 1;
    //     }
        
    //     curr = curr->children[index];
    // }

    // return curr->isWord;

    // if(!root){
    //     return 0;
    // }
    
    // struct node_t *curr = root;
    
    // for(int i = 0; i < strlen(word); i++){
        
    //     int index = word[i] - 'a';
    //     curr = curr->children[index];

    //     if(curr->c != word[i]){
    //         return 0;
    //     }
    //     printf("ddzbrat\n");
    // }

    // if(curr->isWord){
    //     return 1;
    // }

    // return 0;
}


struct node_t init_trie()
{
    struct node_t root = {'\0', 0};

    insert(&root, "./dictionary.txt");

    //print_trie(&root);
    //clear(&root);

    return root;
}