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

void manualCommand (String key) {
  if (key == "w"){
    button40(A);
    button40(A);
  } else if (key == "reset") {
    reset();
  } else if (key == "test") {
    button40(mediumRight, 1000);
  } else if (key == "menu" || key == "start") {
    button40(start);
  } else if (key == "back") {
    backOut();
  } else if (key == "a") {
    button40(A);
  } else if (key == "b") {
    button40(B);
  } else if (key == "x") {
    button40(X);
  } else if (key == "y") {
    button40(Y);
  } else if (key == "xy") {
    jumpHeight('2');
  } else if (key == "z") {
    button40(Z);
  } else if (key == "L") {
    button40(L);
  } else if (key == "R") {
    button40(R);
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
  } else if (key == "1l") {
    button40(easyLeft);
  } else if (key == "2l") {
    button40(mediumLeft);
  } else if (key == "3l") {
    button40(hardLeft);
  } else if (key == "1r") {
    button40(easyRight);
  } else if (key == "2r") {
    button40(mediumRight);
  } else if (key == "3r") {
    button40(hardRight);
  } else if (key == "d400") {
    button40(down, 400);
  } else if (key == "l400") {
    button40(hardLeft, 400);
  } else if (key == "r400") {
    button40(hardRight, 400);
  } else if (key == "u400") {
    button40(up, 400);
  } else if (key[0] == 'e') {
    eovement(key);
  } else if (key[0] == 'm') {
    movement(key);
  } else if (key[0] == 'h') {
    hovement(key);
  }
}
