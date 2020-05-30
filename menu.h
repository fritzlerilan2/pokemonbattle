#ifndef __MENU_H__
#define __MENU_H__
#define FLECHA_ARRIBA 72
#define FLECHA_ABAJO 80
#define ENTER 13
#include <string.h>

/********************************************//**
 * \brief   Carga Opciones de un menu
 *
 * \param   Arreglo de Strings (El que contenga las opciones)
 * \param   Cantidad total de opciones.
 * \return  Nada
 *
 ***********************************************/

void cargarOpcionesEnPantalla(char* opciones[], int cantOpciones){
    for(int i = 0; i < cantOpciones; i++) {
        gotoxy(10, 4 + i);
        printf("%d) %s", i+1, opciones[i]);
    }
}

/********************************************//**
 * \brief   Imprime el Menu de Titulo
 *
 * \param   Titulo del menu
 * \param   Arreglo de Strings con opciones.
 * \param   Cantidad de opciones
 * \return  Imput (Posicion en el menu)
 *
 ***********************************************/

int menu(const char* titulo, char* opciones[], int cantOpciones) {
    int input = 1;
    int flag = 0;
    int tecla;
    int flecha_X = 4;
    system("cls");
    gotoxy( 45 -(strlen(titulo) / 2 ), 2);
    printf("%s", titulo);
    cargarOpcionesEnPantalla(opciones, cantOpciones);
    do {
        gotoxy(flecha_X, 3 + input);
        printf("-->");
        do {
            tecla = getch();
            switch(tecla) {
            case FLECHA_ABAJO:
                input++;
                if(input > cantOpciones) {
                    input = 1;
                }
                break;
            case FLECHA_ARRIBA:
                input--;
                if(input < 1) {
                    input = cantOpciones;
                }
                break;
            case ENTER:
                flag = 1;
                break;
            }
            gotoxy(flecha_X, 3 + input);
            //Sleep(1500);
            printf("   ");
        } while(tecla != FLECHA_ABAJO && tecla!= FLECHA_ARRIBA && tecla != ENTER);
    } while(flag == 0);
    return input;
}

/********************************************//**
 * \brief   Menu Principal
 *
 * \param
 * \param
 * \return  Nada
 *
 ***********************************************/

void menu_principal() {
    hidecursor(0);
    int opcionElegida;
    const char *titulo = {" TRABAJO PRACTICO: ESTRUCTURAS"};
    char *opciones[15] = {" CARGAR POKEMON.",
                          " SALIR"
                         };
    int cantOpciones = 2;
    do {
        system("color F");
        system("cls");
        opcionElegida = menu(titulo, opciones, cantOpciones);

        switch(opcionElegida) {
        case 1:
            break;
        case 2:
            break;
        }
    } while(opcionElegida != cantOpciones);
}



#endif // __MENU_H__
