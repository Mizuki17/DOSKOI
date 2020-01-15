#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <io.h>
#include <windows.h>

// Windows�W���̃R���\�[���ɂ����āAANSI�G�X�P�[�v�V�[�P���X��L��������
bool enable_virtual_terminal_processing(FILE *stream) {
	HANDLE handle = (HANDLE)_get_osfhandle(_fileno(stream));
	DWORD mode = 0;
	if (!GetConsoleMode(handle, &mode)) {
		// ���s
		return false;
	}
	if (!SetConsoleMode(handle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
		// ���s
		// �Â�Windows�R���\�[���̏ꍇ�� GetLastError() == ERROR_INVALID_PARAMETER
		return false;
	}
	return true;
}


bool is_3rdparty_console(FILE *stream) {
	const char *s = getenv("ConEmuANSI");
	if (s && strcmp(s, "ON") == 0) {
		// ConEmu
		return true;
	}
	else if (getenv("ANSICON") != NULL) {
		// ansicon
		return true;
	}

	return false;
}

int main(void) {
	int i = 0;
	int j = 0;
	int a = 0;

	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			if (_isatty(_fileno(stdout))) {
				if (is_3rdparty_console(stdout) || enable_virtual_terminal_processing(stdout)) {
					a = i * 16 + j;
					printf("\033[38;5;%dmCOLOR�@", a);
				}	
			}
		}
		printf("\n");
	}

	//if (_isatty(_fileno(stdout))) {
	//	if (is_3rdparty_console(stdout) || enable_virtual_terminal_processing(stdout)) {
	//		printf("\033[38;5;1m");
	//	}
	//}

	//printf("�e�X�g");

	getchar();
}