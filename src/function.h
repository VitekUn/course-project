#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int count_string(FILE * input);

unsigned int hash(char *key);

int rabinKarpSearch(char* text, char* str, int num_str);

#endif