#include "IComponent.hpp"
#include "Component.hpp"
#include "Parser.hpp"
#include "Circuit.hpp"
#include <string>
#include <iostream>

int main()
{
  nts::t_ast_node *testTree;
  nts::IParser *test = new Parser();
  //comp = comp->createComponent("Fromage de bite", "Null sur 20");
  testTree = test->createTree();
  test->parseTree(*testTree);
  /*std::cout << "----------FIRST NODE------------" << std::endl;
  std::cout << testTree->lexeme << std::endl;
  std::cout << (int)testTree->type << std::endl;
  std::cout << testTree->value << std::endl;
  std::cout << "----------SECOND NODE------------" << std::endl;*/
//  testTree = testTree->children;
  /*std::vector<nts::s_ast_node*>::iterator it = testTree->children->begin();
  std::cout << (*it)->lexeme << '\n';
  std::cout << (*it)->lexeme << '\n';
  std::cout << (*it)->lexeme << '\n';*/
  /*std::cout << (int)testTree->children->type << std::endl;
  std::cout << testTree->children->value << std::endl;*/

  return 0;
}
