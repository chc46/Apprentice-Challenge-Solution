//
//  LL.h
//  COSC052Spring2017L12Ex1
//

#ifndef _STACK_h_
#define _STACK_h_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <exception>

#define DEBUG_LL_POP_BACK

using std::string;
using std::endl;
using std::cout;


/**
 * A stack data structure used to chronologically display the show times of a particular movie.
 * It includes methods necessary to use in the program as well as other potential
 * methods for future program expansion.
 */

/****************************************************************************
 *                                                                          *
 *                       class Node definition                              *
 *                                                                          *
 ****************************************************************************/

template<typename T>
class Node
{
public:
    T info;
    Node<T> *next;
    
    Node(T = T(), Node<T> *next = NULL);
    
}; //END definition class Node



/****************************************************************************
 *                                                                          *
 *                        class Stack definition                            *
 *                                                                          *
 ****************************************************************************/

template<typename T>
class Stack
{
    
private:
    unsigned long count;
    Node<T> *head;
    Node<T> *tail;
    
    void copyList(const Stack<T>&);
    
public:
    Stack();
    Stack(const Stack<T>&);
    ~Stack();
    
    Stack<T> operator=(const Stack<T>&);
    
    void push(T);
    void pop();
    
    // void push_front(T);
    // void pop_front();
    T& top() const;
    
    void clear();
    bool empty() const {return head == NULL;}
    unsigned long size() const {return count;}
    
    // T& at(int ndx) const;
    
}; //END definition templatized class LL



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                      class Node implementation                         **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

template<typename T>
Node<T>::Node(T infoValue, Node<T> *nextPtr)
{
    info = infoValue;
    next = nextPtr;
    
} //END Node::Node(int infoValue, Node *nodePtr)


/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                       class Stack implementation                       **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

template<typename T>
T& Stack<T>::top() const
{
    if ( this->empty() )
    {
        throw std::logic_error("ERROR - in Stack::top() the stack is empty.\n");
    }
    
    return head->info;
    
    
    
} // END member function top


/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

template<typename T>
Stack<T>::Stack()
{
    // default constructor
    // cout << "Inside default constructor for class Stack\n";
    count = 0;
    head = tail = NULL;
    
} //END default constructor for Stack class



/****************************************************************************
 *                       member function copyList                           *
 ****************************************************************************/

template<typename T>
void Stack<T>::copyList(const Stack<T> &otherStack)
{
    // copy constructor
    // std::cout << "Inside function copyList() for class Stack\n";
    
    
    // most everything still needs to be implemented here
    
} //END function copyList(const Stack &otherStack)




/****************************************************************************
 *                            copy constructor                              *
 ****************************************************************************/

template<typename T>
Stack<T>::Stack(const Stack<T> &otherStack)
{
    // copy constructor
    // std::cout << "Inside copy constructor for class Stack\n";
    
    head = tail = NULL;
    count = 0;
    
    // cout << "calling copyList() member function" << endl;
    copyList(otherStack);
    
} //END Stack::Stack(const Stack &otherStack)



/****************************************************************************
 *                               destructor                                 *
 ****************************************************************************/

template<typename T>
Stack<T>::~Stack()
{
    // destructor
    // std::cout << "Stack::~Stack() Entered destructor for class Stack\n";
    if (head == NULL)
    {
        //nothing to do
        // std::cout << "Stack::~Stack() linked list is empty, nothing to do\n";
    }
    else
    {
        
        // unsigned long oldCount = count;
        // std::cout << "calling member function clear() ";
        // std::cout << "to deallocate memory for all objects on the list\n";
        
        clear();
        
        // std::cout << "number of elements on the list was: " << oldCount << std::endl;
        // std::cout << "number of elements on list now is:  " << count << std::endl;
        
        head = NULL;
    }
    
    // std::cout << "Stack::~Stack() Exiting destructor for class Stack\n";
    
} //END Stack::~Stack()



/****************************************************************************
 *              non-member function overloaded operator=                    *
 ****************************************************************************/

template<typename T>
Stack<T> Stack<T>::operator=(const Stack<T> &rhsStack)
{
    //overloaded assignment operator
    
    if (this != &rhsStack)
    {
        //no self-assignment, so OK to continue
        std::cout << "Inside overloaded assignment operator for class Stack\n";
        
        //make sure any existing contents of the left hand side list are deallocated
        this->clear();
        
        //should have been done by clear, but no harm repeating
        count = 0;
        head = tail = NULL;
        
        cout << "calling function copyList()" << endl;
        copyList(rhsStack);
        
    } // END if (this != &rhsStack)
    
    return *this;
    
} // END Stack::operator=(const Stack &rhsStack)



/****************************************************************************
 *                        member function push                              *
 ****************************************************************************/

template<typename T>
void Stack<T>::push(T infoToAdd)
{
    Node<T> *temp;
    
    try
    {
        if (head == NULL)
        {
            //this is the first element
            // std::cout << "adding first node to linked list\n";
            
            head = new Node<T>(infoToAdd, NULL);
            tail = head;
        }
        else
        {
            //list has some contents already
#ifdef DEBUG_Stack_PUSH_FRONT
            std::cout << "adding nodes to non-empty linked list\n";
#endif
            temp = new Node<T>(infoToAdd, head);
            
            head = temp;
        }
        
        count++;
    }
    catch(std::bad_alloc &ba1)
    {
        std::cout << "Inside Stack::addToFront() unable to allocate memory\n";
        throw;
    }
    
} //END Stack::push(T infoToAdd)


/****************************************************************************
 *                       member function pop                                *
 ****************************************************************************/

template<typename T>
void Stack<T>::pop()
{
    std::logic_error le1("ERROR - in Stack::pop_front(), list is already empty\n");
    
    try
    {
        if ( head == NULL )
        {
            // nothing to do
            throw le1;
        }
        else if ( head->next == NULL )
        {
            // only one object on the list
            delete head;
            head = tail = NULL;
            count = 0;
        }
        else
        {
            // more than one object on the list
            Node<T> *current = head;
            head = head->next;
            delete current;
            count--;
        }
    }
    catch (std::logic_error le1)
    {
        cout << le1.what() << endl;
    }
    catch(...)
    {
        cout << "ERROR - unknown exception caught in Stack::pop_front" << endl;
    }
    
} // END member function pop



/****************************************************************************
 *                         member function clear                            *
 ****************************************************************************/

template<typename T>
void Stack<T>::clear()
{
    Node<T> *current = head;
    int i = 0;
    
    std::cout << "\tStack::clear() preparing to remove " << count;
    std::cout << " Nodes from the linked list\n";
    
    while (current != NULL)
    {
        i++;
        head = head->next;
        delete current;
        current = head;
        count--;
    }
    
    current = head = tail = NULL;
    
    std::cout << "\tStack::clear() removed " << i << " Nodes from the list\n";
    std::cout << "\tStack::clear() new count is: " << count << std::endl;
    
} //END Stack::clear()



#endif
