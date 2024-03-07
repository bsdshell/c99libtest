#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "AronCLib.h"

/**
 @file

 @brief The library only use C standard library

 KEY: gcc -I$b/cpplib -o /tmp/AronCLibTest  $b/clib/AronCLibTest.c
 
 Mon May  4 21:35:35 2020 
 passed all tests

*/
void cmpStr_test_0(){
    char* pt1 = "abc";
    char* pt2 = "abc";
    printf("cmpStr_test_0=%s\n", cmpStr(pt1, pt2) ? "true" : "false");
}
void cmpStr_test_1(){
    char* pt1 = "ab";
    char* pt2 = "abc";
    printf("cmpStr_test_1=%s\n", cmpStr(pt1, pt2) == false ? "true" : "false");
}
void cmpStr_test_2(){
    char* pt1 = "";
    char* pt2 = "abc";
    printf("cmpStr_test_2=%s\n", cmpStr(pt1, pt2) == false ? "true" : "false");
}
void cmpStr_test_3(){
    char* pt1 = "";
    char* pt2 = "";
    printf("cmpStr_test_3=%s\n", cmpStr(pt1, pt2) ? "true" : "false");
}
void concat_test_0(){
    char* str1 = (char*)malloc(sizeof(char)*30);
    str1[0] = '\0';
    char* str2 = "aabb";
    concat(str1, str1, str2);
    printf("str1=[%s\n", str1);
}

void partitionAny_test_0() {
    int len = 1;
    float** arr = (float**)malloc(sizeof(float*)*len);
    float** expected = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    float m = 0.6;
    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
        expected[i] = (float*)malloc(sizeof(float));
    }
    *arr[0] = m;
    *expected[0] = m;
    int px = partitionAny((void**)arr, (void*)cmp, lo, hi);

    printf("partitionAny_test_0=%s\n", compareArrayPt((void*)arr, expected, len) && px == 0 ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(arr[i] != NULL) {
            free(arr[i]);
        }
        if(expected[i] != NULL) {
            free(expected[i]);
        }
    }
}

void partitionAny_test_1() {
    int len = 2;
    float** arr = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
    }
    *arr[0] = 0.4;
    *arr[1] = 0.9;

    int px = partitionAny((void**)arr, (void*)cmp, lo, hi);

    float** expected = (float**)malloc(sizeof(float*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (float*)malloc(sizeof(float));
    }
    *expected[0] = 0.4;
    *expected[1] = 0.9;

    printf("partitionAny_test_1=%s\n", compareArrayPt(arr, expected, len) && px == 1 ? "true" : "false");
    for(int i=0; i<len; i++) {
        if(arr[i] != NULL) {
            free(arr[i]);
        }
        if(expected[i] != NULL) {
            free(expected[i]);
        }
    }
}

void partitionAny_test_2() {
    int len = 3;
    float** arr = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
    }
    *arr[0] = 0.4;
    *arr[1] = 0.9;
    *arr[2] = 0.1;

    int px = partitionAny((void**)arr, (void*)cmp, lo, hi);

    float** expected = (float**)malloc(sizeof(float*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (float*)malloc(sizeof(float));
    }
    *expected[0] = 0.1;
    *expected[1] = 0.9;
    *expected[2] = 0.4;

    printf("partitionAny_test_2=%s\n", compareArrayPt(arr, expected, len) && px == 0 ? "true" : "false");
    for(int i=0; i<len; i++) {
        if(arr[i] != NULL) {
            free(arr[i]);
        }
        if(expected[i] != NULL) {
            free(expected[i]);
        }
    }
}
void partitionAny_test_3() {
    int len = 4;
    float** arr = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
    }
    //  0.1 0.3 0.9 0.4
    *arr[0] = 0.4;
    *arr[1] = 0.9;
    *arr[2] = 0.1;
    *arr[3] = 0.3;

    int px = partitionAny((void**)arr, (void*)cmp, lo, hi);

    float** expected = (float**)malloc(sizeof(float*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (float*)malloc(sizeof(float));
    }
    *expected[0] = 0.1;
    *expected[1] = 0.3;
    *expected[2] = 0.9;
    *expected[3] = 0.4;

    printf("partitionAny_test_3=%s\n", compareArrayPt(arr, expected, len) && px == 1 ? "true" : "false");
    for(int i=0; i<len; i++) {
        if(arr[i] != NULL) {
            free(arr[i]);
        }
        if(expected[i] != NULL) {
            free(expected[i]);
        }
    }
}

void partitionAny_test_4() {
    int len = 5;
    float** arr = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
    }
    //    0.1 {0.11} 0.3  0.9 0.4
    *arr[0] = 0.4;
    *arr[1] = 0.9;
    *arr[2] = 0.1;
    *arr[3] = 0.3;
    *arr[4] = 0.11;

    int px = partitionAny((void**)arr, (void*)cmp, lo, hi);

    float** expected = (float**)malloc(sizeof(float*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (float*)malloc(sizeof(float));
    }
    *expected[0] = 0.1;
    *expected[1] = 0.11;
    *expected[2] = 0.3;
    *expected[3] = 0.9;
    *expected[4] = 0.4;

    printf("partitionAny_test_4=%s\n", compareArrayPt(arr, expected, len) && px == 1 ? "true" : "false");
    for(int i=0; i<len; i++) {
        if(arr[i] != NULL) {
            free(arr[i]);
        }
        if(expected[i] != NULL) {
            free(expected[i]);
        }
    }
}
void partitionAny_test_5() {
    int len = 6;
    float** arr = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
    }
    //    0.1 {0.11} 0.3  0.9 0.4
    *arr[0] = 0.1;
    *arr[1] = 0.2;
    *arr[2] = 0.3;
    *arr[3] = 0.4;
    *arr[4] = 0.5;
    *arr[5] = 0.6;

    int px = partitionAny((void**)arr, (void*)cmp, lo, hi);

    float** expected = (float**)malloc(sizeof(float*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (float*)malloc(sizeof(float));
    }
    // 0.1 0.2 0.3 0.4 0.5 {0.6}
    *expected[0] = 0.1;
    *expected[1] = 0.2;
    *expected[2] = 0.3;
    *expected[3] = 0.4;
    *expected[4] = 0.5;
    *expected[5] = 0.6;

    printf("partitionAny_test_5=%s\n", compareArrayPt(arr, expected, len) && px == 5 ? "true" : "false");
    for(int i=0; i<len; i++) {
        if(arr[i] != NULL) {
            free(arr[i]);
        }
        if(expected[i] != NULL) {
            free(expected[i]);
        }
    }
}

void partitionAny_test_6() {
    int len = 2;
    float** arr = (float**)malloc(sizeof(float*)*len);
    int lo = 0;
    int hi = len - 1;

    for(int i=0; i<len; i++) {
        arr[i] = (float*)malloc(sizeof(float));
    }
    *arr[0] = 0.2;
    *arr[1] = 0.1;

    int px = partitionAny((void**)arr, (void*)cmp, lo, hi);

    float** expected = (float**)malloc(sizeof(float*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (float*)malloc(sizeof(float));
    }
    *expected[0] = 0.1;
    *expected[1] = 0.2;

    printf("partitionAny_test_6=%s\n", compareArrayPt(arr, expected, len) && px == 0 ? "true" : "false");
    for(int i=0; i<len; i++) {
        if(arr[i] != NULL) {
            free(arr[i]);
        }
        if(expected[i] != NULL) {
            free(expected[i]);
        }
    }
}

void partition_test0() {
    int num = 1;
    float* arr = (float*)malloc(sizeof(float)*num);
    int lo = 0;
    int hi = num - 1;

    arr[0] = 0.6;
    int n1 = partition(arr, lo, hi);

    float expected[] = {0.6};
    printf("partition2_test_0=%s\n", compareArrayF(arr, num, expected, num) ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void partition_test1() {
    int num = 4;
    float* arr = (float*)malloc(sizeof(float)*num);
    int lo = 0;
    int hi = num - 1;

    arr[0] = 0.6;
    arr[1] = 0.1;
    arr[2] = 0.4;
    arr[3] = 0.3;

    partition(arr, lo, hi);

    float expected[] = {0.1, 0.3, 0.4, 0.6};

    printf("partition_test_1=%s\n", compareArrayF(arr, num, expected, num) ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void partition_test2() {
    int num = 2;
    float* arr = (float*)malloc(sizeof(float)*num);
    int lo = 0;
    int hi = num - 1;

    arr[0] = 0.6;
    arr[1] = 0.1;

    float expected[] = {0.1, 0.6};
    partition(arr, lo, hi);

    printf("=%s\n", compareArrayF(arr, num, expected, num)? "true" : "false");


    if(arr != NULL)
        free(arr);
}

void quickSort_test0() {
    int len = 1;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.6;
    float expected[] = {0.6};
    quickSort(arr, lo, hi);

    printf("quickSort_test0=%s\n", compareArrayF(arr, len, expected, len) ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

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

void quickSort_test1() {
    int len = 2;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.1;
    arr[1] = 0.6;
    float expected[] = {0.1, 0.6};
    quickSort(arr, lo, hi);

    printf("quickSort_test1=%s\n", compareArrayF(arr, len, expected, len) ? "true" : "false");

    if(arr != NULL)
        free(arr);
}


void quickSort_test2() {
    int len = 2;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.6;
    arr[1] = 0.1;
    float expected[] = {0.1, 0.6};
    quickSort(arr, lo, hi);

    printf("quickSort_test2=%s\n", compareArrayF(arr, len, expected, len) ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void quickSort_test3() {
    int len = 3;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.6;
    arr[1] = 0.1;
    arr[2] = 0.2;
    float expected[] = {0.1, 0.2, 0.6};
    quickSort(arr, lo, hi);

    printf("quickSort_test3=%s\n", compareArrayF(arr, len, expected, len) ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void quickSort_test4() {
    int len = 3;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.60;
    arr[1] = 0.1;
    arr[2] = 0.200;
    float expected[] = {0.1, 0.2, 0.6};
    quickSort(arr, lo, hi);

    printf("quickSort_test4=%s\n", compareArrayF(arr, len, expected, len) ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void quickSort_test5() {
    int len = 5;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.9;
    arr[1] = 0.4;
    arr[2] = 0.3;
    arr[3] = 0.4;
    arr[4] = 0.3;

    float expected[] = {0.3, 0.3, 0.4, 0.4, 0.9};
    quickSort(arr, lo, hi);

    bool check = compareArrayF(arr, len, expected, len);
    printf("quickSort_test5=%s\n", check ? "true" : "false");
    if(!check) {
        printf("Actual:");
        for(int i=0; i<len; i++) {
            printf("arr[%d]=[%2.2f]\n", i, arr[i]);
        }
        printf("Expected:");
        for(int i=0; i<len; i++) {
            printf("expected[%d]=[%2.2f]\n", i, expected[i]);
        }
    }

    if(arr != NULL)
        free(arr);
}
void quickSort_test6() {
    int len = 5;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.9;
    arr[1] = 0.3;
    arr[2] = 0.4;
    arr[3] = 0.3;
    arr[4] = 0.4;

    float expected[] = {0.3, 0.3, 0.4, 0.4, 0.9};
    quickSort(arr, lo, hi);

    bool check = compareArrayF(arr, len, expected, len);
    printf("quickSort_test6=%s\n", check ? "true" : "false");
    if(!check) {
        printf("Actual:");
        for(int i=0; i<len; i++) {
            printf("arr[%d]=[%2.2f]\n", i, arr[i]);
        }
        printf("Expected:");
        for(int i=0; i<len; i++) {
            printf("expected[%d]=[%2.2f]\n", i, expected[i]);
        }
    }

    if(arr != NULL)
        free(arr);
}
// All test cases for  mean function
void test_mean_0() {
    int len = 1;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.0;
    float expected = 0.0;
    float m = mean(arr, len);

    printf("test_mean_0=%s\n", m == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void test_mean_1() {
    int len = 2;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.0;
    arr[1] = 0.0;
    float expected = 0.0;
    float m = mean(arr, len);

    printf("test_mean_1=%s\n", m == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void test_mean_2() {
    int len = 1;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.3;
    float expected = 0.3;
    float m = mean(arr, len);

    printf("test_mean_2=%s\n", m == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void test_median_0() {
    int len = 1;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.0;
    float expected = 0.0;
    quickSort(arr, lo, hi);
    float m = median(arr, len);

    printf("test_median_0=%s\n", m == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void test_median_1() {
    int len = 2;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.2;
    arr[1] = 0.4;
    float expected = 0.3;
    quickSort(arr, lo, hi);
    float m = median(arr, len);

    printf("test_median_1=%s\n", m == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}
void test_median_2() {
    int len = 3;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.4;
    arr[1] = 0.1;
    arr[2] = 0.3;
    float expected = 0.3;
    quickSort(arr, lo, hi);
    float m = median(arr, len);

    printf("test_median_2=%s\n", m == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void test_median_3() {
    int len = 4;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.4;
    arr[1] = 0.1;
    arr[2] = 0.3;
    arr[3] = 0.3;
    float expected = 0.3;
    quickSort(arr, lo, hi);
    float m = median(arr, len);

    printf("test_median_3=%s\n", m == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}



void test_mean_3() {
    int len = 2;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.2;
    arr[1] = 0.4;
    float expected = 0.3;
    float m = mean(arr, len);

    printf("test_mean_3=%s\n", m == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void test_mean_4() {
    int len = 3;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.3;
    arr[1] = 0.0;
    arr[2] = 0.6;
    float expected = 0.3;
    quickSort(arr, lo, hi);
    float m = mean(arr, len);

    printf("test_mean_4=%s\n", m == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void standarddeviation_test_0() {
    int len = 1;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;
    arr[0] = 0.0;
    float expected = 0.0;

    float mu = mean(arr, len);
    float stdev = standarddeviation(arr, len, mu);
    printf("standarddeviation_test_0=%s\n", stdev == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void standarddeviation_test_1() {
    int len = 1;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;
    arr[0] = 9.0;
    float expected = 0.0 ;

    float mu = mean(arr, len);
    float stdev = standarddeviation(arr, len, mu);
    printf("standarddeviation_test_1=%s\n", stdev == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}
void standarddeviation_test_2() {
    int len = 2;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;
    arr[0] = 0.4;
    arr[1] = 0.2;
    float expected = 0.1;

    // mu = 0.3
    // 0.4 - 0.3  0.2 - 0.3
    //  0.1^2 + 0.1^2 = 0.02
    // 0.02/2 = 0.01 => sqrt(0.01) = 0.1
    float mu = mean(arr, len);
    float stdev = standarddeviation(arr, len, mu);
    printf("standarddeviation_test_2=%s\n", stdev == expected ? "true" : "false");

    if(arr != NULL)
        free(arr);
}


void standarddeviation_test_3() {
    int len = 3;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;
    arr[0] = 9;
    arr[1] = 4;
    arr[2] = 3;
    float expected = 2.624;

    // mu = 8
    // 9 - 8 = 1, |4-8| = 4, |3-8| = 5
    // 1*1 + 4*4 + 5*5 = 42, 42/3 =
    float mu = mean(arr, len);
    float stdev = standarddeviation(arr, len, mu);
    printf("standarddeviation_test_3=%s\n", 2.61 < stdev && stdev < 2.63 ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void standarddeviation_test_4() {
    int len = 8;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;
    arr[0] = 10;
    arr[1] = 12;
    arr[2] = 23;
    arr[3] = 23;
    arr[4] = 16;
    arr[5] = 23;
    arr[6] = 21;
    arr[7] = 16;

    float expected = 4.89;

    // mu = 0.3
    // 0.4 - 0.3  0.2 - 0.3
    //  0.1^2 + 0.1^2 = 0.02
    // 0.02/2 = 0.01 => sqrt(0.01) = 0.1
    float mu = mean(arr, len);
    float stdev = standarddeviation(arr, len, mu);
    printf("standarddeviation_test_4=%s\n", 4.88 < stdev && stdev < 5.0 ? "true" : "false");

    if(arr != NULL)
        free(arr);
}

void mode_test_0() {
    int len = 3;
    int lenexp = 1;
    const int msgLen = 30;
    float* arr = (float*)malloc(sizeof(float)*len);
    int nGroup = -1;
    GroupFloat** tempGroup = (GroupFloat**)malloc(sizeof(GroupFloat*)*len);
    GroupFloat** expected= (GroupFloat**)malloc(sizeof(GroupFloat*)*lenexp);
    for(int i=0; i<len; i++) {
        tempGroup[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }
    for(int i=0; i<lenexp; i++){
        expected[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }

    int lo = 0;
    int hi = len - 1;
    expected[0]->data = 0.1;
    expected[0]->count= 2;
    
    arr[0] = 0.6;
    arr[1] = 0.1;
    arr[2] = 0.1;

    modeInfo(arr, len, tempGroup, &nGroup);
    char* result = (char*)malloc(sizeof(char)*nGroup*msgLen);
    result[0] = '\0';
    int repeating = -1;
    mode(tempGroup, nGroup, &repeating, result, msgLen);
    // mode(arr, len, tempGroup, &nGroup);
    int k=0;
    printf("kk mode_test_0=%s\n", (repeating == 1) && isEqualGroupFloat(tempGroup[nGroup - 1], expected[0]) ? "true" : "false");


    for(int i=0; i<lenexp; i++) {
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(expected != NULL)
        free(expected);

    for(int i=0; i<len; i++) {
       if(tempGroup[i] != NULL)
            free(tempGroup[i]);
    }
    if(tempGroup != NULL)
        free(tempGroup);

    if(arr != NULL)
        free(arr);
    if(result != NULL)
        free(result);

}

void mode_test_1() {
    int len = 1;
    int lenexp = 1;
    const int msgLen = 30;
    float* arr = (float*)malloc(sizeof(float)*len);
    int nGroup = -1;
    GroupFloat** tempGroup = (GroupFloat**)malloc(sizeof(GroupFloat*)*len);
    GroupFloat** expected= (GroupFloat**)malloc(sizeof(GroupFloat*)*lenexp);
    for(int i=0; i<len; i++) {
        tempGroup[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }
    for(int i=0; i<lenexp; i++){
        expected[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }
    int lo = 0;
    int hi = len - 1;
    expected[0]->data = 0.6;
    expected[0]->count= 1;

    arr[0] = 0.6;

    modeInfo(arr, len, tempGroup, &nGroup);
    char* result = (char*)malloc(sizeof(char)*nGroup*msgLen);
    result[0] = '\0';
    int repeating = -1;
    mode(tempGroup, nGroup, &repeating, result, msgLen);
    // mode(arr, len, tempGroup, &nGroup);
    int k=0;
    printf("mode_test_1=%s\n",(repeating == 0) ? "true" : "false");

    for(int i=0; i<lenexp; i++) {
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(expected != NULL)
        free(expected);

    for(int i=0; i<len; i++) {
       if(tempGroup[i] != NULL)
            free(tempGroup[i]);
    }
    if(tempGroup != NULL)
        free(tempGroup);

    if(arr != NULL)
        free(arr);
    if(result != NULL)
        free(result);
}

void mode_test_2() {
    int len = 5;
    int lenexp = 1;
    const int msgLen = 30;
    float* arr = (float*)malloc(sizeof(float)*len);
    int nGroup = -1;
    GroupFloat** tempGroup = (GroupFloat**)malloc(sizeof(GroupFloat*)*len);
    GroupFloat** expected= (GroupFloat**)malloc(sizeof(GroupFloat*)*lenexp);
    for(int i=0; i<len; i++) {
        tempGroup[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }
    for(int i=0; i<lenexp; i++) {
        expected[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }

    int lo = 0;
    int hi = len - 1;
    expected[0]->data = 0.6;
    expected[0]->count= 3;

    arr[0] = 0.6;
    arr[1] = 0.6;
    arr[2] = 0.4;
    arr[3] = 0.6;
    arr[4] = 0.4;

    modeInfo(arr, len, tempGroup, &nGroup);
    char* result = (char*)malloc(sizeof(char)*nGroup*msgLen);
    // result[0] = '\0';
    int repeating = -1;
    mode(tempGroup, nGroup, &repeating, result, msgLen);
    int k=0;
    printf("mode_test_2=%s\n", (repeating == 1) && isEqualGroupFloat(tempGroup[nGroup-1], expected[0]) ? "true" : "false");

    for(int i=0; i<lenexp; i++) {
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(expected != NULL)
        free(expected);

    for(int i=0; i<len; i++) {
       if(tempGroup[i] != NULL)
            free(tempGroup[i]);
    }
    if(tempGroup != NULL)
        free(tempGroup);

    if(arr != NULL)
        free(arr);
    if(result != NULL)
        free(result);

}
void mode_test_3() {
    int len = 7;
    int lenexp = 1;
    const int msgLen = 30;
    float* arr = (float*)malloc(sizeof(float)*len);
    int nGroup = -1;
    GroupFloat** tempGroup = (GroupFloat**)malloc(sizeof(GroupFloat*)*len);
    GroupFloat** expected= (GroupFloat**)malloc(sizeof(GroupFloat*)*lenexp);
    for(int i=0; i<len; i++) {
        tempGroup[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }
    for(int i=0; i<lenexp; i++) {
        expected[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }

    int lo = 0;
    int hi = len - 1;
    expected[0]->data = 0.1;
    expected[0]->count= 2;

    arr[0] = 0.1;
    arr[1] = 0.1;
    arr[2] = 0.3;
    arr[3] = 0.4;
    arr[4] = 0.5;
    arr[5] = 0.6;
    arr[6] = 0.7;

    modeInfo(arr, len, tempGroup, &nGroup);
    char* result = (char*)malloc(sizeof(char)*nGroup*msgLen);
    result[0] = '\0';
    int repeating = -1;
    mode(tempGroup, nGroup, &repeating, result, msgLen);
    int k=0;
    printf("repeating=%d\n", repeating);
    printf("mode_test_3=%s\n", (repeating == 1) && isEqualGroupFloat(tempGroup[nGroup-1], expected[0]) ? "true" : "false");

    for(int i=0; i<lenexp; i++) {
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(expected != NULL)
        free(expected);

    for(int i=0; i<len; i++) {
       if(tempGroup[i] != NULL)
            free(tempGroup[i]);
    }
    if(tempGroup != NULL)
        free(tempGroup);

    if(arr != NULL)
        free(arr);
    if(result != NULL)
        free(result);
}

void mode_test_4() {
    int len = 7;
    int lenexp = 2;
    const int msgLen = 30;
    float* arr = (float*)malloc(sizeof(float)*len);
    int nGroup = -1;
    GroupFloat** tempGroup = (GroupFloat**)malloc(sizeof(GroupFloat*)*len);
    GroupFloat** expected= (GroupFloat**)malloc(sizeof(GroupFloat*)*lenexp);
    for(int i=0; i<len; i++) {
        tempGroup[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }
    for(int i=0; i<lenexp; i++) {
        expected[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }

    int lo = 0;
    int hi = len - 1;
    expected[0]->data = 0.1;
    expected[0]->count= 2;
    expected[1]->data = 0.5;
    expected[1]->count= 2;

    arr[0] = 0.1;
    arr[1] = 0.1;
    arr[2] = 0.3;
    arr[3] = 0.4;
    arr[4] = 0.5;
    arr[5] = 0.9;
    arr[6] = 0.5;

    modeInfo(arr, len, tempGroup, &nGroup);
    char* result = (char*)malloc(sizeof(char)*nGroup*msgLen);
    result[0] = '\0';
    int repeating = -1;
    mode(tempGroup, nGroup, &repeating, result, msgLen);
    int k=0;
    printf("mode_test_4=%s\n", ((repeating == 2) && 
                           (isEqualGroupFloat(tempGroup[nGroup-1], expected[0]) && 
                            isEqualGroupFloat(tempGroup[nGroup-2], expected[1]))) ||
                           ((isEqualGroupFloat(tempGroup[nGroup-1], expected[1]) && 
                            isEqualGroupFloat(tempGroup[nGroup-2], expected[0]))) 
                            ? "true" : "false");

    for(int i=0; i<lenexp; i++) {
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(expected != NULL)
        free(expected);

    for(int i=0; i<len; i++) {
       if(tempGroup[i] != NULL)
            free(tempGroup[i]);
    }
    if(tempGroup != NULL)
        free(tempGroup);

    if(arr != NULL)
        free(arr);
    if(result != NULL)
        free(result);
}

void mode_test_5() {
    int len = 5;
    int lenexp = 2;
    const int msgLen = 30;
    float* arr = (float*)malloc(sizeof(float)*len);
    int nGroup = -1;
    GroupFloat** tempGroup = (GroupFloat**)malloc(sizeof(GroupFloat*)*len);
    GroupFloat** expected= (GroupFloat**)malloc(sizeof(GroupFloat*)*lenexp);
    for(int i=0; i<len; i++) {
        tempGroup[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }
    for(int i=0; i<lenexp; i++) {
        expected[i] = (GroupFloat*)malloc(sizeof(GroupFloat));
    }

    int lo = 0;
    int hi = len - 1;
    expected[0]->data = 4.10;
    expected[0]->count= 2;
    expected[1]->data = 9.134;
    expected[1]->count= 2;

    arr[0] = 3.1004;
    arr[1] = 4.10;
    arr[2] = 9.134;
    arr[3] = 9.134;
    arr[4] = 4.10;

    modeInfo(arr, len, tempGroup, &nGroup);
    char* result = (char*)malloc(sizeof(char)*nGroup*msgLen);
    result[0] = '\0';
    int repeating = -1;
    mode(tempGroup, nGroup, &repeating, result, msgLen);
    int k=0;
    printf("mode_test_5=%s\n", ((repeating == 2) && 
                               (isEqualGroupFloat(tempGroup[nGroup-1], expected[0]) && 
                                isEqualGroupFloat(tempGroup[nGroup-2], expected[1]))) ||(
                           (isEqualGroupFloat(tempGroup[nGroup-1], expected[1]) && 
                            isEqualGroupFloat(tempGroup[nGroup-2], expected[0]))) 
                            ? "true" : "false");

    for(int i=0; i<lenexp; i++) {
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(expected != NULL)
        free(expected);

    for(int i=0; i<len; i++) {
       if(tempGroup[i] != NULL)
            free(tempGroup[i]);
    }
    if(tempGroup != NULL)
        free(tempGroup);

    if(arr != NULL)
        free(arr);
    if(result != NULL)
        free(result);
}

void test_group_0() {
    int len = 1;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.3;
    GroupFloat* groupFloat[1];
    groupFloat[0] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);

    GroupFloat* expected[1];
    expected[0] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);;
    expected[0]->data = 0.3;
    expected[0]->count = 1;

    int groupInx = 0;

    quickSort(arr, lo, hi);
    group(arr, len, groupFloat, &groupInx);

    quickSort(arr, lo, hi);

    printf("test_group_0=%s\n", compareGroupFloatList(groupFloat, expected, groupInx) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(groupFloat[i] != NULL)
            free(groupFloat[i]);

        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(arr != NULL)
        free(arr);
}

void test_group_1() {
    int len = 2;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.3;
    arr[1] = 0.4;

    GroupFloat** expected = (GroupFloat**) malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }

    expected[0] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[0]->data = arr[0];
    expected[0]->count = 1;

    expected[1] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[1]->data = arr[1];
    expected[1]->count = 1;

    GroupFloat** gf = (GroupFloat**) malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        gf[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }

    int groupInx = 0;
    quickSort(arr, lo, hi);
    group(arr, len, gf, &groupInx);

    printf("test_group_1=%s\n", compareGroupFloatList(gf, expected, groupInx) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(gf[i] != NULL)
            free(gf[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(arr != NULL)
        free(arr);
}

void test_group_2() {
    int len = 3;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.3;
    arr[1] = 0.4;
    arr[2] = 0.3;

    GroupFloat** expected = (GroupFloat**) malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }

    expected[0] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[0]->data = 0.3;
    expected[0]->count = 2;

    expected[1] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[1]->data = 0.4;
    expected[1]->count = 1;

    GroupFloat** gf = (GroupFloat**) malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        gf[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }
    int groupInx = 0;
    quickSort(arr, lo, hi);
    group(arr, len, gf, &groupInx);

    // there are only two group {0.3, 0.3} {0.4}
    printf("test_group_2=%s\n", compareGroupFloatList(gf, expected, groupInx) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(gf[i] != NULL)
            free(gf[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(arr != NULL)
        free(arr);
}

void test_group_3() {
    int len = 4;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.3;
    arr[1] = 0.4;
    arr[2] = 0.3;
    arr[3] = 0.4;

    GroupFloat** expected = (GroupFloat**) malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }

    expected[0] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[0]->data = 0.3;
    expected[0]->count = 2;

    expected[1] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[1]->data = 0.4;
    expected[1]->count = 2;

    GroupFloat** gf = (GroupFloat**) malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        gf[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }
    int groupInx = 0;
    quickSort(arr, lo, hi);
    group(arr, len, gf, &groupInx);

    // there are only two group {0.3, 0.3} {0.4}
    printf("test_group_3=%s\n", compareGroupFloatList(gf, expected, groupInx) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(gf[i] != NULL)
            free(gf[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(arr != NULL)
        free(arr);
}
void test_group_4() {
    int len = 5;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.9;
    arr[1] = 0.4;
    arr[2] = 0.3;
    arr[3] = 0.4;
    arr[4] = 0.3;

    GroupFloat** expected = (GroupFloat**) malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }

    expected[0] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[0]->data = 0.3;
    expected[0]->count = 2;

    expected[1] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[1]->data = 0.4;
    expected[1]->count = 2;

    expected[2] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[2]->data = 0.9;
    expected[2]->count = 1;

    GroupFloat** gf = (GroupFloat**) malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        gf[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }
    int groupInx = 0;
    quickSort(arr, lo, hi);
    group(arr, len, gf, &groupInx);

    // there are only two group {0.3, 0.3} {0.4}
    printf("test_group_4=%s\n", compareGroupFloatList(gf, expected, groupInx) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(gf[i] != NULL)
            free(gf[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(arr != NULL)
        free(arr);
}

void test_group_5() {
    int len = 8;
    float* arr = (float*)malloc(sizeof(float)*len);
    int lo = 0;
    int hi = len - 1;

    arr[0] = 0.9;
    arr[1] = 0.4;
    arr[2] = 0.3;
    arr[3] = 0.4;
    arr[4] = 0.3;
    arr[5] = 0.1;
    arr[6] = 0.1;
    arr[7] = 0.1;

    GroupFloat** expected = (GroupFloat**) malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        expected[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }

    expected[0] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[0]->data = 0.1;
    expected[0]->count = 3;

    expected[1] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[1]->data = 0.3;
    expected[1]->count = 2;

    expected[2] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[2]->data = 0.4;
    expected[2]->count = 2;

    expected[3] = (GroupFloat*)malloc(sizeof(GroupFloat)*1);
    expected[3]->data = 0.9;
    expected[3]->count = 1;

    GroupFloat** gf = (GroupFloat**)malloc(sizeof(GroupFloat*)*len);
    for(int i=0; i<len; i++) {
        gf[i] = (GroupFloat*) malloc(sizeof(GroupFloat)*1);
    }
    int groupInx = 0;
    quickSort(arr, lo, hi);
    group(arr, len, gf, &groupInx);

    // there are only two group {0.3, 0.3} {0.4}
    printf("test_group_5=%s\n", compareGroupFloatList(gf, expected, groupInx) ? "true" : "false");

    for(int i=0; i<len; i++) {
        if(gf[i] != NULL)
            free(gf[i]);
        if(expected[i] != NULL)
            free(expected[i]);
    }
    if(arr != NULL)
        free(arr);
}

void test_group_6() {
    {
        char* expStr = "---";
        char result[3];
        repeat_c(3, '-', result);
        printf("test_group_6=%s\n", (cmpStrN(result, expStr, 3) == true) ? "true" : "false");
    }
    {
        char* expStr = "";
        char result[10];
        repeat_c(0, '-', result);
        printf("test_group_6=%s\n", (cmpStrN(result, expStr, 0) == true) ? "true" : "false");
    }
}
void test_group_7() {
    {
        char s1[50] = "--";
        const char str[] = "x";
        char* expStr = "-x";
        copyStrAt(s1, str, 1);
        ppp("s1=%s\n", s1);
        ppp("test_group_7=%s\n", (cmpStr(s1, expStr) == true) ? "true" : "false");
    }
    {
        char s1[2] = "-";
        const char str[] = "x";
        char* expStr = "x";
        copyStrAt(s1, str, 0);
        ppp("s1=%s\n", s1);
        ppp("test_group_7=%s\n", (cmpStr(s1, expStr) == true) ? "true" : "false");
    }
    {
        char s1[1] = "";
        const char str[] = "";
        char* expStr = "";
        plen("s1", s1);
        plen("str", str);
        plen("expStr", expStr);
        copyStrAt(s1, str, 0);
        plen("s1", s1);
        ppp("test_group_7=%s\n", (cmpStr(s1, expStr) == true) ? "true" : "false");
    }
    {
        char s1[2] = "-";
        const char str[] = "x";
        char* expStr = "x";
        plen("s1", s1);
        plen("str", str);
        plen("expStr", expStr);
        copyStrAt(s1, str, 0);
        ppp("s1=%s\n", s1);
        ppp("test_group_7=%s\n", (cmpStr(s1, expStr) == true) ? "true" : "false");
    }
}

void test8(){
  {
    int arr[1] = {1};
    int lo = 0;
    int hi = 0;
    int k = 1;
    bool b = BinarySearch(arr, lo, hi, k);
    printf("test0 => %d\n", b == true);
  }
  {
    int arr[1] = {1};
    int lo = 0;
    int hi = 0;
    int k = 2;
    bool b = BinarySearch(arr, lo, hi, k);
    printf("test0 => %d\n", b == false);
  }
  {
    int arr[2] = {1, 2};
    int lo = 0;
    int hi = 1;
    int k = 2;
    bool b = BinarySearch(arr, lo, hi, k);
    printf("test0 => %d\n", b == true);
  }
  {
    int arr[2] = {1, 2};
    int lo = 0;
    int hi = 1;
    int k = 1;
    bool b = BinarySearch(arr, lo, hi, k);
    printf("test0 => %d\n", b == true);
  }
  {
    int arr[2] = {1, 2};
    int lo = 0;
    int hi = 1;
    int k = 3;
    bool b = BinarySearch(arr, lo, hi, k);
    printf("test0 => %d\n", b == false);
  }
  {
    int arr[3] = {1, 2, 3};
    int lo = 0;
    int hi = 2;
    int k = 2;
    bool b = BinarySearch(arr, lo, hi, k);
    printf("test0 => %d\n", b == true);
  }
  {
    int arr[3] = {1, 2, 3};

    int lo = 0;
    int hi = 2;
    int k = 3;
    bool b = BinarySearch(arr, lo, hi, k);
    printf("test0 => %d\n", b == true);
  }
  {
    int arr[3] = {1, 2, 3};
    int lo = 0;
    int hi = 2;
    int k = 1;
    bool b = BinarySearch(arr, lo, hi, k);
    printf("test0 => %d\n", b == true);
  }
  {
    int arr[3] = {1, 2, 3};
    int lo = 0;
    int hi = 2;
    int k = 4;
    bool b = BinarySearch(arr, lo, hi, k);
    printf("test0 => %d\n", b == false);
  }
}


void dropChar_test(){
  {
    char arr[] = "abcd";
    dropChar(2, arr);
    ppp("dropChar_test=%s\n", cmpStr(arr, "cd") ? "true" : "false");
  }
  {
    char arr[] = "abcd";
    dropChar(0, arr);
    ppp("dropChar_test=%s\n", cmpStr(arr, "abcd") ? "true" : "false");
  }
  {
    char arr[] = "abcd";
    dropChar(4, arr);
    ppp("dropChar_test=%s\n", cmpStr(arr, "") ? "true" : "false");
  }
  {
    char arr[] = "abcd";
    dropChar(-1, arr);
    ppp("dropChar_test=%s\n", cmpStr(arr, "abc") ? "true" : "false");
  }
  {
    char arr[] = "abcd";
    dropChar(-4, arr);
    ppp("dropChar_test=%s\n", cmpStr(arr, "") ? "true" : "false");
  }
  {
    char arr[] = "abcd";
    dropChar(-3, arr);
    ppp("dropChar_test=%s\n", cmpStr(arr, "a") ? "true" : "false");
  }
}

void dropCharImmutable_test(){
  {
    {
      char arr[] = "abcd";
      char* narr = dropCharImmutable(1, arr);
      ppp("dropCharImmutable_test=%s\n", cmpStr(narr, "bcd") ? "true" : "false");
      free(narr);
    }
    {
      char arr[] = "abcd";
      char* narr = dropCharImmutable(4, arr);
      ppp("dropCharImmutable_test=%s\n", cmpStr(narr, "") ? "true" : "false");
      free(narr);
    }
    {
      char arr[] = "";
      char* narr = dropCharImmutable(0, arr);
      ppp("dropCharImmutable_test=%s\n", cmpStr(narr, "") ? "true" : "false");
      free(narr);
    }
    {
      char arr[] = "abcd";
      char* narr = dropCharImmutable(0, arr);
      ppp("dropCharImmutable_test=%s\n", cmpStr(narr, "abcd") ? "true" : "false");
      free(narr);
    }
    {
      char arr[] = "abcd";
      char* narr = dropCharImmutable(-1, arr);
      ppp("dropCharImmutable_test=%s\n", cmpStr(narr, "abc") ? "true" : "false");
      free(narr);
    }
    {
      char arr[] = "abcd";
      char* narr = dropCharImmutable(-4, arr);
      ppp("dropCharImmutable_test=%s\n", cmpStr(narr, "") ? "true" : "false");
      free(narr);
    }
    {
      char arr[] = "abcd";
      char* narr = dropCharImmutable(-3, arr);
      ppp("dropCharImmutable_test=%s\n", cmpStr(narr, "a") ? "true" : "false");
      free(narr);
    }
  }
}

void match_test(){
  {
    char regex[] = ".";
    char text[] = "a";
    char start = regex[0];
    int ret = match(start, regex, text);
    printf("1 match_test=>%s\n", ret ? "true" : "false");
  }
  {
    char regex[] = ".b";
    char text[] = "ab";
    char start = regex[0];
    int ret = match(start, regex, text);
    printf("1 match_test=>%s\n", ret ? "true" : "false");
  }
  {
    char regex[] = ".*a";
    char text[] = "a";
    char start = regex[0];
    int ret = match(start, regex, text);
    printf("2 match_test=>%s\n", ret ? "true" : "false");
  }
  {
    char regex[] = ".*ab";
    char text[] = "ab";
    char start = regex[0];
    int ret = match(start, regex, text);
    printf("3 match_test=>%s\n", ret ? "true" : "false");
  }
  
  {
    char regex[] = ".*a.";
    char text[] = "ab";
    char start = regex[0];
    int ret = match(start, regex, text);
    printf("4 match_test=>%s\n", ret ? "true" : "false");
  }
  
  {
    char regex[] = ".*a.c";
    char text[] = "abc";
    char start = regex[0];
    int ret = match(start, regex, text);
    printf("5 match_test=>%s\n", ret ? "true" : "false");
  }
  
  {
    char regex[] = ".*a.b";
    char text[] = "abc";
    char start = regex[0];
    int ret = match(start, regex, text);
    printf("6 match_test=>%s\n", ret ? "true" : "false");
  }
  
}

void mytest(){
  {
    int len = 10;
    char* pt = (char*)malloc(sizeof(char)*len);
    for(int i = 0; i < 10; i++){
      *(pt + i) = 'a' + i;
    }
    printf("mytest=>%s\n", pt);
    for(int i = 0; i < len; i++){
      printf("%c ", pt[i]);
    }
    free(pt);
  }
  {
    char* pt;
    testit(&pt);
    printf("pt=[%s]\n", pt);
  }
}

void single_linked_list_test(){
  {
    List* list = createList(compareTo, toString, freeObject);
    int n1 = 10;
    CNode* nodePt = createNode(&n1);
    addFirst(list, nodePt);
    int result = *((int*)(list -> head -> data));
    printf("1 single_linked_list_test=> %s\n", result == 10 ? "true" : "false");
  }
  {
    List* list = createList(compareTo, toString, freeObject);
    int n1 = 10;
    CNode* nodePt = createNode(&n1);
    addFirst(list, nodePt);

    int n2 = 20;
    CNode* nodePt1 = createNode(&n2);
    addFirst(list, nodePt1);

    CNode* curr = list -> head;
    int arr[2];
    int inx = 0;
    while(curr){
      arr[inx] = *((int*)curr -> data);
      inx++;
      curr = curr -> next;
    }
    printf("2 single_linked_list_test=>%s\n", arr[0] == 20 ? "true" : "false");
    printf("3 single_linked_list_test=>%s\n", arr[1] == 10 ? "true" : "false");
    
    int arr1[2];
    int inx1 = 0;
    CNode* curr1 = list -> head;
    while(curr1){
      arr1[inx1] = *((int*)curr1 -> data);
      inx1++;
      curr1 = curr1 -> next;
    }
    
    printf("21 single_linked_list_test=>%s\n", arr1[0] == 20 ? "true" : "false");
    printf("31 single_linked_list_test=>%s\n", arr1[1] == 10 ? "true" : "false");
  }
  {
        List* list = createList(compareTo, toString, freeObject);
    int n1 = 10;
    CNode* nodePt = createNode(&n1);
    addFirst(list, nodePt);
    int result = *((int*)(list -> head -> data));
    printf("1 single_linked_list_test=> %s\n", result == 10 ? "true" : "false");
    freeObject(list);
  }
  
  {
    List* list = createList(compareTo, toString, freeObject);
    int n1 = 10;
    CNode* node1 = createNode(&n1);
    addFirst(list, node1);
    
    int n2 = 20;
    CNode* node2 = createNode(&n2);
    addFirst(list, node2);
    
    CNode* curr = list -> head;
    int arr[2];
    int inx = 0;
    while(curr){
      arr[inx] = *((int*)curr -> data);
      inx++;
      curr = curr -> next;
    }
    printf("31 single_linked_list_test=>%s\n", arr[0] == 20 ? "true" : "false");
    printf("41 single_linked_list_test=>%s\n", arr[1] == 10 ? "true" : "false");

    deleteFirst(list);
    int result = *((int*)list -> head -> data);
    printf("51 single_linked_list_test=>%d\n", result);
  }
  {
    List* list = createList(compareTo, toString, freeObject);
    int n1 = 10;
    CNode* node1 = createNode(&n1);
    addFirst(list, node1);
    
    int n2 = 20;
    CNode* node2 = createNode(&n2);
    addFirst(list, node2);

    deleteFirst(list);
    CNode* curr = list -> head;

    int count = 0;
    while(curr){
      curr = curr -> next;
      count++;
    }

    printf("61 single_linked_list_test count == 1 =>%s\n", count == 1? "true" : "false");
  }
  
  {
    List* list = createList(compareTo, toString, freeObject);
    int n1 = 10;
    CNode* node1 = createNode(&n1);
    addFirst(list, node1);
    
    int n2 = 20;
    CNode* node2 = createNode(&n2);
    addFirst(list, node2);
    
    int n3 = 30;
    CNode* node3 = createNode(&n3);
    addFirst(list, node3);

    deleteFirst(list);
    CNode* curr = list -> head;

    int count = 0;
    while(curr){
      curr = curr -> next;
      count++;
    }

    printf("62 single_linked_list_test count == 2 =>%s\n", count == 2? "true" : "false");
  }
  {
    List* list = createList(compareTo, toString, freeObject);
    int n1 = 10;
    CNode* node1 = createNode(&n1);
    addFirst(list, node1);
    
    int n2 = 20;
    CNode* node2 = createNode(&n2);
    addFirst(list, node2);
    
    int n3 = 30;
    CNode* node3 = createNode(&n3);
    addFirst(list, node3);

    deleteFirst(list);
    CNode* curr = list -> head;

    int arr[2];
    int inx = 0;
    while(curr){
      arr[inx] = *((int*)(curr-> data));
      curr = curr -> next;
      inx++;
    }

    printf("63 single_linked_list_test =>%s\n", arr[0] == 20? "true" : "false");
    printf("64 single_linked_list_test =>%s\n", arr[1] == 10? "true" : "false");
  }

  {
    List* list = createList(compareTo, toString, freeInt);
    int* n1 = (int*)malloc(sizeof(int));
    *n1 = 10;
    
    CNode* nodePt = createNode(n1);
    addFirst(list, nodePt);
    int result = *((int*)(list -> head -> data));
    printf("71 single_linked_list_test=> %s\n", result == 10 ? "true" : "false");
  }
  {
    List* list = createList(compareTo, toString, freeInt);

    for(int i = 0; i < 3; i++){
      int* n1 = (int*)malloc(sizeof(int));
      *n1 = i;
    
      CNode* nodePt = createNode(n1);
      addFirst(list, nodePt);
    }
    ppp("80 => list -> size == 3\n", list -> size == 3);
    t(list -> size == 3, "list -> size == 3");

    
    CNode* curr = list -> head;
    while(curr){
      int result = *(int*)curr -> data;
      ppp("81 => result %d\n", result);
      curr = curr -> next;
    }
    t(list -> size == 3, "list -> size == 3");
    
    CNode* curr1 = list -> head;
    {
      while(curr1){
	int result = *(int*)curr1 -> data;
	ppp("82 => result %d\n", result);
	curr1 = curr1 -> next;
      }
    }
    t(list -> size == 3, "list -> size == 3");
    
    deleteFirst(list);
    {
      CNode* curr1 = list -> head;
      while(curr1){
	int result = *(int*)curr1 -> data;
	ppp("83 => result %d\n", result);
	curr1 = curr1 -> next;
      }
    }
    t(list -> size == 2, "list -> size == 2");
    
    deleteFirst(list);
    {
      CNode* curr1 = list -> head;
      while(curr1){
	int result = *(int*)curr1 -> data;
	ppp("83 => result %d\n", result);
	curr1 = curr1 -> next;
      }
    }
    t(list -> size == 1, "list -> size == 1");
    
    deleteFirst(list);
    {
      CNode* curr1 = list -> head;
      while(curr1){
	int result = *(int*)curr1 -> data;
	ppp("83 => result %d\n", result);
	curr1 = curr1 -> next;
      }
    }
    t(list -> size == 0, "list -> size == 0");
    
    deleteFirst(list);
    {
      CNode* curr1 = list -> head;
      while(curr1){
	int result = *(int*)curr1 -> data;
	ppp("83 => result %d\n", result);
	curr1 = curr1 -> next;
      }
    }
    t(list -> size == 0, "list -> size == 0");
  }
}
void trim_test(){
  {
    char* str = "";
    char* newStr = trim(str);
    t(cmpStr(newStr, ""), "200 newStr =>Empty");
    free(newStr);
  }
  {
    char* str = "   ";
    char* newStr = trim(str);
    t(cmpStr(newStr, ""), "201 newStr =>Empty");
    free(newStr);
  }

  {
    char* str = "abc";
    char* newStr = trim(str);
    t(cmpStr(newStr, "abc"), "202 newStr => abc");
    free(newStr);
  }
  
  {
    char* str = "   abc ";
    char* newStr = trim(str);
    t(cmpStr(newStr, "abc"), "203 newStr => abc");
    free(newStr);
  }
  {
    char* str = "   a bc ";
    char* newStr = trim(str);
    t(cmpStr(newStr, "a bc"), "204 newStr => abc");
    free(newStr);
  }
  {
    char* str = "   a ";
    char* newStr = trim(str);
    t(cmpStr(newStr, "a"), "205 newStr => abc");
    free(newStr);
  }
  
}

void deleteLast_test(){
  {
    {
      List* list = createList(compareTo, toString, freeObject);
      int n1 = 10;
      CNode* node1 = createNode(&n1);
      addFirst(list, node1);

      deleteLast(list);
      CNode* curr = list -> head;
      int count = 0;
      while(curr){
	curr = curr -> next;
	count++;
      }
      printf("deleteLast => count == 0 %s\n", count == 0 ? "true" : "false");
    }
    {
      List* list = createList(compareTo, toString, freeObject);
      
      int n1 = 10;
      CNode* node1 = createNode(&n1);
      addFirst(list, node1);
      
      int n2 = 20;
      CNode* node2 = createNode(&n2);
      addFirst(list, node2);

      deleteLast(list);
      CNode* curr = list -> head;
      int count = 0;
      while(curr){
	curr = curr -> next;
	count++;
      }
      printf("deleteLast => count == 1 %s\n", count == 1 ? "true" : "false");
    }
    {
      List* list = createList(compareTo, toString, freeObject);
      
      int n1 = 10;
      CNode* node1 = createNode(&n1);
      addFirst(list, node1);
      
      int n2 = 20;
      CNode* node2 = createNode(&n2);
      addFirst(list, node2);
      
      int n3 = 30;
      CNode* node3 = createNode(&n3);
      addFirst(list, node3);

      deleteLast(list);
      CNode* curr = list -> head;
      int count = 0;
      while(curr){
	curr = curr -> next;
	count++;
      }
      printf("deleteLast => count == 2 %s\n", count == 2 ? "true" : "false");
    }
    {

      // 30 20 10
      List* list = createList(compareTo, toString, freeObject);
      
      int n1 = 10;
      CNode* node1 = createNode(&n1);
      addFirst(list, node1);
      
      int n2 = 20;
      CNode* node2 = createNode(&n2);
      addFirst(list, node2);
      
      int n3 = 30;
      CNode* node3 = createNode(&n3);
      addFirst(list, node3);

      deleteLast(list);
      CNode* curr = list -> head;
      int inx = 0;
      int arr[2];
      while(curr){
	arr[inx] = *((int*)(curr -> data));
	curr = curr -> next;
	inx++;
      }
      printf("deleteLast => %s\n", arr[0] == 30 ? "true" : "false");
      printf("deleteLast => %s\n", arr[1] == 20 ? "true" : "false");
    }
  }
  {
    List* list = createList(compareTo, toString, freeObject);
    int n1 = 10;
    CNode* node1 = createNode(&n1);
    addLast(list, node1);

    CNode* curr = list -> head;
    int count = 0;
    while(curr){
      curr = curr -> next;
      count++;
    }
    int headInt = *(int*)(list -> head -> data);
    printf("addList => count == 1 %s\n", count == 1 ? "true" : "false");
    printf("addList => headInt == 10 %s\n", headInt == 10 ? "true" : "false");
  }
  {
    List* list = createList(compareTo, toString, freeObject);
    int n1 = 10;
    CNode* node1 = createNode(&n1);
    addFirst(list, node1);
    int n2 = 200;
    CNode* node2 = createNode(&n2);
    addLast(list, node2); 

    CNode* curr = list -> head;
    int count = 0;
    while(curr){
      curr = curr -> next;
      count++;
    }
    ppp("addList => count == 2 %s\n", count == 2 ? "true" : "false");
    int headInt = *((int*)list -> head -> data);
    int tailInt = *((int*)list -> tail -> data);
    ppp("addList => headInt == 10 %s\n",  headInt == 10 ? "true" : "false");
    ppp("addList => tailInt == 200 %s\n", tailInt == 200 ? "true" : "false");
  }

  {
    List* list = createList(compareTo, toString, freeInt);
    for(int i = 0; i < 3; i++){
      int* n1 = (int*)malloc(sizeof(int));
      *n1 = i;
    
      CNode* nodePt = createNode(n1);
      addFirst(list, nodePt);
    }

    deleteIndexNode(list, 0);
    
    t(list -> size == 2, "90 list -> size == 2");
  }
  
  {
    List* list = createList(compareTo, toString, freeInt);
    for(int i = 0; i < 3; i++){
      int* n1 = (int*)malloc(sizeof(int));
      *n1 = i;
    
      CNode* nodePt = createNode(n1);
      addFirst(list, nodePt);
    }

    deleteIndexNode(list, 1);
    
    t(list -> size == 2, "91 list -> size == 2");
  }
  {
    List* list = createList(compareTo, toString, freeInt);
    for(int i = 0; i < 3; i++){
      int* n1 = (int*)malloc(sizeof(int));
      *n1 = i;
    
      CNode* nodePt = createNode(n1);
      addFirst(list, nodePt);
    }
    // [2]  [1]  [0]
    deleteIndexNode(list, 1);
    int head = *(int*)list -> head -> data;
    int tail = *(int*)list -> tail -> data;
    t(head == 2, "92 head == 2");
    t(tail == 0, "93 tail == 0");
  }
  {
    List* list = createList(compareTo, toString, freeInt);
    for(int i = 0; i < 3; i++){
      int* n1 = (int*)malloc(sizeof(int));
      *n1 = i;
    
      CNode* nodePt = createNode(n1);
      addLast(list, nodePt);
    }
    // [0]  [1]  [2]
    deleteIndexNode(list, 1);
    int head = *(int*)list -> head -> data;
    int tail = *(int*)list -> tail -> data;
    t(head == 0, "94 head == 0");
    t(tail == 2, "95 tail == 2");
  }
  {
    List* list = createList(compareTo, toString, freeInt);
    for(int i = 0; i < 3; i++){
      int* n1 = (int*)malloc(sizeof(int));
      *n1 = i;
    
      CNode* nodePt = createNode(n1);
      addLast(list, nodePt);
    }
    // [0]  [1]  [2]
    deleteIndexNode(list, 1);
    deleteIndexNode(list, 1);
    int head = *(int*)list -> head -> data;
    int tail = *(int*)list -> tail -> data;
    t(head == 0, "96 head == 0");
    t(list -> size == 1, "97 list -> size == 1");
  }
  {
    List* list = createList(compareTo, toString, freeInt);
    for(int i = 0; i < 3; i++){
      int* n1 = (int*)malloc(sizeof(int));
      *n1 = i;
    
      CNode* nodePt = createNode(n1);
      addLast(list, nodePt);
    }
    // [0]  [1]  [2]
    deleteIndexNode(list, 1);
    deleteIndexNode(list, 1);
    deleteIndexNode(list, 0);
    t(list -> size == 0, "98 list -> size == 0");
    t(list -> head == NULL, "99 list -> head == NULL");
    t(list -> tail == NULL, "100 list -> tail == NULL");
  }
  {
    List* list = createList(compareTo, toString, freeInt);
    for(int i = 0; i < 3; i++){
      int* n1 = (int*)malloc(sizeof(int));
      *n1 = i;
    
      CNode* nodePt = createNode(n1);
      addLast(list, nodePt);
    }
    // [0]  [1]  [2]
    deleteIndexNode(list, 0);
    deleteIndexNode(list, 0);
    deleteIndexNode(list, 0);
    t(list -> size == 0, "101 list -> size == 0");
    t(list -> head == NULL, "102 list -> head == NULL");
    t(list -> tail == NULL, "103 list -> tail == NULL");
  }
  {
    const char* arr[] = {
      "apple",
      "banana",
      "cherry"
    };
      
    List* list = createList(compareTo, toString, freeStr);
    int len = 100;
    for(int i = 0; i < 3; i++){
      char* pt = (int*)malloc(sizeof(char)*len);
      strcpy(pt + i, arr[i]);
      
      CNode* nodePt = createNode(pt + i);
      addLast(list, nodePt);
    }
    t(list -> size == 3, "104 list -> size == 3");
    t(cmpStr(arr[0], list -> head -> data), "105 arr[0], list -> head -> data");
    t(cmpStr(arr[2], list -> tail -> data), "106 arr[2], list -> head -> data");
  }
  {
    const char* arr[] = {
      "apple",
      "banana",
      "cherry"
    };
      
    List* list = createList(compareTo, toString, freeStr);
    int len = 100;
    for(int i = 0; i < 3; i++){
      CNode* nodePt = createNode(arr[i]);
      addLast(list, nodePt);
    }
    printListNewLine(list);
    /*
    t(list -> size == 3, "104 list -> size == 3");
    t(cmpStr(arr[0], list -> head -> data), "105 arr[0], list -> head -> data");
    t(cmpStr(arr[2], list -> tail -> data), "106 arr[2], list -> head -> data");
    */
  }
  
  {
    List* list = createList(compareTo, toString, freeStr);
    readFileToList("/tmp/x1.x", list);
    if(list != NULL){
      printList(list);
    }else{
      ppp("list is NULL\n");
    }
    ppp("line count=[%d]\n", list -> size);
    freeList(list);
    free(list);
  }

  {
    List* list = createList(compareTo, toString, freeStr);
    readFileToList("/tmp/x1.x", list);
    if(list != NULL){
      printList(list);
    }else{
      ppp("list is NULL\n");
    }
    ppp("line count=[%d]\n", list -> size);

    int flen = list -> size;
    char** arr = (char**)malloc(sizeof(char*)*flen);

    CNode* curr = list -> head;
    int inx = 0;
    while(curr){
      arr[inx] = (char*)malloc(sizeof(char)*strlen(curr -> data));
      strcpy(arr[inx], curr -> data);
      curr = curr -> next;
      inx++;
    }

    int lo = 0;
    int hi = inx - 1;
    quickSortAny(arr,  cmpStr, lo, hi);

    for(int i = 0; i < flen; i++){
      ppp("%s\n", arr[i]);
    }

    for(int i = 0; i < flen; i++){
      free(arr[i]);
    }
    free(arr);
    
    freeList(list);
    free(list);
  }
}

void splitStr_test(){
  {
    char* str = " abc    cat pig banana cherry ";
    List* list = splitStr(str);
    printListNewLine(list);
    freeList(list);
    free(list);
  }
}

void alltests() {
    partition_test0();
    partition_test1();
    partition_test2();

    quickSort_test0();
    quickSort_test1();
    quickSort_test2();
    quickSort_test3();
    quickSort_test4();
    quickSort_test5();
    quickSort_test6();


    test_mean_0();
    test_mean_1();
    test_mean_2();
    test_mean_3();
    test_mean_4();

    test_median_0();
    test_median_1();
    test_median_2();
    test_median_3();

    test_group_0();
    test_group_1();
    test_group_2();
    test_group_3();
    test_group_4();
    test_group_5();



    mode_test_0();

    mode_test_1();
    mode_test_2();
    mode_test_3();
    mode_test_4();
    mode_test_5();

    standarddeviation_test_0();
    standarddeviation_test_1();
    standarddeviation_test_2();
    standarddeviation_test_3();
    standarddeviation_test_4();

    cmpStr_test_0();
    cmpStr_test_1();
    cmpStr_test_2();
    cmpStr_test_3();

    test_group_6();
    test_group_7();

    
    quickSortAny_test0();
    quickSortAny_test1();
    quickSortAny_test2();
    quickSortAny_test3();
    quickSortAny_test4();
    quickSortAny_test5();
    quickSortAny_test6();

    
    partitionAny_test_0();
    partitionAny_test_1();
    partitionAny_test_2();
    partitionAny_test_3();
    partitionAny_test_4();
    partitionAny_test_5();
    partitionAny_test_6();

    dropChar_test();
    dropCharImmutable_test();
    match_test();
    single_linked_list_test();
    deleteLast_test();
    trim_test();
    splitStr_test();
    mytest();
}


int main (int argc, char* argv[]) {
    alltests();
    // test8();
    return(0);
}
