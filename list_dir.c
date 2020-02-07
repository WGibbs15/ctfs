/*
 * C Program to List Files in Directory
 */
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
 
 
void print_file_permissions(char* filename)
{
 
    struct stat fileStat;
    if(stat(filename,&fileStat) < 0)    
        return;

    printf("Information for %s\n",filename);
    printf("---------------------------\n");
    printf("File Size: \t\t%d bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%d\n",fileStat.st_ino);
    printf("File owner: \t\t%d\n", fileStat.st_uid);
    printf("File group: \t\t%d\n", fileStat.st_gid);
 
    printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
 
    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}

void read_dirs(char *dirname) {
    DIR *d;
    struct dirent *dir;
    d = opendir(dirname);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
            if(strcmp(dir->d_name, "flag") == 0) {
                print_file_permissions(dir->d_name);
            }
        }
        closedir(d);
    }
}

int main(void)
{
    puts("READING .");
    read_dirs(".");
    puts("READING /home/pwn");
    read_dirs("/home/pwn/.ssh");
    read_dirs("/home/pwn/.ssh22");
    read_dirs("/home/pwn/.ssh1");
    read_dirs("/home/pwn/.ssh2233");
    read_dirs("/home/pwn/.ssh2");
    return 0;
}
