# Descripción del programa
Este programa consiste en una tienda física de básicos de ropa y tiene como objetivo realizar a través de una selección de productos por el cliente una compra, la cuál podrá ser completada pagando con tarjeta o efectivo. Para solucionar dicho problema se buscó dividir el programa de c++ en las siguientes cinco clases:
- Cliente: almacena los datos del cliente 
- Producto: representa la selección de productos disponibles 
- Compra: registra el precio de la selección de productos y el método de pago 
- Compra con tarjeta: implementa el método de pago 
- Compra con efectivo: implementa el método de pago 

# Funcionalidad
En primera instancia el menú principal donde se trabajara solicitará los datos del cliente como nombre y formas de contacto para comenzar con el proceso. Después por medio de un menú de opciones, se permitirá al cliente tener acceso a los productos y sus precios con las características mostradas a continuación en el siguiente orden:
1. Elegir entre camiseta, sudadera y pantalonera.
2. Seleccionar el color: blanco, negro, beige o verde militar. 
3. Definir talla: S (chica), M (mediana) o G (grande).
4. Opción de pagar o seguir comprando. 

De esta manera el cliente podrá seleccionar sus productos, para luego pasar a la compra donde se desplegaran las dos opciones de método de pago. En caso de que la compra se realice a través de la clase compra con tarjeta se pedirá al cliente los datos esenciales de su tarjeta para cubrir el monto, mientras que si elige la clase pago con efectivo se mostrará el cambio de dicho monto. Por último, con el uso de la clase compra, se imprimirá un ticket que muestre el identificador de la compra, nombre del cliente (uso clase cliente), información de los productos (uso clase productos), monto total, método de pago y sus datos dependiendo si fue con tarjeta o efectivo. Al final del menú principal se permitirá registrar al siguiente cliente o salir del programa. 

# Consideraciones
A continuación se identifican las limitaciones que harían que el programa deje de funcionar: 
- La compra debe ser finalizada para salir y pasar al siguiente cliente.
- Se asume que la forma de pago será exitosa, no se toma en consideración si el cliente no tiene suficiente efectivo o la tarjeta es rechazada.
- Solo se puede trabajar con un cliente a la vez.
- No es posible agregar más productos, colores, tallas o modificar los precios.  
- Una vez realizada la selección el producto no podrá ser eliminado.   
- No se guardan los datos del cliente una vez que el proceso termina y el factor del stock de los productos no se toma en cuenta, sin embargo pueden ser o no agregados en un futuro avance del proyecto. 
