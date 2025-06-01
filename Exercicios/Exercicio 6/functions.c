#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/*REFERENCE
https://www.baeldung.com/cs/quicksort-vs-heapsort
https://pt.wikipedia.org/wiki/Quicksort#Pseudoc%C3%B3digo
https://en.wikipedia.org/wiki/Heapsort#Pseudocode
https://pt.wikipedia.org/wiki/Heapsort#/media/Ficheiro:Heapsort-example.gif
https://en.wikipedia.org/wiki/Tower_of_Hanoi#Recursive_solution
*/

/*General algorithm idea (Recurive Quick sort):
Choose a pivot element (could be any, in this we are choosing the first element)
Then, reorganize the array such as elements smaller than the pivot goes to the right and bigger to the left
Repeat the same process at the right and left arrays
At the end, just add up right + same + left arrays to have the completed sorted array
"Left" : Numbers smaller than pivot number
"Same" : Numbers equal to pivot number
"Right" : Numbers bigger than pivot number

Example:
Suppose we have the following array:
Array: [4, 3, 1, 2, 5]  ->  Pivot chosen = 4
Left: [3, 1, 2] - Same: [4] - Right: [5]
Quicksort left(*1l) and right(*1r): Left: [1, 2, 3] - Same: [4] - Right: [5]
Add them together -> Sorted Array: [1, 2, 3, 4, 5]
    *1l) Array: [3, 1, 2]  ->  Pivot chosen = 3
    Left: [1, 2] - Same: [3] - Right: []
    Quicksort left(*1ll): Left: [1, 2] - Same: [3] - Right: []
    Add them together -> Sorted Array: [1, 2, 3]
        *1ll) Array: [1, 2] -> Pivot chosen = 1
        Left:[] - Same: [1] - Right: [2]
        Quicksort right(*1llr): Left: [] - Same: [1] - Right: [2]
        Add them together -> Sorted Array: [1, 2]
            *1llr) Array: [2] -> Sorted Array: [2]
    *1r) Array: [5] -> Sorted Array: [5]

OBS.: Since the problem wont have disks with the same weight, we wont be needing the "Same" Array
*/

int* recursiveDistinctQuicksort(int* numbers, int size){
    if(DEBUG_QUICKSORT) printf("=Quicksort Start!=");
    int* returnValue = recursiveDistinctQuicksortInternal(numbers, size, 0);
    if(DEBUG_QUICKSORT) printf("=Quicksort Finish!=");
    return returnValue;
}

int* recursiveDistinctQuicksortInternal(int* numbers, int size, int depth){
    if (size <= 1) {                                    // Stop condition: if the array has 1 or 0 elements, it's already sorted
        if(DEBUG_QUICKSORT) printf("Number %d sorted!\n", numbers[0]);
        return numbers;
    }
    int pivot = numbers[0];                             // Pivot element (first element)
    int* left = (int*)malloc(sizeof(int) * size);       // Alloc memory for the left array
    int* right = (int*)malloc(sizeof(int) * size);      // Alloc memory for the right array
    if(left == NULL || right == NULL){
        if(DEBUG_MEMORY) printf("Quicksort: Memory Allocation failed!");
        return NULL;
    }
    int leftSize = 0;                                   // Size of the left array
    int rightSize = 0;                                  // Size of the right array

    if(DEBUG_QUICKSORT) printf("Array (depth = %d): ", depth);
    if(DEBUG_QUICKSORT) for(int i = 0; i < size; i++) printf("%d ", numbers[i]);
    if(DEBUG_QUICKSORT) printf("-> Pivot chosen: %d\n", pivot);

    for (int i = 1; i < size; i++) {                    // Divide the array into left and right arrays (not include pivot, i != 0)
        if (numbers[i] < pivot) {                       // Smaller at left
            left[leftSize++] = numbers[i];              // Increment leftSize as it makes the array
        } else if (numbers[i] > pivot) {
            right[rightSize++] = numbers[i];            // Same for right side
        }
    }

    if(DEBUG_QUICKSORT) printf("Left: ");
    if(DEBUG_QUICKSORT) for(int i = 0; i < leftSize; i++) printf("%d ", left[i]);
    if(DEBUG_QUICKSORT) printf("Right: ");
    if(DEBUG_QUICKSORT) for(int i = 0; i < rightSize; i++) printf("%d ", right[i]);

    if(DEBUG_QUICKSORT) printf("\nSorting left:\n");
    left = recursiveDistinctQuicksortInternal(left, leftSize, depth+1);              // Recursively sort the left array
    if(DEBUG_QUICKSORT) printf("Sorting right:\n");
    right = recursiveDistinctQuicksortInternal(right, rightSize, depth+1);           // Recursively sort the right array

    for (int i = 0; i < leftSize; i++) {                // Copy the sorted left array back to the original array
        numbers[i] = left[i];
    }
    numbers[leftSize] = pivot;                          // Insert the pivot element in the middle
    for (int i = 0; i < rightSize; i++) {               // Copy the sorted right array back to the original array
        numbers[leftSize + 1 + i] = right[i];
    }

    free(left);                                         // Free memory
    free(right);

    return numbers;
}

/*BROKEN
int* recursiveHeapsort(int* numbers, int size){
    for (int i = size / 2 - 1; i >= 0; i--) {           // Build the heap
        heapify(numbers, size, i);
    }
    for (int i = size - 1; i > 0; i--) {                // Extract elements from the heap
        swap(&numbers[0], &numbers[i]);
        heapify(numbers, i, 0);
    }
    return numbers;
}

void heapify(int* numbers, int size, int i) {
    int largest = i;                                    // Initialize largest as root
    int left = 2 * i + 1;                               // left child index
    int right = 2 * i + 2;                              // right child index

    if (left < size && numbers[left] > numbers[largest]) {      // If left child is larger than root
        largest = left;
    }
    if (right < size && numbers[right] > numbers[largest]) {    // If right child is larger than largest so far
        largest = right;
    }
    if (largest != i) {                                 // If largest is not root
        swap(&numbers[i], &numbers[largest]);           // Swap root with largest
        heapify(numbers, size, largest);                // Recursively heapify the affected sub-tree
    }
}

void swap(int* a, int* b) {
    int temp = *a;                                      // Swap the values of a and b
    *a = *b;
    *b = temp;
}*/

Tower createEmptyTower(char towerName, int maxSize) {
    Tower tower = {
        .disk = malloc(sizeof(int) * maxSize),      //Allocs the array
        .size = 0,                                  //Default to 0
        .maxSize = maxSize,
        .name = towerName
    };
    if(tower.disk == NULL && DEBUG_MEMORY) printf("CreateEmptyTower: Memory Allocation failed!");
    for(int i = 0; i < maxSize; i++) {
        tower.disk[i] = -1;                         //Array starts empty (-1)
    }
    return tower;
}
void freeTower(Tower *tower){
    free(tower->disk);
}

int shiftRight(Tower* tower){
    for(int i = (tower->maxSize)-2; i >= 0; i--){
        tower->disk[i+1] = tower->disk[i];          //Moves every element to the right, last element is lost
    }
    tower->disk[0] = -1;                            //First slot becomes empty (-1)
    if(DEBUG_MOVEDISK) printf("  shiftRight (%c)*: successful\n", tower->name);
    return 0;
}
int shiftLeft(Tower* tower){
    for(int i = 0; i < (tower->maxSize)-1; i++){
        tower->disk[i] = tower->disk[i+1];          //Moves every element to the left, first element is lost
    }
    tower->disk[(tower->maxSize)-1] = -1;           //Last slot becomes empty (-1)
    if(DEBUG_MOVEDISK) printf("  shiftLeft (%c)*: successful\n", tower->name);
    return 0;
}

int MoveDisk(Tower* towerFrom, Tower* towerTo){
    if(DEBUG_MOVEDISK) printf("MoveDisk: from %c to %c\n", towerFrom->name, towerTo->name);
    if(towerFrom->size < 1 || towerTo->size == towerTo->maxSize){
        if(DEBUG_MOVEDISK) printf("MoveDisk*: invalid movement (Source empty/Destination full)\n");
        return 1;                                   //ERROR 1: towerFrom empty or towerTo full
    }
    shiftRight(towerTo);                            //Moves to create space for the new top disk
    towerTo->disk[0] = towerFrom->disk[0];          //Copy the new disk to the destination
    shiftLeft(towerFrom);                           //Erase the disk at the origin
    towerFrom->size--;                              //Update new sizes
    towerTo->size++;
    if(DEBUG_MOVEDISK) printf("MoveDisk*: Disk moved successfully\n");
    return 0;
}


/*General algorithm idea (Recursive Hanoi tower):
We start with three towers: A (contains the disks), B (empty, intermediary/temp), C (empty, target)
In the recursive algorithm, to move the tower from A to C, the target goal is to move the last disk (the heaviest), to C
So we first move the smaller tower A1 to the tower B, then we move the largest disk to the C
But moving the A1 tower to B is the same algorithm, where A1 is the starting point, B is the target, and C could be used as temp
Since C is always recursively receiving the heaviest disks, it wont affect the A1,...,An tower moves

Example:
Suppose we have the following towers
A:  1 2 4 6   (Start)
B:  _ _ _ _   (Temp)
C:  _ _ _ _   (Target)
> Objective: move the disk 6 (the heaviest), from A to C
    To do so, we need to first move the disks 4 2 1 from A to B (note that its the same algorithm, but now the roles of B and C switched) (*)
    A: [1 2 4] 6 (Start)
    B: [_ _ _] _ (Target)
    C: [_ _ _] _ (Temp)
    Note that we are fixing 6 in place, and now we want to move the tower A to B, using C as temp
        >Objective: move the disk 4 (the heaviest), from A to B
            (... and the recursion goes on)
After that we can finally move disk 6:
A:  6 _ _ _   (Start)           A:  [_ _ _] _   (Start)
B:  1 2 4 _   (Temp)    --->    B:  [1 2 4] _   (Temp)
C:  _ _ _ _   (Target)          C:  6 [_ _ _]  (Target)
After that, we need to move the smaller tower B, from B to C, the same idea as (*)
A:  _ _ _ _   (Start)
B:  _ _ _ _   (Temp)
C:  6 4 2 1   (Target)
*/
int recursiveSolve(Tower* towerFrom, Tower* towerTemp, Tower* towerTo, int size, int* movements){
    if(DEBUG_HANOI) printf("=Solving Hanoi Tower for %c, %c, %c=\n", towerFrom->name,towerTemp->name,towerTo->name);
    int returnValue = recursiveSolveInternal(towerFrom, towerTemp, towerTo, size, movements);
    if(DEBUG_HANOI) printf("=Hanoi Tower Solved!=\nresult:\n");
    if(DEBUG_HANOI) printTowersABC(*towerFrom, *towerTemp, *towerTo);
    return returnValue;
}

int recursiveSolveInternal(Tower* towerFrom, Tower* towerTemp, Tower* towerTo, int size, int* movements){
    if(size == 0) return 0;
    recursiveSolveInternal(towerFrom, towerTo, towerTemp, size-1, movements);               //Move smaller (n-1) tower to temp
    MoveDisk(towerFrom, towerTo);                                                           //Move the largest Disk to end

    printf("-MOVEMENT %d: (%c -> %c)-\n", ++(*movements), towerFrom->name, towerTo->name);  //Print the movement, and add to the counter
    if(DEBUG_HANOI) printTowersABC(*towerFrom, *towerTemp, *towerTo);
    if(DEBUG_HANOI) printf("\n");

    recursiveSolveInternal(towerTemp, towerFrom, towerTo, size-1, movements);      //Move smaller (n-1) tower to end
    return 0;
}

int printTower(Tower tower, char towerName){
    /* Old printing method (empty <- smallest <- largest| Tower x)
    (Bad for bigger towers or weights of 2 digits)
    printf(" ");
    for(int i = 0; i < tower.maxSize; i++){
        if(tower.disk[i] == -1)
            printf(" _");
    }
    for(int i = 0; i < tower.maxSize; i++){
        if(tower.disk[i] != -1)
            printf(" %d", tower.disk[i]);
    }
    printf("| Tower %c\n", towerName);

    return 0;
    */

    //New printing method (Tower x: |Largest -> smallest -> empty, oposite of array order)
    printf("Tower %c: |", towerName);           //Prints tower name
    for(int i = tower.maxSize-1; i >= 0; i--){
        if(tower.disk[i] != -1)
            printf("%d ", tower.disk[i]);       //Prints values from largest to smallest
    }
    for(int i = 0; i < tower.maxSize; i++){
        if(tower.disk[i] == -1)
            printf("_ ");                       //Print empty spaces
    }
    printf("\n");
    return 0;

}

int printTowersABC(Tower A, Tower B, Tower C){
    //Obs.: This is done because the towers to,temp,from are mixed up in the recursiveSolve
    //So Tower A, B, C, not necessarily means that their identity (.name) are A, B, C respectively
    if('A' == A.name) printTower(A, A.name);
    else if('A' == B.name) printTower(B, B.name);
    else if('A' == C.name) printTower(C, C.name);
    if('B' == A.name) printTower(A, A.name);
    else if('B' == B.name) printTower(B, B.name);
    else if('B' == C.name) printTower(C, C.name);
    if('C' == A.name) printTower(A, A.name);
    else if('C' == B.name) printTower(B, B.name);
    else if('C' == C.name) printTower(C, C.name);
    
    return 0;
}