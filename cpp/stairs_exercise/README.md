# Program do Obliczania Schodów

### Przegląd
Ten program oblicza liczbę stopni potrzebnych do pokonania danej wysokości, uwzględniając standardowe wymiary stopni (25cm głębokości i 15cm wysokości). Sprawdza również, czy obliczone wymiary stopni spełniają optymalne standardy.

### Schemat

<img width="573" alt="image" src="https://github.com/user-attachments/assets/155d570c-5e4d-4dcb-bd30-dab1f0b58e25">

### Opis Programu
Program definiuje funkcję stairsExercise, która przyjmuje dwa parametry:

    int availableDepth: Całkowita dostępna głębokość na schody (cm)
    int availableHeight: Całkowita wysokość do pokonania przez schody (cm)

Funkcja oblicza liczbę stopni (stepCount) potrzebnych do pokonania danej wysokości, używając optymalnej wysokości stopnia. Następnie oblicza głębokość (stepDepth) i wysokość (stepHeight) każdego stopnia.

Program sprawdza, czy obliczone wymiary stopni przekraczają lub są mniejsze od optymalnych wymiarów i wypisuje odpowiednie ostrzeżenia. Na koniec wypisuje liczbę stopni, głębokość stopni i wysokość stopni.

Kod funkcji ```stairsExercise```

```cpp
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
```

### Obliczenia:

>[!Important]
>Program korzysta ze stałych ```OPTIMAL_DEPTH = 25``` (cm) oraz ```OPTIMAL_HEIGHT = 15``` (cm)

```
stepCount: Liczba stopni zaokrąglona w dół, obliczona jako ceil(availableHeight / OPTIMAL_HEIGHT).
stepDepth: Głębokość każdego stopnia (cm), obliczona jako availableDepth / stepCount.
stepHeight: Wysokość każdego stopnia (cm), obliczona jako availableHeight / stepCount.
```
### Przykład Użycia
```cpp
int main() {
    stairsExercise(100, 60);
    return 0;
}
```

### Wynik
Wypisuje ostrzeżenia, jeśli obliczone wymiary stopni przekraczają lub są mniejsze od optymalnych wymiarów.
Wypisuje liczbę stopni, głębokość stopni i wysokość stopni.

Przykład dla ```stairsExercise(100, 90)```

```shell
!!! Obliczona głębokość schodów (16) jest mniejsza od optymalnej (25)
Ilość schodów: 6
Głębokość schodów: 16
Wysokość schodów: 15
```

### Uwagi

>[!Important]
>Program używa funkcji ceil z biblioteki <cmath>, aby zapewnić, że liczba stopni jest zaokrąglona w górę do najbliższej liczby całkowitej.
>
>Program wypisuje ostrzeżenia, jeśli obliczone wymiary stopni nie odpowiadają optymalnym wymiarom.
