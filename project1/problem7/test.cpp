#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>


int main()
{
  int n = 3;
  std::vector<int> v{ 1, 2, 3 };

  for (int i = n-1; i >= 0;i--)
  {
    std::cout<< '\n' << v.at(i);

  }





  // Return 0 when done
  return 0;
}
