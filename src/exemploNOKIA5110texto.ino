/*
 ***********************************************************************
 *              LIBRERIAS y CONSTANTES
 ***********************************************************************
 */

/***** INICIO LCD ******/
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);
/***** FIN LCD ******/

/****** INICIO FUNCIONES ADICIONALES AL SETUP******/
void configurarMonitorSerial() {
  Serial.begin(9600);
  Serial.println("Iniciando...");
}

void configurarLCD() {
  display.begin();
  display.setContrast(40); //Ajusta contraste
  display.setTextColor(BLACK, WHITE);// Color(letra,fondo)
  //display.setTextColor(WHITE, BLACK);//
}

/****** FIN FUNCIONES ADICIONALES AL SETUP******/
/*
 ***********************************************************************
 *              SETUP CONFIGURACIÓN INICIAL
 ***********************************************************************
 */
void setup() {
  configurarMonitorSerial();
  configurarLCD();
}

/****** INICIO FUNCIONES ADICIONALES AL LOOP ******/
void mensajeBienvenida() {
  display.clearDisplay();
  display.setTextSize(1);  //configura tamaño de letra
  display.setCursor(0,0);  //configura posicion columna, fila
  display.println("Grupo Linux UD");
  display.setCursor(0,20);
  display.setTextSize(2);  //Aumenta tamaño de letra
  display.print("  Glud ");
  display.display(); //exibe display
  delay(3000);
}

void mensajePrueba() {
  display.clearDisplay(); //limpia display
  display.setTextSize(1); //cada renglon dispone de 14 caracteres en tamaño 1
  display.print(" Test para     verificar     funcionalidad de Display");
  display.setCursor(0,34);
  display.setTextSize(2);
  display.print("  LISTO ");
  display.display();
  delay(4000);
}
/****** FIN FUNCIONES ADICIONALES AL LOOP ******/

/*
 ***********************************************************************
 *              LOOP BUCLE PRINCIPAL
 ***********************************************************************
 */
void loop() {
  mensajeBienvenida();
  mensajePrueba();
}
