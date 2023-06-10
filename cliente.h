#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>

#include "Compra.h"

using namespace std;

class Cliente {
private:                
    string nombre;     
    vector<Compra *> compras;

public:             
    Cliente();
    Cliente(string);

    void setNombre(string);

    string getNombre();

    void agregarCompraEfectivo(int, int, string, int, int);
    void agregarCompraTarjeta(int, int, string, int);

    Compra* buscarCompra(int);
    
    void mostrarCompras();
};

Cliente::Cliente() {
    nombre = "";
}
Cliente::Cliente(string nombre) {
    this->nombre = nombre;
}

void Cliente::setNombre(string nombre) { this->nombre = nombre; }

string Cliente::getNombre() { return nombre; }

void Cliente::agregarCompraEfectivo(int id, int monto, string metodoPago, int conPago, int cambio){
    Compra *c = new Compra_Efectivo(id, monto, metodoPago, conPago, cambio);
    compras.push_back(c);
}

void Cliente::agregarCompraTarjeta(int id, int monto, string metodoPago, int iva){
    Compra *c = new Compra_Tarjeta(id, monto, metodoPago, iva);
    compras.push_back(c);
}

Compra* Cliente::buscarCompra(int id){
    for(Compra *compra : compras){
        if(compra->getIdCompra() == id){
            return compra;
        }
    }
    return nullptr;
}

void Cliente::mostrarCompras(){
    for(Compra *compra : compras){
        cout << "\n";
        compra->mostrarDatosPago();
        cout << "\n";
    }
}

#endif

//