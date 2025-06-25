#include <stdio.h>

// 函数：计算激光引导能量弧射程
double calculate_range(double power_kw, double pressure_atm, double coefficient_c) {
    if (pressure_atm <= 0) {
        printf("气压必须大于0\n");
        return -1;
    }
    return coefficient_c * power_kw / pressure_atm;
}

int main() {
    double power, pressure, coefficient, range;

    // 输入激光功率(kW)
    printf("请输入激光功率(kW): ");
    scanf("%lf", &power);

    // 输入环境气压(atm)
    printf("请输入环境气压(atm): ");
    scanf("%lf", &pressure);

    // 输入经验系数C (m*atm/kW)
    printf("请输入经验系数C (m*atm/kW), 通常0.1~0.3: ");
    scanf("%lf", &coefficient);

    range = calculate_range(power, pressure, coefficient);

    if (range >= 0) {
        printf("激光诱导等离子体弧射程为: %.2f 米\n", range);
    } else {
        printf("计算失败，请检查输入参数。\n");
    }

    return 0;
}
