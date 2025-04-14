// -- JOGO -- 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> 

// Compilar: -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g 

/* 1ª parte
Ler o jogo
Pintar ou riscar uma dada casa 
*/

// Imprime o tabuleiro
void pTab(int y, int x, char **tab) {
    int i, j;

    putchar('\n');
    for (i = 0; i < y; i++) {
       
         for (j = 0; j < x; j++) {
              printf ("%c ", tab[i][j]); 
         }
         putchar('\n');
    }
}

// Transforma um numero guardado em uma string em um inteiro
int cSpN(char *num, int t) { 
    int r = 0, aux, i = 0, j; 

    while (num[i] != '\0') {  
           aux = num[i] - '0';  
           
           for (j = t; j > 0; j--)  
                aux *= 10;
           
           r += aux;
           i++, t--;   
   }  

   return r; 
}

// Tranformas os agrumentos em coordenadas 
void toCoords(char *arg, int *y, int *x) {
     int  i = 0;
     char num[100] = "";

     while (arg[i] != '\0' && *x == -1) {
            if (arg[i] != ' ') {
                *x = arg[i] - 'a';
            }
            i++;
     }
    
     int j = 0;
     while (arg[i] != '\0' && arg[i] != ' ') {
            num[j++] = arg[i++];       
     }
     num[j] = '\0';

     *y = cSpN(num, j - 1);  
}

// Pinta uma dada coordenada de branco
void pBranco(char *cmd, char **tab, int x, int y) {
     int x1 = - 1, y1 = -1; 
     toCoords (cmd, &x1, &y1); 

     if (x1 < 0 || x1 > x || y1 < 0 || y1 > y) {
         printf("Coordenadas invalidas\n");
     } else { 
         if (tab[y1][x1] >= 'A' && tab[y1][x1] <= 'Z') {
             printf("Coordenada já pintada");
         } else {
             if (tab[y1][x1] == '#') {
                 printf("Coordenada riscada");
             } else {
                 tab[y1][x1] -= 32; 
             }
         }     
     }          
     pTab(y, x, tab);
}

// Risca uma dada coordenada
void risca(char *cmd, char **tab, int x, int y) {
    int x1 = - 1, y1 = -1; 
    toCoords (cmd, &x1, &y1); 

    if (x1 < 0 || x1 > x || y1 < 0 || y1 > y) {
        printf("Coordenadas invalidas\n");
    } else { 
        if (tab[y1][x1] >= 'A' && tab[y1][x1] <= 'Z') {
            printf("Coordenada pintada");
        } else {
            if (tab[y1][x1] == '#') {
                printf("Coordenada já riscada");
            } else {
                tab[y1][x1] = '#'; 
            }
        }     
    }          
    pTab(y, x, tab);       
}

// Lê os comandos inseridos 
void lecmd(char *cmd, int *end, char **tab, int x, int y) {
    int i, fim = 0; 
    
    for (i = 0; cmd[i] != '\0' && fim == 0; i++) {
         if (cmd[i] != ' ') {
             if (cmd[i] == 'b') pBranco(cmd + 1, tab, x, y), fim = 1;
             if (cmd[i] == 'r') risca  (cmd + 1, tab, x, y), fim = 1; 
             if (cmd[i] == 's') *end = 1;
             if (cmd[i] != 'b' && cmd[i] != 'r' && cmd[i] != 's') 
                 printf("Carolina\n"), fim = 1;   
         } 
    }
}

// Lê o tabuleiro de um ficheiro 
void leTab(int x, int y, char **tab, FILE *file) {
    int  i, j;
    char aux;

    for (i = 0; i < y; i++) {
         for (j = 0; j < x; j++) {
              assert(fscanf(file, " %c", &aux) == 1);
              tab[i][j] = aux; 
         }
    } 
} 

// Liberta o tabuleiro e aloca espaço para o novo tabuleiro
void leJogo(int *x, int *y, char ***tab, FILE *file) {
     int i; 
     
     if (*tab != NULL) {
         for(i = 0; i < *y; i++) {
             free(tab[i]);
         }
         free(tab);
     } 

     assert(fscanf(file, "%d %d", y, x) == 2); 
     
     *tab = malloc(*y * sizeof(char*));
     for(i = 0; i < *y; i++) {
         (*tab)[i] = malloc(*x * sizeof(char)); 
     }

     leTab(*x, *y, *tab, file); 
}

// -- MAIN --
int main() {
    FILE *file = fopen("Inputs/I1", "r"); 
    assert(file != NULL); 

    int x, y; 
    char **tab = NULL;  
    leJogo(&x, &y, &tab, file); 
    
    fclose(file);

    pTab(y, x, tab);  

    int end = 0; 
    while (end == 0) {
           char cmd[50] = "";

           putchar ('\n');
           printf ("Comando: "); 
           assert(scanf("%s", cmd) == 1); 

           lecmd(cmd, &end, tab, x, y);       
    }

    for (int i = 0; i < y; i++) {
        free(tab[i]);
    }
    free(tab); 

    return 0; 
} 