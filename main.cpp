/*
 *
 * Proyecto Tienda de ropa
 * Paola María Garrido Montes
 * A01704017
 * 16/06/2023
 * 
 * El programa es una aplicación para una tienda de ropa llamada "Esencia Boutique". 
 * El objetivo de su uso es permitir a los empleados que se encuentran en el área de 
 * caja en la tienda física registrar las compras realizadas, seleccionando el método 
 * de pago (efectivo o tarjeta), así como los productos. Mientras tanto, la aplicación 
 * se encargará de generar un ticket para el cliente, guardando este en el historial de 
 * compras, el cuál podrá ser revisado por los empleados.
 * 
 */

#include "Cliente.h"
#include "Producto.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << "\nBienvenido a la aplicacion de compras para Escencia Boutique" << endl;
    cout << "\nAqui podras registrar las compras realizadas y ver su historial." << endl;

    vector<Cliente> clientes; // Almacena objetos de tipo Cliente.
    bool menuPrincipal = true; // Variable utilizada para repetir continuamente el ciclo while del menu principal.
    int numCliente = 0; // Contador del número de clientes.
    bool comprasRealizadas = false; // Variable para verificar si se han realizado compras.

    // Solicitar el nombre del empleado. 
    string nombre;
    cout << "Nombre del empleado: ";
    cin >> nombre; 
  
    // Ciclo de menú principal para navegar en el programa.
    while(menuPrincipal){

        // Variable para guardar la opción seleccionada en el menú principal y el menú método de pago dentro de este ciclo.
        int opcion;
        cout << "\nMenu Principal\n1. Registrar Compra\n2. Ver historial de compras\n3. Cerrar Sesion\nInserte opcion: ";
        cin >> opcion;

        // Se encarga de registrar la compra.
        if(opcion == 1){
            comprasRealizadas = true; // Indica la realización de una compra al cambiar el valor de la variable a true.
            bool regresarMenu = true; // Variable utilizada para repetir continuamente el ciclo while del menú de tipo de compra.
            while (regresarMenu) {
                string nombre = "Cliente " + to_string(numCliente+1); // Definir el nombre del cliente y pasar el número de cliente a string. 
                clientes.push_back(Cliente(nombre)); // Establecer el nombre y almacenarlo en el vector clientes.
                
                // Menú para el método de pago. 
                cout << "\nMetodo de Pago\n1. Efectivo\n2. Tarjeta\nInserte opcion: ";
                cin >> opcion;
                
                if (opcion == 1) {

                    // Solicitar al usuario la cantidad de productos a registrar.
                    int cantidadProductos;
                    cout << "\nIngrese la cantidad de productos que el cliente selecciono para su registro: ";
                    cin >> cantidadProductos;

                    // Establecer el ID de la compra y método de pago.
                    int idCompra = 28150 + numCliente;
                    string metodoPago = "Efectivo";

                    // Agregar y crear la compra de tipo efectivo. 
                    clientes[numCliente].agregarCompraEfectivo(idCompra, 0, metodoPago, 0, 0);

                    /*
                    Ciclo for para iterar sobre la cantidad de productos especificada
                    y establecer los parámetros correspondientes para su creación. 
                    */ 
                    for (int j = 0; j < cantidadProductos; j++) {
                        // Variable para guardar la opción seleccionada de los productos dentro de este ciclo.
                        int opcionP;
                        // Variables locales para los parámetros del producto.
                        string descripcion;
                        string talla;
                        string color;
                        float precio = 0.0;

                        // Selección de los parámetros del producto y actualización de las variables.
                        while(true){
                            // Selección de producto.
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
                                precio += 520;
                                break;
                            }else{
                                cout <<"Ingresa una opcion valida." << endl;
                            }
                        }

                        while(true){
                            // Selección de talla.
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
                            // Selección de color.
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
                            }else{
                                cout <<"Ingresa una opcion valida." << endl;
                            }
                        }

                        // Crear un nuevo objeto Producto.
                        Producto* producto = new Producto(descripcion, talla, color, precio);

                        // Agregar el producto creado al objeto Compra correspondiente dentro del vector clientes.
                        clientes[numCliente].buscarCompra(idCompra)->agregarProducto(producto);

                        // Obtener el monto total actual de la compra correspondiente.
                        float montoTotal = clientes[numCliente].buscarCompra(idCompra)->getMonto();

                        // Aumentar el monto total sumándole el precio del nuevo producto.
                        montoTotal += precio;

                        // Actualizar el monto total de la compra correspondiente.
                        clientes[numCliente].buscarCompra(idCompra)->setMonto(montoTotal);
                    }

                    // Obtener el monto total correspondiente según el ID de la compra actual.
                    float montoTotal = clientes[numCliente].buscarCompra(idCompra)->getMonto();

                    // Mostrar al cliente el monto total.
                    cout << "\nEl total de su compra fue de: $" << montoTotal << endl;

                    // Pedir al cliente la cantidad con la que realizará el pago y establecer dicha cantidad.
                    float conPago;
                    cout << "Cantidad con la que desea realizar el pago: $";
                    cin >> conPago;
                    dynamic_cast<Compra_Efectivo*>(clientes[numCliente].buscarCompra(idCompra))->setConPago(conPago);

                    // Calcular el cambio y establecer la cantidad de este.
                    float cambio = conPago - montoTotal;
                    dynamic_cast<Compra_Efectivo*>(clientes[numCliente].buscarCompra(idCompra))->setCambio(cambio);

                    // Imprimir el ticket de compra.
                    clientes[numCliente].mostrarCompras();

                    numCliente += 1; // Aumentar el contador de cliente.
                    regresarMenu = false; // Salir del menú de tipo de compra y regresar al menú principal.

                } else if (opcion == 2) {
                    
                    // Solicita al usuario la cantidad de productos a registrar.
                    int cantidadProductos;
                    cout << "\nIngrese la cantidad de productos que el cliente selecciono para su registro: ";
                    cin >> cantidadProductos;

                    // Establece el ID de la compra, método de pago, número de cuenta del cliente y autorización del pago.
                    int idCompra = 28150 + numCliente;
                    string metodoPago = "Tarjeta";
                    int cuenta = 6460 + numCliente;
                    int autorizacion = 52420 + numCliente;

                    // Agrega y crea la compra de tipo tarjeta.
                    clientes[numCliente].agregarCompraTarjeta(idCompra, 0, metodoPago, 0, cuenta, autorizacion); 

                    /*
                    Ciclo for para iterar sobre la cantidad de productos especificada
                    y establecer los parámetros correspondientes para su creación. 
                    */ 
                    for (int j = 0; j < cantidadProductos; j++) {
                        // Variable para guardar la opción seleccionada de los productos dentro de este ciclo.
                        int opcionP;
                        // Variables locales para los parámetros del producto.
                        string descripcion;
                        string talla;
                        string color;
                        float precio = 0.0;

                        // Selección de los parámetros del producto y actualización de las variables. 
                        while(true){
                            // Selección de producto.
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
                                precio += 520;
                                break;
                            }else{
                                cout <<"Ingresa una opcion valida." << endl;
                            }
                        }

                        while(true){
                            // Selección de talla
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
                            // Selección de color
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
                            }else{
                                cout <<"Ingresa una opcion valida." << endl;
                            }
                        }

                        // Crear un nuevo objeto Producto.
                        Producto* producto = new Producto(descripcion, talla, color, precio);

                        // Agrega el producto creado al objeto Compra correspondiente dentro del vector clientes.
                        clientes[numCliente].buscarCompra(idCompra)->agregarProducto(producto);

                        // Obtener el monto total actual de la compra correspondiente.
                        float montoTotal = clientes[numCliente].buscarCompra(idCompra)->getMonto();

                        // Aumentar el monto total sumándole el precio del nuevo producto.
                        montoTotal += precio;

                        // Actualizar el monto total de la compra correspondiente.
                        clientes[numCliente].buscarCompra(idCompra)->setMonto(montoTotal);

                    }

                    // Obtener el monto total correspondiente según el ID de la compra actual.
                    float montoTotal = clientes[numCliente].buscarCompra(idCompra)->getMonto();

                    // Calcular el iva y el nuevo monto total.
                    float iva = montoTotal * 0.16;
                    montoTotal += iva;

                    // Establecer el nuevo monto total y el iva.
                    dynamic_cast<Compra_Tarjeta*>(clientes[numCliente].buscarCompra(idCompra))->setIva(iva); 
                    dynamic_cast<Compra_Tarjeta*>(clientes[numCliente].buscarCompra(idCompra))->setMonto(montoTotal);

                    // Mostrar al cliente el monto total.
                    cout << "\nEl total de su compra fue de: $" << montoTotal << endl;

                    // Simular el pago en terminal.
                    cout << "\n               Ingresar tarjeta               " << endl;
                    cout << "\n----------------------------------------------" << endl;
                    cout << "                 Pago exitoso                 " << endl;
                    cout << "----------------------------------------------" << endl;

                    // Imprimir el ticket de compra.
                    clientes[numCliente].mostrarCompras();

                    numCliente += 1; // Aumentar el contador de cliente.
                    regresarMenu = false; // Salir del menú de tipo de compra y regresar al menu principal.
                }else{
                    // Solicita al usuario ingresar de nuevo una opción si esta no es 1 o 2.
                    cout << "\nIngresa una opcion valida." << endl;
                }
            }

        // Imprime el historial de compras realizadas.
        } else if (opcion == 2) {
            cout << "\nEmpleado: " << nombre << endl;

            /*
            * Si la variable comprasRealizadas es igual a false quiere 
            * decir que no se ha registrado ninguna compra, por lo que se 
            * desplegará un mensaje informando al usuario sobre esto.
            * Por otra parte, si esta cambia a true al seleccionar
            * la opción 1 en el menú principal se imprime el historial.
            * Para esto se itera sobre un rango de índices con un ciclo for
            * desde 0 hasta numCliente - 1. Dentro de este se obtiene el nombre 
            * del cliente con respecto a la posición k del vector y se imprime. 
            * Luego, se muestra el ticket del cliente igualmente en la 
            * posición k del vector. 
            */
            if(comprasRealizadas == false){
                cout << "\nNo se han registrado compras aun." << endl;
            }else{
                for (int k = 0; k < numCliente ; k++) {
                string nombre = clientes[k].getNombre(); 
                cout << "\n";
                cout << nombre << endl; 
                clientes[k].mostrarCompras();
            }

            }

        // Finalizar la ejecución del programa.
        } else if (opcion == 3) {
            /*
            * Cambia la variable menuPrincipal de true a false para salir del 
            * ciclo while del menu principal y finalizar el programa. 
            */
            cout << "\n" << nombre << " tu sesion ha finalizado correctamente." << endl;
            menuPrincipal = false;
        
        // Opción invalida.
        } else {
            // Solicita al usuario ingresar de nuevo una opción si esta no esta entre 1-3.
            cout << "\nIngresa una opcion valida." << endl;
        }
    }
  
    return 0;
}