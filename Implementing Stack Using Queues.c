#define INITIAL_CAPACITY 100

// Queue implementation using a circular dynamic array.
typedef struct {
    int *arr;
    int capacity;
    int head;   // index of the front element
    int tail;   // index for the next enqueue
    int size;   // current number of elements
} Queue;

// Create a new queue.
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = INITIAL_CAPACITY;
    q->arr = (int*)malloc(q->capacity * sizeof(int));
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return q;
}

// Free the memory used by the queue.
void freeQueue(Queue* q) {
    free(q->arr);
    free(q);
}

// Check if the queue is empty.
bool isEmptyQueue(Queue* q) {
    return (q->size == 0);
}

// Resize the queue's array when it is full.
void resizeQueue(Queue* q) {
    int newCapacity = q->capacity * 2;
    int* newArr = (int*)malloc(newCapacity * sizeof(int));
    // Copy elements in order.
    for (int i = 0; i < q->size; i++) {
        newArr[i] = q->arr[(q->head + i) % q->capacity];
    }
    free(q->arr);
    q->arr = newArr;
    q->capacity = newCapacity;
    q->head = 0;
    q->tail = q->size;
}

// Enqueue: add an element to the back of the queue.
void enqueue(Queue* q, int x) {
    if (q->size == q->capacity) {
        resizeQueue(q);
    }
    q->arr[q->tail] = x;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
}

// Dequeue: remove and return the element at the front of the queue.
int dequeue(Queue* q) {
    if (isEmptyQueue(q)) {
        return -1; // or handle underflow appropriately
    }
    int ret = q->arr[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return ret;
}

// Peek: get the front element without removing it.
int peekQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        return -1;
    }
    return q->arr[q->head];
}


// MyStack implementation using two queues.
typedef struct {
    Queue* q1;  // main queue holding elements in reverse order (top at front)
    Queue* q2;  // helper queue used during push
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q1 = createQueue();
    obj->q2 = createQueue();
    return obj;
}

// Push element x onto stack.
void myStackPush(MyStack* obj, int x) {
    // Enqueue the new element into q2.
    enqueue(obj->q2, x);
    
    // Transfer all elements from q1 to q2.
    while (!isEmptyQueue(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    
    // Swap q1 and q2.
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

// Removes the element on top of the stack and returns that element.
int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

// Get the top element.
int myStackTop(MyStack* obj) {
    return peekQueue(obj->q1);
}

// Returns whether the stack is empty.
bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(obj->q1);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->q1);
    freeQueue(obj->q2);
    free(obj);
}
