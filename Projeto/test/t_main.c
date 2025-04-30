#include "CUnit/Basic.h"
#include "tabuleiro.h"


// Testes ´le_cmds.c´
void cmd_s    (TAB *jogo);
void cmd_R    (void);
void cmd_a_A  (void);
void cmd_v    (void); 
void cmd_l_g  (TAB *jogo);
void cmd_b    (TAB *jogo);
void cmd_r    (TAB *jogo);
void cmd_d    (TAB *jogo);
void t_le_cmds(void);

// Testes ´tabuleiro.c´
void t_cSpN          (void);
void t_pBranco       (void);
void t_risca         (void);
void t_guarda_retorna(void);
void t_tabuleiro     (void);

// Testes ´regras.c´
void t_limpaL   (void);
void t_push     (void);
void t_branca   (CP *pintadas);
void t_elem     (CP *lista);
void t_hCaminho (TAB *jogo);
void t_elemB    (TAB *jogo);
void t_caminho  (TAB *jogo1, TAB *jogo2);
void t_rRiscadas(void);
void t_rBrancas (void);
void t_verifica (TAB *jogo1, TAB *jogo2);
void t_regras   (void); 

// Testes ´load_save.c´
void t_limpaT     (void);
void t_limpaS     (TAB *jogo);
void t_le_Jogo_Tab(void);
void t_l_s        (TAB *jogo);
void t_load_save  (void);

// Testes ´dicas.c´
void t_isoladas (void);
void t_dBrancas (void);
void t_dRiscadas(void);
void t_D        (void);
void t_dicas    (void);

// Testes ´solve.c´
void t_unica     (void);
void t_adjacentes(void);
void t_minTmai   (void);
void t_resolve   (void);
void t_solve     (void);


// -- MAIN (Testes) --
int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pSuite = CU_add_suite("jogo_suite", 0, 0);
    if (!pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    
    // Tetes
    CU_add_test(pSuite, "Teste le_cmd"   , t_le_cmds  );
    CU_add_test(pSuite, "Teste tabuleiro", t_tabuleiro);
    CU_add_test(pSuite, "Teste regras"   , t_regras   );
    CU_add_test(pSuite, "Teste load_save", t_load_save);
    CU_add_test(pSuite, "Teste dicas"    , t_dicas    );
    CU_add_test(pSuite, "Teste solve"    , t_solve    );


    CU_basic_set_mode  (CU_BRM_VERBOSE);
    CU_basic_run_tests ();
    CU_cleanup_registry();

    return 0;
}
