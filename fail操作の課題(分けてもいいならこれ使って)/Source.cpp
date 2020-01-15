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
	fscanf(fp, "%s", name);//file‚©‚ç•¶š—ñ‚ğ“üè‚µ‚Äname‚É“ü‚ê‚éB
	printf("%s", name);
	fclose(fp);
	getchar();
	return 0; 
	//file‚Ì’†g‚ğ•Ï‚¦‚é‚Æ‚»‚ê‚ª•\¦‚³‚ê‚é
	
}