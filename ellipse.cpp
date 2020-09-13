#include "ellipse.hpp"

namespace my
{
    double ellipse::getSquare()
    {
        if (isAvailableSquare) return m_square;

        m_square = M_PI * m_xSize * m_ySize;
        isAvailableSquare = true;
        return m_square;
    }
}