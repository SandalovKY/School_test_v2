#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.hpp"

namespace my
{
    class circle : public ellipse
    {
    private:
        /* data */
    public:
        bool isEllipse() override { return false; }
        circle(double x = 0.0, double y = 0.0, double Size = 0.0)
            : ellipse(x, y, Size, Size) {}
    };
}

#endif