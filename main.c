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

void inicHPBAR( char array_hp[], int dim ) ;
void inicGREYBAR( char hp_gastados[], int dim );
int porcientoHP( int psActual, int psTotal, int dimArreglo );
void printHPBAR( char array_hp[], int posFinal );
void printHPGastados( char hp_gastados[], int dim, int posArran );
void showHPBAR(int psActual, int psTotal, char array_hp[], char hp_gastados[], int dimension_HPBAR);


int main() {
    char hp_gastados[20];
    char ps[20];
    inicGREYBAR( hp_gastados, 20 );
    inicHPBAR( ps, 20 );
    int psActual = 325;
    int psTotal = 325;
    do {

        showHPBAR( psActual, psTotal, ps, hp_gastados, 20 );
        psActual--;
        Sleep( 25 );
        system( "cls" );
    } while( psActual >= 0 );

    return 0;
}





void inicGREYBAR( char hp_gastados[], int dim ) {
    for( int i = 0; i < dim; i++ ) {
        hp_gastados[i] = HP;
    }
}

void inicHPBAR( char array_hp[], int dim ) {
    for( int i = 0; i < dim; i++ ) {
        array_hp[i] = HP;
    }
}

int porcientoHP( int psActual, int psTotal, int dimArreglo ) {
    int parteEntera = ( psActual * dimArreglo ) / psTotal;
    return parteEntera;
}

void printHPBAR( char array_hp[], int posFinal ) {
    for( int i = 0; i < posFinal; i++ ) {
        printf( "%c", array_hp[i] );
    }
}

void printHPGastados( char hp_gastados[], int dim, int posArran ) {
    for( int i = posArran; i < dim; i++ ) {
        printf( "%c", hp_gastados[i] );
    }
}

void showHPBAR(int psActual, int psTotal, char array_hp[], char hp_gastados[], int dimension_HPBAR) {
    int dimHPBAR;
    int barraPS;

    barraPS = porcientoHP( psActual, psTotal, 100 );
    dimHPBAR = porcientoHP( psActual, psTotal, dimension_HPBAR );

    ( barraPS > 50 ) ? Color( BLACK, GREEN ) : ( barraPS > 20 ) ? Color( BLACK, YELLOW ) : Color( BLACK, RED );
    gotoxy(20, 21);
    printHPBAR( array_hp, dimHPBAR );
    Color( BLACK, LGREY );
    printHPGastados( hp_gastados, dimension_HPBAR, dimHPBAR );
    Color( BLACK, WHITE );
    //printf("\n");
    gotoxy(20, 22);
    printf( "%3d/%3d\t\t%d%%", psActual, psTotal, barraPS );
}
