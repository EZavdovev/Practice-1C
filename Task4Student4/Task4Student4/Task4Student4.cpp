#include <iostream>

double Perimeter(double a)
{
    return 4 * a;
}

double Square(double a)
{
    return pow(a, 2);
}

double Diagonal(double a)
{
    return sqrt(2 * pow(a, 2));
}

int main()
{
    double a;
    std::cin >> a;
    std::cout << "Perimeter: " << Perimeter(a) << "\n";
    std::cout << "Square: " << Square(a) << "\n";
    std::cout << "Diagonal: " << Diagonal(a) << "\n";
    return 0;
}

