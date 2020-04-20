#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#define EXPO10 10.0
#define EXPO11 11.0
#define EXPO12 12.0
#define EXPO13 13.0
#define EXPO14 14.0
#define EXPO15 15.0
#define EXPO16 16.0
#define EXPO17 17.0


void swap(int *array,int firstInd,int secondInd);
void initRand();
int selectionSort(int *arrayToSort, int *_outSortedArray,int len);
int main() {
    //TIME
    double start;
    struct timeval tm;



    //////////////////////7
    int sortArray[150000];
    int sortedArray[150000];
    time_t t;
    initRand();
    int len = 0;
    //change EXPO17 for testing with bigger exponent
    for ( int i = 0;i<pow(2.0,EXPO16);i++)
    {
        int randNo = (rand()) % 101;

        sortArray[i] = randNo;
        printf("UnSortedDigits: %d\n", sortArray[i]);

        len++;
    }
    gettimeofday(&tm,NULL);
    start = (double) (tm.tv_sec) + ((double) (tm.tv_usec))/1.0e6;
    selectionSort(sortArray,sortedArray,len);
    gettimeofday(&tm,NULL);
    double duration = (double) (tm.tv_sec) + ((double) (tm.tv_usec))/1.0e6 -start;

    for ( int i = 0;i<len;i++)
    {
        printf("Digit: %d\n", sortArray[i]);
    }
    printf("Took %lf seconds!",duration);


}
int selectionSort(int *arrayToSort,int *_outSortedArray,int len){
    for ( int i = 0;i<len-1;i++)
    {
        int min = arrayToSort[i];
        //search min
        for (int k = i+1;k<len;k++)
        {
            if (min > arrayToSort[k] )
            {
                min = arrayToSort[k];
                swap(arrayToSort,i,k);
            }

        }
    }
}
void swap(int *array,int firstInd,int secondInd)
{
    int temp = array[firstInd];
    array[firstInd] = array[secondInd];
    array[secondInd] = temp;
}
void initRand()
{
    srand((unsigned) time(0));
}