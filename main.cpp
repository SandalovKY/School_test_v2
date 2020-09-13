#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <algorithm>
#include "ellipse.hpp"
#include "circle.hpp"
#include "figures.hpp"

int main(int argc, char* argv[])
{
    if (argc == 1) return 1;

    std::srand(std::time(nullptr));
    std::vector<std::unique_ptr<my::ellipse>> myVector{};
    int count = atoi(argv[1]);
    double sum{}, cirleSum{};
    double x, y, xSize, ySize;

    for(int i = 0; i < count; ++i)
    {
        x = fabs(static_cast<double>(rand()) / RAND_MAX);
        y = fabs(static_cast<double>(rand()) / RAND_MAX);
        xSize = fabs(static_cast<double>(rand()) / RAND_MAX);
        ySize = fabs(static_cast<double>(rand()) / RAND_MAX);
        try
        {
            myVector.push_back(createFigure(rand()%2, x, y, xSize, ySize));
        }
        catch(char err)
        {
            switch (err)
            {
            case 'x':
                std::cout << "false x size\n";
                break;
            case 'y':
                std::cout << "false y size\n";
                break;
            default:
                break;
            }
        }
    }
    for (const auto& elem : myVector)
    {
        std::cout << elem->isEllipse() << '\t' << elem->getSquare() << std::endl;
        sum += elem->getSquare();
        if (!elem->isEllipse())
        {
            cirleSum += elem->getSquare();
        }
    }

    std::sort(myVector.begin(), myVector.end(),
        [](const auto& a_ptr, const auto& b_ptr) -> bool
    {
        return a_ptr->getSquare() < b_ptr->getSquare();
    });

    std::cout << std::endl;
    for (const auto& elem : myVector)
    {
        std::cout << elem->isEllipse() << '\t' << elem->getSquare() << std::endl;
    }

    std::cout << "SUM = " << sum << std::endl;
    std::cout << "CIRLE SUM = " << cirleSum << std::endl;
    return 0;
}