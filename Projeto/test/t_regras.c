#include "CUnit/Basic.h"
#include "t_aux.h"

/*
testes do comando v
*/

void t_limpaL(void) {
     CP lista = {NULL, 0, 0};
     push(1, 1, &lista);
     push(2, 2, &lista);

     limpaL(&lista);

     CU_ASSERT_PTR_NULL(lista.brancas);
}


void t_push(void) {
     int x = 1, y = 1;
     CP lista = {NULL, 0, 0};
     push(x, y, &lista);

     x = 0, y = 2;
     push(x, y, &lista);


     CU_ASSERT_EQUAL(lista.brancas[0].x, 1);
     CU_ASSERT_EQUAL(lista.brancas[0].y, 1);
     CU_ASSERT_EQUAL(lista.brancas[1].x, 0);
     CU_ASSERT_EQUAL(lista.brancas[1].y, 2);


     limpaL(&lista);
}


void t_branca(CP *pintadas) {
     CU_ASSERT_EQUAL(pintadas -> brancas[0].x, 1);
     CU_ASSERT_EQUAL(pintadas -> brancas[0].y, 0);

     CU_ASSERT_EQUAL(pintadas -> brancas[1].x, 2);
     CU_ASSERT_EQUAL(pintadas -> brancas[1].y, 0);

     CU_ASSERT_EQUAL(pintadas -> brancas[2].x, 0);
     CU_ASSERT_EQUAL(pintadas -> brancas[2].y, 1);

     CU_ASSERT_EQUAL(pintadas -> brancas[3].x, 2);
     CU_ASSERT_EQUAL(pintadas -> brancas[3].y, 1);
     
     CU_ASSERT_EQUAL(pintadas -> brancas[4].x, 1);
     CU_ASSERT_EQUAL(pintadas -> brancas[4].y, 2);
}


void t_elem(CP *lista) {
     int x = 1, y = 1;
     CU_ASSERT_EQUAL(elem(x, y, lista), 0);

     x = 2, y = 0;
     CU_ASSERT_EQUAL(elem(x, y, lista), 1);
}


void t_hCaminho(TAB *jogo) {
     CP visitadas1 = {NULL, 0, 0};
     CP visitadas2 = {NULL, 0, 0};

     int x = 1, y = 0;
     push(x, y, &visitadas1);
     hCaminho(x, y, jogo, &visitadas1);

     x = 0, y = 1;
     push(x, y, &visitadas2);
     hCaminho(x, y, jogo, &visitadas2);

     
     CU_ASSERT_EQUAL(visitadas1.brancas[0].x, 1);
     CU_ASSERT_EQUAL(visitadas1.brancas[0].y, 0);
     CU_ASSERT_EQUAL(visitadas1.brancas[1].x, 2);
     CU_ASSERT_EQUAL(visitadas1.brancas[1].y, 0);
     CU_ASSERT_EQUAL(visitadas1.brancas[2].x, 2);
     CU_ASSERT_EQUAL(visitadas1.brancas[2].y, 1);

     CU_ASSERT_EQUAL(visitadas2.brancas[0].x, 0);
     CU_ASSERT_EQUAL(visitadas2.brancas[0].y, 1);

     limpaL(&visitadas1);
     limpaL(&visitadas2);
}


void t_elemB(TAB *jogo) {
     CP lista1 = {NULL, 0 ,0};
     CP lista2 = {NULL, 0 ,0};

     push(1, 0, &lista1);
     push(2, 0, &lista1);
     push(2, 1, &lista1);

     push(2, 0, &lista2);
     push(1, 0, &lista2);


     int r = 1, p = 0;
     elemB(&lista2, &lista1, jogo, &r, &p);
     CU_ASSERT_EQUAL(r, 0);

     r = 1;
     push(2, 1, &lista2);
     elemB(&lista2, &lista1, jogo, &r, &p);
     CU_ASSERT_EQUAL(r, 1);


     limpaL(&lista1);
     limpaL(&lista2);
}


void t_caminho(TAB *jogo1, TAB *jogo2) {
     CP vistadas1 = {NULL, 0, 0};
     CP vistadas2 = {NULL, 0, 0};

     CP pintadas1 = {NULL, 0, 0};
     CP pintadas2 = {NULL, 0, 0};

     int r = 1, p = 0;
     caminho(&pintadas1, &vistadas1, jogo1, &r, &p);
     CU_ASSERT_EQUAL(r, 0);

     r = 1;
     caminho(&pintadas2, &vistadas2, jogo2, &r, &p);
     CU_ASSERT_EQUAL(r, 1);

     limpaL(&vistadas1);
     limpaL(&vistadas2);
     limpaL(&pintadas1);
     limpaL(&pintadas2);
}


void t_rRiscadas(void) {
     int i;
     TAB jogo;
     
     jogo.x = 2;
     jogo.y = 2;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));
     
     char tab1[4] = {
          '#', 'b',
          '#', 'd'
     };

     criaTab(&jogo, tab1);

     int r = 1, p = 0;
     rRiscadas(0, 0, &jogo, &r, &p);
     CU_ASSERT_EQUAL(r, 0);

     char tab2[4] = {
          '#', '#',
          'c', 'd'
     };

     criaTab(&jogo, tab2);
     
     r = 1;
     rRiscadas(0, 0, &jogo, &r, &p);
     CU_ASSERT_EQUAL(r, 0); 
     
     char tab3[4] = {
          '#', 'b',
          'C', '#'
     };

     criaTab(&jogo, tab3);

     r = 1;
     rRiscadas(0, 0, &jogo, &r, &p);
     CU_ASSERT_EQUAL(r, 1);

     limpaT(&jogo);
}


void t_rBrancas(void) {
     int i;
     TAB jogo;
     
     jogo.x = 2;
     jogo.y = 2;

     jogo.tab = malloc(jogo.y * sizeof(casa*));
     for (i = 0; i < jogo.y; i++) 
          jogo.tab[i] = malloc(jogo.x * sizeof(casa));
     
     char tab1[4] = {
          'A', 'b',
          'a', 'd'
     };

     criaTab(&jogo, tab1);

     int r = 1, p = 0;
     rBrancas(0, 0, 'A', &jogo, &r, &p);
     CU_ASSERT_EQUAL(r, 1);

     char tab2[4] = {
          'A', 'A',
          'c', 'd'
     };

     criaTab(&jogo, tab2);
     
     r = 1;
     rBrancas(0, 0, 'A', &jogo, &r, &p);
     CU_ASSERT_EQUAL(r, 0); 
     
     char tab3[4] = {
          'A', 'b',
          'A', '#'
     };

     criaTab(&jogo, tab3);

     r = 1;
     rBrancas(0, 0, 'A',&jogo, &r, &p);
     CU_ASSERT_EQUAL(r, 0);

     char tab4[4] = {
          'A', 'b',
          'a', 'A'
     };

     criaTab(&jogo, tab4);

     r = 1;
     rBrancas(0, 0, 'A', &jogo, &r, &p);
     CU_ASSERT_EQUAL(r, 1);

     limpaT(&jogo);
}


void t_verifica(TAB *jogo1, TAB *jogo2) {
     int i;
     TAB jogo3;
     
     jogo3.x = 3;
     jogo3.y = 3;

     jogo3.tab = malloc(jogo3.y * sizeof(casa*));
     for (i = 0; i < jogo3.y; i++) 
          jogo3.tab[i] = malloc(jogo3.x * sizeof(casa));
     
     char tab[9] = {
          'A', 'c', 'C',
          '#', '#', 'C',
          '#', 'f', '#'
     };    

     criaTab(&jogo3, tab);

     int p = 0;

     CU_ASSERT_EQUAL(verifica( jogo1, &p), 0);
     CU_ASSERT_EQUAL(verifica( jogo2, &p), 1);
     CU_ASSERT_EQUAL(verifica(&jogo3, &p), 0);
     
     limpaT(&jogo3);
}


void t_regras(void) {
     int i;
     TAB jogo1;
     
     jogo1.x = 3;
     jogo1.y = 3;

     jogo1.tab = malloc(jogo1.y * sizeof(casa*));
     for (i = 0; i < jogo1.y; i++) 
          jogo1.tab[i] = malloc(jogo1.x * sizeof(casa));
     
     char tab1[9] = {
          '#', 'c', 'C',
          'D', '#', 'c',
          '#', 'f', '#'
     };

     criaTab(&jogo1, tab1);

     TAB jogo2;
     
     jogo2.x = 3;
     jogo2.y = 3;

     jogo2.tab = malloc(jogo2.y * sizeof(casa*));
     for (i = 0; i < jogo2.y; i++) 
          jogo2.tab[i] = malloc(jogo2.x * sizeof(casa));
     
     char tab2[9] = {
          '#', 'C', '#',
          'D', 'e', 'C',
          '#', 'f', '#'
     };

     CP pintadas  = {NULL, 0, 0};

     criaTab(&jogo2, tab2);

     brancas(&pintadas, &jogo1);


     t_limpaL   ();
     t_push     ();
     t_branca   (&pintadas);
     t_elem     (&pintadas);
     t_hCaminho (&jogo1);
     t_elemB    (&jogo1);
     t_caminho  (&jogo1, &jogo2);
     t_rRiscadas();
     t_rBrancas ();
     t_verifica (&jogo1, &jogo2);


     limpaL(&pintadas);
     limpaT(&jogo1);
     limpaT(&jogo2);
}