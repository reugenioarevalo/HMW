#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "proyecto.h"

int main(){
    short opcion;
    do{
        cout<<"\t MENU";
        cout<<endl<<"---------------------------";
        cout<<endl<<"1_ animales";
        cout<<endl<<"2_ mostrar todos animales";
        cout<<endl<<"3_ avistajes";
        cout<<endl<<"4_ mostrar todos avistajes";
        cout<<endl<<"5_ Punto A";
        cout<<endl<<"6_ Punto B";
        cout<<endl<<"7_ Punto C";
        cout<<endl<<"8_ Punto D";
        cout<<endl<<"9_ Punto E";
        cout<<endl<<"10_ Punto F";
        cout<<endl<<"11_ Punto G";
        cout<<endl<<"12_ SALIR";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t OPCION: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            AnimalesCargar();
            system ("pause");
            system ("cls");
        break;
        case 2:
            MostrarAnimales();
            system ("pause");
            system ("cls");
        break;
        case 3:
            CargarAvistajes();
            system ("pause");
            system ("cls");
        break;
        case 4:
            MostrarAvistajes();
            system ("pause");
            system ("cls");
        break;
        case 5:
            PuntoA();
            system ("pause");
            system ("cls");
        break;
        case 6:
            puntoB();
            system ("pause");
            system ("cls");
        break;
        case 7:
            puntoC();
            system ("pause");
            system ("cls");
        break;
        case 8:
            puntoD();
            system ("pause");
            system ("cls");
        break;
        case 9:
            puntoE();
            system ("pause");
            system ("cls");
        break;
        case 10:
            puntoF();
            system ("pause");
            system ("cls");
        break;
        case 11:
            puntoG();
            system ("pause");
            system ("cls");
        break;
        case 12:
            cout<<endl<<"\t Gracias Hasta luego"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        default:
            cout<<endl<<"\t Opcion incorrecta"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        }
    }while (opcion!=12);
return 0;
}
