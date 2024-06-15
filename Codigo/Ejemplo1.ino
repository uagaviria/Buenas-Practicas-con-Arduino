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