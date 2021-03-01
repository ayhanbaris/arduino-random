
// 7 segment pins
const int A = 7; 
const int B = 8; 
const int C = 9; 
const int D = 10; 
const int E = 11; 
const int F = 12; 
const int G = 13;

const int button = A1; 
const int buzzerPin = 5;

int randNumber;


int myArray[6] = {1, 2, 3, 4, 5, 6};

void setup() {
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(button, INPUT);
  pinMode(buzzerPin, OUTPUT);
 
  randomSeed(analogRead(0));

  Serial.begin(9600);

   clear7Segment();
   digitalWrite(buzzerPin, LOW);
}

void loop() {
  if(abReadPin(button, 40) == true) {
    //progressBar();

    for(int i=1; i<50; i++ ) randomize(myArray);

    for(int i = 0; i<6; i++) {
      Serial.print(myArray[i]);
      Serial.print(", ");
    }
    Serial.println();
  
    for(int i = 0; i<6; i++) {
      sound(1,30);
      randNumber = myArray[i];
      clear7Segment();
      SayiYaz(randNumber);
      delay(60);
    }

    sound(1,100);
    
    
  }
  
}


void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

void randomize(int myArray[]) {
  for (int i = 0; i < 6; i++) {
    int j = random(0, 6);
    swap(myArray[i], myArray[j]);
  }
}

 
boolean abReadPin(int pin, unsigned int deBounce) {
  if ( digitalRead(pin) == HIGH ) {
    delay(deBounce);
    if ( digitalRead(pin) == HIGH ) {
      delay(deBounce);
      if ( digitalRead(pin) == HIGH ) {
        return true;
      }
    }
  }
 
  return false;
}

void SayiYaz(int sayi){
switch(sayi)
  {
    case 0:
    digitalWrite(E,LOW);
    digitalWrite(D,LOW); 
    digitalWrite(C,LOW); 
    digitalWrite(B,LOW); 
    digitalWrite(A,LOW); 
    digitalWrite(F,LOW); 
    digitalWrite(G,HIGH); 
    break;
    
    case 1:
    digitalWrite(E,HIGH);
    digitalWrite(D,HIGH); 
    digitalWrite(C,LOW); 
    digitalWrite(B,LOW); 
    digitalWrite(A,HIGH); 
    digitalWrite(F,HIGH); 
    digitalWrite(G,HIGH); 
    break;
    
    case 2:
    digitalWrite(E,LOW);
    digitalWrite(D,LOW); 
    digitalWrite(C,HIGH); 
    digitalWrite(B,LOW); 
    digitalWrite(A,LOW); 
    digitalWrite(F,HIGH); 
    digitalWrite(G,LOW);     
    break;
    
    case 3:
    digitalWrite(E,HIGH);
    digitalWrite(D,LOW); 
    digitalWrite(C,LOW); 
    digitalWrite(B,LOW); 
    digitalWrite(A,LOW); 
    digitalWrite(F,HIGH); 
    digitalWrite(G,LOW); 
    break;
    
    case 4:
    digitalWrite(E,HIGH);
    digitalWrite(D,HIGH); 
    digitalWrite(C,LOW); 
    digitalWrite(B,LOW); 
    digitalWrite(A,HIGH); 
    digitalWrite(F,LOW); 
    digitalWrite(G,LOW); 
    break;
    
    case 5:
    digitalWrite(E,HIGH);
    digitalWrite(D,LOW); 
    digitalWrite(C,LOW); 
    digitalWrite(B,HIGH); 
    digitalWrite(A,LOW); 
    digitalWrite(F,LOW); 
    digitalWrite(G,LOW); 
    break;
    
    case 6:
    digitalWrite(E,LOW);
    digitalWrite(D,LOW); 
    digitalWrite(C,LOW); 
    digitalWrite(B,HIGH); 
    digitalWrite(A,LOW); 
    digitalWrite(F,LOW); 
    digitalWrite(G,LOW); 
    break;
    
    case 7:
    digitalWrite(E,HIGH);
    digitalWrite(D,HIGH); 
    digitalWrite(C,LOW); 
    digitalWrite(B,LOW); 
    digitalWrite(A,LOW); 
    digitalWrite(F,HIGH); 
    digitalWrite(G,HIGH); 
    break;
    
    case 8:
    digitalWrite(E,LOW);
    digitalWrite(D,LOW); 
    digitalWrite(C,LOW); 
    digitalWrite(B,LOW); 
    digitalWrite(A,LOW); 
    digitalWrite(F,LOW); 
    digitalWrite(G,LOW); 
    break;
    
    case 9:
    digitalWrite(E,HIGH);
    digitalWrite(D,LOW); 
    digitalWrite(C,LOW); 
    digitalWrite(B,LOW); 
    digitalWrite(A,LOW); 
    digitalWrite(F,LOW); 
    digitalWrite(G,LOW); 
    break;
  }
  
}


void clear7Segment()
{
    digitalWrite(E,HIGH);
    digitalWrite(D,HIGH); 
    digitalWrite(C,HIGH); 
    digitalWrite(B,HIGH); 
    digitalWrite(A,HIGH); 
    digitalWrite(F,HIGH); 
    digitalWrite(G,HIGH); 
}


void progressBar() {
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH); 
    digitalWrite(C,HIGH); 
    digitalWrite(D,HIGH); 
    digitalWrite(E,HIGH); 
    digitalWrite(F,HIGH); 
    digitalWrite(G,HIGH); 
    
    digitalWrite(A,LOW);
    delay(150);
    digitalWrite(A,HIGH);

    digitalWrite(B,LOW);
    delay(150);
    digitalWrite(B,HIGH);

    digitalWrite(C,LOW);
    delay(150);
    digitalWrite(C,HIGH);

    digitalWrite(D,LOW);
    delay(150);
    digitalWrite(D,HIGH);
 
    digitalWrite(E,LOW);
    delay(150);
    digitalWrite(E,HIGH);   

    digitalWrite(F,LOW);
    delay(150);
    digitalWrite(F,HIGH);
}

/***************************************************************************/
// ses cikart
void sound(byte count, unsigned int bounce) {
  for (byte i = 0; i < count; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(bounce);
    digitalWrite(buzzerPin, LOW);
    if (count > 1) {
      delay(bounce);
    }
  }
}
