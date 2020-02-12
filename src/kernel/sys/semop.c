#include <nanvix/const.h>
#include <nanvix/pm.h>
#include <nanvix/hal.h>
#include <sys/sem.h>


/*
 * Change the semaphore value
 * Decrease ii if op is negative
 * Increase it if op is positive
 */
int sys_semop(int semid, int op){

  if(op<0){
		for (int i=0; i>op; i--)
			current_semaphores[semid].sem=down(&(current_semaphores[semid].sem));
	}

	else if (op>0) {
		for (int i=0; i<op; i++)
			current_semaphores[semid].sem=up(&(current_semaphores[semid].sem));
	}

  return 0;
}
