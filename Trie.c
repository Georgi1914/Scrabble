#include <stdio.h>
#include <stdlib.h>

struct node_t
{
    char c;
    int isWord;
    struct node_t *children[26];
};

char *word_taker(char *word)
{
}

struct node_t *get_node()
{
    struct node_t *new_node = malloc(sizeof(struct node_t)); 
  
    new_node->isWord = 0;
  
    for (int i = 0; i < 26; i++){
        new_node->children[i] = NULL;
    }
  
    return new_node;
}

void insert(struct node_t *root, char *word)
{
    struct node_t *curr = root;
    int letter_num;

    for (int i = 0; word[i] != '\0'; i++)
    {

        letter_num = word[i] - 'a';

        if(curr->children[letter_num] == NULL)
        {
            curr->children[letter_num] = get_node();
            curr->children[letter_num]->c = word[i];
            
        }

        curr = curr->children[letter_num];

    }

    curr->isWord = 1;

}

void print_trie(struct node_t *root)
{
    printf("%c", root->c);

    for (int i = 0; i < 26; i++)
    {

        if (root->children[i] != NULL)
        {

            printf("I = %d\n", i);
            print_trie(root->children[i]);

        }
    }
}
int main()
{
    struct node_t root = {'\0', 0};
    char word[] = "words";

    insert(&root, word);
    insert(&root, word);

    print_trie(&root);
    return 0;
}