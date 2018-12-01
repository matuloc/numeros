#include <iostream>
#include <fstream>
#include <math.h>
#include <locale.h>
#define LOCALE_PROPIO "Spanish_Chile"

using namespace std;

//variables globales
double contador=0, notasFLoat=0, suma=0,media=0,varianza=0,desviacion;
string notasString;

//para contar, sumar y calcular promedio
void primera_lectura()
{
    setlocale(LC_NUMERIC, LOCALE_PROPIO);
    ifstream numeros("numeros.txt", ifstream::in);//se habre el archivo en modo lectura
    do
    {
        numeros>>notasString;
        notasFLoat=std::stof(notasString.c_str());
        suma+=notasFLoat;
        contador++;
    }
    while(!numeros.eof());//se comprueba de que no haya llegado al final
    numeros.close();
}

// para calcular desviacion estandar
void segunda_lectura()
{
    ifstream numeros("numeros.txt", ifstream::in);//se habre el archivo en modo lectura
    do
    {
        numeros>>notasString;
        notasFLoat=std::stof(notasString.c_str());
        varianza+=pow((notasFLoat - media), 2.0);
    }
    while(!numeros.eof());//se comprueba de que no haya llegado al final
    numeros.close();
}

int main()
{
    primera_lectura();
    media=suma/contador;
    segunda_lectura();
    desviacion=sqrt(varianza/(contador-1));
    cout<<"Cantidad de Notas: "<<contador<<"\n"<<"Suma: "<<suma<<"\n"<<"Media: "<<media<<"\n"<<"Desviacion: "<<desviacion<<endl;
}
