#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> numbers;

	int n;
	cin >> n;
  
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;

		numbers.push_back(a);
	}

	//insertionsort
	for (int i = 1; i < numbers.size(); ++i) {
		for (int j = i; j >= 1; j--) {
			if (numbers[j - 1] > numbers[j]) {
				int tmp = numbers[j - 1];
				numbers[j - 1] = numbers[j];
				numbers[j] = tmp;
			}
			else {
				break;
			}
		}
	}

	if (n % 2 == 1) {
		cout << numbers[n / 2] << endl;
	}
	else {
		cout << 0.5*(numbers[n / 2 - 1] + numbers[n / 2]) << endl;
	}


  return 0;
}

