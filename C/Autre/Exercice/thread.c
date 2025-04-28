#include <stdio.h>
#include <string.h>
#include <windows.h>

// Fonction qui sera exécutée dans le thread
DWORD WINAPI ThreadFunction1(PVOID lpParam) {
    for (int i = 0; i < 5; i++) {
        printf("%s%i\n","Thread: ",i);
        Sleep(1000);  // Pause d'une seconde
    }
    return 0;
}

int main() {
    HANDLE hThread;
    DWORD threadId;
    // Créer un thread
    hThread = CreateThread(NULL, 0, ThreadFunction1, NULL, 0, &threadId);

    // if (hThread == NULL) {
    //     puts("Impossible de créer le thread.\n");
    //     return 1;
    // }
    puts("11111");
    Sleep(1000);  // Pause d'une seconde
    puts("22222");
    // Attendre la fin du thread
    WaitForSingleObject(hThread, INFINITE);

    // Fermer la poignée du thread
    CloseHandle(hThread);

    puts("Le thread a terminé son exécution.");

    return 0;
}