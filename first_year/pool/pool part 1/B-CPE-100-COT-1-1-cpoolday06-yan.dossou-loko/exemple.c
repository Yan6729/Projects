#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if(ac == 1) {
	struct dirent *d;
	DIR *dir = opendir(".");
	if(!dir) {
	    perror("Unable to read directory");
	    exit(EXIT_FAILURE);
	}
	while((d = readdir(dir)) != NULL) {
	    if(d->d_name[0] == '.') continue;
	    printf("%s", d->d_name);
	    printf("\n");
	}
	printf("\n");
    }
    return 0;
}
