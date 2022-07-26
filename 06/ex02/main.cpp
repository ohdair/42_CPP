/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:25:36 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/26 17:15:34 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// For random function 
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
    int select = (std::rand() % 3) + 1;
    
    A *a;
    B *b;
    C *c;
    switch (select)
    {
        case 1:
            a = new A;
            return static_cast<Base *>(a);
            break;
        case 2:
            b = new B;
            return static_cast<Base *>(b);
            break;
        default:
            c = new C;
            return static_cast<Base *>(c);
            break;
    }
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
    } else {
        std::cout << "Unkown Type\n";
    }
}

void identify(Base& p)
{
    // 값을 사용하지 않았다 표현되기에 void 사용 
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A\n";
        return ;
    } catch (std::bad_cast &e) {

    }
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B\n";
        return ;
    } catch (std::bad_cast &e) {

    }
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C\n";
        return ;
    } catch (std::bad_cast &e) {

    }
    std::cout << "Unkown Type\n";
}

int main(void)
{
    std::srand(std::time(NULL));
    
    Base *test1 = generate();
    Base *test2 = generate();
    Base *test3 = generate();

    Base &test1_ref = *test1;
    Base &test2_ref = *test2;
    Base &test3_ref = *test3;

    identify(test1);
    identify(test2);
    identify(test3);

    identify(&test1_ref);
    identify(&test2_ref);
    identify(&test3_ref);

    delete test1;
    delete test2;
    delete test3;
    return 0;
}