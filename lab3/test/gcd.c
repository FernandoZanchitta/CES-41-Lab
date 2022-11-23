/* Um programa para calcular mdc */
<<<<<<< HEAD
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
=======
int gdc(int u, int v)
{
    int x;
    if (v == 0)
        return u;
    else
        return gdc(v, u - u / v * v);
    /* u-u / v*v == u mod v */
}
void main(void)
{
    int x;
    int y;
    x = input();
    y = input();
    output(gdc(x, y));
>>>>>>> de37242b5c634879d72f1adc78fcc4f7bc2525d3
}