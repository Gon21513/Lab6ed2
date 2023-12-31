// Declaración de variables
int opcionUsuario; // Variable que almacena la opción elegida por el usuario
char entradaSerial; // Variable que almacena el carácter leído desde el puerto serial

// Función para mostrar un menú al usuario a través de la comunicación serial.
void mostrarMenu() {
    // Imprime las opciones de imágenes disponibles.
    Serial.println("Seleccione 1 para Imagen 1"); 
    Serial.println("Seleccione 2 para Imagen 2");
    Serial.println("Seleccione 3 para Imagen 3");
    // Solicita al usuario que introduzca su elección.
    Serial.print("Introduce tu elección: ");
}

// Función que se ejecuta una vez al inicio del programa
void setup() {
  Serial.begin(9600); // Inicializar la comunicación serial a una velocidad de 9600 baudios
  mostrarMenu(); // Muestra el menú al usuario por primera vez
}

// Función que se ejecuta en bucle continuamente
void loop() {
  if (Serial.available()) { // Esperar hasta que haya datos disponibles en el buffer serial
    entradaSerial = Serial.read(); // Leer un carácter desde el puerto serial

// Comprobar qué opción ha introducido el usuario
  if (entradaSerial == '1'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen 1.");
  }
  else if (entradaSerial == '2'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen 2.");
  }
  else if (entradaSerial == '3'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen 3.");
  }
// Si el usuario introduce una opción no válida.
  else {
    Serial.println(); // Agregar un salto de línea
    Serial.println("Selección no válida. Intenta de nuevo.");
    mostrarMenu(); // Mostrar el menú nuevamente después de indicar que la opción no es válida.
  }

  }
}
