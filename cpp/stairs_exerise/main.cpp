#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int availableDepth;
	int availableHeight;

	int optimalDepth = 25;
	int optimalHeight = 15;

	cout << "Podaj dostepna glebokosc: ";
	cin >> availableDepth;

	cout << "Podaj dostepna wysokosc: ";
	cin >> availableHeight;

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

	return 0;
}
