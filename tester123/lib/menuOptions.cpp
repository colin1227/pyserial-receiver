void back() {
  button40(B);
}

void backOut() {
  button40(start);
  delay(200);
  button40(up);
  button40(A, 750);
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

void low() {
  digitalWrite(start, LOW);
  digitalWrite(up, LOW);
  digitalWrite(down, LOW);
  digitalWrite(hardLeft, LOW);
  digitalWrite(mediumLeft, LOW);
  digitalWrite(easyLeft, LOW);
  digitalWrite(hardRight, LOW);
  digitalWrite(mediumRight, LOW);
  digitalWrite(easyRight, LOW);
  digitalWrite(A, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(Z, LOW);
  digitalWrite(L, LOW);
  digitalWrite(R, LOW);
  digitalWrite(cUp, LOW);
  digitalWrite(cDown, LOW);
  digitalWrite(cLeft, LOW);
  digitalWrite(cRight, LOW);
}
