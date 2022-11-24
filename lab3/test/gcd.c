/* Um programa para calcular mdc */

int gdc (int u, int v)
{
    int r;
if (v == 0) {r = u; return r;}
else {r = gdc(v,u-u/v*v); return r;}

/* u-u / v*v == u mod v */
}

void main(int c)
{
int x;
int y;
int a;
c= 5;
x = 3;
y = 5+x;
a = gdc(x,y) + 4;
}