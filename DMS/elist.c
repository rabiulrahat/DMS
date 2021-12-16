
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void elistFile(const char *path);

/**
 * Lists all files and sub-directories at given path.
 */
void elistFile(const char *path)
{
    struct dirent *dp;
    FILE *fp;
    DIR *dir = opendir(path);

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        printf("%s\n", dp->d_name);
    }

    // Close directory stream
    closedir(dir);
}
