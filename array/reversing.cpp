#include <iostream>
// using namespace std;

int main()
{
  int temp;

  int arr[5]{1, 2, 3, 4, 5};

  std::cout << "Before reversing\n";

  for (int i = 0; i < 5; i++)
  {
    std::cout << arr[i] << " , ";
  }

  std::cout << "\n\n";

  int start = 0;
  int end = 4;
  for (int i = 0; i < 5; i++)
  {
    if (start < end)
    {
      temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;
    }
  }

  std::cout << "After reversing\n";

  for (int i = 0; i < 5; i++)
  {
    std::cout << arr[i] << " , ";
  }
}