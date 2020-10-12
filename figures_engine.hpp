#ifndef FIGURES_ENGINE
#define FIGURES_ENGINE
#include <memory>
#include <vector>
#include "ellipse.hpp"
#include "circle.hpp"
namespace my_engine
{
    enum type
    {
        circle = 0,
        ellipse,
        undefined
    };
    class FiguresVector
    {
    private:
        std::vector<std::unique_ptr<my::ellipse>> my_vector;
    public:
        FiguresVector() = default;
        bool fillRandomFigures(int size);
        bool sortFiguresVector();
        void printFiguresVector();
        double summarySquare(type param);
    };
    
}
#endif