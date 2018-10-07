#include <time.h>
#include <stdio.h>

struct timespec cgt1,cgt2;
double ncgt;
int i,a,N;
int *x,*y;

int main(int argc, char** argv)
{
  unsigned int N=atoi(argv[1]);
  x=(int*) malloc(N*sizeof(int));
  y=(int*) malloc(N*sizeof(int));
  clock_gettime(CLOCK_REALTIME,&cgt1);
  
  for (i=1; i<=N;i++) y[i]=a*x[i]+y[i];
    
  clock_gettime(CLOCK_REALTIME,&cgt2);
  ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec) + (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
  printf("Tiempo(seg.): %11.9f\n",ncgt);
}