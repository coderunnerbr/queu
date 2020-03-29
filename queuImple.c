#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} node;

typedef struct Queu {
    struct Node* begining;
    struct Node* end;
} queu;

node* createNode(int value) {
    node* newNode;

    newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

queu* createQueu(){
    queu* newQueu;

    newQueu = malloc(sizeof(queu));
    newQueu->begining = NULL;
    newQueu->end = NULL;

    return newQueu;
}

void destroyQueu(queu* myQueu) {
    node *firstNode = myQueu->begining;

    while(firstNode->next != NULL){
        node *auxNode = firstNode;
        firstNode = firstNode->next;
        free(auxNode);
    }

    myQueu->begining = NULL;
    myQueu->end = NULL;

    free(firstNode);
    free(myQueu);
}

void addNode(queu* myQueu, int value){
    node *newNode = createNode(value);

    if(myQueu->begining == NULL){
        myQueu->begining = newNode;
        myQueu->end = myQueu->begining;
    }else{
       myQueu->end->next = newNode;
       myQueu->end = myQueu->end->next;
    }
}

void removeNode(queu* myQueu) {
    if(myQueu->begining != NULL) {
        node *erasedNode = myQueu->begining;
        myQueu->begining = myQueu->begining->next;
        erasedNode->next = NULL;
        free(erasedNode);
    }
}

void printQueu(queu* myQueu) {
    node* auxNode = myQueu->begining;

    if(auxNode == NULL)
        printf("Fila Vazia");
    else{
        while(auxNode != NULL) {
            printf("%d ", auxNode->value);
            auxNode = auxNode->next;
        }
    }

    printf("\n");
}

int main() {
    return 0;
}
