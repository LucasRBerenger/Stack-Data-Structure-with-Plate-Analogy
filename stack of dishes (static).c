#include <stdio.h>
#include <stdlib.h>

#define STACKMAX 5

typedef struct Stack{
    int dishes[STACKMAX];
    int top;
} Stack;

void init (Stack *kitchenTable){
    int i;
    for(i = 0; i< STACKMAX; i++){
        kitchenTable->dishes[i] = 0;
    }
    kitchenTable->top = 0;
}

void push (Stack *kitchenTable, int dish){
    if(kitchenTable->top == STACKMAX){
        printf("\nOUCH!!! You overloaded the stack and broke everything! Time for a cleanup...\n");
        exit(EXIT_SUCCESS);
    } else if(kitchenTable->top == STACKMAX - 1){
        printf("\nWhoa, the stack is full! Better wash some dishes before they come crashing down!\n");
        kitchenTable->dishes[kitchenTable->top] = dish;
        kitchenTable->top++;
        return;
    } else if(kitchenTable->top < STACKMAX - 1) {
        kitchenTable->dishes[kitchenTable->top] = dish;
        kitchenTable->top++;
        return;
    }
}

int pop (Stack *kitchenTable){
    if(kitchenTable->top == 0){
        printf("\nNo dishes here! This stack is emptier than a clean plate after dinner!\n");
        return -1;
    } else {
        printf("\nScrubbing the top dish... All clean!\n");
        kitchenTable->top--;
        return kitchenTable->dishes[kitchenTable->top];
    }    
}

void sPrint (Stack *kitchenTable){
    int i;
    if(kitchenTable->top == 0){
        printf("\nNothing to see here, just an empty stack!\n");
    } else {
        printf("\nHere are the dishes waiting for a scrub...\n");
        for (i = kitchenTable->top - 1; i >= 0; i--){
            printf("\nDish %d", kitchenTable->dishes[i]);
        }
    }
    printf("\n");
}

int main() {

    Stack kitchenTable;
    int option, dish;

    init(&kitchenTable);

    printf("Welcome to the kitchen! Ready to stack some dishes or wash them clean?\n");

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

