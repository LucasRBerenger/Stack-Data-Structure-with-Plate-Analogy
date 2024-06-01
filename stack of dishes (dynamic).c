#include <stdio.h>
#include <stdlib.h>

typedef struct Dish {
    int numberDish;
    struct Dish *nextDish;
} Dish;

typedef struct Stack{
    Dish *top;
} Stack;

void init (Stack *s){
    s->top = NULL;
}

void push (Stack *s, int numberDish){
    Dish *ptr = (Dish*)malloc(sizeof(Dish));
    if(ptr == NULL){
        printf("Dish alocation error.\n");
        return;
    } else {
        ptr->numberDish = numberDish;
        ptr->nextDish = s->top;
        s->top = ptr;
    }

}

int pop (Stack *s){
    Dish* aux = s->top;
    int numberDish;
    if (aux == NULL){
        printf("\nNo dishes here! This stack is emptier than a clean plate after dinner!\n");
        return -1;
    } else {
        printf("\nScrubbing the top dish... All clean!\n");
        s->top = aux->nextDish;
        aux->nextDish = NULL;
        numberDish = aux->numberDish;
        free(aux);
        return numberDish;
    }
}

void sPrint (Stack *s){
    Dish *ptr = s->top;
    if(ptr == NULL){
        printf("\nNothing to see here, just an empty stack!\n");
        return;
    } else {
        printf("\nHere are the dishes waiting for a scrub...\n");
        while (ptr != NULL){
            printf("\nDish %d", ptr->numberDish);
            ptr = ptr->nextDish;
        }
        printf("\n");
    }
}

int main() {

    Stack kitchenTable;
    int option, dish;

    init(&kitchenTable);

    printf("Welcome to our new kitchen! Ready to stack some dishes or wash them clean?\nDon't worry, now you can add as many dishes as you want in the stack!\n");

    do {
        printf("\n1 - Add dish\n2 - Wash dish\n3 - See dishes\n4 - Leave the kitchen\n\n");
        printf("What would you like to do? ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Which dish will you put? ");
            scanf("%d", &dish);
            push(&kitchenTable, dish);
            break;

        case 2:
            pop(&kitchenTable);
            break;

        case 3:
            sPrint(&kitchenTable);
            break;
        }
    } while (option != 4);

    printf("\nLeaving the kitchen already? Don't forget to turn off the dishwasher!\n");

    return 0;

}
