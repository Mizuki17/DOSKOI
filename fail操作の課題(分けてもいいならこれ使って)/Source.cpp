#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(void) 
{
	FILE *fp;
	char name[20];
	fp = fopen("test.txt","r");
	fscanf(fp, "%s", name);//fileから文字列を入手してnameに入れる。
	printf("%s", name);
	fclose(fp);
	getchar();
	return 0; 
	//fileの中身を変えるとそれが表示される
	
}