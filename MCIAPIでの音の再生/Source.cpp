#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int main(void) 
{
	mciSendString(" open 11677.mp3 alias music", NULL, 0, NULL);//�����ŉ��y�t�@�C���̃I�[�v���Ƃ�����umusic�v�Ƃ����ϐ��ɓ���Ă���
	mciSendString("play music repeat", NULL, 0, NULL);//�uplay music�v�Ƃ���ƈ�񂾂��uplay music repeat�v�Ƃ���ƃ��[�v�Đ�

	Sleep(5000000);//5000�b�҂�
	mciSendString("stop music", NULL, 0, NULL);//���y���~�߂�
	mciSendString("close music", NULL, 0, NULL);//���y�t�@�C�������
	return 0;
}

