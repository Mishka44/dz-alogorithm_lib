#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int Get_num() {
    static std::random_device rd;
    std::uniform_int_distribution<int> distr(-10, 10);

    return distr(rd);
}
int Get_num2() {
    static std::random_device rd;
    std::uniform_int_distribution<int> distr(0, 20);

    return distr(rd);
}

int main()
{
    std::vector <int> arr(20); // -10, +10
    std::vector<int> arr2(20); // 0, 20



    std::generate(arr.begin(), arr.end(), Get_num);
    std::generate(arr2.begin(), arr2.end(), Get_num2);

    std::stable_sort(arr.begin(), arr.end());
    std::stable_sort(arr2.begin(), arr2.end());


    for (auto& i : arr)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";

    for (auto& i : arr2)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";

    std::vector<int> arr3;
    for (int i = 0; i < arr.size(); i++) {
        auto res = std::find(arr2.begin(), arr2.end(), arr[i]);
        if (res != arr2.end()) {
            auto res2 = std::find(arr3.begin(), arr3.end(), arr[i]);
            if (res2 == arr3.end()) {
                arr3.push_back(*res);
            }
            
        }
    }
    std::cout << "result: ";
    for (auto& i : arr3)
    {
        std::cout << i << ", ";
    }
    
}

