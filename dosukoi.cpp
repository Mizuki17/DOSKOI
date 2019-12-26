
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



	//コンソールI/O　初期化
	void IniDosukoi(int width, int height) {
		CONSOLE_HISTORY_INFO history_inf;

		//ディスプレイ情報
		dis_handle[0] = GetStdHandle(STD_OUTPUT_HANDLE);
		dis_handle[1] = NULL;
		input_handle = GetStdHandle(STD_INPUT_HANDLE);

		//履歴保存なし
		history_info.cbSize = sizeof(CONSOLE_HISTORY_INFO);
		history_info.HistoryBufferSize = 0;
		history_info.NumberOfHistoryBuffers = 0;
		history_info.dwFlags = 0;
		SetConsoleHistoryInfo(&history_info);

		//フォントサイズ変更
		font_size.dwFontSize.X = FONTSIZE_X		16
        font_size.dwFontSize.Y = FONTSIZE_Y		16
		SetCurrentConsoleFontEx(window_handle[0], TRUE, &font_size);

		//バッファサイズ変更
		wind_buffer_size.X = width;
		wind_buffer_size.Y = height;
		SetConsoleScreenBufferSize(dis_handle[0], wind_buffer_size);
		
		//ウィンドサイズ変更
		wind_size.Left = 0;
		wind_size.Top = 0;
		wind_size.Right = width - 1;
		wind_size.Bottom = height - 1;
		SetConsoleWindowInfo(dis_handle[0],TRUE, &wind_size);

		//コンソールウィンドのモード設定
		SetConsoleMode(dis_handle[0], &c_screen_buffer_info);

		//スクリーンバッファ用配列
		screen_buff = new CHAR_INFO[width * height];
		memset(screen_buff, 0, width * height);

	}

	int IniDoubleBuffer(void) {
		//ダブルバッファ用メモリ確保
		dis_handle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		if (dis_handle[0] == INVALID_HANDLE_VALUE) {
			printf("ダブルバッファ１のハンドル取得失敗\n");
			return -1;
		}

		dis_handle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		if (dis_handle[1] == INVALID_HANDLE_VALUE) {
			printf("ダブルバッファ２のハンドル取得失敗");
			return -1;
		}

		//フォントサイズ変更
		SetCurrentConsoleFontEx(dis_handle[0], TRUE, &font_size);
		SetCurrentConsoleFontEx(dis_handle[1], TRUE, &font_size);

		SetConsoleScreenBufferSize(dis_handle[0],wind_buffer_size);	//バッファサイズ変更
		SetConsoleWindowInfo(dis_handle[0], TRUE, &wind_size);		//ウィンドサイズ変更

		SetConsoleScreenBufferSize(dis_handle[1], wind_buffer_size);	//バッファサイズ変更
		SetConsoleWindowInfo(dis_handle[1], TRUE, &wind_size);		//ウィンドサイズ変更

		SetConsoleMode(dis_handle[0], CONSOLE_OUTPUT_MODE);	//バッファ上書きモード
		SetConsoleMode(dis_handle[1], CONSOLE_OUTPUT_MODE);	//バッファ上書きモード

		return 0;
	}

}


