#include <iostream>
#include <Eigen/Dense>

/*
    位姿表示
            旋转向量、四元数表示的位姿可以直接当做旋转矩阵参与运算，因为重载了乘法运算符。
    不同表示方式的位姿在赋值时需要进行显式类型转换。

    位姿初始化
            旋转向量
    旋转向量并不是为了储存旋转，而是为了更加方便地创建其他类型的旋转。
    旋转轴必须是单位向量，推荐使用基向量。
    示例：

    // 3D旋转矩阵直接使用Matrix3d或Matrix3f
    Matrix3d rotation_matrix = Matrix3d::Identity();
    // 旋转向量使用AngleAxis，其底层不直接是Matrix类，但运算可以当作矩阵（因为重载了运算符）
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));    // 沿Z轴旋转45度
    rotation_matrix = rotation_vector.matrix();                 // 旋转向量转旋转矩阵
    rotation_matrix = rotation_vector.toRotationMatrix();       // 旋转向量转旋转矩阵
    // 用AngleAxis进行坐标变换
    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    // 相当于用旋转矩阵进行坐标变换
    Vector3d v_rotated = rotation_matrix * v;

 */
#include <Eigen/Geometry> // 需要包含几何库

void demo01()
{

    // 1. 初始化旋转矩阵（3x3）
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    std::cout << "旋转矩阵（初始化为单位矩阵）:\n" << rotation_matrix << "\n\n";

    // 2. 使用旋转向量（AngleAxis）表示旋转，沿Z轴旋转45度
    Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1)); // 绕 Z 轴旋转 45°
    std::cout << "旋转向量的旋转轴:\n" << rotation_vector.axis().transpose() << "\n\n";
    std::cout << "旋转向量的旋转角度: " << rotation_vector.angle() * 180 / M_PI << " 度\n\n";

    // 3. 旋转向量转化为旋转矩阵
    rotation_matrix = rotation_vector.matrix();
    std::cout << "旋转矩阵（由旋转向量转换）:\n" << rotation_matrix << "\n\n";

    // 4. 旋转向量转旋转矩阵的另一种方式
    Eigen::Matrix3d rotation_matrix2 = rotation_vector.toRotationMatrix();
    std::cout << "旋转矩阵（toRotationMatrix 方法转换）:\n" << rotation_matrix2 << "\n\n";

    // 5. 使用旋转向量进行坐标变换
    Eigen::Vector3d v(1, 0, 0); // 原始向量
    Eigen::Vector3d v_rotated = rotation_vector * v; // 旋转向量 * 向量
    std::cout << "原始向量:\n" << v.transpose() << "\n";
    std::cout << "旋转后向量（使用旋转向量计算）:\n" << v_rotated.transpose() << "\n\n";

    // 6. 使用旋转矩阵进行坐标变换
    Eigen::Vector3d v_rotated_matrix = rotation_matrix * v; // 旋转矩阵 * 向量
    std::cout << "旋转后向量（使用旋转矩阵计算）:\n" << v_rotated_matrix.transpose() << "\n\n";


}

// 绕x轴 y轴 z轴旋转

void demo02() {
    // 定义旋转角度（90°，即π/2）
    double angle = M_PI / 2;

    // 原始向量 (1, 0, 0)
    Eigen::Vector3d v(1, 0, 0);

    // 绕 X 轴旋转 90°
    Eigen::AngleAxisd rotation_x(angle, Eigen::Vector3d(1, 0, 0));  // 旋转向量
    Eigen::Vector3d v_rotated_x = rotation_x * v;

    std::cout << "绕 X 轴旋转后的向量:\n" << v_rotated_x.transpose() << "\n\n";

    // 绕 Y 轴旋转 90°
    Eigen::AngleAxisd rotation_y(angle, Eigen::Vector3d(0, 1, 0));  // 旋转向量
    Eigen::Vector3d v_rotated_y = rotation_y * v;

    std::cout << "绕 Y 轴旋转后的向量:\n" << v_rotated_y.transpose() << "\n\n";

    // 绕 Z 轴旋转 90°
    Eigen::AngleAxisd rotation_z(angle, Eigen::Vector3d(0, 0, 1));  // 旋转向量
    Eigen::Vector3d v_rotated_z = rotation_z * v;

    std::cout << "绕 Z 轴旋转后的向量:\n" << v_rotated_z.transpose() << "\n\n";

}


// 欧拉角的概念：
/**
欧拉角（Euler Angles） 是一种常用的表示 3D 空间中物体旋转 的方法。
 它通过三个角度来描述一个刚体的旋转，通常这三个角度分别是绕 X 轴、Y 轴 和 Z 轴 的旋转角度。

欧拉角 由三个旋转角度组成：
    俯仰角（Pitch）：绕 X 轴 的旋转。
    偏航角（Yaw）：绕 Y 轴 的旋转。
    滚转角（Roll）：绕 Z 轴 的旋转。
这些角度可以用不同的顺序进行组合，顺序的不同会导致不同的旋转结果。
 这些顺序决定了旋转的方式，例如 XYZ 顺序、ZYX 顺序等。
*/

/*
内旋与外旋的区别
        内旋（Intrinsic Rotation）：
    内旋表示旋转是相对于 每次旋转后更新的坐标轴 进行的。
    换句话说，每次旋转之后，坐标轴会随着旋转而变化。旋转是在更新后的坐标轴上进行的。
    在 Eigen 中，默认使用的是 内旋 方式。

外旋（Extrinsic Rotation）：
    外旋表示旋转是相对于 固定坐标轴 进行的，即坐标轴在旋转过程中保持不变。
    每次旋转的坐标轴都是 固定的世界坐标系轴，即旋转时坐标轴不发生变化。

内旋与外旋的旋转顺序
        欧拉角的旋转顺序很重要，旋转顺序会影响最终的结果。对于 内旋 和 外旋，其旋转顺序是相反的。
    外旋（Fixed Axis）：
        旋转顺序是：先绕世界坐标系的 Z 轴旋转，再绕 Y 轴旋转，最后绕 X 轴旋转，顺序是 ZYX。

    内旋（Rotated Axis）：
        旋转顺序是：先绕旋转后的 X 轴旋转，再绕 Y 轴旋转，最后绕 Z 轴旋转，顺序是 XYZ。
*/

// 欧拉角到旋转矩阵的转换
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <cmath> // For M_PI

void demo03()
{
    // 定义欧拉角（以弧度为单位）
    double roll = M_PI / 4;  // 滚转角（绕 Z 轴）
    double pitch = M_PI / 6; // 俯仰角（绕 Y 轴）
    double yaw = M_PI / 3;   // 偏航角（绕 X 轴）

    // 使用 Eigen 的 AngleAxis 类进行旋转
    Eigen::Matrix3d rotation_matrix = Eigen::AngleAxisd(roll, Eigen::Vector3d::UnitZ()) *
                                      Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitY()) *
                                      Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitX());

    // 输出旋转矩阵
    std::cout << "Rotation Matrix:\n" << rotation_matrix << std::endl;

    // 创建一个向量（1, 0, 0）并旋转
    Eigen::Vector3d v(1, 0, 0);
    Eigen::Vector3d v_rotated = rotation_matrix * v;

    std::cout << "Rotated Vector:\n" << v_rotated.transpose() << std::endl;
}



// 内旋和外旋的旋转顺序
/*
        假设我们有相同的旋转角度，可以使用不同的旋转顺序来进行内旋和外旋的组合。
内旋： 使用 AngleAxis 表示。
外旋： 使用 Rotation 进行旋转顺序的控制。

内旋示例：
    Eigen::Matrix3d rotation_matrix = Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitX()) *
                                  Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitY()) *
                                  Eigen::AngleAxisd(roll, Eigen::Vector3d::UnitZ());

 外旋示例：
    Eigen::Matrix3d rotation_matrix = Eigen::AngleAxisd(roll, Eigen::Vector3d::UnitZ()) *
                                  Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitY()) *
                                  Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitX());
 */


