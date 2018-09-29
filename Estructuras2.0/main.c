#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int isEmpty;

}eEmpleados;


int menu();
void inicializarEmpleados(eEmpleados empleados[],int tam);
void mostrarEmpleado(eEmpleados unEmpleado);
void mostrarEmpleados(eEmpleados lista[],int tam);
int buscarLibre(eEmpleados lista[],int tam);
int buscarEmpleado(eEmpleados lista[],int tam,int legajo);
void altaEmpleado(eEmpleados lista[],int tam);
void bajaEmpleado(eEmpleados lista[],int tam);
void modificarEmpleado(eEmpleados lista[],int tam);

int main()
{
    eEmpleados empleado[TAM];
    inicializarEmpleados(empleado,TAM);

    char seguir='s';

      do{
        switch(menu())
        {
            case 1:
                printf("\t**Alta**\n");
                altaEmpleado(empleado,TAM);
                break;
            case 2:
                printf("\t**Baja**\n");
                bajaEmpleado(empleado,TAM);
                break;
            case 3:
                printf("\t**Modificacion**\n");
                break;
            case 4:
                printf("\t**Listar**\n");
                mostrarEmpleados(empleado,TAM);
                break;
            case 5:
                printf("\t**Ordenar**\n");

                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("end");
                exit(-1);
                break;
        }
    }while(seguir == 's');

    return 0;
}



int menu()
{
    int opcion;

    system("cls");
    printf("\t\t***Menu de opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- listar empleados\n");
    printf("5- Ordenar empleados\n");
    printf("5- Salir\n\n");

    printf("ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;

}

void inicializarEmpleados(eEmpleados empleados[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        empleados[i].isEmpty= 0;
        //system("pause");

    }

}


void mostrarEmpleado(eEmpleados unEmpleado)
{
   printf("%d\t \t%s \t%c \t%.2f",unEmpleado.legajo,unEmpleado.nombre,unEmpleado.sexo,unEmpleado.sueldo);

}

void mostrarEmpleados(eEmpleados lista[],int tam)
{
    system("cls");
    printf("Legajo Nombre Sexo Sueldo\n\n");
   for(int i=0;i<tam;i++)
   {
       if(lista[i].isEmpty==1)
       {
           mostrarEmpleado(lista[i]);
           //system("pause");
       }
   }
}


int buscarLibre(eEmpleados lista[],int tam)
{
    int retorno= -1;

    for(int i=0; i <tam; i++)
    {
        if(lista[i].isEmpty==0)
        {
            retorno = i;
            break;

        }
    }
    return retorno;
}


int buscarEmpleado(eEmpleados lista[],int tam,int legajo)
{
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        if(lista[i].legajo==legajo && lista[i].isEmpty==1)
        {
            retorno=i;
            break;

        }
    }
   return retorno;
}

void altaEmpleado(eEmpleados lista[],int tam)
{
    int legajo;
    int libre,existe;

    eEmpleados empleado;
    libre= buscarLibre(lista,tam);

    if(libre == -1)
    {
        printf("error no hay mas lugar\n");
    }
    else
    {
     printf("ingrese el legajo: ");
     scanf("%d",&legajo);

    existe=buscarEmpleado(lista,tam,legajo);

    if(existe!=-1)
     {
         printf("error el empleado ya existe\n");
         mostrarEmpleado(lista[existe]);
     }
     else{
        printf("ingrese el nombre: ");
        fflush(stdin);
        scanf("%s",empleado.nombre);
        printf("ingrese el sexo: ");
        fflush(stdin);
        scanf("%c",&empleado.sexo);
        printf("ingrese el sueldo: ");
        scanf("%f",&empleado.sueldo);

        empleado.isEmpty=1;
        lista[libre]=empleado;

        printf("se dio el acta con exito\n");
        system("pause");

     }



    }

}

void bajaEmpleado(eEmpleados lista[],int tam)
{
    int legajo;
    int existe;
    char opcion;

    mostrarEmpleados(lista,tam);
    printf("\n");
    printf("ingrese el legajo que desea dar de baja: ");
    scanf("%d",&legajo);


    existe=buscarEmpleado(lista,tam,legajo);

    if(existe == -1)
    {
         printf("error el empleado no existe\n");
    }
    else
    {
           mostrarEmpleado(lista[existe]);
           printf("seguro que desea dar de baja a este señor? s\n");
           fflush(stdin);
           scanf("%c",&opcion);

           if(opcion=='n' || opcion=='N')
           {
               printf("se cancelo la baja\n\n");
           }
           else
           {
               lista[existe].isEmpty=0;
               printf("***senior borrado***\n\n");
           }


    }

}


void modificarEmpleado(eEmpleados lista[],int tam)
{

}
