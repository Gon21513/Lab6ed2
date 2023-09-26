void mostrarMenu() {
    Serial.println("Por favor, selecciona una imagen:");
    Serial.println("Imagen 1.");
    Serial.println("Imagen 2.");
    Serial.println("Imagen 3.");
    Serial.print("Introduce tu elección: ");
}

void procesarSeleccion(String seleccion) {
    if (seleccion == "1") {
        Serial.println("Has seleccionado la imagen 1.");
    } else if (seleccion == "2") {
        Serial.println("Has seleccionado la imagen 2.");
    } else if (seleccion == "3") {
        Serial.println("Has seleccionado la imagen 3.");
    } else {
        Serial.println("Selección no válida. Intenta de nuevo.");
    }
}

void setup() {
    Serial.begin(9600);
    mostrarMenu();
}

void loop() {
    if (Serial.available()) {
        String opcion = Serial.readStringUntil('\n');
        procesarSeleccion(opcion);
        delay(1000); // Espera un segundo antes de mostrar el menú nuevamente
        mostrarMenu();
    }
}
