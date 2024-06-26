
# Optimización de Pines en Arduino para Proyectos industriales Estables.
# Buenas Practicas.

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

En este ejemplo, estamos utilizando los pines 2 y 3 para algunas funcionalidades específicas, y el resto de los pines (del 0 al 53) se configuran como salidas y se ponen en estado bajo.

Consideraciones
Pines Especiales: Ten en cuenta que algunos pines del Arduino Mega tienen funciones especiales (por ejemplo, los pines para comunicación serial, I2C, SPI, etc.). Si no los estás utilizando, también puedes configurarlos como salidas, pero si los necesitas para su función específica, debes excluirlos de esta configuración.
Uso Futuro: Si decides usar más pines en el futuro, recuerda excluir esos pines adicionales de la configuración en el bucle for.
Este enfoque ayuda a mantener tu Arduino Mega operando de manera estable y reduce el riesgo de problemas causados por el ruido electromagnético y estados indeterminados en los pines no utilizados.

Supongamos que vamos a utilizar el puerto spi y el i2c el código quedaria de la siguiente manera: 

El Arduino Mega tiene pines específicos designados para SPI y I2C que no deben ser configurados como salidas si los vas a utilizar para sus funciones correspondientes. Los pines involucrados son:

```C++
SPI:
    MISO: pin 50
    MOSI: pin 51
    SCK: pin 52
    SS: pin 53
    I2C:
I2C
    SDA: pin 20
    SCL: pin 21
```
Si queremos configurar el resto de los pines no utilizados como salidas, excluyendo estos pines específicos, el código sería así:

![Código en Modo Oscuro](https://github.com/uagaviria/Buenas-Practicas-con-Arduino/blob/main/img/code3.png)

Explicación del código
Declarar Pines Utilizados: Primero, declaramos los pines que estamos utilizando para otras funcionalidades, como el pin 2 y el pin 3 en este ejemplo.
Bucle para Declarar Pines No Utilizados: Luego, usamos un bucle for para recorrer todos los pines digitales desde el 0 hasta el 53.
Dentro del bucle, excluimos los pines que estamos utilizando (2 y 3) y los pines que son necesarios para SPI (20, 21) e I2C (50, 51, 52, 53).
Configuramos los demás pines como salidas y los ponemos en estado bajo para minimizar el consumo y evitar ruido electromagnético.
# Consideraciones Adicionales
1. Pines Seriales: Si también estás utilizando la comunicación serial (por ejemplo, Serial1, Serial2, Serial3 en el Arduino Mega), debes excluir esos pines también (pines 14 a 19 para Serial1, Serial2, Serial3).
2. Pines Analógicos: Si estás utilizando algún pin analógico en modo digital, asegúrate de excluir esos pines del bucle también (A0 a A15, que corresponden a los pines digitales 54 a 69).
El ajuste del código debe ser hecho según los pines específicos que estés utilizando en tu proyecto.