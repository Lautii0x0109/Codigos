
#include <stdio.h>
#include <string.h>
#define CLIENTES 100
#define VENDEDORES 10

// estructura
struct INFO
{
    int cli;
    float importe;
    char nya[80];
    int cont_cli;

};
// prototipos
int ingreso(struct INFO[], int);
int verificar_cod(int,int,int);
int busqueda_cod(int,int,struct INFO[]);


void ventas(struct INFO[],int,int[],char[]);
float verificacion_imp(float,int);
void leer(char[],int);
int verif_vend(int,int,int);


void mostrar(struct INFO[],int,int[],int);
void burbujeo(struct INFO[],int);

int main()
{
    struct INFO v_info[CLIENTES];
    int cont_ventas[VENDEDORES]={0},i=0, cem=0;
    char decision[3];

    for(i;i<CLIENTES;i++)
    {
        v_info[i].cont_cli=0;
        v_info[i].importe = 0;
    }

    cem=ingreso(v_info,CLIENTES);
    if(cem==0)
    {
        printf("\nNO SE INGRESARON DATOS");
    }
    else
    {
        ventas(v_info,cem,cont_ventas,decision);
        mostrar(v_info,cem,cont_ventas,VENDEDORES);
    }



    return 0;
}
///////////////////////////////////
/////////////FUNCIONES/////////////
///////////////////////////////////
int ingreso(struct INFO v_cli[],int cli)
{
    int chikito=0,f=0,pos=-1,aux;

    printf("\nIngrese el codigo del cliente mi abor:\t");
    scanf("%d", &v_cli[f].cli);
    v_cli[f].cli=verificar_cod(v_cli[f].cli,999,9999);

    while(v_cli[f].cli!=999)
    {
        printf("\nIngrese el nombre y apellido del cliente %d", v_cli[f].cli);
        getchar();
        gets(v_cli[f].nya);

        f++;

        printf("\nIngrese el codigo del cliente mi abor:\t");
        scanf("%d", &aux);
        aux=verificar_cod(aux,999,9999);
        pos=busqueda_cod(aux,f,v_cli);

        while(pos!=-1)
        {
            printf("codigo repetido, reingrese");
            scanf("%d", &aux);
            aux=verificar_cod(aux,999,9999);
            pos=busqueda_cod(aux,f,v_cli);

        }

        v_cli[f].cli=aux;
    }

    return f;
}
/////////////////////////////////
int verificar_cod(int dato, int li, int ls)
{
    while(dato<li||dato>ls)
    {
        printf("\nError, codigo erroneo, reingrese (999 para acabar):\t");
        scanf("%d",&dato);
    }

    return dato;
}
//////////////////////////////////////////
int busqueda_cod(int dato, int cem, struct INFO v[])
{
    int f=0,pos=-1;

    while(pos==-1&&f<cem)
    {
        if(dato==v[f].cli)
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
/////////////////////////////////////////
//////////////SEGUNDO LOTEX/////////7////
/////////////////////////////////////////
void ventas(struct INFO v[],int cem, int v_ventas[],char decision[])
{
    int i=0,vendedor;
    float imp;

    for(i;i<cem;i++)
    {
        printf("\nCLIENTE NUMERO %d", v[i].cli);
        printf("\n\n");
        printf("\nIngrese el importe del cliente anteriormente mostrado:\t");
        scanf("%f",&imp);
        imp=verificacion_imp(imp,0);
        v[i].importe +=imp;
        v[i].cont_cli++;

        printf("\nIngrese el numero del vendedor que le vendio:\t");
        scanf("%d",&vendedor);
        vendedor=verif_vend(vendedor,1,10);

        vendedor--;
        v_ventas[vendedor]++;

        printf("\nel cliente %d realizo alguna otra compra?:\t");
        getchar();
        fgets(decision,3,stdin);
        leer(decision,3);

        while(strcmpi(decision,"si")==0)
        {
            printf("\nIngrese el importe del cliente anteriormente mostrado:\t");
            scanf("%f",&imp);
            imp=verificacion_imp(imp,0);
            v[i].importe +=imp;
            v[i].cont_cli++;

            printf("\nIngrese el numero del vendedor que le vendio:\t");
            scanf("%d",&vendedor);
            vendedor=verif_vend(vendedor,1,10);

            vendedor--;
            v_ventas[vendedor]++;

            printf("\nel cliente %d realizo alguna otra compra?:\t");
            getchar();
            fgets(decision,3,stdin);
            leer(decision,3);
        }

    }






}
///////////////////////////////
float verificacion_imp(float dato, int lim)
{
    while(dato<lim)
    {
        printf("\nError, dato = 0, reingrese:\t");
        scanf("%f",&dato);

    }


    return dato;
}
////////////////////////////////////
void leer (char decision[],int num)
{
    int i=0;

    while(decision[i]!='\0'&&i<num)
    {
        if(decision[i]=='\n')
        {
            decision[i]='\0';
        }
        else
        {
            i++;
        }
    }
}
///////////////////////////////////
int verif_vend(int vendedor,int li,int ls)
{

    while(vendedor<li || vendedor>ls)
    {
        printf("\nError, reingrese numero de vendedor:\t");
        scanf("%d",&vendedor);
    }
    return vendedor;
}
/////////////////////////////////////
//////////////lotex tres////////////
////////////////////////////////////
void mostrar(struct INFO v[],int cem, int cant_v[], int sem)
{
    int f=0;

    printf("\nCANTIDAD DE VENTAS POR CLIENTE:\t");
    for(f;f<cem;f++)
    {

        printf("\nCliente %s: %d", v[f].nya, v[f].cont_cli);

    }

    printf("\nCANTIDAD DE VENTAS REALIZADAS POR VENDEDOR:\t");
    for(f=0;f<sem;f++)
    {
        printf("\nVENDEDOR %d, cantidad de ventas %d", f+1, cant_v[f]);
    }

    burbujeo(v,cem);


    printf("\nCODIGO DE CLIENTE\tNOMBRE Y APELLIDO\t\tTOTAL FACTURADO");
    for(f=0;f<cem;f++)
    {
        printf("\n%d \t %s \t %.2f", v[f].cli, v[f].nya, v[f].importe);
    }


}
///////////////////////////////////////////
void burbujeo(struct INFO v[], int cem)
{
    int i=0,c,aux,aux2;
    char aux3[80];

    for(i;i<cem-1;i++)
    {
        for(c=0;c<cem-1-i;c++)
        {
            if(v[i].importe<v[i+1].importe)
            {
                aux=v[i].importe;
                v[i].importe=v[i+1].importe;
                v[i+1].importe=aux;

                aux2=v[i].cli;
                v[i].cli=v[i+1].cli;
                v[i+1].cli=aux;

                strcpy(aux3,v[i].nya);
                strcpy(v[i].nya,v[i+1].nya);
                strcpy(v[i+1].nya,aux3);

            }
        }
    }
}
