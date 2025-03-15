#include <iostream>
#include <Eigen/Dense>

// Matrix类
// 举证初始化
// 初始化为特殊矩阵

/**
// 基向量
x = Vector3f::UnitX(); // 1 0 0
x = Vector3f::UnitY(); // 0 1 0
x = Vector3f::UnitZ(); // 0 0 1
x = Vector4f::Unit(i);
x.setUnit(i);
x = VectorXf::Unit(size, i);
x.setUnit(size, i);
 */

void demo01()
{
    using namespace Eigen;

    // 3D基向量
    Vector3f x;

    x = Vector3f::UnitX();      // (1,0,0)
    std::cout<<"Unitx:"<<std::endl;
    std::cout<<x.transpose()<<std::endl;

    x = Vector3f::UnitY();  // (0, 1, 0)
    std::cout << "UnitY:\n" << x.transpose() << "\n\n";

    x = Vector3f::UnitZ();  // (0, 0, 1)
    std::cout << "UnitZ:\n" << x.transpose() << "\n\n";

    // 更高维度的单位向量Unit(i)
    // 4D 基向量
    Vector4f v4;
    v4 = Vector4f::Unit(2);  // 第 2 维是 1，其它是 0
    std::cout << "Unit(2) in Vector4f:\n" << v4.transpose() << "\n\n";

    // 5D 动态向量
    VectorXf vx = VectorXf::Unit(5, 3);  // 第 3 维是 1，其它是 0
    std::cout << "Unit(3) in VectorXf (size=5):\n" << vx.transpose() << "\n\n";


    // 用setUnit(i)直接修改已有向量
    VectorXf v(6);
    v.setZero();         // 先初始化为 0
    v.setUnit(4);        // 只把索引 4 设为 1
    std::cout << "After setUnit(4):\n" << v.transpose() << "\n";
}

// 逐元素初始化
// 可以使用<<运算符逐行对于元素进行初始化，也可以使用下标对于特定元素进行初始化
/**
    // 二维固定大小
    Matrix2d A;
    A << 1.0, 0.0,
    0.0, 1.0;
    A(0, 0) = 1.0;
    A(0, 1) = 0.0;
    A(1, 0) = 0.0;
    A(1, 1) = 1.0;
    // 二维动态大小
    int rows = 5, cols = 5;
    MatrixXf m(rows, cols);
    // .finished()成员函数返回初始化后的临时变量
    m << (Matrix3f() << 1, 2, 3, 4, 5, 6, 7, 8, 9).finished(),
            MatrixXf::Zero(3, cols - 3),
            MatrixXf::Zero(rows - 3, 3),
            MatrixXf::Identity(rows - 3, cols - 3);
    // 一维固定大小
    Vector4d b(0, 1, 2, 3);
    b << 0, 1, 2, 3;
    b(0) = 0;
    b(1) = 1;
    b(2) = 2;
    b(3) = 3;
    // 仅适用于向量
    b[0] = 0;
    b[1] = 1;
    b[2] = 2;
    b[3] = 3;
    // 仅适用于向量的前四个元素
    b.x() = 0;
    b.y() = 1;
    b.z() = 2;
    b.w() = 3;
    从内存中映射
    float array[3];
    // 映射，array内容随着矩阵内容变化
    Vector3f::Map(array).fill(10);
    int data[4] = {1, 2, 3, 4};
    // 初始化，data内容被复制到矩阵中
    Matrix2i mat2x2(data);
    // 映射，data内容随着矩阵内容变化
    Matrix2i::Map(data) = 2 * mat2x2;
    MatrixXi::Map(data, 2, 2) += mat2x2;
 */

void demo02() {
    using namespace Eigen;

    // 二维固定大小矩阵
    Matrix2d A;
    A << 1.0, 0.0,
            0.0, 1.0;

    std::cout << "A:\n" << A << std::endl;

    // 使用下标访问单个元素并初始化
    A(0, 0) = 1.0;
    A(0, 1) = 0.0;
    A(1, 0) = 0.0;
    A(1, 1) = 1.0;

    std::cout << "Modified A:\n" << A << std::endl;

}

void demo03()
{
    using namespace Eigen;

    int rows = 5, cols = 5;
    MatrixXf m(rows, cols);

    // 通过逐元素初始化 Matrix3f 和其它 MatrixXf
    m << (Matrix3f() << 1, 2, 3, 4, 5, 6, 7, 8, 9).finished(),
            MatrixXf::Zero(3, cols - 3),
            MatrixXf::Zero(rows - 3, 3),
            MatrixXf::Identity(rows - 3, cols - 3);

    std::cout << "Matrix m:\n" << m << std::endl;

}

// 向量也可以使用<<运算符进行初始化：
void demo04() {
    using namespace Eigen;

    // 一维固定大小向量
    Vector4d b(0, 1, 2, 3);
    std::cout << "Vector b (initialization via constructor):\n" << b.transpose() << std::endl;

    // 逐元素初始化
    b << 0, 1, 2, 3;
    std::cout << "Vector b (after using << operator):\n" << b.transpose() << std::endl;

    // 使用下标初始化
    b(0) = 0;
    b(1) = 1;
    b(2) = 2;
    b(3) = 3;
    std::cout << "Vector b (after using index operator):\n" << b.transpose() << std::endl;

    // 仅适用于向量的前四个元素
    b.x() = 0;
    b.y() = 1;
    b.z() = 2;
    b.w() = 3;
    std::cout << "Vector b (after using x(), y(), z(), w()):\n" << b.transpose() << std::endl;

}

/**
从内存中映射
float array[3];
// 映射，array内容随着矩阵内容变化
Vector3f::Map(array).fill(10);
int data[4] = {1, 2, 3, 4};
// 初始化，data内容被复制到矩阵中
Matrix2i mat2x2(data);
// 映射，data内容随着矩阵内容变化
Matrix2i::Map(data) = 2 * mat2x2;
MatrixXi::Map(data, 2, 2) += mat2x2;
 */

void demo05() {
    using namespace Eigen;

    // 从内存映射一个数组
    float array[3];
    Vector3f::Map(array).fill(10);  // 把数组的内容设置为 10

    std::cout << "Mapped array after fill(10):\n";
    std::cout << array[0] << " " << array[1] << " " << array[2] << std::endl;

    // 使用初始化数据
    int data[4] = {1, 2, 3, 4};
    Matrix2i mat2x2(data);  // 将数组复制到矩阵
    std::cout << "Matrix2i initialized from data:\n" << mat2x2 << std::endl;

    // 映射并修改矩阵内容
    Matrix2i::Map(data) = 2 * mat2x2;
    std::cout << "Mapped and modified data (2 * mat2x2):\n";
    std::cout << data[0] << " " << data[1] << std::endl;
    std::cout << data[2] << " " << data[3] << std::endl;

    // 使用 MatrixXi 映射并修改
    MatrixXi::Map(data, 2, 2) += mat2x2;
    std::cout << "Modified data with MatrixXi:\n";
    std::cout << data[0] << " " << data[1] << std::endl;
    std::cout << data[2] << " " << data[3] << std::endl;

}

