
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

// 矩阵操作

// 计算大小
void demo01()
{
    // 创建一个 3x3 的矩阵
    Matrix3f C;
    C << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;

    // 创建一个 3 维的向量
    Vector3f x(1.0f, 2.0f, 3.0f);

    // 向量长度
    std::cout << "x.size() = " << x.size() << std::endl;  // 输出 3

    // 矩阵行列数
    std::cout << "C.rows() = " << C.rows() << std::endl;  // 输出 3
    std::cout << "C.cols() = " << C.cols() << std::endl;  // 输出 3
}

// 转置
/**
转置矩阵
        C.transpose()：返回矩阵 C 的转置矩阵，
        即行列互换的矩阵，但不会修改原矩阵。它返回一个新的矩阵。

        C.transposeInPlace()：对矩阵 C 进行原地转置，
         直接修改 C 本身，返回的是 void，没有新矩阵返回。

共轭转置
        C.adjoint()：计算矩阵 C 的 共轭转置，
        对于复数矩阵来说，它会进行复数共轭操作并转置。

C.adjointInPlace()：
        对矩阵 C 进行原地共轭转置（即对矩阵 C 本身进行修改）。
        对于 实数矩阵，转置与共轭转置没有区别。
 */

/*
共轭矩阵（Conjugate Matrix）
定义：共轭矩阵是指对一个复数矩阵中的每个元素取 复共轭 后得到的矩阵。
对于复数 a + bi，其复共轭是 a - bi，即改变复数的虚部符号。
对于实数矩阵，其复共轭矩阵与原矩阵相同，因为实数没有虚部
 */

/*
共轭转置矩阵（Adjoint Matrix 或 Hermitian Transpose）
定义：共轭转置矩阵（也称作 Hermitian Transpose）是指 先对矩阵的元素取复共轭，
然后对矩阵进行 转置。可以理解为：
共轭：每个矩阵元素的复共轭。
转置：矩阵的行列互换。
对于一个复数矩阵 A，它的共轭转置 A* 是将矩阵 A 的每个元素先取复共轭，然后转置该矩阵。
*/

/*
假设矩阵 A 为：
A = [ 1   2+i ]
[ 3-i  4 ]

共轭矩阵是：
A_conjugate = [ 1    2-i ]
[ 3+i  4   ]

共轭转置矩阵（Adjoint Matrix）：
A* = [ 1    3+i ]
[ 2-i  4   ]
 */

void demo02()
{
    // 创建一个 3x3 的实数矩阵
    Matrix3f C;
    C << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;

    // 输出原矩阵
    std::cout << "Original Matrix C:\n" << C << std::endl;

    // 计算转置矩阵
    Matrix3f C_transpose = C.transpose();
    std::cout << "Transpose of C:\n" << C_transpose << std::endl;

    // 原地转置
    C.transposeInPlace();
    std::cout << "Matrix C after transposeInPlace:\n" << C << std::endl;

    // 重新创建原始矩阵
    C << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;

    // 共轭转置（对于实数矩阵效果和转置一样）
    Matrix3f C_adjoint = C.adjoint();
    std::cout << "Adjoint (Conjugate transpose) of C:\n" << C_adjoint << std::endl;

    // 原地共轭转置
    C.adjointInPlace();
    std::cout << "Matrix C after adjointInPlace:\n" << C << std::endl;
}

// 求和 取模 范数 类型转换
void demo03()
{
    Eigen::Matrix3f C;
    C << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;

    // 求矩阵C所有元素的和
    std::cout << "Sum of elements in C: " << C.sum() << std::endl;

    // norm() 用于计算向量的模（即长度），而 squaredNorm() 返回模的平方。
    Eigen::Vector3f x(1, 2, 3);

    // 计算模
    std::cout << "Norm of x: " << x.norm() << std::endl;

    // 计算模的平方
    std::cout << "Squared norm of x: " << x.squaredNorm() << std::endl;

//    lpNorm<>() 用于计算矩阵或向量的不同类型的范数：
//    lpNorm<1>()：1-范数（绝对值之和）
//    lpNorm<2>()：2-范数（欧几里得范数）
//    lpNorm<Infinity>()：无穷范数（最大绝对值元素）
    Eigen::Vector3f y(1, -2, 3);
    // 1-范数
    std::cout << "1-Norm of y: " << y.lpNorm<1>() << std::endl;
    // 2-范数
    std::cout << "2-Norm of y: " << y.lpNorm<2>() << std::endl;
    // 无穷范数
    std::cout << "Infinity-Norm of x: " << y.lpNorm<Eigen::Infinity>() << std::endl;

    // 类型转换
    Eigen::Matrix3f C1;
    C1 << 1.0f, 2.0f, 3.0f,
            4.0f, 5.0f, 6.0f,
            7.0f, 8.0f, 9.0f;

    // 转换为double类型
    Eigen::Matrix3d C1_double = C1.cast<double>();
    std::cout << "Matrix C1 as double:\n" << C1_double << std::endl;

    Eigen::MatrixXcd C2(2, 2);
    C2 << std::complex<double>(1, 2), std::complex<double>(2, -3),
            std::complex<double>(3, 4), std::complex<double>(4, -5);

    // 获取实部
    std::cout << "Real part of C:\n" << C2.real() << std::endl;

    // 获取虚部
    std::cout << "Imaginary part of C:\n" << C2.imag() << std::endl;

    // 获取共轭矩阵
    std::cout << "Conjugate of C:\n" << C2.conjugate() << std::endl;
}
// 改变大小
void demo04()
{
//    resize()：改变矩阵或向量的大小，删除原有数据。
//    conservativeResize()：改变矩阵或向量的大小，保留原有数据。
    Eigen::Vector3f vec(1, 2, 3);
    vec.resize(5);
    std::cout << "Resized vector: " << vec.transpose() << std::endl;

    // 改变矩阵大小并保留数据
    Eigen::Matrix3f mat;
    mat << 1, 2, 3, 4, 5, 6, 7, 8, 9;
//    mat.conservativeResize(4, 4);
    std::cout << "Conservatively resized matrix:\n" << mat << std::endl;


//    Resized vector: 1 2 3 0 0
//
//    Conservatively resized matrix:
//    1 2 3 0
//    4 5 6 0
//    7 8 9 0
//    0 0 0 0


}

// 获取运行时信息
void demo05()
{
//    data()：返回指向矩阵或向量数据的指针。
//    innerStride()：返回相邻元素之间的内存地址增量。
//    outerStride()：返回相邻行或列之间的内存地址增量。

    Eigen::Matrix3f mat;
    mat << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;

    // 获取数据指针
    std::cout << "Data pointer: " << mat.data() << std::endl;

    // 获取内存步长（inner stride）
    std::cout << "Inner stride: " << mat.innerStride() << std::endl;

    // 获取外部步长（outer stride）
    std::cout << "Outer stride: " << mat.outerStride() << std::endl;
}

