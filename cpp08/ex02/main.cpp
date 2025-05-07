#include "MutantStack.hpp"
#include <list>

int main()
{
    {

    
        std::cout << "Mutant Stack:" << std::endl;

        MutantStack<int> mstack;
        std::cout << YELLOW << "Push 1 into the stack." << RESET << std::endl;
        std::cout << YELLOW << "Push 2 into the stack." << RESET << std::endl;
        mstack.push(1);
        mstack.push(2);
        std::cout << "Top of stack: " << mstack.top() << std::endl;
        std::cout << YELLOW << "Pop from stack." << RESET << std::endl;
        mstack.pop();
        std::cout << "Top of stack: " << mstack.top() << std::endl;
        std::cout << "Size of stack: " << mstack.size() << std::endl;
        std::cout << YELLOW << "Push 3 into the stack." << RESET << std::endl;
        mstack.push(3);
        std::cout << YELLOW << "Push 4 into the stack." << RESET << std::endl;
        mstack.push(4);
       std::cout << YELLOW << "Push 5 into the stack." << RESET << std::endl;
        mstack.push(5);

        std::cout << YELLOW << "Iterate through stack from beginning to end and print each element:" << RESET << std::endl;
        MutantStack<int>::iterator it_start = mstack.begin();
        MutantStack<int>::iterator it_end = mstack.end();
        ++it_start;
        --it_start;
        while (it_start != it_end)
        {
            std::cout << *it_start << std::endl;
            ++it_start;
        }

        std::cout << YELLOW << "Iterate through stack from end to beginning and print each element:" << RESET << std::endl;
        MutantStack<int>::reverse_iterator it_rstart = mstack.rbegin();
        MutantStack<int>::reverse_iterator it_rend = mstack.rend();
        while (it_rstart != it_rend)
        {
            std::cout << *it_rstart << std::endl;
            ++it_rstart;
        }
 
    }
    
    
    {
        
        
        
        std::cout << std::endl << "List:" << std::endl;

        std::list<int> mlist;
        std::cout << YELLOW << "Push 1 into the list." << RESET << std::endl;
        std::cout << YELLOW << "Push 2 into the list." << RESET << std::endl;
        mlist.push_back(1);
        mlist.push_back(2);
        std::cout << "Top of list: " << mlist.back() << std::endl;
        std::cout << YELLOW << "Pop from list." << RESET << std::endl;
        mlist.pop_back();
        std::cout << "Top of list: " << mlist.back() << std::endl;
        std::cout << "Size of list: " << mlist.size() << std::endl;
        std::cout << YELLOW << "Push 3 into the list." << RESET << std::endl;
        mlist.push_back(3);
        std::cout << YELLOW << "Push 4 into the list." << RESET << std::endl;
        mlist.push_back(4);
        std::cout << YELLOW << "Push 5 into the list." << RESET << std::endl;
        mlist.push_back(5);
        std::list<int>::iterator it_start = mlist.begin();
        std::list<int>::iterator it_end = mlist.end();
        ++it_start;
        --it_start;
        std::cout << YELLOW << "Iterate through list from beginning to end and print each element:" << RESET << std::endl;
        while (it_start != it_end)
        {
            std::cout << *it_start << std::endl;
            ++it_start;
        }
        std::list<int> s(mlist);


        std::cout << YELLOW << "Iterate through list from end to beginning and print each element:" << RESET << std::endl;
        std::list<int>::reverse_iterator it_rstart = mlist.rbegin();
        std::list<int>::reverse_iterator it_rend = mlist.rend();
        while (it_rstart != it_rend)
        {
            std::cout << *it_rstart << std::endl;
            ++it_rstart;
        }

    }
    return 0;
}