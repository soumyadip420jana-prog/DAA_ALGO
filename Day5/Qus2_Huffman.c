#include <stdio.h>
#include <stdlib.h>

struct SYMBOL {
    char alphabet;
    int frequency;
    struct SYMBOL *left;
    struct SYMBOL *right;
};

struct SYMBOL* createNode(char ch, int freq) {
    struct SYMBOL *newNode;

    newNode = (struct SYMBOL*)malloc(sizeof(struct SYMBOL));

    newNode->alphabet = ch;
    newNode->frequency = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


void sort(struct SYMBOL *arr[], int n) {
    int i, j;
    struct SYMBOL *temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {

            if (arr[i]->frequency > arr[j]->frequency) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void inorder(struct SYMBOL *root) {

    if (root == NULL)
        return;

    inorder(root->left);

    if (root->alphabet != '#')
        printf("%c ", root->alphabet);

    inorder(root->right);
}

int main() {

    int n, i;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL *arr[100];

    char ch;
    int freq;

    printf("Enter the alphabets: ");

    for (i = 0; i < n; i++) {
        scanf(" %c", &ch);

        arr[i] = createNode(ch, 0);
    }

    printf("Enter its frequencies: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &freq);

        arr[i]->frequency = freq;
    }

   
    while (n > 1) {

       
        sort(arr, n);

   
        struct SYMBOL *left = arr[0];
        struct SYMBOL *right = arr[1];

   
        struct SYMBOL *newNode =
            createNode('#',
                       left->frequency + right->frequency);

        newNode->left = left;
        newNode->right = right;

    
        arr[0] = newNode;

        for (i = 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;
    }

    printf("\nIn-order traversal of the tree (Huffman): ");

    inorder(arr[0]);

    return 0;
}