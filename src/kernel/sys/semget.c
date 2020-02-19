#include <nanvix/const.h>
#include <nanvix/pm.h>
#include <nanvix/hal.h>
#include <sys/sem.h>


	/*
	 * Use semaphore associated to a key
	 * or Create it if doesn't exist
	 */



int sys_semget(unsigned key){

//if we find the semaphore associated to the our key we return the key
//if goes right return semaphore id
  for(int i =0; i<NB_SEM; i++){
    if(semaphoreTab[i].key==key){
      semaphoreTab[i]. npcurrent++;
      return i;
    }

  }

//if not
//adding new sepmaphore to existant semaphores

semaphoreTab[NB_SEM].sem=create(SEM_EMPTY);
semaphoreTab[NB_SEM].key=key;
semaphoreTab[NB_SEM]. npcurrent=1;

NB_SEM ++;

  return NB_SEM-1;
}
