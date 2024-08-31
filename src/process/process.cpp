#include <iostream>
#include <Eigen/Dense>
#include "process.h"

using Eigen::MatrixXd;
using std::cout, std::endl;

void Process::planProcess(){
    cout << "this is planning process" << endl;
    myMap.mapInfo();

    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    cout << m << endl;

    cout << "planning suceess!" << endl;
}