#include "dicas.h"

/*
Implementação dos comandos a e A 
*/


void dNisolados(int x, int y, TAB *aux, TAB *jogo, int *r) {
     int v = 1;

     if (y + 1 < aux -> y && aux -> tab[y + 1][x].game != '#' && v) {
         if (jogo -> tab[y + 1][x].game >= 'a' && jogo -> tab[y + 1][x].game <= 'z') {
             jogo -> tab[y + 1][x].game -= 32;
             v = 0;
             *r = 1;
         }
     }

     if (y - 1 >= 0 && aux -> tab[y - 1][x].game != '#' && v) { 
        if (jogo -> tab[y - 1][x].game >= 'a' && jogo -> tab[y - 1][x].game <= 'z') {
            jogo -> tab[y - 1][x].game -= 32;
            v = 0;
            *r = 1;
        }
     }

     if (x + 1 < aux -> x && aux -> tab[y][x + 1].game != '#' && v) {
        if (jogo -> tab[y][x + 1].game >= 'a' && jogo -> tab[y][x + 1].game <= 'z') {
            jogo -> tab[y][x + 1].game -= 32;
            v  = 0;
            *r = 1;
        } 
     }
     
     if (x - 1 >= 0 && aux -> tab[y][x - 1].game != '#' && v) {
        if (jogo -> tab[y][x - 1].game >= 'a' && jogo -> tab[y][x - 1].game <= 'z') {
            jogo -> tab[y][x - 1].game -= 32;
            v  = 0;
            *r = 1;
        } 
     }
}


void vIsoladas(int x, int y, TAB *aux, TAB *jogo, int *r) {
    int c = 0;

    if ((y + 1 >= aux -> y || aux -> tab[y + 1][x].game == '#'))
        c++;

    if ((x + 1 >= aux -> x || aux -> tab[y][x + 1].game == '#'))
        c++;

    if ((y - 1 < 0 || aux -> tab[y - 1][x].game == '#'))
        c++;

    if ((x - 1 < 0 || aux -> tab[y][x - 1].game == '#'))
        c++;

    if (c == 3)
        dNisolados(x, y, aux, jogo, r);
}


int isoladas(TAB *aux, TAB *jogo) {
    int i, j, r = 0;
    
    for (i = 0; i < aux -> y; i++) {
         for (j = 0; j < aux -> x; j++) {
              if (aux -> tab[i][j].game >= 'A' && aux -> tab[i][j].game <= 'Z')
                  vIsoladas(j, i, aux, jogo, &r); 
         }
    }
    
    return r;
}


void dBrancas(int x, int y, char c, TAB *aux, TAB *jogo, int *r) {
     int i;

     for (i = 1; y + i < jogo -> y; i++) {
          if (aux -> tab[y + i][x].game == c) {
              jogo -> tab[y + i][x].game = '#';
              *r = 1;   
          }
     }

     for (i = 1; y - i >= 0; i++) {
          if (aux -> tab[y - i][x].game == c) {
              jogo -> tab[y - i][x].game = '#'; 
              *r = 1; 
          }
     }

     for (i = 1; x + i < jogo -> x; i++) {
          if (aux -> tab[y][x + i].game == c) {
              jogo -> tab[y][x + i].game = '#'; 
              *r = 1;
          }
     }

     for (i = 1; x - i >= 0; i++) {
          if (aux -> tab[y][x - i].game == c) {
              jogo -> tab[y][x - i].game = '#'; 
              *r = 1;
          }
     }
}


void dRiscadas(int x, int y, TAB *aux, TAB *jogo, int *r) {
    if (y + 1 < aux -> y && (aux -> tab[y + 1][x].game < 'A' || aux -> tab[y + 1][x].game > 'Z') &&
        aux -> tab[y + 1][x].game != '#') {  
        if (!(jogo -> tab[y + 1][x].game >= 'A' && jogo -> tab[y + 1][x].game <= 'Z')) {
            jogo -> tab[y + 1][x].game -= 32;
            *r = 1;
        }    
    }

    if (x + 1 < aux -> x && (aux -> tab[y][x + 1].game < 'A' || aux -> tab[y][x + 1].game > 'Z') &&
        aux -> tab[y][x + 1].game != '#') {
        if (!(jogo -> tab[y][x + 1].game >= 'A' && jogo -> tab[y][x + 1].game <= 'Z')) {
            jogo -> tab[y][x + 1].game -= 32;
            *r = 1;
        }
    }

    if (y - 1 >= 0 && (aux -> tab[y - 1][x].game < 'A' || aux -> tab[y - 1][x].game > 'Z') &&
        aux -> tab[y - 1][x].game != '#') { 
        if (!(jogo -> tab[y - 1][x].game >= 'A' && jogo -> tab[y - 1][x].game <= 'Z')) {
            jogo -> tab[y - 1][x].game -= 32;
            *r = 1;
        }    
    }

    if (x - 1 >= 0 && (aux -> tab[y][x - 1].game < 'A' || aux -> tab[y][x - 1].game > 'Z') &&
        aux -> tab[y][x - 1].game != '#') {
        if (!(jogo -> tab[y][x - 1].game >= 'A' && jogo -> tab[y][x - 1].game <= 'Z')) {
            jogo -> tab[y][x - 1].game -= 32;
            *r = 1;
        }    
    } 
}


int dicas(TAB *jogo) {
    int i, j, t, r = 0;
    TAB aux;
    
    aux.x = jogo -> x;
    aux.y = jogo -> y;

    aux.tab = malloc(aux.y * sizeof(casa*));
    for (i = 0; i < aux.y; i++) {
         aux.tab[i] = malloc(aux.x * sizeof(casa)); 
    }

    for(i = 0; i < aux.y; i++) {
        for (j = 0; j < aux.x; j++) {
             aux.tab[i][j].game = jogo -> tab[i][j].game;
        }
    }

    char c;

    for(i = 0; i < aux.y; i++) {
        for (j = 0; j < aux.x; j++) {
             if (aux.tab[i][j].game >= 'A' && aux.tab[i][j].game <= 'Z') {
                 c = aux.tab[i][j].game + 32;  
                 dBrancas(j, i, c, &aux, jogo, &r); 
             }   
             if (aux.tab[i][j].game == '#') {
                 dRiscadas(j, i, &aux, jogo, &r);
             }
        }
    } 

    t = isoladas(&aux, jogo);

    if (t == 1) r = 1;

    limpaT(&aux);

    return r;
}


int Dicas(TAB *jogo) {
    int r, t, end = 1, c = 0;
    
    while (end) {
           t = dicas(jogo);
           end = t;
           c ++;
    }

    if  (c - 1 >= 1) r = 1;
    else r = 0;

    return r;
}
