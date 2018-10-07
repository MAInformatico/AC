#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PRINTF_ALL
#define VECTOR_DYNAMIC //descomentar para que los vectores sean variables ...
		      //dinámicas (memoria reautilizable durante la ejecución)
#ifdef VECTOR_GLOBAL
#define MAX 33554432
double matriz[MAX], matriz2[MAX], resultado[MAX];
#endif
		      
		      
int main(int argc, char** argv){
    int i,j, temporal,k;
    struct timespec cgt1,cgt2;
    double ncgt; //para tiempo de ejecución
 
    if(argc<2){
      printf("Faltan nº componentes de las matrices <nº_filas_matriz_y_nº_columnas_matriz>\n");
      exit(-1);
    }
    unsigned int N=atoi(argv[1]);
    
    int **matriz, **matriz2, **resultado;
    //Reservamos espacio pa la matriz
    //*******************************
    matriz= (int**) malloc(N*sizeof(int*));
    for(i=0;i<N;i++)
      matriz[i]=(int *) malloc(N*sizeof(int));

    matriz2= (int**) malloc(N*sizeof(int*));
    for(i=0;i<N;i++)
      matriz2[i]=(int *) malloc(N*sizeof(int));
    
    resultado= (int**) malloc(N*sizeof(int*)); //matriz resultante de la multiplicación
    for(i=0;i<N;i++)
      resultado[i]=(int *) malloc(N*sizeof(int));    
    //*******************************
    if((matriz==NULL) || (matriz2==NULL) || (resultado==NULL)){
      printf("Error en la reserva de espacio para los vectores\n");
      exit(-2);
    }
  
    //Inicializar matrices
    for(i=0;i<N;i++){
      for(j=0;j<N;j++)
	  matriz[i][j]= i*j;
    }
    for(i=0;i<N;i++){
      for(j=0;j<N;j++)
	  matriz2[i][j]= i*j;
    }    
    for(i=0;i<N;i++){
      for(j=0;j<N;j++)
	  resultado[i][j]=0;
    }   
    //***********************
       
   
    clock_gettime(CLOCK_REALTIME,&cgt1);
    //Calcular multiplicación de la matrices
    //**************************************
    for(i=0;i<N;i++){ //filas de la matriz resultante
      	for(j=0;j<N;j++){ //columnas de la matriz resultante
	  for(k=0;k<N;k++) //realizamos las multiplicaciones de los elementos de la matriz
	    resultado[i][j]=matriz[i][k] * matriz2[k][j];
	}
    }
    //**************************************
    clock_gettime(CLOCK_REALTIME,&cgt2);
    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec) + (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
        
    #ifdef PRINTF_ALL
    printf("Tiempo(seg.): %11.9f\t / Tamaño Vectores:%u\n",ncgt,N);
    for(i=0;i<N;i++){
      for(j=0;j<N;j++)
	printf("/matriz[%d][%d]*matriz2[%d][%d](%d*%d=%d)/\n", i,j,i,j,matriz[i][j],matriz2[i][j],matriz[i][j] * matriz2[i][j]);
    }
    printf("Resultado final resultante:\n");
    for(i=0;i<N;i++){
      for(j=0;j<N;j++)
	printf("resultado[%d][%d]= %d\n", i,j,resultado[i][j]);
    }
    #else
    printf("Tiempo(seg.): %11.9f\t / Tamaño Vectores:%u\n",
	   ncgt,N,matriz[0][0],matriz2[0][0],resultado[0][0],N-1,N-1,N-1,matriz[N-1][N-1],matriz2[N-1][N-1],resultado[N-1][N-1]);
    #endif
    
    #ifdef VECTOR_DYNAMIC
      free(matriz); //libera el espacio reservado para v1
      free(matriz2); //libera el espacio reservado para v2
      free(resultado); //libera el espacio reservado para v3
    #endif
    return 0;
}