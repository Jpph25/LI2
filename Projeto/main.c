#include "le_cmds.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// -- MAIN -- 

int main() {
    int end = 1; 
    
    TAB jogo;
    jogo.tab = NULL; 

    while(end) {
          int  n, l = 1; 
          char input[100]; 
          char cmd, arg[50];
 
          putchar('\n');
          printf("Comando: ");

          if (fgets(input, sizeof(input), stdin) != NULL) {
            n = sscanf(input, " %c %s", &cmd, arg);

            if (n == 1 && cmd == 's') {
                lecmd(cmd, "", &end, &l, &jogo);
            } else {

                if (n == 2 && (cmd == 'l')) {
                    lecmd(cmd, arg, &end, &l, &jogo);
                } else {
                    printf("Comando invalido\n");
                }
            }
          }  
    }

    for (int i = 0; i < jogo.y; i++) {
        free(jogo.tab[i]);
    }
    free(jogo.tab);

    return 0; 
}
