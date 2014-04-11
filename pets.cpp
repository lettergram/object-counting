#include <iostream>
#include <string>

using namespace std;

class Pet{
private:
  static int count; // Count of generic Pet Objects
public:
  Pet(){ count++; }
  virtual ~Pet(){ count--; }
  
  virtual int getCount(){ return count; };
};

class Dog: public Pet{
private:
  static int Dogs;  // The count of Dog objects
public:
  Dog(){ Dogs++; }
  ~Dog(){ Dogs--; }
  
  int getCount(){ return Dogs; }
};

class Cat: public Pet{
private:
  static int Cats; // The count of Cat objects
public:
  Cat(){ Cats++; }
  ~Cat(){ Cats--; }
  int getCount(){ return Cats; }
};

// I have to initialize the static ints
int Pet::count = 0;
int Dog::Dogs = 0;
int Cat::Cats = 0;

int main(){

  Pet * pet = new Pet(); // This is just used to get counter
  Pet * p = new Cat();
  Pet * c  = new Cat();
  Pet * d = new Dog();
  
  cout << "\nPets: " << pet->getCount() << endl;
  cout << "Cats: " << c->getCount() << endl;
  cout << "Dogs: " << d->getCount() << endl;
  
  cout << "----------" << endl;
  
  cout << "Cats: " << p->getCount() << endl;
  delete p;
  cout << "Cat Deleted" << endl;
  cout << "Cats: " << c->getCount() << endl;
  delete c;
  cout << "Cat Deleted" << endl;
  cout << "Dogs: " << d->getCount() << endl;
  cout << "Pets: " << pet->getCount() << endl;
  delete d;
  cout << "Dog Deleted" << endl;
  cout << "Pets: " << pet->getCount() << endl;
  delete pet;
  cout << "Abstract Pet Deleted\n" << endl;

  return 0;
}
