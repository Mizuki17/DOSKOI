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
#pragma comment(lib,"winmm.lib")

#define FONTSIZE_X		16
#define FONTSIZE_Y		16

	enum COLORS {
		BLACK,			/* #000000	黒				*/
		BLUE,			/* #0000AA	青				*/
		GREEN,			/* #00AA00	緑				*/
		CYAN,			/* #00AAAA	シアン			*/
		RED,			/* #AA0000	赤				*/
		MAGENTA,		/* #AA00AA	マゼンタ		*/
		BROWN,			/* #AA5500	茶				*/
		LIGHTGRAY,		/* #AAAAAA	明るい灰色		*/
		DARKGRAY,		/* #555555	暗い灰色		*/
		LIGHTBLUE,		/* #5555FF	明るい青		*/
		LIGHTGREEN,		/* #55FF55	明るい緑		*/
		LIGHTCYAN,		/* #55FFFF	明るいシアン	*/
		LIGHTRED,		/* #FF5555	明るい赤		*/
		LIGHTMAGENTA,	/* #FF55FF	明るいマゼンタ	*/
		YELLOW,			/* #FFFF55	黄				*/
		WHITE			/* #FFFFFF	白				*/
	};
	void IniDosukoi(int width, int height);
	int IniDoubleBuffer(void);
	void SetFontSize(int width, int height);


	void PrintString(const char* buf, int size);
	void ClearScreen(void);
	void FlipScreen(void);
#ifdef __cplusplus
}
#endif
//////////////音についての説明//////////////////
/*
mciSendString(" open X alias Y", NULL, 0, NULL);
「open X」のXに再生したい音楽ファイルを選択。
「alias Y」のYに変数を入れると次からその変数を使えば指定している音楽ファイルを使ってくれる※「alias Y」を使わないとこの後に使う関数でいちいちファイルの名前を使わないといけない

mciSendString("play Y repeat", NULL, 0, NULL);
「play Y」とすると一回だけ「play Y repeat」とするとループ再生

mciSendString("stop Y", NULL, 0, NULL);
音楽を止める

mciSendString("close Y", NULL, 0, NULL);
音楽ファイルを閉じる

mciSendString("setaudio Y volume to 1000", NULL, 0, NULL);
音量を1000にする
*/
///////////////////////////////////////////////わからなかったらワイサに聞いて

#endif
