#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>

char *toLower(char *str);//Преобразование строки в нижний регистр

char toLowCase(char ch);//Преобразование символа в нижний регистр

int isLowCase(char ch);//Проверка символа на принадлежность к нижнему регистру

int isDigit(char ch);//Проверка символа на принадлежность к числовому диапозону

int isApperCase(char ch);//Проверка символа на принадлежность к верхнему регистру

int slen(char *str);//Вычисление длины строки

void scopy(char *s1, char *s2);//Копирование строк

int sequal(char *s1, char *s2);//Проверка строк на совпадение

int scmp(char *s1, char *s2);//Cравнение строк по алфавиту

int schr(char *str, char ch);//Поиск символа в строке

int s_stok(char *str, char delim, char *ptr[]);//Разбиение строки на поля

void suntok(char *str, char delim, char *ptr[], int cnt);//Восстановление строки после разбиения на поля

int sspn(char *str, char *sym);//Определение подстроки, состоящей из допустимых символов

int s_str(char *txt, char *p);//Поиск пожстроки в строке

void concat(char *dest, char* str);//Конкатенация строк

#endif