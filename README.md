# Buenas-Practicas-con-Arduino

En el mundo de Arduino, declarar los pines no utilizados como salidas es una práctica común para evitar ruidos electromagnéticos y potenciales problemas de bloqueo. Aquí te explico por qué y cómo hacerlo:

¿Por qué declarar los pines no utilizados como salidas?

1. Ruido Electromagnético: Los pines no utilizados que están en modo de entrada (el estado predeterminado) pueden actuar como antenas y recoger ruido electromagnético del entorno. Esto puede generar fluctuaciones en los niveles de voltaje que pueden afectar el comportamiento del Arduino.
2. Estado Indeterminado: Los pines configurados como entradas pero no conectados pueden quedar en un estado flotante (indeterminado). Esto significa que su voltaje puede variar aleatoriamente entre alto y bajo, lo que puede causar comportamiento errático en el microcontrolador.
Consumo de Energía: Aunque menos significativo, los pines en estado flotante pueden consumir energía innecesariamente debido a las fluctuaciones de voltaje.
Cómo declarar los pines no utilizados como salidas.
En tu programa de Arduino, puedes declarar los pines no utilizados como salidas en la sección setup(). Aquí tienes un ejemplo de cómo hacerlo:

# :construction: Código

```cpp
void setup() {
  // Declarar pines utilizados
  pinMode(pinUtilizado1, OUTPUT);
  pinMode(pinUtilizado2, INPUT);

  // Declarar pines no utilizados como salidas
  for (int i = 0; i <= 13; i++) {
    if (i != pinUtilizado1 && i != pinUtilizado2) {
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);  // Opcional: Establecer el estado bajo para minimizar el consumo
    }
  }
}

void loop() {
  // Tu código aquí
}
```

![Código en Modo Oscuro](https://github.com/uagaviria/Buenas-Practicas-con-Arduino/blob/main/img/code1.png)
