#include <iostream>
#include <cmath>

using namespace std;

void stairsExercise(int availableDepth, int availableHeight) {
	const int optimalDepth = 25;
	const int optimalHeight = 15;

	int stepCount = ceil(availableHeight / optimalHeight);

	float stepDepth = availableDepth / stepCount;
	float stepHeight = availableHeight / stepCount;

	if(stepHeight > optimalHeight) {
		cout << "!!! Obliczona wysokosc schodow (" << stepHeight << ") jest wieksza od optymalnej (" << optimalHeight << ")" << endl;
	}
	else if(stepHeight < optimalHeight) {
		cout << "!!! Obliczona wysokosc schodow (" << stepHeight << ") jest mniejsza od optymalnej (" << optimalHeight << ")" << endl;
	}

	if(stepDepth > optimalDepth) {
		cout << "!!! Obliczona glebokosc schodow (" << stepDepth << ") jest wieksza od optymalnej (" << optimalDepth << ")" << endl;
	}
	else if(stepDepth < optimalDepth) {
		cout << "!!! Obliczona glebokosc schodow (" << stepDepth << ") jest mniejsza od optymalnej (" << optimalDepth << ")" << endl;
	}


	cout << "Ilosc schodow: " << stepCount << endl;
	cout << "Glebokosc schodow: " << stepDepth << endl;
	cout << "Wysokosc schodow: " << stepHeight << endl;
}

int main() {
	stairsExercise(100, 60);

	return 0;
}
