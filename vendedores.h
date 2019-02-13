#ifndef VENDEDORES_H_INCLUDED
#define VENDEDORES_H_INCLUDED

#define MASCARA_VENDE "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
#define BUFFER_VENDE buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]
#define HEADER_VENDE "ID,Nombre_Vendedor,Nivel,cantidad_productos,Monto_vendido,isEmpty\n"
#define MASC_VENDE "%d,%s,%d,%d,%f,%d\n"

#define MASCARA_VENDE_C "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
#define BUFFER_VENDE_C buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]
#define HEADER_VENDE_C "ID,Nombre_Vendedor,Nivel,cantidad_productos,Monto_vendido,comision,isEmpty\n"
#define MASC_VENDE_C "%d,%s,%d,%d,%f,%f,%d\n"


#define JUNIOR 0
#define STANDART 1
#define EXPERT 2


typedef struct{

    int id;
    char nombreVendedor[30];
    int nivel;
    int cantProductos;
    float montoVendido;
    float comision;
    int isEmpty;
}Vendedores;


//CONSTRUCTORES
Vendedores* newVendedor();

//ALTA
void addVendedor(ArrayList* lista);

//SELECCIONADOR
int selectVendedor(ArrayList* lista);
int selectLevel();
int getLevel1(Vendedores* x);
int getLevel2(Vendedores* x);
int getLevel3(Vendedores* x);

//BUSCA LIBRE
int searchFreeVendedor(ArrayList* lista);

//LISTADOS
void mostrarUnVendedor(Vendedores* pVendedor);
void mostrarVendedoresComision(Vendedores* pVendedor);
void showVendedores(ArrayList* lista);
void showVendedoresComisiones(ArrayList* lista);
void showVendedorAlfabetico(ArrayList* lista);
void showVendedorMonto(ArrayList* lista);
void vendeMax(ArrayList* lista);
void vendedoresMasGanadoresNivel(ArrayList* lista);


//PERSISTENCIA
void saveVendedor(char* path, ArrayList* lista);
int saveVendedorComisiones(char* path, ArrayList* lista);

//LOAD DATOS
void VendedorParser(char* path, ArrayList* lista);
void VendedorComisionParser(char* path, ArrayList* lista);

//CALCULO DE COMISION

int calcularComision(ArrayList* lista);
void VendedorComisionNivel(ArrayList* lista);
void VendedorNivel(ArrayList* lista);
int calcComision(Vendedores* oneVendedor);

int cmpVendedorNivel(void* x, void* y);
int cmpVendedorName(void* x, void* y);
int cmpVendedorMonto(void* x, void* y);
int cmpVendedorLevel(Vendedores* pVendedores);


void header1();
void header2();
void footer1();
void footer2();



#endif // VENDEDORES_H_INCLUDED
