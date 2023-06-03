#include "tiendaropa.h"

int main() {
    
    cout << "Wardrobe Essentials Sistema de Compras" << endl;

    // Se declaran los objetos. 
    Compra_Efectivo compra1;
    Compra_Tarjeta compra2;

    // Esta sección es temporal, despues se utulizará la clase Cliente y Productos para estos datos. 
    string nombre;
    cout << "Nombre cliente: ";
    cin>> nombre;
    compra1.setNombre(nombre);
    compra2.setNombre(nombre);

    int monto;
    monto = 600;
    compra1.setMonto(monto);
    compra2.setMonto(monto);

    int id; 
    id = 123456;
    compra1.setIdCompra(id);
    compra2.setIdCompra(id);

    /*Se inicializa el ciclo while para establecer el metodo de pago, de esta 
    manera se puede imprimir el Ticket de compra con sus datos correspondientes.*/
    string metodoPago;
    int opcion = 0;

    while (opcion != 1 && opcion != 2 && opcion != 3) {
        cout << "\nSeleccione su método de pago:\n1. Efectivo\n2. Tarjeta\n3. Tarjeta a plazos\nInserte opción: ";
        cin >> opcion;

    if (opcion == 1) {
        //Realizar el pago en efectivo.  
        cout << "\nHa seleccionado Efectivo como método de pago." << endl;
        metodoPago = "Efectivo";
        compra1.setMetodoPago(metodoPago);

        int conPago;
        cout << "\nCantidad con la que se realizará el pago: ";
        cin>> conPago;
        compra1.setConPago(conPago);

        //Calculo del cambio. 
        int cambio;
        cambio = conPago - monto;
        compra1.setCambio(cambio);

        //Mostrar Ticket. 
        compra1.mostrarDatosPago();

    } else if (opcion == 2) {
        // Realizar pago con tarjeta sin plazos.
        cout << "\nHa seleccionado Tarjeta como método de pago." << endl;
        metodoPago = "Tarjeta";
        compra2.setMetodoPago(metodoPago);

        string titular;
        cout << "\nNombre del titular de la tarjeta: ";
        cin>> titular;
        compra2.setTitular(titular);
     
        string cp;
        while (true) {
        cout << "Código postal: ";
        cin >> cp;
        // Asegurar que sea un código postal valido. 
        if (cp.length() == 5) {
            compra2.setCp(cp);
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
            compra2.setNumero(numero);
            break;
        } else {
            cout << "Error: Debe ingresar exactamente 16 digitos." << endl;
        }
        }

        string vencimiento;
        cout << "Fecha de vencimiento mes/año: ";
        cin >> vencimiento;
        compra2.setVencimiento(vencimiento);

        string cvc;  
        while (true) {
        cout << "CVC: ";
        cin >> cvc;
        // Asegurar que sea un CVC valido. 
        if (cvc.length() == 3) {
            compra2.setCvc(cvc);
            break;
        } else {
            cout << "Error: Debe ingresar exactamente 3 digitos." << endl;
        }
        }
        //Mostrar Ticket. 
        compra2.mostrarDatosPago();

    } else if (opcion == 3) {
        cout << "\nHa seleccionado Tarjeta como método de pago." << endl;
        metodoPago = "Tarjeta";
        compra2.setMetodoPago(metodoPago);

        string titular;
        cout << "\nNombre del titular de la tarjeta: ";
        cin>> titular;
        compra2.setTitular(titular);

        // Asegurar que sea un código postal valido.  
        string cp;
        while (true) {
        cout << "Codigo postal: ";
        cin >> cp;
        if (cp.length() == 5) {
            compra2.setCp(cp);
            break;
        } else {
            cout << "Error: Debe ingresar exactamente 5 digitos." << endl;
        }
        }

        // Asegurar que sea un número de tarjeta valido. 
        string numero;
        while (true) {
        cout << "Número tarjeta: ";
        cin >> numero;
        if (numero.length() == 16) {
            compra2.setNumero(numero);
            break;
        } else {
            cout << "Error: Debe ingresar exactamente 16 digitos." << endl;
        }
        }

        string vencimiento;
        cout << "Fecha de vencimiento mes/año: ";
        cin >> vencimiento;
        compra2.setVencimiento(vencimiento);

        // Asegurar que sea un CVC valido. 
        string cvc;  
        while (true) {
        cout << "CVC: ";
        cin >> cvc;
        if (cvc.length() == 3) {
            compra2.setCvc(cvc);
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
            compra2.setPlazosPago(plazosPago);
        } else if (opcionPlazos == 2){
            plazosPago = 6;
            compra2.setPlazosPago(plazosPago);
        }else if (opcionPlazos == 3){
            plazosPago = 12;
            compra2.setPlazosPago(plazosPago);
        }else {
            cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
        }
        }
        // Mostrar Ticket. 
        compra2.mostrarDatosPago();

    }else {
        cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
    }
    } 
    return 0;
}
