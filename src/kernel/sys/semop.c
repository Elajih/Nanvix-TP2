#include <nanvix/const.h>
#include <nanvix/pm.h>
#include <nanvix/hal.h>
#include <sys/sem.h>


/*
 * Change the semaphore value
 * Decrease it if op is negative
 * Increase it if op is positive
 */
int sys_semop(int semid, int op){

  semaphore semo=semaphoreTab[semid].sem;
  if(op<0){
		for (int i=0; i>op; i--)
		    semo=down(&semo);
	}

	else if (op>0) {
		for (int i=0; i<op; i++)
			semo=up(&semo);
	}

  return 0;
}
