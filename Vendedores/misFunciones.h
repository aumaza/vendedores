#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

#ifdef __linux__
#define SO "Linux"
#elif _WIN32
#define SO "Windows"
#elif _WIN64
#define SO "MsWindows"
#endif

typedef struct
{
  int dia;
  int mes;
  int anio;
}Fecha;

char stringlwr(char *str);
char strupper(char *str);
void removeNewLine(char* string);
void removeNewLines(char* string);
void upInitialCharString (char *str);
void sortVectorUp(char vec[], int tam);
void sortVectorDown(char vec[], int tam);
void sortVectorChar(char vec[], int tam);
int getInt(char msj[], char error[], int limInf, int limSup, int attemp);
int optionMain();
void getString(char* string, int lengh);
void osDetect(char* string);
void wait(char* string);
int optionValid();
int intValid(char* string);
int openFileReadAppend(char* string);
int openFileWrite(char* string);
int validNULL(void* string);
char localDate();
int calculoAntiguedad(Fecha fecha1);
int regularBisiesto(int anio);
int numeroBisiestos(int anio);
int diaDelAnio(Fecha fecha);


#endif // MISFUNCIONES_H_INCLUDED
