#include <nanvix/const.h>
#include <sys/sem.h>

/*
 * Run operations on a semaphore
 * GETVAL, SETVAL, IPC_RMID
 */

int sys_semctl(int semid, int cmd, int val){
  int value=-1;

//return current semaphore's value
if (cmd==GETVAL){
  value= current_semaphores[semid].sem.value;
}

//define semaphore's value with val
else if (cmd==SETVAL){
  current_semaphores[semid].sem.value=val;
  value=0;
}

//delete semaphore and destroy it if it isn't used
else if(cmd==IPC_RMID){
  if(current_semaphores[semid].nbp_currents==1){
    current_semaphores[semid].sem=destroy(&(current_semaphores[semid].sem));
    current_semaphores[semid].nbp_currents=0;
    current_semaphores[semid].key=SEM_EMPTY;
  }
  else{
    current_semaphores[semid].nbp_currents--;
}
    value=0;
}



  return value;
}
