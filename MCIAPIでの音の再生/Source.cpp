#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int main(void) 
{
	mciSendString(" open 11677.mp3 alias music", NULL, 0, NULL);//11677.mp3�Ƃ������y�t�@�C�����I�[�v�����Ă�����umusic�v�Ƃ����ϐ��ɓ����
	mciSendString("setaudio Y volume to 10", null, 0, IntPtr.Zero);
	mciSendString("play music repeat", NULL, 0, NULL);//�uplay music�v�Ƃ���ƈ�񂾂��uplay music repeat�v�Ƃ���ƃ��[�v�Đ�  �������Ŏg���Ă���music�͕ϐ�music�̂��Ƃł���
	
	Sleep(5000000);//5000�b�҂�  �����̊ԋȂ������

	mciSendString("stop music", NULL, 0, NULL);//music�ɓ����Ă��鉹�y���~�߂�
	mciSendString("close music", NULL, 0, NULL);//music�ɓ����Ă��鉹�y�t�@�C�������
	return 0;
}

