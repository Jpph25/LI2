#include "CUnit/Basic.h"
#include "t_aux.h"

/*
Testes dos comandos a e A 
*/

void t_isoladas (void) {
     int i;
     TAB jogo;

     jogo.x = 3;
     jogo.y = 3;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));

    TAB aux;

    aux.x = 3;
    aux.y = 3;
     
    aux.tab = malloc(aux.y * sizeof(casa*));
    for (i = 0; i < aux.y; i++) 
         aux.tab[i] = malloc(aux.x * sizeof(casa));

     char tab1[9] = {
          'A', '#', 'c',
          'd', 'e', 'f',
          'g', '#', 'i'
     };

     criaTab(&jogo, tab1);
     cpyTab (&aux , &jogo);

     CU_ASSERT_EQUAL(isoladas(&aux, &jogo), 1);
     CU_ASSERT_EQUAL(jogo.tab[1][0].game, 'D');
     CU_ASSERT_EQUAL(jogo.tab[1][2].game, 'f');
     CU_ASSERT_EQUAL(isoladas(&aux, &jogo), 0);

     char tab2[9] = {
        'a', 'b', 'c',
        '#', 'e', '#',
        'g', '#', 'i'
     };
     
     criaTab(&jogo, tab2);
     cpyTab (&aux , &jogo);

     CU_ASSERT_EQUAL(isoladas(&aux, &jogo), 0);
     jogo.tab[1][1].game = aux.tab[1][1].game = 'E';

     CU_ASSERT_EQUAL(isoladas(&aux, &jogo), 1);
     CU_ASSERT_EQUAL(jogo.tab[0][1].game, 'B');

     jogo.tab[1][0].game = aux.tab[1][0].game = 'd';
     CU_ASSERT_EQUAL(isoladas(&aux, &jogo), 0);

     jogo.tab[1][0].game = aux.tab[1][0].game = '#';
     jogo.tab[1][1].game = aux.tab[1][1].game = '#';
     CU_ASSERT_EQUAL(isoladas(&aux, &jogo), 0);

     limpaT(&aux);
     limpaT(&jogo);
}


void t_dBrancas(void) {
     int i, r = 0;
     TAB jogo;

     jogo.x = 4;
     jogo.y = 4;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));

     TAB aux;

     aux.x = 4;
     aux.y = 4;
    
     aux.tab = malloc(aux.y * sizeof(casa*));
     for (i = 0; i < aux.y; i++) 
          aux.tab[i] = malloc(aux.x * sizeof(casa));

     char tab[16] = {
          'a', 'b', 'c', 'd',
          'b', 'B', 'B', 'b',
          'b', 'j', 'b', 'l',
          'm', 'b', 'o', 'b'
     };
     
     criaTab(&jogo, tab);
     cpyTab (&aux , &jogo);

     dBrancas(1, 1, 'b', &aux, &jogo, &r);
     CU_ASSERT_EQUAL(jogo.tab[0][1].game, '#');
     CU_ASSERT_EQUAL(jogo.tab[1][0].game, '#');
     CU_ASSERT_EQUAL(jogo.tab[1][2].game, 'B');
     CU_ASSERT_EQUAL(jogo.tab[3][1].game, '#');
     CU_ASSERT_EQUAL(jogo.tab[1][3].game, '#');
     CU_ASSERT_EQUAL(r, 1);

     r = 0;
     cpyTab (&aux , &jogo);
     dBrancas(1, 1, 'b', &aux, &jogo, &r);
     CU_ASSERT_EQUAL(r, 0);
     
     limpaT(&aux);
     limpaT(&jogo);
}


void t_dRiscadas(void) {
    int i, r = 0;
    TAB jogo;

    jogo.x = 4;
    jogo.y = 4;

    jogo.tab = malloc(jogo.y * sizeof(casa*));
    for (i = 0; i < jogo.y; i++) 
         jogo.tab[i] = malloc(jogo.x * sizeof(casa));

    TAB aux;

    aux.x = 4;
    aux.y = 4;
   
    aux.tab = malloc(aux.y * sizeof(casa*));
    for (i = 0; i < aux.y; i++) 
         aux.tab[i] = malloc(aux.x * sizeof(casa));

    char tab[16] = {
         'a', 'b', 'c', 'd',
         'e', '#', 'g', 'h',
         'i', 'j', 'k', '#',
         'm', 'n', 'o', '#'
    };
    
    criaTab(&jogo, tab);
    cpyTab (&aux , &jogo);

    dRiscadas(1, 1, &aux, &jogo, &r);
    dRiscadas(3, 3, &aux, &jogo, &r);
    CU_ASSERT_EQUAL(jogo.tab[0][1].game, 'B');
    CU_ASSERT_EQUAL(jogo.tab[1][0].game, 'E');
    CU_ASSERT_EQUAL(jogo.tab[1][2].game, 'G');
    CU_ASSERT_EQUAL(jogo.tab[2][1].game, 'J');

    dRiscadas(3, 2, &aux, &jogo, &r);
    CU_ASSERT_EQUAL(jogo.tab[1][3].game, 'H');
    CU_ASSERT_EQUAL(jogo.tab[2][2].game, 'K');
    CU_ASSERT_EQUAL(jogo.tab[3][3].game, '#');

    dRiscadas(3, 3, &aux, &jogo, &r);
    CU_ASSERT_EQUAL(jogo.tab[3][2].game, 'O');
    CU_ASSERT_EQUAL(jogo.tab[2][3].game, '#');
    CU_ASSERT_EQUAL(r, 1);

    r = 0;
    cpyTab (&aux , &jogo);
    dRiscadas(1, 1, &aux, &jogo, &r);
    CU_ASSERT_EQUAL(r, 0);
    
    limpaT(&aux);
    limpaT(&jogo);
}


void t_D(void) {
     int i;
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

     criaTab(&res, tab2);

     CU_ASSERT_EQUAL(Dicas(&jogo), 1);
     CU_ASSERT_EQUAL(tabIguais(&res, &jogo), 1);

     CU_ASSERT_EQUAL(Dicas(&jogo), 0);

     limpaT(&jogo);
     limpaT(&res);
}


void t_dicas() {
     t_isoladas ();
     t_dBrancas ();
     t_dRiscadas();
     t_D        ();
}