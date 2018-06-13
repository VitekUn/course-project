#include "function.h"
#include "string.h"

int main(int argc, char * argv[])
{
    //ввод аргументов 
    if( argc < 3) {
        printf("%s%s","Usage:\n",
                "rkmatcher <pattern> <file.txt>\n");
        return -1;
    } 
    //проверка 
    // if(strcmp(argv[1], "что то") == 0) {
    //     return -1;
    //}
    //Считывание текста
    FILE *text_in = fopen(argv[2], "r");
    if(text_in == NULL) {
        printf("Ошибка в считывании текста\n");
        return 0;
    }
    int num_str = count_string(text_in);
    text_in = fopen(argv[2], "r");
    char text[num_str][50];
    for (int i = 0; i < num_str; i++) {
        fscanf(text_in, "%s",text[i]);
        //printf("%s\n", text[i]);
    }
    for(int j = 0; j < num_str; j++) {
        rabinKarpSearch(text[j], argv[1], j+1);
    }

    return 0;
}