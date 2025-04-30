#include "CUnit/Basic.h"
#include "t_aux.h"

/*
testes do comando R
*/

void t_unica(void) {
     int i, j, r = 0;
     TAB jogo;

     jogo.x = 5;
     jogo.y = 5;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));

     char tab1[25] = {
          'e', 'c', 'a', 'd', 'c',
          'd', 'C', 'd', 'e', 'c',
          'b', 'd', 'd', 'c', 'e',
          'c', 'd', 'e', 'e', 'b',
          'a', 'c', 'c', 'b', 'b'
     };
   
     criaTab(&jogo, tab1);

     TAB res;

     res.x = 5;
     res.y = 5;
   
     res.tab = malloc(res.y * sizeof(casa*));
     for (i = 0; i < res.y; i++) 
          res.tab[i] = malloc(res.x * sizeof(casa));
     
     char tab2[25] = {
          'E', 'c', 'A', 'D', 'c',
          'd', 'C', 'd', 'e', 'c',
          'B', 'd', 'd', 'C', 'E',
          'C', 'd', 'e', 'e', 'b',
          'A', 'c', 'c', 'b', 'b'
     };

     criaTab(&res, tab2);

     for(i = 0; i < jogo.y; i++) {
         for(j = 0; j < jogo.x; j++) {
             unica(j, i, jogo.tab[i][j].orig, &jogo, &r);
         }
     }
     
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);

     limpaT(&jogo);
     limpaT(&res);
}


void t_adjacentes(void) {
     int i, r = 0;
     TAB jogo;

     jogo.x = 5;
     jogo.y = 5;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));

     char tab1[25] = {
          'e', 'c', 'a', 'd', 'c',
          'd', 'c', 'd', 'e', 'c',
          'b', 'd', 'd', 'c', 'e',
          'c', 'd', 'e', 'e', 'b',
          'a', 'c', 'c', 'b', 'b'
     };
   
     criaTab(&jogo, tab1);

     TAB res;

     res.x = 5;
     res.y = 5;
   
     res.tab = malloc(res.y * sizeof(casa*));
     for (i = 0; i < res.y; i++) 
          res.tab[i] = malloc(res.x * sizeof(casa));

     cpyTab(&res, &jogo);

     adjacentes(0, 1, 'c', &jogo, &r);
     CU_ASSERT_EQUAL(r, 0);


     char tab2[25] = {
          'E', '#', 'A', 'D', 'C',
          'D', 'C', '#', 'E', '#',
          'B', '#', 'D', 'C', 'E',
          'C', 'D', 'E', '#', 'B',
          'A', '#', 'C', 'B', '#'
     };

     criaTab(&res, tab2);

     adjacentes(1, 1, 'c', &jogo, &r);
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);
     CU_ASSERT_EQUAL(r, 1);

     limpaT(&jogo);
     limpaT(&res);
}


void t_minTmai(void) {
     int i, r = 0;
     TAB jogo;

     jogo.x = 5;
     jogo.y = 5;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));

     char tab1[25] = {
          'e', 'c', 'a', 'd', 'c',
          'd', 'c', 'd', 'e', 'c',
          'b', 'd', 'd', 'c', 'e',
          'c', 'd', 'e', 'e', 'b',
          'a', 'c', 'c', 'b', 'b'
     };
   
     criaTab(&jogo, tab1);

     TAB res;

     res.x = 5;
     res.y = 5;
   
     res.tab = malloc(res.y * sizeof(casa*));
     for (i = 0; i < res.y; i++) 
          res.tab[i] = malloc(res.x * sizeof(casa));

     char tab2[25] = {
          'E', '#', 'A', 'D', 'C',
          'D', 'C', '#', 'E', '#',
          'B', '#', 'D', 'C', 'E',
          'C', 'D', 'E', '#', 'B',
          'A', '#', 'C', 'B', '#'
     };

     criaTab(&res, tab2);

     minTmai(&jogo, &r);
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);
     CU_ASSERT_EQUAL(r, 1);

     r = 0;
     minTmai(&jogo, &r);
     CU_ASSERT_EQUAL(r, 0);

     limpaT(&jogo);
     limpaT(&res);
}


void t_resolve(void) {
     int i;
     TAB jogo;

     jogo.x = 5;
     jogo.y = 5;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));

     char tab1[25] = {
          'e', 'c', 'a', 'd', 'c',
          'd', 'c', 'd', 'e', 'c',
          'b', 'd', 'd', 'c', 'e',
          'c', 'd', 'e', 'e', 'b',
          'a', 'c', 'c', 'b', 'b'
     };
   
     criaTab(&jogo, tab1);

     TAB res;

     res.x = 5;
     res.y = 5;
   
     res.tab = malloc(res.y * sizeof(casa*));
     for (i = 0; i < res.y; i++) 
          res.tab[i] = malloc(res.x * sizeof(casa));

     char tab2[25] = {
          'E', '#', 'A', 'D', 'C',
          'D', 'C', '#', 'E', '#',
          'B', '#', 'D', 'C', 'E',
          'C', 'D', 'E', '#', 'B',
          'A', '#', 'C', 'B', '#'
     };

     criaTab(&res, tab2);

     CU_ASSERT_EQUAL(resolve(&jogo), 1);
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);

     CU_ASSERT_EQUAL(resolve(&jogo), 0);

     limpaT(&jogo);
     limpaT(&res);
}


void t_solve() {
     t_unica     ();
     t_adjacentes();
     t_minTmai   ();
     t_resolve   ();
}