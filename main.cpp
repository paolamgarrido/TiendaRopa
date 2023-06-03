//En este avance se agrega el uso de polimorfismo. 

#include "compra.h"

int main() {
    cout << "Wardrobe Essentials Sistema de Compras" << endl;
    cout << "\n¡Bienvenid@ comienza a explorar nuestros productos y realiza tus compras!" << endl;

    // Variable constante para establecer el numero de compras posibles. 
    const int numCompras = 3;

    // Crear los objetos de la clase Compra implementando polimorfismo. 
    Compra* compras[numCompras] = { nullptr };

    int opcionM = 0;    // Inicializar variable para el menu de opciones. 
    int numComprasRealizadas = 0;   //Inicializar contador para las compras realizadas. 

    while (opcionM != 3) {
        // Menu principal.
        cout << "\n1. Realizar Compra\n2. Historial de compras\n3. Salir\nInserte opción: ";
        cin >> opcionM;

        if (opcionM == 1) {
            int opcionPago = 0;     // Inicializar variable para el menu de opciones de pago. 
            bool menuPrincipal = false;     // Variable de control para volver al menu principal. 
            // Revisa si el numero máximo de compras que se pueden realizar fue alcanzado. 
            if (numComprasRealizadas >= numCompras) {
                cout << "Ya ha alcanzado el limite de compras permitidas. No puede realizar mas compras." << endl;
                continue;
            }

            // Menú para el metodo de pago. 
            while (!menuPrincipal) {
                cout << "\nSeleccione su metodo de pago:\n1. Efectivo\n2. Tarjeta\n3. Tarjeta (pago a plazos)\n4. Volver al menu principal\nInserte opcion: ";
                cin >> opcionPago;

                if (opcionPago == 1) {
                    // Se crea instancia de la clase Compra_Efectivo. 
                    for (int i = 0; i < numCompras; i++) {
                        if (compras[i] == nullptr) {
                            compras[i] = new Compra_Efectivo();
 
                            string metodoPago;
                            cout << "\nHa seleccionado Efectivo como método de pago." << endl;
                            metodoPago = "Efectivo";
                            compras[i]->setMetodoPago(metodoPago);

                            // Nota: Esta sección es temporal, despues se utulizará la clase Cliente y Productos para estos datos. 
                            string nombre;
                            cout << "\nNombre cliente: ";
                            cin>> nombre;
                            compras[i]->setNombre(nombre);

                            int monto;
                            monto = 600;
                            compras[i]->setMonto(monto);

                            int id; 
                            id = 178452 + i;
                            compras[i]->setIdCompra(id);

                            // Realizar configuraciones específicas para la compra en efectivo.
                            int conPago;
                            cout << "Cantidad con la que se realizará el pago: ";
                            cin>> conPago;
                            static_cast<Compra_Efectivo*>(compras[i])->setConPago(conPago);
 
                            int cambio;
                            cambio = conPago - monto;
                            static_cast<Compra_Efectivo*>(compras[i])->setCambio(cambio);

                            // Incrementar el contador de compras realizadas
                            numComprasRealizadas++;

                            // Mostrar Ticket.
                            cout << "\nTicket de Compra #" << i + 1 << endl;
                            compras[i]->mostrarDatosPago();
                            break;
                        }
                    }
                break;
                } else if (opcionPago == 2) {
                    // Se crea instancia de la clase Compra_Tarjeta.
                    for (int i = 0; i < numCompras; i++) {
                        if (compras[i] == nullptr) {
                            compras[i] = new Compra_Tarjeta();
                            
                            cout << "\nHa seleccionado Tarjeta como método de pago." << endl;
                            string metodoPago;
                            metodoPago = "Tarjeta";
                            compras[i]->setMetodoPago(metodoPago);

                            // Esta sección es temporal, despues se utulizará la clase Cliente y Productos para estos datos. 
                            string nombre;
                            cout << "\nNombre cliente: ";
                            cin>> nombre;
                            compras[i]->setNombre(nombre);

                            int monto;
                            monto = 600;
                            compras[i]->setMonto(monto);

                            int id; 
                            id = 178452 + i;
                            compras[i]->setIdCompra(id);

                            // Realizar configuraciones específicas para la compra con tarjeta.
                            string titular;
                            cout << "Nombre del titular de la tarjeta: ";
                            cin>> titular;
                            static_cast<Compra_Tarjeta*>(compras[i])->setTitular(titular);
                        
                            string cp;
                            while (true) {
                            cout << "Código postal: ";
                            cin >> cp;
                            // Asegurar que sea un código postal valido. 
                            if (cp.length() == 5) {
                                static_cast<Compra_Tarjeta*>(compras[i])->setCp(cp);
                                break;
                            } else {
                                cout << "Error: Debe ingresar exactamente 5 digitos." << endl;
                            }
                            }

                            string numero;
                            while (true) {
                            cout << "Número tarjeta: ";
                            cin >> numero;
                            // Asegurar que sea un número de tarjeta valido. 
                            if (numero.length() == 16) {
                                static_cast<Compra_Tarjeta*>(compras[i])->setNumero(numero);
                                break;
                            } else {
                                cout << "Error: Debe ingresar exactamente 16 digitos." << endl;
                            }
                            }

                            string vencimiento;
                            cout << "Fecha de vencimiento mes/año: ";
                            cin >> vencimiento;
                            static_cast<Compra_Tarjeta*>(compras[i])->setVencimiento(vencimiento);

                            string cvc;  
                            while (true) {
                            cout << "CVC: ";
                            cin >> cvc;
                            // Asegurar que sea un CVC valido. 
                            if (cvc.length() == 3) {
                                static_cast<Compra_Tarjeta*>(compras[i])->setCvc(cvc);
                                break;
                            } else {
                                cout << "Error: Debe ingresar exactamente 3 digitos." << endl;
                            }
                            }

                            // Incrementar el contador de compras realizadas
                            numComprasRealizadas++;

                            // Mostrar el ticket de la compra
                            cout << "\nTicket de Compra #" << i + 1 << endl;
                            compras[i]->mostrarDatosPago();
                            break;
                        }
                    }
                break;
                }  else if (opcionPago == 3) {
                    // Se crea instancia de la clase Compra_Tarjeta.
                    for (int i = 0; i < numCompras; i++) {
                        if (compras[i] == nullptr) {
                            compras[i] = new Compra_Tarjeta();
                           
                            cout << "\nHa seleccionado Tarjeta como método de pago." << endl;
                            string metodoPago;
                            metodoPago = "Tarjeta";
                            compras[i]->setMetodoPago(metodoPago);

                            // Esta sección es temporal, despues se utulizará la clase Cliente y Productos para estos datos. 
                            string nombre;
                            cout << "\nNombre cliente: ";
                            cin>> nombre;
                            compras[i]->setNombre(nombre);

                            int monto;
                            monto = 600;
                            compras[i]->setMonto(monto);

                            int id; 
                            id = 178452 + i;
                            compras[i]->setIdCompra(id);

                            // Realizar configuraciones específicas para la compra en efectivo.
                            string titular;
                            cout << "Nombre del titular de la tarjeta: ";
                            cin>> titular;
                            static_cast<Compra_Tarjeta*>(compras[i])->setTitular(titular);
                        
                            string cp;
                            while (true) {
                            cout << "Código postal: ";
                            cin >> cp;
                            // Asegurar que sea un código postal valido. 
                            if (cp.length() == 5) {
                                static_cast<Compra_Tarjeta*>(compras[i])->setCp(cp);
                                break;
                            } else {
                                cout << "Error: Debe ingresar exactamente 5 digitos." << endl;
                            }
                            }

                            string numero;
                            while (true) {
                            cout << "Número tarjeta: ";
                            cin >> numero;
                            // Asegurar que sea un número de tarjeta valido. 
                            if (numero.length() == 16) {
                                static_cast<Compra_Tarjeta*>(compras[i])->setNumero(numero);
                                break;
                            } else {
                                cout << "Error: Debe ingresar exactamente 16 digitos." << endl;
                            }
                            }

                            string vencimiento;
                            cout << "Fecha de vencimiento mes/año: ";
                            cin >> vencimiento;
                            static_cast<Compra_Tarjeta*>(compras[i])->setVencimiento(vencimiento);

                            string cvc;  
                            while (true) {
                            cout << "CVC: ";
                            cin >> cvc;
                            // Asegurar que sea un CVC valido. 
                            if (cvc.length() == 3) {
                                static_cast<Compra_Tarjeta*>(compras[i])->setCvc(cvc);
                                break;
                            } else {
                                cout << "Error: Debe ingresar exactamente 3 digitos." << endl;
                            }
                            }

                            // Seleccionar los meses de plazo para el pago. 
                            int plazosPago;
                            int opcionPlazos;
                            while(opcionPlazos != 1 && opcionPlazos != 2 && opcionPlazos != 3){
                                cout << "\nSelecione plazos de pago a meses sin intereses:\n1. 3 meses\n2. 6 meses\n3. 12 meses\nInserta opción: ";
                                cin>> opcionPlazos;
                            if (opcionPlazos == 1){
                                plazosPago = 3;
                                static_cast<Compra_Tarjeta*>(compras[1])->setPlazosPago(plazosPago);
                            } else if (opcionPlazos == 2){
                                plazosPago = 6;
                                static_cast<Compra_Tarjeta*>(compras[1])->setPlazosPago(plazosPago);
                            }else if (opcionPlazos == 3){
                                plazosPago = 12;
                                static_cast<Compra_Tarjeta*>(compras[1])->setPlazosPago(plazosPago);
                            }else {
                                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                            }
                            }

                            // Incrementar el contador de compras realizadas.
                            numComprasRealizadas++;

                            // Mostrar el ticket de la compra.
                            cout << "\nTicket de Compra #" << i + 1 << endl;
                            compras[i]->mostrarDatosPago();
                            break;
                        }
                    }
                break;
                } else if (opcionPago == 4) {
                    menuPrincipal = true; // Volver al menú principal.
                } else {
                    cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                }
            }
        } else if (opcionM == 2) {
            if (numComprasRealizadas == 0) {
                cout << "Aún no se han realizado compras." << endl;
            } else {
                // Acceder a los objetos compras para mostrar el historial.
                for (int i = 0; i < numCompras; i++) {
                    if (compras[i] != nullptr) {
                        cout << "\nTicket de Compra #" << i + 1 << endl;
                        compras[i]->mostrarDatosPago();
                    }
                }
            }
        } else if (opcionM == 3) {
            cout << "\n¡Gracias por comprar en Wardrobe Essentials, vuelve pronto!" << endl;
            break;
        } else {
            cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
        }
    }

    // Liberar la memoria de los objetos compras,
    for (int i = 0; i < numCompras; i++) {
        delete compras[i];
    }

    return 0;
}
