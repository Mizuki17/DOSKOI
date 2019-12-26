#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	int main(void)
	{
		int t[15][15], x, y, x2, y2, cun=1, num;
		for (;; system("cls")) {
			printf("Please enter the random odd number \n");
			scanf("%d", &num); rewind(stdin);
			if (num == 2 || num == 4 || num == 6 || num == 8 || num == 10 || num == 12 || num == 14) { printf("enter the random odd number"); getchar(); }
			else if (num < 16 && num > 0) { break; }
			else { system("cls"); printf("Please enter the random odd number \n"); getchar(); }
		}

		for (y = 0; y < 15; y++) { for (x = 0; x < 15; t[y][x++] = 0); }

		for (x2 = num / 2, y2 = 0; t[num - 1][num / 2] == 0; cun++) {
			if (x2 > num - 1) { x2 = 0; }
			if (y2 < 0) { y2 = num - 1; }
			if (t[y2][x2] != 0) { y2 = y2 + 2; x2 = x2--; }
			if (x2 < 0) { x2 = num - 1; }
			if (y2 > num - 1) { y2 = 1; }

			t[y2][x2] = cun;
			
			x2++; y2--;
		}

		for (y = 0; y < num; y++)
		{
			for (x = 0; x < num; printf("%3d ", t[y][x++]));
			printf("\n");
		}

		getchar();
		return 0;
	}
	
