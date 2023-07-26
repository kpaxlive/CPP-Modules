<h1 align="center"> 🧰 CPP06 </h1>

<h2 align="center">This repository contains the exercises of Module 06 from C++ modules.</h2>
<br>

<p align="center">
  <a href="#about">About</a> &#xa0; | &#xa0; 
  <a href="#links">Links</a> &#xa0; | &#xa0;
  <a href="https://github.com/kpaxlive" target="_blank">Author</a>
</p>

<hr>

## About

<p>
This module is designed to help you understand the different casts in CPP.
</p>
<p>
A Cast operator is an unary operator which forces one data type to be converted into another data type.
</p>

#### Objectives
- C++ Casts

#### Skills
- Rigor
- Object-oriented programming
- Imperative programming

## Cast Types
C++ supports four types of casting:
- Static Cast
- Dynamic Cast
- Const Cast
- Reinterpret Cast

#### 1. Static Cast
This is the simplest type of cast which can be used. It is a compile time cast. It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions (or implicit ones).
```cpp
#include <iostream>
using namespace std;
int main()
{
    float f = 3.5;
    int a = f; // this is how you do in C
    cout << "Before " << f << endl;
    int b = static_cast<int>(f);
    cout << "After " << b << endl;
}
```
##### Output:
```cpp
Before 3.5
After 3
```

#### 2. Dynamic Cast
A cast is an operator that converts data from one type to another type. In C++, dynamic casting is mainly used for safe downcasting at run time. To work on dynamic_cast there must be one virtual function in the base class. A dynamic_cast works only polymorphic base class because it uses this information to decide safe downcasting.
```cpp
#include <iostream>
using namespace std;
  
// Base class declaration
class Base {
    virtual void print()
    {
        cout << "Base" << endl;
    }
};
  
// Derived1 class declaration
class Derived1 : public Base {
    void print()
    {
        cout << "Derived1" << endl;
    }
};

// Driver Code
int main()
{
    Derived1 d1;
  
    // Base class pointer holding
    // Derived1 Class object
    Base* bp = dynamic_cast<Base*>(&d1);
  
    // Dynamic_casting
    Derived1* dp2 = dynamic_cast<Derived1*>(bp);
    if (dp2 == nullptr)
        cout << "null" << endl;
    else
        cout << "not null" << endl;
  
    return 0;
}
```
##### Output:
```cpp
not null
```

#### 3. Reinterpret Cast
It is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different. It does not check if the pointer type and data pointed by the pointer is same or not.

```cpp
#include <iostream>
using namespace std;
 
int main()
{
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    cout << *p << endl;
    cout << *ch << endl;
    cout << p << endl;
    cout << ch << endl;
    return 0;
}
```
##### Output:
```cpp
65
A
0x1609c20
A
```

#### 3. Const Cast
It is used to change the constant value of any object or we can say it is used to remove the constant nature of any object. const_cast can be used in programs that have any object with some constant value which need to be changed occasionally at some point.

```cpp
#include <iostream>
using namespace std;
  
class student
{
private:
    int roll;
public:
    // constructor
    student(int r):roll(r) {}
  
    // A const function that changes roll with the help of const_cast
    void fun() const
    {
        ( const_cast <student*> (this) )->roll = 5;
    }
    int getRoll()  { return roll; }
};
  
int main(void)
{
    student s(3);
    cout << "Old roll number: " << s.getRoll() << endl;
    s.fun();
    cout << "New roll number: " << s.getRoll() << endl; 
    return 0;
}
```

##### Output:
```cpp
Old roll number: 3
New roll number: 5
```

## Links ##
- [CPP Reference](https://en.cppreference.com/)
- [CPP CAST Types Article](https://www.tutorialspoint.com/cplusplus/cpp_casting_operators.htm#:~:text=A%20cast%20is%20a%20special,as%20any%20other%20unary%20operator.&text=const_cast%20(expr),or%20volatile%20in%20a%20cast)
- [Dynamic Cast](https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/)
- [Static Cast](https://www.geeksforgeeks.org/static_cast-in-c-type-casting-operators/?ref=rp)
- [Reinterpret Cast](https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/?ref=rp)
- [Const Cast](https://www.geeksforgeeks.org/const_cast-in-c-type-casting-operators/?ref=rp)
