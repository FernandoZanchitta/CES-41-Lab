int minloc:	param a param low param high 
  0: k = low;
  1: x = a[low];
  2: r_0 = low + 1;
  3: i = r_0;
L0:
  4: r_1 = i >= high;
  5: if_true r_1 goto L1
  6: r_2 = a - x;
  7: if_true r_2 goto L0
  8: goto L1
  9: L0: 
 10: x = a[i];
 11: k = i;
 12: L1: 
 13: r_3 = i + 1;
 14: i = r_3;
 15: goto L0
L2:
return i;
void main:	param a return;
