#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define DEBUG 1

//tower struct
typedef struct Tower_str{
int maxSize;                //The max amount of disks
int size;                   //The current amount of disks
int *disk;                  //List of disks by weight, from top to bottom
} Tower;


//Sorting algorithms
    //Recursive function for quicksort algorithm with distinct numbers
    int* recursiveDistinctQuicksort(int* numbers, int size);
    //Recursive function for heap algorithm
    int* recursiveHeapsort(int* numbers);
    void heapify(int* numbers, int size, int i);
    void swap(int* a, int* b);

//Disk/Tower manipulation
    //Function for moving disks between towers, return 0 if succeed
    int MoveDisk(int* towerFrom, int* towerTo, int size);
    //Checks if the disk movement is valid (?)
    int validMovement(int* towerFrom, int* towerTo);
    //Prints the three towers
    int printTowers(int* from, int* temp, int* to, int size);
    //Solve the tower of hanoi
    int recursiveSolve(int* from, int* temp, int* to, int size, int* movements, int* A, int* B, int* C);




#endif // FUNCTIONS_H