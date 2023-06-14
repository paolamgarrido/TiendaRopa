#ifndef COMPRA_H
#define COMPRA_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "Producto.h"

using namespace std;

class Compra {

// Declaro las variables públicas de instancia 
protected:
    int id;
    float monto;
    string metodoPago;
    vector<Producto *> productos; // Almacena punteros a objetos de Producto.

// Declaro constructor por defecto, con parámetros y los métodos públicos
public:
    Compra();
    Compra(int, float, string);

    void setIdCompra(int);
    void setMonto(float);
    void setMetodoPago(string);

    int getIdCompra();
    float getMonto();
    string getMetodoPago();

    virtual void mostrarDatosPago() = 0; //Método abstracto el cuál será sobreescrito
    void agregarProducto(Producto *);
    void mostrarProductos();
};

// Definición del constructor por defecto
Compra::Compra() {
    id = 0;
    monto = 0.0f;
    metodoPago = "";
};

// Definición del constructor con parámetros
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

/**
 * agregarProducto agrega los productos.
 *
 * Agrega un objeto de la clase Producto al vector productos dentro de la compra.
 * Se utiliza la función push_back() del vector productos para agregar dicho puntero 
 * del producto al final del vector, el cuál permite su almacenamiento en la lista de
 * productos asociados con la compra correspondiente. 
 * 
 * Se implica el uso de agregación. 
 *
 * @param producto puntero a un objeto de la clase Producto.
 * @return 
 */
void Compra::agregarProducto(Producto *producto) {
    productos.push_back(producto);
}

/**
 * mostrarProductos imprime los datos de los productos
 * asociados a una compra.
 *
 * Muestra los detalles de todos los productos almacenados en el 
 * vector productos asociados a la compra correspondiente deseada. 
 * Para esto itera sobre el vector productos y para cada producto, 
 * llama al método mostrarProducto con el uso de apuntadores, con  
 * el fin de mostrar todos los productos seleccionados en esa compra. 
 * 
 * @param
 * @return detalles de los productos seleccionados.
 */
void Compra::mostrarProductos() {
    for (Producto *producto : productos) {
        producto->mostrarProducto();
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

    void mostrarDatosPago();
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
    int cuenta;
    int autorizacion;

public:
    Compra_Tarjeta();
    Compra_Tarjeta(int, float, string, float, int, int);

    void setIva(float);
    void setCuenta(int);
    void setAutorizacion(int);

    float getIva();
    int getCuenta();
    int getAutorizacion();

    void mostrarDatosPago();
};

Compra_Tarjeta::Compra_Tarjeta() : Compra() {
    iva = 0.0f;
    cuenta = 0;
    autorizacion = 0;
}

Compra_Tarjeta::Compra_Tarjeta(int id, float monto, string metodoPago, float iva, int cuenta, int autorizacion) : Compra(id, monto, metodoPago) {
    this->iva = iva;
    this->cuenta = cuenta;
    this->autorizacion = autorizacion;
}

void Compra_Tarjeta::setIva(float iva) { this->iva = iva; }
void Compra_Tarjeta::setCuenta(int cuenta) { this->cuenta = cuenta; }
void Compra_Tarjeta::setAutorizacion(int autorizacion) { this->autorizacion = autorizacion; }

float Compra_Tarjeta::getIva() { return iva; }
int Compra_Tarjeta::getCuenta() { return cuenta; }
int Compra_Tarjeta::getAutorizacion() { return autorizacion; }

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
    cout << "No. cuenta:************"<< cuenta << endl;
    cout << "Num. Autorizacion:0" << autorizacion << endl;
    cout << "                                              " << endl;
    cout << "Iva:                                $" << iva << endl;
    cout << "Total:                              $" << monto << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
}

#endif  
