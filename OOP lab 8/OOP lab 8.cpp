#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime> 

using namespace std;

void processArray(vector<int>& arr)
{
    auto minAbsElementIt = min_element(arr.begin(), arr.end(), [](int a, int b)
        {
            return abs(a) < abs(b);
        });
    int minAbsElement = *minAbsElementIt;
    cout << "Мiнiмальний за модулем елемент: " << minAbsElement << endl;

    auto zeroIt = find(arr.begin(), arr.end(), 0);
    int sumAfterZero = 0;
    if (zeroIt != arr.end() && zeroIt + 1 != arr.end())
    {
        sumAfterZero = accumulate(zeroIt + 1, arr.end(), 0, [](int sum, int val)
            {
                return sum + abs(val);
            });
    }
    cout << "Сума модулiв елементiв пiсля першого нуля: " << sumAfterZero << endl;

    vector<int> evenPosElements, oddPosElements;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (i % 2 == 0)
        {
            evenPosElements.push_back(arr[i]);
        }
        else
        {
            oddPosElements.push_back(arr[i]);
        }
    }

    arr.clear();
    arr.insert(arr.end(), evenPosElements.begin(), evenPosElements.end());
    arr.insert(arr.end(), oddPosElements.begin(), oddPosElements.end());

    cout << "Перетворений масив: ";
    for (const int& elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    srand(time(0));

    int n = 10;
    vector<int> arr(n);
    for (int& elem : arr)
    {
        elem = rand() % 21 - 10;
    }

    cout << "Початковий масив: ";
    for (const int& elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;

    processArray(arr);

    return 0;
}