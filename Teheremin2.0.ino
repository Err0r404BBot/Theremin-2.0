 
#include "frecuencias.h"
#define MIN_DISTANCIA 50


//Sensor
int echo = 12;                              
int trigger = 13;                                
int speaker = 9; 
unsigned long tiempoRespuesta;
unsigned long distancia;
int limiteInferior = 5;
int limiteSuperior = 25;
int cantidadNotas = 12;

//Display
int pin_a = 2;
int pin_b = 3;
int pin_c = 4;
int pin_d = 5;
int pin_e = 6;
int pin_f = 7;
int pin_g = 8;

//Botones

int pulsador1 = 10;
int pulsador2 = 11;

int cont = 1;

//Escalas
int notas1[]={NOTA_B2,NOTA_AS2,NOTA_A2,NOTA_GS2,NOTA_G2,NOTA_FS2,NOTA_F2,NOTA_E2,NOTA_DS2,NOTA_D2,NOTA_CS2,NOTA_C2}; 
int notas2[]={NOTA_B3,NOTA_AS3,NOTA_A3,NOTA_GS3,NOTA_G3,NOTA_FS3,NOTA_F3,NOTA_E3,NOTA_DS3,NOTA_D3,NOTA_CS3,NOTA_C3}; 
int notas3[]={NOTA_B4,NOTA_AS4,NOTA_A4,NOTA_GS4,NOTA_G4,NOTA_FS4,NOTA_F4,NOTA_E4,NOTA_DS4,NOTA_D4,NOTA_CS4,NOTA_C4}; 
int notas4[]={NOTA_B5,NOTA_AS5,NOTA_A5,NOTA_GS5,NOTA_G5,NOTA_FS5,NOTA_F5,NOTA_E5,NOTA_DS5,NOTA_D5,NOTA_CS5,NOTA_C5}; 
int notas5[]={NOTA_B6,NOTA_AS6,NOTA_A6,NOTA_GS6,NOTA_G6,NOTA_FS6,NOTA_F6,NOTA_E6,NOTA_DS6,NOTA_D6,NOTA_CS6,NOTA_C6}; 
int notas6[]={NOTA_B7,NOTA_AS7,NOTA_A7,NOTA_GS7,NOTA_G7,NOTA_FS7,NOTA_F7,NOTA_E7,NOTA_DS7,NOTA_D7,NOTA_CS7,NOTA_C7}; 
int notas7[]={NOTA_B8,NOTA_AS8,NOTA_A8,NOTA_GS8,NOTA_G8,NOTA_FS8,NOTA_F8,NOTA_E8,NOTA_DS8,NOTA_D8,NOTA_CS8,NOTA_C8}; 


void setup() {
  pinMode(pulsador1, INPUT_PULLUP);
  pinMode(pulsador2, INPUT_PULLUP);
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_c, OUTPUT);
  pinMode(pin_d, OUTPUT);
  pinMode(pin_e, OUTPUT);
  pinMode(pin_f, OUTPUT);
  pinMode(pin_g, OUTPUT);
  pinMode(speaker, OUTPUT);                  
  pinMode(trigger, OUTPUT);                     
  pinMode(echo, INPUT);   
  Serial.begin(9600);                 
 } 

void loop() {
    
int estadoP1 = digitalRead(pulsador1);
int estadoP2 = digitalRead(pulsador2);
delay(70);

if(estadoP1==0)
{
  cont=cont+1;
}

delay(50); //Antirrebotes

if(estadoP2==0)
{
  cont=cont-1;
}

if(cont >= 7)
{
  cont = 7;
  }

if(cont <= 1)
{
  cont = 1;
  }
  digitalWrite(trigger, HIGH);            
  delayMicroseconds(10);                        
  digitalWrite(trigger, LOW);                   
  tiempoRespuesta = pulseIn(echo, HIGH);  
  distancia = tiempoRespuesta/58;         // Calculo de distancia en cm


if(cont==1)
{  
digitalWrite(pin_a, LOW);
digitalWrite(pin_b, LOW);
digitalWrite(pin_c, LOW);
digitalWrite(pin_d, HIGH);
digitalWrite(pin_e, HIGH);
digitalWrite(pin_f, LOW);
digitalWrite(pin_g, LOW);
  
  if (distancia >= limiteInferior && distancia <= limiteSuperior) {
    int x=map(distancia,limiteInferior,limiteSuperior,0,((cantidadNotas-1)*10));
    tone(speaker, notas1[x/10]);
    delay(100);
  
  }  
  else{
    noTone(9);
    }
   
}

if(cont==2)
{
digitalWrite(pin_a, HIGH);
digitalWrite(pin_b, HIGH);
digitalWrite(pin_c, HIGH);
digitalWrite(pin_d, LOW);
digitalWrite(pin_e, HIGH);
digitalWrite(pin_f, LOW);
digitalWrite(pin_g, HIGH);

 if (distancia >= limiteInferior && distancia <= limiteSuperior) {
    int x=map(distancia,limiteInferior,limiteSuperior,0,((cantidadNotas-1)*10));
    tone(speaker, notas2[x/10]);
    delay(100);
  
  }  
  else{
    noTone(9);
    }
   
}

if(cont==3)
{
digitalWrite(pin_a, HIGH);
digitalWrite(pin_b, HIGH);
digitalWrite(pin_c, HIGH);
digitalWrite(pin_d, LOW);
digitalWrite(pin_e, LOW);
digitalWrite(pin_f, HIGH);
digitalWrite(pin_g, HIGH);

 if (distancia >= limiteInferior && distancia <= limiteSuperior) {
    int x=map(distancia,limiteInferior,limiteSuperior,0,((cantidadNotas-1)*10));
    tone(speaker, notas3[x/10]);
    delay(100);
  
  }  
  else{
    noTone(9);
    }
   
}

if(cont==4)
{
digitalWrite(pin_a, HIGH);
digitalWrite(pin_b, LOW);
digitalWrite(pin_c, LOW);
digitalWrite(pin_d, HIGH);
digitalWrite(pin_e, LOW);
digitalWrite(pin_f, HIGH);
digitalWrite(pin_g, HIGH);

 if (distancia >= limiteInferior && distancia <= limiteSuperior) {
    int x=map(distancia,limiteInferior,limiteSuperior,0,((cantidadNotas-1)*10));
    tone(speaker, notas4[x/10]);
    delay(100);
  
  }  
  else{
    noTone(9);
    }
   

}

if(cont==5)
{
    
digitalWrite(pin_a, HIGH);
digitalWrite(pin_b, HIGH);
digitalWrite(pin_c, HIGH);
digitalWrite(pin_d, HIGH);
digitalWrite(pin_e, LOW);
digitalWrite(pin_f, HIGH);
digitalWrite(pin_g, LOW);

 if (distancia >= limiteInferior && distancia <= limiteSuperior) {
    int x=map(distancia,limiteInferior,limiteSuperior,0,((cantidadNotas-1)*10));
    tone(speaker, notas5[x/10]);
    delay(100);
  
  }  
  else{
    noTone(9);
    }
   

}

if(cont==6)
{
    
digitalWrite(pin_a, HIGH);
digitalWrite(pin_b, HIGH);
digitalWrite(pin_c, HIGH);
digitalWrite(pin_d, HIGH);
digitalWrite(pin_e, HIGH);
digitalWrite(pin_f, HIGH);
digitalWrite(pin_g, LOW);

 if (distancia >= limiteInferior && distancia <= limiteSuperior) {
    int x=map(distancia,limiteInferior,limiteSuperior,0,((cantidadNotas-1)*10));
    tone(speaker, notas6[x/10]);
    delay(100);
  
  }  
  else{
    noTone(9);
    }
   

}

if(cont==7)
{
    
digitalWrite(pin_a, HIGH);
digitalWrite(pin_b, LOW);
digitalWrite(pin_c, HIGH);
digitalWrite(pin_d, LOW);
digitalWrite(pin_e, LOW);
digitalWrite(pin_f, HIGH);
digitalWrite(pin_g, HIGH);

 if (distancia >= limiteInferior && distancia <= limiteSuperior) {
    int x=map(distancia,limiteInferior,limiteSuperior,0,((cantidadNotas-1)*10));
    tone(speaker, notas7[x/10]);
    delay(100);
  
  }  
  else{
    noTone(9);
    }

}
}
   
