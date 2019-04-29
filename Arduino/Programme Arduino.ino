#include <SoftwareSerial.h>
#include <Servo.h>  // Importation de la librairie Servo

Servo monServomoteur; // Création d'un objet Servo

SoftwareSerial BT(10, 11); //TX, RX respetively
String state;
int servopos;

//MCC
const int pwm_a = 3;
const int dir_a = 12;
const int brake_a = 9;


void setup() {
 BT.begin(9600);// bluetooth serial communication will happen on pin 10 and 11
 Serial.begin(9600); // serial communication to check the data on serial monitor
 monServomoteur.attach(8); // Associe le servomoteur à la broche 9
 pinMode(pwm_a,OUTPUT);
 pinMode(dir_a,OUTPUT);
 pinMode(brake_a,OUTPUT);
 digitalWrite(brake_a,LOW);
}

//-----------------------------------------------------------------------//  
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable 
    char c = BT.read(); //Conduct a serial read
    state += c;
    if (state.length() > 0) {
      Serial.println(state);
      if (state=="L") {
        digitalWrite(dir_a,LOW);
        analogWrite(pwm_a,100);
      }
      else if (state=="H"){
        digitalWrite(dir_a,LOW);
        analogWrite(pwm_a,250);
      }
      else if (state=="R"){
        digitalWrite(dir_a,HIGH);
        analogWrite(pwm_a,100);
      }
      else if (state=="S"){
        digitalWrite(dir_a,LOW);
        analogWrite(pwm_a,0);
      }
      else if (state=="0") {
        monServomoteur.write(45);
        }
      else if (state=="1") {
        monServomoteur.write(56);
        }
      else if (state=="2") {
        monServomoteur.write(67);
        }
      else if (state=="3") {
        monServomoteur.write(79);
        }
      else if (state=="4") {
        monServomoteur.write(90);
        }
      else if (state=="5") {
        monServomoteur.write(101);
        }
      else if (state=="6") {
        monServomoteur.write(113);
        }
      else if (state=="7") {
        monServomoteur.write(124);
        }
      else if (state=="8") {
        monServomoteur.write(135);
        }
      }
    }
    state ="";
   }



