//Luis Pedro Gonzalez 21513

//agregra librerias 

#include <SPI.h> //Incluir Librería de comunicación SPI
#include <SD.h> //Incluir librería para la memoria microSD

// Declaración de variables
int opcionUsuario; // Variable que almacena la opción elegida por el usuario
char entradaSerial; // Variable que almacena el carácter leído desde el puerto serial
int imagen; //bandera para cheuqear la imagen que se selecciono 

File myFile; //Se define myFile como tipo archivo


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
  SPI.setModule(0); //Utilizar el SPI Module 0


  Serial.print("Initializing SD card..."); //Indicar que se está inicializando la memoria
  pinMode(PA_3, OUTPUT); //poner el pin CS como output, es el slave selet

  if (!SD.begin(PA_3))
   {
       Serial.println("initialization failed!");
       return;
   }
   Serial.println("initialization done.");
  
}

// Función que se ejecuta en bucle continuamente
void loop() {
  if (Serial.available()) { // Esperar hasta que haya datos disponibles en el buffer serial
    entradaSerial = Serial.read(); // Leer un carácter desde el puerto serial

// Comprobar qué opción ha introducido el usuario
  if (entradaSerial == '1'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen 1.");
    imagen = 1;// bandera de l aimagen 1
  }
  else if (entradaSerial == '2'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen 2.");
    imagen = 2; //bandera de la image 2 
  }
  else if (entradaSerial == '3'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen 3.");
    imagen = 3; //bandera de la imagen 3
  }
// Si el usuario introduce una opción no válida.
  else {
    Serial.println(); // Agregar un salto de línea
    Serial.println("Selección no válida. Intenta de nuevo.");
    imagen = 0; // re reincia la bandera 
    mostrarMenu(); // Mostrar el menú nuevamente después de indicar que la opción no es válida.
    
  }

  }
  imagenes();// funcion que abre las imagenes 
}



//funcion para abrir las imagenes

void imagenes(){
  if (imagen == 1){// si la imagen que se selcciona es 1
    myFile = SD.open("imagen1.txt"); // abrir el archivo con el nombre 
   
    if (myFile)
    {
        Serial.println("imagen1.txt:");

        // leer el archivo hasta que no se enceuntre nada mas 
        while (myFile.available())//leer el archivo complto 
        {
            Serial.write(myFile.read());// mostarr que se esta leyendo 
        }
        //cerrar el archivo 
        myFile.close();
      Serial.println('\n'); //salto de linea 

    }
    else
    {
        // si el archivo no logro abrirse se muestra el mensaje siguiente
        Serial.println("Error al abrir imagen.txt");
    }

  }
  imagen = 0; // se reinicia la bandera de imagen 
  
  }
