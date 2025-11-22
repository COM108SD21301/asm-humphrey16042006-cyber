#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int BCNN(int a, int b) {
    return a * b / UCLN(a, b);
}

int main() {
    int luaChon;
    do {
        printf("\n================ MENU ================");
        printf("\nNhap 1: Lua chon chuc nang So nguyen");
        printf("\nNhap 2: Lua chon chuc nang tim UCLN va BCNN");
        printf("\nNhap 3: Lua chon chuc nang Tinh tien quan Karaoke");
        printf("\nNhap 4: Lua chon chuc nang Tinh tien dien");
        printf("\nNhap 5: Tinh lai suat vay ngan hang tra gop");
        printf("\nNhap 6: Sap xep thong tin sinh vien");
        printf("\nNhap 7: Xay dung chuong trinh tinh toan phan so");
        printf("\nNhap 0: Thoat chuong trinh");
        printf("\nMoi ban nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {

        case 1: {
            printf("Ban chon CN1\n");
            float x;
            printf("Moi ban nhap so x: "); 
            scanf("%f", &x);

            if (x == (int)x) {
                printf("%.0f la so nguyen\n", x);

                for (int i = 1; i <= x / 2; i++) {
                    if (i * i == x) {
                        printf("%.0f la so chinh phuong\n", x);
                    }
                }

                int xLaSoNT = 1;
                for (int i = 2; i <= sqrt(x); i++) {
                    if ((int)x % i == 0) xLaSoNT = 0;
                }

                if (xLaSoNT == 1) {
                    printf("%.0f la so nguyen to\n", x);
                } else {
                    printf("%.0f khong phai so nguyen to\n", x);
                }

            } else {
                printf("%.2f la so thuc\n", x);
            }
            break;
        }

        case 2: {
            printf("Ban chon CN2\n");
            int a, b;
            printf("Nhap 2 so nguyen: "); 
            scanf("%d%d", &a, &b);

            printf("UCLN(%d,%d) = %d\n", a, b, UCLN(a, b));
            printf("BCNN(%d,%d) = %d\n", a, b, BCNN(a, b));
            break;
        }

        case 3: {
            printf("Ban chon CN3\n");
            int start, end;
            printf("Nhap gio bat dau: "); scanf("%d", &start);
            printf("Nhap gio ket thuc: "); scanf("%d", &end);

            if (start < 12 || end > 23 || start >= end) {
                printf("Gio khong hop le!\n");
            } else {
                int soGio = end - start;
                float tongTien = 0;

                if (soGio <= 3) tongTien = soGio * 150000;
                else tongTien = 3 * 150000 + (soGio - 3) * 150000 * 0.7;

                if (start >= 14 && start <= 17) tongTien *= 0.9;

                printf("So tien phai tra: %.0f\n", tongTien);
            }
            break;
        }

        case 4: {
            printf("Ban chon CN4\n");
            int kwh; 
            printf("Nhap so kWh: "); 
            scanf("%d", &kwh);

            int bac[] = {50, 50, 100, 100, 100};
            int gia[] = {1678, 1734, 2014, 2536, 2834, 2927};

            int tong = 0, i = 0;

            while (kwh > 0 && i < 5) {
                int sd = (kwh > bac[i]) ? bac[i] : kwh;
                tong += sd * gia[i];
                kwh -= sd;
                i++;
            }
            if (kwh > 0) tong += kwh * gia[5];

            printf("Tien dien phai tra: %d VND\n", tong);
            break;
        }

        case 5: {
            printf("Ban chon CN5\n");
            int tienVay; 
            printf("Nhap so tien vay: "); 
            scanf("%d", &tienVay);

            int gocPhaiTra = tienVay / 12;
            int conLai = tienVay;

            for (int thang = 1; thang <= 12; thang++) {
                int lai = conLai * 0.05;
                int phaiTra = gocPhaiTra + lai;
                conLai -= gocPhaiTra;

                printf("Thang %d: Lai=%d, Goc=%d, Tong=%d, Con lai=%d\n",
                       thang, lai, gocPhaiTra, phaiTra, conLai);
            }
            break;
        }

        case 6: {
            printf("Ban chon CN6\n");
            int n; 
            printf("Nhap so luong SV: "); 
            scanf("%d", &n);

            char ten[50][50]; 
            float diem[50];

            for (int i = 0; i < n; i++) {
                printf("Nhap ten SV %d: ", i + 1); 
                scanf("%s", ten[i]);
                printf("Nhap diem SV %d: ", i + 1); 
                scanf("%f", &diem[i]);
            }

            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (diem[i] < diem[j]) {
                        float tmp = diem[i]; 
                        diem[i] = diem[j]; 
                        diem[j] = tmp;

                        char t[50]; 
                        strcpy(t, ten[i]); 
                        strcpy(ten[i], ten[j]); 
                        strcpy(ten[j], t);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                printf("%s - %.2f - ", ten[i], diem[i]);
                if (diem[i] >= 9) printf("Xuat sac\n");
                else if (diem[i] >= 8) printf("Gioi\n");
                else if (diem[i] >= 6.5) printf("Kha\n");
                else if (diem[i] >= 5) printf("Trung binh\n");
                else printf("Yeu\n");
            }
            break;
        }

        case 7: {
            printf("Ban chon CN7\n");
            int tu1, mau1, tu2, mau2;

            printf("Nhap phan so 1 (tu mau): "); 
            scanf("%d%d", &tu1, &mau1);

            printf("Nhap phan so 2 (tu mau): "); 
            scanf("%d%d", &tu2, &mau2);

            printf("Tong: %d/%d\n", tu1 * mau2 + tu2 * mau1, mau1 * mau2);
            printf("Hieu: %d/%d\n", tu1 * mau2 - tu2 * mau1, mau1 * mau2);
            printf("Tich: %d/%d\n", tu1 * tu2, mau1 * mau2);
            printf("Thuong: %d/%d\n", tu1 * mau2, tu2 * mau1);

            break;
        }

        case 0:
            return 0;

        default:
            printf("\nBan nhap sai lua chon\n");
            break;
        }
    } while (luaChon != 0);

    return 0;
}

