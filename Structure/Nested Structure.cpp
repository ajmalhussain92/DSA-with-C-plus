#include<iostream>
using namespace std;

struct Owner {
  char firstName[30];
  char lastName[30];
};

struct Car {
  char brand[30];
  int year;
  struct Owner owner; // Nested structure
};

int main() {
  struct Owner person = {"John", "Doe"};
  struct Car car1 = {"Toyota", 2010, person};

  cout << "Car: " << car1.brand << " " << car1.year << endl;
  cout << "Owner: " << car1.owner.firstName << " " << car1.owner.lastName << endl;

  return 0;
}