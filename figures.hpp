#include <memory>
#include "ellipse.hpp"
#include "circle.hpp"

std::unique_ptr<my::ellipse> createFigure (bool isEllipse, double x = 0.0, double y = 0.0, double xSize = 0.0, double ySize = 0.0);