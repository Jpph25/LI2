#include "regras.h"

/*
Implementação do comando v
*/

void limpaL (CP *lista) {
     free (lista -> brancas); 
}


void push(int x, int y, CP *pintadas) {

     if (pintadas -> t == 0) {
         pintadas -> brancas  = malloc(4 * sizeof (coord));
         pintadas -> t = 4; 
     } 
      
     if (pintadas -> t == pintadas -> sp && pintadas -> t != 0) { 
         pintadas -> brancas = realloc (pintadas -> brancas, 2 * pintadas -> t * sizeof(coord));
         pintadas -> t *= 2;  
     }

     pintadas -> brancas[pintadas -> sp].x = x;
     pintadas -> brancas[pintadas -> sp].y = y;

     pintadas -> sp ++; 
}


void brancas(CP *pintadas, TAB *jogo) {
     int i, j;

     for (i = 0; i < jogo -> y; i++) {
          for (j = 0; j < jogo -> x; j++) {
               if (jogo -> tab[i][j].game >= 'A' && jogo -> tab[i][j].game <= 'Z')
                   push(j, i, pintadas);  
          } 
     }
}


int elem(int x, int y, CP *lista) {
    int i, r = 0;

    for (i = 0; i < lista -> sp && !r; i++) {
         if (lista -> brancas[i].x == x && lista -> brancas[i].y == y)
             r = 1;
    }

    return r;
}

void hCaminho(int x, int y, TAB *jogo, CP *visitadas) {

     if (y + 1 < jogo -> y && jogo -> tab[y + 1][x].game != '#' && !elem(x, y + 1, visitadas)) {  
         push(x, y + 1, visitadas);
         hCaminho(x, y + 1, jogo, visitadas);
     }

     if (x + 1 < jogo -> x && jogo -> tab[y][x + 1].game != '#' && !elem(x + 1, y, visitadas)) {
         push(x + 1, y, visitadas);
         hCaminho(x + 1, y, jogo, visitadas);
     }
 
     if (y - 1 >= 0 && jogo -> tab[y - 1][x].game != '#' && !elem(x, y - 1, visitadas)) { 
         push(x, y - 1, visitadas);
         hCaminho(x, y - 1, jogo, visitadas);
     }
 
     if (x - 1 >= 0 && jogo -> tab[y][x - 1].game != '#' && !elem(x - 1, y, visitadas)) {
         push(x - 1, y, visitadas);
         hCaminho(x - 1, y, jogo, visitadas); 
     }
}


void elemB(CP *visitadas, CP *pintadas, TAB *jogo) {
     int i, x, y, c = 0;

     for(i = 0; i < visitadas -> sp; i++) {
         x = visitadas -> brancas[i].x;
         y = visitadas -> brancas[i].y;

         if (jogo -> tab[y][x].game >= 'A' && jogo -> tab[y][x].game <= 'Z' && elem(x, y, pintadas))
             c ++;
     }

     if (c != pintadas -> sp) 
         printf("Não existe um caminho ortogonal entre todas as casas pintadas.\n");
}


void caminho(CP *pintadas, CP *visitadas, TAB *jogo) {
     int i, j, v = 1;
     int sX = -1, sY = -1;

     brancas(pintadas, jogo);

     for (i = 0; i < jogo -> y && v; i++) {
          for (j = 0 ; j < jogo -> x && v; j++) {
               if (jogo -> tab[i][j].game >= 'A' && jogo -> tab[i][j].game <= 'Z') {
                   sX = j;
                   sY = i;
                   v = 0; 
               }    
          }
     }
     
     if (sX != -1 && sY != -1) {
          push    (j, i, visitadas);
          hCaminho(j, i, jogo, visitadas);
          elemB   (visitadas, pintadas, jogo); 
     }
}


void rRiscadas(int x, int y, TAB *jogo) {

     if (y + 1 < jogo -> y && jogo -> tab[y + 1][x].game == '#') {  
         printf ("A coordenada (%d, %d) infringe a regra das riscadas (a coordenada abaixo está riscada).\n", x, y); 
     }

     if (x + 1 < jogo -> x && jogo -> tab[y][x + 1].game == '#') {
         printf ("A coordenada (%d, %d) infringe a regra das riscadas (a coordenada à direita está riscada).\n", x, y);
     }

     if (y - 1 >= 0 && jogo -> tab[y - 1][x].game == '#') { 
         printf ("A coordenada (%d, %d) infringe a regra das riscadas (a coordenada acima está riscada).\n", x, y);
     }

     if (x - 1 >= 0 && jogo -> tab[y][x - 1].game == '#') {
         printf ("A coordenada (%d, %d) infringe a regra das riscadas (a coordenada à esquerda está riscada).\n", x, y);
     }
}


void rBrancas (int x, int y, char c, TAB *jogo) {
     int i, v = 1;
    
     for (i = 1; v && y + i < jogo -> y; i++) {
          if(jogo -> tab[y + i][x].game == c) {
             v = 0;
             printf("A coordenada (%d, %d) infringe a regra das brancas  (existe outro %c na coluna).\n", x, y, c);
          }
     }

     for (i = 1; v && y - i >= 0; i++) {
          if(jogo -> tab[y - i][x].game == c) {
             v = 0;
             printf("A coordenada (%d, %d) infringe a regra das brancas  (existe outro %c na coluna).\n", x, y, c);
          }
     }

     v = 1;

     for (i = 1; v && x + i < jogo -> x; i++) {
          if(jogo -> tab[y][x + i].game == c) {
             v = 0;
             printf("A coordenada (%d, %d) infringe a regra das brancas  (existe outro %c na linha).\n", x, y, c);
          }
     }

     for (i = 1; v && x - i >= 0; i++) {
          if(jogo -> tab[y][x - i].game == c) {
             v = 0;
             printf("A coordenada (%d, %d) infringe a regra das brancas  (existe outro %c na linha).\n", x, y, c);
          }
     }
}


void verifica(TAB *jogo) {
     int i, j; 
    
     for(i = 0; i < jogo -> y; i++) {
          for(j = 0; j < jogo -> x; j++) {
              if (jogo -> tab[i][j].game == '#') 
                  rRiscadas(j, i, jogo);
              if (jogo -> tab[i][j].game >= 'A' && jogo -> tab[i][j].game <= 'Z')
                  rBrancas(j, i, jogo -> tab[i][j].game, jogo);  
          } 
     }

     CP pintadas, visitadas; 

     pintadas.sp       = 0;
     pintadas.t        = 0;
     pintadas.brancas  = NULL;

     visitadas.sp      = 0;
     visitadas.t       = 0;
     visitadas.brancas = NULL;

     caminho(&pintadas, &visitadas, jogo);

     putchar('\n');

     limpaL(&visitadas);
     limpaL(&pintadas);
}
