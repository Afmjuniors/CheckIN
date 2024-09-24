#include <time.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif


// Declaração das funções
void getComputerName(char *name, int len);
void getCurrentTimestamp(char *timestamp, int len);

void getComputerName(char *name, int len) {
#ifdef _WIN32
    DWORD size = len;
    GetComputerName(name, &size);
#else
    FILE *fp = popen("hostname", "r");
    if (fp == NULL) return;
    fgets(name, len, fp);
    pclose(fp);
#endif
}

void getCurrentTimestamp(char *timestamp, int len) {
    time_t now = time(NULL);
    strftime(timestamp, len, "%Y-%m-%d %H:%M:%S", localtime(&now));
}