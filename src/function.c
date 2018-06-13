#include "function.h"


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
int h_init(int strLen) {
    int d = 52;
    int p = 65713;
 
    int h = 1;
    for(int i=1; i < strLen; i++) {
        h = (h*d) % p;
    }
 
    return h;
}
 
int ringHash(char* str, int strLen, int prevHash, int *h) {
    int d = 52; //Константа из формулы
    int p = 65713; //Вычисления производятся по модулю простого числа
 
    //h = d^(len-1) (mod p) - константа для быстроого пересчета хэша
    if(*h == 0) { //Если константа не инициализирована
        *h = h_init(strLen);
    }
 
    //Если считаем хеш первый раз
    if(prevHash == 0) {
        for(int i=0; i<strLen; i++) {
            prevHash += (d*prevHash + (int)str[i]) % p;
        }
        if(prevHash < 0) {
            prevHash += p;
        }
 
        return prevHash;
    }
    //Если пересчитываем для другого окна
    else {
        int hash = (d * (prevHash - (int)str[0] * (*h)) + (int)str[strLen]) % p;
        if(hash < 0) {
            hash += p;
        }
 
        return hash;
    }
}

int rabinKarpSearch(char* text, char* str, int num_str)
{
    int strLen = slen(str);
    int textLen = slen(text);
    int s;
    int h = 0;
    //шаблонный
    if(schr(str, '*') >= 0) {
 		char *ptr1[10];
 		char pattern[10];
 		scopy(str, pattern);
 		int n_pattern = s_stok(pattern, '*', ptr1);
 		char *ptr2[10];
 		int n_slov = s_stok(text, ' ', ptr2); 
 		 for(int i = 0; i < n_slov; i++) {
 			s = 0;
 			for(int j = 0; j < n_pattern; j++) {
 				if(s_str(ptr2[i], ptr1[j]) != -1) {
 					s++;
 				}
 			}
 			if(s == n_pattern) {
 				if(i == 0) {
 					printf("%d строка:Было найдено слово по шаблону(%s)\nЕго индекс = %d\n", num_str, str, i);
 					return i;
 				} else {
 					suntok(text, ' ', ptr2, i+1);
 					int k = schr(text, ' ');
 					printf("%d строка:Было найдено слово по шаблону(%s)\nЕго индекс = %d\n", num_str, str, k+1);
					return k+1;
				}
    	 	}
    	 	s = 0;
 		}
 	}
    //Хэш подстроки для поиска без шаблонный
 	if(schr(str, '*') == -1){
    
    int strHash = ringHash(str, strLen, 0, &h);
    //Хэш первого окна в тексте
    int textHash = ringHash(text, strLen, 0, &h);
 
    for(int k = 0; k <= (textLen-strLen); k++) {
        if(strHash == textHash) {
            //Если хэши совпали, проверяем посимвольно
            for(int i = 0; (i < strLen) && (str[i] == text[k+i]); i++) {
                if(i == (strLen-1)) {
                  	printf("%d строка)Было найдено слово по шаблону(%s)\nЕго индекс = %d\n", num_str, str, k);
                    return k;
                }
            }
        }
        //Хэш следующего окна
        textHash = ringHash(&text[k], strLen, textHash, &h);
    }
    }
    //Строка не найдена
    printf("%d)Строка не найдена\n", num_str);
    return -1;
}

// unsigned int hash(char *key, int num_str)
// {
//     unsigned int h = 0;
// 	char *p;
// 	for(p = key; *p !='\0'; p++){
// 		h = h*33 + (unsigned int)*p + 11;
// 	}
// 	return h % num_str;
// }