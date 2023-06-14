/*
 *
 * Proyecto Tienda de ropa
 * Paola María Garrido Montes
 * A01704017
 * 16/06/2023
 * version: 3
 * Esta clase guarda las características de un producto 
 * y modela su comportamiento, permitiendo la creación así
 * como visualización de este. 
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Producto {

// Declaro las variables privadas de instancia    
private:                   
    string descripcion;
    string talla;
    string color;
    float precio; 

// Declaro constructor por defecto, con parámetros y el método público
public:             
    Producto();
    Producto(string, string, string, float);
    void mostrarProducto();
};

// Definición del constructor por defecto
Producto::Producto() {
    descripcion = "";
    talla = "";
    color = "";
    precio = 0.0;
}

// Definición del constructor con parámetros
Producto::Producto(string descripcion, string talla, string color, float precio) {
    this->descripcion = descripcion;
    this->talla = talla;
    this->color = color;
    this->precio = precio;
}

/**
 * mostrarProducto imprime los datos del producto.
 *
 * Muestra la descripcion, color, talla y precio del
 * producto usando dos decimales. Utiliza espacios
 * para tener una mejor visualización de estos en el
 * ticket de compra. 
 *
 * @param
 * @return datos del producto con espacios correspondientes.
 */
void Producto::mostrarProducto(){
    cout << descripcion << " " << color << " " << talla << "                     " << fixed << setprecision(2) << precio << endl;
}

#endif
