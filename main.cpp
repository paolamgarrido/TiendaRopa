/* Falta comentar todo el código y se
* elimino el main anterior debido a que
* no había comprendido correctamente el 
* uso de apuntadores y polimorfismo.
* Por lo tanto, sigo trabajando en el
* para determinar el funcionamiento del 
* programa. Sin embargo, esta entrega cuenta 
* con la implementación de la clase abstracta.*/

int main(){
    Cliente c("nombre");
    Producto *p = new Producto("Camisa", "S", "Blanco", 250);
    c.agregarCompraEfectivo(1, 250, "efectivo", 300, 50);
    c.buscarCompra(1)->getIdCompra();
    c.buscarCompra(1)->agregarProducto(p);
    c.agregarCompraTarjeta(2, 290, "tarjeta", 40);
    c.buscarCompra(2)->getIdCompra();
    c.buscarCompra(2)->agregarProducto(p);
    cout << "Gracias por comprar con nosotros " << c.getNombre() << ", te entrego tu comprobante de pago." << endl;
    c.mostrarCompras();
}
