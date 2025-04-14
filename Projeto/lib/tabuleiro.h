/*
Implementação dos comandos b <coordenadas>, r <coordenadas> e d 
 <coordenadas> - <letra minúscula><número>
*/

typedef struct{
        char orig;
        char game;
} casa;

typedef struct{
        int x;
        int y; 
        casa **tab;  
} TAB; 

void tabuleiro(); 