#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define QTD_T 3


int max, min, qtd = 0;
int num[0];
float med;

void *minimo();
void *maximo();
void *media();

int main(){
    pthread_t threads [QTD_T];


    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        scanf("%d", &num[i]);
    }
    
    pthread_create(&(threads[0]), NULL, media, NULL);
    pthread_join(threads[0], NULL);

    pthread_create(&(threads[1]), NULL, maximo, NULL);
    pthread_join(threads[1], NULL);

    pthread_create(&(threads[2]), NULL, minimo, NULL);
    pthread_join(threads[2], NULL);


    printf("The average value is %0.2f", med);
    printf("\nThe maximum value is %d", max);
    printf("\nThe minimum value is %d\n", min);

    return 0;


}

void *minimo() {
    int minimo = num[0];
    for (int i = 1; i < qtd; i++){
        if (num[i] < minimo){
            minimo = num[i];
        }
    }
    min = minimo;

    return NULL;
}

void *maximo() {
    int maximo = num[0];
    for (int i = 1; i < qtd; i++){
        if (num[i] > maximo){
            maximo = num[i];
        }
    }
    max = maximo;

    return NULL;
}

void *media() {
    int total = 0;
    for (int i = 0; i < qtd; i++){
        total += num[i];
    }
    med = total / qtd;

    return NULL;
}