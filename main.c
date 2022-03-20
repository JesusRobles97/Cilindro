#include <stdio.h>
#include <math.h>
#include <time.h>
#define PI 3.1416
float area();
float volumen();
void salir();
int main(void) {
    time_t tiempoInicio;
    time(&tiempoInicio);
    printf("Hora de aperura del programa: %s\n",ctime(&tiempoInicio));
    struct tm *miTiempoInicio = localtime(&tiempoInicio);
    int opcion;
    char repetir;
    do{
    printf("MENU DE OPCIONES\n");
    printf("1. Calcular volumen de cilindro\n");
    printf("2. Calcular el area del cilindro\n");
  
    scanf("%d",&opcion);
    switch (opcion) {
        case 1:
            printf("\nEl volumen del cilindro es: %f\n",volumen());
            break;
        case 2:
            printf("\nEl area del cilindro es: %f\n",area());
            break;
            
        default:
            printf("Opcion invalida\n");
            break;
    }
        printf("\n¿Desea seguir utilizando el programa?[S/N]\n");
        fflush(stdin);
        scanf("%c",&repetir);
        if(repetir == 'S'){
         
        }
    }while(repetir == 'S');
    salir(*miTiempoInicio);

    return 0;
}

float volumen(){
    float volumen,radio,altura;
    printf("Ingrese el valor del radio: ");
    scanf("%f",&radio);
    printf("\nIngrese el valor de la altura: ");
    scanf("%f",&altura);
    volumen = PI * pow(radio, 2) * altura;
    return  volumen;
}

float area(){
    float area,radio,altura;
    printf("Ingrese el valor del radio: ");
    scanf("%f",&radio);
    printf("\nIngrese el valor de la altura: ");
    scanf("%f",&altura);
    area = PI * pow(radio, 2) * altura + 2 * PI * pow(radio, 2);
    return area;
}
void salir(struct tm *miTiempoInicio){
    int hora,minuto,segundo;
    time_t tiempoFinal;
    time(&tiempoFinal);
    printf("Hora de cierre del programa: %s\n",ctime(&tiempoFinal));
    struct tm *miTiempoFinal = localtime(&tiempoFinal);
    hora = miTiempoFinal->tm_hour - miTiempoInicio->tm_hour;
    minuto = miTiempoFinal->tm_min - miTiempoInicio->tm_min;
    segundo = miTiempoFinal->tm_sec - miTiempoInicio->tm_sec;
    printf("\nEl tiempo que usted mantuvo abierto el programa es de: %d hrs %d min %d sec\n",hora,minuto,segundo);
    getchar();
    
}
