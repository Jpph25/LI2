#include "CUnit/Basic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pTab    (int y, int x, char **tab);
int  cSpN    (char *num, int t);
void toCoords(char *arg, int *x, int *y);
void pBranco (char *arg, char **tab, int x, int y);
void risca   (char *arg, char **tab, int x, int y);
void lecmd   (char cmd, char *arg, int *end, char **tab, int x, int y);
void leTab   (int x, int y, char **tab, FILE *file);
void leJogo  (int *x, int *y, char ***tab, FILE *file);

void test_cSpN(void) {
     CU_ASSERT_EQUAL(cSpN("123", 2), 123);
     CU_ASSERT_EQUAL(cSpN("000", 2), 0  );
     CU_ASSERT_EQUAL(cSpN("9"  , 0), 9  );
}


void test_toCoords(void) {
     int x = -1, y = -1;
     toCoords("c12", &x, &y);

     CU_ASSERT_EQUAL(y, 2 );
     CU_ASSERT_EQUAL(x, 12);
}


void test_pBranco(void) {
    int x = 3, y = 3;

    char **tab = malloc(y * sizeof(char*));
    for (int i = 0; i < y; i++) 
         tab[i] = malloc(x * sizeof(char));
    
    for (int i = 0; i < y; i++) 
         for (int j = 0; j < x; j++) 
              tab[i][j] = 'a';

    pBranco("a1", tab, x, y);
    CU_ASSERT_EQUAL(tab[0][1], 'A');

    for (int i = 0; i < y; i++) 
         free(tab[i]);
    free(tab);
}


void test_risca(void) {
    int x = 3, y = 3;

    char **tab = malloc(y * sizeof(char*));
    for (int i = 0; i < y; i++) 
         tab[i] = malloc(x * sizeof(char));

    for (int i = 0; i < y; i++) 
         for (int j = 0; j < x; j++) 
              tab[i][j] = 'a';

    risca("a1", tab, x, y);
    CU_ASSERT_EQUAL(tab[0][1], '#');

    for (int i = 0; i < y; i++) 
         free(tab[i]);
    free(tab);
}


void test_lecmd(void) {
    int x = 3, y = 3, end = 0;
    
    char **tab = malloc(y * sizeof(char*));
    for (int i = 0; i < y; i++) 
         tab[i] = malloc(x * sizeof(char));
    
    for (int i = 0; i < y; i++) 
         for (int j = 0; j < x; j++) 
              tab[i][j] = 'a';

    lecmd('b', "a1", &end, tab, x, y);
    CU_ASSERT_EQUAL(tab[0][1], 'A');

    lecmd('r', "a1", &end, tab, x, y);
    CU_ASSERT_EQUAL(tab[0][1], 'A');

    lecmd('s', "", &end, tab, x, y);
    CU_ASSERT_EQUAL(end, 1);

    for (int i = 0; i < y; i++) 
         free(tab[i]);
    free(tab);
}

int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pSuite = CU_add_suite("jogo_suite", 0, 0);
    if (!pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite, "Teste cSpN"    , test_cSpN    );
    CU_add_test(pSuite, "Teste toCoords", test_toCoords);
    CU_add_test(pSuite, "Teste pBranco" , test_pBranco );
    CU_add_test(pSuite, "Teste risca"   , test_risca   );
    CU_add_test(pSuite, "Teste lecmd"   , test_lecmd   );

    CU_basic_set_mode  (CU_BRM_VERBOSE);
    CU_basic_run_tests ();
    CU_cleanup_registry();

    return 0;
}