#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Producto {
private:                   
    string descripcion;
    string talla;
    string color;
    float precio; 

public:             
    Producto();
    Producto(string, string, string, float);

    void setDescripcion(string);
    void setTalla(string);
    void setColor(string);
    void setPrecio(float);

    string getDescripcion();
    string getTalla();
    string getColor();
    float getPrecio();

    void mostrarProductos();
};

Producto::Producto() {
    descripcion = "";
    talla = "";
    color = "";
    precio = 0.0;
}

Producto::Producto(string descripcion, string talla, string color, float precio) {
    this->descripcion = descripcion;
    this->talla = talla;
    this->color = color;
    this->precio = precio;
}

void Producto::setDescripcion(string descripcion) { this->descripcion = descripcion; }
void Producto::setTalla(string talla) { this->talla = talla; }
void Producto::setColor(string color) { this->color = color; }
void Producto::setPrecio(float precio) { this->precio = precio; }

string Producto::getDescripcion() { return descripcion; }
string Producto::getTalla() { return talla; }
string Producto::getColor() { return color; }
float Producto::getPrecio() { return precio; }

void Producto::mostrarProductos(){
    cout << descripcion << " " << color << " " << talla << "                     " << fixed << setprecision(2) << precio << endl;
}

#endif
