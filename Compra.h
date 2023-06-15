/*
 *
 * Proyecto Tienda de ropa
 * Paola María Garrido Montes
 * A01704017
 * 16/06/2023
 * Contamos con la clase padre Compra que se define como 
 * abstracta, por lo que los objetos creados de compra serán
 * de las clases hijas Compra_Efectivo o Compra_Tarjeta.
 * El objetivo principal de la clase compra es agregar los productos 
 * a la compra asociada para realizar su impresión. Por otra parte, 
 * el objetivo de las clases hijas es imprimir el ticket dependiendo 
 * del tipo de compra realizada junto con los productos seleccionados. 
 * 
 */

#ifndef COMPRA_H
#define COMPRA_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "Producto.h"

using namespace std;

// Declaracion de clase Compra que es abstracta.
class Compra {

// Declaro las variables protegidas de instancia. 
protected:
    int id;
    float monto;
    string metodoPago;
    vector<Producto *> productos; // Almacena punteros a objetos de Producto.

// Declaro constructor por defecto, con parámetros y los métodos públicos.
public:
    Compra();
    Compra(int, float, string);
    void setIdCompra(int);
    void setMonto(float);
    void setMetodoPago(string);
    int getIdCompra();
    float getMonto();
    string getMetodoPago();
    virtual void mostrarDatosPago() = 0; // Método abstracto el cuál será sobreescrito por las clases hijas.
    void agregarProducto(Producto *);
    void mostrarProductos();
};

// Definición del constructor por defecto.
Compra::Compra() {
    id = 0;
    monto = 0.0;
    metodoPago = "";
};

// Definición del constructor con parámetros.
Compra::Compra(int id, float monto, string metodoPago) {
    this->id = id;
    this->monto = monto;
    this->metodoPago = metodoPago;
}

void Compra::setIdCompra(int id) { this->id = id; } // Establece el ID de la compra.
void Compra::setMonto(float monto) { this->monto = monto; } // Establece el monto. 
void Compra::setMetodoPago(string metodoPago) { this->metodoPago = metodoPago; } // Establece el método de pago. 

int Compra::getIdCompra() { return id; } // Devuelve el valor del atributo Id de la compra.
float Compra::getMonto() { return monto; } // Devuelve el valor del atributo monto. 
string Compra::getMetodoPago() { return metodoPago; } // Devuelve el valor del atributo metodo de pago. 

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
 * @return 
 */
void Compra::mostrarProductos() {
    for (Producto *producto : productos) {
        producto->mostrarProducto();
    }
}

// Declaración de clase Efectivo que es hija de la clase padre Compra.
class Compra_Efectivo : public Compra {

// Declaro las variables privadas de instancia  
private:
    float conPago;
    float cambio;

// Declaro constructor por defecto, con parámetros y los métodos públicos.
public:
    Compra_Efectivo();
    Compra_Efectivo(int, float, string, float, float);
    void setConPago(float);
    void setCambio(float);
    float getConPago();
    float getCambio();
    void mostrarDatosPago();
};

// Definición del constructor por defecto.
Compra_Efectivo::Compra_Efectivo() : Compra() {
    conPago = 0.0;
    cambio = 0.0;
}

// Definición del constructor con parámetros.
Compra_Efectivo::Compra_Efectivo(int id, float monto, string metodoPago, float conPago, float cambio) : Compra(id, monto, metodoPago) {
    this->conPago = conPago;
    this->cambio = cambio;
}

void Compra_Efectivo::setConPago(float conPago) { this->conPago = conPago; } // Establece la cantidad con la que se pago.
void Compra_Efectivo::setCambio(float cambio) { this->cambio = cambio; } // Establece el cambio.

float Compra_Efectivo::getConPago() { return conPago; } // Devuelve el valor del atributo que indica la cantidad con la que se pago.
float Compra_Efectivo::getCambio() { return cambio; } // Devuelve el valor del atributo cambio.

/**
 * mostrarDatosPago se encarga de imprimir el ticket.
 *
 * Esta función hace uso de la sobrescritura, por lo 
 * que imprime el ticket correspondiente a una compra
 * en efectivo según los parámetros necesarios recolectados 
 * en el main para realizar este tipo de compra. Además se 
 * manda a llamar la función mostrarProductos(), con el fin
 * de imprimir los productos asociados a la compra.
 * 
 * @param  
 * @return 
 */
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

// Declaración de clase tarjeta que es hija de la clase padre compra.
class Compra_Tarjeta : public Compra {

// Declaro las variables privadas de instancia.  
private:
    float iva;
    int cuenta;
    int autorizacion;

// Declaro constructor por defecto, con parámetros y los métodos públicos.
public:
    Compra_Tarjeta();
    Compra_Tarjeta(int, float, string, float, int, int);
    void setIva(float);
    void setCuenta(int);
    void setAutorizacion(int);
    float getIva();
    void mostrarDatosPago();
};

// Definición del constructor por defecto.
Compra_Tarjeta::Compra_Tarjeta() : Compra() {
    iva = 0.0;
    cuenta = 0;
    autorizacion = 0;
}

// Definición del constructor con parámetros.
Compra_Tarjeta::Compra_Tarjeta(int id, float monto, string metodoPago, float iva, int cuenta, int autorizacion) : Compra(id, monto, metodoPago) {
    this->iva = iva;
    this->cuenta = cuenta;
    this->autorizacion = autorizacion;
}

void Compra_Tarjeta::setIva(float iva) { this->iva = iva; } // Establece el iva del pago.
void Compra_Tarjeta::setCuenta(int cuenta) { this->cuenta = cuenta; } // Establece el número de cuenta con el que se realizó el pago. 
void Compra_Tarjeta::setAutorizacion(int autorizacion) { this->autorizacion = autorizacion; } // Establece el número de autorización.

float Compra_Tarjeta::getIva() { return iva; } // Devuelve el valor del iva para realizar los cálculos del monto total. 

/**
 * mostrarDatosPago se encarga de imprimir el ticket.
 *
 * Esta función hace uso de la sobrescritura, por lo 
 * que imprime el ticket correspondiente a una compra
 * con tarjeta según los parámetros necesarios recolectados 
 * en el main para realizar este tipo de compra. Además se 
 * manda a llamar la función mostrarProductos(), con el fin
 * de imprimir los productos asociados a la compra.
 * 
 * @param  
 * @return 
 */
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