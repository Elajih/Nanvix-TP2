#include <nanvix/const.h>
#include <sys/sem.h>

/*
 * Run operations on a semaphore
 * GETVAL, SETVAL, IPC_RMID
 */

int sys_semctl(int semid, int cmd, int val){
  int value = -1;


//return current semaphore's value
if (cmd == GETVAL){
  value = semaphoreTab[semid].sem.value;
}

//define semaphore's value with val
else if (cmd == SETVAL){
  semaphoreTab[semid].sem.value = val;
  value = 0;
}

//delete semaphore and destroy it if it isn't used
else if(cmd == IPC_RMID){
  if(semaphoreTab[semid].npcurrent == 1){
    semaphoreTab[semid].sem = destroy(&(semaphoreTab[semid].sem));
    semaphoreTab[semid].npcurrent = 0;
    semaphoreTab[semid].key = SEM_EMPTY;
  }
  else{
    semaphoreTab[semid]. npcurrent--;
  }
    value = 0;
}

return value;
}
