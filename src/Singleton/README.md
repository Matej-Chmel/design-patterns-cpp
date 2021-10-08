# Singleton

Singleton encapsulates an instance of an object that should be created only once and should be available globally. The main advantage of using this pattern over global variables is that Singleton is initialized lazily the first time it's accessed.

## Examples

- App
  - An entry point of a program that contains the information about that program.
- Console
  - For console applications only one instance of a class responsible for input and output is needed. This is particularly important when dealing with threads. The implementation of such Singleton should lock access to itself when one thread is performing an operation with the sole instance.

