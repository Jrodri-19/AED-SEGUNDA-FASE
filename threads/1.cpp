#include <iostream>
#include <thread>

void t(){
  std::cout<<"Hola\n";
}
int main(){
  std::thread h1(t);
  h1.join();
  return 0;
}
