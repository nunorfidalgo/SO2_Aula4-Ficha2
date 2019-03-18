#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

#define LIM 1000

DWORD WINAPI Thread(LPVOID param);

void gotoxy(int x, int y);

int _tmain(int argc, LPTSTR argv[]) {
	TCHAR resp;
	int y;
	DWORD threadId; //Id da thread a ser criada
	HANDLE hT; //HANDLE/ponteiro para a thread a ser criada

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	srand((int)time(NULL));
	_tprintf(TEXT("Lançar thread (S/N)?"));
	_tscanf_s(TEXT("%c"), &resp, 1);
	if (resp == 'S' || resp == 's') {
		y = rand() % 40;
		hT = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread, (LPVOID)y, 0, &threadId);
		SetThreadPriority(&threadId, THREAD_PRIORITY_LOWEST);
		if (hT != NULL) {
			_tprintf(TEXT("Lancei uma thread com id %d\n"), threadId);
			//Sleep(10000);
			WaitForSingleObject(hT, INFINITE);
		}
		else
			_tprintf(TEXT("Erro ao criar Thread\n"));
	}
	_tprintf(TEXT("[Thread Principal %d ]Vou terminar..."), GetCurrentThreadId());
	return 0;
}
/* ----------------------------------------------------- */
/* "Thread" - Funcao associada à Thread */
/* ----------------------------------------------------- */
DWORD WINAPI Thread(LPVOID param) {
	int i;
	int y = ((int)param);
	_tprintf(TEXT("[Thread %d] Vou começar a trabalhar\n"), GetCurrentThreadId());
	Sleep(100);
	for (i = 0; i < LIM; i++) {
		gotoxy(y, y);
		_tprintf(TEXT("Thread %5d "), i);
	}
	return 0;
}
void gotoxy(int x, int y) {
	static HANDLE hStdout = NULL;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	if (!hStdout)
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, coord);
}