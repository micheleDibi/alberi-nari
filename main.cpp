#include <iostream>
#include "alberoNarioList.h"
#include "alberoNarioPuntatori.h"

using namespace std;

int main()
{
    linkedTree<char> Tree;

	linkedTree<char>::node n;
	Tree.insRoot(n);
	Tree.writeNode(Tree.root(),'a');
	//Tree.print();
    return 0;
}
