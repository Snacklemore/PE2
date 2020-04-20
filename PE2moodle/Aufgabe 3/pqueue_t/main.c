#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pqueue.h"
//#define MAX 100000

char * randomString ( int size ) {
    int i ;
    char* str = ( char *) malloc (( size +1)* sizeof ( char ));
    for ( i = 0 ; i < size ; ++ i ) {
        str [ i ] = ( rand () % 26) + 'A';
    }
    str [ size +1] = '/0';
    return str ;
}

int main() {


    ///////////TestTreiber//////////
#define MAX 40

    priorityqueue_t *pq;
    pq=pqueue_create();
    float a =100.00,b=50;
    char *str[MAX];
    srand(time(NULL));
    for (int i=0;i<MAX;i++){
        str[i]=randomString(5);
    }
    ///////////InsertTest//////////
    for (int i=0;i<MAX;i++){
        pqueue_insert(pq,str[i],((float)rand()/(float)(RAND_MAX)) * a);

    }
    toScreen(pq);


    ///////////DecreaseKeyTest/////
    printf("Changing priority of %s Element to 0.34\n",str[0]);
    pqueue_decreaseKey(pq,str[0],0.34);
    printf("\n");
    toScreen(pq);




    //////////ExtractMinTest&RemoveTest///////

    printf("Extracting entry with smallest priority until empty\n");
    for (int k=0;k<MAX;k++){
        printf("%s\n",pqueue_extractMinSortedDesc(pq));
        toScreen(pq);
    }



    toScreen(pq);
    ///DestroyTest////////
    pqueue_destroy(pq);


    return 0;


/*
    int i ;
    char * strings [ MAX ];
    clock_t tic , toc ;

    srand ( time ( NULL ));


    for ( i = 0 ; i < MAX ; ++ i ) {
        strings [ i ] = randomString (8);
    }


    priorityqueue_t * pq = pqueue_create ();

    tic = clock ();
    for ( i = 0 ; i < MAX ; ++ i ) {
        pqueue_insert ( pq , strings [ i ] , rand () % 100);
    }
    toc = clock ();
    printf ( " insertion time : %.2f \n " , ( float )( toc - tic ) / CLOCKS_PER_SEC );


    tic = clock ();
    for ( i = 0 ; i < MAX ; ++ i ) {
        pqueue_extractMinSortedAsc( pq );
    }
    toc = clock ();
    printf ( " extract time : %.2f\n " , ( float )( toc - tic ) / CLOCKS_PER_SEC );

        for ( i = 0 ; i < MAX ; ++ i ) {
        free ( strings [ i ]);
    }
    pqueue_destroy ( pq );


    return 0;
    */




}