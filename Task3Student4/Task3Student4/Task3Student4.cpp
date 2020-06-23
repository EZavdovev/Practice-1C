#include <iostream>
#include <cmath>
#include<algorithm>
int main()
{
    const int size2 = 32;
    int x, y, x_save, y_save, m, n, size_x, size_y, size_low_bit_y, max_size;// x_save и y_save нужны для вывода информации
    int x2[size2], y2[size2]; // представление чисел в виде битов

    std::cin >> x >> y >> m >> n;

    x_save = x;
    y_save = y;

    size_x = log2(x) + 1; // вычисляем количество бит числа
    size_y = log2(y) + 1;

    if (size_x < m || size_y < m || size_y < n) // если количество бит для работы превышает число бит самих чисел, то решения нет
    {
        std::cout << "doesn't have a solution!";
        return 0;
    }

    size_low_bit_y = size_y - m; // количество битов y, которые не используются для изменения младших битов x
    
    max_size = std::max(n / 2 + 1, size_x - m); // ищем сколько операций больше для корректной работы программы. либо инвертировать младшие биты y либо дописать оставшиеся биты x.

    for (int i = 0, j = -1; i < size_y + max_size; i++) 
    {
        if (i < size_y) // если не заполнили массив y
        {   
            y2[i] = y % 2;
            if (i >= size_low_bit_y) // если доходим до необходимых старших битов y, то присваиваем их как младшие биты x.
            {
                x2[i - size_low_bit_y] = y % 2;
                x /= 2;
            }
            y /= 2;
        }

        if (i >= size_y) 
        { 
            if (i - size_y < size_x - m) // заполняем оставшиеся биты x без изменений
            {
                x2[i - size_low_bit_y] = x % 2;
                x /= 2;
            }

            if (i - size_y < j + n) // инвертируем младшие биты y
            {
                std::swap(y2[i - size_y], y2[j + n]);
                j--;
            }
        }
    }

    std::cout << "x: " << x_save << " ";
    for (int i = size_x - 1; i >= 0; i--)
    {
        std::cout << x2[i];
    }
    std::cout << "\n";

    std::cout << "y: " << y_save << " ";
    for (int i = size_y - 1; i >= 0; i--)
    {
        std::cout << y2[i];
    }
    std::cout << "\n";

    return 0;
}