// -- FICHA C -- 

#include <stdio.h> 
#include <assert.h>
#include <math.h> 

// Compilar : -Wall -Wextra -pedantic -O2 

/* Input 
Recebe o numero (G) de grupos a ler (no maximo 100) 
Para cada grupo recebe um numero (V) de valores que cada grupo têm (no maximo 100)
Lê V valores para cada grupo 
*/

// Novo tipo que guarda o numero de valores de cada grupo e esses valores

typedef struct {
        int nV; 
        int v[100];  
} Grupo; 

typedef struct {
        int   Grp; 
        float OrdRel; 
        int   Val; 
} tabela1;

// Função que lê os valores

void leValores(Grupo *g) {
     assert (scanf ("%d\n", &g -> nV) == 1); 
     
     int i; 
     for (i = 0; i < g -> nV; i++) {
          int aux;
          assert (scanf ("%d\n", &aux) == 1); 
          g -> v[i] = aux; 
     }
}

// Função que conta quantos valores têm ao todo 

int contaVs(Grupo *Gs, int G) {
    int i, nvls = 0; 

    for (i = 0; i < G; i++) {
         nvls += Gs[i].nV;
    }

    return nvls;
}

// Troca dois elemente do array
   
void swap(tabela1 *tb1, int i, int j) {
     tabela1 temp = tb1[j];
     tb1[j] = tb1[i];
     tb1[i] = temp;
}

// Ordena o array da tabela 1 por ordem de valor 

void ordenaVal(tabela1 *tb1, int x) {
     int i, j, m; 
     
     for (i = 0; i < x - 1; i++) {
          m = i; 

          for (j = i + 1; j < x; j++) {
               if ( tb1[j].Val < tb1[m].Val || 
                   (tb1[j].Val == tb1[m].Val && tb1[j].Grp < tb1[m].Grp)) 
                   m = j;
          }

          if (m != i)swap (tb1, i, m); 
     } 
}

// Calcula a media da posições dos lementos com o mesmo valor

void calcMedia(tabela1 *tb1, int c, int f) {
     int   i;
     float m = 0, sum = 0; 
     
     for (i = c; i < f; i++) {
          sum += i + 1; 
     }

     m = sum / (f - c);
     
     for (i = c; i < f; i++) {
          tb1[i].OrdRel = m; 
     }
}

// Calcula a ordem relativa 

void calcOR (tabela1 *tb1, int x) {
     int i, c = 0; 

     for (i = 0; i < x; i++) {

          if (tb1[i].Val != tb1[c].Val) {
              calcMedia (tb1, c, i);
              c = i;
          }
     }

     calcMedia(tb1, c, x);
}

// Desenha a primeira tabela

void Itab1(tabela1 *tb1, int x) {
     printf (" Pos  Ord  Grp     OrdRel  Val  Prm\n");

     int i, c = 0; 
     for (i = 0; i < x; i++) {
          if (tb1[i].Val != tb1[c].Val) c = i; 
          printf("%4d %4d %4d %10.1f %4d %4d\n", i, i + 1, tb1[i].Grp, tb1[i].OrdRel, tb1[i].Val, c);
     }
}

// Clacula os array para a tabela 1 

void tab1(Grupo *Gs, tabela1 *tb1, int x) {
     int i, j = 0, k = 0, nVls = Gs[0].nV; 

     for (i = 0; i < x; i++) {
          if (k >= nVls) j++, nVls = Gs[j].nV, k = 0;

          tb1[i].Grp = j + 1;
          tb1[i].Val = Gs[j].v[k++]; 
     } 

     ordenaVal (tb1, x);
     
     calcOR (tb1, x);
     
     Itab1 (tb1, x);
}

// Calcula a media da OrdRel de um grupo

float mGrp(tabela1 *tb1, int x, int k) {
     int   i, t = 0;
     float sum = 0, m = 0;

     for (i = 0; i < x; i++) {
         if (tb1[i].Grp == k) sum += tb1[i].OrdRel, t++;
     }

     m = sum / t;

     return m; 
}

// Calcula a media total 

float mT (tabela1 *tb1, int x) {
      int   i;
      float sum = 0, m = 0;
    
      for (i = 0; i < x; i++) {
           sum += tb1[i].OrdRel; 
      }

      m = sum / x;

      return m;
}

// Desenha a tabela 2

void Itab2 (tabela1 *tb1, int x, int G) {
     printf ("  Grp MediaOrdem\n");
 
     int i;
     for (i = 0; i < G; i++) {
          printf (" %4d %10.1f\n", i + 1, mGrp(tb1, x, i + 1));
     }

     printf ("Todos %10.1f\n", mT(tb1, x));
}

// Calcula S

float calcS(tabela1 *tb1, int x, Grupo *Gs, int G) {
      int   i;
      float S = 0, s, k, l;

      for (i = 0; i < G; i++) {
          k = mT(tb1, x);
          l = mGrp(tb1, x, i + 1);
          s = Gs[i].nV * (l - k)*(l - k); 
          S += s;
      }

      return S; 
}

// Calcula X 

float calcX(tabela1 *tb1, int x, Grupo *Gs, int G) {
      float S = calcS(tb1, x, Gs, G), X;
      
      X = ((x - 1.0) / x) * (12.0 * S / (x*x - 1.0)); 

      return X; 
} 

// Valor de referência 

double valor_referencia(int num_grupos) {
     double p = 0.95;
     double df = num_grupos - 1;
     double a = (p < 0.5) ?  sqrt(-2.0 * log(p)) : sqrt(-2.0 * log(1.0 - p));
     double poly = 2.515517 + 0.802853 * a + 0.010328 * a * a;
     double q = 1.0 + 1.432788 * a + 0.189269 * a * a + 0.001308 * a * a * a;
     double z = (p < 0.5) ? -(a - poly / q) : (a - poly / q);
     double x = df * pow(1.0 - 2.0 / (9.0 * df) + z * sqrt(2.0 / (9.0 * df)), 3.0);
     return x;
}

// Imprime a teceira tabela

void Itab3 (tabela1 *tb1, int x, Grupo *Gs, int G) {
     float X   = calcX(tb1, x, Gs, G);
     float Ref = valor_referencia (G); 

     printf("Calc: %.2f\n", X);
     printf(" Ref: %.2f\n", Ref); 
     
     if   (X > Ref) printf("Sim\n"); 
     else  printf("Nao\n"); 
}

// -- MAIN -- 

int main() {
    int G; 
    assert (scanf ("%d\n", &G) == 1);  

    int i; 
    Grupo Gs[G]; 
    for (i = 0; i < G; i++) {
         leValores (&Gs[i]);
    }
    
    int x;
    x = contaVs (Gs, G);
    tabela1 tb1[x];  

    tab1 (Gs, tb1, x); 
    
    putchar ('\n'); 

    Itab2(tb1, x, G);

    putchar ('\n');

    Itab3 (tb1, x, Gs, G); 

    return 0;
} 
