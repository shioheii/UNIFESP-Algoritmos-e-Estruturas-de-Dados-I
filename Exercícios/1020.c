#include <stdio.h>
 
int main() {
 
    int dias = 0;
    scanf("%d", &dias);
    
    int anos = dias / 365;
    int dias_restantes = dias - anos * 365 ;
    int meses = dias_restantes / 30;
    int dias_final = dias_restantes - meses * 30;

    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias_final);
    
    return 0;
}
