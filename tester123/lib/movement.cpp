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

void eovement(String key) {
  String n;
  int o = 0;
  for (int a = 0; a < key.length(); a++) {
    if(key[a] != '0' && key[a] != 'e' && key[a] != 'u' && key[a] != 'd' && key[a] != 'l' && key[a] != 'r') {
      n = n + key[a];
    }
    if ( key[a] == '0') {
      o = o + 1;
    } 
  }
  int wait = n.toInt();
  for (int r = 0; r < o; r++) {
    wait = wait * 10;
  }
  Serial.println(wait);
  if(key[1] == 'r') {
    button40(easyRight, wait);
  }else if(key[1] == 'l') {
    button40(easyLeft, wait);
  }else if(key[1] == 'u') {
    button40(up, wait);
  }else if(key[1] == 'd') {
    button40(down, wait);
  }
}

void movement(String key) {
  String n;
  int o = 0;
  for (int a = 0; a < key.length(); a++) {
    if(key[a] != '0' && key[a] != 'm' && key[a] != 'u' && key[a] != 'd' && key[a] != 'l' && key[a] != 'r') {
      n = n + key[a];
    }
    if ( key[a] == '0') {
      o = o + 1;
    } 
  }
  int wait = n.toInt();
  for (int r = 0; r < o; r++) {
    wait = wait * 10;
  }
  Serial.println(wait);
  if(key[1] == 'r') {
    button40(mediumRight, wait);
  }else if(key[1] == 'l') {
    button40(mediumLeft, wait);
  }else if(key[1] == 'u') {
    button40(up, wait);
  }else if(key[1] == 'd') {
    button40(down, wait);
  }
}

void hovement(String key) {
  String n;
  int o = 0;
  for (int a = 0; a < key.length(); a++) {
    if(key[a] != '0' && key[a] != 'h' && key[a] != 'u' && key[a] != 'd' && key[a] != 'l' && key[a] != 'r') {
      n = n + key[a];
    }
    if ( key[a] == '0') {
      o = o + 1;
    } 
  }
  int wait = n.toInt();
  for (int r = 0; r < o; r++) {
    wait = wait * 10;
  }
  Serial.println(wait);
  if(key[1] == 'r') {
    button40(hardRight, wait);
  }else if(key[1] == 'l') {
    button40(hardLeft, wait);
  }else if(key[1] == 'u') {
    button40(up, wait);
  }else if(key[1] == 'd') {
    button40(down, wait);
  }
}
