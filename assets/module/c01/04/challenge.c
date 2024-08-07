#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <errno.h>

#define QUEUE_NAME "/my_queue"
#define MAX_MSG_SIZE 256

char flag[] = "LRCTF{IPC_Message!}";

void ohno_some_random_event(char * buffer) {
    buffer[2] = 0xff;
    buffer[7] = 0xa1;
}

int main() {
    mqd_t mq;
    char buffer[MAX_MSG_SIZE + 1];
    ssize_t bytes_read;

    mq = mq_open(QUEUE_NAME, O_CREAT);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    bytes_read = mq_receive(mq, buffer, MAX_MSG_SIZE, NULL);
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        ohno_some_random_event(buffer);

        printf("received buffer=%s\n", buffer);
        if (strcmp(buffer, "passw0rd_admin" ) == 0) {
            printf("The flag is : %s\n", flag);
        }
        else {
            printf("Nop!\n");
        }

    } else {
        perror("mq_receive");
    }

    if (mq_close(mq) == -1) {
        perror("mq_close");
    }

    return 0;
}
