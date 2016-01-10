#include <sstream>
#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc,char **argv) {
  // Create an empty Binary Search Tree
  BST Tree;

  char line[100];
  while(std::cin.getline(line,100)) {
    string str(line);
    if(str.size() ==0) continue; 
    if(str.substr(0,1) == "e") return 1;

    if(str.substr(0,1) == "o") {
      if(str.substr(0,3) == "oin") {
        Tree.Print("IN");
      }
      else if(str.substr(0,4) == "opre") {
        Tree.Print("PRE");
      }
      else if(str.substr(0,5) == "opost") {
        Tree.Print("POST");
      }
      continue;
    }

    //int key = std::stoi(str.substr(1,str.size()-1));
    int key;
    stringstream convert_stm(str.substr(1,str.size()-1));
    if(!(convert_stm >> key)) {
      key = -1;
    }

    if(str.substr(0,1) == "i") Tree.Insert(key);
    else if(str.substr(0,1) == "d") Tree.Delete(key);
  }

  return 1;

}
