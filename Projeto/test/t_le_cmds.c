#include "CUnit/Basic.h"
#include "t_aux.h"

/*
Implementação da funão que lê os comandos dados
l jogo, g jogo, b <coordenadas>, r <coordenadas>, d, s, v, a, A e R
  <coordenadas> - <letra minúscula><número>
  jogo - nome do ficheiro a dar `load` e `save`
*/

void cmd_d(TAB *jogo) {
  int i, end = 1, l = 1;
  stack passos = {0, 0, NULL};

  TAB aux;

  aux.x = 3;
  aux.y = 3;

  aux.tab = malloc(aux.y * sizeof(casa*));
  for (i = 0; i < aux.y; i++) 
       aux.tab[i] = malloc(aux.x * sizeof(casa));

  cpyTab(&aux, jogo);


  lecmd('r', "b1", &end, &l, jogo, &passos);
  lecmd('r', "e4", &end, &l, jogo, &passos);
  

  lecmd('d', "", &end, &l, jogo, &passos);
  CU_ASSERT_EQUAL(jogo -> tab[1][1].game, 'e');


  lecmd('d', "", &end, &l, jogo, &passos);
  CU_ASSERT_EQUAL(tabIguais(&aux, jogo), 1);


  lecmd('b', "b1", &end, &l, jogo, &passos);
  lecmd('b', "c2", &end, &l, jogo, &passos);


  lecmd('d', "", &end, &l, jogo, &passos);
  CU_ASSERT_EQUAL(jogo -> tab[2][2].game, '#');
  CU_ASSERT_EQUAL(jogo -> tab[1][1].game, 'E');


  lecmd('d', "", &end, &l, jogo, &passos);
  CU_ASSERT_EQUAL(jogo -> tab[1][1].game, 'e');


  l = 0;
  lecmd('d', "", &end, &l, jogo, &passos);
  CU_ASSERT_EQUAL(tabIguais(&aux, jogo), 1);


  limpaS(&passos);
  limpaT(&aux);
}


void cmd_r(TAB *jogo) {
  int i, end = 1, l = 1;
  stack passos = {0, 0, NULL};

  TAB aux;

  aux.x = 3;
  aux.y = 3;

  aux.tab = malloc(aux.y * sizeof(casa*));
  for (i = 0; i < aux.y; i++) 
       aux.tab[i] = malloc(aux.x * sizeof(casa));

  cpyTab(&aux, jogo);


  lecmd('r', "c2", &end, &l, jogo, &passos);
  CU_ASSERT_EQUAL(jogo -> tab[2][2].game, '#');
  CU_ASSERT_EQUAL(jogo -> tab[2][2].orig, 'g');
  CU_ASSERT_EQUAL(tabIguais(&passos.tabs[0], &aux), 1);


  TAB ant;

  ant.x = 3;
  ant.y = 3;

  ant.tab = malloc(ant.y * sizeof(casa*));
  for (i = 0; i < ant.y; i++) 
       ant.tab[i] = malloc(ant.x * sizeof(casa));

  cpyTab(&ant, jogo);


  lecmd('r', "e4", &end, &l, jogo, &passos);
  CU_ASSERT_EQUAL(tabIguais(&ant, jogo), 1);
  CU_ASSERT_EQUAL(tabIguais(&passos.tabs[0], &aux), 1);


  cpyTab(&ant, jogo);

  lecmd('r', "c2", &end, &l, jogo, &passos);
  CU_ASSERT_EQUAL(tabIguais(&ant, jogo), 1);
  CU_ASSERT_EQUAL(tabIguais(&passos.tabs[0], &aux), 1);


  cpyTab(&ant, jogo);

  l = 0;
  lecmd('r', "c2", &end, &l, jogo, &passos);
  CU_ASSERT_EQUAL(tabIguais(&ant, jogo), 1);


  limpaS(&passos);
  limpaT(&ant);
  limpaT(&aux);
}


void cmd_b(TAB *jogo) {
     int i, end = 1, l = 1;
     stack passos = {0, 0, NULL};

     TAB aux;

     aux.x = 3;
     aux.y = 3;

     aux.tab = malloc(aux.y * sizeof(casa*));
     for (i = 0; i < aux.y; i++) 
          aux.tab[i] = malloc(aux.x * sizeof(casa));

     cpyTab(&aux, jogo);


     lecmd('b', "a0", &end, &l, jogo, &passos);
     CU_ASSERT_EQUAL(jogo -> tab[0][0].game, 'A');
     CU_ASSERT_EQUAL(jogo -> tab[0][0].orig, 'a');
     CU_ASSERT_EQUAL(tabIguais(&passos.tabs[0], &aux), 1);


     TAB ant;

     ant.x = 3;
     ant.y = 3;

     ant.tab = malloc(ant.y * sizeof(casa*));
     for (i = 0; i < ant.y; i++) 
          ant.tab[i] = malloc(ant.x * sizeof(casa));

     cpyTab(&ant, jogo);


     lecmd('b', "e4", &end, &l, jogo, &passos);
     CU_ASSERT_EQUAL(tabIguais(&ant, jogo), 1);
     CU_ASSERT_EQUAL(tabIguais(&passos.tabs[0], &aux), 1);


     cpyTab(&ant, jogo);

     lecmd('b', "a0", &end, &l, jogo, &passos);
     CU_ASSERT_EQUAL(tabIguais(&ant, jogo), 1);
     CU_ASSERT_EQUAL(tabIguais(&passos.tabs[0], &aux), 1);


     cpyTab(&ant, jogo);

     l = 0;
     lecmd('b', "a1", &end, &l, jogo, &passos);
     CU_ASSERT_EQUAL(tabIguais(&ant, jogo), 1);


     limpaS(&passos);
     limpaT(&ant);
     limpaT(&aux);
}


void t_le_cmds() {
     int i;
     TAB jogo;
     
     jogo.x = 3;
     jogo.y = 3;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));
  
     char tab[9] = {
          'a', 'c', 'c',
          'd', 'e', 'c',
          'a', 'f', 'g'
     };

     criaTab(&jogo, tab);


     cmd_b(&jogo);
     cmd_r(&jogo);
     cmd_d(&jogo);


     limpaT(&jogo);
}