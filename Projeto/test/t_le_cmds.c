#include "CUnit/Basic.h"
#include "t_aux.h"

/*
Implementação da funão que lê os comandos dados
l jogo, g jogo, b <coordenadas>, r <coordenadas>, d, s, v, a, A e R
  <coordenadas> - <letra minúscula><número>
  jogo - nome do ficheiro a dar `load` e `save`
*/

void t_rGuardar(void){
     int i;
     TAB jogo1;
     
     jogo1.x = 2;
     jogo1.y = 2;

     jogo1.tab = malloc(jogo1.y * sizeof(casa*));
     for (i = 0; i < jogo1.y; i++) 
          jogo1.tab[i] = malloc(jogo1.x * sizeof(casa));
  
     char tab1[4] = {
          'a', 'a',
          'a', 'a'
     };

     criaTab(&jogo1, tab1);

     TAB jogo2;
     
     jogo2.x = 2;
     jogo2.y = 2;

     jogo2.tab = malloc(jogo2.y * sizeof(casa*));
     for (i = 0; i < jogo2.y; i++) 
          jogo2.tab[i] = malloc(jogo2.x * sizeof(casa));
  
     char tab2[4] = {
          'b', 'b',
          'b', 'b'
     };

     criaTab(&jogo2, tab2);

     stack passos = {0, 0, NULL};

     guarda(&jogo1, &passos);
     guarda(&jogo2, &passos);

     CU_ASSERT_EQUAL(tabIguais(&jogo1, &passos.tabs[0]), 1);
     CU_ASSERT_EQUAL(tabIguais(&jogo2, &passos.tabs[1]), 1);

     rGuardar(&passos);
     CU_ASSERT_EQUAL(tabIguais(&jogo1, &passos.tabs[0]), 1);
     CU_ASSERT_EQUAL(passos.sp, 1);

     rGuardar(&passos);
     CU_ASSERT_PTR_NULL(passos.tabs);
}


void cmd_s(TAB *jogo) {
     int end = 1, l = 1;
     stack passos = {0, 0, NULL};

     lecmd('s', "", &end, &l, jogo, &passos);

     CU_ASSERT_EQUAL(end, 0);

     limpaS(&passos);
}


void cmd_R(void) {
     int i, end = 1, l = 0;
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

     criaTab(&res, tab1);

     stack passos = {0, 0, NULL};

     lecmd('R', "", &end, &l, &jogo, &passos);
     CU_ASSERT_PTR_NULL(passos.tabs);
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);

     criaTab(&res, tab2);
     l = 1;

     lecmd('R', "", &end, &l, &jogo, &passos);
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);
     criaTab(&res, tab1);
     CU_ASSERT_EQUAL(tabIguais(&res, &passos.tabs[0]), 1);


     limpaT(&jogo);
     limpaT(&res);
     limpaS(&passos);
}


void cmd_a_A(void) {
     int i, end = 1, l = 0;
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
          'E', '#', 'A', 'D', 'C',
          'D', 'C', '#', 'E', '#',
          'B', '#', 'D', 'C', 'E',
          'C', 'D', 'E', '#', 'B',
          'A', '#', 'C', 'B', '#'
     };

     criaTab(&res, tab1);

     stack passos = {0, 0, NULL};

     lecmd('a', "", &end, &l, &jogo, &passos);
     CU_ASSERT_PTR_NULL(passos.tabs);
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);

     lecmd('A', "", &end, &l, &jogo, &passos);
     CU_ASSERT_PTR_NULL(passos.tabs);
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);

     l = 1;


     lecmd('a', "", &end, &l, &jogo, &passos);
     CU_ASSERT_EQUAL(jogo.tab[0][1].game, '#');
     CU_ASSERT_EQUAL(jogo.tab[1][4].game, '#');
     CU_ASSERT_EQUAL(jogo.tab[4][1].game, '#');
     CU_ASSERT_EQUAL(tabIguais(&res, &passos.tabs[0]), 1);

     criaTab(&res, tab2);

     lecmd('A', "", &end, &l, &jogo, &passos);
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);
     CU_ASSERT_EQUAL(passos.tabs[1].tab[0][1].game, '#');
     CU_ASSERT_EQUAL(passos.tabs[1].tab[1][4].game, '#');
     CU_ASSERT_EQUAL(passos.tabs[1].tab[4][1].game, '#');


     limpaT(&jogo);
     limpaT(&res);
     limpaS(&passos);
}


void cmd_v() {}


void cmd_l_g(TAB *jogo) {
     int end = 1, l = 1;

     stack passos = {0, 0, NULL};
     guarda(jogo, &passos);

     jogo -> tab[0][0].game = 'A';

     lecmd('g', "teste", &end, &l, jogo, &passos);

     FILE *f = fopen("Inputs/teste", "r");
     CU_ASSERT_PTR_NOT_NULL(f);
     if (f != NULL) fclose(f);


     TAB jogot;
     jogot.tab = NULL;

     stack passost = {0, 0, NULL}; 

     lecmd('l', "NULL", &end, &l, &jogot, &passost);

     CU_ASSERT_PTR_NULL(jogot.tab);
     CU_ASSERT_PTR_NULL(passost.tabs);

     lecmd('l', "teste", &end, &l, &jogot, &passost);

     CU_ASSERT_EQUAL(tabIguais(&jogot, jogo), 1);
     CU_ASSERT_EQUAL(tabIguais(&passos.tabs[0], &passost.tabs[0]), 1);


     limpaS(&passos);
     limpaS(&passost);
     limpaT(&jogot);

     remove("Inputs/teste");
}


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
     
     cmd_s  (&jogo);
     cmd_R  ();
     cmd_a_A();
     cmd_v  ();
     cmd_l_g(&jogo);
     cmd_b  (&jogo);
     cmd_r  (&jogo);
     cmd_d  (&jogo);

     limpaT(&jogo);
}
