//




//

#ifndef __DOSUKOI_H
#define __DOSUKOI_H

#ifdef __cplusplus
extern "C" {
#endif

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>


#define FONTSIZE_X		16
#define FONTSIZE_Y		16

	enum COLORS {
		BLACK,			/* #000000	��				*/
		BLUE,			/* #0000AA	��				*/
		GREEN,			/* #00AA00	��				*/
		CYAN,			/* #00AAAA	�V�A��			*/
		RED,			/* #AA0000	��				*/
		MAGENTA,		/* #AA00AA	�}�[���^		*/
		BROWN,			/* #AA5500	��				*/
		LIGHTGRAY,		/* #AAAAAA	���邢�D�F		*/
		DARKGRAY,		/* #555555	�Â��D�F		*/
		LIGHTBLUE,		/* #5555FF	���邢��		*/
		LIGHTGREEN,		/* #55FF55	���邢��		*/
		LIGHTCYAN,		/* #55FFFF	���邢�V�A��	*/
		LIGHTRED,		/* #FF5555	���邢��		*/
		LIGHTMAGENTA,	/* #FF55FF	���邢�}�[���^	*/
		YELLOW,			/* #FFFF55	��				*/
		WHITE			/* #FFFFFF	��				*/
	};
	void IniDosukoi(int width, int height);
	void IniDoubleBuffer(void);
	void SetFontSize(int width, int height);


	void PrintString(const char* buf, int size);
	void ClearScreen(void);
	void FlipScreen(void);
#ifdef __cplusplus
}
#endif

#endif

