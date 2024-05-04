#!/usr/local/bin/bash

# Sat  4 May 13:17:15 2024 
# add quickSortAny_test.c
# 
gcc -I$clib AronCLibNewTest.c -o AronCLibNewTest && ./AronCLibNewTest
gcc -I$clib quickSortAny_test.c -o quickSortAny_test && ./quickSortAny_test
