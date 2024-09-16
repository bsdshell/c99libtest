#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "AronCLibNew.h"

/**
 @file

 @brief The library only use C standard library

 KEY: gcc -I$b/cpplib -o /tmp/AronCLibNewTest  $b/clib/AronCLibNewTest.c
 
 Mon May  4 21:35:35 2020 
 passed all tests

*/
void splitPath_test(){
    {
        char* str = "usr/tmp/f.x";
        int retLen = 0;
        int len = strlen(str);
        char c = '/';
        char** retppt = splitPath(str, len, &retLen, c);
        if(retppt){
            t_int(retLen, 3, " test 0");
            free_splitPath(retppt, retLen);
        }else{
            printf("retppt is NULL\n");
        }
    }

    {
        char* str = "usr";
        int retLen = 0;
        int len = strlen(str);
        char c = '/';
        char** retppt = splitPath(str, len, &retLen, c);
        if(retppt){
            t_int(retLen, 1, " test 1");
            free_splitPath(retppt, retLen);
        }else{
            printf("retppt is NULL\n");
        }
    }

    {
        char* str = "/";
        int retLen = 0;
        int len = strlen(str);
        char c = '/';
        char** retppt = splitPath(str, len, &retLen, c);
        if(retppt){
            t_int(retLen, 1, " test 2");
            free_splitPath(retppt, retLen);
        }else{
            printf("retppt is NULL\n");
        }
    }
	
	{
        char* str = "/";
        int retLen = 0;
        int len = strlen(str);
        char c = '/';
        char** retppt = splitPath(str, len, &retLen, c);
        if(retppt){
            t_int(retLen, 1, " test 2");
            free_splitPath(retppt, retLen);
        }else{
            printf("retppt is NULL\n");
        }
    }
	{
        char* str = "//";
        int retLen = 0;
        int len = strlen(str);
        char c = '/';
        char** retppt = splitPath(str, len, &retLen, c);
        if(retppt){
            t_int(retLen, 2, " test // 2");
            free_splitPath(retppt, retLen);
        }else{
            printf("retppt is NULL\n");
        }
    }

    {
        char* str = "//";
        int retLen = 0;
        int len = strlen(str);
        char c = '/';
        char** retppt = splitPath(str, len, &retLen, c);
        if(retppt){
            t_int(retLen, 2, " test 3");
            free_splitPath(retppt, retLen);
        }else{
            printf("retppt is NULL\n");
        }
    }

    {
        char* str = "/tmp/f.x";
        int retLen = 0;
        int len = strlen(str);
        char c = '/';
        char** retppt = splitPath(str, len, &retLen, c);
        if(retppt){
            t_int(retLen, 3, " splitPath 4 0");

            t_charPt(retppt[0], "", " splitPath 4 1");
            t_charPt(retppt[1], "tmp", " splitPath 4 2");
            t_charPt(retppt[2], "f.x", " splitPath 4 3");

            free_splitPath(retppt, retLen);

        }else{
            printf("retppt is NULL\n");
        }
    }

    {
        char* str = "usr/tmp/f.x";
        int retLen = 0;
        int len = strlen(str);
        char c = '/';
        char** retppt = splitPath(str, len, &retLen, c);
        if(retppt){
            t_int(retLen, 3, " splitPath 5 0");

            t_charPt(retppt[0], "usr", " splitPath 5 1");
            t_charPt(retppt[1], "tmp", " splitPath 5 2");
            t_charPt(retppt[2], "f.x", " splitPath 5 3");

            free_splitPath(retppt, retLen);

        }else{
            printf("retppt is NULL\n");
        }
    }

    {
        char* str = "dir1/dir2/f.x";
        int retLen = 0;
        int len = strlen(str);
        char c = '/';
        char** retppt = splitPath(str, len, &retLen, c);
        if(retppt){
            t_int(retLen, 3, " splitPath 6 0");

            t_charPt(retppt[0], "dir1", " splitPath 6 1");
            t_charPt(retppt[1], "dir2", " splitPath 6 2");
            t_charPt(retppt[2], "f.x", " splitPath 6 3");

            free_splitPath(retppt, retLen);

        }else{
            printf("retppt is NULL\n");
        }
    }

	{
	 char c = '/';
	 char* str = "/d1/d2/d3/f.x";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitPath(str, bufLen, &retRow, c);
	 t_int(retRow, 5, " splitPath 5 ");
	 t_charPt(retppt[0], "", " splitPath 6");
	 t_charPt(retppt[1], "d1", " splitPath 7");
	 t_charPt(retppt[2], "d2", " splitPath 8");
	 t_charPt(retppt[3], "d3", " splitPath 9");
	 t_charPt(retppt[4], "f.x", " splitPath 10");
   }
   
}

void splitStrChar_test(){
  pl("splitStrChar_test");
  {
	char c = '/';
	char* str = "/";
	int bufLen = strlen(str);
	int retRow = 0;
	char** retppt = splitStrChar(str, bufLen, &retRow, c);
	t_int(retRow, 3, " splitStrChar xx 1");
	t_charPt(retppt[0], "", " splitStrChar xx 2");
	t_charPt(retppt[1], "/", " splitStrChar xx 2");
	t_charPt(retppt[2], "", " splitStrChar xx 2");
	printCharPt2d(retppt, retRow);
  }
  {
	char c = '/';
	char* str = "//";
	int bufLen = strlen(str);
	int retRow = 0;
	char** retppt = splitStrChar(str, bufLen, &retRow, c);
	t_int(retRow, 5,           " splitStrChar 1 ");
	t_charPt(retppt[0], "",   " splitStrChar 2");
	t_charPt(retppt[1], "/", " splitStrChar 3");
	t_charPt(retppt[2], "", " splitStrChar  4");
	t_charPt(retppt[3], "/", " splitStrChar  5");
	t_charPt(retppt[4], "", " splitStrChar  5");
	printCharPt2d(retppt, retRow);
  }
  {
	char c = '/';
	char* str = "/tmp/f.x";
	int bufLen = strlen(str);
	int retRow = 0;
	char** retppt = splitStrChar(str, bufLen, &retRow, c);
	t_int(retRow, 5,           " splitStrChar kk 1 ");
	t_charPt(retppt[0], "",    " splitStrChar kk 2");
	t_charPt(retppt[1], "/",   " splitStrChar kk 3");
	t_charPt(retppt[2], "tmp", " splitStrChar kk 4");
	t_charPt(retppt[3], "/",   " splitStrChar kk 5");
	t_charPt(retppt[4], "f.x",   " splitStrChar kk 6");
	printCharPt2d(retppt, retRow);

  }
  {
	char c = '/';
	char* str = "tmp/f.x";
	int bufLen = strlen(str);
	int retRow = 0;
	char** retppt = splitStrChar(str, bufLen, &retRow, c);
	t_int(retRow, 3,           " splitStrChar ee 1 ");
	t_charPt(retppt[0], "tmp",   " splitStrChar ee 2");
	t_charPt(retppt[1], "/", " splitStrChar ee 3");
	t_charPt(retppt[2], "f.x",   " splitStrChar ee 4");
	printCharPt2d(retppt, retRow);
  }
  {
	char c = '/';
	char* str = "f.x";
	int bufLen = strlen(str);
	int retRow = 0;
	char** retppt = splitStrChar(str, bufLen, &retRow, c);
	t_int(retRow, 1,           " splitStrChar cc 1 ");
	t_charPt(retppt[0], "f.x",   " splitStrChar cc 2");
	for(int i = 0; i < retRow; i++){
	  pp("retppt=%s\n", retppt[i]);
	}
  }
}


void alltest(){
    splitPath_test();
    splitStrChar_test();
}
int main (int argc, char* argv[]) {
    alltest();

    return(0);
}
