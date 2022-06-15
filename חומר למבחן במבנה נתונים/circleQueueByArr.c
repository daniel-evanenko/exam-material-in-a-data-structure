#include <stdio.h>
#include <stdbool.h>
#define N 6 // for 5 places
int START = 0;
int END = 0;
bool isEmpty();
bool insert(int num);
int Remove();
int peek();
bool isFull();
int tor[N];
bool isEmpty()
{
    if(START == END)
        return true;
    else
        return false;
}
bool insert(int num)
{
    if(!isFull())
    {
        tor[END] = num;
        END = (END+1)%N;
        return true;
    }
    return false;
}
int Remove()
{
    if(!isEmpty())
    {
        int val = tor[START];
        START = (START+1)%N;
        return val;
    }
    return -1;
}
int peek()
{
    if(!isEmpty())
        return tor[START];
}

bool isFull()
{
    if((END+1)%N == START) // full
        return true;
    return false;
}


