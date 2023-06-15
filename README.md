# Descripción del programa
El proyecto es una aplicación para una tienda de ropa llamada "Esencia Boutique". El objetivo de su uso es permitir a los empleados que se encuentran en el área de caja en la tienda física registrar las compras realizadas, seleccionando el método de pago (efectivo o tarjeta), así como los productos. Mientras tanto, la aplicación se encargará de generar un ticket para el cliente, guardando este en el historial de compras, el cuál podrá ser revisado por los empleados. 

Para solucionar dicho problema se buscó dividir el programa de c++ en las siguientes cinco clases:
- Cliente: almacena el nombre del cliente que realizó la compra (en el formato cliente #)
- Productos: representa la selección del producto o productos  
- Compra: representa el id de la compra, el precio de los productos, el método de pago elegido por el cliente y los productos que este seleccione
- Compra con tarjeta: implementa la compra con el método de pago con tarjeta (basándose en el uso de terminal)
- Compra con efectivo: implementa la compra con el método de pago en efectivo (basándose en el uso de billetes y monedas)

# Funcionalidad
Como se mencionó anteriormente, la aplicación permite a los usuarios registrar compras, realizar pagos utilizando diferentes métodos de pago y ver el historial de compras. Para que esto sea posible su funcionamiento es el siguiente:

1. El programa da la bienvenida al usuario y solicita el nombre del empleado. 
2. Se muestra el menú principal con diferentes opciones: registrar compras, ver historial de compras y cerrar sesión.
3. Al seleccionar la opción de registrar compra, se solicita al usuario ingresar los detalles de la compra, como el método de pago y la cantidad de productos seleccionados. Dependiendo del método de pago elegido, se realizan diferentes acciones:
- Para pagos en efectivo, se solicita la información de cada producto seleccionado (descripción, talla, color) y se agrega a la compra del cliente con su precio correspondiente según la prenda. El monto total de la compra se va actualizando de acuerdo a la cantidad de productos y se muestra el precio total al cliente. Después se solicita la cantidad con la que se realizará el pago. Luego se entrega el ticket de compra y se regresa el cambio si es el caso.
- Para pagos con tarjeta, se realiza el mismo proceso antes mencionado para los productos. Sin embargo, en este caso se le indica al cliente la cantidad a pagar y se hace "el uso" de la terminal para la autorización del pago. Después se agrega al ticket información adicional como el número de cuenta, el número de autorización y se calcula el monto total de la compra con el 16% de IVA incluido mostrando incluso la cantidad de este. Luego se entrega el ticket de compra.
4. Al seleccionar la opción de ver historial de compras, se muestra el historial de todas las compras realizadas por número de cliente y su ticket de compra correspondiente. Si aún no existen compras realizadas se le informará al usuario. 
5. Al seleccionar la opción de cerrar sesión, se finaliza la ejecución del programa.

Nota: A lo largo del programa si el usuario no ingresa un número válido para las opciones disponibles este le solicitara al usuario que ingrese una opción válida, su entrada debe ser un número entero (tipo int). 

Para correr el programa en la terminal utilizamos:
- g++ main.cpp
- ./a

# UML & Main
Para dejar más clara la conexión entre el main y el UML, se mencionan las siguientes especificaciones: 
- Un vector de Cliente es creado en el main para generar un arreglo de clientes. 
- Cuando se selecciona la opción de registrar compra se crea el cliente y se guarda el parámetro de su nombre. La clase cliente se compone de un arreglo de compras, esto quiere decir que cada cliente tendrá su compra ya sea en efectivo o tarjeta. Una vez elegido el método de pago se pasarán los parámetros correspondientes a la clase compra respectivamente de acuerdo a su tipo. Parámetros como el monto de pago, iva (en tarjeta), cantidad con la que se pagó y cambio (en efectivo), serán igual a 0 hasta ser definidos o calculados según sea el caso, de acuerdo al precio de los productos seleccionados. 
- Una vez se establece el tipo de compra, comenzamos a trabajar en agregar el producto o productos, los cuales se pasan a la clase Compra para ser agregados en su arreglo de productos dentro de esta con respecto a sus parámetros.
- Después se definen los datos faltantes a partir del precio de los productos con el uso de los métodos y apuntadores, para de esta manera imprimir el ticket con el método de sobrescritura en las clases hijas de la función mostrarDatosPago() que está guardado dentro del método mostrarCompras() en la clase Cliente que se manda a llamar a través del cliente creado.
- En resumen se podría decir que la clase cliente cuenta con un arreglo de compras y las compras cuentan con un arreglo de productos. 

# Consideraciones
A continuación se identifican algunas limitaciones del programa, consideraciones y casos que harían que el programa dejará de funcionar correctamente: 
- La compra debe ser finalizada para salir y pasar al siguiente cliente, es decir solo se puede trabajar con uno a la vez. Una vez que la compra registrada finalice con la entrega del ticket, no será posible regresar a este cliente para realizar modificaciones o agregar otra compra. Por lo tanto, el set del nombre no es requerido, ya que este no se planea cambiar una vez que la compra sea realizada. 
- Las compras no pueden ser eliminadas. 
- En la compra tarjeta los atributos de cuenta y autorización no cuentan con getters, ya que esos datos solo se utilizarán para el ticket de compra buscando mantener la confidencialidad de esta. Por otra parte, se mantuvieron los setters para obtener del cliente el número de cuenta del pago completo y la autorización después del uso de la terminal aunque no se utilicen en este versión del programa, debido a que podrían implementarse en un futuro. 
- En la clase compra a pesar de que todos los getters y setters no se utilicen se mantuvieron, debido a que en un futuro podrían realizarse modificaciones en el programa donde por ejemplo: se establezca un ID más complejo o se revisen las ventas según su método de pago. 
- Ingresar en la compra efectivo una cantidad con la que se pagará menor al monto, provocaría un error en el programa. 
- Se asume que la forma de pago será exitosa, no se toma en consideración si la tarjeta es rechazada, ya que solamente solamente se simula el uso de una terminal. Además por este motivo los datos bancarios no se solicitan al cliente. 
- No es posible modificar los productos esto incluye su descripción, colores, tallas o precio establecido. Por lo tanto, sus atributos no cuentan con setters y getters, ya que no son necesarios debido a que los datos se guardan en los parámetros del producto y en el futuro sería mejor utilizar un ID para identificar cada producto.
- No existe un inventario de productos, así que estos no cuentan con un código individual para ser buscados o seleccionados, por lo que sus parámetros deben ser definidos de forma individual en el main. En el futuro podrían existir diferentes ID que incluyan los parámetros del producto, para de esta manera hacer lo anterior posible. 
- Una vez realizada la selección el producto creado no podrá ser eliminado, en el futuro esto podría ser agregado con una función. 
- Al imprimir el ticket no se muestra una cantidad y precio individual para productos repetidos, es decir, si llevas dos blusas iguales se imprimirá el producto uno debajo del otro, no como blusa (descripción del producto) 2 (precio individual) precio x2). Esto podría ser agregado una vez que se incremente la complejidad del programa.  
- No existe la clase empleado, por lo que sólo se solicita el nombre del empleado para mostrarle sus ventas al ver el historial de compras y al final del programa para informarle que su sesión ha finalizado correctamente. Sus datos no serán guardados y no se verán las ventas realizadas por cada empleado debido a que este programa está diseñado para uno solo en el momento de su uso, sin embargo, esto podría ser implementado en un futuro si se busca expandir la capacidad del programa para llevar un conteo de las ventas realizadas por cada empleado y así de esta manera conocer su desempeño.
- Ingresar un carácter, palabra o símbolo en las opciones del menú o listado de productos provocará un comportamiento inusual en el programa.
- Debido a que los arreglos son vectores, estos no tienen un tamaño límite definido en el programa, sin embargo debemos tomar en cuenta que se podrán seguir agregando objetos y datos hasta que el espacio en la memoria se acabe. Podemos tomar en consideración agregarle un tamaño adecuado al vector según la cantidad de registros límites deseados así como el espacio disponible en la memoria. 

# Adicionales 
Además de los temas y bibliotecas vistas en clase que se encuentran dentro del programa, se implementaron otras bibliotecas, el uso de vectores y dynamic cast. 

Bibliotecas:
- #include <vector>: permite el uso de vectores gracias a que cuenta con el contenedor y las definiciones de sus funciones 
- #include <iomanip>: permite la precisión decimal al momento de mostrar los precios y el monto en el programa
  
Vectores:
- Los vectores son arreglos dinámicos dentro de un contenedor, que cuentan con la habilidad de modificar de forma automática su tamaño dependiendo de si un objeto es agregado o eliminado, es decir no cuentan con un tamaño fijo. Los datos de los vectores son ingresados hasta el final y cuentan con varias funciones que se pueden utilizar. Por ejemplo, el programa cuenta con la función .push_back() para agregar objetos y datos al final de los vectores creados.
  
Dynamic Cast: 
- Recordemos que cast es un operador que nos permite convertir de un tipo de dato a otro, por lo que un dynamic cast nos permite realizar este cast durante el tiempo de ejecución de forma segura, ya que para ser aplicado cuenta con ciertas condiciones. Para utilizarlo debemos contar con una función virtual en la clase base y el uso de polimorfismo. Por lo tanto, en el proyecto este es implementado en dos casos, para convertir un puntero de tipo base (Compra*) a un puntero de tipo derivado (Compra_Efectivo*) y de la misma forma con (Compra_Tarjeta*), con el fin de permitir el acceso a las funciones y miembros específicos de la clase Compra_Efectivo y Compra_Tarjeta que no están presentes en la clase base Compra guardada dentro del cliente donde se crean los objetos de tipo compra efectivo o tarjeta. 


Fuentes: 
- “Vector in C++ STL.” GeeksforGeeks, 20 Mar. 2023, www.geeksforgeeks.org/vector-in-cpp-stl/. 
- "Dynamic_cast in C++." GeeksforGeeks, 20 May 2021, www.geeksforgeeks.org/dynamic-_cast-in-cpp/.
