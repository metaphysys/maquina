#include <stdio.h>

int main()
{
    /* Números enteros */
    int a;
    unsigned int b;
    signed long c;
    signed long long d = 10000000;
    
    /* Números reales */
    float e;
    double f = 1e23;
    double g = 3.1416;
    float h = 4e-9;
    double i = -78;

    /* Caracteres */
    char j;
    char k = 's';
    unsigned char l = 48;

    // Imprimiendo Integer, Char y Float

    int Integer;
    char Character;
    float InputFloat;
    
    printf(" Please Enter a Character :  ");
    scanf("%c", &Character);
    
    printf(" Please Enter an Integer Value :  ");
    scanf("%d", &Integer);
    
    printf(" Please Enter Float Value :  ");
    scanf("%f", &InputFloat);    
    
    printf(" \n The Integer Value that you Entered is :  %d", Integer);
    printf(" \n The Character that you Entered is :  %c", Character);
    printf(" \n The Float Value that you Entered is :  %f", InputFloat);
    printf(" \n The Float Value with precision 2 is :  %.2f", InputFloat);

    return 0;
}