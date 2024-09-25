#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& x)
{
    for(int i = 0; i < x.size(); i++)
    {
        for(int j = 0; j < x.size() - 1; j++)
        {
            if(x[j] > x[j + 1])
            {
                int tmp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = tmp;
            }
        }
    }
}

void print_vector(std::vector<int> x)
{
    for (size_t i = 0; i < x.size(); i++)
    {
        std::cout << x[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> first_vector { 5, 2, 3, 1, 6, 3, 8 };

    print_vector(first_vector);

    bubble_sort(first_vector);

    print_vector(first_vector);
}
