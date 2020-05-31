#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include "pokemon.h"
#include "gotoxy.h"
#include "menu.h"



void inicHPBAR( char array_hp[], int dim ) ;
void inicGREYBAR( char hp_gastados[], int dim );
int porcientoHP( int psActual, int psTotal, int dimArreglo );
void printHPBAR( char array_hp[], int posFinal );
void printHPGastados( char hp_gastados[], int dim, int posArran );
void showHPBAR(stPkmn archivoPokemon[], int idPokemon, int x, int y);
int calculoDanio(stPkmn pkmAtaca, stPkmn pkmnDefiende);

int main() {
    hidecursor(0);
    srand(time(NULL));
    FILE* archivoPokemon;



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

void showHPBAR(stPkmn archivoPokemon[2], int idPokemon, int x, int y) {
    //Inicializacion de las barras
    char hp_gastados[DIMHP];
    char barra_ps[DIMHP];
    inicGREYBAR( hp_gastados, DIMHP );
    inicHPBAR( barra_ps, DIMHP );
    //Inicializacion de los datos
    int dimHPBAR;
    int barraPS;
    int psTotal = archivoPokemon[idPokemon + 1]._Est.psTOTAL;
    int psActual = archivoPokemon[idPokemon + 1]._Est.psTOTAL;
    barraPS = porcientoHP( psActual, psTotal, 100 );
    dimHPBAR = porcientoHP( psActual, psTotal, DIMHP );

    gotoxy(x, y);
    printf("%s\n", archivoPokemon[idPokemon + 1].name);
    ( barraPS > 50 ) ? Color( BLACK, GREEN ) : ( barraPS > 20 ) ? Color( BLACK, YELLOW ) : Color( BLACK, RED );

    gotoxy(x, y + 1);
    printHPBAR( barraPS, dimHPBAR );
    Color( BLACK, LGREY );
    printHPGastados( hp_gastados, dimHPBAR, DIMHP );
    Color( BLACK, WHITE );
    gotoxy(x, y + 2);
    printf( "%3d/%3d\t\t%d%%", psActual, psTotal, barraPS );
}

int calculoDanio(stPkmn pkmAtaca, stPkmn pkmnDefiende){
    float danio;
    //Sistema de niveles NO IMPLEMENTADO, se presupone que todos los pokemon son de nivel 100 por el momento.
    int nivel = 100;
    //Daño de poder segun el ataque NO IMPLEMENTADO
    int poder = 70;
    //Bonificacion depende del ataque que realiza, si es del mismo tipo que el pokemon sera mas efectivo.
    float bonificacion = 1.0;
    //Efectividad: depende de que tan eficaz es el tipo de ataque con que se ataca y el tipo del pokemon.
    float efectividad = 1.0;
    //Variacion: Valor incalculable, sirve para dar aleatoriedad al daño causado.
    float variacion = (rand() % 16 + 85);
    //Todas las variables que intervienen en el calculo estan cargadas para posibles modificaciones futuras.
    danio = 0.01 * bonificacion * efectividad * variacion * ( (((0.2 * nivel + 1) * pkmAtaca._Est.ATK * poder) / (25 * pkmnDefiende._Est.DEF) ) + 2 );

    return (int) danio;
}


void cargarPokemonEnArchivo(FILE* archivo){

    fopen("archivoPokemon.bin", "ab");


}
