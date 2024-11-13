# Program do Obliczania Schodów

Program oblicza liczbę stopni potrzebnych do pokonania danej wysokości, uwzględniając minimalne i maksymalne wymiary stopni (wysokość i głębokość). Sprawdza również, czy podane wymiary schodów mieszczą się w określonych granicach i zwraca wynik obliczeń.

### Opis Programu

Program definiuje dwie klasy i jedną funkcję:

- **StairCalculationException**: Klasa wyjątku rzucanego, gdy nie można obliczyć schodów z podaną wysokością i głębokością.
- **StairCalculationResult**: Klasa przechowująca wynik obliczeń schodów, zawierająca liczbę schodków, ich wysokość i głębokość.
- **calculateStairs**: Funkcja obliczająca liczbę schodów, ich wysokość i głębokość na podstawie dostępnej wysokości i głębokości.

### Klasa `StairCalculationException`

```cpp
class StairCalculationException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Nie można utworzyć schodów z podaną wysokością i głębokością.";
    }
};
```

- Klasa dziedziczy po `std::exception` i nadpisuje metodę `what()`, która zwraca komunikat błędu.

### Klasa `StairCalculationResult`

```cpp
class StairCalculationResult
{
public:
    int stairsCount;
    int heightOfEachStair;
    int depthOfEachStair;

    StairCalculationResult(int stairsCount, int heightOfEachStair, int depthOfEachStair)
    {
        this->stairsCount = stairsCount;
        this->heightOfEachStair = heightOfEachStair;
        this->depthOfEachStair = depthOfEachStair;
    }
};
```

- Klasa przechowuje wynik obliczeń schodów: liczbę schodków (`stairsCount`), ich wysokość (`heightOfEachStair`) i głębokość (`depthOfEachStair`).
- Posiada konstruktor inicjujący te wartości.

### Funkcja `calculateStairs`

```cpp
StairCalculationResult calculateStairs(int availableHeight, int availableDepth)
{
    const int minHeight = 14;
    const int maxHeight = 19;
    const int minDepth = 25;
    const int maxDepth = 32;

    if (availableHeight < minHeight || availableDepth < minDepth)
    {
        throw StairCalculationException();
    }

    for (int height = maxHeight; height >= minHeight; --height)
    {
        for (int depth = maxDepth; depth >= minDepth; --depth)
        {
            int stepsByHeight = availableHeight / height;
            int stepsByDepth = availableDepth / depth;

            if (stepsByHeight * height <= availableHeight && stepsByDepth * depth <= availableDepth)
            {
                return StairCalculationResult(stepsByHeight, height, depth);
            }
        }
    }

    throw StairCalculationException();
}
```

- Funkcja oblicza liczbę schodów, ich wysokość i głębokość na podstawie dostępnych wymiarów.
- Sprawdza, czy dostępne wymiary są wystarczające do obliczeń (minimalna wysokość to 14 cm, minimalna głębokość to 25 cm).
- Przeszukuje możliwe kombinacje wysokości i głębokości schodków w zadanym zakresie (od 14 cm do 19 cm dla wysokości i od 25 cm do 32 cm dla głębokości).
- Zwraca obiekt `StairCalculationResult` z obliczonymi wartościami, gdy znajdzie odpowiednie wymiary.
- Rzuca wyjątek `StairCalculationException`, gdy nie można znaleźć odpowiednich wymiarów schodków.

### Przykład Użycia
```cpp
int main() {
    try {
        StairCalculationResult result = calculateStairs(200, 150);
        std::cout << "Ilość schodów: " << result.stairsCount << std::endl;
        std::cout << "Wysokość schodków: " << result.heightOfEachStair << " cm" << std::endl;
        std::cout << "Głębokość schodków: " << result.depthOfEachStair << " cm" << std::endl;
    } catch (const StairCalculationException& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
```

### Testy dla Programu do Obliczania Schodów

Testy mają na celu weryfikację poprawności działania funkcji `calculateStairs`. Wykorzystujemy framework Google Test (gtest) do testowania różnych scenariuszy.

### Zawartość Pliku `main_test.cpp`

```cpp
#include <gtest/gtest.h>
#include "main.cpp"

// Test sprawdzający poprawne działanie funkcji dla poprawnych danych wejściowych
TEST(stairsTests, validInput) {
    StairCalculationResult stairs = calculateStairs(250, 150);
    EXPECT_EQ(stairs.stairsCount, 13); // Oczekujemy, że liczba schodków wynosi 13
    EXPECT_NE(stairs.depthOfEachStair, 0); // Oczekujemy, że głębokość każdego schodka nie wynosi 0
}

// Test sprawdzający poprawne rzucenie wyjątku dla niepoprawnych danych wejściowych
TEST(stairsTests, invalidInput) {
    try
    {
        StairCalculationResult stairs = calculateStairs(0, 0);
    }
    catch(std::exception& e)
    {
        EXPECT_STREQ("Exception was thrown as expected: ", e.what());
    }
}

// Funkcja główna uruchamiająca wszystkie testy
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### Opis Testów

1. **Test validInput**:
    - Sprawdza, czy funkcja `calculateStairs` zwraca poprawny wynik dla prawidłowych danych wejściowych (`250` wysokości i `150` głębokości).
    - Oczekujemy, że liczba schodków (`stairsCount`) wynosi `13`.
    - Sprawdzamy, czy głębokość każdego schodka (`depthOfEachStair`) nie jest równa `0`.

2. **Test invalidInput**:
    - Sprawdza, czy funkcja `calculateStairs` poprawnie rzuca wyjątek dla niepoprawnych danych wejściowych (`0` wysokości i `0` głębokości).
    - Oczekujemy, że zostanie rzucony wyjątek z odpowiednim komunikatem.

### Jak Uruchomić Testy

1. Zainstaluj bibliotekę Google Test.
2. Skompiluj plik `main_test.cpp` wraz z plikiem źródłowym `main.cpp`.
3. Uruchom wygenerowany plik wykonywalny, aby przeprowadzić testy.

### Wyniki Testów

- Testy zostaną uruchomione automatycznie przez Google Test, a wyniki zostaną wyświetlone w konsoli.
- Wyniki testów pokażą, czy funkcja `calculateStairs` działa poprawnie dla różnych scenariuszy danych wejściowych.
