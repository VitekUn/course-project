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
    printf("Количество строк = %d\n", num_str);
    char text[num_str][50];
    for (int i = 0; i < num_str; i++) {
        fscanf(text_in, "%s",text[i]);
        printf("%s\n", text[i]);
    }


    /////////////////////////////////////////////////////////////////////
    // int index, index_slova;
    // int RAZMER, k = 0, i, s, schet;

    // printf("Введите размер шаблона ");
    // scanf("%d", &RAZMER);

    
    // char *slovo[RAZMER + 1];
    // char *shablon[RAZMER + 1];
    // char *key;
    

    // printf("Введите шаблон для поиска ");
    // scanf("%s", slovo);
    // key = *slovo;
    // index_slova = hash(key);

    // for (s = 0; s < (num_str - RAZMER); s++) {
    //     schet = 0;
    //     for (i = s; i < (s + 3); i++) {
    //         *shablon[schet] = text[i];
    //         schet++;
    //     }
    //     key = *shablon;
    //     index = hash(key);
    //     s = s - 2;

    //     if ((index_slova == index) && (*slovo[0] == *shablon[0]) &&
    //         (*slovo[1] == *shablon[1]) && (*slovo[2] == *shablon[2]))
    //         k++;
    // }
    // printf("Количество совпадений равно = %u", k);
    return 0;
}