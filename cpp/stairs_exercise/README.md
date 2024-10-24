# Program do Obliczania Schodów

### Przegląd
Ten program oblicza liczbę stopni potrzebnych do pokonania danej wysokości, uwzględniając standardowe wymiary stopni. Sprawdza również, czy obliczone wymiary stopni spełniają optymalne standardy.

### Opis Programu
Program definiuje funkcję stairsExercise, która przyjmuje dwa parametry:

    int availableDepth: Całkowita dostępna głębokość na schody (cm)
    int availableHeight: Całkowita wysokość do pokonania przez schody (cm)

Funkcja oblicza liczbę stopni (stepCount) potrzebnych do pokonania danej wysokości, używając optymalnej wysokości stopnia. Następnie oblicza głębokość (stepDepth) i wysokość (stepHeight) każdego stopnia.

Program sprawdza, czy obliczone wymiary stopni przekraczają lub są mniejsze od optymalnych wymiarów i wypisuje odpowiednie ostrzeżenia. Na koniec wypisuje liczbę stopni, głębokość stopni i wysokość stopni.

Kod funkcji ```stairsExercise```

```cpp
void stairsExercise(int availableDepth, int availableHeight) {
	int optimalDepth = 25;
	int optimalHeight = 15;

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
