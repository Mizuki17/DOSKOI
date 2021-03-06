
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
	WORD screen_buffer_kind = BLACK;

	int swap_flag = 0;
	CHAR_INFO* screen_buff;



	//コンソールI/O　初期化
	void IniDosukoi(int width, int height) {
		CONSOLE_HISTORY_INFO history_inf;

		//ディスプレイ情報
		dis_handle[0] = GetStdHandle(STD_OUTPUT_HANDLE);
		dis_handle[1] = NULL;
		input_handle = GetStdHandle(STD_INPUT_HANDLE);

		//履歴保存なし
		history_inf.cbSize = sizeof(CONSOLE_HISTORY_INFO);
		history_inf.HistoryBufferSize = 0;
		history_inf.NumberOfHistoryBuffers = 0;
		history_inf.dwFlags = 0;
		SetConsoleHistoryInfo(&history_inf);

		//フォントサイズ変更
		font_size.dwFontSize.X = FONTSIZE_X;
		font_size.dwFontSize.Y = FONTSIZE_Y;
		SetCurrentConsoleFontEx(dis_handle[0], TRUE, &font_size);

		//バッファサイズ変更
		wind_buffer_size.X = width;
		wind_buffer_size.Y = height;
		SetConsoleScreenBufferSize(dis_handle[0], wind_buffer_size);

		//ウィンドサイズ変更
		wind_size.Left = 0;
		wind_size.Top = 0;
		wind_size.Right = width - 1;
		wind_size.Bottom = height - 1;
		SetConsoleWindowInfo(dis_handle[0], TRUE, &wind_size);

		//コンソールウィンドのモード設定
		SetConsoleMode(dis_handle[0], CONSOLE_OUTPUT_MODE);
		SetConsoleMode(input_handle, CONSOLE_INPUT_MODE);

		//スクリーンバッファの情報取得
		GetConsoleScreenBufferInfo(dis_handle[0], &c_screen_buffer_info);

		//スクリーンバッファ用配列作成
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

		//フォントサイズの変更
		SetCurrentConsoleFontEx(dis_handle[0], TRUE, &font_size);
		SetCurrentConsoleFontEx(dis_handle[1], TRUE, &font_size);

		SetConsoleScreenBufferSize(dis_handle[0], wind_buffer_size);	//バッファサイズ変更
		SetConsoleWindowInfo(dis_handle[0], TRUE, &wind_size);		//ウィンドサイズ変更

		SetConsoleScreenBufferSize(dis_handle[1], wind_buffer_size);	//バッファサイズ変更
		SetConsoleWindowInfo(dis_handle[1], TRUE, &wind_size);		//ウィンドサイズ変更

		SetConsoleMode(dis_handle[0], CONSOLE_OUTPUT_MODE);	//バッファ上書きモード
		SetConsoleMode(dis_handle[1], CONSOLE_OUTPUT_MODE);	//バッファ上書きモード

		return 0;
	}

	void SetFontSize(int width, int height) {

		//フォントサイズ変更
		font_size.dwFontSize.X = width;
		font_size.dwFontSize.Y = height;
		if (dis_handle[1] == NULL) {
			SetCurrentConsoleFontEx(dis_handle[0], TRUE, &font_size);
		}
		else {
			SetCurrentConsoleFontEx(dis_handle[0], TRUE, &font_size);
			SetCurrentConsoleFontEx(dis_handle[1], TRUE, &font_size);
		}
	}

	////ちょっと置いといて
	//void DrawString(int x, int y, const char* buf) {
	//	
	//	TextOut(hdc, x, y, buf, sizeof (buf));
	//}

	//文字出力
	void PrintString(const char* buf, int size)
	{
		DWORD write_num;

		WriteConsole(dis_handle[swap_flag], buf, size, &write_num, NULL);
	}
}


//画面消去
void ClearScreen(void)
{
	DWORD fill_num;
	COORD screen_ini = { 0,0 };
	screen_buffer_kind = c_screen_buffer_info.wAttributes;

	FillConsoleOutputAttribute(dis_handle[swap_flag],
		c_screen_buffer_info.wAttributes,
		c_screen_buffer_info.dwSize.X * c_screen_buffer_info.dwSize.Y,
		screen_ini,
		&fill_num);
	FillConsoleOutputCharacter(dis_handle[swap_flag],
		TEXT(' '),
		c_screen_buffer_info.dwSize.X * c_screen_buffer_info.dwSize.Y,
		screen_ini,
		&fill_num);
	//SetCursorPosition(c_screen_buffer_info.srWindow.Left + 1, c_screen_buffer_info.srWindow.Top + 1);

}
//ダブルバッファ時画面切り替え
void FlipScreen(void)
{
	SetConsoleActiveScreenBuffer(dis_handle[swap_flag]);	// バッファを入れ替え表示
	swap_flag = (swap_flag) ? 0 : 1;
}

