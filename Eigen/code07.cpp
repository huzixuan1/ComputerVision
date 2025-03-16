#include <iostream>
#include <Eigen/Dense>

// 矩阵运算
// 方阵相关

/*
    C.trace()           // 迹
    C.inverse()         // 逆
    C.determinant()     // 行列式
 */

//点乘和叉乘
/*
    // 点乘
    x.dot(y)
    x.transpose() * y
    // 叉乘
    x.cross(y)
 */

void demo01()
{
    using namespace Eigen;
    Eigen::Matrix3f C;
    C << 2, -1, 3,
            1,  0, -2,
            -3,  4,  1;

//    C<<1,0,0,
//    0,1,0,
//    0,0,1;

    std::cout << "矩阵 C:\n" << C << "\n\n";
    // 计算矩阵的迹（trace）：对角线元素之和
    std::cout << "C.trace() (迹): " << C.trace() << "\n\n";

    // 计算矩阵的行列式（determinant）
    std::cout << "C.determinant() (行列式): " << C.determinant() << "\n\n";

    // 计算矩阵的逆（inverse）
    if (C.determinant() != 0) {  // 确保矩阵可逆
        Eigen::Matrix3f C_inv = C.inverse();
        std::cout << "C.inverse() (逆矩阵):\n" << C_inv << "\n\n";
    } else {
        std::cout << "矩阵 C 是奇异的，不可逆。\n\n";
    }
}

// 向量运算

void demo02()
{

    // --------------- 向量运算 ---------------
    // 创建 3 维向量
    Eigen::Vector3f x(1, 2, 3);
    Eigen::Vector3f y(4, 5, 6);

    std::cout << "向量 x:\n" << x.transpose() << "\n";
    std::cout << "向量 y:\n" << y.transpose() << "\n\n";

    // 计算点乘（dot product）
    float dot_product = x.dot(y);
    std::cout << "x.dot(y) (点乘): " << dot_product << "\n";

    // 另一种点乘方式：使用矩阵乘法
    float dot_product_alt = x.transpose() * y;
    std::cout << "x.transpose() * y (点乘, 另一种方式): " << dot_product_alt << "\n\n";

    // 计算叉乘（cross product）
    Eigen::Vector3f cross_product = x.cross(y);
    std::cout << "x.cross(y) (叉乘):\n" << cross_product.transpose() << "\n";
    // 叉乘的计算方式：写两遍a b,然后给第一列叉了，依次往后做较差乘就可以了
}
