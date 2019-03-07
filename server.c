#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXSIZE     27

void die(char *s)
{
    perror(s);
    exit(1);
}

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        die("shmat");

    s = shm;
    printf("Sending Message to Client\n");
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;

    printf("Waiting for client to read the message sent\n");
    while (*shm != '*')
        sleep(1);
    printf("Client finished reading the message");
    exit(0);
}
