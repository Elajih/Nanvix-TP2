
#include <nanvix/const.h>
#include <nanvix/pm.h>
#include <nanvix/hal.h>
#include <sys/sem.h>

PUBLIC semaphore create(int n){
  semaphore sem;

  if(n<0){
		return destroy(&sem);
	}

	sem.value = n;
	sem.wait_queue = NULL;

  return sem;
}
PUBLIC semaphore down(semaphore *sem){
//todos

  return *sem;
}
PUBLIC semaphore up(semaphore *sem){
  //TO DO
  return *sem;
}
PUBLIC semaphore destroy(semaphore *sem){
//TO DO

  return *sem;
}
