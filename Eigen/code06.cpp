#include <iostream>
#include <Eigen/Dense>

// 分块

/*
// 向量
// Eigen                           // MATLAB
    x.head(n)                          // x(1:n)
    x.head<n>()                        // x(1:n)
    x.tail(n)                          // x(end - n + 1: end)
    x.tail<n>()                        // x(end - n + 1: end)
    x.segment(i, n)                    // x(i+1 : i+n)
    x.segment<n>(i)                    // x(i+1 : i+n)


// 矩阵
// Eigen                           // MATLAB
    P.block(i, j, rows, cols)          // P(i+1 : i+rows, j+1 : j+cols)
    P.block<rows, cols>(i, j)          // P(i+1 : i+rows, j+1 : j+cols)
    P.row(i)                           // P(i+1, :)
    P.col(j)                           // P(:, j+1)
    P.leftCols<cols>()                 // P(:, 1:cols)
    P.leftCols(cols)                   // P(:, 1:cols)
    P.middleCols<cols>(j)              // P(:, j+1:j+cols)
    P.middleCols(j, cols)              // P(:, j+1:j+cols)
    P.rightCols<cols>()                // P(:, end-cols+1:end)
    P.rightCols(cols)                  // P(:, end-cols+1:end)
    P.topRows<rows>()                  // P(1:rows, :)
    P.topRows(rows)                    // P(1:rows, :)
    P.middleRows<rows>(i)              // P(i+1:i+rows, :)
    P.middleRows(i, rows)              // P(i+1:i+rows, :)
    P.bottomRows<rows>()               // P(end-rows+1:end, :)
    P.bottomRows(rows)                 // P(end-rows+1:end, :)
    P.topLeftCorner(rows, cols)        // P(1:rows, 1:cols)
    P.topRightCorner(rows, cols)       // P(1:rows, end-cols+1:end)
    P.bottomLeftCorner(rows, cols)     // P(end-rows+1:end, 1:cols)
    P.bottomRightCorner(rows, cols)    // P(end-rows+1:end, end-cols+1:end)
    P.topLeftCorner<rows,cols>()       // P(1:rows, 1:cols)
    P.topRightCorner<rows,cols>()      // P(1:rows, end-cols+1:end)
    P.bottomLeftCorner<rows,cols>()    // P(end-rows+1:end, 1:cols)
    P.bottomRightCorner<rows,cols>()   // P(end-rows+1:end, end-cols+1:end)
*/

// 向量部分
void demo01()
{
    using namespace Eigen;
    // 向量
    Eigen::VectorXf x(10);
    x.setLinSpaced(10,1,10);    // x = 1 2 3 4 5 6 7 8 9 10

    std::cout<<"x.head(3):"<<std::endl;
    std::cout<<x.head(3).transpose()<<std::endl;
    // 结果: [1 2 3]

    std::cout << "x.tail(3): \n" << x.tail(3).transpose() << std::endl;
    // 结果: [8 9 10]

    std::cout << "x.segment(2, 4): \n" << x.segment(2, 4).transpose() << std::endl;
    // 结果: [3 4 5 6]

}

// 矩阵部分
void demo02()
{
    using namespace Eigen;

    Eigen::MatrixXf P(5,5);

    P.setRandom();  // 生成随机5x5矩阵

    std::cout << "P.block(1,1,3,3): \n" << P.block(1,1,3,3) << std::endl;
    // 取 P(2:4,2:4) 3x3 子矩阵

    std::cout << "P.col(2): \n" << P.col(2) << std::endl;
    // 取第 3 列

    std::cout << "P.topLeftCorner(2,2): \n" << P.topLeftCorner(2,2) << std::endl;
    // 取 2x2 左上角子矩阵

    // 其他的提取使用方法类似

}
