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


 ## CODE


* [Macros](#macros)
* [Iterator-Class](#iterator-class) 
    
## Macros 
***
### Description  :

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

## Iterator 

   
* To 'create' Iterator
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
   ```
