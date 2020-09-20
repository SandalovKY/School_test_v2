#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "figures_engine.hpp"
namespace my_engine
{
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

    bool FiguresVector::fillRandomFigures(int size)
    {
        std::srand(std::time(nullptr));
        double x = 0.0, y = 0.0, xSize = 0.0, ySize = 0.0;

        for(int i = 0; i < size; ++i)
        {
            x = fabs(static_cast<double>(rand()) / RAND_MAX);
            y = fabs(static_cast<double>(rand()) / RAND_MAX);
            xSize = fabs(static_cast<double>(rand()) / RAND_MAX);
            ySize = fabs(static_cast<double>(rand()) / RAND_MAX);
            try
            {
                my_vector.push_back(createFigure(rand()%2, x, y, xSize, ySize));
            }
            catch(char err[])
            {
                return false;
            }
        }
        return true;
    }

    bool FiguresVector::sortFiguresVector(void)
    {
        std::sort(my_vector.begin(), my_vector.end(),
        [](const auto& a_ptr, const auto& b_ptr) -> bool
        {
            return a_ptr->getSquare() < b_ptr->getSquare();
        });
        return true;
    }

    void FiguresVector::printFiguresVector(void)
    {
        std::string isCrcl {"circle"};
        std::string isEllps {"ellipse"};
        for (const auto& elem : my_vector)
        {
            if (elem->isEllipse()) std::cout << isEllps;
            else std::cout << isCrcl;
            std::cout << '\t' << elem->getSquare() << std::endl;
        }
        std::cout << std::endl;
    }

    double FiguresVector::summarySquare(type param)
    {
        double sum = 0.0;
        if (param == type::undefined)
        {
            for (const auto& elem : my_vector)
            {
                sum += elem->getSquare();
            }
        }
        else
        {
            for (const auto& elem : my_vector)
            {
                if (elem->isEllipse() == param)
                {
                    sum += elem->getSquare();
                }
            }
        }
        
        return sum;
    }
}