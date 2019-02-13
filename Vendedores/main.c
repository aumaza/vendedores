#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "misFunciones.h"
#include "vendedores.h"

int main()
{
    ArrayList* list = al_newArrayList();
    validNULL(list); // Vendedores

    ArrayList* list1 = al_newArrayList();
    validNULL(list1);


    VendedorParser("DATA.csv",list);
    VendedorComisionParser("DATA1.csv",list1);

    osDetect (SO);
    int option;

    do
    {
        osDetect (SO);
        printf("\n=======================");
        printf("\n1. Altas");
        printf("\n2. Bajas");
        printf("\n3. Modificaciones");
        printf("\n4. Informes");
        printf("\n5. Calculo Comisiones");
        printf("\n6. Guardar Datos");
        printf("\n=======================");
        printf("\n0. Salir");
        printf("\n=======================");
        option = optionValid();

        switch (option)
        {
        case 1:

            osDetect (SO);
            int A;

            do
            {
                osDetect (SO);
                printf("\n=======================");
                printf("\n1. Alta Vendedores");
                printf("\n=======================");
                printf("\n0. Salir");
                printf("\n=======================");
                A = optionValid();

                switch (A)
                {
                case 1:
                    addVendedor(list);
                    break;

                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;

                case 5:
                    break;

                case 6:
                    break;

                case 7:

                    break;
                }
            }
            while(A != 0);
            break;
        case 2:
            break;

        case 3:

            osDetect (SO);
            int C;

            do
            {
                osDetect (SO);
                printf("\n=================================");
                printf("\n1. Modificar Nombre Vendedor");
                printf("\n2. Modificar Apellido Empleado");
                printf("\n3. Modificar Edad");
                printf("\n4. Modificar Estudios");
                printf("\n5. Modificar Estado Civil");
                printf("\n6. Modificar Cantidad Hijos");
                printf("\n7. Modificar Antiguedad");
                printf("\n=================================");
                printf("\n0. Salir");
                printf("\n=================================");
                C = optionValid();

                switch(C)
                {
                case 1:

                    break;

                case 2:

                    break;

                case 3:

                    break;

                case 4:

                    break;

                case 5:

                    break;

                case 6:

                    break;

                case 7:

                    break;
                }
            }
            while(C != 0);
            break;
        case 4:

            osDetect (SO);
            int D;

            do
            {
                osDetect (SO);
                printf("\n===============================");
                printf("\n1. Listar Vendedores");
                printf("\n2. Listar Vendedores con Comisiones");
                printf("\n3. Seleccionar Nivel");
                printf("\n4. Listar Alfabeticamente");
                printf("\n5. Listar por Montos Facturados");
                printf("\n6. Vendedor con Mayor Facturacion");
                printf("\n7. Vendedor con Mayor Facturacion por Nivel");
                /*printf("\n8. Listar Tipos de Baja");
                printf("\n9. Buscar Empleado por Nombre y Apellido");
                printf("\n10. Buscar Empleado por DNI");
                printf("\n11. Buscar Nivel de Estudio");
                printf("\n12. Buscar Nacionalidad");
                printf("\n13. Buscar Estado Civil");*/
                printf("\n===============================");
                printf("\n0. Salir");
                printf("\n===============================");
                D = optionValid();

                switch(D)
                {
                case 1:
                    showVendedores(list);
                    break;

                case 2:
                    showVendedoresComisiones(list1);
                    break;

                case 3:
                    //VendedorComisionNivel(list1);
                    //VendedorNivel(list1);
                    osDetect(SO);
                    int counter = 0;
                    int flag = 0;
                    int nivel = selectLevel();

                    header2();

                    switch(nivel)
                    {
                    case 0:
                            if(saveVendedorComisiones("JUNIOR.csv",list1->filter(list1,getLevel1)) == 1)
                            {
                            printf("\nJunior");

                            showVendedoresComisiones(list1->filter(list1,getLevel1));
                            counter++;
                            flag = 1;
                            }
                            break;


                    case 1:
                            if(saveVendedorComisiones("STANDART.csv",list1->filter(list1,getLevel2)) == 1)
                            {
                            printf("\nStandart");

                            showVendedoresComisiones(list1->filter(getLevel2));
                            counter++;
                            flag = 1;
                            }
                            break;

                    case 2:
                            if(saveVendedorComisiones("EXPERT.csv",list1->filter(list1,getLevel3)) == 1)
                            {
                            printf("\nExpert");

                            showVendedoresComisiones(list1->filter(list1,getLevel3));
                            counter++;
                            flag = 1;
                            }
                            break;
                    }
                    footer2();
                    printf("\nHay %d Vendedores en el nivel %d", counter, nivel);

                    if(flag == 1)
                    {
                        printf("\nDATOS GUARDADOS EXITOSAMENTE!");
                        footer2();
                    }
                    wait(SO);
                    break;

                case 4:
                    showVendedorAlfabetico(list1);
                    break;

                case 5:
                    showVendedorMonto(list1);
                    break;

                case 6:
                    vendeMax(list1);
                    break;

                case 7:
                    vendedoresMasGanadoresNivel(list1);
                    break;

                case 8:

                    break;

                case 9:

                    break;

                case 10:

                    break;

                case 11:

                    break;

                case 12:

                    break;

                case 13:

                    break;
                }
            }
            while(D != 0);
            break;

        case 5:
            osDetect (SO);
            int E;

            do
            {
                osDetect (SO);
                printf("\n===============================");
                printf("\n1. Calcular Comisiones");
                /*printf("\n2. Liquidar Vacaciones");
                printf("\n3. Liquidar Aguinaldo");*/
                printf("\n===============================");
                printf("\n0. Salir");
                printf("\n===============================");
                E = optionValid();

                switch(E)
                {
                case 1:
                    list->map(list,calcComision);
                    showVendedoresComisiones(list);
                    //calcularComision(list);
                    break;
                case 2:

                    break;
                case 3:

                    break;
                }
            }
            while(E != 0);
            break;

        case 6:
            saveVendedor("DATA.csv",list);
            saveVendedorComisiones("DATA1.csv",list);
            break;
        }
    }
    while(option != 0);

    return 0;
}
