
#ifdef __cplusplus
extern"C" {
#endif 

#include "dosukoi.h"

#define CONSOLE_INPUT_MODE	ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT | ENABLE_WINDOW_INPUT | ENABLE_PROCESSED_INPUT
#define CONSOLE_OUTPUT_MODE	ENABLE_PROCESSED_OUTPUT

	HANDLE dis_handle[2];
	HANDLE input_handle;
	COORD wind_buffer_size;
	CONSOLE_FONT_INFOEX font_size = { sizeof font_size };
	SMALL_RECT wind_size;
	CONSOLE_SCREEN_BUFFER_INFO c_screen_buffer_info;


	CHAR_INFO* screen_buff;



	//�R���\�[��I/O�@������
	void IniDosukoi(int width, int height) {
		CONSOLE_HISTORY_INFO history_inf;

		//�f�B�X�v���C���
		dis_handle[0] = GetStdHandle(STD_OUTPUT_HANDLE);
		dis_handle[1] = NULL;
		input_handle = GetStdHandle(STD_INPUT_HANDLE);

		//����ۑ��Ȃ�
		history_info.cbSize = sizeof(CONSOLE_HISTORY_INFO);
		history_info.HistoryBufferSize = 0;
		history_info.NumberOfHistoryBuffers = 0;
		history_info.dwFlags = 0;
		SetConsoleHistoryInfo(&history_info);

		//�t�H���g�T�C�Y�ύX
		font_size.dwFontSize.X = FONTSIZE_X		16
        font_size.dwFontSize.Y = FONTSIZE_Y		16
		SetCurrentConsoleFontEx(window_handle[0], TRUE, &font_size);

		//�o�b�t�@�T�C�Y�ύX
		wind_buffer_size.X = width;
		wind_buffer_size.Y = height;
		SetConsoleScreenBufferSize(dis_handle[0], wind_buffer_size);
		
		//�E�B���h�T�C�Y�ύX
		wind_size.Left = 0;
		wind_size.Top = 0;
		wind_size.Right = width - 1;
		wind_size.Bottom = height - 1;
		SetConsoleWindowInfo(dis_handle[0],TRUE, &wind_size);

		//�R���\�[���E�B���h�̃��[�h�ݒ�
		SetConsoleMode(dis_handle[0], &c_screen_buffer_info);

		//�X�N���[���o�b�t�@�p�z��
		screen_buff = new CHAR_INFO[width * height];
		memset(screen_buff, 0, width * height);

	}

	int IniDoubleBuffer(void) {
		//�_�u���o�b�t�@�p�������m��
		dis_handle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		if (dis_handle[0] == INVALID_HANDLE_VALUE) {
			printf("�_�u���o�b�t�@�P�̃n���h���擾���s\n");
			return -1;
		}

		dis_handle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		if (dis_handle[1] == INVALID_HANDLE_VALUE) {
			printf("�_�u���o�b�t�@�Q�̃n���h���擾���s");
			return -1;
		}

		//�t�H���g�T�C�Y�ύX
		SetCurrentConsoleFontEx(dis_handle[0], TRUE, &font_size);
		SetCurrentConsoleFontEx(dis_handle[1], TRUE, &font_size);

		SetConsoleScreenBufferSize(dis_handle[0],wind_buffer_size);	//�o�b�t�@�T�C�Y�ύX
		SetConsoleWindowInfo(dis_handle[0], TRUE, &wind_size);		//�E�B���h�T�C�Y�ύX

		SetConsoleScreenBufferSize(dis_handle[1], wind_buffer_size);	//�o�b�t�@�T�C�Y�ύX
		SetConsoleWindowInfo(dis_handle[1], TRUE, &wind_size);		//�E�B���h�T�C�Y�ύX

		SetConsoleMode(dis_handle[0], CONSOLE_OUTPUT_MODE);	//�o�b�t�@�㏑�����[�h
		SetConsoleMode(dis_handle[1], CONSOLE_OUTPUT_MODE);	//�o�b�t�@�㏑�����[�h

		return 0;
	}

}


