#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> numbers;

	int n;
	cin >> n;
    numbers.reserve(n);

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;

		numbers.push_back(a);
	}

	// insertionsort from std lib
	sort(numbers.begin(), numbers.end());

	//output
	if (n % 2 == 1) {
		cout << numbers[n / 2] << endl;
	}
	else {
		cout << 0.5*(numbers[n / 2 - 1] + numbers[n / 2]) << endl;
	}

	return 0;
}

