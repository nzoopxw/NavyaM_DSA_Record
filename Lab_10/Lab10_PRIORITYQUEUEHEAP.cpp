// PROGRAM TO IMPLEMENT PRIORITY QUEUE USING MAX HEAP 
#include<cstdio>
#include<cstdlib>
#define MAX_CAP 100 // MAXIMUM CAPACITY OF THE HEAP

class maxheap {
    private:
        int heap[MAX_CAP]; // ARRAY REPRESENTATION OF THE HEAP
        int size, capacity; // SIZE TRACKS THE NUMBER OF ELEMENTS, CAPACITY IS FIXED
    public:
        maxheap(int cap) {
            size = 0;
            capacity = cap;
        }
        void insert(int val); // FUNCTION TO INSERT AN ELEMENT INTO THE HEAP
        void deletemax(); // FUNCTION TO DELETE THE MAXIMUM ELEMENT (ROOT)
        void display(); // FUNCTION TO DISPLAY THE HEAP
        void search(int val); // FUNCTION TO SEARCH FOR AN ELEMENT IN THE HEAP
        void heapsort(); // FUNCTION TO PERFORM HEAP SORT
};

int main() {
    maxheap pqh(MAX_CAP); // CREATING A MAX HEAP WITH A DEFINED CAPACITY
    int choice, value;

    do {
        printf("MENU\n1. INSERT\n2. DELETE\n3. DISPLAY\n4. SEARCH\n5. SORT (HEAP SORT)\n6. EXIT\n");
        printf("ENTER CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ENTER VALUE: ");
                scanf("%d", &value);
                pqh.insert(value);
                break;
            case 2:
                pqh.deletemax();
                break;
            case 3:
                pqh.display();
                break;
            case 4:
                printf("ENTER VALUE TO SEARCH: ");
                scanf("%d", &value);
                pqh.search(value);
                break;
            case 5:
                pqh.heapsort();
                break;
            case 6:
                printf("EXITED SUCCESSFULLY :) \n");
                break;
            default:
                printf("INVALID CHOICE!\n");
        }
    } while (choice != 6);
    
    return 0;
}

// FUNCTION TO INSERT AN ELEMENT INTO THE MAX HEAP
void maxheap :: insert(int val) {
    if(size == capacity) {
        printf("HEAP IS FULL \n");
        return;
    }
    int i = size;
    heap[size++] = val;
    // HEAPIFY UP TO MAINTAIN MAX HEAP PROPERTY
    while(i > 0 && heap[(i-1)/2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

// FUNCTION TO DELETE THE MAXIMUM ELEMENT (ROOT) FROM THE HEAP
void maxheap :: deletemax() {
    if(size == 0) {
        printf("THE HEAP IS EMPTY \n");
        return;
    }
    heap[0] = heap[size-1];
    size--;
    int i = 0, j;
    // HEAPIFY DOWN TO MAINTAIN MAX HEAP PROPERTY
    while(true) {
        j = 2*i + 1; // LEFT CHILD INDEX
        if(j >= size) break;
        if(j+1 < size && heap[j] < heap[j+1]) {
            j = j + 1; // SELECT THE LARGER CHILD
        }
        if(heap[i] < heap[j]) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
        } else {
            break;
        }
    }
}

// FUNCTION TO DISPLAY THE HEAP ELEMENTS
void maxheap :: display() {
    if(size == 0) {
        printf("HEAP IS EMPTY NOTHING TO DISPLAY \n");
        return;
    }
    for(int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// FUNCTION TO SEARCH FOR AN ELEMENT IN THE HEAP
void maxheap :: search(int val) {
    if(size == 0) {
        printf("THE HEAP IS EMPTY \n");
        return;
    }
    for(int i = 0; i < size; i++) {
        if(val == heap[i]) {
            printf("ELEMENT FOUND \n");
            return;
        }
    }
    printf("ELEMENT NOT FOUND \n");
}

// FUNCTION TO PERFORM HEAP SORT
void maxheap :: heapsort() {
    if(size == 0) {
        printf("THE HEAP IS EMPTY \n");
        return;
    }
    int tempHeap[MAX_CAP];
    int tempSize = size;
    // COPY ELEMENTS TO PRESERVE THE ORIGINAL HEAP
    for(int i = 0; i < tempSize; i++) {
        tempHeap[i] = heap[i];
    }
    // HEAP SORT PROCESS
    for (int i = tempSize - 1; i > 0; i--) {
        int temp = tempHeap[0];
        tempHeap[0] = tempHeap[i];
        tempHeap[i] = temp;
        
        int j = 0, index;
        do {
            index = 2 * j + 1;
            if (index < i - 1 && tempHeap[index] < tempHeap[index + 1])
                index++;
            if (index < i && tempHeap[j] < tempHeap[index]) {
                temp = tempHeap[j];
                tempHeap[j] = tempHeap[index];
                tempHeap[index] = temp;
                j = index;
            } else {
                break;
            }
        } while (index < i);
    } 
    // DISPLAY SORTED ELEMENTS
    printf("HEAP SORTED:\n");
    for (int i = 0; i < tempSize; i++) {
        printf("%d ", tempHeap[i]);
    }
    printf("\n");  
}
