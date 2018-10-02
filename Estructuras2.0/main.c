#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int idSector;
    float sueldo;
    int isEmpty;

}eEmpleados;

typedef struct
{
    int id;
    char descripcion[20];
}eSector;


int menu();
void inicializarEmpleados(eEmpleados empleados[],int tam);
void mostrarEmpleado(eEmpleados unEmpleado,eSector sectores,int tam);
void mostrarEmpleados(eEmpleados lista[],int tam,eSector sectores,int tamSector);
int buscarLibre(eEmpleados lista[],int tam);
int buscarEmpleado(eEmpleados lista[],int tam,int legajo);
void altaEmpleado(eEmpleados lista[],int tam,eEmpleados sectores[],int tamSector);
void bajaEmpleado(eEmpleados lista[],int tam);
void modificarEmpleado(eEmpleados lista[],int tam);
void ordenarEmpleadosXlegajo(eEmpleado lista[], int tam);
void harcodearEmpleados(eEmpleados empleados[]);
void harcodearSectores{eSector sectores[]);
void obtenerSector(eSector sectores[],int tam,int idSector,char cadena[]);

int main()
{
    eSector sectores[TAM];
    eEmpleados empleado[TAM];
    inicializarEmpleados(empleado,TAM);
    harcodearEmpleados(empleado);
    harcodearSectores(empleado);

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
                mostrarEmpleados(empleado,TAM,sectores,5);
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


void mostrarEmpleado(eEmpleados unEmpleado,eSector sectores,int tam)
{
    char descSector[20];
    obtenerSector(sectores,tam,unEmpleado.idSector,descSector);

   printf("%d\t \t%s \t%c \t%.2f \t%10s\n",unEmpleado.legajo,unEmpleado.nombre,unEmpleado.sexo,unEmpleado.sueldo,descSector);

}

void mostrarEmpleados(eEmpleados lista[],int tam,eSector sectores[],int tamSector)
{
    system("cls");
    printf("Legajo Nombre Sexo Sueldo\n\n");
   for(int i=0;i<tam;i++)
   {
       if(lista[i].isEmpty==1)
       {
           mostrarEmpleado(lista[i],sectores,tamSector);
       }
   }
   system("pause");
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

void altaEmpleado(eEmpleados lista[],int tam,eSector sectores[],int tamSector)
{
    int legajo;
    int libre,existe,idSector;

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

        listarSectores(sectores,tamSector);
        printf("ingrese el sector: ");
        scanf("%d",&idSector);

        empleado.idSector=idSector
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


void ordenarEmpleadosXlegajo(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;
    for(int i=0; i<tam-1; i++){
        for(int j= i+1; j < tam; j++){

            if( lista[i].legajo > lista[j].legajo){
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;

            }
        }
    }

    printf("Empleados oredenados con exito!!!\n\n");


}

void ModificarEmpleado(eEmpleado lista[], int tam)
{
    int legajo;
    int indice;
    char seguir;
    float nuevoSueldo;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de legajo %d\n\n", legajo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice]);

        printf("\nModifica sueldo? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            lista[indice].sueldo = nuevoSueldo;

            printf("Modificacion exitosa\n\n");
        }
        system("pause");
    }

}

void harcodearEmpleados(eEmpleados empleados[])
{
    eEmpleados lista[]={
        {1111,"juan",'m',2,21000,1},
        {2111,"luis",'m',3,23000,1},
        {3111,"ana",'f',4,11000,1},
        {4111,"mateo",'m',5,23000,1},
        {5111,"mia",'f',6,91000,1},
        {6111,"mauro",'m',1,16000,1},
        {7111,"alberto",'m',1,31000,1},
        {8111,"valentina",'f',2,22000,1},
    };

    for(int i=0;i<8;i++)
    {
        empleados[i]=lista[i];
    }


}
void harcodearSectores{eSector sectores[]}
{
    eSector x[]={
    {1,"RRHH"}
    {2,"ciencia"}
    {3,"sistemas"}
    {4,"contable"}
    {5,"social"}
    {6,"quimico"}
    }
}

void obtenerSector(eSector sectores[],int tam,int idSector,char cadena[])
{
    for(int=0;i<tam;i++)
    {
        if(sectores[i].id==idSector)
        {
            strcpy(cadena,sectores[i].descripcion);
        }
    }

}


void listarSectores(eSector sectores[],int tam)
{
    printf("id  descripcion");
    for(int i=0,i<tam,i++)
    {
        printf("%d  %10s",sectores[i].id,sectores[i].descripcion);
    }
    printf("\n\n");
}


    int legajo;
    int indice;
    char seguir;
    float nuevoSueldo;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de legajo %d\n\n", legajo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice]);

        printf("\nModifica sueldo? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            lista[indice].sueldo = nuevoSueldo;

            printf("Modificacion exitosa\n\n");
        }
        system("pause");
    }





}
