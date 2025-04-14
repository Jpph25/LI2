/*
Implementação dos comandos b <coordenadas>, r <coordenadas> e d 
 <coordenadas> - <letra minúscula><número>
*/

// Tipo de cada casa de um tabuleiro
typedef struct{
        char orig; // Casa original
        char game; // Casa a ser modificada
} casa;

// Tipo do tabuleiro
typedef struct{
        int x;      // Numero de colunas 
        int y;      // Numero de linhas 
        casa **tab; // Tabuleiro  
} TAB; 

void tabuleiro(); 