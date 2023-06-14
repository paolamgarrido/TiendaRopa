#include "Cliente.h"
#include "Producto.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << "\nBienvenido a la aplicacion de compras para Escencia Boutique" << endl;
    cout << "\nAqui podras registrar las compras realizadas y ver su historial." << endl;

    vector<Cliente> clientes;
    bool menuPrincipal = true;
    int numCliente = 0;
    bool comprasRealizadas = false;

    string nombre;
    cout << "Nombre del empleado: ";
    cin >> nombre; 
  
    while(menuPrincipal){
        int opcion;
        cout << "\nMenu Principal\n1. Registrar Compra\n2. Ver historial de compras\n3. Cerrar Sesion\nInserte opcion: ";
        cin >> opcion;

        if(opcion == 1){
            comprasRealizadas = true;
            bool regresarMenu = true;
            while (regresarMenu) {
                string nombre = "Cliente " + to_string(numCliente+1);
                clientes.push_back(Cliente(nombre));
                
                cout << "\nMetodo de Pago\n1. Efectivo\n2. Tarjeta\nInserte opcion: ";
                cin >> opcion;
                
                if (opcion == 1) {
                    
                    int cantidadProductos;
                    cout << "\nIngrese la cantidad de productos que el cliente selecciono para su registro: ";
                    cin >> cantidadProductos;

                    int idCompra = 28150 + numCliente;
                    string metodoPago = "Efectivo";

                    clientes[numCliente].agregarCompraEfectivo(idCompra, 0, metodoPago, 0, 0);

                    for (int j = 0; j < cantidadProductos; j++) {
                        
                        int opcionP;

                        string descripcion;
                        string talla;
                        string color;
                        float precio = 0.0;

                        while(true){
                            cout << "\nSeleccion de producto\n1. Playera\n2. Sudadera\n3. Pantalonera\nInserte opcion: ";
                            cin >> opcionP;

                            if (opcionP == 1) {
                                descripcion = "Pla.  ";
                                precio += 250.50;
                                break;
                            } else if (opcionP == 2) {
                                descripcion = "Sud.  ";
                                precio += 360.80;
                                break;
                            } else if (opcionP == 3) {
                                descripcion = "Pants.";
                                precio += 520.90;
                                break;
                            }else{
                                cout <<"Ingresa una opcion valida." << endl;
                            }
                        }

                        while(true){
                            cout << "\nSeleccione la talla\n1. S (chica)\n2. M (mediana)\n3. L (grande)\nInserte opcion: ";
                            cin >> opcionP;
                            if (opcionP == 1) {
                                talla = "S";
                                break;
                            } else if (opcionP == 2) {
                                talla = "M";
                                break;
                            } else if (opcionP == 3) {
                                talla = "L";
                                break;
                            }else{
                                cout <<"Ingresa una opcion valida." << endl;
                            }
                        }

                        while(true){
                            cout << "\nSeleccione el color\n1. Blanco\n2. Beige\n3. Verde Militar\nInserte opcion: ";
                            cin >> opcionP;
                            if (opcionP == 1) {
                                color = "Blanco";
                                break;
                            } else if (opcionP == 2) {
                                color = "Beige ";
                                break;
                            } else if (opcionP == 3) {
                                color = "Verde ";
                                break;
                            }
                        }

                        Producto* producto = new Producto(descripcion, talla, color, precio);

                        clientes[numCliente].buscarCompra(idCompra)->agregarProducto(producto);

                        float montoTotal = clientes[numCliente].buscarCompra(idCompra)->getMonto();
                        montoTotal += precio;
                        clientes[numCliente].buscarCompra(idCompra)->setMonto(montoTotal);
                    }

                    float montoTotal = clientes[numCliente].buscarCompra(idCompra)->getMonto();

                    cout << "\nEl total de su compra fue de: $" << montoTotal << endl;

                    float conPago;
                    cout << "Cantidad con la que desea realizar el pago: $";
                    cin >> conPago;
                    dynamic_cast<Compra_Efectivo*>(clientes[numCliente].buscarCompra(idCompra))->setConPago(conPago);

                    float cambio = conPago - montoTotal;
                    dynamic_cast<Compra_Efectivo*>(clientes[numCliente].buscarCompra(idCompra))->setCambio(cambio);

                    clientes[numCliente].mostrarCompras();

                    numCliente += 1;
                    regresarMenu = false;

                } else if (opcion == 2) {
                    
                    int cantidadProductos;
                    cout << "\nIngrese la cantidad de productos que el cliente selecciono para su registro: ";
                    cin >> cantidadProductos;

                    int idCompra = 28150 + numCliente;
                    string metodoPago = "Tarjeta";
                    int cuenta = 6460 + numCliente;
                    int autorizacion = 52420 + numCliente;

                    clientes[numCliente].agregarCompraTarjeta(idCompra, 0, metodoPago, 0, cuenta, autorizacion); 

                    for (int j = 0; j < cantidadProductos; j++) {
                        
                        int opcionP;

                        string descripcion;
                        string talla;
                        string color;
                        float precio = 0.0;

                        while(true){
                            cout << "\nSeleccion de producto\n1. Playera\n2. Sudadera\n3. Pantalonera\nInserte opcion: ";
                            cin >> opcionP;

                            if (opcionP == 1) {
                                descripcion = "Pla.  ";
                                precio += 250.50;
                                break;
                            } else if (opcionP == 2) {
                                descripcion = "Sud.  ";
                                precio += 360.80;
                                break;
                            } else if (opcionP == 3) {
                                descripcion = "Pants.";
                                precio += 520.90;
                                break;
                            }else{
                                cout <<"Ingresa una opcion valida." << endl;
                            }
                        }

                        while(true){
                            cout << "\nSeleccione la talla\n1. S (chica)\n2. M (mediana)\n3. L (grande)\nInserte opcion: ";
                            cin >> opcionP;
                            if (opcionP == 1) {
                                talla = "S";
                                break;
                            } else if (opcionP == 2) {
                                talla = "M";
                                break;
                            } else if (opcionP == 3) {
                                talla = "L";
                                break;
                            }else{
                                cout <<"Ingresa una opcion valida." << endl;
                            }
                        }

                        while(true){
                            cout << "\nSeleccione el color\n1. Blanco\n2. Beige\n3. Verde Militar\nInserte opcion: ";
                            cin >> opcionP;
                            if (opcionP == 1) {
                                color = "Blanco";
                                break;
                            } else if (opcionP == 2) {
                                color = "Beige ";
                                break;
                            } else if (opcionP == 3) {
                                color = "Verde ";
                                break;
                            }
                        }

                        Producto* producto = new Producto(descripcion, talla, color, precio);

                        clientes[numCliente].buscarCompra(idCompra)->agregarProducto(producto);

                        float montoTotal = clientes[numCliente].buscarCompra(idCompra)->getMonto();
                        montoTotal += precio;
                        clientes[numCliente].buscarCompra(idCompra)->setMonto(montoTotal);

                    }

                    float montoTotal = clientes[numCliente].buscarCompra(idCompra)->getMonto();
                    float iva = montoTotal * 0.16;
                    montoTotal += iva;

                    dynamic_cast<Compra_Tarjeta*>(clientes[numCliente].buscarCompra(idCompra))->setIva(iva);
                    dynamic_cast<Compra_Tarjeta*>(clientes[numCliente].buscarCompra(idCompra))->setMonto(montoTotal);

                    cout << "\nEl total de su compra fue de: $" << montoTotal << endl;

                    cout << "\n               Ingresar tarjeta               " << endl;
                    cout << "\n----------------------------------------------" << endl;
                    cout << "                 Pago exitoso                 " << endl;
                    cout << "----------------------------------------------" << endl;
                    clientes[numCliente].mostrarCompras();

                    numCliente += 1;
                    regresarMenu = false;
                }
            }

        } else if (opcion == 2) {
            cout << "\nEmpleado: " << nombre << endl;

            if(comprasRealizadas == false){
                cout << "\nNo se han registrado compras aún." << endl;

            }else{
                for (int k = 0; k < numCliente ; k++) {
                string nombre = clientes[k].getNombre();
                cout << "\n";
                cout << nombre << endl;
                clientes[k].mostrarCompras();
            }

            }
        } else if (opcion == 3) {
            cout << "\n" << nombre << " tu sesion ha finalizado correctamente." << endl;
            menuPrincipal = false;
        } else {
            cout << "\nIngresa una opcion valida." << endl;
        }
    }
  
    return 0;
}