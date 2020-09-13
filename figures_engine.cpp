#include "figures.hpp"

std::unique_ptr<my::ellipse> createFigure (bool isEllipse, double x, double y, double xSize, double ySize)
{
    if (isEllipse)
    {
        return std::unique_ptr<my::ellipse>(new my::ellipse(x, y, xSize, ySize));
    }
    else
    {
        return std::unique_ptr<my::ellipse>(new my::circle(x, y, xSize));
    }
}