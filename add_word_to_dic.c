#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_t
{
  char* name;
  struct node_t* right; 
  struct node_t* left; 
};

// void WriteToFile(char* file_name, struct node_t** binary_tree)
// {
//   FILE* file;
//    if (fopen_s(&file, file_name, "w") != 0)
//    {
//      puts("failure\n");
//    }
//    else
//    {
//     WriteNodes(file, binary_tree);
//     fclose(file);
//    }
// }

// void WriteNodes(FILE* file, struct node_t** binary_tree)
// {
//   if(binary_tree != NULL)
//    {
//     WriteNodes(file, &(*binary_tree)->left);
//     //fprintf(file,"%s %d\n",(*binary_tree)->surname,(*binary_tree)->ID_student);
//     WriteNodes(file,&(*binary_tree)->right);
//    }
// }

// // void export(struct node_t* root) {
// //     FILE* fp;
// //     fp = fopen("Names.txt", "w");
// //     export_recursive(fp, root);
// //     fclose(fp);
// // }

// // void export_recursive(FILE* fp, struct node_t* root) {
// //     if (root != NULL) {
// //         export_recursive(fp, root->left);
// //         fprintf(fp,root->Emp);
// //         export_recursive(fp, root->right);
// //     }
// // }


void add_word_to_dictionary() {
    
    char word[50];
    char buff[50];
    printf("Enter a word: ");
    fgets(word, 50, stdin);
  
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

int main() {
    add_word_to_dictionary();
}

//spisuk s dannite na txt file
// vruzkite na tezi danni na drug/sushtiq txt file