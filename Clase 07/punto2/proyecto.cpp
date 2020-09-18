#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "proyecto.h"
#include "estructura.h"
#include "archivos.h"

void AnimalesCargar(){
    animales uno;
    cout<<"Ingrese codigo de animal: ";
    cin>>uno.CodigoAnimal;
    cout<<"Ingrese el nombre: ";
    cin.ignore();
    cin.getline(uno.nombre, 30, '\n');
    cout<<"Ingrese la clasificacion: ";
    cin.getline(uno.clasificacion, 30, '\n');
    cout<<"Ingrese la zona de habitat: ";
    cin>>uno.ZonaHabitat;
    uno.estado=true;
    ///guardamos
    FILE *p=fopen("Animales.dat","ab");
    if(p==NULL){
        cout<<"error";
        fclose(p);
        return;
    }
    fwrite(&uno, sizeof(animales),1,p);
    fclose(p);
return;
}

void MostrarAnimales(){
    animales uno;
    FILE *p=fopen("Animales.dat","rb");
    if(p==NULL){
        cout<<"error";
        fclose(p);
        return;
    }
    while(fread(&uno, sizeof(animales),1,p)){
        if (uno.estado==true){
            cout<<"Ingrese codigo de animal: "<<uno.CodigoAnimal<<endl;
            cout<<"Ingrese el nombre: "<<uno.nombre<<endl;
            cout<<"Ingrese la clasificacion: "<<uno.clasificacion<<endl;
            cout<<"Ingrese la zona de habitat: "<<uno.ZonaHabitat<<endl;
        }
    }
    fclose(p);
}

void CargarAvistajes(){
    viajes uno;
    cout<<"Ingrese codigo de animal: ";
    cin>>uno.CodigoAnimal;
    cout<<"Ingrese la zona de avistada: ";
    cin>>uno.ZonaAvistada;
    cout<<"Ingrese la fecha de nacimiento"<<endl;
    cout<<"\t dia    : ";
    cin>>uno.tiempo.dia;
    cout<<"\t mes    : ";
    cin>>uno.tiempo.mes;
    cout<<"\tanio (4): ";
    cin>>uno.tiempo.anio;
    ///guardamos
    FILE *p=fopen("Avistajes.dat","ab");
    if(p==NULL){
        cout<<"error";
        fclose(p);
        return;
    }
    fwrite(&uno, sizeof(viajes),1,p);
    fclose(p);
}

void MostrarAvistajes(){
    viajes uno;
    FILE *p=fopen("Avistajes.dat","rb");
    if(p==NULL){
        cout<<"error";
        fclose(p);
        return;
    }
    while(fread(&uno, sizeof(viajes),1,p)){
        cout<<"Ingrese codigo de animal: "<<uno.CodigoAnimal<<endl;
        cout<<"Ingrese la zona de avistada: "<<uno.ZonaAvistada<<endl;
        cout<<"Ingrese la fecha de nacimiento"<<uno.tiempo.dia<<"/"<<uno.tiempo.mes<<"/"<<uno.tiempo.anio<<endl;
    }
    fclose(p);
}

void PuntoA(){
    int total;
    total=NoSeVieron();
    animales *uno=(animales *)malloc(total*sizeof(animales));
    int pos=0;
    for(int x=0;x<total;x++){
        uno[x]=TraerA(&pos);
        if(uno[x].CodigoAnimal==-1){
            cout<<"se pudrio todo";
            return;
        }
    }
    ///guardamos
    FILE *p=fopen("peligro.dat","ab");
    if(p==NULL){
        cout<<"error";
        fclose(p);
        return;
    }
    fwrite(&uno, sizeof(animales),total,p);
    fclose(p);
}

void puntoB(){
    animales uno;
    FILE *p=fopen("Animales.dat","rb");
    if(p==NULL){
        cout<<"error";
        fclose(p);
        return;
    }
    while(fread(&uno, sizeof(animales),1,p)){
        if(uno.ZonaHabitat>=3 && uno.ZonaHabitat<=5){
            cout<<"nombre: "<<uno.nombre<<endl;
        }
    }
    fclose(p);
}

void puntoC(){
    int cont=0;
    char palabra[]="erus";
    animales uno;
    FILE *p=fopen("Animales.dat","rb");
    if(p==NULL){
        fclose(p);
        return;
    }
    while(fread(&uno, sizeof(animales),1,p)){
        if(strcmp(uno.clasificacion, palabra)==0){
            cont++;
        }
    }
    cout<<"cantidad erus: "<<cont<<endl;
}

void puntoD(){
    int cont[12]={};
    viajes uno;
    FILE *p=fopen("Avistajes.dat","rb");
    if(p==NULL){
        fclose(p);
        return;
    }
    for(int x=0;x<12;x++){
        fseek(p, 0, SEEK_SET);
        while(fread(&uno,sizeof(viajes),1,p)){
            if(uno.tiempo.mes==x+1){
                cont[x]++;
            }
        }
        cout<<"en el anio "<<x+1<<" avistajes "<<cont[x]<<endl;
    }
    fclose(p);
}

void puntoE(){
    int cont[10][12]={};
    viajes uno;
    FILE *p=fopen("Avistajes.dat","rb");
    if(p==NULL){
        fclose(p);
        return;
    }
    while(fread(&uno,sizeof(viajes),1,p)){
        cont[uno.ZonaAvistada][uno.tiempo.mes]++;
    }
    for(int x=0;x<10;x++){
        for(int y=0;y<12;y++){
            cout<<"en la zona "<<x+1<<endl;
            cout<<"en el anio "<<y+1<<endl;
            cout<<"cantidad: "<<cont[x][y]<<endl;
        }
        cout<<endl<<endl;
    }
fclose(p);
}

void puntoF(){
    int cont[20]={};
    viajes uno;
    FILE *p=fopen("Avistajes.dat","rb");
    if(p==NULL){
        fclose(p);
        return;
    }
    while(fread(&uno,sizeof(viajes),1,p)){
        for(int x=2000;x<2020;x++){
            if(uno.tiempo.anio==x){
                cont[x-2000]=+1;
            }
        }
    }
    for(int x=0;x<20;x++){
        cout<<"en el anio "<<x+1<<" canitidad "<<cont[x]<<endl;
    }
fclose(p);
}

void puntoG(){
    int cont=0;
    char palabra[]="abcd";
    animales uno;
    FILE *p=fopen("Animales.dat","rb");
    if(p==NULL){
        fclose(p);
        return;
    }
    while(fread(&uno, sizeof(animales),1,p)){
        if(strcmp(uno.clasificacion, palabra)==0){
            cont++;
        }
    }
    cout<<"cantidad abcd: "<<cont<<endl;
}
