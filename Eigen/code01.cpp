
#include <iostream>
#include "Eigen/Dense"

int matrix01()
{
    Eigen::Matrix3d mat;
    mat<<1,2,3,4,5,6,7,8,9;
    std::cout<<"Matrix:"<<std::endl;
    std::cout<<mat<<std::endl;

    return 0;
}

