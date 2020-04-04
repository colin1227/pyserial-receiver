#include <general.h>
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
