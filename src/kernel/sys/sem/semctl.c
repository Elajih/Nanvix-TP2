#include <nanvix/const.h>
#include <nanvix/pm.h>
#include <nanvix/hal.h>
#include <sys/sem.h>

int sys_semctl(int a, int b, int c){
  return 1;
}
