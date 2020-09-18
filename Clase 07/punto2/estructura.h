#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

struct fecha{
    int dia, mes, anio;
};

struct animales{
    bool estado;
    int CodigoAnimal, ZonaHabitat;
    char nombre [30], clasificacion [5];
};

struct viajes{
    int CodigoAnimal,ZonaAvistada;
    fecha tiempo;
};

#endif // ESTRUCTURA_H_INCLUDED
