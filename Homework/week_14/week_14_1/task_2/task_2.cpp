#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int M, N;
    std::cout << "¬ведите M: ";
    std::cin >> M;

    std::cout << "¬ведите N: ";
    std::cin >> N;

    std::vector<int> A(M);
    std::vector<int> B(N);
    std::vector<int> result;

    for (int i = 0; i < M; ++i) {
        A[i] = rand() % 10;
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < N; ++i) {
        B[i] = rand() % 15;
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < M; ++i) {
        if (std::find(B.begin(), B.end(), A[i]) == B.end()) {
            if (std::find(result.begin(), result.end(), A[i]) == result.end()) {
                result.push_back(A[i]);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (std::find(A.begin(), A.end(), B[i]) == A.end()) {
            if (std::find(result.begin(), result.end(), B[i]) == result.end()) {
                result.push_back(B[i]);
            }
        }
    }

    std::cout << "”никальные элементы: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}