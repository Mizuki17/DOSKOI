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
	fscanf(fp, "%s", name);//file���當�������肵��name�ɓ����B
	printf("%s", name);
	fclose(fp);
	getchar();
	return 0; 
	//file�̒��g��ς���Ƃ��ꂪ�\�������
	
}