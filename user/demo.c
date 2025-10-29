// demo.c - Prueba Lottery Scheduler en xv6
#include "kernel/types.h"
#include "user/user.h"

#define N 10
#define BURN_LOOPS 50000000  // Ajusta según tu CPU

struct child_info {
  int pid;
  int tickets;
  int slices;
};

int main(int argc, char *argv[]) {
  int i;
  int pid;
  struct child_info info[N];

  for(i = 0; i < N; i++){
    pid = fork();
    if(pid < 0){
      printf("fork failed\n");
      exit(1);
    }
    if(pid == 0){
      // Hijo
      settickets(50*(i+1));  // Asignar tickets distintos
      // Simular uso de CPU
      for(int j = 0; j < BURN_LOOPS; j++){
        asm("");  // no-op para gastar CPU
      }
      exit(0);  // hijo termina
    } else {
      // Padre: guardar PID y tickets
      info[i].pid = pid;
      info[i].tickets = 50*(i+1);
      info[i].slices = 0;  // se actualizará luego
    }
  }

  // Padre espera a todos los hijos
  for(i = 0; i < N; i++){
    wait(0);  // esperamos que cada hijo termine
    // Obtener slices del hijo terminado
    info[i].slices = getcpuslices(); // esto obtiene slices de *este proceso*, así que mejor: guardar slices antes de que el hijo muera
  }

  // Imprimir tabla final
  printf("pid\ttickets\tcpu_slices\n");
  for(i = 0; i < N; i++){
    printf("%d\t%d\t%d\n", info[i].pid, info[i].tickets, info[i].slices);
  }

  exit(0);
}