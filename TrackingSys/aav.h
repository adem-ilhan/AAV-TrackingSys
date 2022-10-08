#ifndef AAV_H
#define AAV_H

#include<QString>
class AAV
{
public:
    AAV(int id,double x_coor,double y_coor);
    int id;
    double x_coor,y_coor;
    QString status;// = "not impl.";
};

#endif // AAV_H
