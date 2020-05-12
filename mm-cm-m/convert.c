#include <stdio.h>

int main() {
    float mm, cm, m;

    printf("enter a length in metres: ");
    scanf("%f", &m);

    cm = m * 100;
    mm = cm *10;

    printf("length in metres: %.2f m \n", m);
    printf("length in centimetres: %0.2f cm \n", cm);
    printf("length in milimetres: %0.2f mm \n", mm);
}