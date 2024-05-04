#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "AronCLibNew.h"
//

/**
 *
 * Sat  4 May 12:43:06 2024 
 * Passed all tests
 * gcc -I$clib -o quickSortAny_test quickSortAny_test.c
 *
 */

void quickSortAny_test0() {
    int len = 1;
    float** arr = (float**)malloc(sizeof(float*)*len);
    float** expected = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;
    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
        expected[i] = (float*)malloc(sizeof(float));
    }
    *arr[0] = 0.2;
    *expected[0] = 0.2;

    quickSortAny((void**)arr, (void*)cmpFloat, lo, hi);

    printf("quickSortAny_test0=%s\n", compareArrayPt(arr, expected, len) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(arr[i] != NULL)
            free(arr[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
}

void quickSortAny_test1() {
    int len = 2;
    float** arr = (float**)malloc(sizeof(float*)*len);
    float** expected = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
        expected[i] = (float*)malloc(sizeof(float));
    }
    *arr[0] = 0.2;
    *arr[1] = 0.1;

    *expected[0] = 0.1;
    *expected[1] = 0.2;
    
    quickSortAny((void**)arr, (void*)cmpFloat, lo, hi);
    
    printf("quickSortAny_test1=%s\n", compareArrayPt(arr, expected, len) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(arr[i] != NULL)
            free(arr[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
}

void quickSortAny_test2() {
    int len = 3;
    float** arr = (float**)malloc(sizeof(float*)*len);
    float** expected = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
        expected[i] = (float*)malloc(sizeof(float));
    }
    *arr[0] = 0.2;
    *arr[1] = 0.1;
    *arr[2] = 0.0;

    *expected[0] = 0.0;
    *expected[1] = 0.1;
    *expected[2] = 0.2;

    quickSortAny((void**)arr, (void*)cmpFloat, lo, hi);

    printf("quickSortAny_test2=%s\n", compareArrayPt(arr, expected, len) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(arr[i] != NULL)
            free(arr[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
}


void quickSortAny_test3() {
    int len = 4;
    float** arr = (float**)malloc(sizeof(float*)*len);
    float** expected = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
        expected[i] = (float*)malloc(sizeof(float));
    }
    *arr[0] = 0.4;
    *arr[1] = 0.3;
    *arr[2] = 0.2;
    *arr[3] = 0.1;

    *expected[0] = 0.1;
    *expected[1] = 0.2;
    *expected[2] = 0.3;
    *expected[3] = 0.4;

    quickSortAny((void**)arr, (void*)cmpFloat, lo, hi);

    printf("quickSortAny_test3=%s\n", compareArrayPt(arr, expected, len) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(arr[i] != NULL)
            free(arr[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
}

void quickSortAny_test4() {
    int len = 2;
    float** arr = (float**)malloc(sizeof(float*)*len);
    float** expected = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
        expected[i] = (float*)malloc(sizeof(float));
    }
    *arr[0] = 0.4;
    *arr[1] = 0.4;

    *expected[0] = 0.4;
    *expected[1] = 0.4;

    quickSortAny((void**)arr, (void*)cmpFloat, lo, hi);

    printf("quickSortAny_test4=%s\n", compareArrayPt(arr, expected, len) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(arr[i] != NULL)
            free(arr[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
}

void quickSortAny_test5() {
    int len = 2;
    GroupFloat** arr = (GroupFloat**)malloc(sizeof(GroupFloat*)*len);
    GroupFloat** expected = (GroupFloat**)malloc(sizeof(GroupFloat*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
        expected[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }
    arr[0]->data = 0.1 ;
    arr[0]->count = 2 ;
    arr[1]->data = 0.4;
    arr[1]->count= 1;

    expected[0]->data = 0.4;
    expected[0]->count = 1;
    expected[1]->data = 0.1;
    expected[1]->count = 2;

    quickSortAny((void**)arr, (void*)cmpGroupFloat, lo, hi);
    printf("quickSortAny_test5=%s\n", isEqualArrayGroupFloat(arr, expected, len) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(arr[i] != NULL)
            free(arr[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
}

void quickSortAny_test6(){
  int len = 3;
  int** arr = (int**)malloc(sizeof(int*)*len);
  int** expected = (int**)malloc(sizeof(int*)*len);
  int lo = 0;
  int hi = len - 1;
  for(int i = 0; i < len; i++){
    arr[i] = (int*)malloc(sizeof(int));
    expected[i] = (int*)malloc(sizeof(int));
  }
  
  *arr[0] = 3;
  *arr[1] = 1;
  *arr[2] = 2;

  *expected[0] = 1;
  *expected[1] = 2;
  *expected[2] = 3;

  quickSortAny((void**)arr, (void*)cmpInt, lo, hi);
  printf("quickSortAny_test6=%s\n", isEqualArrayInt(arr, expected, len) ? "true" : "false");
  
  for(int i=0; i<len; i++) {
    if(arr[i] != NULL)
      free(arr[i]);
    if(expected[i] != NULL)
      free(expected[i]);
  }
  
}


int main (int argc, char* argv[]) {
  quickSortAny_test0();
  quickSortAny_test1();
  quickSortAny_test2();
  quickSortAny_test3();
  quickSortAny_test4();
  quickSortAny_test5();
  quickSortAny_test6();
}
