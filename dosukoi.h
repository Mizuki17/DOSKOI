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
//////////////���ɂ��Ă̐���//////////////////
/*
mciSendString(" open X alias Y", NULL, 0, NULL);
�uopen X�v��X�ɍĐ����������y�t�@�C����I���B
�ualias Y�v��Y�ɕϐ�������Ǝ����炻�̕ϐ����g���Ύw�肵�Ă��鉹�y�t�@�C�����g���Ă���遦�ualias Y�v���g��Ȃ��Ƃ��̌�Ɏg���֐��ł��������t�@�C���̖��O���g��Ȃ��Ƃ����Ȃ�

mciSendString("play Y repeat", NULL, 0, NULL);
�uplay Y�v�Ƃ���ƈ�񂾂��uplay Y repeat�v�Ƃ���ƃ��[�v�Đ� 

mciSendString("stop Y", NULL, 0, NULL);
���y���~�߂�

mciSendString("close Y", NULL, 0, NULL);
���y�t�@�C�������
*/
///////////////////////////////////////////////�킩��Ȃ������烏�C�T�ɕ�����
