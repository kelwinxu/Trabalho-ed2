#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/*REFERENCE
https://www.baeldung.com/cs/quicksort-vs-heapsort
https://pt.wikipedia.org/wiki/Quicksort#Pseudoc%C3%B3digo
https://pt.wikipedia.org/wiki/Heapsort#Implementa%C3%A7%C3%A3o_em_C
https://pt.wikipedia.org/wiki/Heapsort#/media/Ficheiro:Heapsort-example.gif
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
    if (size <= 1) {                                    // Stop condition: if the array has 1 or 0 elements, it's already sorted
        return numbers;
    }
    int pivot = numbers[0];                             // Pivot element (first element)
    int* left = (int*)malloc(sizeof(int) * size);       // Alloc memory for the left array
    int* right = (int*)malloc(sizeof(int) * size);      // Alloc memory for the right array
    int leftSize = 0;                                   // Size of the left array
    int rightSize = 0;                                  // Size of the right array

    for (int i = 0; i < size; i++) {                    // Divide the array into left and right arrays
        if (numbers[i] < pivot) {                       // Smaller at left
            left[leftSize++] = numbers[i];              // Increment leftSize as it makes the array
        } else if (numbers[i] > pivot) {
            right[rightSize++] = numbers[i];            // Same for right side
        }
    }

    left = recursiveDistinctQuicksort(left, leftSize);              // Recursively sort the left array
    right = recursiveDistinctQuicksort(right, rightSize);           // Recursively sort the right array

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

int shiftRight(Tower* tower){
    for(int i = (tower->maxSize)-2; i >= 0; i--){
        tower->disk[i+1] = tower->disk[i];
    }
    tower->disk[0] = -1;
    if(DEBUG) printf("  shiftRight (%c)*: successful\n", tower->name);
    return 0;
}
int shiftLeft(Tower* tower){
    for(int i = 0; i < (tower->maxSize)-1; i++){
        tower->disk[i] = tower->disk[i+1];
    }
    tower->disk[(tower->maxSize)-1] = -1;
    if(DEBUG) printf("  shiftLeft (%c)*: successful\n", tower->name);
    return 0;
}

int MoveDisk(Tower* towerFrom, Tower* towerTo){
    if(DEBUG) printf("MoveDisk: from %c to %c\n", towerFrom->name, towerTo->name);
    if(towerFrom->size < 1 || towerTo->size == towerTo->maxSize){
        if(DEBUG) printf("MoveDisk*: invalid movement (Source empty/Destination full)\n");
        return 1;                                   //towerFrom empty or towerTo full
    }
    shiftRight(towerTo);                            //Moves to create space for the new top disk
    towerTo->disk[0] = towerFrom->disk[0];          //Copy the new disk to the destination
    shiftLeft(towerFrom);                           //Erase the disk at the origin
    towerFrom->size--;                              //Update sizes
    towerTo->size++;
    if(DEBUG) printf("MoveDisk*: Disk moved successfully\n");
    return 0;
}

int recursiveSolve(Tower* towerFrom, Tower* towerTemp, Tower* towerTo, int size, int* movements){
    if(size == 0) return 0;
    recursiveSolve(towerFrom, towerTo, towerTemp, size-1, movements);      //Move smaller (n-1) tower to temp
    MoveDisk(towerFrom, towerTo);                                          //Move the largest Disk to end
    printf("-MOVEMENT %d: (%c -> %c)-\n", ++(*movements), towerFrom->name, towerTo->name);
    printTowers(*towerFrom, *towerTemp, *towerTo);
    printf("\n");
    recursiveSolve(towerTemp, towerFrom, towerTo, size-1, movements);      //Move smaller (n-1) tower to end
    return 0;
}

int printTower(Tower tower, char towerName){
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
}

int printTowers(Tower A, Tower B, Tower C){
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