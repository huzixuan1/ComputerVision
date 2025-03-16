#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
using namespace Eigen;

// 四元数

// 必须使用单位四元数表示旋转
/*
    // 直接初始化，注意参数顺序为(w，x，y，z)
    Quaterniond q = Quaterniond(q_w, q_x, q_y, q_z);
    // 可以把AngleAxis赋值给四元数，反之亦然
    Quaterniond q = Quaterniond(rotation_vector);
    // 可以把旋转矩阵赋值给四元数
    Quaterniond q = Quaterniond(rotation_matrix);
    // 向量v1和向量v2之间的旋转，将向量v1旋转到与向量v2同向，对于两个向量的模长没有要求
    Quaterniond q = Quaterniond::FromTwoVectors(v1, v2);
    // 访问四元数中各元素
    q.x()
    q.y()
    q.z()
    q.w()
    q.coeffs()              // 注意coeffs的顺序是(x, y, z, w)，w为实部，前三者为虚部，这也是Eigen中四元数的存储顺序
    q.normalize()           // 归一化四元数，直接对原四元数操作，无返回值，不能作为等号右值
    q.normalized()          // 归一化四元数，原四元数不变，返回拷贝构造值，可以作为等号右值
    q.matrix()              // 四元数转旋转矩阵
    q.toRotationMatrix()    // 四元数转旋转矩阵
    // 取共轭和取逆仅在单位四元数情况下是等价的，相当于对旋转取逆
    q.conjugate()           // 取共轭，q * q^{*} = \|q\|^{2}
    q.inverse()             // 取逆，q * q^{-1} = 1
    // 使用四元数旋转一个向量，使用重载的乘法即可
    v_rotated = q * v;      // 注意数学上是qvq^{-1}
    欧氏变换
    示例：

    // 欧氏变换矩阵使用Isometry
    Isometry3d T = Isometry3d::Identity();  // 虽然称为3d，实质上是4*4的矩阵
    T.rotate(rotation_vector);              // 按照rotation_vector进行旋转
    T.pretranslate(Vector3d(1, 2, 3))       // 把平移向量设成(1, 2, 3)
    T.matrix()                              // 欧氏变换矩阵
    // 用欧氏变换矩阵进行坐标变换
    Vector3d v_transformed = T * v;         // 相当于R * v + t
 */

/*
四元数的初始化
        四元数在计算机图形学中广泛用于表示旋转，相较于欧拉角，
        它能避免万向节死锁（gimbal lock），并且提供更稳定的插值。

初始化四元数：
    // 直接初始化，注意参数顺序为(w，x，y，z)
    Quaterniond q = Quaterniond(q_w, q_x, q_y, q_z);

这里，Quaterniond 是 Eigen 库中的四元数类，
 它的构造函数允许通过四个参数来初始化四元数，其中：
    q_w：实部
    q_x、q_y、q_z：虚部
顺序为 (w, x, y, z)，这是四元数的标准表示方法，w 是实部，x、y、z 是虚部。

通过旋转向量初始化四元数
    Quaterniond q = Quaterniond(rotation_vector);

这个构造函数通过一个 AngleAxisd 旋转向量（即旋转轴和旋转角度）来初始化四元数。
 它将旋转向量转换为对应的四元数。
 旋转向量通常是通过单位向量表示旋转轴，乘以旋转角度来获得。

通过旋转矩阵初始化四元数
    Quaterniond q = Quaterniond(rotation_matrix);

四元数也可以通过一个旋转矩阵来初始化。在这里，rotation_matrix是一个 3x3 的旋转矩阵，
表示绕某个轴的旋转。这个构造函数将旋转矩阵转换为四元数。

通过两个向量计算旋转：
    Quaterniond q = Quaterniond::FromTwoVectors(v1, v2);
如果你有两个向量 v1 和 v2，并且希望计算将 v1 旋转到 v2 所需要的旋转（无关长度），
可以使用 FromTwoVectors 方法。


这个方法计算的是一个四元数，表示从 v1 到 v2 的旋转。
    q.x();    // 获取四元数的 x 分量
    q.y();    // 获取四元数的 y 分量
    q.z();    // 获取四元数的 z 分量
    q.w();    // 获取四元数的 w 分量
    q.coeffs(); // 获取四元数的系数 (x, y, z, w)，注意顺序

四元数的归一化：
    q.normalize();    // 归一化四元数，直接对原四元数操作
    q.normalized();   // 归一化四元数，原四元数不变，返回一个新的四元数

q.normalize()：直接在原四元数上进行归一化操作。归一化四元数的模长为 1，通常用于保持旋转的单位性质。
q.normalized()：返回一个归一化后的四元数，原始的四元数不变。

四元数与旋转矩阵的转换：
    q.matrix();         // 四元数转旋转矩阵
    q.toRotationMatrix();  // 四元数转旋转矩阵

这两种方法都可以将四元数转换为 3x3 的旋转矩阵。可以选择其中一个，通常 toRotationMatrix() 是推荐使用的，因为它更常见和直观。

*/

void demo01() {
    // 1. 四元数的使用
    // 初始化四元数（w, x, y, z）
    double q_w = 0.7071, q_x = 0.0, q_y = 0.7071, q_z = 0.0;
    Eigen::Quaterniond q(q_w, q_x, q_y, q_z);  // 初始化四元数

    std::cout << "Original Quaternion:" << std::endl;
    std::cout << q.coeffs() << std::endl;  // 输出四元数系数 (x, y, z, w)

    // 归一化四元数
    q.normalize();
    std::cout << "\nNormalized Quaternion:" << std::endl;
    std::cout << q.coeffs() << std::endl;  // 输出归一化后的四元数

    // 使用四元数旋转一个向量
    Eigen::Vector3d v(1, 0, 0);  // 初始向量
    Eigen::Vector3d v_rotated = q * v;  // 使用四元数旋转该向量
    std::cout << "\nRotated Vector:" << std::endl;
    std::cout << v_rotated.transpose() << std::endl;  // 输出旋转后的向量

    // 计算四元数的共轭和逆
    Eigen::Quaterniond q_conjugate = q.conjugate();  // 获取共轭四元数
    Eigen::Quaterniond q_inverse = q.inverse();  // 获取逆四元数
    std::cout << "\nQuaternion Conjugate:" << std::endl;
    std::cout << q_conjugate.coeffs() << std::endl;
    std::cout << "\nQuaternion Inverse:" << std::endl;
    std::cout << q_inverse.coeffs() << std::endl;

    // 2. 欧氏变换的使用
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();  // 创建单位欧氏变换矩阵（4x4）

    // 创建旋转向量（旋转角度 90°，绕 z 轴）
    Eigen::Vector3d rotation_vector(0, 0, M_PI / 2);  // 旋转向量
    T.rotate(Eigen::AngleAxisd(rotation_vector.norm(), rotation_vector.normalized()));  // 旋转变换

    // 平移变换
    T.pretranslate(Eigen::Vector3d(1, 2, 3));  // 平移向量 (1, 2, 3)

    // 获取变换矩阵
    std::cout << "\nTransformation Matrix (Isometry):" << std::endl;
    std::cout << T.matrix() << std::endl;

    // 使用欧氏变换矩阵进行坐标变换
    Eigen::Vector3d v_transformed = T * v;  // 使用变换矩阵旋转和平移向量 v
    std::cout << "\nTransformed Vector:" << std::endl;
    std::cout << v_transformed.transpose() << std::endl;
}

/*
    Original Quaternion:
    0.7071 0 0.7071 0

    Normalized Quaternion:
    0.7071 0 0.7071 0

    Rotated Vector:
    0.7071 0 0.7071

    Quaternion Conjugate:
    0.7071 0 -0.7071 0

    Quaternion Inverse:
    0.7071 0 -0.7071 0

    Transformation Matrix (Isometry):
    1 0 0 1
    0 0 -1 2
    0 1 0 3
    0 0 0 1

    Transformed Vector:
    1 3 4
*/

/*
位姿相关运算
        旋转矩阵归一化
四元数法：

    通过将旋转矩阵转换为四元数，将四元数归一化后再转回旋转矩阵。

    Matrix3f R;
    Quaternionf q(R);
    R = q.normalized().toRotationMatrix();
    SVD分解法：

    Matrix3f R;
    JacobiSVD<MatrixXf> svd(R, ComputeFullU | ComputeFullV);
    R = svd.matrixU() * svd.matrixV().transpose();
    流形投影法：

    Matrix3f R;
    Matrix3f H = R * R.transpose();
    Matrix3f L = H.llt().matrixL();
    R = L.inverse() * R;
    位姿插值
    double t1, t2, t;
    Quaterniond quat1, quat2, quat;
    Vector3d trans1, trans2, trans;
    assert(t1 <= t && t <= t2);
    // 当t1和t2过于接近时，选择与当前时刻最近的位姿作为插值结果即可
    if (t2 - t1 <= std::numeric_limits<double>::epsilon()) {
    quat = ((t1 + t2) > 2 * t) ? quat1 : quat2;
    trans = ((t1 + t2) > 2 * t) ? trans1 : trans2;
    }
    // 这里可以看出当t1和t2过于接近时会引起数值误差
    double ratio = (t - t1) / (t2 - t1);
    // 旋转部分位姿使用球面线性插值（Spherical Linear Interpolation，SLERP）
    Quaterniond quat = quat1.slerp(ratio, quat2);
    // 平移部分位姿使用线性插值
    Vector3d trans = trans1 + ratio * (trans2 - trans1);
*/


void demo02()
{

    // 假设我们已经有一个旋转矩阵 R
    Matrix3f R;
    R << 0.36, 0.48, -0.8,
            -0.8, 0.6, 0,
            0.48, 0.64, 0.6;

    // 通过旋转矩阵构造四元数
    Quaternionf q(R);

    // 归一化四元数
    q = q.normalized();

    // 将归一化的四元数转换回旋转矩阵
    R = q.toRotationMatrix();

    std::cout << "Normalized Rotation Matrix: \n" << R << std::endl;


}

/*
SVD分解法（奇异值分解）
SVD（Singular Value Decomposition）是一种常用的矩阵分解方法。
对于旋转矩阵 R，通过 SVD 分解可以得到一个正交矩阵（用于修正矩阵中的小误差）。

方法 2：SVD 分解
计算矩阵 R 的 SVD 分解。
使用 U 和 V 矩阵重新构建旋转矩阵
 */

#include <Eigen/Dense>
#include <Eigen/SVD>
#include <iostream>

using namespace Eigen;

void demo03() {
    // 假设我们已经有一个旋转矩阵 R
    Matrix3f R;
    R << 0.36, 0.48, -0.8,
            -0.8, 0.6, 0,
            0.48, 0.64, 0.6;

    // 使用 JacobiSVD 分解
    JacobiSVD<Matrix3f> svd(R, ComputeFullU | ComputeFullV);

    // 重新构建旋转矩阵
    R = svd.matrixU() * svd.matrixV().transpose();

    std::cout << "Rotation Matrix after SVD: \n" << R << std::endl;
}

/*
 流形投影法（Manifold Projection）
流形投影方法是将旋转矩阵 R 映射回旋转群 SO(3) 上的一个合法矩阵。通过这种方式，可以修正旋转矩阵的数值误差。

方法 3：流形投影
计算旋转矩阵 R 的乘积 R * R^T，得到矩阵 H。
对 H 进行 Cholesky 分解，得到矩阵 L。
使用 L.inverse() * R 重新修正旋转矩阵
 */

#include <Eigen/Dense>
#include <Eigen/LU>
#include <iostream>

using namespace Eigen;

void demo04() {
    // 假设我们已经有一个旋转矩阵 R
    Matrix3f R;
    R << 0.36, 0.48, -0.8,
            -0.8, 0.6, 0,
            0.48, 0.64, 0.6;

    // 计算 H = R * R^T
    Matrix3f H = R * R.transpose();

    // 进行 Cholesky 分解，得到 L
    Matrix3f L = H.llt().matrixL();

    // 使用 L 修正旋转矩阵
    R = L.inverse() * R;

    std::cout << "Rotation Matrix after Manifold Projection: \n" << R << std::endl;
}

/*
位姿插值（Pose Interpolation）
在机器人学和计算机视觉中，位姿插值常用于平滑的运动轨迹生成。常见的插值方法有**球面线性插值（SLERP）**用于旋转部分，线性插值用于平移部分。

方法：位姿插值
        球面线性插值（SLERP）：用于旋转部分。
线性插值：用于平移部分

 */

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>
#include <limits>

using namespace Eigen;
void demo05() {
    // 定义两个位姿（旋转和位移）
    Quaterniond quat1(1, 0, 0, 0);  // 初始四元数
    Quaterniond quat2(0, 1, 0, 0);  // 目标四元数
    Vector3d trans1(0, 0, 0);       // 初始平移
    Vector3d trans2(1, 1, 1);       // 目标平移

    double t1 = 0.0, t2 = 1.0, t = 0.5;  // 插值时间段

    assert(t1 <= t && t <= t2);

    Quaterniond quat;
    Vector3d trans;

    // 如果 t1 和 t2 过于接近，则选择与当前时刻最近的位姿
    if (t2 - t1 <= std::numeric_limits<double>::epsilon()) {
        quat = ((t1 + t2) > 2 * t) ? quat1 : quat2;
        trans = ((t1 + t2) > 2 * t) ? trans1 : trans2;
    } else {
        // 旋转部分使用球面线性插值（SLERP）
        double ratio = (t - t1) / (t2 - t1);
        quat = quat1.slerp(ratio, quat2);

        // 平移部分使用线性插值
        trans = trans1 + ratio * (trans2 - trans1);
    }

    std::cout << "Interpolated Quaternion: \n" << quat.coeffs().transpose() << std::endl;
    std::cout << "Interpolated Translation: \n" << trans.transpose() << std::endl;

}

