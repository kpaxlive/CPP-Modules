<h1 align="center"> 🧰 CPP07 </h1>

<h2 align="center">This repository contains the exercises of Module 07 from C++ modules.</h2>
<br>

<p align="center">
  <a href="#about">About</a> &#xa0; | &#xa0;
  <a href="#samples">Samples</a> &#xa0; | &#xa0;
  <a href="#links">Links</a> &#xa0; | &#xa0;
  <a href="https://github.com/kpaxlive" target="_blank">Author</a>
</p>

<hr>

## About ##

This module is designed to help you understand Templates and the way they work in CPP.

## Objectives
- C++ Templates
## Skills
- Understand the concept of C++ templates.
- Learn how to create function templates and class templates.
- Implement generic algorithms using templates.
## Samples ##
### Simple Class Template Sample
```cpp
// A simple template class
template <typename T>
class MyTemplate {
private:
    T value;

public:
    MyTemplate(T val) : value(val) {}

    T getValue() const {
        return value;
    }

    void setValue(T val) {
        value = val;
    }
};
```
### Simple Function Template Sample
```cpp
// A simple template function
template <typename T>
T add(T a, T b) {
    return a + b;
}
```
## Links ##
- [CPP Templates](https://www.youtube.com/watch?v=I-hZkUa9mIs)
- [CPP Class Templates](https://www.youtube.com/watch?v=mQqzP9EWu58)
- [CPP Article](https://www.geeksforgeeks.org/templates-cpp/)
