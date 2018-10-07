#include <time.h>
#include <stdio.h>
struct {
  int a;
  int b;
}  s[5000];

main()
{
  struct timespec cgt1,cgt2;
double ncgt;
int ii,i,X01,X02,X1,X2,X11,X12,X13,X21,X22,X23;
int R[40000];
  clock_gettime(CLOCK_REALTIME,&cgt1);


  for (ii=1; ii<=10000;ii++) { //si dividimos 40000/4= 10000  
    for(i=0; i<1250;i++){ //si dividimos 5000/4 = 1250
      X1+=2*s[i].a+ii;
      X11+=2*s[i+1].a+(ii+1);
      X12+=2*s[i+2].a+(ii+2);
      X13+=2*s[i+3].a+(ii+3);
    }
    for(i=0; i<1250;i++){ //si dividimos 5000/4 = 1250
      X2+=3*s[i].b-ii;    
      X21+=3*s[i+1].b-(ii+1);
      X22+=3*s[i+2].b-(ii+2);
      X23+=3*s[i+3].b-(ii+3);
    }
    X01+=X1+X11+X12+X13;
    X02+=X2+X21+X22+X23;
    
    if (X01<X02) R[ii]=X01; else R[ii]=X02;
    
  }
  clock_gettime(CLOCK_REALTIME,&cgt2);
  ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec) + (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
  printf("Tiempo(seg.): %11.9f\n",ncgt);
}