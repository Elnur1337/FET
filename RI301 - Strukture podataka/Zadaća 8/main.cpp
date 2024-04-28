#include "SingleLinkedList.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  SingleLinkedList<std::string> lista;
  lista.push_back("word1").push_back("word2");
  lista.push_front("word3");
  std::cout << lista << std::endl;
  lista.pop_front();
  std::cout << lista << std::endl;
  lista.pop_back();
  std::cout << lista << std::endl;
  SingleLinkedList<std::string> lista2;
  lista2.push_back("word1").push_back("word2");
  lista.extend(lista2);
  auto it = lista.find("word2");
  if (it != lista.end()) {
    std::cout << "Element: " << *it << std::endl;
  } else {
    std::cout << "Element ne postoji" << std::endl;
  }
  std::cout << lista << std::endl;
  auto pos = lista.begin();
  ++pos;
  lista.insert(pos, "nova rijec");
  std::cout << lista << std::endl;
  auto eraseIt = lista.begin();
  auto it2 = lista.erase(lista.find("word2"));
  std::cout << lista << std::endl;
  it = std::find_if(lista.begin(), lista.end(),[](const auto& el){return el.size() > 3;});
  if(it != lista.end()){
    std::cout << "Element pronadjen: "<<*it<< std::endl;
  }
  else{
    std::cout << "Element ne postoji: "<< std::endl;
  }
  return 0;

}
