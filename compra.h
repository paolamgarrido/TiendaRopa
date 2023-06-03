/*En este avance se implementa el uso de:
Herencia, Sobre escritura y Sobre carga.*/

#ifndef TIENDAROPA_H
#define TIENDAROPA_H

#include <iostream>

using namespace std;

class Compra {
private:                // Atributos
    int id;     
    int monto;
    string metodoPago;
    string nombre;

public:             // Metodos
    Compra(){                   //Constructor
        id = 0;
        monto = 0;
        metodoPago = "";
        nombre = "";
    };
    Compra(int, int, string, string);
    void setIdCompra(int);
    int getIdCompra();
    void setMonto(int);
    int getMonto();
    void setMetodoPago(string);
    string getMetodoPago();
    void setNombre(string);
    string getNombre();
    void imprimirDatosTicket();
    void mostrarDatosPago();    // Sobreescritura
};

Compra::Compra(int _id, int _monto, string _metodoPago, string _nombre) {
    id = _id;
    monto = _monto;
    metodoPago = _metodoPago;
    nombre = _nombre;
}

void Compra::setIdCompra(int _id) {
    id = _id;
}

int Compra::getIdCompra() {
    return id;
}

void Compra::setMonto(int _monto) {
    monto = _monto;
}

int Compra::getMonto() {
    return monto;
}

void Compra::setMetodoPago(string _metodoPago) {
    metodoPago = _metodoPago;
}

string Compra::getMetodoPago() {
    return metodoPago;
}

void Compra::setNombre(string _nombre) {
    nombre = _nombre;
}

string Compra::getNombre() {
    return nombre;
}

void Compra::imprimirDatosTicket() {
    cout << "\nID Compra: " << id << endl;
    cout << "Nombre Cliente: " << nombre << endl;
    cout << "Método de Pago: " << metodoPago << endl;
    cout << "Monto: " << monto << endl;
}

class Compra_Efectivo : public Compra{
    private:        // Atributos
        int conPago;
        int cambio;
    public:         // Metodos
        Compra_Efectivo() {     // Constructor
            conPago = 0;
            cambio = 0;
        }
        Compra_Efectivo(int, int, string, string, int, int);
        void setConPago(int);
        int getConPago();
        void setCambio(int);
        int getCambio();
        void mostrarDatosPago();        // Sobreescritura
};

Compra_Efectivo::Compra_Efectivo(int _id, int _monto, string _metodoPago, string _nombre, int _conPago, int _cambio): Compra(_id, _monto,_metodoPago,_nombre){
    conPago = _conPago;
    cambio = _cambio;
}

void Compra_Efectivo::setConPago(int _conPago){
    conPago = _conPago;
}

int Compra_Efectivo::getConPago(){
    return conPago;
}

void Compra_Efectivo::setCambio(int _cambio){
    cambio = _cambio;
}

int Compra_Efectivo::getCambio(){
    return cambio;
}

void Compra_Efectivo::mostrarDatosPago(){
    imprimirDatosTicket();
    cout << "Cantidad con la que se pagó: " << conPago << endl;
    cout << "Cambio: " << cambio << endl;
}


class Compra_Tarjeta : public Compra{
    private:        // Atributos
        string titular;
        string cp;
        string numero;
        string vencimiento;
        string cvc;
        int plazosPago;
    public:     // Metodos
        Compra_Tarjeta() {      // Constructor
            titular = "";
            cp = "";
            numero = "";
            vencimiento = "";
            cvc = "";
            plazosPago = 0;
        }
        Compra_Tarjeta(int, int, string, string, string, string, string,string, string);
        Compra_Tarjeta(int, int, string, string, string, string, string,string, string,int);    // Sobrecarga
        void setTitular(string);
        string getTitular();
        void setCp(string);
        string getCp();
        void setNumero(string);
        string getNumero();
        void setVencimiento(string);
        string getVencimiento();
        void setCvc(string);
        string getCvc();
        void setPlazosPago(int);
        int getPlazosPago();
        void mostrarDatosPago();        // Sobreescritura
};

Compra_Tarjeta::Compra_Tarjeta(int _id, int _monto, string _metodoPago, string _nombre, string _titular, string _cp, string _numero, string _vencimiento, string _cvc): Compra(_id, _monto,_metodoPago,_nombre){
        titular = _titular;
        cp = _cp;
        numero = _numero;
        vencimiento = _vencimiento;
        cvc = _cvc;
}

Compra_Tarjeta::Compra_Tarjeta(int _id, int _monto, string _metodoPago, string _nombre, string _titular, string _cp, string _numero, string _vencimiento, string _cvc, int _plazosPago): Compra(_id, _monto,_metodoPago,_nombre){
        titular = _titular;
        cp = _cp;
        numero = _numero;
        vencimiento = _vencimiento;
        cvc = _cvc;
        plazosPago = _plazosPago;
}

void Compra_Tarjeta::setTitular(string _titular) {
    titular = _titular;
}

string Compra_Tarjeta::getTitular() {
    return titular;
}

void Compra_Tarjeta::setCp(string _cp) {
    cp = _cp;
}

string Compra_Tarjeta::getCp() {
    return cp;
}

void Compra_Tarjeta::setNumero(string _numero) {
    numero = _numero;
}

string Compra_Tarjeta::getNumero() {
    return numero;
}

void Compra_Tarjeta::setVencimiento(string _vencimiento) {
    vencimiento = _vencimiento;
}

string Compra_Tarjeta::getVencimiento() {
    return vencimiento;
}

void Compra_Tarjeta::setCvc(string _cvc) {
    cvc = _cvc;
}

string Compra_Tarjeta::getCvc() {
    return cvc;
}

void Compra_Tarjeta::setPlazosPago(int _plazosPago) {
    plazosPago = _plazosPago;
}

int Compra_Tarjeta::getPlazosPago() {
    return plazosPago;
}

void Compra_Tarjeta::mostrarDatosPago(){
    imprimirDatosTicket();
    cout << "Titular tarjeta: " <<titular<< endl;
    cout << "Codigo postal: " <<cp<< endl;
    cout << "Número tarjeta: " <<numero<< endl;
    cout << "Vencimiento tarjeta: " <<vencimiento<< endl;
    cout << "CVC: " <<cvc<< endl;
    cout <<"Plazos de pago: " << plazosPago << endl;
}

#endif 
