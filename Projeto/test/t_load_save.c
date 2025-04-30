#include "CUnit/Basic.h"
#include "t_aux.h"

/*
Teste dos comandos l jogo e g jogo
*/

void t_limpaT(void) {
     int i;
     TAB jogo;

     jogo.x = 2;
     jogo.y = 2;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));
    
     char tab[4] = {
          'a', 'b',
          'c', 'd'
     };

     criaTab(&jogo, tab);

     limpaT(&jogo);

     CU_ASSERT_PTR_NULL(jogo.tab);
}


void t_limpaS(TAB *jogo) {
     stack passos = {0, 0, NULL};
     guarda(jogo, &passos);

     limpaS(&passos);

     CU_ASSERT_PTR_NULL(passos.tabs);     
}


void t_le_Jogo_Tab(void) {
     FILE *file = fopen("test_input.txt", "w");
     fprintf(file, "2 2\n");
     fprintf(file, "ab\n cd\n");  
     fclose (file);

     file = fopen("test_input.txt", "r");
     TAB jogo = {0};

     leJogo(&jogo, file);

     CU_ASSERT_EQUAL(jogo.x, 2);
     CU_ASSERT_EQUAL(jogo.y, 2);

     CU_ASSERT_EQUAL(jogo.tab[0][0].orig, 'a');
     CU_ASSERT_EQUAL(jogo.tab[0][1].orig, 'b');
     CU_ASSERT_EQUAL(jogo.tab[1][0].orig, 'c');
     CU_ASSERT_EQUAL(jogo.tab[1][1].orig, 'd');
     
     CU_ASSERT_EQUAL(jogo.tab[0][0].game, 'a');
     CU_ASSERT_EQUAL(jogo.tab[0][1].game, 'b');
     CU_ASSERT_EQUAL(jogo.tab[1][0].game, 'c');
     CU_ASSERT_EQUAL(jogo.tab[1][1].game, 'd');

     limpaT(&jogo);
     fclose(file);
     remove("test_input.txt");
}


void t_l_s(TAB *jogo) {
     stack passos = {0, 0, NULL};
     guarda(jogo, &passos);

     jogo -> tab[0][0].game = 'A';

     save("teste", jogo, &passos);


     FILE *f = fopen("Inputs/teste", "r");
     CU_ASSERT_PTR_NOT_NULL(f);
     if (f != NULL) fclose(f);


     TAB jogot;
     jogot.tab = NULL;

     stack passost = {0, 0, NULL}; 

     load("NULL", &jogot, &passost);

     CU_ASSERT_PTR_NULL(jogot.tab);
     CU_ASSERT_PTR_NULL(passost.tabs);

     load("teste", &jogot, &passost);

     CU_ASSERT_EQUAL(tabIguais(&jogot, jogo), 1);
     CU_ASSERT_EQUAL(tabIguais(&passos.tabs[0], &passost.tabs[0]), 1);


     limpaS(&passos);
     limpaS(&passost);
     limpaT(&jogot);

     remove("Inputs/teste");
}


void t_load_save(void) {
     int i;
     TAB jogo;

     jogo.x = 2;
     jogo.y = 2;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));
   
     char tab[4] = {
          'a', 'b',
          'c', 'd'
     };

     criaTab(&jogo, tab);


     t_limpaT     ();
     t_limpaS     (&jogo);
     t_le_Jogo_Tab();
     t_l_s        (&jogo);


     limpaT(&jogo);
}
