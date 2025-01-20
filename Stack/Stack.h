#include <stdlib.h>
#include <stdbool.h>

/*Stack structure*/
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;


/*Double type structure*/
typedef struct {
    bool bool_v;
    int int_v;
} Dtype;

const 
/*Stack creation happens here*/
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL || capacity <= 0) {
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(capacity * sizeof(int));
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    return stack;
}

/*returns true if stack is empty*/
bool isEmpty(const Stack* stack) {
    return stack->top == -1;
}

/*returns true if stack is full*/
bool isFull(const Stack* stack) {
    return stack->top == (stack->capacity) - 1;
}

/*returns true if put is success*/
bool put(Stack* stack, int data) {
    if (stack == NULL || isFull(stack))
        return false;
    stack->data[++(stack->top)] = data;
    return true;
}

/*returns true and popped element if pop is success*/
Dtype pop(Stack* stack) {
    Dtype res;
    if (stack == NULL || isEmpty(stack)) {
        res.bool_v = false;
        res.int_v = -1;
        return res;
    }
    res.bool_v = true;
    res.int_v = stack->data[(stack->top)--];
    return res;
}

/*return true top element if top function is success*/
Dtype top(const Stack* stack) {
    Dtype res;
    if (stack == NULL || isEmpty(stack)) {
        res.bool_v = false;
        res.int_v = -1;
        return res;
    }
    res.bool_v = true;
    res.int_v = stack->data[stack->top];
    return res;
}

/*returns true and index of the element if success*/
Dtype search(const Stack* stack, int data) {
    Dtype res;
    if (stack == NULL || isEmpty(stack)) {
        res.bool_v = false;
        res.int_v = -1;
        return res;
    }
    for (int i = 0; i <= stack->top; i++) {
        if (data == stack->data[i]) {
            res.bool_v = true;
            res.int_v = i;
            return res;
        }
    }
    res.bool_v = false;
    res.int_v = -1;
    return res;
}

/*returns the element at the index*/
int *select(const Stack *stack, int index)
{
    if (stack == NULL || index < 0 || index > stack->top) {
        return NULL;
    }
    return &stack->data[index];
}

/*frees memory after completion*/
void destroyStack(Stack* stack) {
    if (stack != NULL) {
        free(stack->data);
        free(stack);
    }
}