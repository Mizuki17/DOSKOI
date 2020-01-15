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
*/
///////////////////////////////////////////////わからなかったらワイサに聞いて
