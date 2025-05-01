
# Informe Práctica 8
## Ejercicio Practico 1 (Bucle de Comunicación UART 2)

###  Código fuente operativo
 ```cpp
#include <Arduino.h>

// Definiciones de pines para UART
#define RXD0 0   // GPIO0 (UART0 RX)
#define TXD0 1   // GPIO1 (UART0 TX)
#define RXD2 16  // GPIO16 (UART2 RX)
#define TXD2 17  // GPIO17 (UART2 TX)

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
```

### Descripción del código
Este programa permite que el ESP32 se comunique usando dos puertos serie: UART0 y UART2.

- **UART0** : Se conecta al monitor serie del ordenador, donde podemos escribir y ver datos
- **UART2** : Usa los pines GPIO16(RX) y GPIO17(TX) para enviar y recibir datos

Funcionaria de la siguiente manera:

- Si escribimos algo en el monitor serie (UART0), el ESP32 lo envía por UART2
- Si UART2 recibe algo lo envía de vuelta al monitor serie

Esto nos permite comprobar si la UART2 funciona correctamente.

### Entradas y salidas por consola
**Entrada desde el monitor serie**
Escribimos a través del teclado cualquier carácter . Por ejemplo, una letra, la "a".

**Lo que aparece como salida en pantalla**
Siguiendo el ejemplo anterior, por pantalla aparecería lo siguiente: 

 ```cpp
Tú escribiste: a  
UART2 dice: a
```

Esto indica que el carácter "a" ha sido leído por la ESP32 desde el monitor serie, enviado por la UART2, y recibido de vuelta, así demostrando que la comunicación si que funciona.
