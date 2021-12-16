#include <stdio.h>
#include <string.h>   // for string operations
#include <stdlib.h>   //for malloc()
#include <fcntl.h>    //for creat()
#include <sys/stat.h> //for struct stat, stat()
#include <unistd.h>   //for close()
#ifdef _WIN64
#define DIR_SEPARATOR "\\"
#else
#define DIR_SEPARATOR "/"
#endif
void dir()
{
    int iFd = 0;
    char line[80], dir[50], name[50], path[100];

    FILE *fp, *fp1;
    fp = fopen("source.txt", "r");
    fp1 = fopen("log.txt", "w");
    if (fp1 == NULL)
    {
        fp1 = fopen("log.txt", "w");
    }

    fgets(line, 80, fp);
    sscanf(line, "%s", dir);
    fclose(fp);

    printf("ENTER FILE NAME: ");
    scanf(" %[^\n]s", name);
    sprintf(path, "%s%s%s.txt", dir,DIR_SEPARATOR, name);
    fprintf(fp1, "%s/%s.txt", dir, name);
    fclose(fp1);

    printf("[INFO] File Created Successfully : %s\n", path);

}

