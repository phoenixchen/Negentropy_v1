#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "array.h"

void Negentropy(char * chess){

    Array *ends = ReturnAllOfTheMove(chess,31);

    /*

    char *element;
    for(int i=0;i<array_size(ends);i++){
        array_remove_at(ends, 0,(void*)&element);
        //printf("%4d ",*element);
    }

    */
    array_destroy(ends);
    //GreedyMove(chess);
}

