/* Um programa para calcular mdc */
int gdc (int u, int v)
{
if (v == 0) return u;
else return gdc(v,u-u/v*v);
/* u-u / v*v == u mod v */
}
int input()
{
    return 0;
}
void output (int x){
    return;
}

void main(void)
{
int x;
int y;
x = input();
y = input();
output(gdc(x,y));
}