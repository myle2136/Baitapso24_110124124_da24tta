#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int tu;   
    int mau;  
} 
	PHAN_SO;
// Ham nhap phan so 
void nhapPhanSo(PHAN_SO *ps) 
{
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do 
	{
        printf("Nhap mau so: ");
        scanf("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so khong duoc bang 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

//Ham xuat phan so 
void xuatPhanSo(PHAN_SO ps) 
{
    printf("%d/%d\n", ps.tu, ps.mau);
}

// Ham tinh uoc chung lon nhat
int ucln(int a, int b) 
{
    a = abs(a);
    b = abs(b);
    while (b != 0) 
	{
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//Ham rut gon phan so 
void rutGonPhanSo(PHAN_SO *ps) 
{
    int u = ucln(ps->tu, ps->mau);
    ps->tu /= u;
    ps->mau /= u;
}

//Ham cong hai phan so
PHAN_SO congPhanSo(PHAN_SO ps1, PHAN_SO ps2) 
{
    PHAN_SO ps;
    ps.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ps.mau = ps1.mau * ps2.mau;
    rutGonPhanSo(&ps);
    return ps;
}

// Hàm tru hai phân so
PHAN_SO truPhanSo(PHAN_SO ps1, PHAN_SO ps2) 
{
    PHAN_SO ps;
    ps.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ps.mau = ps1.mau * ps2.mau;
    rutGonPhanSo(&ps);
    return ps;
}

//Ham nhan hai phan so
PHAN_SO nhanPhanSo(PHAN_SO ps1, PHAN_SO ps2) 
{
    PHAN_SO ps;
    ps.tu = ps1.tu * ps2.tu;
    ps.mau = ps1.mau * ps2.mau;
    rutGonPhanSo(&ps);
    return ps;
}

// Ham chia hai phan so 
PHAN_SO chiaPhanSo(PHAN_SO ps1, PHAN_SO ps2) 
{
    PHAN_SO ps;
    if (ps2.tu == 0) 
	{
        printf("Loi: Khong the chia cho 0\n");
        exit(1);
    }
    ps.tu = ps1.tu * ps2.mau;
    ps.mau = ps1.mau * ps2.tu;
    rutGonPhanSo(&ps);
    return ps;
}

//Ham main 
int main() 
{
    PHAN_SO ps1, ps2, psKQ;
    
    printf("Nhap phan so 1:\n");
    nhapPhanSo(&ps1);
    rutGonPhanSo(&ps1);
    fflush(stdin);
  
    printf("Nhap phan so 2:\n");
    nhapPhanSo(&ps2);
    rutGonPhanSo(&ps2);
    fflush(stdin);
    
    // Xuat cac phan so da nhap 
    printf("Phan so 1: ");
    xuatPhanSo(ps1);
    printf("Phan so 2: ");
    xuatPhanSo(ps2);
    
    // Cong hai phan so
    psKQ = congPhanSo(ps1, ps2);
    printf("Tong hai phan so: ");
    xuatPhanSo(psKQ);
    
    // Tru hai phan so
    psKQ = truPhanSo(ps1, ps2);
    printf("Hieu hai phan so: ");
    xuatPhanSo(psKQ);

    // Nhan hai phan so
    psKQ = nhanPhanSo(ps1, ps2);
    printf("Tich hai phan so: ");
    xuatPhanSo(psKQ);
    
    // Chia hai phan so 
    psKQ = chiaPhanSo(ps1, ps2);
    printf("Thuong hai phan so: ");
    xuatPhanSo(psKQ);

    return 0;
}

