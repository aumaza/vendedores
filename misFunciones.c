#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include "misFunciones.h"


/** \brief Funcion strlwr
 *
 * \param convierte todos los caracteres de un string a minuscula.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string en letras minusculas.-
 *
 */


char stringlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p)

   {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return 0;
}


/** \brief Funcion strupper
 *
 * \param convierte todos los caracteres de un string a mayuscula.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string en letras mayusculas.-
 *
 */

char strupper(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p)
  {
     *p = toupper((unsigned char)*p);
      p++;
  }

  return 0;
}

/** \brief Funcion removeNewLine
 *
 * \param mide la longitud de un string y elimina el caracter de salto de carro del final.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string con el caracter de salto de carro eliminado.-
 *
 */

void removeNewLine(char* string)

{
  size_t length;

  if( (length = strlen(string) ) >0)
  {
       if(string[length-1] == '\n')
                string[length-1] ='\0';
  }
}


/** \brief removeNewLines
 *
 * \param mide la longitud de un string y elimina los caracteres de salto de carro del final.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string con los caracteres de salto de carro eliminados.-
 *
 */

void removeNewLines(char* string)

{
  size_t length = strlen(string);

  while(length>0)

  {
       if(string[length-1] == '\n')
       {
                --length;
                string[length] ='\0';
       }
       else
           break;
  }

}

/** \brief Funcion upInitialCharString
 *
 * \param convierte el caracter inicial de un string a mayuscula.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string con el primer caracter en mayuscula.-
 *
 */

void upInitialCharString (char *str)

{
int i;
int length_string;

length_string = strlen(str);


for(i=0; i<length_string; i++)
    {
        str[0] = toupper(str[0]);

        if(str[i] == ' ')
        {
            str[i+1] = toupper(str[i+1]);
        }
    }

}

/** \brief Funcion sortVectorUp
 *
 * \param ordena los caracteres en orden ascendente.-
 * \param recibe un array de caracteres.-
 * \return Devuelve el array de caracteres ordenado del primero al ultimo de acuerdo a como fueron ingresados.-
 *
 */

void sortVectorUp(char vec[], int tam)
{
    int i;

    printf("\n\nEn orden Ascendente");
    printf("\n==========================\n\n");

    for(i=0; i<tam; i++)
    {

         printf("%c ", vec[i]);
    }
}

/** \brief Funcion sortVectorDown
 *
 * \param ordena los caracteres en orden descendente.-
 * \param recibe un array de caracteres.-
 * \return Devuelve el array de caracteres ordenado del ultimo al primero de acuerdo a como fueron ingresados.-
 *
 */

void sortVectorDown(char vec[], int tam)
{
    int i;

printf("\n\nEn orden descendente");
printf("\n==========================\n\n");

   for(i=tam-1; i>=0; i--)
    {

         printf("%c ", vec[i]);
    }
}

/** \brief Funcion sortVectorChar
 *
 * \param ordena los caracteres en orden de mayor a menor.-
 * \param recibe un array de caracteres.-
 * \return Devuelve el array de caracteres ordenado de mayor a mennor de acuerdo a su valor en la tabla ASCII.-
 *
 */

void sortVectorChar(char vec[], int tam)
{
    char aux;
    int i;
    int j;


    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
           if(vec[i] < vec[j])
           {
               aux = vec[i];
               vec[i] = vec[j];
               vec[j] = aux;
           }
        }
    }
}

/** \brief Funcion getInt
 *
 * \param valida valores ingresados dentro de determinados rangos.-
 * \param recibe mesaje de ingreso de datos.-
 * \param recibe mensaje de error.-
 * \param recibe el limite inferior y superior del rango a determinar.-
 * \param recibe la cantidad de intentos permitidos.-
 * \return devuelve el valor correcto ingresado.-
 *
 */

int getInt(char msj[], char error[], int limInf, int limSup, int attemp)
{
    int dato;
    int flag=0;

    printf("\n%s", msj);
    scanf("%d", &dato);

    while((dato<limInf || dato>limSup) && (attemp>0))
    {
        printf("\n=======================================");
        printf("\n%s", error);
        printf("\n=======================================\n");
        attemp--;

        printf("\n%s", msj);
        scanf("%d", &dato);
        flag=1;

    }

    if(flag==1)
    {
        printf("\n=====================================");
        printf("\nHA EXCEDIDO LA CANTIDAD DE INTENTOS");
        printf("\n=====================================");
        return EXIT_FAILURE;
    }

     if(flag==0)
    {
        printf("\n=====================================");
        printf("\nUSTED INGRESO: %d", dato);
        printf("\n=====================================");

    }
return dato;
}

/** \brief optionMain Function
 *
 * \param prompt the options the task to do, in a numeric main
 * \param call to the available functions
 * \return the action request in main selection.
 *
 */


int optionMain()
{
osDetect(SO);


int opc;

do{
osDetect(SO);

//Employee list, *pEmployee;
//pEmployee = &list;

printf("\n======================================");
printf("\nSeleccione la Operacion a Realizar");
printf("\n======================================\n");
printf("\n1. Altas");
printf("\n2. Modificar");
printf("\n3. Baja");
printf("\n4. Informes");
printf("\n5. Salir");
printf("\n\n======================================\n");

opc=optionValid();
printf("\n======================================\n");

switch(opc)
{

case 1:  break;
case 2:  break;
case 3:  break;
case 4:  break;

}
}while(opc != 5);

return 0;

}

/** \brief Funcion getString
 *
 * \param recibe una cadena de caracteres.-
 * \param recibe como parametro un puntero a string.-
 * \param recibe la longitud de la cadena de caracteres (cantidad de caracteres+1 caracter del salto de carro).-
 * \return no devuelve nada.-
 *
 */

void getString(char* string, int lengh)
{
char String[lengh];

fgets(String, lengh, stdin);
fflush(stdin);


}

/** \brief Funcion osDetect
 *
 * \param recibe una cadena de caracteres.-
 * \param compara la cadena, si es Linux usa un comando, si es Windows, usa otro comando.-
 * \return no devuelve nada.-
 *
 */


void osDetect(char* string)
{


    if(strcmp(string,"Linux")==0)
    {
        system("clear");
    }

    if(strcmp(string,"Windows")==0)
    {
        system("cls");

    }

      if(strcmp(string,"MsWindows")==0)
    {
        system("cls");
    }

}

void wait(char* string)
{

    if(strcmp(string,"Linux")==0)
    {

    printf("\nPresione una tecla para continuar...");
    getchar();
    getchar();

    }

    if(strcmp(string,"Windows")==0)
    {
        system("pause");
    }

    if(strcmp(string,"MsWindows")==0)
    {
        system("pause");
    }



}


int optionValid()
{
   int ok;
   int ch;
   int opc;

    do
    {
      printf("\nOpcion: ");
      fflush(stdout);
      if ((ok = scanf("%d", &opc)) == EOF)
         return 1;


      if ((ch = getchar()) != '\n')
      {
         ok = 0;

         while ((ch = getchar()) != EOF && ch != '\n');
      }
   }while(!ok);

   return opc;
}


int intValid(char* string)
{
   int ok;
   int ch;
   int num;

    do
    {
      printf("%s: ", string);
      fflush(stdout);
      if ((ok = scanf("%d", &num)) == EOF)
         return 1;


      if ((ch = getchar()) != '\n')
      {
         ok = 0;

         while ((ch = getchar()) != EOF && ch != '\n');
      }
   }while(!ok);

   return num;
}



int openFileReadAppend(char* string)
{
    FILE *pArch;

    if((pArch=fopen("string","a+"))==NULL)
    {
        printf("\nNO ES POSIBLE ABRIR EL ARCHIVO!!");
        return 1;
    }

    if((fclose(pArch))==-1)
    {
        printf("\nNO ES POSIBLE CERRAR EL ARCHIVO!!");
    }

    else
    {
        printf("\nEL ARCHIVO SE CERRO CON EXITO!!");
    }

    return 0;
}



int openFileWrite(char* string)
{
    FILE *pArch;

    if((pArch=fopen("string","w"))==NULL)
    {
        if((pArch=fopen("string","w"))==NULL)
        {
            printf("\nNO ES POSIBLE ABRIR EL ARCHIVO!!");
            return 1;
        }

        fclose(pArch);
    }

    return 0;
}

int validNULL(void* string)
{

if(string == NULL)
{
return 1;
}

else
{
printf("SUCCESS!!");
return 0;
}
}


char localDate()
{
    time_t date = time(NULL);
    struct tm *tlocal = localtime(&date); //estructura donde obtengo el tiempo
    char output[11]; //array donde guardo la fecha

    strftime(output,11,"%d/%m/%Y",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
    printf("%s\n",output);
    return 0;
}

//=================================================================================

int calculoAntiguedad(Fecha fecha1)
{
    Fecha fecha2;
    int difDias = 0;
    int anios = 0;
    time_t t;
    struct tm *tm;
    t=time(NULL);
    tm=localtime(&t);

    fecha2.dia = tm->tm_mday;
    fecha2.mes = tm->tm_mon+1;
    fecha2.anio = 1900+tm->tm_year;

    // Cálculo del intervalo fecha1 -> fecha2
    // no se tienen en cuenta los años en este punto porque la corrección se realiza después


    difDias = diaDelAnio( fecha2 ) - diaDelAnio( fecha1 );

    if( fecha1.anio != fecha2.anio )
    {
        // Días por los años completos
        difDias += (fecha2.anio - fecha1.anio - 1) * 365;
        difDias += numeroBisiestos(fecha2.anio - 1) - numeroBisiestos(fecha1.anio);

        // Cálculo correspondiente al intervalo fecha1 -> fin año fecha1
        fecha1.dia = 31;
        fecha1.mes = 12;
        difDias += diaDelAnio( fecha1 );
        anios = difDias / 365;
    }

    return anios;
}

int regularBisiesto( int anio)
{
    return ((anio%4 == 0 && anio%100 != 0) || (anio%400) == 0);
}

int numeroBisiestos( int anio )
{
    return anio / 4 - anio / 100 + anio / 400;
}

int diaDelAnio( Fecha fecha )
{
    int tot_dias[] = { 00,31,28,31,30,31,30,31,31,30,31,30,31 };

    int dias = fecha.dia;
    int mes;

    for( mes = 1; mes < fecha.mes; ++mes )
    {
        dias += tot_dias[mes];

        if( fecha.mes > 2 )
        {
            dias += regularBisiesto( fecha.anio );
        }
    }
    return dias;
}




