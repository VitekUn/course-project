#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int count_string(FILE * input);

int h_init(int strLen);

int ringHash(char* str, int strLen, int prevHash, int *h);

int rabinKarpSearch(char* text, char* str, int num_str);

#endif