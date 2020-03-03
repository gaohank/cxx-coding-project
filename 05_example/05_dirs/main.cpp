#include <unistd.h>
#include <sys/stat.h>
#include <sys/dirent.h>
#include <dirent.h>
#include <cstdio>
#include <cstring>
#include <io.h>
#include <iostream>

// 遍历目录
void printdir(const char * pathname, const int depth)
{
    DIR * dir;
    struct dirent * de;
    struct stat fs;
    int i = 0;

    if((dir = opendir(pathname)) == NULL)
    {
        printf("open dir %s error \r\n", pathname);
        return;
    }

    chdir(pathname);
    while((de = readdir(dir)) != NULL)
    {
        if(strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0){continue;}

        if(stat(de->d_name, &fs) == -1){perror("fstat error");continue;}

        if(S_ISDIR(fs.st_mode)) {
            for(i=0;i<depth;++i){printf(" ");}
            printf("%s\r\n", de->d_name);
            printdir(de->d_name, depth + 4);
        }
        else
        {
            for(i=0;i<depth;++i)
            {
                printf(" ");
            }

            printf("%s\r\n", de->d_name);
        }
    }
    chdir("..");
    closedir(dir);

    return;
}

using namespace std;
int main(int argc, char ** argv)
{
    char buffer[100];
    // 获得当前可执行程序所在的路径
    getcwd(buffer, 100);
    printdir(buffer, 0);

    cout << buffer << endl;

    return 0;
}