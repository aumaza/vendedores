#include "ArrayList.h"
#include "misFunciones.h"
#include "vendedores.h"
#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//CONSTRUCTORES
//===============================================================

Vendedores* newVendedor()
{
    Vendedores* newVendedor = (Vendedores*)malloc(sizeof(Vendedores));

    if(newVendedor != NULL)
    {
        newVendedor->id = 0;
        strcpy(newVendedor->nombreVendedor,"");
        newVendedor->nivel = 0;
        newVendedor->cantProductos = 0;
        newVendedor->montoVendido = 0;
        newVendedor->comision = 0;
        newVendedor->isEmpty = 0;
    }
    return newVendedor;
}

//CARGA DE DATOS
//=================================================

void addVendedor(ArrayList* lista)
{
    osDetect(SO);
    Vendedores* oneVendedor;
    int id = searchFreeVendedor(lista);

    oneVendedor = newVendedor();

    if(oneVendedor != NULL)
    {
        oneVendedor->id = id+2;

        printf("\nIngrese el Nombre: ");
        fflush(stdin);
        fgets(oneVendedor->nombreVendedor,30,stdin);
        removeNewLine(oneVendedor->nombreVendedor);
        strupper(oneVendedor->nombreVendedor);

        printf("\nIngrese Nivel: ");
        fflush(stdin);
        scanf("%d",&oneVendedor->nivel);
        getchar();

        printf("\nIngrese Cantidad de Productos Vendidos: ");
        fflush(stdin);
        scanf("%d", &oneVendedor->cantProductos);
        getchar();

        printf("\nIngrese Monto Vendido: ");
        fflush(stdin);
        scanf("%f", &oneVendedor->montoVendido);
        getchar();

        oneVendedor->isEmpty = 1;

        lista->add(lista,oneVendedor);
    }

}

//BUSCA LIBRE

int searchFreeVendedor(ArrayList* lista)
{
    int index = -1;
    Vendedores* unVendedor;

    for(int i=0; i<lista->len(lista); i++)
    {
        unVendedor = (Vendedores*)lista->get(lista,i);

        if(unVendedor->id < 0 || unVendedor->id == lista->len(lista))
        {
            index = i;
            break;
        }
    }
    return index;
}


//LISTADO BASICO
//==========================================

void mostrarUnVendedor(Vendedores* pVendedor)
{
    printf("\n%d", pVendedor->id);
    printf("\t%16s", pVendedor->nombreVendedor);
    printf("\t%10d", pVendedor->nivel);
    printf("\t%10d", pVendedor->cantProductos);
    printf("\t%10.2f", pVendedor->montoVendido);
}

void mostrarVendedoresComision(Vendedores* pVendedor)
{
    printf("\n%d", pVendedor->id);
    printf("\t%16s", pVendedor->nombreVendedor);
    printf("\t%10d", pVendedor->nivel);
    printf("\t%10d", pVendedor->cantProductos);
    printf("\t%10.2f", pVendedor->montoVendido);
    printf("\t%10.2f", pVendedor->comision);
}

//LISTADO COMPLETO
//===========================================================
void showVendedores(ArrayList* lista)
{
    osDetect(SO);
    int count = 0;
    Vendedores* unVendedor;

    header1();
    for(int i=0; i<lista->len(lista); i++)
    {
        unVendedor = (Vendedores*)lista->get(lista,i);

        if(unVendedor->isEmpty == 1)
        {
            mostrarUnVendedor(unVendedor);
            count++;
        }
    }

    footer1();
    printf("\nHay %d Vendedores", count);
    footer1();

    wait(SO);
}

void showVendedoresComisiones(ArrayList* lista)
{
    osDetect(SO);
    int count = 0;
    Vendedores* unVendedor;

    header2();

    for(int i=0; i<lista->len(lista); i++)
    {
        unVendedor = (Vendedores*)lista->get(lista,i);

        if(unVendedor->isEmpty == 1)
        {
            mostrarVendedoresComision(unVendedor);
            count++;
        }
    }
    footer2();
    printf("\nHay %d Vendedores", count);
    footer2();

    wait(SO);
}

void showVendedorAlfabetico(ArrayList* lista)
{
    lista->sort(lista,cmpVendedorName,1);
    header2();
    showVendedoresComisiones(lista);
    footer2();

}

void showVendedorMonto(ArrayList* lista)
{
    lista->sort(lista,cmpVendedorMonto,1);
    header2();
    showVendedoresComisiones(lista);
    footer2();
}

//PERSISTENCIA
//============================================================

void saveVendedor(char* path, ArrayList* lista)
{
    FILE* fp;
    fp=fopen(path,"w");
    Vendedores* nVendedor;

    if(fp != NULL)
    {
        fprintf(fp,HEADER_VENDE);

        for(int i=0; i<lista->len(lista); i++)
        {
            nVendedor = (Vendedores*)lista->get(lista,i);
            fprintf(fp,MASC_VENDE,nVendedor->id,nVendedor->nombreVendedor,nVendedor->nivel,nVendedor->cantProductos,nVendedor->montoVendido,nVendedor->isEmpty);

        }
        fclose(fp);
    }
}

int saveVendedorComisiones(char* path, ArrayList* lista)
{
    int aux = -1;
    FILE* fp;
    fp=fopen(path,"w");
    Vendedores* nVendedor;

    if(fp != NULL)
    {
        fprintf(fp,HEADER_VENDE_C);

        for(int i=0; i<lista->len(lista); i++)
        {
            nVendedor = (Vendedores*)lista->get(lista,i);

            fprintf(fp,MASC_VENDE_C,nVendedor->id,nVendedor->nombreVendedor,nVendedor->nivel,nVendedor->cantProductos,nVendedor->montoVendido,nVendedor->comision,nVendedor->isEmpty);

        }
        aux = 1;
        fclose(fp);
    }
    return aux;
}

//CARGADOR DE DATOS
void VendedorParser(char* path, ArrayList* lista)
{
    FILE* fp;

    Vendedores* nVendedor;

    int cant;
    char buffer[6][128];
    fp = fopen(path, "a+");

    if(fp != NULL && lista != NULL)
    {
        fscanf(fp,MASCARA_VENDE,BUFFER_VENDE);

        while(!feof(fp))
        {
            cant = fscanf(fp,MASCARA_VENDE,BUFFER_VENDE);

            if( cant == 6)
            {
                nVendedor = newVendedor();

                if(nVendedor != NULL)
                {
                    nVendedor->id = atoi(buffer[0]);
                    strcpy(nVendedor->nombreVendedor,buffer[1]);
                    nVendedor->nivel = atoi(buffer[2]);
                    nVendedor->cantProductos = atoi(buffer[3]);
                    nVendedor->montoVendido = atof(buffer[4]);
                    nVendedor->isEmpty = atoi(buffer[5]);

                    lista->add(lista,nVendedor);
                }
            }
            else
            {
                break;
            }
        }
        fclose(fp);
    }
}


void VendedorComisionParser(char* path, ArrayList* lista)
{
    FILE* fp;

    Vendedores* nVendedor;

    int cant;
    char buffer[7][128];
    fp = fopen(path, "a+");

    if(fp != NULL && lista != NULL)
    {
        fscanf(fp,MASCARA_VENDE_C,BUFFER_VENDE_C);

        while(!feof(fp))
        {
            cant = fscanf(fp,MASCARA_VENDE_C,BUFFER_VENDE_C);

            if( cant == 7)
            {
                nVendedor = newVendedor();

                if(nVendedor != NULL)
                {
                    nVendedor->id = atoi(buffer[0]);
                    strcpy(nVendedor->nombreVendedor,buffer[1]);
                    nVendedor->nivel = atoi(buffer[2]);
                    nVendedor->cantProductos = atoi(buffer[3]);
                    nVendedor->montoVendido = atof(buffer[4]);
                    nVendedor->comision = atof(buffer[5]);
                    nVendedor->isEmpty = atoi(buffer[6]);

                    lista->add(lista,nVendedor);
                }
            }
            else
            {
                break;
            }
        }
        fclose(fp);
    }
}

//CALCULO COMISION
//===============================================================

int calcularComision(ArrayList* lista)
{
    osDetect(SO);
    int flag = 0;
    Vendedores* oneVendedor;
    float comision = 0;


    printf("\n     Vendedor     Comision");
    printf("\n=======================================");

    for(int i=0; i<lista->len(lista); i++)
    {
        oneVendedor = (Vendedores*)lista->get(lista,i);

        if(oneVendedor->nivel == JUNIOR && oneVendedor->isEmpty == 1)
        {
            comision = oneVendedor->montoVendido * 0.02;
            oneVendedor->comision = comision;
            flag = 1;

        }

        else if((oneVendedor->nivel == STANDART || oneVendedor->nivel == EXPERT))
        {
            if(oneVendedor->cantProductos < 100)
            {
                comision = oneVendedor->montoVendido * 0.035;
                oneVendedor->comision = comision;
                flag = 1;
            }

            if(oneVendedor->cantProductos > 100)
            {
                comision = oneVendedor->montoVendido * 0.05;
                oneVendedor->comision = comision;
                flag = 1;
            }

        }

        printf("\n%12s", oneVendedor->nombreVendedor);
        printf("\t%10.2f", oneVendedor->comision);
    }
    printf("\n=======================================");
    if(flag == 1)
    {
        printf("\nCALCULO DE COMISION FINALIZAD0 CON EXITO\n");
    }
    wait(SO);
    return 0;
}


int selectVendedor(ArrayList* lista)
{
    int dato;
    Vendedores* oneVendedor;

    header1();
    for(int i=0; i<lista->len(lista); i++)
    {
        oneVendedor = (Vendedores*)lista->get(lista,i);

        if(oneVendedor->isEmpty == 1)
        {
            mostrarUnVendedor(oneVendedor);
        }
    }
    dato = getInt("SELECCIONE UN VENDEDOR: ","VENDEDOR INEXISTENTE",1,lista->len(lista),5);
    return dato;
}


void VendedorComisionNivel(ArrayList* lista)
{
    osDetect(SO);

    Vendedores* oneVendedor;
    int flag = 0;
    int counter = 0;
    int nivel = selectLevel();

    header2();
    for(int i=0; i<lista->len(lista); i++)
    {
        oneVendedor = (Vendedores*)lista->get(lista,i);

        switch(nivel)
        {
        case JUNIOR:

            if(oneVendedor->nivel == JUNIOR)
            {

                mostrarVendedoresComision(oneVendedor);
                //saveVendedorComisiones("DATA_LEVEL_0.csv",lista->filter(lista,getLevel1));
                counter++;
                flag = 1;
                break;
            }
            break;


        case STANDART:

            if(oneVendedor->nivel == STANDART)
            {
                mostrarVendedoresComision(oneVendedor);
                //saveVendedorComisiones("DATA_LEVEL_1.csv",lista->filter(lista,getLevel1));
                counter++;
                flag = 1;
            }
            break;

        case EXPERT:

            if(oneVendedor->nivel == EXPERT)
            {
                mostrarVendedoresComision(oneVendedor);
                saveVendedorComisiones("DATA_LEVEL_2.csv", lista);
                counter++;
                flag = 1;
            }
            break;
        }
    }

    footer2();
    printf("\nHay %d Vendedores en el nivel %d", counter, nivel);

    if(flag == 1)
    {
        printf("\nDATOS GUARDADOS EXITOSAMENTE!");
        footer2();
    }
    wait(SO);

}



int selectLevel()
{
    osDetect(SO);
    int aux;
    printf("\nIngrese el Nivel(1 - JUNIOR / 2 - STANDART / 3 - EXPERT): ");

    int dato = optionValid();

    switch(dato)
    {
    case 1:
        aux = 0;
      break;

    case 2:
        aux = 1;
        break;

    case 3:
        aux = 2;
        break;

    }

    return aux;
}


//COMPARADORES
//==============================================================

int cmpVendedorNivel(void* x, void* y)
{

    Vendedores* vend1 = (Vendedores*)x;
    Vendedores* vend2 = (Vendedores*)y;

    int retorno;

    if(vend1->nivel == vend2->nivel)
    {

        retorno = 0;
    }
    else if(vend1->nivel > vend2->nivel)
    {

        retorno = 1;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}


int cmpVendedorLevel(Vendedores* pVendedores)
{

    int retorno = -1;

    if((pVendedores->nivel == 0) || (pVendedores->nivel == 1) || (pVendedores->nivel == 2))
    {
        retorno = 1;
    }

    return retorno;
}


int cmpVendedorName(void* x, void* y)
{

    Vendedores* vende1 = (Vendedores*)x;
    Vendedores* vende2 = (Vendedores*)y;

    return strcmp(vende1->nombreVendedor, vende2->nombreVendedor);

}

int cmpVendedorMonto(void* x, void* y)
{

    Vendedores* vende1 = (Vendedores*)x;
    Vendedores* vende2 = (Vendedores*)y;

    int retorno;

    if(vende1->montoVendido == vende2->montoVendido)
    {

        retorno = 0;
    }
    else if( vende1->montoVendido > vende2->montoVendido)
    {

        retorno = 1;
    }
    else
    {
        retorno = -1;
    }

    return retorno;

}


void vendeMax(ArrayList* lista)
{
    Vendedores* oneVendedor;
    Vendedores* maxVendedor;
    osDetect(SO);

    float maxMonto = 0;
    printf("\nVENDEDOR CON MAYOR FACTURACION");
    header2();
    for(int i=0; i<lista->len(lista); i++)
    {
        oneVendedor = (Vendedores*)lista->get(lista,i);


        if(maxMonto < oneVendedor->montoVendido)
        {
            maxMonto = oneVendedor->montoVendido;
            maxVendedor = oneVendedor;

        }
    }

    mostrarVendedoresComision(maxVendedor);
    footer2();

    wait(SO);
}


void vendedoresMasGanadoresNivel(ArrayList* lista)
{
    osDetect(SO);
    float maxMonto = 0;
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;
    int suma = 0;

    Vendedores* oneVendedor;
    header2();
    for(int i=0; i<lista->len(lista); i++)
    {
        oneVendedor = (Vendedores*)lista->get(lista,i);

        if(oneVendedor->montoVendido > maxMonto && oneVendedor->nivel == JUNIOR)
        {
            maxMonto = oneVendedor->montoVendido;
            mostrarVendedoresComision(oneVendedor);
            counter++;

        }

        if(oneVendedor->montoVendido > maxMonto && oneVendedor->nivel == STANDART)
        {
            maxMonto = oneVendedor->montoVendido;
            mostrarVendedoresComision(oneVendedor);
            counter1++;

        }

        if(oneVendedor->montoVendido > maxMonto && oneVendedor->nivel == EXPERT)
        {
            maxMonto = oneVendedor->montoVendido;
            mostrarVendedoresComision(oneVendedor);
            counter2++;

        }

    }
    suma = counter+counter1+counter2;
    footer2();
    printf("\nHay %d Vendedores que mas Facturaron", suma);
    printf("\n%d son del nivel JUNIOR", counter);
    printf("\n%d son del nivel STANDART", counter1);
    printf("\n%d son del nivel EXPERT", counter2);
    footer2();


    wait(SO);
}


void header1()
{
    printf("\n=====================================================================================");
    printf("\nID          NOMBRE VENDEDOR            NIVEL       PRODUCTOS      FACTURADO");
    printf("\n=====================================================================================");
}


void header2()
{
    printf("\n====================================================================================================");
    printf("\nID          NOMBRE VENDEDOR            NIVEL       PRODUCTOS      FACTURADO        COMISION");
    printf("\n====================================================================================================");
}

void footer1()
{
    printf("\n=====================================================================================");
}

void footer2()
{
    printf("\n====================================================================================================");
}

int calcComision(Vendedores* oneVendedor)
{
    //int flag = 0;
    float comision = 0;

    if(oneVendedor->nivel == JUNIOR && oneVendedor->isEmpty == 1)
    {
        comision = oneVendedor->montoVendido * 0.02;
        oneVendedor->comision = comision;
    }

    else if((oneVendedor->nivel == STANDART || oneVendedor->nivel == EXPERT))
    {
        if(oneVendedor->cantProductos < 100)
        {
            comision = oneVendedor->montoVendido * 0.035;
            oneVendedor->comision = comision;
        }

        if(oneVendedor->cantProductos > 100)
        {
            comision = oneVendedor->montoVendido * 0.05;
            oneVendedor->comision = comision;
        }
    }
    return 0;
}


int getLevel1(Vendedores* x)
{
    int aux = -1;

    //Vendedores* pVendedor = (Vendedores*)x;

    if(x->nivel == JUNIOR)
    {
        aux = 1;
    }
    return aux;
}

int getLevel2(Vendedores* x)
{

    int aux = -1;

    //Vendedores* pVendedor = (Vendedores*)x;

    if(x->nivel == STANDART)
    {
        aux = 1;
    }
    return aux;
}

int getLevel3(Vendedores* x)
{
    int aux = -1;
    //Vendedores* pVendedor = (Vendedores*) x;

    if(x->nivel == EXPERT)
    {
        aux = 1;
    }

    return aux;
}

void VendedorNivel(ArrayList* lista)
{
    osDetect(SO);

    int flag = 0;
    int counter = 0;
    int nivel = selectLevel();

    header2();

    switch(nivel)
    {
    case 0:

        if(saveVendedorComisiones("JUNIOR.csv",lista->filter(lista,cmpVendedorLevel)) == 1)
        {

            showVendedoresComisiones(lista->filter(lista,cmpVendedorLevel));
            counter++;
            flag = 1;
        }
        break;


    case 1:

        if(saveVendedorComisiones("STANDART.csv",lista->filter(lista,cmpVendedorLevel)) == 1)
            {
                showVendedoresComisiones(lista->filter(lista,cmpVendedorLevel));
                counter++;
                flag = 1;
            }
        break;

    case 2:

        if(saveVendedorComisiones("EXPERT.csv",lista->filter(lista,cmpVendedorLevel)) == 1)
        {
            showVendedoresComisiones(lista->filter(lista,cmpVendedorLevel));
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

}
