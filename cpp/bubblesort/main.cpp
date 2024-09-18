#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> x) {
	for(size_t i = 0; i < x.size(); i++) {
		cout<<x[i]<<" ";
	}

	cout<<endl;
}

void bubbleSort(vector<int>& x) {
	bool swap = true;

	while(swap) {
		swap = false;

		for(size_t i = 0; i < x.size() - 1; i++) {
			if(x[i] > x[i + 1]) {
				x[i] += x[i + 1];
				x[i + 1] = x[i] - x[i + 1];
				x[i] -= x[i + 1];

				swap = true;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	vector<int> x { 3, 1, 5, 4 };

	printVector(x);

	bubbleSort(x);

	printVector(x);
}
