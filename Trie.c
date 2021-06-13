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

void insert(struct node_t *root, char *word)
{
    struct node_t *new_node = malloc(sizeof(struct node_t));
    struct node_t *curr = root;
    int i = 0;
    char c;

    for (i = 0; word[i] != '\0'; i++)
    {
        c = word[i];
        int j = 0;
        printf("%d", curr->children[c - 'a'] == NULL);

        for (j = 0; j < 26; j++)
        {
            new_node->children[j] = NULL;
        }

        if (curr->children[c - 'a'] == NULL)
        {
            new_node->c = c;
            curr->children[c - 'a'] = new_node;
            curr->isWord = 0;
        }

        curr = curr->children[c - 'a'];
    }
    curr->isWord = 1;
}

void print_trie(struct node_t *root)
{

    int i = 0;

    printf("%c\n", root->c);
    for (i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            print_trie(root->children[i]);
        }
    }
}
int main()
{
    struct node_t root = {'\0', 0};
    char word[] = "words";

    insert(&root, word);
    print_trie(&root);
    return 0;
}