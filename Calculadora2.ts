import * as readline from 'readline';


enum OpcionMenu
{
    sumar = 1,
    restar,
    multiplicar,
    dividir,                                //enumeracion de las opciones de la calculadora
    reingreso,
    salida

}

const rl = readline.createInterface(
    {
        input: process.stdin,
        output: process.stdout,                 //constante de entrada y salida de respuesta
    });

async function ingresonum(pregunta: string): Promise <number> 
{
    while (true)
    {
        const input = await new Promise <string> ((resolve) => rl.question(pregunta, resolve));
        const numero = parseFloat(input);

        if(!isNaN(numero))
        {
            return numero;                                        //ingreso de numero
        }

        else
        {
            console.log("\nNumero invalido, reingrese el numero");
        }
    }
}

async function mostrarelmenu(valor1: number, valor2: number): Promise<OpcionMenu>
{
    console.log(`\nMenu de opciones \nNumero 1: %d     Numero 2: %d`, valor1, valor2);
    console.log("\n1) Sumar");
    console.log("\n2) Restar");
    console.log("\n3) multiplicar");                        //funcion de MOSTRAR el menu
    console.log("\n4) dividir");
    console.log("\n5) Ingresar nuevos numeros");
    console.log("\n6) salir del programa");

    while(true)
    {
        const input = await new Promise <string> ((resolve) => rl.question("\nSeleccione una opcion:", resolve));

        const opcion = parseInt(input);

        if(!isNaN(opcion)&& opcion >= 1 && opcion <=6)              //validar opcion
        {
            return opcion as OpcionMenu;
        }
        else
        {
            console.log("\nOpcion invalida, Ingrese nuevamente un numero con opcion correcta");
        }
    }
}

async function main(): Promise <void>
{
    let salir = false;
    let valor1 = await ingresonum("\nIngrese el primer numero:\t");
    let valor2 = await ingresonum("\ningrese el segundo numero:\t");

    while(!salir)
    {
        const opcion = await mostrarelmenu(valor1, valor2);

        switch(opcion)
        {

            case 1:
                {
                    console.log("\nresultado: %d", valor1 + valor2);            //opcion sumar
                    break;
                }
            
            case 2:
                {
                    console.log("\nresultado: %d", valor1 - valor2);                //opcion resta
                    break;
                }

            case 3:
                {
                    console.log("\nresultado: %d", valor1 * valor2);        //opcion multi
                    break;
                }

            case 4:
                {
                    if (valor2 == 0)                                                    //validacion de 0 cuando se divide
                    {
                        console.log("\nError, imposible la division por 0 (cero)");     //error al div por 0
                    }
                    else
                    {
                        console.log("\nresultado: %d", valor1 / valor2);                //division completa
                        
                    }

                    break;
                }
            
            case 5:
                {
                    valor1 = await ingresonum("\ningrese el primer numero:\t");             //pedida de reingreso
                    valor2 = await ingresonum ("\ningrese el segundo numero:\t");
                    break;
                }
            
            case 6:
                {
                    const validacion = await new Promise <string> ((resolve) =>
                        rl.question("\nSeguro de que quiere salir del programa? (0 para confirmar, X numero para negar):\t", resolve)          //pregunta si quiere salior del programa
                    );

                    if(validacion === "0")
                    {
                        console.log("\ncierre de programa");                        
                        salir = true;
                    }
                    else
                    {
                        console.log("\nRegresando al menu de opcione");
                    }
                    break;

                
                }

        }

       
    }

    rl.close();
}

main();

//tsc(ts) para compilar y node(js) para ejecutar 