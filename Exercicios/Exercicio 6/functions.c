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
        if (numbers[i] > pivot) {                       // Greater at left
            left[leftSize++] = numbers[i];              // Increment leftSize as it makes the array
        } else if (numbers[i] < pivot) {
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

int MoveDisk(Tower* towerFrom, Tower* towerTo){
    if(TowerFrom->size < 1 || TowerTo->size == TowerTo->maxSize){
        if(DEBUG) printf("MoveDisk: invalid movement (Source empty/Destination full)");
        return 1;      //From empty or To full
    }
    towerTo->disk[(towerTo->size)-1] = towerFrom->disk[towerFrom->size];        //Move the disk
    towerTo->size++;
    towerFrom->size--;
    towerFrom[indexFrom] = -1;                                                  //Set the empty slot as -1
    if(DEBUG) printf("MoveDisk: disk moved successfully");
    return 0;
}
int shrinkTower(Tower)

int recursiveSolve(Tower* from, Tower* temp, Tower* to, int* movements){
    if(size == 0) return 0;
    recursiveSolve(from, to, temp, size-1, movements);     //Move smaller (n-1) tower to temp
    MoveDisk(from, to);                                    //Move the largest Disk to end
    recursiveSolve(temp, from, to, size-1, movements);     //Move smaller (n-1) tower to end
    return 0;
}

int printTowers(int* from, int* temp, int* to, int size){
    printf("Tower A:");
    for(int i = 0; i < size; i++){
        if(from[i] == -1)
            printf(" _");
        else
            printf(" %d", from[i]);
    }
    printf("\nTower B:");
    for(int i = 0; i < size; i++){
        if(temp[i] == -1)
            printf(" _");
        else
            printf(" %d", temp[i]);
    }
    printf("\nTower C:");
    for(int i = 0; i < size; i++){
        if(to[i] == -1)
            printf(" _");
        else
            printf(" %d", to[i]);
    }
    printf("\n");
    return 0;
}