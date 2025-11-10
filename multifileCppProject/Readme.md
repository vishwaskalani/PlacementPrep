# In this module we will be learning how to maintain and write a multifile C++ project 

- Let us say you want to maintain a base class b1 separate from its 2 derived classes d1 and d2 and then a main file to use them in separate files for better organization and modularity.
- First, we will create a header file for the base class b1. Let's name it `b1.h`.
- In `b1.h`, we will define the base class b1 with its member functions and variables.
- We will include the header file in the base class implementation file `b1.cpp`, where we will define the member functions of the base class.
- Next, we will create header files for the derived classes d1 and d2, named `d1.h` and `d2.h` respectively.
- In `d1.h`, we will include `b1.h` and define the derived class d1, inheriting from b1.
- Similarly, in `d2.h`, we will include `b1.h` and define the derived class d2, inheriting from b1.
- We will then create implementation files for the derived classes, `d1.cpp` and `d2.cpp`, where we will define the member functions of d1 and d2 respectively.
- Finally, we will create a `main.cpp` file where we will include the header files for the derived classes and use them to demonstrate polymorphism and inheritance.
- For compiling the multifile project, we can use a command like:
  ```
  g++ main.cpp b1.cpp d1.cpp d2.cpp -o my_program
  ```
- This will compile all the source files and link them together to create an executable named `my_program`.
- By organizing the code in this way, we can easily maintain and update each class separately without affecting the others, leading to better code management and readability.