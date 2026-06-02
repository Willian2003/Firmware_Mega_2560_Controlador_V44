#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

//*****************************************************************
//contador dosímetros
int contador_dosimetro = 1;
//*****************************************************************
unsigned long delay_exibir_standby = 0;

byte lcd_custom_char_linhas_verticais[] = { //carácter usado para construir os limites laterais da barra de progresso
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};
byte lcd_custom_char_linhas_verticais_linha_final[] = { //carácter usado para construir limites laterais e final da barra de progresso
  B11111,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B11111
};
byte lcd_custom_char_barra_de_progresso_1_linha[] = {
  B11111,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B11111
};
byte lcd_custom_char_barra_de_progresso_2_linhas[] = {
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11111
};
byte lcd_custom_char_barra_de_progresso_3_linhas[] = {
  B11111,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11111
};
byte lcd_custom_char_barra_de_progresso_4_linhas[] = {
  B11111,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11111
};
byte lcd_custom_char_barra_de_progresso_5_linhas[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte lcd_custom_char_barra_de_progresso_final_array[][8] = {
  {
    B11111,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B11111
  },
  {
    B11111,
    B11001,
    B11001,
    B11001,
    B11001,
    B11001,
    B11001,
    B11111
  },
  {
    B11111,
    B11101,
    B11101,
    B11101,
    B11101,
    B11101,
    B11101,
    B11111
  },
  {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  },
  {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  }
};
//=============================================================
void exibir_timeout_contador() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Time out contador");
  lcd.setCursor(0, 2);
  lcd.print("Reinitiate!");
}
//=============================================================
void exibir_timeout() {
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Time out, PC");
  lcd.setCursor(0, 2);
  lcd.print("Reinitiate!");
}
//=============================================================
void exibir_vpmt_lcd() {
  int VPMT = analogRead(A0);
  VPMT = VPMT * 4.88; //(mV)
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Vpmt:");
  lcd.setCursor(1, 2);
  lcd.print(VPMT);
  delay(4000);
}
//=============================================================
void exibirInicializando() {
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Initializing...");
}

//=============================================================
void exibirEmpresa() {
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("RADinstruments");
  delay(4000);
}

//=============================================================
void exibirStandBy() {
  if (millis() - delay_exibir_standby > 4000) {
    delay_exibir_standby = millis();
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Press Start/Stop");
  }
}
//=============================================================
void exibir_waiting_connect() {
  if (millis() - delay_exibir_standby > 4000) {
    delay_exibir_standby = millis();
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Connect Software");
  }
}
//=============================================================
void exibir_reinitiate() {
  if (millis() - delay_exibir_standby > 4000) {
    delay_exibir_standby = millis();
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Reinitiate!");
  }
}
//=============================================================
/*void exibirTempoZerameto(int tempo) {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(String(tempo));
  delay(1000);
  }*/

//=============================================================
void exibir_numDosimetro() {
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Dosimeter " + String(contador_dosimetro));
  lcd.setCursor(2, 2);
  lcd.print(String((contador_dosimetro - 1) * 3.448276, 0) + " %");
  contador_dosimetro++;
}

//=============================================================
void exibir_Dosimetro_OK() {
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Dosimeter " + String((contador_dosimetro - 1)));
  lcd.setCursor(2, 2);
  lcd.print(String((contador_dosimetro - 1) * 3.33, 0) + " %");
  lcd.setCursor(14, 1);
  lcd.print("OK");
}

//=============================================================
void exibir_Dosimetro_NOK() {
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Dosimeter " + String((contador_dosimetro - 1)));
  lcd.setCursor(2, 2);
  lcd.print(String((contador_dosimetro - 1) * 3.33, 0) + " %");
  lcd.setCursor(14, 1);
  lcd.print("Er");
}

//=============================================================
void exibir_leitura_completa() {
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("Process");
  lcd.setCursor(0, 2);
  lcd.print("Finished");
  contador_dosimetro = 1;
  //delay(2000);
}

//=============================================================
//
void exibirEquipamento() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Lumideteck 3001A");
  delay(2000);
}
//=============================================================
void exibirAutoteste() {
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("Autotest");
}
//=============================================================
void exibirFalhaLuzDeRef() {
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Reference Light");
  lcd.setCursor(0, 2);
  lcd.print("Failure");
  delay(2000);
}
//=============================================================
void exibirFalhaMecanica() {
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("Mechanical");
  lcd.setCursor(1, 2);
  lcd.print("Failure");
  delay(5000);
}
//=============================================================
void exibirAutoTesteOK() {
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("Autotest OK");
  delay(2000);
}
//=============================================================
void exibirBarraStatus(int i) {
  int porcentagem = (i + 1) / 0.6;

  for (int b = i / 5; b < 11; b++) {
    lcd.setCursor(b - 2, 3);
    lcd.write(1);
  }
  lcd.setCursor(9, 3);
  lcd.write(2);

  int x = -2;
  int y = 3;

  int n_caracteres_cheios = i / 5;
  int nLinhas = i % 5;

  for (int a = 0; a < n_caracteres_cheios; a++) {
    lcd.setCursor(x, y);
    lcd.write(7);
    x++;
  }
  if (i != 30) {
    lcd.setCursor(3, 2);
    lcd.print(porcentagem);
    lcd.print("%");
    lcd.setCursor(x, y);
    lcd.write(nLinhas + 3);
  }
}
//=============================================================
void exibirLeitura(int nCol) {
  int nDos = nCol / 2;
  lcd.clear();
  delay(500);
  lcd.setCursor(2, 0);
  lcd.print("Dosimeter ");
  if (nDos < 10) {
    lcd.print("0");
  }
  lcd.print(nDos);
  lcd.setCursor(-3, 2);
  lcd.print("HP07: ");
  lcd.print("0.00");
  lcd.print(" uSv");
  lcd.setCursor(-3, 3);
  lcd.print("HP10: ");
  lcd.print("0.00");
  lcd.print(" uSv");
  delay(4000);
}
//=============================================================
void exibir_palavra(String palavra_lcd) {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(palavra_lcd);
  delay(500);
}
//=============================================================
void exibir_zerando() {
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("Erasing...");
}
//=============================================================
void exibir_zeramentofinalizado() { //obs: não colocar delay
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("Erasing");
  lcd.setCursor(-1, 2);
  lcd.print("Completed");
}
//=============================================================
void exibir_checking() {
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("Checking...");
}
//=============================================================
void exibirZeramento(int nCol) {
  int nDos = nCol / 2;
  lcd.clear();
  delay(500);
  lcd.setCursor(2, 0);
  lcd.print("Dosimeter ");
  if (nDos <= 9) {
    lcd.print("0");
  }
  lcd.print(nDos);
  lcd.setCursor(5, 1);
  lcd.print("Erasing");

  for (int b = 0; b < 11; b++) {
    lcd.setCursor(b - 2, 3);
    lcd.write(1);
  }
  lcd.setCursor(9, 3);
  lcd.write(2);

  for (int a = 0; a < 60; a++) {
    int porcentagem = (a + 1) / 0.6;
    lcd.setCursor(3, 2);
    lcd.print(porcentagem);
    lcd.print("%");
    int x = -2;
    int y = 3;

    int n_caracteres_cheios = a / 5;
    int nLinhas = a % 5;

    for (int c = 0; c < n_caracteres_cheios; c++) {
      lcd.setCursor(x, y);
      lcd.write(7);
      x++;
    }
    if (a > 55) {
      lcd.createChar(0, lcd_custom_char_barra_de_progresso_final_array[a - 56]);
      lcd.home();
      lcd.setCursor(9, 3);
      lcd.write(0);
      delay(10000 / 60);
    } else if (a < 55) {
      lcd.setCursor(x, y);
      lcd.write(nLinhas + 3);
      delay(10000 / 60);
    }
  }

  lcd.clear();
  delay(500);
  lcd.setCursor(2, 0);
  lcd.print("Dosimeter ");
  if (nDos < 9) {
    lcd.print("0");
  }

  if (nCol < 60) {
    lcd.print(nDos + 1);
    exibirBarraStatus(nCol - 1);
  } else {
    lcd.print(nDos);
    exibirBarraStatus(nCol - 1);
  }

  lcd.setCursor(5, 1);
  lcd.print("Reading");

  delay(1000);
}
//=============================================================
void exibirProcessoFinalizado() {
  lcd.clear();
  delay(500);
  lcd.setCursor(4, 1);
  lcd.print("Process");
  lcd.setCursor(0, 2);
  lcd.print("Finished");
}
//=============================================================
void atualizar_barra_de_status() {
  for (int i = 0; i < 61; i++) {
    if (i % 2 == 0 && i != 0) {
      exibirLeitura(i);
      exibirZeramento(i);
      if (i == 60) {
        break;
      }
    }
    lcd.setCursor(2, 0);
    lcd.print("Dosimeter ");
    if ((i / 2) < 9) {
      lcd.print("0");
    }
    lcd.print(int(i / 2) + 1);
    lcd.setCursor(5, 1);
    lcd.print("Reading");
    exibirBarraStatus(i);
    delay(1000);
  }
}
