#ifdef __linux__
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <limits.h>

void dircreat(char name[20], char dirName[NAME_MAX + 1], int pid)
{


    struct stat st = {0};
    if (stat(dirName, &st) == -1)
    {
        if (mkdir(dirName, 0755) != -1)
        {
            char libPath[PATH_MAX + 1];
            snprintf(libPath, PATH_MAX + 1, "%s/%s.txt", dirName, dirName);

            FILE *fLib = fopen(libPath, "w+");
            fclose(fLib);
        }
        else
        {
            perror("mkdir: ");
        }
    }
}
#else
// C program to create a directory
// using system() function
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <limits.h>
#include <process.h>
#include <windows.h>
#include <conio.h>
void dircreat(char dirname[256])
{
    char cmd[32] = {0};

    int ret = 0;

    sprintf(cmd, "mkdir %s", dirname);

    ret = system(cmd);

    if (ret == 0)
        printf("Directory created successfully\n");
    else
        printf("Unable to create directory %s\n", dirname);
}

#endif
