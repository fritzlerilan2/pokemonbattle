#ifndef __POKEMON_H__
#define __POKEMON_H__

///CONSTANTES
#define HP 219
#define BLACK 0
#define GREEN 2
#define YELLOW 14
#define RED 4
#define WHITE 15
#define LGREY 7
#define HPBAR1_X 10
#define HPBAR1_Y 21
#define HPBAR2_X 60
#define HPBAR2_Y 4
#define DIMHP 20

typedef struct{
    int psTOTAL;
    int ATK;
    int DEF;
    int SPEED;
} stStatics;
/*
typedef struct{
    char nombre[10];
    int id;
    int poder;
    int pp;
}stAtaque;
*/
typedef struct {
    int id;
    char name[15];
    //char* types[10]; //ToDo
    stStatics _Est;
    //stAtaque ataques[4];
} stPkmn;

#endif // __POKEMON_H__
