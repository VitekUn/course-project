#include "string.h"

char *toLower(char *str)
{
	int i;
	for(i = 0; str[i] != '\0'; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + ('a' - 'A');
		}
	}
	return str;
}
char toLowCase(char ch)
{
	if( ch >= 'A' && ch <= 'Z') {
		return ch + ('a' - 'A');
	}
	return ch;

}

int isLowCase(char ch)
{
	if( ch >= 'a' && ch <= 'z') {
		return 1;
	}
	return 0;
	
}

int isDigit(char ch)
{
	if( ch >= '0' && ch <= '9') {
		return 1;
	}
	return 0;
}

int isApperCase(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return 1;

    return 0;
}

int slen(char *str)
{
	int i = 0;
	while(*str){
		i++;
		str++;
	}
	return i;
}

void scopy(char *s1, char *s2)
{
	while((*s2++ = *s1++) != '\0');
}

int sequal(char *s1, char *s2)
{
	int i, flg = 1;
		for(i = 0; flg && (s1[i]!='\0' || s2[i]!='\0');i++) {
			if( s1[i]!=s2[i] ) flg = 0;
		}
	return flg;
}

int scmp(char *s1, char *s2)
{
	int i, flg = 0;
	for( i = 0; (s1[i]==s2[i]) && s1[i]!='\0' && s2[i]!='\0'; i++);
		if( s1[i] < s2[i] ) 
			flg = -1; // если строки
		else if( s1[i] > s2[i] ) 
			flg = 1;// разной длины
	return flg;
}


int schr(char *str, char ch)
{
	int i, index = -1;
	for(i = 0; (str[i] != '\0') && (str[i] != ch); i++);
		if( str[i] == ch )
		index = i;

	return index;
}

int s_stok(char *str, char delim, char *ptr[])
{
	char *suf = str;
	ptr[0] = str; // первое поле – начало str
	int i, j = 1; // j – счетчик полей
	while( ( i = schr(suf, delim) ) >= 0 ){
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] = suf;
		j++;
	}
	return j;
}

void suntok(char *str, char delim, char *ptr[], int cnt)
{
	int i;
	for(i = 1; i < cnt; i++){
		*(ptr[i] - 1) = delim;
	}
}

int sspn(char *str, char *sym)
{
	int i;
	for( i = 0; str[i] != '\0' ; i++) {
		if( schr(sym, str[i] ) < 0 ) {
		break;
		}
	}
	return i;
}

int s_str(char *txt, char *p)
{
	char *suf = txt;
	int len = slen(p);
	int i, pos = -1;
	while( ( ( i = schr(suf,p[0]) ) >= 0) && (pos < 0) ){
		char tmp;
		suf = suf + i;
		tmp = suf[len];
		suf[len] = '\0';
		if( sequal(suf, p) ){ // посимвольное сравнение строк
			pos = suf - txt; // разность указателей = индекс
		}
		suf[len] = tmp;
		suf++;
	}
	return pos;
}

void concat(char *dest, char* str){
	while(*dest) {
		dest++;
	}
	while((*dest++ = *str++) != '\0');
}
