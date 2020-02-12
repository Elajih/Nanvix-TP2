/*
 * Copyright(C) 2011-2016 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 *
 * This file is part of Nanvix.
 *
 * Nanvix is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Nanvix is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Nanvix. If not, see <http://www.gnu.org/licenses/>.
 */

 #include<nanvix/const.h>
 #include<nanvix/config.h>

#ifndef SEM_H_
#define SEM_H_

	/**
	 * @brief Comand values for semaphores.
	 */
	/**@{*/
	#define GETVAL   0 /**< Returns the value of a semaphore. */
	#define SETVAL   1 /**< Sets the value of a semaphore.    */
	#define IPC_RMID 3 /**< Destroys a semaphore.            */
	/**@}*/

	#define SEM_SIZE_T PROC_MAX //Semaphore's size array
	#define SEM_EMPTY -999 //semaphore value when emty

  #ifndef _ASM_FILE_
	/**
	*@brief the structure of semaphore
	*
	*@details composed by : semaphore value ad wainting queue
	*
	*
	**/
 PUBLIC typedef struct {
	 int value;
	 struct process *wait_queue;

 }semaphore;

 /**
 *@brief semaphore storage
 *
 *@details composed by : semaphore, a key, number of current process using the semaphore
  *
 *
 **/
 PUBLIC typedef struct {
	 semaphore sem;
	 unsigned key;
	 int nbp_currents;
 }s_statement;


 /**
	 * @brief Active semaphores table
	 *
	**/

	PUBLIC s_statement current_semaphores[SEM_SIZE_T];

	// active semaphores number
	PUBLIC int NB_SEM;

	// Functions to edit a semaphore

	PUBLIC semaphore create(int n);
	PUBLIC semaphore down(semaphore *sem);
	PUBLIC semaphore up(semaphore *sem);
	PUBLIC semaphore destroy(semaphore *sem);



	/* Forward definitions. */
	extern int semget(unsigned);
	extern int semctl(int, int, int);
	extern int semop(int, int);

#endif
#endif /* SEM_H_ */
