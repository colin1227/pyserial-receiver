
void smash(String key) {
  /////// vars //////////

  int movement = 0;     // key[0]
  // int intensity = 0;

  int movement2 = 0;    // key[1]
  // int intensity2 = 0;
  // int waitTime2 = 0;

  int waitTime = 0;     // key[2]

  char jump = key[3];   // key[3]

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
