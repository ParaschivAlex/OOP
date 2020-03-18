#include <iostream>
#include <Complex.h>
#include <cmath>
using namespace std;

int main()
{
    Complex v[5];
    citire_n_obiecte(5,v);
    rezolvare(v[0], v[1], v[2]);
    return 0;

}
