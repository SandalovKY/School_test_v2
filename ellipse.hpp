#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <math.h>

namespace my
{
    struct point
    {
        double m_x{};
        double m_y{};
        point(double x = 0.0, double y = 0.0) : m_x(x), m_y(y) {}
    };

    class ellipse
    {
    private:
    protected:
        double m_square{}; // площадь фигуры
        bool isAvailableSquare {false};
        point m_center; // координаты точки пересечения осей эллипса
        double m_xSize, m_ySize; // полуоси эллипса
        
    public:
        virtual bool isEllipse() { return true; }
        double getSquare();
        ellipse(double x = 0.0, double y = 0.0, double xSize = 0.0, double ySize = 0.0): m_center(x, y), m_xSize(xSize), m_ySize(ySize)
        {
            if (xSize < 0.0)
            {
                throw 'x';
            }
            if (ySize < 0.0)
            {
                throw 'y';
            }
            m_xSize = xSize;
            m_ySize = ySize;
        }
    };
    
}

#endif