#include <iostream>

using namespace std;

int main() {

	float numbers[15];

	for (int i = 0; i < 15; i++) {
		cin >> numbers[i];
	}

    for (int i = 0; i < 15 - 1; i++)
    {
        for (int j = 0; j < 15 - i - 1; j++)
        {

            if (numbers[j] > numbers[j + 1])
            {
                float temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    cout << "The array will be:\n";
    for (int i = 0; i < 15; i++)
        cout << numbers[i] << " ";
}