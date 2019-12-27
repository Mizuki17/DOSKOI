#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int main(void) 
{
	mciSendString(" open 11677.mp3 alias music", NULL, 0, NULL);//ここで音楽ファイルのオープンとそれを「music」という変数に入れている
	mciSendString("play music repeat", NULL, 0, NULL);//「play music」とすると一回だけ「play music repeat」とするとループ再生

	Sleep(5000000);//5000秒待つ
	mciSendString("stop music", NULL, 0, NULL);//音楽を止める
	mciSendString("close music", NULL, 0, NULL);//音楽ファイルを閉じる
	return 0;
}

