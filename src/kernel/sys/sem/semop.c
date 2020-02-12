#include <nanvix/const.h>
#include <nanvix/pm.h>
#include <nanvix/hal.h>
#include <sys/sem.h>

int sys_semop(int a, int b){
  return 1;
}
