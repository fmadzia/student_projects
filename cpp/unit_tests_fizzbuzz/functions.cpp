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
