#include "le_cmds.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// -- MAIN -- 

int main() {
    int end = 1, l = 0; 
    // O end termina o ciclo quando o comeando s é usado    
    // O l indica se o tabuleiro está inciado 

    TAB jogo;
    jogo.tab = NULL; 

    stack passos; 
    passos.cap  = 0; 
    passos.sp   = 0; 
    passos.tabs = NULL;

    while(end) {
          int  n; 
          char input[100]; 
          char cmd, arg[50];

          printf("Comando: ");

          if (fgets(input, sizeof(input), stdin) != NULL) {
            n = sscanf(input, " %c %s", &cmd, arg);

            if (n == 1 && (cmd == 's' || cmd == 'd' || cmd == 'a' || cmd == 'A' || cmd == 'v' || cmd == 'R')) {
                lecmd(cmd, "", &end, &l, &jogo, &passos, 1);
            } else {

                if (n == 2 && (cmd == 'l' || cmd == 'g' || cmd == 'b' || cmd == 'r') ) {
                    lecmd(cmd, arg, &end, &l, &jogo, &passos, 1);
                } else {
                    printf("Comando inválido\n\n");
                }
            }
          }  
    }
    
    if (l) limpaT(&jogo);

    if (passos.tabs != NULL) limpaS(&passos);

    return 0; 
}
