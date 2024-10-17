#include <stdio.h>
 
int main() {
 
    double pi = 3.14159;
    double raio = 0.0;
    
    scanf("%lf", &raio);
    double res = pi * raio * raio;
    
    printf("A=%.4lf\n", res);
 
    return 0;
}
