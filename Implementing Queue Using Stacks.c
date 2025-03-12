#define INITIAL_CAPACITY 100

// Definition of a simple stack using a dynamic array.
typedef struct {
    int *arr;
    int capacity;
    int top; // index of the top element (-1 if empty)
} Stack;

// Creates a new stack.
Stack* createStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = INITIAL_CAPACITY;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Frees the stack.
void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

// Returns true if the stack is empty.
bool isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

// Pushes an element x onto the stack.
void pushStack(Stack* stack, int x) {
    if(stack->top + 1 == stack->capacity) {
        // Expand capacity if needed.
        stack->capacity *= 2;
        stack->arr = (int*)realloc(stack->arr, stack->capacity * sizeof(int));
    }
    stack->arr[++stack->top] = x;
}

// Pops the top element from the stack and returns it.
int popStack(Stack* stack) {
    if(isEmptyStack(stack)) {
        // Ideally, you should handle the error case.
        return -1;
    }
    return stack->arr[stack->top--];
}

// Returns the top element of the stack without removing it.
int peekStack(Stack* stack) {
    if(isEmptyStack(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

// Definition of MyQueue that uses two stacks.
typedef struct {
    Stack* stack_in;   // For push operations.
    Stack* stack_out;  // For pop and peek operations.
} MyQueue;

// Creates a new MyQueue.
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack_in = createStack();
    queue->stack_out = createStack();
    return queue;
}

// Pushes element x to the back of the queue.
void myQueuePush(MyQueue* obj, int x) {
    pushStack(obj->stack_in, x);
}

// Removes the element from the front of the queue and returns it.
int myQueuePop(MyQueue* obj) {
    // If stack_out is empty, transfer all elements from stack_in.
    if (isEmptyStack(obj->stack_out)) {
        while (!isEmptyStack(obj->stack_in)) {
            int x = popStack(obj->stack_in);
            pushStack(obj->stack_out, x);
        }
    }
    return popStack(obj->stack_out);
}

// Returns the element at the front of the queue.
int myQueuePeek(MyQueue* obj) {
    // If stack_out is empty, transfer all elements from stack_in.
    if (isEmptyStack(obj->stack_out)) {
        while (!isEmptyStack(obj->stack_in)) {
            int x = popStack(obj->stack_in);
            pushStack(obj->stack_out, x);
        }
    }
    return peekStack(obj->stack_out);
}

// Returns true if the queue is empty, false otherwise.
bool myQueueEmpty(MyQueue* obj) {
    return isEmptyStack(obj->stack_in) && isEmptyStack(obj->stack_out);
}

// Frees the memory allocated for MyQueue.
void myQueueFree(MyQueue* obj) {
    freeStack(obj->stack_in);
    freeStack(obj->stack_out);
    free(obj);
}
