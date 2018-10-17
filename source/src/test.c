#define _GNU_SOURCE
#define _FILE_OFFSET_BITS 64
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#define errExit(msg) do { perror(msg); exit(EXIT_FAILURE); \
	} while (0)
int
main(int argc, char *argv[])
{
    struct rlimit old, new;
    struct rlimit *newp;
    pid_t pid;
    if (!(argc == 2 || argc == 4)) {
        fprintf(stderr, "Usage: %s <pid> [<nouvelle-limite-souple> "
                "<nouvelle-limite-stricte>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    pid = atoi(argv[1]);        /* PID du processus cible */
    newp = NULL;
    if (argc == 4) {
        new.rlim_cur = atoi(argv[2]);
        new.rlim_max = atoi(argv[3]);
        newp = &new;
    }
    /* Définir la limite de temps CPU du processus cible ;
       récupérer et afficher la limite de temps CPU antérieure */
    if (prlimit(pid, RLIMIT_CPU, newp, &old) == -1)
        errExit("prlimit-1");
    printf("Limites précédentes : souple=%lld; stricte=%lld\n",
		   (long long) old.rlim_cur, (long long) old.rlim_max);
    /* Récupérer et afficher la nouvelle limite de temps CPU */
    if (prlimit(pid, RLIMIT_CPU, NULL, &old) == -1)
        errExit("prlimit-2");
    printf("Nouvelles limites: souple=%lld; stricte=%lld\n",
		   (long long) old.rlim_cur, (long long) old.rlim_max);
    exit(EXIT_FAILURE);
}
