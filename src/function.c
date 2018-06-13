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
 
unsigned int hash(char *key)
{
    unsigned int h = 0;
    char *p;
    for(p = key; *p !='\0'; p++){
    h = h*33 + (unsigned int)*p + 11;
    }
    return h % 73;
}

int rabinKarpSearch(char* text, char* str, int num_str)
{
    //шаблонный
    if(schr(str, '*') >= 0) {
        int s;
        char *ptr1[10];
        char pattern[10];
        scopy(str, pattern);
        int n_pattern = s_stok(pattern, '*', ptr1);
        char *ptr2[10];
        int n_slov = s_stok(text, ' ', ptr2); 
        // int strLen = slen(str);
        // int textLen = slen(text);
         for(int i = 0; i < n_slov; i++) {
            s = 0;
            for(int j = 0; j < n_pattern; j++) {
                if(s_str(ptr2[i], ptr1[j]) != -1) {
                    s++;
                }
            }
            if(s == n_pattern) {
                if(i == 0) {
                    printf("%d)Было найдено слово по шаблону(%s) - индекс = %d\n", num_str, str, i);
                    return i;
                } else {
                    suntok(text, ' ', ptr2, i+1);
                    int k = schr(text, ' ');
                    printf("%d)Было найдено слово по шаблону(%s) - индекс = %d\n", num_str, str, k+1);
                    return k+1;
                }
            }
            s = 0;
        }
    }
    //Хэш подстроки для поиска без шаблонный
    if(schr(str, '*') == -1) {
        char copied_text[50];
        scopy(text, copied_text);
        char *ptr[10];
        int n_slov = s_stok(copied_text, ' ', ptr); 
        for(int i = 0; i < n_slov; i++) { 
            int strHash = hash(str);
            int textHash = hash(ptr[i]);
            //printf("strHash = %d\ntextHash = %d\n", strHash, textHash);
            if(strHash == textHash) {
                int position = s_str(text, ptr[i]);
                printf("%d)Было найдено слово по шаблону(%s) - индекс = %d\n", num_str, str, position);    
            } else {
                printf("%d)Строка не найдена\n", num_str);
            }
        }
    }
    return 0;
}

// int rabinKarpSearch(char* text, char* str, int num_str) {
//     int strLen = slen(str);
//     int textLen = slen(text);
//     int h = 0;
 
//     //Хэш подстроки для поиска
//     int strHash = ringHash(str, strLen, 0, &h);
//     //Хэш первого окна в тексте
//     int textHash = ringHash(text, strLen, 0, &h);
 
//     for(int k = 0; k <= (textLen-strLen); k++) {
//         if(strHash == textHash) {
//             //Если хэши совпали, проверяем посимвольно
//             for(int i = 0; (i < strLen) && (str[i] == text[k+i]); i++) {
//                 if(i == (strLen-1)) {
//                     printf("%d)Было найдено слово по шаблону(%s) - индекс = %d\n", num_str, str, k);
//                     return k;
//                 }
//             }
//         }
 
//         //Хэш следующего окна
//         textHash = ringHash(&text[k], strLen, textHash, &h);
//     }
 
//     //Строка не найдена
//     printf("%d)Строка не найдена\n", num_str);
//     return -1;
// }