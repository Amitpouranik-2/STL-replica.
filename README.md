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

 
## Array List 

 *  [Macros](#macros-)
 *  [Iterator Class](#iterator-class)
 *  [TMLIST ( ABSTRACT CLASS)](#tmlist)
 * [ Array List Class](#array-list)  
   * [ Add Row ](#add-row)
   * [ Add Function](#add)  

   












## Macros :

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
## Iterator Class
   
* To 'add' Iterator Class in  Array List
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


    // Iterable Class 
   class iterable
   {
   public:
   virtual Iterator getiterator()=0;
   };

  ```

## TMLIST  


* To `create` Abstract Class TMList
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
***
### Description of Array List functions :

* To `create` ArrayList Class
   ```c
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


    ```

## Add Row 
   

* To `add row `  in Array List
  ```c
    bool TMArrayList :: addrow()
    {
    if(capacity%100 == 0)
    {
    int numberofpointers;
    numberofpointers = this->capacity/10;
    int **tmp = new int *[numberofpointers+10];
    if(tmp == NULL) return false;
    for(int e=0; e<numberofpointers; e++)tmp[e] = this->ptr[e];
    delete []this -> ptr;
    this-> ptr = tmp;
    }
    int i =this->capacity/10;
    this->ptr[i] = new int[10];
    if(this->ptr[i]== NULL) return false;
    this->capacity = this->capacity +10;
    return true;
    }

     // CONSTRUCTOR

    
    TMArrayList :: TMArrayList()
    {
    this->ptr = new int *[10];
    this->ptr[0] = new int[10];
    this->capacity = 10;
    this->size = 0;
    this->allocationFlag = 0;
    }
    
    TMArrayList :: TMArrayList(int buffersize)
    {
    this->allocationFlag = 0;
    if(buffersize<=0)
    { 
    this->ptr = new int *[10];
    this->ptr[0]= new int[10];
    this->capacity = 10;
    this->size = 0;
    }
    else 
    {
    int rows;
    int numberofpointers;
    rows = buffersize/10;
    if(buffersize%10!=0) rows++;
    numberofpointers = rows +(10 -(rows%10));
    this->ptr = new int*[numberofpointers];
    for(int e=0 ; e<rows ; e++)
    {
    this->ptr[e] = new int[10];
    }
    this->capacity  = rows *10;
    this->size = 0;
     }
     }


    ```


  ## Add 
    
  * To `add` element in Array List
   ```c
     void TMArrayList :: add(int data, bool *success) 
     {
     if(success) *success=false;
     if(this->size == this->capacity)
     {
     if(!addrow()) return ;
     }
     int rowindex , columnindex;
     rowindex = this->size/10;
     columnindex = this->size%10;
     this->ptr[rowindex][columnindex]= data;
     this->size++;
     if(success) *success = true;
      }

     
     TMArrayList ::TMArrayList(const TMArrayList &other)
     {
     this->allocationFlag = 0;
     int buffersize = other.size;
     if(buffersize<=0)
     {
     this->ptr = new int*[10];
     this->ptr[0] = new int[10];
     this->capacity = 10;
     this->size = 0;
     }
     else
     {
     int rows;
     int numberofpointers;
     rows = buffersize/10;
     if(buffersize%10!=0) rows++;
     numberofpointers = rows + (10 - (rows % 10));
     this->ptr = new int *[numberofpointers];
     for (int e = 0; e < rows; e++)
     {
     this->ptr[e] = new int[10];
     }
     this->capacity = rows*10;
     this->size = 0;
     }
     int succ;
     for(int e=0; e<other.size; e++)
     {
     this->add(other.get(e, &succ) ,&succ);
     }
     }


    
     ```

  ## Get 
    
  * To `get` element from Array List
   ```c

     int TMArrayList :: get(int index , int *success) const
     {
     if(success) *success = false;
     if( index<0 || index>=this->size) return 0;
     int rowindex = index/10;
     int columnindex = index%10;
     if(success) *success = true; 
     return ptr[rowindex][columnindex];
     }

  ```


   ## Insert 
    
  * To `insert` element in Array List
   ```c
      void TMArrayList:: insert(int index , int data , bool *success)
      {
      if(success) *success = false;
      if(index < 0 || index>this->size) return;
      if(index == this->size)
      {
      this->add(data , success);
      return;
      }
      bool succ;
      int k = this->get(this->size-1 , &succ);
      this->add(k ,&succ);
      if(succ== false);
      int j;
      j = this->size-3;
      while(j>=index)
      {
      this->update(j+1, this->get(j,&succ), &succ);
      j--;
       }
      this->update(index ,data, &succ);
     
      if(success )  *success = true;
      }
     

  ```

 ## Insert 
    
  * To `insert` element in Array List
   ```c
   

   
 
TMArrayList:: TMArrayList(const TMlist &other)
{
this->ptr= new int*[10];
this->ptr[0] = new int[10];
this->capacity = 0;
this->size =0;
this->allocationFlag = 0;
int e;
int succ;
for(e=0; e<other.getsize(); e++)
{
this->add(other.get(e, &succ), &succ);
}
} 
TMArrayList:: ~TMArrayList()
{
if(this->allocationFlag == 0)
{
int rows = this->capacity/10;
int j;
for(j=0; j<rows; j++)
{
delete [] this->ptr[j];
}
delete[] this->ptr;
}
}


TMArrayList & TMArrayList :: operator=(const TMArrayList &other)
{
if(this->allocationFlag == 0)
{
this->size = 0;
int succ;
for(int e=0; e<other.size; e++)
{
this->add(other.get(e,&succ),&succ);
}
}
else
{
int rows = this->capacity/10;
int j;
for(j=0; j<rows; j++)
{
delete [] this->ptr[j];
}
delete[] this->ptr;
this->ptr = other.ptr;
this->capacity = other.capacity;
this->size = other.size;
}
return *this;
}



TMArrayList & TMArrayList :: operator=(const TMlist &other)
{
this->size = 0;
int e;
int succ;
for(e=0; e<other.getsize(); e++)
{
this->add(other.get(e ,&succ), &succ);
}
return *this;
}

void  TMArrayList :: operator+=(const TMArrayList &other)
{
int succ;
for(int e=0; e<other.size; e++)
{
this->add(other.get(e,&succ),&succ);
}
}


void  TMArrayList :: operator+=(const TMlist &other)
{
int succ;
int e;
for(e=0; e<other.getsize(); e++)
{
this->add(other.get(e,&succ), &succ);
}
}


TMArrayList   TMArrayList :: operator+(const  TMArrayList &other)
{
TMArrayList k;
int succ ;
for(int e=0; e<this->size; e++) k.add(this->get(e, &succ), &succ);
for(int e=0; e<other.size; e++) k.add(other.get(e,&succ) ,&succ);
return k;
}


TMArrayList   TMArrayList :: operator+(const  TMlist &other)
{
TMArrayList k;
int succ ;
for(int e=0; e<this->size; e++) k.add(this->get(e, &succ), &succ);
for(int e=0; e<other.getsize(); e++) k.add(other.get(e,&succ) ,&succ);
return k;
}




void TMArrayList :: update( int index , int data , bool *success)
{
if(success) *success = false;
if(index<0 || index>=size) return ;
int rowindex = index/10;
int columnindex = index%10;
this->ptr[rowindex][columnindex] = data;
if(success) *success = true;
}


int TMArrayList :: getsize()const
{
return this->size;
}

void   TMArrayList :: clear()
{
this->size =0;
}

void  TMArrayList :: removeall()
{
 this->size = 0;
}


