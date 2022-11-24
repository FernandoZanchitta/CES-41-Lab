int teste:	param y param z param a param d 
  0: ka = r_0;
  1: r_1 = y + z;
  2: k = r_1;
return k;
void main:	param a param d 
L0:
  3: r_2 = x == 10;
  4: if_true r_2 goto L1
  5: r_3 = 1 + 2;
  6: r_4 = r_3 + 3;
  7: r_5 = r_4 + 4;
  8: r_6 = r_5 + 5;
  9: b = r_6;
 10: r_7 = b * 2;
 11: r_8 = 138 + r_7;
 12: r_9 = 5 * r_8;
 13: x = r_9;
L1:
 14: r_10 = call teste, 3
 15: x = r_10;
return;
