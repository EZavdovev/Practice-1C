#include <iostream>
#include<algorithm>
int main()
{
    const int size2 = 32;
    int x, y, m, n, size_x, size_y, size_low_bit_y, max_size;
    int x2[size2], y2[size2]; // представление чисел в виде битов

    std::cin >> x >> y >> m >> n;
    
    size_x = log2(x) + 1; // вычисляем количество бит числа
    size_y = log2(y) + 1;
    
    if (size_x < m || size_y < m || size_y < n) // если количество бит для работы превышает число бит самих чисел, то решения нет
    {
        std::cout << "doesn't have a solution!";
        return 0;
    }
    
    size_low_bit_y = size_y - m; // количество битов y, которые не используются для изменения младших битов x

    max_size = std::max(size_x, size_y);// выбираем какое число имеет больше бит для корректной работы программы
    
    for (int i = 0; i < max_size; i++)
    {
        if (i < m) // меняем m младших бит x на m старших битов y
        {
            if (y & (1 << (i + size_low_bit_y)))
            {
                x2[i] = 1;
            }
            else
            {
                x2[i] = 0;
            }
        }
        else
        {
            if (i < size_x) // дописываем оставшиеся биты x
            {
                if (x & (1 << i))
                {
                    x2[i] = 1;
                }
                else
                {
                    x2[i] = 0;
                }
            }
        }

        if (i < n) // инвертируем n младших битов y
        {
            if (y & (1 << i))
            {
                y2[i] = 0;
            }
            else
            {
                y2[i] = 1;
            }
        }
        else
        {
            if (i < size_y) // дописываем оставшиеся биты y
            {
                if (y & (1 << i))
                {
                    y2[i] = 1;
                }
                else
                {
                    y2[i] = 0;
                }
            }
        } 
    }

    std::cout << "x: " << x << " ";
    for (int i = size_x - 1; i >= 0; i--)
    {
        std::cout << x2[i];
    }
    std::cout << "\n";

    std::cout << "y: " << y << " ";
    for (int i = size_y - 1; i >= 0; i--)
    {
        std::cout << y2[i];
    }
    std::cout << "\n";
    
    return 0;
}