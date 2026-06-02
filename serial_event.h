//imediatamente uma após a outra

String palavra;
String dado;
String palavra_3;

boolean novaPalavra = false;
boolean novoDado = false;
boolean nova_palavra_3 = false;

//leitura da serial
void serialEvent() {
  // captura os caracteres da palavra serial
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    palavra += inChar;
    // identifica o fim da palavra
    if (inChar == '&') {
      //exibir_palavra(palavra);
      novaPalavra = true;
      break;
    }
  }
}

//leitura da serial
void serial2Event() {
  // captura os caracteres da palavra serial2
  while (Serial2.available()) {
    char inChar2 = (char)Serial2.read();
    // identifica o fim da palavra
    if (inChar2 == '&') {
      novoDado = true;
      break;
    }
    dado += inChar2;
  }

}void serial1Event() {//utilizado como substituto do serial 2 na placa protótipo
  // captura os caracteres da palavra serial1
  while (Serial1.available()) {
    char inChar1 = (char)Serial1.read();
    // identifica o fim da palavra
    if (inChar1 == '&') {
      novoDado = true;
      break;
    }
    dado += inChar1;
  }
}

//leitura da serial
void serial3Event() {
  // captura os caracteres da palavra serial3
  while (Serial3.available()) {
    //Serial.println(palavra_3);
    delay(1); //por alguma razão o arduino perde caracteres da serial se não houver esse delay
    char inChar3 = (char)Serial3.read();
    palavra_3 += inChar3;
    // identifica o fim da palavra
    //Serial.println(palavra_3);
    if (inChar3 == '&') {
      nova_palavra_3 = true;
      break;
    }
  }
}
