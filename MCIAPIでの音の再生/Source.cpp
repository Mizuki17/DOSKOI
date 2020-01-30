#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int main(void) 
{
	mciSendString(" open 11677.mp3 alias music", NULL, 0, NULL);//11677.mp3という音楽ファイルをオープンしてそれを「music」という変数に入れる
	mciSendString("setaudio Y volume to 10", null, 0, IntPtr.Zero);
	mciSendString("play music repeat", NULL, 0, NULL);//「play music」とすると一回だけ「play music repeat」とするとループ再生  ※ここで使っているmusicは変数musicのことである
	
	Sleep(5000000);//5000秒待つ  ※この間曲が流れる

	mciSendString("stop music", NULL, 0, NULL);//musicに入っている音楽を止める
	mciSendString("close music", NULL, 0, NULL);//musicに入っている音楽ファイルを閉じる
	return 0;
}

