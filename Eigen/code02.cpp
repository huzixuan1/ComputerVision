

#include <iostream>
#include <Eigen/Dense>

int matrixAndArray() {
    Eigen::Matrix3d matA;
    matA << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;

    Eigen::Array3d arrA(1, 2, 3);
    Eigen::Array3d arrB(4, 5, 6);

    // 矩阵运算（线性代数）
    std::cout << "Matrix Multiplication (matA * matA):\n" << matA * matA << "\n\n";

    // 数组运算（逐元素操作）
    std::cout << "Array Element-wise Multiplication (arrA * arrB):\n" << arrA * arrB << "\n\n";

    // 类型转换
    std::cout << "Array to Matrix:\n" << arrA.matrix() * arrB.matrix().transpose() << "\n\n";

    return 0;
}


void func01()
{

    Eigen::Matrix<double,4,4> matrix4x4;
    matrix4x4<<1,2,3,4,
                5,6,7,8,
                9,10,11,12,
                1,2,4,6;

    std::cout<<matrix4x4<<std::endl;


}


void func02()
{
    Eigen::Matrix<float,3,3> matrix1;
    Eigen::Matrix<float,3,3> matrix2;

    matrix1<<1,2,3,
                4,3,1,
                6,3,4;

    matrix1<<1,2,3,
            4,6,1,
            6,3,4;

    std::cout<<"matrix1 + matrix2 = "<<matrix1+matrix2<<std::endl;
    std::cout<<"matrix1 * matrix2 = "<<matrix1*matrix2<<std::endl;
    std::cout<<"matrix1 transport "<<matrix1.transpose()<<std::endl;

}


void func03()
{

    // 求解Ax = b
    Eigen::Matrix2d A;
    Eigen::Vector2d b,x;

    A<<2,-1,
        -1,3;

    b << 1,2;

    // 使用LU分解求解 Ax = b
    x=A.lu().solve(b);
    std::cout<<"Solution:"<<x<<std::endl;

}

void func04()
{

    // 计算特征值
    Eigen::Matrix2d A;
    A << 3, -2,
            4,  1;

    Eigen::EigenSolver<Eigen::Matrix2d> solver(A);
    std::cout << "Eigenvalues:" << solver.eigenvalues() << std::endl;


}

void func05()
{
    Eigen::Array3d arr(1, 2, 3);
    std::cout << "Square root:\n" << arr.sqrt() << "\n";  // 开平方
    std::cout << "Exp:\n" << arr.exp() << "\n";  // 指数
}

