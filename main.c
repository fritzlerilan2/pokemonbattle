#include <stdio.h>
#include <stdlib.h>

#include "pokemon.h"
#include "gotoxy.h"
#include "menu.h"


void inic_HPBAR(char* ps, int dim);
void inicMascara(char* mascara, int dim);
int calcularPorcHP(int psActual, int psTotal, int dimArreglo);
void printHPBAR(char* HPBAR, int posFinal);
void printHPMascara(char* mascara, int dim, int posArran);
void HPBAR(int psActual, int psTotal, char* ps, char* mascara, int dimension);


int main()
{
    char mascara[20];
    char ps[20];
    inicMascara(mascara, 20);
    inic_HPBAR(ps, 20);
    int psActual = 163;
    int psTotal = 325;
    HPBAR(psActual, psTotal, ps, mascara, 20);
    return 0;
}





void inicMascara(char* mascara, int dim){
    for(int i = 0; i < dim; i++){
        mascara[i] = 0;
    }
}

void inic_HPBAR(char* ps, int dim){
    for(int i = 0; i < dim; i++){
        ps[i] = 35;
    }
}

int calcularPorcHP(int psActual, int psTotal, int dimArreglo){
    int parteEntera;
    parteEntera = (psActual * dimArreglo) / psTotal;
    return parteEntera;
}

void printHPBAR(char* HPBAR, int posFinal){
    for(int i = 0; i < posFinal; i++){
        printf("%c", HPBAR[i]);
    }
}

void printHPMascara(char* mascara, int dim, int posArran){
    for(int i = posArran; i < dim; i++){
        printf("%c", mascara[i]);
    }
}

void HPBAR(int psActual, int psTotal, char* ps, char* mascara, int dimension){
    int dimHPBAR;
    int porcentaje;
    porcentaje = calcularPorcHP(psActual, psTotal, 100);
    dimHPBAR = calcularPorcHP(psActual, psTotal, dimension);
    printf("[");
    printHPBAR(ps, dimHPBAR);
    printHPMascara(mascara, dimension, dimHPBAR);
    printf("]\n");
    printf("%4d/%4d    %d%%", psActual, psTotal, porcentaje);
}
