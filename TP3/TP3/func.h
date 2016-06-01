
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[1000];
    int estado;
}eMovie;

void iniciar(eMovie *movie, int largo);
int menu();
int validarMenu (int *numOp, char mensaje[], char msgError[]);
void altaItem(eMovie *movie, int largo);
void bajaItem(eMovie *movie,int largo);
int getMin(int* num, char mensaje[], char msgError[]);
int getIntP(int *num, char mensaje[], char msgError[]);
void generarPagWeb(eMovie *movie, int largo);
void guardarBin(eMovie *movie, int lenght);
void leerBin(eMovie *movie, int lenght);
 void modificarItem(eMovie *movie,int largo);
