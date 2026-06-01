#include<stdio.h>
#include <stdlib.h>


struct INFO
{
    int cod;
    char des[50];
    int stock;

};

struct INFO_F
{
    int cod;
    int falta;
};

//////////////////////////////
void arch_null(FILE*);
void carga(FILE*, FILE*);
int ingresa_y_valida_cant(int, int);
int busqueda(int, FILE*);
int ingresa_y_valida_cod(int, int);
int busqueda2 (int,FILE*);
void creacion_archivo(FILE*);

///////////////////////////
int main(void)
{
    FILE *arch;
    FILE *arch3;

    creacion_archivo(arch3);

    carga(arch,arch3);



    return 0;
}
///////////////////////////////////
void arch_null(FILE* puntero)
{
    if(puntero == NULL)
    {
        printf("\nNo se pudo abrir el archivo...");
        system ("pause");
        exit(1);
    }
}
///////////////////////////////////
void carga(FILE* arch, FILE* arch3)
{
    struct INFO producto;
    struct INFO_F faltante;
    int pos=-1,aux,cant,neg;

    faltante.falta=0;

    printf("\nIngrese el codiggo del articulo a cambiar (0 para finalizar):\t");
    scanf("%d",&aux);
    aux = ingresa_y_valida_cod(aux,0);


    while(aux != 0)
    {
        pos = busqueda(aux,arch);

        while(pos == -1 && aux != 0)
        {
            printf("\nCod no encontrado, reingrese (0 para finalizar):\t");
            scanf("%d",&aux);
            aux = ingresa_y_valida_cod(aux,0);

            if(aux != 0)
            {
                pos = busqueda(aux,arch);
            }
        }

        arch = fopen("Stock.dat","rb+");

        arch3 = fopen("Faltantes.dat","rb+");

        arch_null(arch);

        arch_null(arch3);

        printf("\nIngrese la cantidad vendida:\t");
        scanf("%d",&cant);
        cant = ingresa_y_valida_cant(cant,0);

        fseek(arch,pos * sizeof(producto),SEEK_SET);
        fread(&producto,sizeof(producto),1,arch);

        if(producto.stock >= cant)
        {
            producto.stock-=cant;
            fseek(arch,(int)-sizeof(producto),SEEK_CUR);
            fwrite(&producto,sizeof(producto),1,arch);

        }
        else
        {

            producto.stock-=cant; //numero negativo

            neg=producto.stock;     //guardo el negativo

            producto.stock = 0;

            fseek(arch,(int)-sizeof(producto),SEEK_CUR);
            fwrite(&producto,sizeof(producto),1,arch); //escribo 0 en el stock de STOCK.dat

            neg = neg*(-1); //paso a positivo

            pos = busqueda2(aux,arch3);


            if(pos!=-1)
            {
                fseek(arch3,pos * sizeof(faltante),SEEK_SET);
                fread(&faltante,sizeof(faltante),1,arch3);

                faltante.falta +=neg;

                fseek(arch3,-sizeof(faltante),SEEK_CUR);
                fwrite(&faltante,sizeof(faltante),1,arch3);
            }
            else
            {
                faltante.cod=aux;
                faltante.falta=neg;

                fseek(arch3,0 * sizeof(faltante),SEEK_END);
                fwrite(&faltante,sizeof(faltante),1,arch3);

            }


        }

        fclose(arch);
        fclose(arch3);

        if(aux!=0)
        {
            printf("\nIngrese el codiggo del articulo a cambiar (0 apra finalizar):\t");
            scanf("%d",&aux);
            aux = ingresa_y_valida_cod(aux,0);
        }

    }

    printf("\nCarga finalizada...");


}
/////////////////////////////////////////////
int ingresa_y_valida_cod(int aux,int lim)
{
    while(aux<lim)
    {
        printf("\nError, reingrese codigo:\t");
        scanf("%d",&aux);
    }


    return aux;
}
/////////////////////////////////////////////
int busqueda (int aux, FILE* arch)
{
    struct INFO producto;
    int pos=0,encontrado=-1;

    arch = fopen("Stock.dat","rb");
    arch_null(arch);

    rewind(arch);

    fread(&producto,sizeof(producto),1,arch);

    while(!feof(arch)&&encontrado==-1)
    {
        if(producto.cod == aux)
        {
            encontrado=pos;
        }
        else
        {
            pos++;
            fread(&producto,sizeof(producto),1,arch);
        }

    }

    fclose(arch);

    return encontrado;
}
///////////////////////////////////////////
int ingresa_y_valida_cant(int dato,int lim)
{
    while(dato<=lim)
    {
        printf("\nError, reingrese codigo:\t");
        scanf("%d",&dato);
    }

    return dato;
}
////////////////////////////////////////////////
int busqueda2 (int aux, FILE* arch3)
{
    struct INFO_F producto;
    int pos=0,encontrado=-1;

    arch3 = fopen("Faltantes.dat","rb");
    arch_null(arch3);

    rewind(arch3);

    fread(&producto,sizeof(producto),1,arch3);

    while(!feof(arch3)&&encontrado==-1)
    {
        if(producto.cod == aux)
        {
            encontrado=pos;
        }
        else
        {
            pos++;
            fread(&producto,sizeof(producto),1,arch3);
        }

    }

    fclose(arch3);

    return encontrado;
}
/////////////////////////////
void creacion_archivo(FILE* puntero)
{
    puntero = fopen("Faltantes.dat","ab");
    arch_null(puntero);
    fclose(puntero);
}
