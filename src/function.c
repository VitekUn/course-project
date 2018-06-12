#include "function.h"
#include "string.h"

int count_string(FILE * input) 
{
	int lines_count = 0;

	while( !feof(input)) {
		if(fgetc(input) == '\n') {
			lines_count++;
		}
	}
	fclose(input);
	return lines_count+1;

}

unsigned int hash(char *key, int num_str)
{
    unsigned int h = 0;
	char *p;
	for(p = key; *p !='\0'; p++){
		h = h*33 + (unsigned int)*p + 11;
	}
	return h % num_str;
}