
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
