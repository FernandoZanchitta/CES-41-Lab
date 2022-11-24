int gdc:	param u param v 
  0: r_0 = v == 0;
  1: if_true r_0 goto L0
  2: r_1 = call gdc, 3
  3: r = r_1;
  4: goto L1
  5: L0: 
  6: r = u;
  7: L1: 
return r;
void main:	param c 
  8: c = r_1;
  9: x = r_1;
 10: r_2 = 5 + x;
 11: y = r_2;
 12: r_3 = call gdc, 3
 13: r_4 = 48939520 + 4;
 14: a = r_4;
return;
