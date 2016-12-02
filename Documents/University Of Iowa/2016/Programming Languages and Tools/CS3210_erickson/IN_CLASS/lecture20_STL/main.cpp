//
//  The C++ Standard Template Library
//  main.cpp
//
//  Created by Jason Fries on 11/16/13.
//  Copyright (c) 2013 Jason Fries. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include <queue>
#include "creature.h"
#include <ctime>
#include "formatter.h"

template <typename T>
void print_vector(std::vector<T> v)
{
    // Q: Why do we have to use typename here? The reason is that
    // the template metavariable T is *nondeducable* in the this context.
    
    typename std::vector<T>::iterator itr;
    
    for(itr=v.begin(); itr!=v.end(); itr++)
    {
        std::cout << *itr << ", ";
    }
    std::cout << std::endl;
    
}

template <typename U>
void print_value(U v)
{
    std::cout << "VALUE: " << v << std::endl;
}


int main(int argc, const char * argv[])
{
    using namespace std;
    
    //=================================================================
    //
    // STL Sequence Containers
    //
    //=================================================================
    
    print_header("STL Sequence Containers" );
    
    // The STL provides a number of useful container objects for storing
    // data. Any object can be stored in a container as long as it is:
    //
    // 1) copy constructable
    // 2) assignable
    //
    // Basic data types (int, double) have this property, as do classes
    // assuming the assignment operator or copy constructor are not
    // private to the class.
    
    //
    //
    // I. Vectors
    //
    //
    
    print_section("I: Vectors");
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Creating a vector container object
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 1: Instantiating a vector object");
    
    // vector is a C++ template class that implements
    // the functionality of an array. This gives us
    // several convenient member functions
    
    vector<int> integers(100);
    cout << integers.size() << endl;
    
    // we can use array notation
    for(int i=0;i<100;i++)
    {
        integers[i] = i*100;
    }
    cout << integers[40] << endl;
    
    // we can swap contents from other containers, which is
    // essentially assigning the contents of one array to another
    vector<int> moreints(100);
    for(int i=0;i<100;i++)
    {
        moreints[i] = i;
    }
    
    integers.swap(moreints);
    cout << integers[40] << endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: Iterators
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 2: Iterators");
    
    // Containers can be implemented in many ways; to deal with the
    // common need to iterate through the contents of the container,
    // we introduce the idea of an iterator -- a generalization of a pointer
    vector<int>::iterator itr;
    itr = integers.begin();

    cout << *itr << endl;
    cout << *(itr + 1) << endl;
    
    // we can also use iterators in a for loop control structure
    // Remember the structure of a for loop
    // <initalization>; <test-expression>; <update-expression>
    for( vector<int>::iterator i = integers.begin(); i != integers.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 3: Dynamic memory management
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 3: Dynamic memory management");
    
    // vector has another feature that is useful: it can increase
    // in size to handle new elements dynamically
    vector<Creature> creatures(2);
    creatures[0] = Creature("troll",100);
    creatures[1] = Creature("rat",10);
    
    cout << "# of creatures: " << creatures.size() << endl;
    
    // with a standard array, we would have to manually manage memory
    // but with the vector class we can do this:
    creatures.push_back(Creature("skeleton",50));
    
    // and the vector will grow in size as needed
    cout << "# of creatures: " << creatures.size() << endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 4: Erase and Insert Spans
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 4: Erase and Insert Spans");
    
    // Erase Spans
    cout << "# of integers: " << integers.size() << endl;
    
    // the range [0,10) deletes 0-9 in the vector
    integers.erase( integers.begin(), integers.begin() + 10);
    print_vector(integers);
    
    cout << "# of integers: " << integers.size() << endl;
    
    // Insert Spans of Values
    // We can insert a block of values (assuming they are the same type)
    // into an vector. The argument format is as follows:
    // <insert point>, <insert values being>, <inserted values end>
    integers.insert(integers.begin(), moreints.begin(), moreints.begin() + 10);
    
    cout << "# of integers: " << integers.size() << endl;
    cout << endl << "=======================================================" << endl;
    print_vector(integers);
    cout << endl << "=======================================================" << endl;
    
    //
    //
    // II. STL functions
    //
    //
    
    print_section("II: Useful STL Functions");
    
    // The STL contains may useful functions -- let's look at 3 that
    // could be helpful for your final project.
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Random Shuffle
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 1: Random Shuffle");
    
    // A: We can randomly shuffle a range of elements in a vector
    random_shuffle(integers.begin(),integers.end());
    print_vector(integers);
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: Sorting Elements
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 2: Sort Elements");
    
    // B: Sort elements.
    sort(integers.begin(),integers.end());
    print_vector(integers);
   
    // NOTE - in order for sort to work, the items in the vector needs to
    // have the operator< member function defined (i.e., some definiton
    // of ordering)
    
    // ----------------------------------------------------------------
    // EXAMPLE 3: Applying Functions
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 3: Applying a function to elements");
    
    // C: Apply a function to each element of a container class
    // This iterates over the contents of a container class and
    // invokes the provided function on ever item.
    // This is the same essential mechinism of what are called
    // functors, which we'll look at next week.
    for_each(integers.begin(),integers.end(),print_value<int>);
    
   
    //
    //
    // III. STL Iterators
    //
    //
    print_section("II: Useful STL Functions");
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Iterating in reverse
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 1: Iterating in reverse");
    
    // for_each is a powerful tool. We can use another type of iterator
    // for example, to iterate through a vector in reverse
    for_each(integers.rbegin(), integers.rend(), print_value<int>);
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: ostream iterators
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 2: ostream iterators");

    // or we can use an iterator to replace the print_vector function implemented above
    ostream_iterator<int> out_itr(cout, " ");
    copy(integers.begin(), integers.end(), out_itr);
    
    
    // ----------------------------------------------------------------
    // EXAMPLE 3: ostream iterators (backwards)
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 3: ostream iterators");
    
    // now backwards
    copy(integers.rbegin(), integers.rend(), out_itr);
    std::cout << std::endl;
    

    //
    //
    // IV. Lists
    //
    //
    
    print_section("IV: Lists");
    
    
    // List is the STL implementation of a doublely linked list (familar
    // to you from homework 4). The advantage of a list object is that
    // insertion in a constant time operation. Insertion (and removal)
    // time for a vector is linear time (i.e., proportional to the number
    // of elements in the container). This means random access in a list
    // is expensive, but insertion and deletion of elements is more effecient
    // than with a vector.
    
    // lets time an example to show the difference
    int N = 40000;
    list<double> dbls(N);
    vector<double> vdbls(N);
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Linear Access
    // list:  O(N)
    // vector O(1)
    // ----------------------------------------------------------------
    
    // ===================================================
    // PERFORMANCE (only 1 sample run)
    // ===================================================
    // MacBook 2.2 GHz Intel Core i7
    //
    // Input size N: 40000
    //
    // Doublely Linked List    ACCESS:0.000688
    // vector                  ACCESS:0.000544
    //
    // Summary: About the same performance
    // ===================================================
    
    print_example("TEST 1: Linear Access ");
    
    clock_t begin = clock();
    list<double>::iterator list_itr;
    int j = 0;
    for(list_itr=dbls.begin(); list_itr != dbls.end(); list_itr++)
    {
        *list_itr = j;
        j++;
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout << "Doublely Linked List ACCESS:" << elapsed_secs << endl;
    
    begin = clock();
    vector<double>::iterator vec_itr;
    j = 0;
    for(vec_itr=vdbls.begin(); vec_itr != vdbls.end(); vec_itr++)
    {
        *vec_itr = j;
        j++;
    }
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout << "vector               ACCESS:" << elapsed_secs << endl << endl;
    

    
    // ----------------------------------------------------------------
    // TEST 1: Random Access
    // list:  O(N)
    // vector O(1)
    // ----------------------------------------------------------------
    
    // ===================================================
    // PERFORMANCE (only 1 sample run)
    // ===================================================
    // MacBook 2.2 GHz Intel Core i7
    //
    // Input size N: 40000
    //
    // Doublely Linked List RANDOM ACCESS:25.1301
    // vector               RANDOM ACCESS:0.000485
    //
    // Summary: ~ 52,000x slower for linked lists
    // ===================================================
    
    
    print_example("TEST 2: Random Access ");
    
    vector<int> idx(N);
    for ( int i = 0; i < N; i++ ) {
        idx[i] = i;
    }
    
    random_shuffle(idx.begin(),idx.end());
    
    // random access in a list is *very* expensive
    begin = clock();
    j = 0;
    int k = 0;
    for(size_t i = 0; i < idx.size(); i++ ) {
        for( list_itr=dbls.begin(); list_itr != dbls.end(); list_itr++) {
        
            if( k == idx[i] ) {
                *list_itr = j;
            }
            ++k;
        }
        k = 0;
        j++;
    }
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout << "Doublely Linked List RANDOM ACCESS:" << elapsed_secs << endl;
    
    
    begin = clock();
    j = 0;
    for(size_t i = 0; i < idx.size(); i++ ) {

        vdbls[ idx[i] ] = j;
        j++;
    }
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout << "vector              RANDOM ACCESS:" << elapsed_secs << endl << endl;

    
    // ----------------------------------------------------------------
    // TEST 2: DELETION
    // random list of integers to remove
    // the list is *much* faster
    // ----------------------------------------------------------------
  
    // ===================================================
    // PERFORMANCE (only 1 sample run)
    // ===================================================
    // MacBook 2.2 GHz Intel Core i7
    //
    // Input size N: 40000
    //
    // Doublely Linked List REMOVE:0.004571
    // vector               REMOVE:0.235781
    //
    // Summary: ~ 52x *faster* for linked lists
    // ===================================================
    
    print_example("TEST 3: Deletion ");
    
    begin = clock();
    for(int i=0;i<N;i++)
    {
        dbls.pop_front();
    }
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout << "Doublely Linked List REMOVE:" << elapsed_secs << endl;
    
    // vector
    begin = clock();
    while(vdbls.size() > 0)
    {
        vdbls.erase(vdbls.begin()); //erase the front element
    }
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout << "vector               REMOVE:" << elapsed_secs << endl;
    
    
    
    
    //
    //
    // V. Queues
    //
    //
    
    print_section("V: Queues");
   
    
    // Queues don't permit access to random items in the container --
    // you can't even iterate over the contents of a queue. All queues
    // permit are adding an element to the rear and remove from the front,
    // as well as viewing the first and last value
    
    queue<double> q;
    for(int i=0;i<100;i++)
    {
        q.push(i);
    }
    
    cout << q.size() << endl;
    q.pop(); // this *destroys* the item at the front of the queue
    
    int front = q.front(),
        back = q.back();
    cout << front << " " << back << endl;

    
    return 0;
}

