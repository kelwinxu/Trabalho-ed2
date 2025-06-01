#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define DEBUG_MEMORY 1      //Debug for memory malloc errors
#define DEBUG_QUICKSORT 0   //Debug for Quicksort function
#define DEBUG_HEAPSORT 1    //Debug for Heapsort function
#define DEBUG_MOVEDISK 0    //Debug for MoveDisk function (and shifts)
#define DEBUG_HANOI 1       //Debug for RecursiveSolve function
//tower struct
typedef struct Tower_str{
char name;                  //Name for debug and print purposes
int maxSize;                //The max amount of disks
int size;                   //The current amount of disks
int *disk;                  //List of disks by weight, from top to bottom
} Tower;


//Sorting algorithms
    //recursiveDistinctQuicksortInternal wrapper
    int* recursiveDistinctQuicksort(int* numbers, int size);
    //Recursive function for quicksort algorithm with distinct numbers
    int* recursiveDistinctQuicksortInternal(int* numbers, int size, int depth);
    //Recursive heapsort wrapper
    void recursiveHeapSort(int* numbers, int size);
    //Recursive function setup
    void setupRecursiveHeapsort(int* numbers, int i, int size);
    //Recursive function for heap algorithm
    void recursiveHeapsortInternal(int* numbers, int size);
    //Order the array with heapify rules
    void heapify(int* numbers, int size, int i);
    //Swap two numbers in array
    void swap(int *a, int *b);

//Disk/Tower manipulation
    //Creates an empty (-1) tower, returns the empty tower
    Tower createEmptyTower(char towerName, int maxSize);
    //Frees Disk malloc
    void freeTower(Tower *tower);
    //Function to shift the whole array to the next index
    int shiftRight(Tower* tower);
    //Function to shift the whole array the the previous index
    int shiftRight(Tower* tower);
    //Function for moving disks between towers, return 0 if succeed
    int MoveDisk(Tower* towerFrom, Tower* towerTo);
    //Prints the three towers
    int printTowers(Tower A, Tower B, Tower C);
    //RecursiveSolveInternal wrapper
    int recursiveSolve(Tower* towerFrom, Tower* towerTemp, Tower* towerTo, int size, int* movements);
    //Solve the tower of hanoi
    int recursiveSolveInternal(Tower* towerFrom, Tower* towerTemp, Tower* towerTo, int size, int* movements);

//Debug/Print purposes
    //Prints the tower array
    int printTower(Tower tower, char towerName);
    //Prints three towers, in order of name ABC
    int printTowersABC(Tower A, Tower B, Tower C);

//Unused functions
    //Checks if the disk movement is valid (?)
    //int validMovement(int* towerFrom, int* towerTo);


#endif // FUNCTIONS_H