# Buenas-Practicas-con-Arduino

En el mundo de Arduino, declarar los pines no utilizados como salidas es una práctica común para evitar ruidos electromagnéticos y potenciales problemas de bloqueo. Aquí te explico por qué y cómo hacerlo:

¿Por qué declarar los pines no utilizados como salidas?

1. Ruido Electromagnético: Los pines no utilizados que están en modo de entrada (el estado predeterminado) pueden actuar como antenas y recoger ruido electromagnético del entorno. Esto puede generar fluctuaciones en los niveles de voltaje que pueden afectar el comportamiento del Arduino.
2. Estado Indeterminado: Los pines configurados como entradas pero no conectados pueden quedar en un estado flotante (indeterminado). Esto significa que su voltaje puede variar aleatoriamente entre alto y bajo, lo que puede causar comportamiento errático en el microcontrolador.
Consumo de Energía: Aunque menos significativo, los pines en estado flotante pueden consumir energía innecesariamente debido a las fluctuaciones de voltaje.
Cómo declarar los pines no utilizados como salidas.
En tu programa de Arduino, puedes declarar los pines no utilizados como salidas en la sección setup(). Aquí tienes un ejemplo de cómo hacerlo:

# :construction: Código para Arduino UNO

![Código en Modo Oscuro](https://github.com/uagaviria/Buenas-Practicas-con-Arduino/blob/main/img/code1.png)

En este ejemplo, los pines pinUtilizado1 y pinUtilizado2 son los pines que realmente usas en tu proyecto. El resto de los pines (del 0 al 13) en este caso arduino uno, se declaran como salidas y se ponen en estado bajo. Ajusta el rango del bucle for según los pines disponibles en tu modelo de Arduino.

Si en el futuro decides usar algunos de estos pines, recuerda actualizar la configuración en tu código.
Esta práctica ayuda a mantener el Arduino funcionando de manera estable y eficiente, especialmente en entornos con mucho ruido electromagnético.

# :artificial_satellite: Código para Arduino MEGA

El Arduino Mega tiene más pines que el Arduino Uno, por lo que necesitamos ajustar el rango del bucle for para abarcar todos los pines disponibles. El Arduino Mega tiene 54 pines digitales (numerados del 0 al 53). Aquí tienes un ejemplo para declarar los pines no utilizados como salidas en un Arduino Mega:

![Código en Modo Oscuro](https://github.com/uagaviria/Buenas-Practicas-con-Arduino/blob/main/img/code2.png)