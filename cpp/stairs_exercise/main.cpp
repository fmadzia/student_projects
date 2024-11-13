#include <iostream>
#include <cmath>

using namespace std;

void stairsExercise(int availableDepth, int availableHeight) {
	const int OPTIMAL_DEPTH = 25;
	const int OPTIMAL_HEIGHT = 15;

	int stepCount = ceil(availableHeight / OPTIMAL_HEIGHT);

	float stepDepth = availableDepth / stepCount;
	float stepHeight = availableHeight / stepCount;

	if(stepHeight > OPTIMAL_HEIGHT) {
		cout << "!!! Obliczona wysokosc schodow (" << stepHeight << ") jest wieksza od optymalnej (" << OPTIMAL_HEIGHT << ")" << endl;
	}
	else if(stepHeight < OPTIMAL_HEIGHT) {
		cout << "!!! Obliczona wysokosc schodow (" << stepHeight << ") jest mniejsza od optymalnej (" << OPTIMAL_HEIGHT << ")" << endl;
	}

	if(stepDepth > OPTIMAL_DEPTH) {
		cout << "!!! Obliczona glebokosc schodow (" << stepDepth << ") jest wieksza od optymalnej (" << OPTIMAL_DEPTH << ")" << endl;
	}
	else if(stepDepth < OPTIMAL_DEPTH) {
		cout << "!!! Obliczona glebokosc schodow (" << stepDepth << ") jest mniejsza od optymalnej (" << OPTIMAL_DEPTH << ")" << endl;
	}


	cout << "Ilosc schodow: " << stepCount << endl;
	cout << "Glebokosc schodow: " << stepDepth << endl;
	cout << "Wysokosc schodow: " << stepHeight << endl;
}

int main() {
	int depth;
	int height;

	cout << "Podaj glebokosc: ";
	cin >> depth;

	cout << "Podaj wysokosc: ";
	cin >> height;

	stairsExercise(depth, height);

	return 0;
}
