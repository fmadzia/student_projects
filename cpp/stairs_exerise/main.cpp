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

	int stepCount = ceil(availableDepth / optimalHeight);

	float stepDepth = availableDepth / stepCount;
	float stepHeight = availableHeight / stepCount;

	if(stepHeight > optimalHeight) {
		cout << "!!! Obliczona wysokosc schodow (" << stepHeight << ") jest wieksza od optymalnej (" << optimalHeight << endl;
	}

	cout << "Ilosc schodow: " << stepCount << endl;
	cout << "Glebokosc schodow: " << stepDepth << endl;
	cout << "Wysokosc schodow: " << stepHeight << endl;

	return 0;
}
