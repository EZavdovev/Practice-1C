#include <iostream>
#include<vector>
#include<ctime>

int main()
{
    srand(time(NULL));
    const int n = 6, m = 8;
    double C[n][m];
    std::vector<double> A;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            C[i][j] = ((double)rand() / (double)RAND_MAX) * 100 - 50; // генерирует числа от -50 до 50
            if (C[i][j] > 0) A.push_back(C[i][j]);
        }

    std::cout << "Matrix C:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << C[i][j] << " ";
        std::cout << "\n";
    }

    if (A.empty())
    {
        std::cout << "Matrix C hasn't positive numbers";
        return 0;
    }

    for (int i = 0; i < A.size() - 1; i++)
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] > A[j])
            {
                double tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }

    std::cout << "vector A:\n";
    for (int i = 0; i < A.size(); i++)
        std::cout << A[i] << " ";
    return 0;
}


