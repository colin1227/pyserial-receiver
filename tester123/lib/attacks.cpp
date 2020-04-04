void punch(char atk, int charge, int pummels, int thrw) {
  switch (atk) {
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
      smashAttack(mediumLeft , charge);
      break;
    case '8':
      smashAttack(mediumRight, charge);
      break;
    case '9':
      smashAttack(up, charge);
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

void dashAttack(int direct, int wait = 150) {
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

void aerialRising2(int movement, char jump, int wait, char attack, int chargeTime, int pummels, int thrw, int movement2) {
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
  punch(attack, 0 , 0 , 0);
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

void grab(int pummels, int thrw) {
  button40(Z, 20);
  for (int i = 0; i < pummels; i++) {
    button40(Z, 20);
  }
  if (thrw) {
    button40(thrw, 20);
  }
}
