#include <stdio.h>
#include <string.h>

void multS (char r[], char dig) {
     int d = dig - '0'; 
     int t = strlen (r); 
     int i, j = 0, n, m, resto = 0;
     char aux[2000]; // array que guarda o resultado invertido 

     if (d == 0) strcpy (r, "0"); 
     else {
         for (i = t - 1; i >= 0; i--) {
             n = r[i] - '0';
             m = n * d + resto; 
             aux[j] = (m % 10) + '0'; 
             resto  =  m / 10; 
             j++;  
         } 

         if (resto > 0) aux[j] = '1', j++;
         aux[j] = '\0'; 

         for (i = 0; i < j; i++) {
             r[i] = aux[j - 1 - i]; 
         }
         r[i] = '\0';
     }
}

int main() {
    char r[2000] = "123";  
    char dig = '3';  

    multS(r, dig);  

    printf("Resultado: %s\n", r);  
    
    return 0;
}