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
#include <queue>
#include <map>
#include <algorithm>
#include <iterator>
#include <ctime>

struct Monster
{
    std::string name;
    int xp;
    int hp;
    Monster() {}
    Monster(std::string name, int xp, int hp) : name(name), xp(xp), hp(hp) {}
    ~Monster() { std::cout << "------> " << name << " Monster Destructor" << std::endl; }
    
    friend std::ostream & operator<<(std::ostream & os, Monster & m )
    {
        os << "Monster:" << m.name;
        return os;
    }
};

// this typedef makes coding more elegant and readable
typedef std::multimap<const std::string, Monster> RoomMap;

int main(int argc, const char * argv[])
{
    using namespace std;
    
    // now boolean types with print out as true/false
    cout.setf(ios_base::boolalpha);
    
    //=================================================================
    //
    // II. ASSOCIATIVE CONTAINERS
    //
    //=================================================================
    
    // Associative containers are difference from sequence containers in
    // that they are used to store key/value relationships. There are
    // 2 types of assocaitive containers in the STL:
    
    // 1: Ordered
    // 2: Unordered
    
    // Ordered containers are stored using a tree data structure,
    // such as a binary search tree.
    
    // Unordered containers are stored using what's called a hash table.
    
    // ----------------------------------------------------------------
    // Set
    // ----------------------------------------------------------------
    
    // A set is the C++ equivilent of the mathematical definition of a set. A
    // set can contain only unqiue elements, so for a set the element is both
    // the key and the value.
    
    string names[5] = {"pat","jane","sue","bob","pat"};
    set<string> strset(names, names + 5);               // iterator constructor --remember names is just a pointer
    ostream_iterator<string> out(cout," ");             // ostream iterator (for printing to cout)
    
    // Note that when we print elements, there is only 1 "pat" in the set
    copy(strset.begin(),strset.end(),out);
    cout << endl << strset.size() << endl;
    cout << "========================================" << endl;
    
    // We can insert elements
    strset.insert("foo");
    copy(strset.begin(),strset.end(),out);
    cout << endl << strset.size() << endl;
    cout << "========================================" << endl;
    
    // and remove elements form a set
    strset.erase("jane");
    copy(strset.begin(),strset.end(),out);
    cout << endl << strset.size() << endl;
    cout << "========================================" << endl;
    
    // However, while can iterate over the contents of the set, all items contained
    // within the container are immutable (i.e., they *cannot* be changed.) Keys in
    // associative containers are always constant. With sets, keys are also values.
    set<string>::iterator itr;
    // *itr = "mutable???";  // COMPILE ERROR!
    
    // sets are implmented (typically) as a binary search tree, meaning that, on average,
    // finding a specific item in a set is faster than finding an item in a vector
    // O(log n) vs O(n)
    
    // How do we check if a particular element is part of a set?
    // We could manually iterate over the contents...
    string testcase = "pat";
    for(itr=strset.begin(); itr!=strset.end(); itr++)
    {
        if(*itr == testcase)
        {
            cout << "Using iterator -- set contains testcase: " << testcase << endl;
            break;
        }
    }
    
    // This is perfectly okay, but a lot of code. We'd hope there is a method
    // like "contains()" in the set STL definition, but no such luck.
    
    // We could use the inherited "count()" function, but is this a good idea?
    // No, because count will iterate through every item
    if(strset.count(testcase) !=0)
        cout << "Using count() -- set contains testcase: " << testcase << endl;
    
    // a common convention is to see if the find member function returns an
    // iterator that is equal to a pointer to the end of the container, i.e.,
    // the item wasn't found.
    bool contains = (strset.find(testcase) != strset.end());
    if(contains)
        cout << "STL convention: -- set contains testcase " << testcase << endl << endl;
    
    if(strset.find("foobar") != strset.end())
        cout << "STL convention: -- set contains foobar " << endl << endl;
    
    
    // Set Mathematical Operations
    
    // set difference, union, intersection
    
    set<int> A;
    for(int i=0;i<10;i++)
    {
        A.insert(i);
    }
    
    set<int> B;
    for(int i=7;i<15;i++)
    {
        B.insert(i);
    }
    
    set<int> C;
    for(int i=0;i<10;i++)
    {
        C.insert(i);
    }
    
    // print iterator for containers with integers
    ostream_iterator<int> intout(cout," ");
    
    cout << "Set A = { ";
    copy(A.begin(), A.end(), intout);
    cout << "}" << endl;
    
    cout << "Set B = { ";
    copy(B.begin(), B.end(), intout);
    cout << "}" << endl;
    
    cout << "Set C = { ";
    copy(C.begin(), C.end(), intout);
    cout << "}" << endl << endl;
    
    // set equality is defined
    cout << (A == B) << endl;
    cout << (A == A) << endl;
    cout << (A == C) << endl << endl;
    
    // the union of both sets A and B
    cout << "UNION (A,B)" << endl;
    set_union(A.begin(),A.end(), B.begin(), B.end(), intout);
    cout << endl << "----------------------------------------" << endl;
    
    // the intersection of A and B
    cout << "INTERSECTION (A,B)" << endl;
    set_intersection(A.begin(),A.end(), B.begin(), B.end(), intout);
    cout << endl << "----------------------------------------" << endl;
    
    // the difference of A and B
    cout << "DIFFERENCE (A,B)" << endl;
    set_difference(A.begin(),A.end(), B.begin(), B.end(), intout);
    cout << endl << "----------------------------------------" << endl;
    
    // the difference of B and A
    cout << "DIFFERENCE (B,A)" << endl;
    set_difference(B.begin(),B.end(), A.begin(), A.end(), intout);
    cout << endl << "----------------------------------------" << endl;
    
    // Remember, set difference is *not* commutative -- order matters!
    
    // operations can also copy items into a new container, but the syntax requires
    // an insert_iterator
    set<int> D;
    set_union(A.begin(),A.end(), B.begin(), B.end(), insert_iterator< set<int> >(D, D.begin()));
    
    cout << "Set D = {";
    copy(D.begin(), D.end(), intout);
    cout << "}" << endl << endl;
    
    // you can also use methods to determine upper and lower bounds
    // in relation to some key argument to extract ranges of set items
    cout << "Set D lower/upper bound range" << endl;
    copy( D.lower_bound(2), D.upper_bound(9), intout);
    cout << endl << "===========================================================" << endl;
    

    // ----------------------------------------------------------------
    // Map
    // ----------------------------------------------------------------
    
    // map objects are very similar to python's dictionary object. We must
    // have unqiue keys, but the data type of a key can be different
    // from the value data type
    
    map<const string,Monster> rooms;

    // We can insert items directly into the map object by creating
    // a templated pair instance
    pair<const string,Monster> zombie("throne room", Monster("Zombie",10,10));
    rooms.insert(zombie);
   
    // Or we can let map create such a pair for us and use index notation.
    // In order for this assignment syntax to work, you must have a
    // default constructor in your class or struct
    rooms["entrance"] = Monster("Goblin",10,10);
    rooms["hallway"] = Monster("Rat",1,1);
    rooms["cavern"] = Monster("Red Dragon",1000,1000);
    
    cout << "----------------------------------------" << endl;
    
    // we can iterate as usual through items with this iterator
    map<const string, Monster>::iterator mitr;
    for(mitr=rooms.begin(); mitr!=rooms.end(); mitr++)
    {
        // pair doesn't have an ostream definition, so we have to
        // use the public member variables first and second
        
        // Q: Why do we have to use the pointer-to-member operator here?
        cout << mitr->first << " contains a " << mitr->second << endl;
    }
    
    cout << "----------------------------------------" << endl;
    
    // we can re-assign a key value, which destroys whatever value
    // was originally assocaited with that key
    rooms["cavern"] = Monster("Dragon",100,100);
    
    // ----------------------------------------------------------------
    // Multimap
    // ----------------------------------------------------------------
    
    // multimap is similar to map , except it allows non-unique keys, meaning
    // multiple values can be associated with a single key
    multimap<const string,Monster> mrooms;
    
    // this, however, means we can no longer use the index operator since
    // its meaning would be ambiguous. All of the following will create
    // temporary copies of each instance which will be destroyed after assignment
    mrooms.insert( pair<const string,Monster>("throne room", Monster("Troll",100,1000)) );
    mrooms.insert( pair<const string,Monster>("throne room", Monster("Rat",1,1)) );
    mrooms.insert( pair<const string,Monster>("throne room", Monster("Red Dragon",1000,1000)) );
    mrooms.insert( pair<const string,Monster>("entrance", Monster("Goblin",10,10)) );
    mrooms.insert( pair<const string,Monster>("entrance", Monster("Goblin",10,10)) );
    mrooms.insert( pair<const string,Monster>("entrance", Monster("Rat",1,1)) );
    
    cout << "----------------------------------------" << endl;
    
    // we can count the number of a particular type of *key* in the multimap
    cout << "There are " << mrooms.count("throne room") << " creatures in the throne room" << endl;
    cout << "There are " << mrooms.count("entrance") << " creatures in the entrance" << endl;
    cout << "There are " << mrooms.count("void") << " creatures in the void" << endl;
    
    cout << "----------------------------------------" << endl;
    
    // or restrict an action to a specific key value using this slightly cumbersome syntax that
    // defines a pair of iterators. The equal range allows us to iterate only over the portion
    // of the multimap that matches our range key value
    pair< multimap<const string,Monster>::iterator, multimap<const string,Monster>::iterator> range;
    range = mrooms.equal_range("throne room");
    
    // a multimap iterator
    multimap<const string,Monster>::iterator mm_itr;
    for(mm_itr = range.first; mm_itr != range.second; ++mm_itr)
    {
        cout << mm_itr->first << " contains a " << mm_itr->second << endl;
    }
    
    cout << "----------------------------------------" << endl;
    
    // Code like the above is better served by using a typedef to create a more compact
    // notion for the iterator pair. The code is otherwise the same.
    pair<RoomMap::iterator, RoomMap::iterator> elegant = mrooms.equal_range("throne room");
    
    for(mm_itr = elegant.first; mm_itr != elegant.second; ++mm_itr)
    {
        cout << mm_itr->first << " contains a " << mm_itr->second << endl;
    }
    
    cout << "----------------------------------------" << endl;
    
    
    // ----------------------------------------------------------------
    // Unordered containers
    // ----------------------------------------------------------------
    
    // All of the above container types have unordered versions
    
    // unordered_set
    // unordered_multiset
    // unordered_map
    // unordered_multimap
    
    // The difference between these and the ordered variants is how data is stored in the
    // data structure. Using a hash instead of a tree results in faster access time, since
    // finding an element takes constant time O(1) instead of logarithmic time O(log n)
    
    // More information on these containers can be found in Appendix G
    
    return 0;
}

