#ifndef __POKEMON_H__
#define __POKEMON_H__

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
    char name[10];
    //char* types[10]; //ToDo
    stStatics _Est;
    //stAtaque ataques[4];
} stPkmn;

#endif // __POKEMON_H__
