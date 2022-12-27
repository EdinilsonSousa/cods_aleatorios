#include <stdio.h>
#include <stdbool.h>

int main() {
int n;
scanf("%d", &n);
char estradas[n];
for (int i = 0; i < n; i++) {
    scanf(" %c", &estradas[i]);
}

bool possivel = false;
for (int i = 0; i < n - 1; i++) {
    if (estradas[i] == 'T' && estradas[i + 1] == 'A') {
        possivel = true;
        break;
    }
}

if (possivel) {
    printf("SIM\n");
} else {
    printf("NAO\n");
}

return 0;
}

/* 
Entrada
10
A T T A G C C G A T
Saída
SIM

Entrada
10
A T T T G C C G A T
Saída
NAO 

if((B=='0'||B=='1'||B=='2'||B=='3'||B=='4'||B=='5'||B=='6'||B=='7'||B=='8'||B=='9') exemplo
*/     
