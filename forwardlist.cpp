#include<iostream>
#define bool int
#define true 1
#define True 1
#define TRUE 1
#define False 0
#define FALSE 0
#define false 0
using namespace std;
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
class TMlist : public iterable
{
public:
virtual void add(  int data , bool *success)=0;
virtual void insert(int index, int data, bool *success)=0;
virtual void update(int index , int data, bool *success)=0;
virtual int get(int index , int *success) const=0;
virtual int getsize()const=0 ;
virtual int  remove(int index , int  *success)=0;
virtual  void removeall()=0;
virtual  void clear()=0;
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
class TMArraylistIterator : public Iterator 
{
int index;
int size;
int **ptr;
public:
TMArraylistIterator (int **ptr , int size)
{
this->size= size;
this->index = 0;
this->ptr = ptr;
}
TMArraylistIterator(const TMArraylistIterator &other)
{
this->index  = other.index;
}
TMArraylistIterator & operator=(const TMArraylistIterator  &other)
{
this->index = other.index;
return *this;
}

int hasmoreelement()
{
return index <size;
}
int next()
{
if(index == size) return 0;
int rowindex = index/10;
int columnindex = index%10;
int data = this->ptr[rowindex][columnindex];
index++;
return data;
}
};
Iterator getiterator()
{
TMArraylistIterator *tmArraylistiterator;
tmArraylistiterator =new TMArraylistIterator(this->ptr ,this->size);
Iterator k(tmArraylistiterator);
k.setReleaseIteratorAfterIteration(0);
return k;
}

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
if (buffersize%10!=0) rows++;
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
int TMArrayList :: get(int index , int *success) const
{
if(success) *success = false;
if( index<0 || index>=this->size) return 0;
int rowindex = index/10;
int columnindex = index%10;
if(success) *success = true;
return ptr[rowindex][columnindex];
}
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

int  TMArrayList:: remove( int index , int *success)
{
if(success) *success = false;
if(index<0 || index>=size) return 0;
bool succ;
int data = this->get(index, &succ);
int j;
int ep = this->size-2;
j =index;
while(j<=ep)
{
this->update(j, this->get(j+1 , &succ), &succ);
j++;
}
this->size--;
if(success) *success = true;
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
void TMForwardList:: add( int data , bool *success)
{
if(success) *success = false;
TMNode *t;
t= new TMNode;
if(t==NULL) return;
t->data = data;
if(this->start == NULL)
{
this->start = this->end=t;
}
else
{
this->end->next  = t; 
this->end = t;

}
if(success) *success = true;
this->size++;
}
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
TMForwardList ::TMForwardList(const TMForwardList &other)
{
this->start = NULL;
this->end = NULL;
this->size = 0;
this->allocationflag = 0;
int succ;
for(int e=0; e<other.getsize(); e++ )
{
this->add(other.get(e, &succ), &succ);
}
}
TMForwardList ::TMForwardList(const TMlist &other)
{
this->start = NULL;
this->end = NULL;
this->size = 0;
this->allocationflag = 0;
int succ;
for(int e=0; e<other.getsize(); e++ )
{
this->add(other.get(e, &succ), &succ);
}
}



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
for (int e = 0; e < other.getsize(); e++)
    this->add(other.get(e, &k), &k);
}

void TMForwardList :: operator+=(const TMlist &other)
{
int k;
for (int e = 0; e < other.getsize(); e++)
    this->add(other.get(e, &k), &k);
}

TMForwardList:: ~TMForwardList()
{
if(this->allocationflag == 0)
{
this->clear();
}
}
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


void  TMForwardList:: update(int index, int data , bool *success)
{
if(success) *success = false;
if(index<0 || index >= this->size) return;
TMNode *t;
int x;
t=this->start;
for( x=0; x<index; x++)
t=t->next;
t->data = data;
if(success) *success = true;
}


int  TMForwardList:: getsize() const
{
return this->size;
}
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
void TMForwardList:: removeall()
{
clear();
}
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

int main()
{
cout<<"------------------forward list ---------"<<endl;
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
cout<<"-------------------------------------------------------"<<endl;
cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;

cout<<"------------------Array list ---------"<<endl;
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
cout<<"-------------------------------------------------------"<<endl;
cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;

return 0;
}
