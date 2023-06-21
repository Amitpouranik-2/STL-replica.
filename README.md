# DOCUMENTATION

## STL-Replica
The `REPLICA OF STANDARD TEMPLETE LIBRARY (STL)` using the technology `C++`. `STL` is the library present in the `C++` technology. It is a library that is making easy the life of millions of software developers or the workers of the IT (Information Technology) industries. As we all know that C++ technology is just a wrapper of C technology (language). The employees or workers had been facing lots of problems during the old days while working on the C technology because this technology doesn’t have any collection of in-built functions. 

## About STL

Let us discuss some overview about the `STL`. `STL` stands for Standard Template Library. This library is very useful and helpful for the new generation programmers. This library provides a lot of convenience and efficiency to the IT industry’s workers. This library is very friendly because before `C++`, there was the language C, that is hard to make the programmers understood the code.

* Even C++ is the wrapper over the C programming language, but `C++` provides us several libraries containing in-built functions that are common in use or the functions that are required almost in every scenario. STL is one of those libraries in `C++`.

*  Talking about `C`, there are no such facilities of in-built functions there, so each and every code is written by us and that become so time and money consuming. 

* By that the `STL` turned out to be very friendly for the users as we don’t have to remember too many codes as well along with it we do not have to waste our time and money on writing each and every code.

* The reason discussed above is responsible for the sudden demand of C++ programming language in the market of IT industries. STL provides some standard in built functions for providing convenience and efficiency for the programming world. These in-built functions are helpful in every scenarios or circumstances.

So here is clearly specified that the `STL (Standard Template Library)` is also wrapping the basic DATA STRUCTURES that are required in almost every programming 
approach. STL provides STACK, QUEUE  etc. ,so it is auto understood that how much C++ programming language or technology along with STL is providing a big 
support to the developers (developers related to the IT industry).

There are many functionalities provided by STL that made the life of people convenient. These functionalities also helped us to get better version of 
programming languages in future.

* STL provides a collection of templates representing containers, iterators, algorithms and function objects.

  1. An iterator (a generalization of pointer) is an object that lets you transverse through elements of a container, 
     e.g., vector<int>::iterator, list<string>::iterator.
  2. Algorithms are used for tasks such as searching, sorting and comparison, e.g., for_each, find, sort.
  3. Function objects are objects that act like futions.

## MY STL

It is very difficult / complex to provide all the features / functionalities that are provided in the Standard Template Library (STL) at individual level. In MY STL i.e.my project (Replica of Standard Template Library) I am providing some of the functionalities of STL. 

Some of the functionalities provided in STL are:

1. array
2. forward_list
3. list
4. vector
5. priority_queue
6. stack
7. queue
8. map
9. multimap
and many more…

* Taking array class as a guidance I have created a class named `TMArrayList` which is used to store multiple values in a single variables for each value.

* Taking forward_list class of STL as a guidance I have created a class named `TMForwardList`. Alike forward_list, it implements Singly Linked List. It supports fast insertion and retrieval of elements from anywhere in the list.

## TM LIST



  ```c
       class TMlist
       {
       public:
       virtual void add(  int data , bool *success)=0;
       virtual void insert(int index, int data, bool *success)=0;
       virtual void update(int index , int data, bool *success)=0;
       virtual int get(int index , int *success) const=0;
       virtual int getsize()const=0 ;
       virtual int  remove(int index , int  *success)=0;
       virtual void removeall()=0;
       virtual void clear()=0;
       };

  ```
  





## Array List

     ✅` Link Below `👇
* [Macros](#macros)
* [Iterator](#iterators)

    
***
### Macros
* To `create` Macros
   ```c
    #define bool int
    #define true 1
    #define True 1
    #define TRUE 1
    #define False 0
    #define FALSE 0
    #define false 0
   ```
   
### Iterators
    
* To `create` Iterator
    

    ```c
     class Iterator
     {
     private:
     int ReleaseIteratorAfterIteration;
     Iterator *iterator;
     public:
     Iterator()
     {
     this->ReleaseIteratorAfterIteration=1;
     this->iterator = NULL;
     }
     Iterator( Iterator *iterator)
     {
     this->ReleaseIteratorAfterIteration=1;
     this->iterator = iterator;
     }
     Iterator(const Iterator &other)
     {
     this->ReleaseIteratorAfterIteration=1;
     this->iterator = other.iterator;
     } 
     virtual ~Iterator()
     { 
    if(this->ReleaseIteratorAfterIteration=1) delete this->iterator;
     }

    void  setReleaseIteratorAfterIteration(int ReleaseIteratorAfterIteration)
     {
    this->ReleaseIteratorAfterIteration = ReleaseIteratorAfterIteration;
    }

    Iterator & operator=(const Iterator &other)
    {
    this->iterator = other.iterator;
    return *this;
    } 

    virtual int hasmoreelement()
    {
    if(iterator!=NULL) return this->iterator->hasmoreelement();
    return 0;
     }

    virtual int next()
    {
    if(iterator!=NULL) return  this->iterator->next();
    return 0;
    }
    };

    class iterable
    {
    public:
    virtual Iterator getiterator()=0;
    };




class TMArrayList : public TMlist
{
private:
char allocationFlag; 
int **ptr;
int capacity;
int size;
int addrow();



public:
TMArrayList();
TMArrayList(int buffersize);
TMArrayList(const TMArrayList &other);
TMArrayList(const TMlist &other);
TMArrayList & operator=(const TMArrayList &other);
TMArrayList & operator=(const TMlist &other);
TMArrayList  operator+(const TMArrayList &other);
TMArrayList  operator+(const TMlist &other);
void  operator+=(const TMArrayList &other);
void  operator+=(const TMlist &other);
virtual ~TMArrayList();
void add( int data , bool *success);
void insert(int index , int data , bool *success);
void update(int index, int data , bool *success);
int  get(int index , int *success)const;
int getsize() const ;
void clear();
void removeall();
int remove(int index , int *success);
};

   
  

* To `get size` of Singly Linked List
  ```c
  int getsizeofSinglylinkedlist(Singlylinkedlist *singlylinkedlist);
  ```
  `int size;`  
  `size=getsizeofSinglylinkedlist(list);`  
* To `get an element` from Singly Linked List  
  ```c
  void * getfromSinglylinkedlist(Singlylinkedlist *singlylinkedlist,int index,bool *success);
  ```
  `bool success;`  
  `void * ptr;`  
  `int index;`  
  `ptr=getfromSinglylinkedlist(list,index,&success);`  
  if(`success==true`) element is received in ptr.  
  if(`success==false`) element is not received int ptr.  

* To `merge one list into another list` of Singly Linked List  
  ```c
  void appendtoSinglylinkedlist(Singlylinkedlist *targetSinglylinkedlist,Singlylinkedlist * sourceSinglylinkedlist,bool *success);
  ```
  we have `list_1` and `list_2` of Singlylinkedlist.  
  for merging `list_1` into `list_2`.  
  `bool success;`   
  `appendtoSinglylinkedlist(list_1,list_2,&success);`  
  if(`success==true`) lists are merged.  
  if(`success==false`) lists are not merged.  

* To `clear` the Singly Linked List  
  ```c
  void clearSinglylinkedlist(Singlylinkedlist *singlylinkedlist);
  ```
  use to free (remove) nodes of list (size of list is zero).  
  `clearSinglylinkedlist(list);`  
* To `delete/destroy` the Singly Linked List    
  ```c
  void destroySinglylinkedlist(Singlylinkedlist *singlylinkedlist);
  ```
  use to delete the list.  
  `destroySinglylinkedlist(list);`  
  ***  




