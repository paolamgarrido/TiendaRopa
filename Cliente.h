/*
 *
 * Proyecto Tienda de ropa
 * Paola María Garrido Montes
 * A01704017
 * 16/06/2023
 * version: 3
 * Esta clase permite establecer y obtener el nombre
 * del cliente así como agregar las compras realizadas
 * según su método de pago (tarjeta o efectivo). También
 * permite buscar una compra específica por su ID (con el fin
 * de agregar datos a la compra) e incluso se encarga de mostrar
 * los detalles de todas las compras realizadas. 
 * 
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>

#include "Compra.h"

using namespace std;

class Cliente {

// Declaro las variables privadas de instancia  
private:
    string nombre;
    vector<Compra *> compras; // Almacena punteros a objetos de Compra.

// Declaro constructor por defecto, con parámetros y los métodos públicos
public:
    Cliente();
    Cliente(string);
    string getNombre();
    void agregarCompraEfectivo(int, float, string, float, float);
    void agregarCompraTarjeta(int, float, string, float, int, int);
    Compra *buscarCompra(int);
    void mostrarCompras();
};

// Definición del constructor por defecto
Cliente::Cliente() {
    nombre = "";
}

// Definición del constructor con parámetros
Cliente::Cliente(string nombre) {
    this->nombre = nombre;
}

// Devuelve el valor del atributo nombre 
string Cliente::getNombre() { return nombre; }

/**
 * agregarCompraEfectivo agerga una compra del tipo Efectivo.
 *
 * Agrega una nueva compra de tipo efectivo al vector compras. 
 * Crea un objeto Compra_Efectivo utilizando los parámetros 
 * proporcionados y luego agrega un puntero de dicho objeto 
 * al vector compras utilizando la función push_back.
 * 
 * Se implica el uso de herencia, polimorfismo y composición. 
 *
 * @param  int Id de la compra, float monto, string metodo de pago, 
 *         float cantidad con la que se pago y float cambio.
 * @return 
 */
void Cliente::agregarCompraEfectivo(int id, float monto, string metodoPago, float conPago, float cambio) {
    Compra *c = new Compra_Efectivo(id, monto, metodoPago, conPago, cambio);
    compras.push_back(c);
}

/**
 * agregarCompraTarjeta agerga una compra del tipo Tarjeta.
 *
 * Agrega una nueva compra de tipo tarjeta al vector compras. 
 * Crea un objeto Compra_Tarjeta utilizando los parámetros 
 * proporcionados y luego agrega un puntero de dicho objeto 
 * al vector compras utilizando la función push_back.
 * 
 * Se implica el uso de herencia, polimorfismo y composición. 
 *
 * @param  int Id de la compra, float monto, string metodo de pago, 
 *         float iva, int últimos números del número de cuenta y int
 *         número de autorización dela compra. 
 * @return 
 */
void Cliente::agregarCompraTarjeta(int id, float monto, string metodoPago, float iva, int cuenta, int autorizacion) {
    Compra *c = new Compra_Tarjeta(id, monto, metodoPago, iva, cuenta, autorizacion);
    compras.push_back(c);
}

/**
 * buscarCompra busca las compras según su ID. 
 *
 * Busca una compra en el vector compras según el ID proporcionado. 
 * Para esto recorre el vector y compara el ID de cada compra con el ID buscado. 
 * Si encuentra una coincidencia devuelve un puntero a esa compra, de lo contrario
 * devuelve un puntero nulo.
 *
 * @param  int Id de la compra.
 * @return puntero de compra o puntero nulo, según sea el caso. 
 */
Compra *Cliente::buscarCompra(int id) {
    for (Compra *compra : compras) {
        if (compra->getIdCompra() == id) {
            return compra;
        }
    }
    return nullptr;
}

/**
 * mostrarCompras imprime el ticket de compra. 
 *
 * Muestra los detalles de todas las compras almacenadas en el 
 * vector compras. Para esto itera sobre el vector y para cada compra, 
 * llama al método mostrarDatosPago de la compra correspondiente con
 * el uso de apuntadores para mostrar los datos de pago, es decir, 
 * el ticket de compra. Además imprime una línea en blanco antes
 * y después para una mejor visualización al momento de impresión. 
 *
 * @param   
 * @return ticket o tickets de compra.
 */
void Cliente::mostrarCompras() {
    for (Compra *compra : compras) {
        cout << "\n";
        compra->mostrarDatosPago();
        cout << "\n";
    }
}

#endif  