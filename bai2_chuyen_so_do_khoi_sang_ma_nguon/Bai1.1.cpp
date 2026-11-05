#include <stdio.h>
#include <math.h>
void giaiPtb1(float b, float c) {
    if (b == 0) {
        if (c == 0) {
            printf("Phuong trinh co vo so nghiem\n");
        } else {
            printf("Phuong trinh vo nghiem (VN)\n");
        }
    } else {
        printf("Phuong trinh co 1 nghiem: x = %.2f\n", -c / b);
    }
}

int main() {
    float a, b, c;
    float delta, x1, x2;
    printf("Nhap cac he so a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0) {
        giaiPtb1(b, c);
    } 
    else {
        delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("Phuong trinh vo nghiem (VN)\n");
        }
        else if (delta == 0) {
            x1 = -b / (2 * a); 
            printf("Phuong trinh co nghiem kep: x1 = x2 = %.2f\n", x1);
        }
        else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co 2 nghiem phan biet:\n");
            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        }
    }

    return 0; 
}

