#include "sculptor.h"
#include "sculptor.cpp"
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    Sculptor area1(20,20,20);
    area1.setColor(0,0,1.0,1);
    area1.putBox(0,10,0,10,0,10);
    area1.writeOFF("cubao.OFF");

    Sculptor area2(20,20,20);
    area2.setColor(0,0,1.0,1);
    area2.putSphere(6,6,6,6);
    area2.writeOFF("bolao.OFF");

    Sculptor area3(20,20,20);
    area3.setColor(0,0,1.0,1);
    area3.putEllipsoid(6,6,6,2,3,4);
    area3.writeOFF("elipizaoo.OFF");
    return 0;
}