/*#ifndef BATTMED_HPP
#define BATTMED_HPP

const int pinBatt = A0;
const int divisor = 2.89;

void medirBateria() {
    int leitura = analogRead(pinBatt);
    float tensaoBatt = (leitura/1023) * 3.0 * divisor;

    Serial.print("Tensão: ");
    Serial.print(tensaoBatt);
    Serial.print(" V");
}

#endif

*/