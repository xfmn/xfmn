#include <stdio.h>

#define NSTEPS 1000
#define DT 0.001  // 时间步长，秒
#define DX 0.01   // 空间步长，米
#define NX 100    // 空间点数

typedef struct {
    double Ex;   // 电场 (V/m)
    double Bz;   // 磁场垂直于电流方向 (T)
    double Jx;   // 电流密度 (A/m^2)
    double Fx;   // 力密度 (N/m^3)
    double vx;   // 等离子体速度 (m/s)
} Cell;

int main() {
    Cell plasma[NX];
    double conductivity = 1e5; // 电导率 S/m (示例值)
    double mass_density = 1e-4; // 等离子体质量密度 kg/m^3 (示例值)
    int i, t;

    // 初始化电场和磁场（示例：恒定电场和磁场）
    for (i = 0; i < NX; i++) {
        plasma[i].Ex = 1e4;   // 1e4 V/m
        plasma[i].Bz = 0.01;  // 0.01 Tesla
        plasma[i].Jx = 0.0;
        plasma[i].Fx = 0.0;
        plasma[i].vx = 0.0;
    }

    // 时间迭代计算
    for (t = 0; t < NSTEPS; t++) {
        for (i = 0; i < NX; i++) {
            // 计算电流密度 J = sigma * E
            plasma[i].Jx = conductivity * plasma[i].Ex;

            // 计算洛伦兹力 F = J x B
            // J方向x，B方向z，则 F方向y = Jx * Bz
            // 简化为标量演示，这里用Fx表示大小
            plasma[i].Fx = plasma[i].Jx * plasma[i].Bz;

            // 速度更新 (简单牛顿第二定律) v = v + (F/mass_density)*dt
            plasma[i].vx += (plasma[i].Fx / mass_density) * DT;

            // 位置更新可根据需要添加
        }

        // 简单输出第一个空间点速度演化
        if (t % 100 == 0) {
            printf("Time=%.3f s, Plasma velocity at x=0: %.3f m/s\n", t * DT, plasma[0].vx);
        }
    }

    return 0;
}
