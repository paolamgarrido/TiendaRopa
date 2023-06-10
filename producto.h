#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>

using namespace std;

class Producto {
private:                   
    string descripcion;
    string talla;
    string color;
    int precio; 

public:             
    Producto();
    Producto(string, string, string, int);

    void setDescripcion(string);
    void setTalla(string);
    void setColor(string);
    void setPrecio(int);

    string getDescripcion();
    string getTalla();
    string getColor();
    int getPrecio();

    void mostrarProductos();
};

Producto::Producto() {
    descripcion = "";
    talla = "";
    color = "";
    precio = 0;
}

Producto::Producto(string descripcion, string talla, string color, int precio) {
    this->descripcion = descripcion;
    this->talla = talla;
    this->color = color;
    this->precio = precio;
}

void Producto::setDescripcion(string descripcion) { this->descripcion = descripcion; }
void Producto::setTalla(string talla) { this->talla = talla; }
void Producto::setColor(string color) { this->color = color; }
void Producto::setPrecio(int precio) { this->precio = precio; }

string Producto::getDescripcion() { return descripcion; }
string Producto::getTalla() { return talla; }
string Producto::getColor() { return color; }
int Producto::getPrecio() { return precio; }

void Producto::mostrarProductos(){
    cout << "Descripcion                         Precio    " << endl;
    cout << descripcion << " " << color << " " << talla << "                      " << precio << endl;
}

#endif
