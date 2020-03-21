#include <Keypad.h>
const int left = 28;
const int right = A4;
const int up = A5;
const int down = A3;
const int Z = 47;
const int start = 44;
const int A = 49;
const int B = 48;
const int Y = 46;
const int LR = 45;
const int RTilt = 43;
const int LTilt = 42;
const int DTilt = 11;
const int UTilt = 12;
char lastKey = "";
const int timeToWait = 500;
boolean runMe = false;
String a;
int counter = 0;
void button40(int direct, int wait = 40) {
  digitalWrite(direct, HIGH);
  delay(wait);
  digitalWrite(direct, LOW);
  digitalWrite(direct, LOW);
  digitalWrite(direct, LOW);
  delay(40);
}

void dashDance(int ammount) {
  int u = 0;
  while(u < ammount) {
    button40(left, 20);
    button40(right, 20);
    u = u + 1;
  }
}

void reset() {
  digitalWrite(LR, HIGH);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(LR, LOW);
  digitalWrite(A, LOW);
  delay(100);
}

void dashAttack(int direct) {
  digitalWrite(direct, HIGH);
  delay(150);
  button40(A);
  digitalWrite(direct, LOW);
}

void PG() {
  button40(down);
  button40(left);
  button40(down);
  button40(right);
  digitalWrite(B, HIGH);
  delay(100);
  digitalWrite(B, LOW);
}

void BW() {
  button40(down, 25);
  button40(right, 25);
  button40(down, 25);
  button40(right, 25);
  digitalWrite(B, HIGH);
  delay(100);
  digitalWrite(B, LOW);
}

void powerDunk() {
  digitalWrite(down, HIGH);
  digitalWrite(B, HIGH);
  delay(250);
  digitalWrite(down, LOW);
  digitalWrite(B, LOW);
  delay(700);
}

void smash(String key) {
      /* Movement */
    int movement = 0;
    int intensity = 0;
    int jump = 0;
    int attack = 0;
    int chargeTime = 0;
    int pummels = 0;
    
    switch (key[0]) {
      case '0':
        // No movement
        break;
      case '1':
        // movement left
        movement = left;
        break;
      case '2':
        // movement right
        movement = right;
        break;
      case '3':
        // movement up
        movement = up;
        break;
      case '4':
        // movement down
        movement = down;

        break;
      default:
        break;
    }
    /* Movement intensity */
//    switch (key[1]) {
//      case '0':
//        intensity = 26;
//        break;
//      case '1':
//        intensity = 51;
//        break;
//      case '2':
//        intensity = 77;
//        break;
//      case '3':
//        intensity = 102;
//        break;
//      case '4':
//        intensity = 128;
//        break;
//      case '5':
//        intensity = 153;
//        break;
//      case '6':
//        intensity = 179;
//        break;
//      case '7':
//        intensity = 204;
//        break;
//      case '8':
//        intensity = 230;
//        break;
//      
//      case '9':
//        intensity = 255;
//        break;
//      default:
//        break;
//    }



    /* Jump key[2] */
//    switch (key[2]) {
//      case '0':
//        // No
//        jump = 0;
//        break;
//      case '1':
//        // Yes Short
//        jump = 1;
//        break;
//      case '2':
//        // Yes Full
//        jump = 2;
//        break;
//      default:
//        break;
//    }

    /* Attack Type key[3] */



    /* Charge time 1 */
    switch (key[4]) {
      case '0':
        chargeTime = 0;   // 0
        break;
      case '1':
        chargeTime = 17;  // 1
        break;
      case '2':
        chargeTime = 34;  // 2
        break;
      case '3':
        chargeTime = 51;  // 3
        break;
      case '4':
        chargeTime = 85;  // 5
        break;
      case '5':
        chargeTime = 136; // 8
        break;
      case '6':
        chargeTime = 221; // 13
        break;
      case '7':
        chargeTime = 357; // 21
        break;
      case '8':
        chargeTime = 578; // 34
        break;
      case '9':
        chargeTime = 935; // 55
        break;
      default:
        break;
    }

    /* Pummel(s) */
    switch (key[5]) {
      case '0':
        pummels = 0;
        break;
      case '1':
        pummels = 1;
        break;
      case '2':
        pummels = 2;
        break;
      case '3':
        pummels = 3;
        break;
      default:
        break;
    }

    int movement = 0;
    int intensity = 0;
    int jump = 0;
    int attack = 0;
    int chargeTime = 0;
    int pummels = 0;
    int thrw = 0;
    /* Order */
    
    // 0 | move     jump      wait     attack     move2   (Aerial rising)
    
    // 1 | jump     attack    wait     move               (Aerial moving while falling)

    // 2 | jump     attack

    // 3 | move     jump                                  (ledge trap)

    // 4 | move

    // 5 | attack

    // 6 | jump
    

    // X | jump     move      wait     attack     move2

    // X | attack   jump      wait     move    
    // X | attack   move      wait     jump    
    // X | move     attack    wait     jump    

    // X | attack   move
    
    switch (key[6]) {
      case '0':
        aerialRising2(movement, jump, wait, attack, movement2);
        break;
      case '1':
        aerialRising(jump, attack, wait, movement);
        break;
      case '2':
        jumpKick(jump, attack);
        break;
      case '3':
        ledgeTrap(movement, jump);
        break;
      case '4':
        soleMovement(movement);
        break;
      case '5':
        soleAttack(attack);
        break;
      case '6':
        soleJump(jump);
        break;
      default:
        break;
    }
}

void aerialRising2(int movement, int jump, int wait, int attack, int movement2) {
  // Jump and Movement will need to be analogWrite
  digitalWrite(movement, HIGH);
  digitalWrite(Y, HIGH);
  delay(wait);
  digitalWrite(movement, LOW);
  digitalWrite(Y, LOW);
  punch(attack);
}


void punch(char atk, int charge) {
  switch(atk) {
    case '1':
      jab();
      break;
    case '2':
      jab2();
      break;
    case '3':
      cLeft();
      break;
    case '4':
      cRight();
      break;
    case '5':
      cUp();
      break;
    case '6':
      cDown();
      break;
    case '7':
      fSmashLeft(charge);
      break;
    case '8':
      fSmashRight(charge);
      break;
    case '9':
      upSmash(charge);
      break;
    case 'a':
      downSmash(charge);
      break;
    case 'b':
      grab(pummel, thrw);
      break;
    case 'c':
      sheild(charge);
      break;
    case 'd':
      specialN(charge);
      break;
    case 'e':
      specialF(charge);
      break;
    case 'f':
      specialU(charge);
      break;
    case 'g':
      specialD(charge);
      break;
    default:
      break;
  }
}
void marthToTerry() {
    back();
    button40(down, 600);
    button40(A);
    button40(A);

}

void back() {
  button40(B);
}

void backOut() {
  button40(start);
  delay(200);
  button40(up);
  button40(A, 750);
}
void setup() {
  Serial.begin(9600);
  pinMode(start, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(Z, OUTPUT);
  pinMode(LR, OUTPUT);

  button40(A);
  button40(A);
  reset();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String key = Serial.readString();
    smash(key);
    Serial.println(key);
  }
}
