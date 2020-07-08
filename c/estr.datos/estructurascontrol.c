#include <stdio.h>

int main()
{
    int a;
    printf("Introduce un número: ");
    scanf("%d", &a);

    /* Estructura condicional if...else */
    if (a > 100) 
	    printf("Tu número es mayor que 100.\n");
	else
	    printf("Tu número es menor que 100.\n");

    /* Estructura condicional abierta y cerrada switch...case */
	switch(a) {
		case 1 :
			printf("Lun, Lunes\n");
			break;
		case 2 :
			printf("Mar, Martes\n");
			break;
		case 3 :
			printf("Mier, Miercoles\n");
			break;
		case 4 :
			printf("Jue, Jueves\n");
			break;
		case 5 :
			printf("Vie, Viernes\n");
			break;
		case 6 :
			printf("Sab, Sabado\n");
			break;
		case 7 :
			printf("Dom, Domingo\n");
			break;
		default :
			printf("No existe en la semana\n");
    }

    /* Bucle while */
    int b = a;
    int i = 0;
    while (b < 1000000) {
        b = b + 1;
        i++;
    }
    printf("El número de iteraciones para llegar a 1.000.000 ha sido de %d\n", i);

    /* Bucle do...while */
    // TODO

    return 0;
}