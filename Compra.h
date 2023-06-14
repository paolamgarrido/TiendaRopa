#ifndef COMPRA_H
#define COMPRA_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "Producto.h"

using namespace std;

class Compra {
protected:
    int id;
    float monto;
    string metodoPago;
    vector<Producto *> productos;

public:
    Compra();
    Compra(int, float, string);

    void setIdCompra(int);
    void setMonto(float);
    void setMetodoPago(string);

    int getIdCompra();
    float getMonto();
    string getMetodoPago();

    virtual void mostrarDatosPago() = 0;

    void agregarProducto(Producto *);
    void mostrarProductos();
};

Compra::Compra() {
    id = 0;
    monto = 0.0f;
    metodoPago = "";
};

Compra::Compra(int id, float monto, string metodoPago) {
    this->id = id;
    this->monto = monto;
    this->metodoPago = metodoPago;
}

void Compra::setIdCompra(int id) { this->id = id; }
void Compra::setMonto(float monto) { this->monto = monto; }
void Compra::setMetodoPago(string metodoPago) { this->metodoPago = metodoPago; }

int Compra::getIdCompra() { return id; }
float Compra::getMonto() { return monto; }
string Compra::getMetodoPago() { return metodoPago; }

void Compra::agregarProducto(Producto *producto) {
    productos.push_back(producto);
}

void Compra::mostrarProductos() {
    for (Producto *producto : productos) {
        producto->mostrarProductos();
    }
}

class Compra_Efectivo : public Compra {
private:
    float conPago;
    float cambio;

public:
    Compra_Efectivo();
    Compra_Efectivo(int, float, string, float, float);

    void setConPago(float);
    void setCambio(float);

    float getConPago();
    float getCambio();

    void mostrarDatosPago() override;
};

Compra_Efectivo::Compra_Efectivo() : Compra() {
    conPago = 0.0f;
    cambio = 0.0f;
}

Compra_Efectivo::Compra_Efectivo(int id, float monto, string metodoPago, float conPago, float cambio) : Compra(id, monto, metodoPago) {
    this->conPago = conPago;
    this->cambio = cambio;
}

void Compra_Efectivo::setConPago(float conPago) { this->conPago = conPago; }
void Compra_Efectivo::setCambio(float cambio) { this->cambio = cambio; }

float Compra_Efectivo::getConPago() { return conPago; }
float Compra_Efectivo::getCambio() { return cambio; }

void Compra_Efectivo::mostrarDatosPago() {
    cout << fixed << setprecision(2);
    cout << "               TICKET DE COMPRA               " << endl;
    cout << "                      " << id << "                  " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "                Esencia Boutique              " << endl;
    cout << "    Independencia Norte 10, Centro, 76226     " << endl;
    cout << "               Tel. 442 291 0898               " << endl;
    cout << "                                              " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "Descripcion                         Precio    " << endl;
    mostrarProductos();
    cout << "                                              " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "Total:                              $" << monto << endl;
    cout << "                                              " << endl;
    cout << "Cantidad:                           $" << conPago << endl;
    cout << "Cambio:                             $" << cambio << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
}

class Compra_Tarjeta : public Compra {
private:
    float iva;

public:
    Compra_Tarjeta();
    Compra_Tarjeta(int, float, string, float);

    void setIva(float);

    float getIva();

    void mostrarDatosPago();
};

Compra_Tarjeta::Compra_Tarjeta() : Compra() {
    iva = 0.0f;
}

Compra_Tarjeta::Compra_Tarjeta(int id, float monto, string metodoPago, float iva) : Compra(id, monto, metodoPago) {
    this->iva = iva;
}

void Compra_Tarjeta::setIva(float iva) { this->iva = iva; }

float Compra_Tarjeta::getIva() { return iva; }

void Compra_Tarjeta::mostrarDatosPago() {
    cout << fixed << setprecision(2);
    cout << "               TICKET DE COMPRA               " << endl;
    cout << "                      " << id << "                  " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "                Esencia Boutique              " << endl;
    cout << "    Independencia Norte 10, Centro, 76226     " << endl;
    cout << "               Tel. 442 291 0898               " << endl;
    cout << "                                              " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "Descripcion                         Precio    " << endl;
    mostrarProductos();
    cout << "                                              " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "Iva:                                $" << iva << endl;
    cout << "Total:                              $" << monto << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
}

#endif  
