const int hardLeft = 26;
const int mediumLeft = 7;
const int easyLeft = 6;
const int hardRight = 22;
const int mediumRight = 4;
const int easyRight = 5;
const int up = 30;
const int down = 28;
const int L = 24;
// 35 Unassigned
// 33 Unassigned
const int R = 25;
const int Z = 23;

const int cLeft = 36;
const int cRight = 38;
const int cUp = 39;
const int cDown  = 37;
const int B = 29;
const int A = 27;
const int X = 31;
const int Y = 35; // short
const int start = 33;

void button40(int direct, int wait = 40) {
  digitalWrite(direct, HIGH);
  delay(wait);
  digitalWrite(direct, LOW);
  digitalWrite(direct, LOW);
  digitalWrite(direct, LOW);
  delay(40);
}

void downThrow() {
  digitalWrite(down, HIGH);
  digitalWrite(Z, HIGH);
  delay(40);
  digitalWrite(Z, LOW);
  digitalWrite(down, LOW);
  delay(40);
  digitalWrite(down, HIGH);
  delay(40);
  digitalWrite(down, LOW);

}

void fullHop(int drift = false) {
  digitalWrite(Y, HIGH);
  if (drift) {
    digitalWrite(drift, HIGH);
    delay(25);
    digitalWrite(drift, LOW);
  } else {
    delay(25);
  }

  if (drift) {
    digitalWrite(drift, HIGH);
    delay(195);
    button40(Z);
    digitalWrite(drift, LOW);
    delay(160);
  } else {
    delay(345);
  }
  digitalWrite(Y, LOW);
  downThrow();
}
void banana() {
  digitalWrite(down, HIGH);
  digitalWrite(B, HIGH);
  delay(300);
  digitalWrite(down, LOW);
  digitalWrite(B, LOW);
  delay(350);
}


void infinite() {
  button40(mediumRight, 865);
  delay(300);
  for (int x = 0; x < 3; x++) {
    banana();
    digitalWrite(40, HIGH);
    delay(20);
    digitalWrite(40, LOW);
    delay(50);
    if (x % 2 == 0) {
      fullHop(mediumLeft);
    } else {
      fullHop(mediumRight);
    }
    delay(200);
    digitalWrite(down, HIGH);
    delay(40);
    digitalWrite(down, LOW);
    delay(100);
  }
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
    button40(mediumLeft, 20);
    button40(mediumRight, 20);
    u = u + 1;
  }
}

void reset() {
  digitalWrite(L, HIGH);
  digitalWrite(R, HIGH);

  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(L, LOW);
  digitalWrite(R, LOW);

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
  button40(mediumLeft);
  button40(down);
  button40(mediumRight);
  digitalWrite(B, HIGH);
  delay(100);
  digitalWrite(B, LOW);
}

void BW() {
  button40(down, 25);
  button40(mediumRight, 25);
  button40(down, 25);
  button40(mediumRight, 25);
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
 
    char jump = key[3];    // key[3] 0: none, 1:short, 2:shortFF, 3:full, 4:fullFF
    
    int attack = key[4];  // key[4]
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
        movement = mediumLeft;
        break;
      case '2':
        movement = mediumRight;
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
        movement2 = hardLeft;
        break;
      case '2':
        movement2 = hardRight;
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
        thrw = mediumLeft;
        break;
      case '2':
        thrw = mediumRight;
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
    */

    switch (key[8]) {
      case '0':
        aerialRising2(movement, jump, waitTime, attack, chargeTime, pummels, thrw, movement2);
        break;
      case '1':
         aerialRising(jump, attack, waitTime, movement);
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
        aerial2(movement, jump, attack);
      default:
        break;
    }
}

void jumpHeight(char jump) {
  if (jump == '1') {
    digitalWrite(X, HIGH);
    digitalWrite(Y, HIGH);
  } else if (jump == '2') {
    digitalWrite(X, HIGH);
    digitalWrite(Y, HIGH);
    // (SH frames / 2) * 16.667
  } else if (jump == '3') {
    digitalWrite(Y, HIGH);
  } else if (jump == '4') {
    digitalWrite(Y, HIGH);
    // (FH frames / 2) * 16.667
  }
  delay(17);
  digitalWrite(X, LOW);
  digitalWrite(Y, LOW);
}

void aerialRising2(int movement, char jump, int wait, char attack,int chargeTime,int pummels, int thrw, int movement2) {
   digitalWrite(hardRight, HIGH);
  delay(20);
  digitalWrite(hardRight, LOW);
  if (jump != '0') jumpHeight(jump);
  punch(attack, chargeTime, pummels, thrw);
  digitalWrite(hardRight, LOW);
  digitalWrite(Y, LOW);
}

void aerialRising(char jump, int attack, int wait, int movement) {
  digitalWrite(Y, HIGH);
  punch(attack,0 ,0 ,0);
  delay(wait);
  digitalWrite(movement, HIGH);
  delay(100);
  digitalWrite(movement, LOW);
  digitalWrite(Y, LOW);

}

void aerial2(int movement, char jump, char attack) {
  digitalWrite(hardRight, HIGH);
  delay(20);
  digitalWrite(hardRight, LOW);
  digitalWrite(Y, HIGH);
  punch(attack, 0, 0, 0);
  digitalWrite(hardRight, LOW);
  digitalWrite(Y, LOW);
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
      button40(cLeft);
      break;
    case '4':
      button40(cRight);
      break;
    case '5':
      button40(cUp);
      break;
    case '6':
      button40(cDown);
      break;
    case '7':
      smashAttack(mediumLeft ,charge);
      break;
    case '8':
      smashAttack(mediumRight, charge);
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
      button40(L, charge);
      break;
    case 'd':
      button40(B, charge);
      break;
    case 'e':
      button40v2(B, mediumLeft, charge);
      break;
    case 'f':
      button40v2(B, mediumRight, charge);
      break;
    case 'g':
      button40v2(B, up, charge);
      break;
    case 'h':
      button40v2(B, down, charge);
      break;
    case 'i':
      dashAttack(mediumLeft, charge);
      break;
    case 'j':
      dashAttack(mediumRight, charge);
      break;
    case 'y':
      button40v2(B, mediumLeft, charge);
      button40v2(B, up, charge);
      button40v2(B, down, charge);
      button40(B, charge);
      break;
    case 'z':
      button40v2(B, mediumRight, charge);
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

void hardBreak() {
  backOut();
  button40(B);
  button40(B);
  button40(B);
  delay(4000);
  button40(B);
  button40(B);
  button40(B);
}
void setup() {
  Serial.begin(9600);
  pinMode(start, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(hardLeft, OUTPUT);
  pinMode(mediumLeft, OUTPUT);
  pinMode(easyLeft, OUTPUT);
  pinMode(hardRight, OUTPUT);
  pinMode(mediumRight, OUTPUT);
  pinMode(easyRight, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(Z, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(cUp, OUTPUT);
  pinMode(cDown, OUTPUT);
  pinMode(cLeft, OUTPUT);
  pinMode(cRight, OUTPUT);
  pinMode(50, OUTPUT);
  digitalWrite(50, HIGH);
   reset(); 
 }

void loop() {
}

void serialEvent() {
    if (Serial.available() > 0) {
      String key = Serial.readString();
      Serial.println(key);
      if (key == "wake") {
        button40(A);
        button40(A);
      } else if (key == "reset") {
        reset();
      } else if (key == "test") { 
        button40(X);
      }else if (key == "menu") {
        button40(start);
      } else if (key == "back") {
        backOut();
      } else if (key == "a") {
        button40(A);
      } else if (key == "b") {
        button40(B);
      } else if (key == "y") {
        button40(Y);
      } else if (key == "xy") {
        jumpHeight('2');
      } else if (key == "cDown") {
        button40(cDown);
      } else if (key == "cUp") {
        button40(cUp);
      } else if (key == "cLeft") {
        button40(cLeft);
      } else if (key == "cRight") {
        button40(cRight);
      } else if (key == "u") {
        button40(up);
      } else if (key == "d") {
        button40(down);
      } else if (key == "d400") {
        button40(down, 400);
      } else if (key == "l400") {
        button40(mediumLeft, 400);
      } else if (key == "r400") {
        button40(mediumRight, 400);
      } else if (key == "u400") {
        button40(up, 400);
      } else if (key == "1l") {
        button40(easyLeft, 1000);
      } else if (key == "2l") {
        button40(mediumLeft, 1000);
      } else if (key == "3l") {
        button40(hardLeft, 1000);
      } else if (key == "1r") { 
        button40(easyRight, 1000);
      } else if (key == "2r") {
        button40(mediumRight, 1000);
      } else if (key == "3r") { 
        button40(hardRight, 1000);
      } else {
        smash(key);
      }
    } 
}
