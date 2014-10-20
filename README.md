UnifyAlgorithm
==============

An implementation of the classes on the repository 'BlurParser' to implement Robinson's Unification algorithm.

The grammar that is accepted as input to the unification algorithm is the following:

UNIFY ::= TERM = TERM<br>
TERM ::= symbol<br>
TERM ::= integer<br>
TERM ::= float<br>
TERM ::= variable<br>
TERM ::= FORMULA<br>
FORMULA ::= symbol ( TERMLIST )<br>
FORMULA ::= symbol ()<br>
TERMLIST ::= TERM<br>
TERMLIST ::= TERM , TERMLIST<br>

Compiling the code
-------------------

You can compile the code as long as you have a Make utility and a C++ compiler. This code was compiled with gcc-g++ 4.8.3, however it probably should work with most C++ compilers like Clang or MSVC++ compiler. No features from C++11 are used, so it should work with relatively old compilers.

To compile using Linux, open a terminal and move to the directory of the project and then type:
```
  make
```

Object files should be generated for all the files, as well as the executable application, 'unify'. You can run it by typing:
```
  ./unify
```

If the program does not run, it probably generated the executable without the appropiate permissions. To solve the problem, just allow the program to have execution privileges.

Finally, if you want to remove the object files, you can type on the terminal:
```
  make clean
```

Do note that this won't remove the 'unify' executable file.
