#include <stdio.h>
#include <stdlib.h>
#include <string.h>

        // declaracion de estructuras (struct) segun enunciado

struct INFO
{
    char cod[4];
    char nombre[31];
    float sueldo;
    char estado;
};

struct INFO2
{
    char codigo[4];
    int horas;
    float precio;
};

/////////////////////////////////////////////////

void actualizacion(struct INFO, struct INFO2);
void arch_null(FILE*,int);
void eliminacion_renombre(struct INFO);             //funciones que se utilizaran con sus respectivos parametros

////////////////////////////
int main()
{
    struct INFO personal;
    struct INFO2 liquid;

    actualizacion(personal, liquid);

    eliminacion_renombre(personal);


    printf("\nFin del programa. . .\n");

    system ("pause");
    return 0;
}
//////////////////////////////
void eliminacion_renombre(struct INFO personal)
{
    FILE *arch;
    FILE *arch2;

    arch = fopen("PERSONAL.DAT","rb");
    arch_null(arch,4);

    arch2 = fopen ("personal.copy","wb");
    arch_null(arch2,5);                         //apertura de los archivos mas verificacion si da error al intentar abrirlos



    fread(&personal,sizeof(personal),1,arch);

    while(!feof(arch))
    {
        if(personal.estado == 'A')
        {
            fwrite(&personal,sizeof(personal),1,arch2);
        }

        fread(&personal,sizeof(personal),1,arch);

    }


    fclose(arch);
    fclose(arch2);

    remove("PERSONAL.DAT");
    rename("personal.copy","PERSONAL.DAT");     //cierre de archivos primero y luego eliminacion y renonmbre (de ahi su nombre)


}

/////////////////////////////////////
void actualizacion(struct INFO personal, struct INFO2 liquid)
{
    FILE *arch;
    FILE *arch2;
    FILE *archtxt;
    int encontrado;


    arch = fopen("PERSONAL.DAT","r+b");
    arch_null(arch,1);

    arch2 = fopen("LIQUIDACION.DAT","rb");
    arch_null(arch2,2);

    archtxt = fopen("ERRORES.TXT","wt");
    arch_null (archtxt,3);                      //apertura de los archivos mas verificacion si da error al intentar abrirlos


    fread(&liquid,sizeof(liquid),1,arch2);

    while(!feof(arch2))
    {
        rewind(arch);
        encontrado = 0;


        fread(&personal,sizeof(personal),1,arch);
        while(!feof(arch) && encontrado == 0)
              {

                  if(strcmpi(personal.cod, liquid.codigo)==0)
                  {
                      encontrado = 1;
                      personal.sueldo = liquid.horas * liquid.precio;       //sumo sueldo
                      fseek(arch,-sizeof(personal),SEEK_CUR);
                      fwrite(&personal,sizeof(personal),1,arch);
                      fflush(arch);

                  }

                  fread(&personal,sizeof(personal),1,arch);

              }

              if(encontrado==0)
              {
                  fprintf(archtxt,"horas:%d;codigo:%s\n",liquid.horas,liquid.codigo);
              }

        fread(&liquid,sizeof(liquid),1,arch2);

    }

    fclose(arch);
    fclose(arch2);
    fclose(archtxt);            //cierre de archivos
}
///////////////////////////
void arch_null(FILE* puntero,int error) //se le preasigna un valor int (entero) para saber que archivo fallo al abrirse
{
    if(puntero ==NULL)
    {
        printf("\nNo se pudo abrir el archivo...");     //mensaje de error
        exit(error);                                    //muestra del error mas valor-marca de que archivo fallo
    }


}
///////////////////////////////
