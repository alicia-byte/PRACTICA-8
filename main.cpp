#include <Arduino.h>

// Definiciones de pines para UART
#define RXD0 0   // GPIO0
#define TXD0 1   // GPIO1
#define RXD2 16  // GPIO16
#define TXD2 17  // GPIO17

void setup() {
  // Inicialización de UART0 (Serial) y UART2
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
}



void loop() {
  // Lectura de UART0 (Serial) y envío a UART2 (Serial2)
  if (Serial.available()) {
    char c = Serial.read();              // Leer carácter de la terminal
    Serial.print("Tú escribiste: ");     // Eco de lo que se escribió
    Serial.println(c);                   // Mostrar el carácter
    Serial2.write(c);                    // Enviar a UART2
  }

  // Lectura de UART2 (Serial2) y envío a UART0 (Serial)
  if (Serial2.available()) {
    char c = Serial2.read();             // Leer carácter de UART2
    Serial.print("UART2 dice: ");        // Mostrar que proviene de UART2
    Serial.println(c);                   // Mostrar el carácter
  }
}