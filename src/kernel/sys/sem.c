
#include <nanvix/const.h>
#include <nanvix/pm.h>
#include <nanvix/hal.h>
#include <sys/sem.h>

/**
*@brief Creates semaphore
*@details if n>=0 => create semaphore and initiate its value with n
* else is n <0 return a dead semaphore
**/

PUBLIC semaphore create(int n){
  semaphore sem;

  if(n<0){
		return destroy(&sem);
	}

	sem.value = n;
	sem.wait_queue = NULL;

  return sem;
}

/** 
*@brief Tests semaphore value to decrease
*@details if value > 0 it is decremented and the calling process continues to execute normally
* otherwise the process is blocked on the waiting queue
**/

PUBLIC semaphore down(semaphore *sem){
  sem->value--;
  if (sem->value<0){
    sleep(&(sem->wait_queue), PRIO_SEM);
  }

  return *sem;
}

/**
*@brief Tests semaphore value to increase
*@details If the value become positive, we wake up the first process in the waiting queue.

**/

PUBLIC semaphore up(semaphore *sem){
  sem->value++;
  if (sem->value<=0){
    wakeup(&(sem->wait_queue));
  }

  return *sem;
}

/**
*@brief Destroys the semaphore
*@details we set the vlue and waiting queue of semaphore
**/
PUBLIC semaphore destroy(semaphore *sem){
  sem -> value = SEM_EMPTY;
  sem->wait_queue = NULL;

  return *sem;
}
