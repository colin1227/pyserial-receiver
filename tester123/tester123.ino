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
int counter = 0;

void button40(int direct, int wait = 40) {
  digitalWrite(direct, HIGH);
  delay(wait);
  digitalWrite(direct, LOW);
  digitalWrite(direct, LOW);
  digitalWrite(direct, LOW);
  delay(40);
}

void button40v2(int b1, int b2, int wait = 40) {
  digitalWrite(b1, HIGH);
  digitalWrite(b2, HIGH);
  delay(wait);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  delay(100);
}

void grab(int pummels,int thrw) {
  button40(Z, 20);
  for(int i = 0; i < pummels; i++) {
    button40(Z, 20);
  }
  if (thrw) {
    button40(thrw, 20);
  }
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

void dashAttack(int direct,int wait = 150) {
  digitalWrite(direct, HIGH);
  delay(wait);
  button40(A);
  digitalWrite(direct, LOW);
}

void smashAttack(int direct, int wait = 200) {
  digitalWrite(A, HIGH);
  digitalWrite(direct, HIGH);
  delay(wait);
  digitalWrite(A, LOW);
  digitalWrite(direct, LOW);
  delay(350);
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
    /////// vars //////////

    int movement = 0;     // key[0]
    // int intensity = 0;

    int movement2 = 0;    // key[1]
    // int intensity2 = 0;
    // int waitTime2 = 0;
    
    int waitTime = 0;     // key[2]
 
    int jump = key[3];    // key[3]
    
    int attack = key[4];  //
    int chargeTime = 0;   // key[5]
    int pummels = 0;      // key[6]
    int thrw = 0;         // key[7]
    int order = key[9];   // key[8]

    ///////////////////////
    
    /* Movement */    
    switch (key[0]) {
      case '0':
        // No movement
        break;
      case '1':
        movement = left;
        break;
      case '2':
        movement = right;
        break;
      case '3':
        movement = up;
        break;
      case '4':
        movement = down;
        break;
      default:
        break;
    }

    
    /* Second Movement */    
    switch (key[1]) {
      case '0':
        // No movement
        break;
      case '1':
        movement2 = left;
        break;
      case '2':
        movement2 = right;
        break;
      case '3':
        movement2 = up;
        break;
      case '4':
        movement2 = down;
        break;
      default:
        break;
    }

    /* Wait Time */
    switch (key[2]) {
      case '0':
        waitTime = 0;   // 0
        break;
      case '1':
        waitTime = 17;  // 1
        break;
      case '2':
        waitTime = 34;  // 2
        break;
      case '3':
        waitTime = 51;  // 3
        break;
      case '4':
        waitTime = 85;  // 5
        break;
      case '5':
        waitTime = 136; // 8
        break;
      case '6':
        waitTime = 221; // 13
        break;
      case '7':
        waitTime = 357; // 21
        break;
      case '8':
        waitTime = 578; // 34
        break;
      case '9':
        waitTime = 935; // 55
        break;
      default:
        break;
    }

    /* Charge Time 1 */
    switch (key[5]) {
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
    switch (key[6]) {
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

    /* Throw Direction */
    switch (key[7]) {
      case '0':
        // No movement
        break;
      case '1':
        thrw = left;
        break;
      case '2':
        thrw = right;
        break;
      case '3':
        thrw = up;
        break;
      case '4':
        thrw = down;
        break;
      default:
        break;
    }
   
    
    /*   
       Order
       0 | move     jump      wait     attack     move2
       1 | jump     attack    wait     move            
       2 | jump     attack
       3 | move     jump                               
       4 | move
       5 | attack
       6 | jump
   
       Options Deemed Unworthy
       X | jump     move      wait     attack     move2
       X | attack   jump      wait     move    
       X | attack   move      wait     jump    
       X | move     attack    wait     jump    
       X | attack   move
    int movement = 0;     // key[0]
    // int intensity = 0;

    int movement2 = 0;    // key[1]
    // int intensity2 = 0;

    int waitTime = 0;     // key[2]

    int jump = key[3];    // key[3]
    
    int attack = key[4];  //
    int chargeTime = 0;   // key[5]
    int pummels = 0;      // key[6]
    int thrw = 0;         // key[7]
    int order = key[9];   // key[8]

    */

    switch (key[8]) {
      case '0':
        aerialRising2(movement, jump, waitTime, attack, chargeTime, pummels, thrw, movement2);
        break;
      case '1':
        // aerialRising(jump, attack, wait, movement);
        break;
      case '2':
        // jumpKick(jump, attack);
        break;
      case '3':
        // ledgeTrap(movement, jump);
        break;
      case '4':
        // soleMovement(movement);
        break;
      case '5':
        // soleAttack(attack);
        break;
      case '6':
        // soleJump(jump);
        break;
      case '7':
        // aerial2(movement, jump, attack)
      default:
        break;
    }
}

void aerialRising2(int movement, char jump, int wait, int attack,int chargeTime,int pummels, int thrw, int movement2) {
  // TODO: analogWrite w/ Intensity of movements and jumps
  if (movement != 0) digitalWrite(movement, HIGH);
  if (jump == '1') digitalWrite(Y, HIGH);
  delay(wait);
  if (movement != 0) digitalWrite(movement, LOW);
  if (jump == '1') digitalWrite(Y, LOW);
  punch(attack, chargeTime, pummels, thrw);
  button40(movement2, 100);
}


void punch(char atk, int charge, int pummels, int thrw) {
  switch(atk) {
    case '1':
      button40(A);
      break;
    case '2':
      button40(A);
      button40(A);
      break;
    case '3':
      button40(LTilt);
      break;
    case '4':
      button40(RTilt);
      break;
    case '5':
      button40(UTilt);
      break;
    case '6':
      button40(DTilt);
      break;
    case '7':
      smashAttack(left ,charge);
      break;
    case '8':
      smashAttack(right, charge);
      break;
    case '9':
      smashAttack(up,charge);
      break;
    case 'a':
      smashAttack(down, charge);
      break;
    case 'b':
      grab(pummels, thrw);
      break;
    case 'c':
      // sheild
      button40(LR, charge);
      break;
    case 'd':
      button40(B, charge);
      break;
    case 'e':
      button40v2(B, left, charge);
      break;
    case 'f':
      button40v2(B, right, charge);
      break;
    case 'g':
      button40v2(B, up, charge);
      break;
    case 'h':
      button40v2(B, down, charge);
      break;
    case 'i':
      dashAttack(left, charge);
      break;
    case 'j':
      dashAttack(right, charge);
      break;
    case 'y':
      button40v2(B, left, charge);
      button40v2(B, up, charge);
      button40v2(B, down, charge);
      button40(B, charge);
      break;
    case 'z':
      button40v2(B, right, charge);
      button40v2(B, up, charge);
      button40v2(B, down, charge);
      button40(B, charge);
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
    
    if (key == "reset"){
       button40(A);
       button40(A);
       reset();
    } else {
      smash(key);
      Serial.println(key);
    }
  }
}
