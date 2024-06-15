void setup() {
  // Declarar pines utilizados
  pinMode(2, OUTPUT);  // Ejemplo de un pin utilizado
  pinMode(3, INPUT);   // Ejemplo de otro pin utilizado

  // Declarar pines no utilizados como salidas
  for (int i = 0; i <= 53; i++) {
    if (i != 2 && i != 3) {  // Excluir los pines utilizados
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);  // Opcional: Establecer el estado bajo para minimizar el consumo
    }
  }
}

void loop() {
  // Tu código aquí
}