# FizzBuzz

Program, który wyświetla fizz, gdy liczba jest podzielna przez 3, buzz, gdy liczba jest podzielna przez 5 i fizzbuzz gdy jest podzielna przez 3 i 5.

Do programu napisane są testy jednostkowe sprawdzające, czy algorytm działa

Kod

```cpp
#include <iostream>
#include <string>

using namespace std;

string fizz_buzz(int number)
{
  if(number % 5 == 0 && number % 3 == 0)
  {
    return "fizzbuzz";
  }
  else if(number % 3 == 0)
  {
    return "fizz";
  }
  else if(number % 5 == 0)
  {
    return "buzz";
  }
  else
  {
    return "raah";
  }
}
```

<img width="960" alt="image" src="https://github.com/user-attachments/assets/6754a251-2bea-44a8-9d64-706c18c75679">
