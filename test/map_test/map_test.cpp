#include <iostream>
#include "pnc_map.h"
using std::cout, std::endl;


// 测试文件要编成一个单独的可执行文件
void mapTest(){
    cout << "this is pnc_map test" << endl;
    PNC_Map myMap;
    myMap.mapInfo();
}

int main(){     // 程序入口
    mapTest();
    return 0;
}

