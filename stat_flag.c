#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
 
int main(int argc, char **argv)
{
 
    struct stat fileStat;
    struct passwd* userPasswd;
    struct passwd* effectiveUserPasswd;

    struct passwd* fileOwner;
    struct group* fileGroup;
    if(stat("flag",&fileStat) < 0)    
        return 1;
    userPasswd = getpwuid(getuid());
    effectiveUserPasswd = getpwuid(geteuid());
    fileOwner = getpwuid(fileStat.st_uid);
    fileGroup = getgrgid(fileStat.st_gid);

    printf("Current User: %s\n", userPasswd->pw_name);
    printf("Current Effective User: %s\n", effectiveUserPasswd->pw_name);
 
    printf("Information for %s\n","flag");
    printf("---------------------------\n");
    printf("File Size: \t\t%d bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%d\n",fileStat.st_ino);
    printf("File owner: \t\t%s\n", fileOwner->pw_name);
    printf("File group: \t\t%s\n", fileGroup->gr_name);
 
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
 
    return 0;
}
