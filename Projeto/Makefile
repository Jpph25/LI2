# Diretórios
APP_DIR = app
LIB_DIR = lib
TST_DIR = test
EXC_DIR = Exec

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g -I$(LIB_DIR)

# Fontes do programa
APP = $(APP_DIR)/dicas.c     \
      $(APP_DIR)/le_cmds.c   \
      $(APP_DIR)/load_save.c \
      $(APP_DIR)/regras.c    \
      $(APP_DIR)/solve.c     \
      $(APP_DIR)/tabuleiro.c \
      main.c

OBJ = $(patsubst %.c,$(EXC_DIR)/%.o,$(notdir $(APP)))

TEST_OBJ_DEP = $(filter-out $(EXC_DIR)/main.o, $(OBJ))

# Fontes dos testes
TEST_APP = $(TST_DIR)/t_aux.c       \
           $(TST_DIR)/t_dicas.c     \
           $(TST_DIR)/t_le_cmds.c   \
           $(TST_DIR)/t_load_save.c \
           $(TST_DIR)/t_regras.c    \
           $(TST_DIR)/t_solve.c     \
           $(TST_DIR)/t_tabuleiro.c \
           $(TST_DIR)/t_main.c

TEST_OBJ = $(patsubst %.c,$(EXC_DIR)/%.o,$(notdir $(TEST_APP)))

# Biblioteca de testes
TEST_LIBS = -lcunit

# Regra geral para compilar .c → Exec/.o (para código do app/)
$(EXC_DIR)/%.o: $(APP_DIR)/%.c
	            $(CC) $(CFLAGS) -c $< -o $@

# Regra geral para compilar .c → Exec/.o (para testes)
$(EXC_DIR)/%.o: $(TST_DIR)/%.c
	          $(CC)     $(CFLAGS) -c $< -o $@

# Regra geral para main.c (que está fora do app/)
$(EXC_DIR)/%.o: %.c
	          $(CC) $(CFLAGS) -c $< -o $@

# Alvo padrão
all: $(EXC_DIR)/jogo $(EXC_DIR)/teste

# Compila o executável principal
$(EXC_DIR)/jogo: $(OBJ)
	           $(CC) $(CFLAGS) -o $@ $^
jogo: $(EXC_DIR)/jogo

# Compila os testes
$(EXC_DIR)/teste: $(TEST_OBJ_DEP) $(TEST_OBJ)
	            $(CC)           $(CFLAGS)  -o $@ $^ $(TEST_LIBS)
teste: $(EXC_DIR)/teste

# Limpeza de arquivos temporários
clean:
	  rm -f $(OBJ) $(TEST_OBJ)
	  rm -f $(EXC_DIR)/jogo   $(EXC_DIR)/teste

.PHONY: all clean jogo teste
