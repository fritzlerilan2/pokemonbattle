#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "pokemon.h"
#include "gotoxy.h"
#include "menu.h"

#define HP 219
#define BLACK 0
#define GREEN 2
#define YELLOW 14
#define RED 4
#define WHITE 15
#define LGREY 7

void inic_HPBAR( char* ps, int dim );
void inicMascara( char* mascara, int dim );
int calcularPorcHP( int psActual, int psTotal, int dimArreglo );
void printHPBAR( char* HPBAR, int posFinal );
void printHPMascara( char* mascara, int dim, int posArran );
void HPBAR( int psActual, int psTotal, char* ps, char* mascara, int dimension );


int main() {
    char mascara[20];
    char ps[20];
    inicMascara( mascara, 20 );
    inic_HPBAR( ps, 20 );
    int psActual = 325;
    int psTotal = 325;
    do {
        HPBAR( psActual, psTotal, ps, mascara, 20 );
        psActual--;
        Sleep( 25 );
        system( "cls" );
    } while( psActual >= 0 );

    return 0;
}





void inicMascara( char* mascara, int dim ) {
    for( int i = 0; i < dim; i++ ) {
        mascara[i] = HP;
    }
}

void inic_HPBAR( char* ps, int dim ) {
    for( int i = 0; i < dim; i++ ) {
        ps[i] = HP;
    }
}

int calcularPorcHP( int psActual, int psTotal, int dimArreglo ) {
    int parteEntera = ( psActual * dimArreglo ) / psTotal;
    return parteEntera;
}

void printHPBAR( char* HPBAR, int posFinal ) {
    for( int i = 0; i < posFinal; i++ ) {
        printf( "%c", HPBAR[i] );
    }
}

void printHPMascara( char* mascara, int dim, int posArran ) {
    for( int i = posArran; i < dim; i++ ) {
        printf( "%c", mascara[i] );
    }
}

void HPBAR(int psActual, int psTotal, char* ps, char* mascara, int dimension) {
    int dimHPBAR;
    int porcentaje;
    porcentaje = calcularPorcHP( psActual, psTotal, 100 );
    dimHPBAR = calcularPorcHP( psActual, psTotal, dimension );
    ( porcentaje > 50 ) ? Color( BLACK, GREEN ) : ( porcentaje > 20 ) ? Color( BLACK, YELLOW ) : Color( BLACK, RED );
    printHPBAR( ps, dimHPBAR );
    Color( BLACK, LGREY );
    printHPMascara( mascara, dimension, dimHPBAR );
    Color( BLACK, WHITE );
    printf("\n");
    printf( "%4d/%4d    %d%%", psActual, psTotal, porcentaje );
}
