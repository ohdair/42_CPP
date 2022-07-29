#include "MutantStack.hpp"

int main()
{
    std::cout << "-------- CONSTRUCTED --------\n";
    MutantStack<int> mstack;
    std::cout << "-------- PUSH --------\n";
    mstack.push(5);
    std::cout << mstack << std::endl;
    mstack.push(17);
    std::cout << mstack << std::endl;
    std::cout << "-------- TOP --------\n";
    std::cout << mstack.top() << std::endl;
    std::cout << "\n-------- POP --------\n\n";
    mstack.pop();
    std::cout << mstack << std::endl;
    std::cout << "\n-------- SIZE --------\n";
    std::cout << mstack.size() << std::endl;
    std::cout << "\n-------- PUSH --------\n";
    mstack.push(3);
    std::cout << mstack << std::endl;
    mstack.push(5);
    std::cout << mstack << std::endl;
    mstack.push(737); //[...] mstack.push(0);
    std::cout << mstack << std::endl;

    std::cout << "\n-------- STACK --------\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "\n-------- STACK --------\n";
    std::stack<int> s(mstack);
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop(); 
    }

    return 0;
}