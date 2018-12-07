#include <iostream>
#include <string>

using namespace std;

class singleton
{
  private:
    int a;
    int b;
    static singleton *ptr;    // prevents the creation of new private elements

    singleton()
    {
      singleton::a = 3;
      singleton::b = 2;
    }

    singleton(int _a, int _b)
    {
      singleton::a = _a;
      singleton::b = _b;
    }

  protected:

  public:
    singleton& operator=(const singleton&) = delete;    // building by copy is forbidden, the singleton cannot get initialed by equality (copy)

    singleton(const singleton&) = delete;                // building by copy is forbidden, the singleton cannot get initialed by equality (copy)

    // -> Impossible to copy a singleton class, thus only accessible by its get() function "operator underloading?"

    // On ne peut retourner qu'un pointeur sur les singletons
    static singleton *get()
    {
      if(ptr == NULL)             //
        ptr = new singleton();
      return ptr;
    }

    static singleton *get(int _a, int _b)
    {
      if(ptr == NULL)             //
        ptr = new singleton(_a, _b);
      return ptr;
    }

    int get_a()
    {
      return singleton::a;
    }

    int get_b()
    {
      return singleton::b;
    }
};

singleton *singleton::ptr = nullptr;    // declare singleton ptr as null

void fonctionApart()
{
  cout << singleton::get()->get_a() << endl;    // singleton::get() = equiv to singleton object
}

int main()
{
  singleton *toto = singleton::get();
  singleton *titi = singleton::get();
  cout << toto <<  " " << titi << endl; // check toto & titi addresses supposedly equal

  singleton *tutu = singleton::get(1,5);
  cout << tutu->get_a() << " " << tutu->get_b() << endl;
  fonctionApart();                      //

  singleton *tata = tutu;               // operator '=' is available : same address
  cout << tata << endl;

  singleton tete = *tutu;
  cout << &tete <<  endl;
}
