#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include "archivos.h"
#include "estructura.h"

int NoSeVieron(){
    int cont=0;
    animales uno;
    FILE *p=fopen("Animales.dat","rb");
    if(p==NULL){
        cout<<"error";
        fclose(p);
        return -1;
    }
    while(fread(&uno, sizeof(animales),1,p)){
        if (uno.estado==false){
            cont++;
        }
    }
    fclose(p);
return cont;
}

animales TraerA(int *pos){
    animales uno;
    FILE *p=fopen("Animales.dat","rb");
    if(p==NULL){
        cout<<"error";
        fclose(p);
        uno.CodigoAnimal=-1;
        return uno;
    }
    fseek(p, *pos*sizeof(animales), SEEK_SET);
    while(fread(&uno, sizeof(animales),1,p)){
        if (uno.estado==false){
            fclose(p);
            return uno;
        }
        pos++;
        cout<<pos;
    }
    fclose(p);
uno.CodigoAnimal=-1;
return uno;
}
