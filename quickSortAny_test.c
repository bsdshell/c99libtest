#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "/Users/aaa/myfile/github/c99lib/AronCLibNew.h"
//

/**
 *
 * Sat  4 May 12:43:06 2024 
 * Passed all tests
 * gcc -o quickSortAny_test quickSortAny_test.c
 *
 */

/*
typedef struct GroupFloat {
    float data;
    int count;
} GroupFloat;

// Compare GroupFloat according to count
int cmpGroupFloat(const GroupFloat* p1, const GroupFloat* p2) {
  return p1->count <= p2->count;
}

// Compare an GroupFloat
bool isEqualGroupFloat(GroupFloat *pt1, GroupFloat* pt2){
    return pt1->data == pt2->data && pt1->count == pt2->count;
}

bool cmpInt(const int* p1, const int* p2){
  return *p1 <= *p2;
}


// KEY: compare int array, array int
// NOTE: pt1[i] => pointer to int
//
// **pt1[i] == **(pt1 + i)
bool isEqualArrayInt(int** pt1, int** pt2, const int len){
  for(int i = 0; i < len; i++){
    // if(*pt1[i] != *pt2[i])
    if(**(pt1 + i) != **(pt2 + i))
      return false;
  }
  return true;
}

// Compare an array of GroupFloat
bool isEqualArrayGroupFloat(GroupFloat** pt1, GroupFloat** pt2, const int len){
    for(int i=0; i<len; i++){
        if(!isEqualGroupFloat(pt1[i], pt2[i]))
            return false;
    }
    return true;
}

bool compareArrayPt(float** arr1, float** arr2, int len) {
    if(arr1 != NULL && arr2 != NULL) {
        for(int i=0; i<len; i++) {
            if(arr1[i] != NULL && arr2[i] != NULL && *arr1[i] != *arr2[i])
                return false;
        }
    }
    return true;
}


bool cmpFloat(const float* p1, const float* p2) {
  return *p1 <= *p2;
}

// Compare two float array
bool compareArrayF(float* arr1, int len1, float* arr2, int len2) {
    if(arr1 != NULL && arr2 != NULL && len1 == len2) {
        for(int i=0; i<len1; i++) {
            if(arr1[i] != arr2[i])
                return false;
        }
    }
    return true;
}


int partitionAny(void** ls, int (*cmp)(const void *, const void *), int lo, int hi) {
    const int len = hi - lo + 1;
    int i=0;
    int j=len - 1;
    int k=lo;
    void* arr[len];
    
    if(len > 1) {
        // Use last element as pivot
        void* pivot = ls[hi];
        // if i == j then, the i or j is pivot position
        while(i != j) {
            if(cmp(ls[k], pivot)) {
                arr[i] = ls[k];
                i++;
            } else {
                arr[j] = ls[k];
                j--;
            }
            k++;
        }
        arr[i] = pivot;

        for(int i=0; i<len; i++) {
            ls[lo+i] = arr[i];
        }
    }
    return (lo + i);
}

void quickSortAny(void** ls, int (*cmp)(const void*, const void*), int lo, int hi) {
    if ( lo < hi) {
        int p = partitionAny(ls, cmp, lo, hi);
        quickSortAny(ls, cmp, lo, p-1);
        quickSortAny(ls, cmp, p+1, hi);
    }
}
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
