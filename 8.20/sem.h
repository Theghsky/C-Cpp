#ifndef __SEM_H__
#define __SEM_H__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
				(Linux-specific) */
};

extern void sem_init(int semid,int semnum,int value);
extern void sem_init_ALL(int semid,int semnum,unsigned short *value);
extern void sem_p(int semid,int semnum);
extern void sem_v(int semid,int semnum);

#endif

