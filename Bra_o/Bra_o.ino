//Braço Robótico com sensor de presença
//Código por Alexandre de Oliveira Júnior 1816144 e Fábio Augusto Amaral 798800
//Projeto Integrador 2019/1

//INCLUSÃO DAS BIBLIOTECAS
#include <Servo.h>
#include <Ultrasonic.h>

//DECLARÇÃO DAS PORTAS DO MICROCONTROLADOR
#define SERVO1 3  //Servo base
#define SERVO2 5  //Servo direito
#define SERVO3 6  //Servo esquerdo
#define SERVO4 9 //Servo garra
Ultrasonic ultrassom(8,7); //trig(8 )= emissor; echo(7) = receptor
//VARIÁVEIS GLOBAIS
Servo s1, s2, s3, s4;
int pos1, pos2, pos3, pos4, ajuste;
long distancia;

//INICIALIZAÇÃO
void setup(){
  Serial.begin(9600);         //Inicialização do microcontrolador,
  s1.attach(SERVO1);          //Inicialização do servo 01
  s1.write(5);                //Posicionamento incial do servo 01
  s2.attach(SERVO2);          //Inicialização do servo 02
  s2.write(45);               //Posicionamento incial do servo 02
  s3.attach(SERVO3);          //Inicialização do servo 03
  s3.write(75);               //Posicionamento incial do servo 03
  s4.attach(SERVO4);          //Inicialização do servo 03
  s4.write(90);               //Posicionamento incial do servo 03
  delay(2000);
}

//FUNÇÃOAJUSTE01
void ajuste1(){
  for(ajuste = 0; ajuste < 20; ajuste++){
    s1.write(pos1);
    pos1++;
  }
}

//FUNÇÃOAJUSTE02
void ajuste2(){
  for(ajuste = 0; ajuste < 15; ajuste++){
    s1.write(pos1);
    pos1++;
  }
}

//FUNÇÃOAJUSTE03
void ajuste3(){
  for(ajuste = 0; ajuste < 12; ajuste++){
    s1.write(pos1);
    pos1++;
  }
}


//FUNÇÃOAJUSTE04
void ajuste4(){
  for(ajuste = 0; ajuste < 10; ajuste++){
    s1.write(pos1);
    pos1++;
  }
}

//FUNÇÃO ESCOLHE AJUSTE
void ea(){
  if(pos1 < 15){
    ajuste1();
  }
  else if(pos1 >= 15 && pos1 < 35){
    ajuste2();
  }
  else if(pos1 >= 35 && pos1 < 40){
    ajuste3();
  }
  else if(pos1 >= 40 && pos1 < 130){
    ajuste2();
  }
  else if(pos1 >= 130){
    ajuste4();
  }
}

//FUNÇÃO MOVER
void mov(){
  Serial.print(pos1);
  Serial.println("º");
  ea();
  for(pos3 = 75; pos3 >= 15; pos3--){
    s3.write(pos3);
    delay(50);
  }
    for(pos2 = 45; pos2 < 115; pos2++){
    s2.write(pos2);
    delay(50);
  }
    for(pos4 = 90; pos4 >= 15; pos4--){
    s4.write(pos4);
    delay(50);
  }
    for(pos2 = 115; pos2 >= 45; pos2--){
    s2.write(pos2);
    delay(50);
  }
    for(pos3 = 15; pos3 < 75; pos3++){
    s3.write(pos3);
    delay(50);
  }
    while(pos1 > 5){
    s1.write(pos1);
    delay(20);
    pos1--;
  }
    for(pos4 = 15; pos4 < 90; pos4++){
    s4.write(pos4);
    delay(20);
  }
}

//PROGRAMA PRINCIPAL
void loop(){
  for(pos1 = 5; pos1 < 175; pos1++){
    s1.write(pos1);
    distancia = ultrassom.Ranging(CM);
    if(distancia < 20 && distancia > 3){
      mov();
      delay(1000);
      break;
    }
    delay(15);
  }
    while(pos1 > 5){
    s1.write(pos1);
    delay(20);
    pos1--;
  }
}
