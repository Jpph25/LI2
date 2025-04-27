#include "CUnit/Basic.h"
#include "t_aux.h"

/*
Testes dos comandos b <coordenadas>, r <coordenadas> e d 
*/

void t_cSpN(void) {
     CU_ASSERT_EQUAL(cSpN("123", 2), 123);
     CU_ASSERT_EQUAL(cSpN("000", 2), 0  );
     CU_ASSERT_EQUAL(cSpN("9"  , 0), 9  );
}


void t_pBranco(void) {
     TAB jogo;
     jogo.x = 2;
     jogo.y = 2; 

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (int i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));

     char tab[4] = {
          'a', 'b',
          'c', 'd'
     };    

     criaTab(&jogo, tab);

     // Pinta a posição (1,0)        
     pBranco("a1", &jogo);

     // Pinta a posição (4,4) [invalida]
     pBranco("e4", &jogo);


     CU_ASSERT_EQUAL(jogo.tab[0][0].game, 'a');
     CU_ASSERT_EQUAL(jogo.tab[0][1].game, 'b');
     CU_ASSERT_EQUAL(jogo.tab[1][0].game, 'C');
     CU_ASSERT_EQUAL(jogo.tab[1][1].game, 'd');


     limpaT(&jogo);
}


void t_risca(void) {
     TAB jogo;
     jogo.x = 2;
     jogo.y = 2; 

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (int i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));
    
     char tab[4] = {
          'a', 'b',
          'c', 'd'
     };

     criaTab(&jogo, tab);

     // Risca a posição (1,0)
     risca("a1", &jogo);

     // Risca a posição (4,4) [invalida]
     risca("e4", &jogo);
     

     CU_ASSERT_EQUAL(jogo.tab[0][0].game, 'a');
     CU_ASSERT_EQUAL(jogo.tab[0][1].game, 'b');
     CU_ASSERT_EQUAL(jogo.tab[1][0].game, '#');
     CU_ASSERT_EQUAL(jogo.tab[1][1].game, 'd');


     limpaT(&jogo);
}


void t_guarda_retorna(void) {
     TAB jogo;
     jogo.x = 2;
     jogo.y = 2; 

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (int i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));
    
     char tab[4] = {
          'a', 'b', 
          'c', 'd' 
     };

     criaTab(&jogo, tab);
    
     stack passos = {0, 0, NULL};     
    

     //Guarda 1º estado
     guarda(&jogo, &passos);     
     CU_ASSERT_EQUAL(passos.tabs[0].tab[0][0].game, 'a');
     CU_ASSERT_EQUAL(passos.tabs[0].tab[0][1].game, 'b');
     CU_ASSERT_EQUAL(passos.tabs[0].tab[1][0].game, 'c');
     CU_ASSERT_EQUAL(passos.tabs[0].tab[1][1].game, 'd');

     //Guarda 2º estado
     jogo.tab[0][0].game = 'A';
     guarda(&jogo, &passos);
     CU_ASSERT_EQUAL(passos.tabs[0].tab[0][0].game, 'a');
     CU_ASSERT_EQUAL(passos.tabs[1].tab[0][0].game, 'A');

     //Guarda 3º estado
     jogo.tab[1][1].game = '#';
     guarda(&jogo, &passos);
     CU_ASSERT_EQUAL(passos.tabs[0].tab[1][1].game, 'd');
     CU_ASSERT_EQUAL(passos.tabs[1].tab[1][1].game, 'd');
     CU_ASSERT_EQUAL(passos.tabs[2].tab[1][1].game, '#');
    
     //4º estado
     jogo.tab[1][1].game = 'd';

     //Retorna ao 3º estado
     retorna(&jogo, &passos);
     CU_ASSERT_EQUAL(jogo.tab[0][0].game, 'A');
     CU_ASSERT_EQUAL(jogo.tab[1][1].game, '#');

     //Retorna ao 2º estado
     retorna(&jogo, &passos);
     CU_ASSERT_EQUAL(jogo.tab[0][0].game, 'A');
     CU_ASSERT_EQUAL(jogo.tab[1][1].game, 'd');

     //Retorna ao 1º estado
     retorna(&jogo, &passos);
     CU_ASSERT_EQUAL(jogo.tab[0][0].game, 'a');
     CU_ASSERT_EQUAL(jogo.tab[1][1].game, 'd');

    
     limpaT(&jogo);
     limpaS(&passos);
}


void t_tabuleiro(void) {
     t_cSpN          ();
     t_pBranco       ();
     t_risca         ();
     t_guarda_retorna();
}
