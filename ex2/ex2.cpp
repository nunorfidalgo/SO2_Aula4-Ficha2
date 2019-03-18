#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

#define LIM 1000

#define N_HT 10

typedef struct {
	int num;
	int inicio;
	int fim;
} PARAM;

DWORD WINAPI Thread(LPVOID param);

void gotoxy(int x, int y);

int _tmain(int argc, LPTSTR argv[]) {
	TCHAR resp;
	int y;
	DWORD threadId; //Id da thread a ser criada
	HANDLE hT[N_HT]; //HANDLE/ponteiro para a thread a ser criada

	PARAM p[N_HT];

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	srand((int)time(NULL));

	for (int i = 0; i < N_HT; i++) {

		/*x->lim1 = (LIM / N_HT) - N_HT;
		x->lim2 = LIM / N_HT;*/

		/*hT[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread, (LPVOID)&x[i], 0, &threadId);
		if (hT != NULL) {
			_tprintf(TEXT("Lancei uma thread com id %d\n"), threadId);
			WaitForMultipleObjects(i, hT, true, INFINITE);
		}
		else
			_tprintf*/(TEXT("Erro ao criar Thread\n"));
	}
	_tprintf(TEXT("[Thread Principal %d] Vou terminar..."), GetCurrentThreadId());
	return 0;
}

/* ----------------------------------------------------- */
/* "Thread" - Funcao associada à Thread */
/* ----------------------------------------------------- */
DWORD WINAPI Thread(LPVOID param) {
	int i;
	//X y = ((X)param);

	//_tprintf(TEXT(" - [Thread %d] Vou contar de %d a %d "), GetCurrentThreadId(), y->lim1, y->lim2);

	/*for (i = 0; y->inicio < y->fim; i++) {
		gotoxy(50, 10 + y->num);
		_tprintf(TEXT("T%5d: "), y->num, i);
		Sleep(10);
	}*/

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