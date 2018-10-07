#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num()0
#endif

main(int argc, char **argv){
  int i,n=200,chunk,a[n],suma=0;
  
  if(argc<3){
    fprintf(stderr,"\nFalta iteraciones o chunk\n");
    exit(-1);
  }
  n= atoi(argv[1]); if(n>200) n=200; chunk=atoi(argv[2]);
  
  for(i=0;i<n;i++) a[i]=i;
  
  #pragma omp parallel for firstprivate(suma)\
	lastprivate(suma) schedule(dynamic,chunk)
  for(i=0;i<n;i++){
      suma=suma+ a[i];
      printf("thread %d suma a [%d] suma=%d\n", omp_get_thread_num(),i,suma);
      printf("Valor de la variable dyn-var: %d \n",omp_get_dynamic());
      printf("Valor de la variable nthreads_var: %d\n",omp_get_max_threads());
      printf("Valor de la variable thread_limit-var: %d\n", omp_get_thread_limit()); //suponemos versión 3.0 de openMP
      //printf("Valor de la variable run-sched-var: %d\n",omp_get_schedule(n,chunk));
      printf("Valor de la función omp_get_num_threads: %d\n",omp_get_num_threads());
      printf("Valor de la función omp_get_num_procs: %d\n",omp_get_num_procs());
      printf("Valor de la función omp_in_parallel: %d\n",omp_in_parallel());
      printf("\n");
  }
    
      printf("\nFuera de 'parallel for' suma=%d\n",suma);
      printf("Valor de la variable dyn-var: %d\n",omp_get_dynamic());
      printf("Valor de la variable nthreads_var: %d\n",omp_get_max_threads());
      printf("Valor de la variable thread_limit-var: %d\n",omp_get_thread_limit()); //suponemos versión 3.0 de openMP
      //printf("Valor de la variable run-sched-var: ",omp_get_schedule(n,chunk));
      printf("Valor de la función omp_get_num_threads: %d\n",omp_get_num_threads());
      printf("Valor de la función omp_get_num_procs: %d\n",omp_get_num_procs());
      printf("Valor de la función omp_in_parallel: %d\n",omp_in_parallel());
      printf("\n");
}