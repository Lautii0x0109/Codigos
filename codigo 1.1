#include <stdio.h>
#include <string.h>
#define ALUMNOS 80

struct ALU
{
    int dni;
    char pibe[80];
    int nota1 ;
    int nota2;
    float prom;
};

void leer (char[],int);
int ingreso(struct ALU[],int);
int busqueda_d(struct ALU[], int,int);
int valida_d(int,int,int);
int valida_n(int,int,int);

void resultado(struct ALU[],int);

void promo (struct ALU[],int);

int main()
{
    struct ALU v_alumno[ALUMNOS];
    int f=0, cant_alu=0;
    char secaga[3];

    for(f;f<ALUMNOS;f++)
    {
        v_alumno[f].dni= -3;
        v_alumno[f].nota1 = 0;
        v_alumno[f].nota2 = 0;
        v_alumno[f].prom= 0;
    }

    printf("\nSe esta cagando encima (si o no):\t");
    fgets(secaga,3,stdin);
    leer(secaga,3);

    if(strcmpi(secaga,"no")==0)
    {
        cant_alu = ingreso(v_alumno,ALUMNOS);
        resultado(v_alumno,cant_alu);
        promo(v_alumno,cant_alu);
    }
    else
    {
        printf("\nAproveche y vaya a hacer poopie");
        printf("\n\n");
    }



    return 0;
}

///////////////FUNCIONES////////////////////////////////
void leer (char c[],int cem)
{
    int f=0;

    while(c[f]!='\0')
    {
        if(c[f]=='\n')
        {
            c[f]='\0';
        }
        else
        {
            f++;
        }
    }
}

///////////////////////////////////////////////
int ingreso(struct ALU v_alumno[],int cem)
{

    int f=0,pos=-1,dni;

    printf("\nIngrese el DNI del alumno:\t");
    scanf("%d",&v_alumno[f].dni);
    v_alumno[f].dni = valida_d(v_alumno[f].dni,0,99999999);

    while(v_alumno[f].dni != 0&&f<cem)
    {
        printf("\nIngrese el apellido y nombre del alumno:\t");
        getchar();
        gets(v_alumno[f].pibe);

        printf("\nIngrese la nota del primer parcial del alumno %d:\t",v_alumno[f].dni);
        scanf("%d",&v_alumno[f].nota1);
        v_alumno[f].nota1 = valida_n (v_alumno[f].nota1,1,10);

        printf("\nIngrese la nota del segundo parcial del alumno %d:\t",v_alumno[f].dni);
        scanf("%d",&v_alumno[f].nota2);
        v_alumno[f].nota2 = valida_n (v_alumno[f].nota2,1,10);

        v_alumno[f].prom = ((float)v_alumno[f].nota1 + v_alumno[f].nota2)/2;

        f++;

        printf("\nIngrese el DNI del alumno:\t");   //busca si se repite algun DNI
        scanf("%d",&dni);
        dni = valida_d(dni,0,99999999);
        pos = busqueda_d(v_alumno,f,dni);

        if(dni!=0)
        {
            while(pos!=-1)
            {
                printf("Error, DNI ya ingresado, reingrese (0 para terminar):\t");
                scanf("%d",&dni);
                dni = valida_d(dni,0,99999999);
                pos = busqueda_d(v_alumno,f,dni);
            }
        }

        v_alumno[f].dni = dni;



    }

    return f;

}
///////////////////////////////////////////
int busqueda_d(struct ALU v[], int cem, int cod)
{
    int f=0, pos=-1;

    while(pos==-1&&f<cem)
    {
        if(v[f].dni==cod)
        {
            pos=f;
        }
        else
        {
            f++;
        }

    }

    return pos;


}
///////////////////////////////////////////
int valida_d(int dato, int li, int ls)
{
    while(dato<li || dato > ls)
    {
        printf("\nError, reingrese el DNI del alumno:\t");
        scanf("%d",&dato);
    }

    return dato;
}
/////////////////////////////////////////////
int valida_n(int dato, int li, int ls)
{
    while(dato<li || dato > ls)
    {
        printf("\nError, reingrese la nota del parcial del alumno:\t");
        scanf("%d",&dato);
    }

    return dato;
}

////////////////////////////////////////////
///////////////SEGUNDO LOTE/////////////////
////////////////////////////////////////////

void resultado (struct ALU v_alumno[], int cem)
{
    int f=0,cont_aprobado=0,cont_desa=0;

    for(f;f<cem;f++)
    {
        if((v_alumno[f].nota1 >= 4 )&& (v_alumno[f].nota2) >= 4)
        {
            cont_aprobado++;
        }
        else
        {
            cont_desa++;
        }
    }

    printf("\nCantidad de alumnos aprobados (con notas mayores o iguales a 4):\t %d", cont_aprobado);
    printf("\nCantidad de alumnos desaprobaron (con notas menores a 4):\t %d", cont_desa);

}

////////////////////////////////////////////////
///////////////////TERCER LOTE//////////////////
////////////////////////////////////////////////

void promo(struct ALU v_alumno[],int cem)
{
    int f=0;


    printf("\nALUMNOS PROMOCIONADOS");

    for(f;f<cem;f++)
    {
        if((v_alumno[f].nota1 >= 7) && (v_alumno[f].nota2) >= 7)
        {
            printf("\n\nDNI: %d", v_alumno[f].dni);
            printf("\n");
            printf("\nNombre y Apellido: %s", v_alumno[f].pibe);
            printf("\n");
            printf("\nNota promedio: %f", v_alumno[f].prom);
        }
    }

}
