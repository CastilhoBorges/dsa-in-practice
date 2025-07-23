#include <stdio.h>

int main() {
    // Variavel x é inicializada com valor 25
    int x = 25;
    // Variavel y recebe o endereço onde esta a variavel x
    int* y = &x;
    // Coloca o valor 30 na posição de memoria referenciada
    *y = 30;
}