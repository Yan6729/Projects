#include <errno.h>
#include <unistd.h>
int main(int ac, char **av) {
char *args[] = {av[1], NULL};
    execvp(av[1], args);
//    perror("execvp");
return 1;
}
