#include <stdio.h>
#include "lang.h"

int add(int num_1, int num_2){
    return num_1 + num_2;
}

int addl(int num, int prev){
    return num + prev;
}

int sb(int num_1, int num_2){
    return num_1 - num_2;
}

int sbl(int num, int prev){
    return num - prev;
}

int com(int num_1, int num_2){
    if (num_1 == num_2){
        return 1;
    }
    return 0;
}

int coml(int num, int prev){
    if (num == prev){
        return 1;
    }
    return 0;
}

