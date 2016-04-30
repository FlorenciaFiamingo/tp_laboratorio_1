typedef struct
{
    char nombre[31];
    char apellido[31];
    long int dni;
    int edad;
    int isEmpty;

} ePersona;

int menu();
void iniciar(ePersona[], int );
void altaItem(ePersona[], int );
void ordenarNombre(ePersona[],int);
void bajaItem(ePersona[],int);
void graficoEdad(ePersona personas[], int largo);
int getEdad(int* num, char mensaje[], char msgError[]);
int getLong (long int * doc, char mensaje[], char mensajeError[]);
int validarMenu (int* numOp, char mensaje[], char msgError[]);
