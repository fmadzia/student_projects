# Benchmark sortowanie

Benchmark sortowania typu quick sort oraz bubble sort

```cpp
// Funkcja sortująca wektor za pomocą QuickSort
void quickSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}

void bubbleSort(std::vector<int>& x) {
	for(int i = 0; i < x.size(); i++)
	{
		for(int j = 0; j < x.size() - 1; j++)
		{
			if(x[j] > x[j + 1])
			{
				int tmp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = tmp;
			}
		}
	}
}

// Test wydajności sortowania QuickSort
TEST(BenchmarkTest, QuickSortBenchmark) {
    std::vector<int> vec(10000); // Tworzymy wektor z 10000 losowymi liczbami
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(vec.begin(), vec.end(), std::rand);

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(vec); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania quick sort: " << elapsed_seconds.count() << "s\n";
}

TEST(BenchmarkTest, BubbleSortBenchmark) {
	std::vector<int> vec(10000);
	std::srand(std::time(0));
	std::generate(vec.begin(), vec.end(), std::rand);

	auto start = std::chrono::high_resolution_clock::now();

	bubbleSort(vec);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;

	std::cout << "Czas sortowania bubble sort: " << elapsed_seconds.count() << "s\n";
}
```

<img width="960" alt="image" src="https://github.com/user-attachments/assets/8197f40a-214c-4cae-9142-aba412459e03">

### Wnioski

Quicksort jest szybszy
