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

   *  [Macros](#macros-)
   *  [Iterator Class](#iterator-class)
   *  [TMLIST ( ABSTRACT CLASS)](#tmlist)

 
 
## Array List 

 * [ Array List Class](#array-list)  
   * [ Add Row ](#add-row)
   * [ Add Function](#add)  
   * [ Get Function](#get)  
   * [ Insert Function](#insert)  
   * [ Update Function](#update)
   * [ GET Size Function](#get-size)
   * [ Remove All Function](#remove-all)
   * [ Operators](#operators)  
   * [Internal Structure Of Array List](#internal-structure-of-array-list)  

     
 ## Forward List 
   
   * [ Forward List Class](#forward-list)  
     * [ Add Row ](#add-row) 
     * [ Add Function](#add)  
     * [ Get Function](#get)  
     * [ Insert Function](#insert)  
     * [ Update Function](#update)
     * [ GET Size Function](#get-size)
     * [ Remove All Function](#remove-all)
     * [Remove Function](#remove)
     * [ Operators](#operators)  
     * [Internal Structure Of Forward List](#internal-structure-of-forward-list)  

   
 ## TestCases 
   
  * [ Array List Testcase ](#array-list-testcase) 
  * [ Forward List Testcase ](#forward-list-testcase)  
     
   












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

  
  ##  Insert 
    
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

  ## Update  
    
  * To `update` element in Array List
   ```c

     void TMArrayList :: update( int index , int data , bool *success)
     {
     if(success) *success = false;
     if(index<0 || index>=size) return ;
     int rowindex = index/10;
     int columnindex = index%10;
     this->ptr[rowindex][columnindex] = data;
     if(success) *success = true;
     }
   ```


  ## Get Size  
    
  * To `get Size`  of element in Array List
   ```c

     int TMArrayList :: getsize()const
      {
      return this->size;
      }

  ```


  ## Remove All  
    
  * To ` remove ` all element from Array List
   ```c
    void  TMArrayList :: removeall()
    {
    this->size = 0;
    }

    ```


## Operators  
    
   ```c

   // Construtor 

   
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

      // Destructor
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

   ```



## Internal Structure Of Array List 


  ![Picture1](https://github.com/Amitpouranik-2/STL-replica./assets/109301830/a651e4ed-3c80-4773-af69-da38313d204b)




## Forward List   
***
### Description of Forward List functions :

* To `create` ForwardList Class
   ```c
     class TMForwardList : public TMlist
      {
      class TMNode
      {
      public:
      int data;
      TMNode *next;
      TMNode()
      {
      this->next = NULL;
      }
      };
      private:
      char  allocationflag;
      TMNode *start, *end;
      int size;
      public:
      class TMForwardlistIterator : public Iterator 
      {
      TMNode *ptr;
      public:
      TMForwardlistIterator()
      {
      this->ptr = NULL;
      }
   
      TMForwardlistIterator(TMNode *ptr)
      {
      this->ptr = ptr;
      }
   
      TMForwardlistIterator(const TMForwardlistIterator &other)
      {  
      this->ptr = other.ptr;
      }

      TMForwardlistIterator & operator=(const TMForwardlistIterator  &other)
      {
      this->ptr = other.ptr;
      return *this;
      }

      int hasmoreelement()
      {
      return this->ptr!= NULL; 
      }


      int next()
      {
      if(this->ptr==NULL) return 0;
      int data = this->ptr->data;
      this->ptr = this->ptr->next;
      return data;
      }
      };

      public:
      Iterator getiterator()
      { 
      TMForwardlistIterator *tmforwardlistiterator;
      tmforwardlistiterator =new TMForwardlistIterator(this->start);
      Iterator k(tmforwardlistiterator);
      k.setReleaseIteratorAfterIteration(0);
      return k;
      }

      TMForwardList();
      TMForwardList(int buffersize);
      TMForwardList(const TMForwardList &other);
      TMForwardList(const TMlist &other);
      TMForwardList & operator=(const TMForwardList &other);
      TMForwardList & operator=(const TMlist &other);
      TMForwardList operator+(const TMForwardList &other);
      TMForwardList operator+(const TMlist &other);
      void  operator+=(const TMForwardList &other);
      void  operator+=(const TMlist &other);
      virtual ~TMForwardList();
      void add( int data , bool *success);
      void insert(int index , int data , bool *success);
      void update(int index, int data , bool *success);
      int  get(int index , int *success)const;
      int getsize()const ;
      void clear();
      void removeall();
      int remove(int index , int *success);
      };
     

    ```
## Add Row 
   

* To `add row `  in Forward List
  ```c
   
    TMForwardList::TMForwardList()
    {
    this->start = NULL;
    this->end = NULL;
    this->size = 0;
    this->allocationflag =0;
    }
  
   TMForwardList::TMForwardList(int buffersize)
   {
   this->start = NULL;
   this->end = NULL;
   this->size =0;
   this->allocationflag=0;
   }
    

    ```




## Get 
    
* To `get` element from Forward List
   ```c
     int  TMForwardList:: get(int index , int *success)const
     {
     if(success ) *success = false;
     if(index< 0 || index > this->size) return 0;
     TMNode *t;
     int x;
     t = this->start;
     for(x=0; x<index; x++) t= t->next;
     if(success) *success = true;
     return t->data; 
     }

   ```

  
##  Insert 
    
* To `insert` element in Forward List
   ```c

    void TMForwardList:: insert(int index , int data , bool *success)
    {
    if(success) *success = false;
    if(index<0 || index > this->size) return ;
    if(index == this->size)
    {
    this->add(data, success);
    return;
    }
    TMNode *gg;
    gg = new TMNode; 
    if(gg== NULL) return;
    gg->data =data;
    int x;
    TMNode *t, *j;
    t=this->start;
    for(x=0; x<index; x++)
    {
    j=t;
    t=t->next;
    }
    if(t== this->start)
    {
    gg->next = this->start;
    this->start = gg;
    }
    else
    {
    gg->next = t;
    j->next= gg;
    }
    this->size++;
    if(success) *success = true;
    }

      
   ```

## Update  
    
  * To `update` element in Forward List
   ```c
      void  TMForwardList:: update(int index, int data , bool *success)
      { 
      if(success) *success = false;
      if(index<0 || index >= this->size) return;
      TMNode *t;
      int x;
      t=this->start;
      for( x=0; x<index; x++ ) t=t->next;
      t->data = data;
      if(success) *success = true;
      }

   ```
 

  ## Get Size  
    
  * To `get Size`  of element in Forward List
   ```c
      int  TMForwardList:: getsize() const
      {
      return this->size;
      }

  ```


  ## Clear  
    
   * To ` clear` all element from Forward List
   ```c
      void  TMForwardList:: clear()
      {
      TMNode *t;
      while(this->start!=NULL)
      {
      t= this->start;
      this->start = this->start->next;
      delete t;
      } 
      this->end= NULL;
      this->size= 0;
      }

    
        
  ```




## Remove  
    
  * To ` remove`  element from Forward List
    ```c
      int TMForwardList::remove(int index, int *success)
      {
      int data =0;
      if(success) *success = false;
      if(index<0 || index>=this->size) return data ;
      TMNode *t, *j;
      int x;
      t=this->start;
      for(x=0; x<=index; x++)
      {
      j=t;
      t=t->next;
      }
      data = t->data;
      if(t==this->start && t==this->end)
      {
      this->start = this->end = NULL;
      }
      else if(t==this->start)
      {
      this->start = this->start->next;
      }
      else if(t== this->end)
      {
      j->next= NULL;
      this->end = j;
      }
      else
      {
      j->next =t->next;
      }
      this->size--;
      delete t;
      if(success) *success = true;
      return data;
      }

      
    
       
      ```

 
 ## Operators  
     
   ```c
       TMForwardList  & TMForwardList::  operator=(const TMForwardList &other)
       {
       this->clear();
       if(other.allocationflag == 1)
       { 
       this->size = other.size;
       this->start = other.start;
       this->end = other.end;
       }
       else
       {
       int succ;
       for(int e=0; e<other.getsize(); e++)
       {
       this->add(other.get(e, &succ), &succ);
       }
       }
       return *this;
       }

       TMForwardList  & TMForwardList::  operator=(const TMlist &other)
       { 
       this->clear();
       int succ;
       for(int e=0; e<other.getsize(); e++)
       {
       this->add(other.get(e, &succ), &succ);
       }
       return *this;
       }


      TMForwardList TMForwardList ::operator+(const TMForwardList &other)
      {
      TMForwardList k;
      k+=(*this);
      k+=other;
      return  k;
      }

      TMForwardList TMForwardList ::operator+(const TMlist &other)
      {
      TMForwardList k;
      k+=(*this);
      k+=other;
      return  k;
      }



      void TMForwardList :: operator+=(const TMForwardList &other)
      {
      int k;
      for (int e = 0; e < other.getsize(); e++) this->add(other.get(e, &k), &k);
      }

      void TMForwardList :: operator+=(const TMlist &other)
      {
      int k;
      for (int e = 0; e < other.getsize(); e++) this->add(other.get(e, &k), &k);
      }

      TMForwardList:: ~TMForwardList()
      {
      if(this->allocationflag == 0)
      {
      this->clear();
      }
      }


   

   ```



## Internal Structure Of Forward List 

  ![Picture2](https://github.com/Amitpouranik-2/STL-replica./assets/109301830/eeda6741-f433-4d41-8514-c6f86a116fe7)


##Testcases

  
## Array List Testcase  
    
   ```c
    int main ()
    {
    TMArrayList list2;

    list2.add(100,&k);
    list2.add(200,&k);
    list2.add(2200,&k);
    list2.add(3100,&k);
    list2.add(3300,&k);
    list2.add(13300,&k);
    cout<<"bbbbb"<<endl;
    iterator1=list2.getiterator();
    iterator2=list2.getiterator();
    cout<<"aaaaaa"<<endl;
    iterator3=list2.getiterator();
    cout<<iterator1.next()<<endl;
    cout<<iterator2.next()<<endl;
    cout<<iterator3.next()<<endl;
    cout<<iterator1.next()<<endl;
    cout<<iterator2.next()<<endl;
    cout<<iterator3.next()<<endl;
    return 0;
    }

    
        
  ```
 


## Forward List Testcase  
    
   ```c
   int main()
   {
   TMForwardList list1;
   int  k;
   list1.add(100,&k);
   list1.add(200,&k);
   list1.add(2200,&k);
   list1.add(3100,&k);
   list1.add(3300,&k);
   list1.add(13300,&k);
   Iterator iterator1=list1.getiterator();
   Iterator iterator2=list1.getiterator();
   Iterator iterator3=list1.getiterator();

   cout<<iterator1.next()<<endl;
   cout<<iterator2.next()<<endl;
   cout<<iterator3.next()<<endl;
   cout<<iterator1.next()<<endl;
   cout<<iterator2.next()<<endl;
   cout<<iterator3.next()<<endl;
    
    
        
  ```

