/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DeLeoCollatz.c
 * Author: cristi
 *
 * Created on October 23, 2019, 6:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Simple C Test Suite
 */

void test1() {
    printf("DeLeoCollatz test 1\n");
}

void test2() {
    printf("DeLeoCollatz test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (DeLeoCollatz) message=error message sample\n");
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% DeLeoCollatz\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (DeLeoCollatz)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (DeLeoCollatz) \n");

    printf("%%TEST_STARTED%% test2 (DeLeoCollatz)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (DeLeoCollatz) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
