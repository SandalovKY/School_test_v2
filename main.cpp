#include <iostream>
#include "figures_engine.hpp"
#define DEFAULT_SIZE 10

int main(int argc, char* argv[])
{
    using type = my_engine::type;
    int size = 0;
    size = (argc == 1) ? DEFAULT_SIZE : atoi(argv[1]);
    my_engine::FiguresVector myVec;
    myVec.fillRandomFigures(size);
    myVec.printFiguresVector();
    myVec.sortFiguresVector();
    myVec.printFiguresVector();
    std::cout << "total sum square: " << myVec.summarySquare(type::undefined)
        << "\tcircle sum square: " << myVec.summarySquare(type::circle)
        << "\tellipse sum square: " << myVec.summarySquare(type::ellipse) << std::endl;
    return 0;
}