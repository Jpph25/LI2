#include "solve.h" 

/*
Implementação dos comando R 
*/

void cpyTab(TAB *dest, TAB *font) {
     int i, j;  
 
     dest -> x = font -> x;
     dest -> y = font -> y;
 
     for (i = 0; i < dest -> y; i++) {   
          for (j = 0; j < dest -> x; j++) {
               dest -> tab[i][j].game = font -> tab[i][j].game;
               dest -> tab[i][j].orig = font -> tab[i][j].orig;
          }
     }
 }


int tabIguais(TAB *aux, TAB *jogo) {
    int r = 1;
 
    for (int i = 0; i < aux -> y && r; i++) {
         for (int j = 0; j < aux -> x && r; j++) {
              if (aux -> tab[i][j].game != jogo -> tab[i][j].game) r = 0;
         }
    }
   
    return r;
}


void minTmai(TAB *jogo, int *r) {
     int i, j, p = 0;
     TAB aux;
    
     aux.x = jogo -> x;
     aux.y = jogo -> y;
 
     aux.tab = malloc(aux.y * sizeof(casa*));
     for (i = 0; i < aux.y; i++) {
          aux.tab[i] = malloc(aux.x * sizeof(casa)); 
     }

     cpyTab(&aux, jogo);

     for (i = 0; i < jogo -> y; i++) {
          for (j = 0; j < jogo -> x; j++) {
               if(aux.tab[i][j].game >= 'a' && aux.tab[i][j].game <= 'z') {
                  aux.tab[i][j].game -= 32;
                  Dicas(&aux);
                  if (verifica(&aux, &p)) { 
                      cpyTab(jogo, &aux);
                  } else {
                      jogo -> tab[i][j].game = '#';
                      Dicas(jogo);
                      cpyTab(&aux, jogo);
                  }
                  *r = 1;
               }   
          }
     }

     limpaT(&aux);
}


void adjacentes(int x, int y, char c, TAB *jogo, int *r) {
     int i, v = 1, p = 0;
     TAB aux;
    
     aux.x = jogo -> x;
     aux.y = jogo -> y;
 
     aux.tab = malloc(aux.y * sizeof(casa*));
     for (i = 0; i < aux.y; i++) {
          aux.tab[i] = malloc(aux.x * sizeof(casa)); 
     }
 
     cpyTab(&aux, jogo);

     if (y + 1 < jogo -> y && v && jogo -> tab[y + 1][x].orig == c) {  
         aux.tab[y + 1][x].game = '#';
         Dicas(&aux);
         if (verifica(&aux, &p) && !tabIguais(&aux, jogo)) 
             cpyTab(jogo, &aux), v = 0, *r = 1;
     }
 
     if (x + 1 < jogo -> x && v && jogo -> tab[y][x + 1].orig == c) {
         aux.tab[y][x + 1].game = '#';
         Dicas(&aux);
         if (verifica(&aux, &p) && !tabIguais(&aux, jogo)) 
             cpyTab(jogo, &aux), v = 0, *r = 1;
     }
 
     if (y - 1 >= 0 && v && jogo -> tab[y - 1][x].orig == c) { 
         aux.tab[y - 1][x].game = '#';
         Dicas(&aux);
         if (verifica(&aux, &p) && !tabIguais(&aux, jogo)) 
             cpyTab(jogo, &aux), v = 0, *r = 1;
     }
 
     if (x - 1 >= 0 && v && jogo -> tab[y][x - 1].orig == c) {
         aux.tab[y][x - 1].game = '#';
         Dicas(&aux);
         if (verifica(&aux, &p) && !tabIguais(&aux, jogo)) 
             cpyTab(jogo, &aux), v = 0, *r = 1;
     }

     limpaT(&aux);
}


void unica(int x, int y, char c, TAB *jogo, int *r) {
     int i, cont = 0; 

     for (i = 1; y + i < jogo -> y; i++) {
          if (jogo -> tab[y + i][x].orig == c) {
              cont ++;
          }
     }

     for (i = 1; y - i >= 0; i++) {
          if (jogo -> tab[y - i][x].orig == c) {
              cont ++;
          }
     }

     for (i = 1; x + i < jogo -> x; i++) {
          if (jogo -> tab[y][x + i].orig == c) {
              cont ++;
          }
     }

     for (i = 1; x - i >= 0; i++) {
          if (jogo -> tab[y][x - i].orig == c) {
              cont ++;
          }
     }
     
     if (cont == 0 && ((jogo -> tab[y][x].game >= 'a' && jogo -> tab[y][x].game <= 'z') || jogo -> tab[y][x].game == '#' )) 
         jogo -> tab[y][x].game = jogo -> tab[y][x].orig - 32, *r = 1; 
}


void percorre(TAB *jogo, int *r) {
     int i, j;  
     char c;

     for (i = 0; i < jogo -> y; i++) {
          for (j = 0; j < jogo -> x; j++) {
               c = jogo -> tab[i][j].orig;
               unica     (j, i, c, jogo, r);
               adjacentes(j, i, c, jogo, r);
          }
     }
}


int resolve(TAB *jogo) {
    int p = 0, r = 0;  

    if (!verifica(jogo, &p)) printf("Tabuleiro atual invalido.\n\n");

    percorre(jogo, &r); 
     
    minTmai(jogo, &r);

    return r;
}
