#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int podziel(const char *s)
{   
    int fdFirst = open(s, O_RDONLY);
    if (fdFirst == -1)
        return -1;
    char fileBuffer[4097];
    int bytes = read(fdFirst, fileBuffer, 4096);
    if(bytes == -1)
        return -1;
    int firstHalf_fd = open("fragment1", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if(firstHalf_fd == -1)
        return -1;
    int secondHalf_fd = open("fragment2", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU) ;
    if(secondHalf_fd == -1)
        return -1;
    if(bytes % 2 == 0){
        if(write(firstHalf_fd, fileBuffer, bytes / 2) == -1)
            return -1;
        if(write(secondHalf_fd, fileBuffer + (bytes / 2), bytes / 2) == -1)
            return -1;
    }
    else if(bytes %2 == 1){
        if(write(firstHalf_fd, fileBuffer, (bytes / 2) + 1) == -1)
            return -1;
        if(write(secondHalf_fd, fileBuffer + (bytes / 2) + 1, bytes/2) == -1)
            return -1;
    }
    close(fdFirst);
    close(firstHalf_fd);
    close(secondHalf_fd);
    return 0;
}
