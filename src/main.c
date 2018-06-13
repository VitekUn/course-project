#include "stroka.h"

int main(){

    int index, index_slova;
    unsigned int RAZMER, k = 0, i, s, schet;

    printf("Введите размер шаблона ");
    scanf("%u", &RAZMER);

    char *word[SIZE];
    char *slovo[RAZMER + 1];
    char *shablon[RAZMER + 1];
    char *key;
    
    FILE *file = fopen("text.txt", "r");
    for (i = 0; i < SIZE; i++) {
		fscanf(file, "%s", word[i]);
    }

    printf("Введите шаблон для поиска ");
    scanf("%s", *slovo);
    key = *slovo;
    index_slova = hash(key);

    for (s = 0; s < (SIZE - RAZMER); s++) {
        schet = 0;
        for (i = s; i < (s + 3); i++) {
            *shablon[schet] = *word[i];
            schet++;
        }
        key = *shablon;
        index = hash(key);
        s = s - 2;

        if ((index_slova == index) && (*slovo[0] == *shablon[0]) &&
            (*slovo[1] == *shablon[1]) && (*slovo[2] == *shablon[2]))
            k++;
    }
    printf("Количество совпадений равно = %u", k);

}

unsigned int hash(char *key){
    unsigned int h = 0;
	char *p;
	for(p = key; *p !='\0'; p++){
		h = h*33 + (unsigned int)*p + 11;
	}
	return h % SIZE;
}