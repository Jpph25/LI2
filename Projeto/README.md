# Laboratórios de Informática II

Projeto desenvolvido para a disciplina de Laboratórios de Informática II. O sistema implementa um jogo simples em linguagem C, com organização modular e testes unitários utilizando a biblioteca CUnit.

## Autores

Carolina Amorim Neiva    <a111537@alunos.uminho.pt>
Gonçalo Gomes Gonçalves  <a108313@alunos.uminho.pt>
João Pedro Pimenta Gomes <a110587@alunos.uminho.pt>

## Jogo

### Compilador

Para compilar o programa use o comando:

```bash
make jogo 
```

### Executar

Após compilar pode executar o programa através dos comando:

```bash
./jogo
```

## Testes 

O projeto utiliza a biblioteca [CUnit](https://cunit.sourceforge.net/) para fazer testes unitarios.

### Compilar 

Para compilar os testes use o comando:

```bash
make teste
```

### Executar

Execute os testes usando o comando: 

```bash
./teste 
```

Os testes são executados no terminal, com relatórios indicando os testes bem-sucedidos e eventuais falhas.

## Limpeza 

Para limpra todos os arquivos temporarios e executaveis use o comado: 

```bash
make clean
```

## Estrutura do Projeto

```
.
├── app/            # Código-fonte do jogo (.c)
├── Exec/           # Executaveis compilados
├── gCov/           # Relatorios do gcov
├── Inputs/         # Inputs para dar load 
├── lib/            # Arquivos de cabeçalho (.h)
├── test/           # Arquivos de teste com CUnit
├── main.c          # Função principal do programa
├── Makefile        # Regras de compilação
└── README.md       # Documentação do projeto
```

---

## Requisitos

Certifique-se de ter os seguintes pacotes instalados no seu sistema:

- GCC (compilador)
- Make
- CUnit (para testes)

### Instalação da CUnit em sistemas Debian/Ubuntu:

```bash
sudo apt-get install libcunit1-dev
```

---