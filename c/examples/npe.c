#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* bar(int i)
{
    char s[100] = {};
    char *str;

    int e;
    for (e = 0; e < 100; e++) 
    {
        strcat(str, "#");
    }

    return str;
}

int calc( int alfa, int omega, int x )
{
    if (x < alfa) 
    {
        return 0;
    } 
    else if (x > omega) 
    {
        return 999;
    }
    else 
    {
        int p,y; 
        y = omega - alfa;
        p = x / y * 100; 
        return p;
    }
}

int main( int argc, char *argv[] )
{

    int a,b,c,d;
    
    /* 
        TODO: Mejora en eficiencia de obtención de los datos a,b,c,d
    */
    FILE *fpa = popen("npe ?AI1", "r");
    fscanf(fpa, "%d", &a);
    pclose(fpa);
        
    FILE *fpb = popen("npe ?AI2", "r");
    fscanf(fpb, "%d", &b);
    pclose(fpb);
        
    FILE *fpc = popen("npe ?AI3", "r");
    fscanf(fpc, "%d", &c);
    pclose(fpc);
        
    FILE *fpd = popen("npe ?AI4", "r");
    fscanf(fpd, "%d", &d);
    pclose(fpd);

    printf("Cél calibrada:\t %d \t %d \t %s \n", a, calc(380, 1700, a), bar(80));
    printf("Anenómetro:\t %d \t %d \t %s \n", b, calc(380, 1700, b), bar(12));
    printf("Célula temp:\t %d \t %d \t %s \n", c, calc(380, 1700, c), bar(73));
    printf("Célula temp:\t %d \t %d \t %s \n", d, calc(380, 1700, d), bar(20));

    return 0;
}