# Descripción del programa
El proyecto es una aplicación para una tienda de ropa llamada "Esencia Boutique". El objetivo de su uso es permitir a los empleados que se encuentran en el área de caja en la tienda física registrar las compras realizadas, seleccionando el método de pago (efectivo o tarjeta), así como los productos. Mientras tanto, la aplicación se encargará de generar un ticket para el cliente, guardando una copia de este en el historial de compras, que podrá ser revisado por los empleados para uso personal de la tienda en el control de ventas. 

Para solucionar dicho problema se buscó dividir el programa de c++ en las siguientes cinco clases:
- Cliente: almacena el nombre del cliente que realizó la compra (en el formato cliente #)
- Productos: representa la selección del producto o productos comprados por el cliente 
- Compra: registra el id de la compra, el precio de la selección de productos, el método de pago elegido por el cliente y los productos que este seleccione
- Compra con tarjeta: implementa el método de pago (basándose en el uso de terminal)
- Compra con efectivo: implementa el método de pago (basándose en el uso de billetes y monedas)

# Funcionalidad
Como se mencionó anteriormente, la aplicación permite a los usuarios registrar compras, realizar pagos utilizando diferentes métodos de pago y ver el historial de compras. Para que esto sea posible su funcionamiento es el siguiente:

1. El programa muestra un menú principal con diferentes opciones: registrar compras, ver historial de compras y cerrar sesión.
2. Al seleccionar la opción de registrar compra, se solicita al usuario ingresar los detalles de la compra, como el método de pago y la cantidad de productos seleccionados. Dependiendo del método de pago elegido, se realizan diferentes acciones:
- Para pagos en efectivo, se solicita la información de cada producto seleccionado (descripción, talla, color) y se agrega a la compra del cliente con su precio correspondiente según la prenda. El monto total de la compra se va actualizando de acuerdo a la cantidad de productos y se muestra el precio total al cliente. Después se solicita la cantidad con la que se realizará el pago. Luego se entrega el ticket de compra y se regresa el cambio si es el caso.
- Para pagos con tarjeta, se realiza el mismo proceso antes mencionado para los productos. Sin embargo, en este caso se le indica al cliente la cantidad a pagar y se hace "el uso" de la terminal para la autorización del pago. Después se agrega al ticket información adicional como el número de cuenta, el número de autorización y se calcula el monto total de la compra con el 16% de IVA incluido mostrando incluso la cantidad de este. Luego se entrega el ticket de compra
3. Al seleccionar la opción de ver historial de compras, se muestra el historial de todas las compras realizadas por número de cliente y su ticket de compra correspondiente. Si aún no existen compras realizadas se le informará al usuario. 
4. Al seleccionar la opción de cerrar sesión, se finaliza la ejecución del programa.

Nota: A lo largo del programa si el usuario no ingresa un número válido para las opciones disponibles este le solicitara al usuario que ingrese una opción válida, su entrada debe ser un número entero (tipo int). 

# UML & Main
Para dejar más clara la conexión entre el main y el UML, se mencionan las siguientes especificaciones: 
- Un vector de Cliente es creado para generar un arreglo de clientes. 
- Cuando se selecciona la opción de registrar compra se crea el cliente y se guarda el parámetro de su nombre. La clase cliente se compone de un arreglo de compras, esto quiere decir que cada cliente tendrá su compra ya sea en efectivo o tarjeta. Una vez elegido el método de pago se pasarán los parámetros correspondientes a la clase compra respectivamente de acuerdo a su tipo. Parámetros como el monto de pago, iva (en tarjeta), cantidad con la que se pagó y cambio (en efectivo), serán igual a 0 hasta ser definidos o calculados según sea el caso, de acuerdo al precio de los productos seleccionados. 
- Una vez se establece el tipo de compra, comenzamos a trabajar en agregar el producto o productos, los cuales se pasan a la clase Compra para ser agregados en su arreglo de productos dentro de esta con respecto a sus parámetros.
- Después se definen los datos faltantes a partir del precio de los productos con el uso de los métodos y apuntadores, para de esta manera imprimir el ticket con el método de sobrescritura en las clases hijas de la función mostrarDatosPago() que está guardado dentro del método mostrarCompras() en la clase Cliente que se manda a llamar a través del cliente creado. 

# Consideraciones
A continuación se identifican algunas limitaciones del programa y casos que harían que el programa dejará de funcionar correctamente: 
- La compra debe ser finalizada para salir y pasar al siguiente cliente, es decir solo se puede trabajar con uno a la vez. Una vez que la compra registrada finalice con la entrega del ticket, no será posible regresar a este cliente para realizar modificaciones o agregar otra compra. 
- Se asume que la forma de pago será exitosa, no se toma en consideración si el cliente no tiene suficiente efectivo o la tarjeta es rechazada. En el caso de la tarjeta se simula el uso de una terminal, por lo que los datos bancarios no se solicitan al cliente. 
- No es posible modificar los productos esto incluye sus colores, tallas o precios. 
- Al imprimir el ticket no se muestra una cantidad y precio individual para productos repetidos, es decir, si llevas dos blusas iguales se imprimirá el producto uno debajo del otro, no como blusa (descripción del producto) 2 (precio individual) precio x2). 
- No existe un inventario de productos, así que estos no cuentan con un código individual para ser buscados o seleccionados, por lo que sus parámetros deben ser definidos de forma individual en el main. 
- Una vez realizada la selección el producto no podrá ser eliminado.  
- Las compras no pueden ser eliminadas. 
- No existe la clase empleado, por lo tanto, solo se solicita el nombre del empleado para informarle al final del programa con el uso de su nombre que la sesión ha finalizado correctamente. Sus datos no serán guardados y no se verán las ventas realizadas por cada empleado.
- Ingresar un carácter, palabra o símbolo en las opciones del menú o listado de productos, provocaría un comportamiento inusual en el programa.
- Ingresar en la compra efectivo una cantidad con la que se pagará menor al monto, provocaría un error en el programa. 

# Adicionales 
Además de los temas y bibliotecas vistas en clase que se encuentran dentro del programa, se implementaron otras bibliotecas, el uso de vectores y dynamic cast. 

Bibliotecas
-.
-.
Vectores
-.
-.
Dynamic Cast 
-.
-.
