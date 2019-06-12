//
//  main.cpp
//  heap
//  Created by Julian Rincon on 2018-05-19.
//

#include <iostream>
#include <vector>
#include <random>
#include "p2.hpp"

int main()
{
    const short min = 65, max = 90, dim = 13;
    std::random_device rd;
    std::default_random_engine generator{rd()};
    std::uniform_int_distribution<int> distribution(min, max);
    
    binary_heap<char> bin_ch;
    for (unsigned i = 0; i < 2 * dim; i++)
        bin_ch.insert(distribution(generator));

    std::cout << "Extreme element: " << bin_ch.top() << std::endl;
    bin_ch.display();
    
    for (unsigned i = 0; i <= dim; i++) {
        if (bin_ch.empty()) continue;
        std::cout << "Extract " << bin_ch.pop() << " element\n";
    }
    bin_ch.display();

    return 0;
}
