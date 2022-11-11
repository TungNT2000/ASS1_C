#include <stdio.h>
#include <math.h>
#define M_PI 3.14159
float ax, ay, bx, by, cx, cy;
float a, b, c, A, B, C, s, ma, mb, mc, ha, hb, hc;
float calc_scarla(float x1, float y1, float x2, float y2, float x3, float y3);

/*typedef struct m_vector{
    float x,y;
}m_vector;*/
void set_triangle()
{
    printf("Nhap thong so cua tam giac: \n");
    printf("\tNhap ax= ");
    scanf("%f", &ax);
    printf("\tNhap ay= ");
    scanf("%f", &ay);
    printf("\n");
    printf("\tNhap bx= ");
    scanf("%f", &bx);
    printf("\tNhap by= ");
    scanf("%f", &by);
    printf("\n");
    printf("\tNhap cx= ");
    scanf("%f", &cx);
    printf("\tNhap cy= ");
    scanf("%f", &cy);
    printf("\n");
}
void display_triangle()
{
    printf("- Thong so da nhap A(%.2f,%.2f), B(%.2f,%.2f), C(%.2f,%.2f)\n", ax, ay, bx, by, cx, cy);
}
int check_triangle()
{
    if (a <= 0 || b <= 0 || c <= 0 || (a + b) <= c || (b + c) <= a || (c + a) <= b)
    {
        printf("\t -> Khong phai la mot tam giac\n");
        return 0;
    }
    printf("\t -> La mot tam giac\n");
    return 1;
}
float calc_distance(float x1, float y1, float x2, float y2)
{
    return (float)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
// GOC A
float calc_angle(float a, float b, float c)
{
    float tmp = (b * b + c * c - a * a) / (2 * b * c);
    return (float)acos(tmp);
}
void calc_triagle_edge()
{
    a = calc_distance(bx, by, cx, cy);
    b = calc_distance(ax, ay, cx, cy);
    c = calc_distance(ax, ay, bx, by);
    printf("- Do dai ba canh lan luot la: \n");
    printf("\ta=%f, b=%f, c=%f\n", a, b, c);
}
void calc_triagle_angle()
{
    A = calc_angle(a, b, c);
    B = calc_angle(b, c, a);
    C = calc_angle(c, a, b);
    printf("- So do cac goc cua tam giac la:\n");
    printf("\tA=%f, B=%f, C=%f\n", A, B, C);
}
void check_triangle_type()
{
    /*   m_vector v_ab,v_bc,v_ca;
       v_ab = calc_vector(ax,ay,bx,by);
       v_bc = calc_vector(bx,by,cx,cy);
       v_ca = calc_vector(cx,cy,ax,ay);

       float tmp1,tmp2,tmp3;
       tmp1= calc_scarla(v_ab,v_bc);
       tmp2= calc_scarla(v_bc,v_ca);
       tmp3= calc_scarla(v_ca,v_ab);*/
    float tmp1, tmp2, tmp3;
    tmp1 = calc_scarla(ax, ay, bx, by, cx, cy); // A
    tmp2 = calc_scarla(bx, by, ax, ay, cx, cy); // B
    tmp3 = calc_scarla(cx, cy, ax, ay, bx, by); // C

    if (tmp1 == 0 || tmp2 == 0 || tmp3 == 0)
    {
        if (a == b || b == c || c == a)
        {
            printf("\t -> Day la tam giac vuong can\n");
        }
        else
            printf("\t -> Day la tam giac vuong\n");
    }
    else if (tmp1 > 0 || tmp2 > 0 || tmp3 > 0)
    {
        printf("\t -> Day la tam giac tu\n");
    }
    else
        printf("\t -> Day la tam giac nhon\n");
    if (a != b || b != c || c != a)
    {
        if (a == b || b == c || c == a)
        {
            printf("\t -> Day la tam giac can\n");
        }
        else
            ("\t -> Day la tam giac thuong\n");
    }
    else
        printf("\t -> Day la tam giac deu\n");
}
void calc_triangle_area()
{
    float p = (a + b + c) / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("- Dien tich tam giac l�: %f\n", s);
}
float calc_m(float a, float b, float c)
{
    return (float)(sqrt((2 * (b * b + c * c) - a * a) / 4));
}
float calc_h(float s, float a)
{
    return 2 * s / a;
}
/*m_vector calc_vector(float x1, float y1, float x2, float y2){
    m_vector v;
    v.x= x2-x1;
    v.y= y2-y1;
    return v;

}*/
float calc_scarla(float x1, float y1, float x2, float y2, float x3, float y3)
{
    return (float)((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1));
}
void calc_triangle_m()
{
    ma = calc_m(a, b, c);
    mb = calc_m(b, c, a);
    mc = calc_m(c, a, b);
    printf("- Do dai duong trung tuyen: \n");
    printf("\t ma=%f, mb=%f, mc=%f\n", ma, mb, mc);
}
void calc_triangle_h()
{
    ha = calc_h(s, a);
    hb = calc_h(s, b);
    hc = calc_h(s, c);
    printf("- Do dai duong cao: \n");
    printf("\t ha=%f, hb=%f, hc=%f\n", ha, hb, hc);
}
int main()
{
    set_triangle();
    display_triangle();
    calc_triagle_edge();
    int check = check_triangle();
    if (check == 1)
    {
        calc_triagle_angle();
        check_triangle_type();
        calc_triangle_area();
        calc_triangle_m();
        calc_triangle_h();
    }
    return 0;
}
