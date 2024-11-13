#include <iostream>
#include <stdexcept>
#include <cmath>

class StairCalculationException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Impossible to create stairs with given height and depth.";
    }
};

class StairCalculationResult
{
public:
    int stairsCount;
    int heightOfEachStair;
    int depthOfEachStair;

    StairCalculationResult(int stairsCount, int heightOfEachStair, int depthOfEachStair)
    {
        this->stairsCount = stairsCount;
        this->heightOfEachStair = heightOfEachStair;
        this->depthOfEachStair = depthOfEachStair;
    }
};

StairCalculationResult calculateStairs(int availableHeight, int availableDepth)
{
    const int minHeight = 14;
    const int maxHeight = 19;
    const int minDepth = 25;
    const int maxDepth = 32;

    if (availableHeight < minHeight || availableDepth < minDepth)
    {
        throw StairCalculationException();
    }

    for (int height = maxHeight; height >= minHeight; --height)
    {
        for (int depth = maxDepth; depth >= minDepth; --depth)
        {
            int stepsByHeight = availableHeight / height;
            int stepsByDepth = availableDepth / depth;

            if (stepsByHeight * height <= availableHeight && stepsByDepth * depth <= availableDepth)
            {
                return StairCalculationResult(stepsByHeight, height, depth);
            }
        }
    }

    throw StairCalculationException();
}

int main()
{
    try
    {
        int height, depth;
        std::cout << "Enter the available height (in cm): ";
        std::cin >> height;
        std::cout << "Enter the available depth (in cm): ";
        std::cin >> depth;

        StairCalculationResult stairs = calculateStairs(height, depth);
        std::cout << "Number of stairs: " << stairs.stairsCount << std::endl;
        std::cout << "Height of each stair: " << stairs.heightOfEachStair << std::endl;
        std::cout << "Depth of each stair: " << stairs.depthOfEachStair << std::endl;
    }
    catch (const StairCalculationException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
