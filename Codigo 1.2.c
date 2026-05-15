#include <stdio.h>
#include <string.h>
#define ARCHIVOS 99

struct INFO
{
    int codigo;
    char materia[31];
    char archivo [31];
};


///////////////////
int carga_archivos(struct INFO[], int);
int validar_cod(int, int, int);
int busqueda (struct INFO[], int, int);
/////////////////
void ingreso_descargas(struct INFO[],int,int [][31],int);
int validar_dia(int,int,int);

////////////////////////////////
void mostrar(struct INFO[],int, int[][31], int);

void leer(char[],int);
void leer2(char[],int);

int main()
{
    struct INFO v_archivos[ARCHIVOS];
    int cem, matriz[ARCHIVOS][31]={{0}},i=0;

    for(i;i<ARCHIVOS;i++)
    {
        v_archivos[i].codigo=0;
    }


    cem=carga_archivos(v_archivos,ARCHIVOS);

    if(cem==0)
    {
        printf("\nNo se ingresaron archivos...");

    }
    else
    {
        ingreso_descargas(v_archivos,cem,matriz,31);
        mostrar(v_archivos,cem,matriz,31);
    }


    return 0;
}
///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
int carga_archivos(struct INFO v[], int cem) //termina con Nombre de arcivo = FIN
{
    int f=0,aux,pos=-1;

    printf("\nIngrese el nombre del archivo:\t");

    fgets(v[f].archivo,31,stdin);
    leer(v[f].archivo,31);


    while(strcmpi(v[f].archivo,"FIN")!=0)
    {
        printf("\nCodigo del archivo:\t");
        scanf("%d",&aux);
        aux=validar_cod(aux,1000,9999);
        pos=busqueda(v,f,aux);

        while(pos!=-1)
        {
            printf("\nCodigo ya ingresado, reingrese:\t");
            scanf("%d",&aux);
            aux=validar_cod(aux,1000,9999);
            pos=busqueda(v,f,aux);

        }

        v[f].codigo = aux;

        printf("\nNombre de la materia:\t");
        getchar();
        fgets(v[f].materia,31,stdin);
        leer(v[f].materia,31);

        f++;

        printf("\nIngrese el nombre del archivo:\t");

        fgets(v[f].archivo,31,stdin);
        leer(v[f].archivo,31);

    }


    return f;

}
//////////
void leer (char v[],int cem)
{
    int f=0;

    while(v[f]!='\0')
    {
        if(v[f]=='\n')
        {
            v[f] = '\0';
        }
        else
        {
            f++;
        }
    }


}
///////////////////////////
int validar_cod(int dato,int li,int ls)
{
    while(dato<li||dato>ls)
    {
        printf("\nCodigo fuera de rango, reingrese:\t");
        scanf("%d",&dato);
    }

    return dato;
}
/////////////////////
int busqueda (struct INFO v[], int cem, int dato)
{
    int f=0,pos=-1;

    while(pos==-1&&f<cem)
    {
        if(v[f].codigo==dato)
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
/////////////////////////////////
/////////////////////////////////
void ingreso_descargas(struct INFO v[], int cem, int m[][31],int cc)
{
    int aux,pos=-1,dia;


    printf("\ncarga de dias: Ingrese el codigo del archivo:\t");
    scanf("%d",&aux);


    while(aux!=999)
    {
        pos=busqueda(v,cem,aux);

        if(pos==-1)
        {
            printf("\nCodigo not found...");
        }
        else
        {
            printf("\nQue dia el archivo %d ue cargado:\t", v[pos].codigo);
            scanf("%d",&dia);
            dia=validar_dia(dia,1,31);

            m[pos][dia-1]+=1;


        }

        printf("\nIngrese el codigo del archivo:\t");
        scanf("%d",&aux);

    }

}
///////////////////////////////
int validar_dia(int dia, int li, int ls)
{
    while(dia<li||dia>ls)
    {
        printf("\nRango de dias erroneo, reingrese:\t");
        scanf("%d",&dia);
    }


    return dia;
}
///////////////////////////////
///////////////////////////////
void mostrar(struct INFO v[],int cem, int m[][31],int cc)
{
    int f,c,i;

    printf("\nNombre del archivo| DIA");
    for(i=0;i<cc;i++)
    {
        printf("|%d|", i+1);
    }

    for(f=0;f<cem;f++)
    {
        printf("\n%s\t", v[f].archivo);

        for(c=0;c<cc;c++)
        {
            printf("%4d",m[f][c]);
        }
    }


}
