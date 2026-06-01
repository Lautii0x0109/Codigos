#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct VUELOS
{
    char cod[11]; //10 caracteres max
    int dia;
    int nro_vuelo;
    float pasaje_v;
    int pasajeros; //cantidad originalmente en 0


};

struct PASAJEROS //AERO 1 SOLAMENTE
{
    int dni;
    int nro_vuelo2;
};

////////////////////////////////////
void actualizacion(FILE*, FILE*);
void arch_null(FILE*);

////////////////////////////////////
int main(void)
{
    FILE *flight;
    FILE *pass;

    actualizacion(flight,pass);



    return 0;
}
/////////////////////////////
void actualizacion (FILE* v, FILE* pass)
{

    struct VUELOS vuelo;
    struct PASAJEROS pas;
    char aerolinea[11] = "Aero1";

    pass = fopen("Pasajeros.dat","rb");
    arch_null(pass);

    v = fopen("Vuelos.dat","rb+");
    arch_null(v);

    fread(&vuelo,sizeof(vuelo),1,v);

    while(!feof(v))
    {

        if(strcmpi(vuelo.cod,aerolinea)==0)
        {
            rewind(pass);
            fread(&pas,sizeof(pas),1,pass);

            while(!feof(pass))
            {


                if(pas.nro_vuelo2 == vuelo.nro_vuelo)
                {


                    vuelo.pasajeros += 1;


                }

                fread(&pas,sizeof(pas),1,pass);
            }

            fseek(v,-sizeof(vuelo),SEEK_CUR);
            fwrite(&vuelo,sizeof(vuelo),1,v);


        }

        fread(&vuelo,sizeof(vuelo),1,v);

    }

    fclose(v);
    fclose(pass);



}
///////////////////////////////////////
void arch_null(FILE* puntero)
{
    if(puntero == NULL)
    {
        system("pause");
        exit(1);
    }




}
////////////////////////////////////////





