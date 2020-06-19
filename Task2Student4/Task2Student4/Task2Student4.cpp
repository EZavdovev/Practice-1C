#include <iostream>

double func(double d, double k, double x) // уравнение линии для получения значения y
{
    return (d * x + k);
}

int main()
{
    double a, b, c, d, k, dis, x1, x2, y1, y2;
    
    std::cout << " enter the coefficients of the equations in order y = ax^2 + bx + c y = dx + k\n";
    std::cin >> a >> b >> c >> d >> k;
    dis = pow(b - d, 2) - 4 * a * (c - k); // вычисляем дискриминант
    if (dis < 0)
    {
        std::cout << "there is no intersection";
        return 0;
    }

    if (dis == 0)
    {
        std::cout << "one intersection point\n";
        x1 = (d - b) / (2 * a);
        y1 = func(d, k, x1);
        std::cout << "x: " << x1 << "\n";
        std::cout << "y: " << y1 << "\n";
        return 0;
    }

    std::cout << "two intersection point\n";
    x1 = ((d - b) - sqrt(dis))/ (2 * a);
    x2 = ((d - b) + sqrt(dis)) / (2 * a);
    y1 = func(d, k, x1);
    y2 = func(d, k, x2);
    std::cout << "x1: " << x1 << "\n";
    std::cout << "y1: " << y1 << "\n";
    std::cout << "\n";
    std::cout << "x2: " << x2 << "\n";
    std::cout << "y2: " << y2 << "\n";
    
    return 0;
}


