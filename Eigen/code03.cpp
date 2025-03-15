
/** 经过上面的eigen初体验以后，下面的才是开始 **/
/**
Matrix<typename Scalar,                                 // [必需] 数据类型
        int RowsAtCompileTime,                           // [必需] 编译时确定的行数，如果不确定可以使用Dynamic指定动态大小
        int ColsAtCompileTime,                           // [必需] 编译时确定的列数，如果不确定可以使用Dynamic指定动态大小
        int Options = 0,                                 // [可选] 位字段，可以使用RowMajor指定逐行保存，或者使用ColMajor指定逐列保存，默认逐列保存
int MaxRowsAtCompileTime = RowsAtCompileTime,    // [可选] 编译时确定的最大行数，用于避免动态内存分配
int MaxColsAtCompileTime = ColsAtCompileTime>    // [可选] 编译时确定的最大列数，用于避免动态内存分配
 **/


/**
* Eigen使用typedef关键字重命名了常用大小的矩阵和数组，后缀f代表float、d代表double、i代表int，
 * 不同数据类型的矩阵在运算中禁止混用，需要显式类型转换，在使用中应尽可能少用动态大小的矩阵和数组，以提高运行速度：
*/

/**
// Matrix类
Matrix<float, Dynamic, Dynamic>     <=>     MatrixXf
        Matrix<double, Dynamic, 1>          <=>     VectorXd
        Matrix<int, 1, Dynamic>             <=>     RowVectorXi
        Matrix<float, 3 , 3>                <=>     Matrix3f
        Matrix<float, 4, 1>                 <=>     Vector4f
// Array类
Array<float, Dynamic, Dynamic>      <=>     ArrayXXf
        Array<double, Dynamic, 1>           <=>     ArrayXd
        Array<int, 1, Dynamic>              <=>     RowArrayXi
        Array<float, 3, 3>                  <=>     Array33f
        Array<float, 4, 1>                  <=>     Array4f

**/

/**
 * Matrix类和Array类之间运算和类型转换的规则
 * **/

/**
 * Array44f a1, a2;
    Matrix4f m1, m2;
    m1 = a1 * a2;                       // 逐元素相乘，运算结果从Array类到Matrix类隐式类型转换
    a1 = m1 * m2;                       // 矩阵相乘，运算结果从Matrix类到Array类隐式类型转换
    a2 = a1 + m1.array();               // Array类和Matrix类的对象在运算中禁止混用，需要显式类型转换
    m2 = a1.matrix() + m1;              // Array类和Matrix类的对象在运算中禁止混用，需要显式类型转换
    ArrayWrapper<Matrix4f> m1a(m1);     // m1a相当于m1.array()，二者参数相同
    MatrixWrapper<Array44f> a1m(a1);    // a1m相当于a1.matrix()，二者参数相同
 */
#include <Eigen/Dense>
#include <iostream>

#include <iostream>
#include <Eigen/Dense>

void demo01() {
    using namespace Eigen;

    // 定义 4x4 的 Array 和 Matrix
    Array44f a1, a2;
    Matrix4f m1, m2;

    // 赋值
    a1.setRandom();
    a2.setRandom();
    m1.setRandom();
    m2.setRandom();

    // 逐元素相乘，Array -> Matrix（隐式转换）
    m1 = (a1 * a2).matrix();

    // 矩阵相乘，Matrix -> Array（隐式转换）
    a1 = (m1 * m2).array();

    // 显式转换，保证 Array 和 Matrix 运算合法
    a2 = a1 + m1.array();  // m1 转换为 Array 进行逐元素运算
    m2 = a1.matrix() + m1;  // a1 转换为 Matrix 进行矩阵运算

    // 使用 ArrayWrapper 和 MatrixWrapper
    ArrayWrapper<Matrix4f> m1a(m1);  // 相当于 m1.array()
    MatrixWrapper<Array44f> a1m(a1); // 相当于 a1.matrix()

    // 输出结果
    std::cout << "m1:\n" << m1 << "\n";
    std::cout << "a1:\n" << a1 << "\n";
    std::cout << "m1a (ArrayWrapper):\n" << m1a << "\n";
    std::cout << "a1m (MatrixWrapper):\n" << a1m << "\n";

}

/**
 * Matrix类和Array类的初始化方式，建议在定义后对变量进行初始化；
    固定大小——大小确定，可不加行列数：
    typedef {Matrix3f | Array33f} FixedXD;
      FixedXD x;
      // 创建对应类的对象（作为等号右值）
      x = FixedXD::Identity();      生成单位矩阵
      x = FixedXD::Zero();
      x = FixedXD::Ones();
      x = FixedXD::Constant(value);
      x = FixedXD::Random();
      x = FixedXD::LinSpaced(size, low, high);      生成在指定范围内均匀分布的数值
      // 调用对应成员函数
      x.setIdentity();
      x.setZero();
      x.setOnes();
      x.setConstant(value);
      x.setRandom();
      x.setLinSpaced(size, low, high);
 */


#include <iostream>
#include <Eigen/Dense>

int demo02() {
    using namespace Eigen;

    typedef Matrix3f FixedXD;
    FixedXD x;

    // 作为等号右值（创建新对象）
    x = FixedXD::Identity();      // ✅ 生成单位矩阵（仅 Matrix 支持）
    std::cout << "Identity Matrix:\n" << x << "\n\n";

    x = FixedXD::Zero();          // ✅ 生成全 0 矩阵
    std::cout << "Zero Matrix:\n" << x << "\n\n";

    x = FixedXD::Ones();          // ✅ 生成全 1 矩阵
    std::cout << "Ones Matrix:\n" << x << "\n\n";

    x = FixedXD::Constant(5.0f);  // ✅ 生成所有元素都为 5 的矩阵
    std::cout << "Constant Matrix:\n" << x << "\n\n";

    x = FixedXD::Random();        // ✅ 生成随机矩阵（值在 -1~1 之间）
    std::cout << "Random Matrix:\n" << x << "\n\n";

    // LinSpaced() 仅适用于 Vector（不能用于 Matrix）
    VectorXf v = VectorXf::LinSpaced(3, 1.0f, 3.0f);
    std::cout << "LinSpaced Vector:\n" << v << "\n\n";

    // 调用成员函数
    x.setIdentity();              // ✅ 设置为单位矩阵
    std::cout << "Set Identity:\n" << x << "\n\n";

    x.setZero();                  // ✅ 设置为全 0 矩阵
    x.setOnes();                  // ✅ 设置为全 1 矩阵
    x.setConstant(10.0f);          // ✅ 设置所有元素为 10
    x.setRandom();                 // ✅ 设置为随机矩阵

    return 0;
}

#include <iostream>
#include <Eigen/Dense>

int demo03() {
    using namespace Eigen;

    typedef Array33f FixedXD;
    FixedXD x;

    // 作为等号右值（创建新对象）
    // x = FixedXD::Identity();  // ❌ 错误！Array 没有 Identity()

    x = FixedXD::Zero();          // ✅ 生成全 0 数组
    std::cout << "Zero Array:\n" << x << "\n\n";

    x = FixedXD::Ones();          // ✅ 生成全 1 数组
    std::cout << "Ones Array:\n" << x << "\n\n";

    x = FixedXD::Constant(5.0f);  // ✅ 生成所有元素都为 5 的数组
    std::cout << "Constant Array:\n" << x << "\n\n";

    x = FixedXD::Random();        // ✅ 生成随机数组（值在 -1~1 之间）
    std::cout << "Random Array:\n" << x << "\n\n";

    // x = FixedXD::LinSpaced(3, 1.0f, 3.0f);  // ❌ 错误！Array 没有 LinSpaced()

    // 调用成员函数
    // x.setIdentity();  // ❌ 错误！Array 没有 setIdentity()
    x.setZero();        // ✅ 设置为全 0 数组
    x.setOnes();        // ✅ 设置为全 1 数组
    x.setConstant(10.0f); // ✅ 设置所有元素为 10
    x.setRandom();        // ✅ 设置为随机数组

    return 0;
}

/**
 *   typedef {MatrixXf | ArrayXXf} Dynamic2D;
      Dynamic2D x;
      // 创建对应类的对象（作为等号右值）
      x = Dynamic2D::Identity(rows, cols);
      x = Dynamic2D::Zero(rows, cols);
      x = Dynamic2D::Ones(rows, cols);
      x = Dynamic2D::Constant(rows, cols, value);
      x = Dynamic2D::Random(rows, cols);
      // 调用对应成员函数
      x.setIdentity(rows, cols);
      x.setZero(rows, cols);
      x.setOnes(rows, cols);
      x.setConstant(rows, cols, value);
      x.setRandom(rows, cols);
 *
 *
 * */

// 上面说的是不需要指定维度的方式定义矩阵和数组
#include <Eigen/Dense>
#include <iostream>

using namespace std;

void demo04()
{
    typedef Eigen::MatrixXf Dynamic2D;
    Dynamic2D x;
    int rows = 3;
    int cols = 3;

    // 作为等号右值（创建新对象）
    x = Dynamic2D ::Identity(rows,cols);    // 生成单位矩阵
    std::cout<<"Identify Matrix:"<<std::endl;
    std::cout<<x<<std::endl;

    x = Dynamic2D::Zero(rows,cols);  // 生成全是0的矩阵
    std::cout<<"Zero Matrix:"<<std::endl;
    std::cout<<x<<std::endl;

    x = Dynamic2D::Ones(rows,cols);  // 生成全1矩阵
    std::cout<<"One Matrix:"<<std::endl;
    std::cout<<x<<std::endl;

    x = Dynamic2D::Constant(rows,cols,5.0f);     // 生成所有元素都是5的矩阵
    std::cout<<"Constant matrix:"<<std::endl;
    std::cout<<x<<std::endl;

    x = Dynamic2D::Random(rows,cols);        // 生成随机矩阵
    std::cout<<"Random Matrix:"<<std::endl;
    std::cout<<x<<std::endl;


    // 调用成员函数
    x.setIdentity(rows,cols);   // 重现设置为单位矩阵
    x.setZero(rows,cols);       // 重新设置成为全为0的矩阵
    x.setOnes(rows,cols);       // 重现设置为全1的矩阵
    x.setConstant(rows,cols,10.0f);     // 重现设置所有元素为10
    x.setRandom(rows,cols);     // 重现设置为随机矩阵

}

// 动态ArrayXXf示例
void demo05()
{
    typedef Eigen::ArrayXXf Dynamic2D;  // 定义动态数组类型
    Dynamic2D x;

    int rows = 3,cols = 3;

    // 作为等号右值（创建新对象）
    // x = Dynamic2D::Identity(rows,cols);  // ArraryXXf不支持

    x = Dynamic2D::Zero(rows,cols);  // 生成全是0的数组
    std::cout<<"Zero Matrix:"<<std::endl;
    std::cout<<x<<std::endl;

    x = Dynamic2D::Ones(rows,cols);  // 生成全1数组
    std::cout<<"One Matrix:"<<std::endl;
    std::cout<<x<<std::endl;

    x = Dynamic2D::Constant(rows,cols,5.0f);     // 生成所有元素都是5的数组
    std::cout<<"Constant matrix:"<<std::endl;
    std::cout<<x<<std::endl;

    x = Dynamic2D::Random(rows,cols);        // 生成随机数组
    std::cout<<"Random Matrix:"<<std::endl;
    std::cout<<x<<std::endl;

    // 调用成员函数
//    x.setIdentity(rows,cols);   // 重现设置为单位数组 数组不支持
    x.setZero(rows,cols);       // 重新设置成为全为0的数组
    x.setOnes(rows,cols);       // 重现设置为全1的数组
    x.setConstant(rows,cols,10.0f);     // 重现设置所有元素为10
    x.setRandom(rows,cols);     // 重现设置为随机数组

}

/**
    typedef {VectorXf | ArrayXf} Dynamic1D;
    Dynamic1D x;
    // 创建对应类的对象（作为等号右值）
    x = Dynamic1D::Zero(size);
    x = Dynamic1D::Ones(size);
    x = Dynamic1D::Constant(size, value);
    x = Dynamic1D::Random(size);
    x = Dynamic1D::LinSpaced(size, low, high);
    // 调用对应成员函数
    x.setZero(size);
    x.setOnes(size);
    x.setConstant(size, value);
    x.setRandom(size);
    x.setLinSpaced(size, low, high);
 */

// vectorXf(动态向量)示例
void demo06()
{
    int size = 5;   // 向量的大小
    Eigen::VectorXf vec;    // 声明动态向量

    // 赋值操作（创造新的向量）
    vec = Eigen::VectorXf ::Zero(size); // 全0向量
    std::cout<<"Eigen::VectorXf::Zero:"<<std::endl;
    std::cout<<vec.transpose()<<std::endl;  // transpose表示转置

    vec = Eigen::VectorXf::Ones(size);        // 全 1
    std::cout << "VectorXf::Ones:\n" << vec.transpose() << "\n\n";

    vec = Eigen::VectorXf::Constant(size, 3); // 全 3
    std::cout << "VectorXf::Constant(3):\n" << vec.transpose() << "\n\n";

    vec = Eigen::VectorXf::Random(size);      // 生成随机数
    std::cout << "VectorXf::Random:\n" << vec.transpose() << "\n\n";

    vec = Eigen::VectorXf::LinSpaced(size, 1, 5);  // 生成 1 到 5 均匀分布
    std::cout << "VectorXf::LinSpaced(1,5):\n" << vec.transpose() << "\n\n";

    // 调用成员函数修改已有向量
    vec.setZero(size);
    std::cout << "setZero:\n" << vec.transpose() << "\n\n";

    vec.setOnes(size);
    std::cout << "setOnes:\n" << vec.transpose() << "\n\n";

    vec.setConstant(size, 7);
    std::cout << "setConstant(7):\n" << vec.transpose() << "\n\n";

    vec.setRandom(size);
    std::cout << "setRandom:\n" << vec.transpose() << "\n\n";

    vec.setLinSpaced(size, 10, 50);
    std::cout << "setLinSpaced(10,50):\n" << vec.transpose() << "\n\n";
    
}

