#ifndef COMPRA_H
#define COMPRA_H

#include <iostream>
#include <vector>

#include "Producto.h"


using namespace std;

class Compra {
protected:                
    int id;     
    int monto;
    string metodoPago;
    vector<Producto *> productos;

public:            
    Compra();
    Compra(int, int, string);

    void setIdCompra(int);
    void setMonto(int);
    void setMetodoPago(string);

    int getIdCompra();
    int getMonto();
    string getMetodoPago();
   
    virtual void mostrarDatosPago() = 0;    

    void agregarProducto(Producto *);
    void mostrarProductos();
};

Compra::Compra(){                  
        id = 0;
        monto = 0;
        metodoPago = "";
};

Compra::Compra(int id, int monto, string metodoPago) {
    this->id = id;
    this->monto = monto;
    this->metodoPago = metodoPago;
}

void Compra::setIdCompra(int id) { this->id = id; }
void Compra::setMonto(int monto) { this->monto = monto;}
void Compra::setMetodoPago(string metodoPago) { this->metodoPago = metodoPago; }

int Compra::getIdCompra() { return id; }
int Compra::getMonto() { return monto; }
string Compra::getMetodoPago() { return metodoPago; }

void Compra::agregarProducto(Producto *producto) { 
    productos.push_back(producto);
}

void Compra::mostrarProductos(){
    for(Producto *producto : productos){
        producto->mostrarProductos();      // ARREGLAR 
    }
}

class Compra_Efectivo : public Compra{
    private:        
        int conPago;
        int cambio;

    public:        
        Compra_Efectivo();
        Compra_Efectivo(int, int, string, int, int);

        void setConPago(int);
        void setCambio(int);

        int getConPago();
        int getCambio();

        void mostrarDatosPago() override;       // SE QUEDA O NO?  
};

Compra_Efectivo::Compra_Efectivo() : Compra() {     
    conPago = 0;
    cambio = 0;
}

Compra_Efectivo::Compra_Efectivo(int id, int monto, string metodoPago, int conPago, int cambio): Compra(id, monto, metodoPago){
    this->conPago = conPago;
    this->cambio = cambio;
}

void Compra_Efectivo::setConPago(int conPago){ this->conPago = conPago; }
void Compra_Efectivo::setCambio(int cambio){ this->cambio = cambio;}

int Compra_Efectivo::getConPago(){ return conPago; }
int Compra_Efectivo::getCambio(){ return cambio;}

void Compra_Efectivo::mostrarDatosPago(){
    cout << "               TICKET DE COMPRA               " << endl;
    cout << "                      "<< id <<"                  " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "                Esencia Boutique              " << endl;
    cout << "    Independencia Norte 10, Centro, 76226     " << endl;
    cout << "               Tel. 442 291 0898               " << endl;
    cout << "                                              " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    mostrarProductos();
    cout << "                                              " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "Total:                               " << monto << endl;
    cout << "                                              " << endl;
    cout << "Cantidad:                            " << conPago << endl;
    cout << "Cambio:                              " << cambio << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
}


class Compra_Tarjeta : public Compra{
    private:        
        int iva;

    public:    
        Compra_Tarjeta();
        Compra_Tarjeta(int, int, string, int);

        void setIva(int);

        int getIva();

        void mostrarDatosPago();       
};

Compra_Tarjeta::Compra_Tarjeta() : Compra() {
    iva = 0;      
}

Compra_Tarjeta::Compra_Tarjeta(int id, int monto, string metodoPago, int iva): Compra(id, monto, metodoPago){
        this->iva = iva;
}

void Compra_Tarjeta::setIva(int iva){ this->iva = iva;}

int Compra_Tarjeta::getIva(){ return iva; }

void Compra_Tarjeta::mostrarDatosPago(){
    cout << "               TICKET DE COMPRA               " << endl;
    cout << "                      "<< id <<"                  " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "                Esencia Boutique              " << endl;
    cout << "    Independencia Norte 10, Centro, 76226     " << endl;
    cout << "               Tel. 442 291 0898               " << endl;
    cout << "                                              " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    mostrarProductos();
    cout << "                                              " << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "Iva:                                 " << iva << endl;
    cout << "Total:                               " << monto << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * " << endl;

}

#endif 
