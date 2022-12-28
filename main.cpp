/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>
#include "main.h"
#include <deque>
#include <netinet/in.h>
using namespace std;

deque < uint24_t > work_deque;

uint24_t counter_;

#define MAX_ITER 10
uint8_t iter_counter = 0;

void
func (uint24_t counter)
{
    
  
  if(iter_counter == MAX_ITER){
    counter_++;
    iter_counter = 0;
    
  }
  
  //нужен ли он?
  uint24_t wait_couter = counter_ + 1;
  
  if (wait_couter == counter)
    work_deque.push_front(counter);
  else if(counter > wait_couter || wait_couter != 0)
    work_deque.push_back(counter);
  else
    cout << "error" << endl;
    

  while (!work_deque.empty () && wait_couter == work_deque.front())
    {
        counter_ = work_deque.front();
        wait_couter = counter_+1;
    
        //функция обработки
        cout << "send: " << work_deque.front() << endl;
        
        
        work_deque.pop_front();
        iter_counter = 0;
    }
    

    if(!work_deque.empty()){
        auto itr = find(work_deque.begin(), work_deque.end(), wait_couter);
        if(itr != work_deque.end()){
        
            ///поставить найденный элемент в начало
            work_deque.push_front(*itr);
            work_deque.erase(itr);
        }
    }
    
    iter_counter++;

}


int main ()
{
  uint24_t counter[] = { 0xffffff ,0x000001,0x000002, 0x000003, 0x000005, 0x000006, 0x000007,
                        0x000009, 0x00000c, 0x00000a, 0x00000b, 0x000008, 0x000004, 
                        0x00000d,0x00000e,0x00000f,0x000010,0x000011};

  counter_ = counter[0];
  cout << "send: " << counter[0] << endl;
  
  for (int i = 1; i < 18; i++)
    {
      func (counter[i]);
    }

    for (size_t i = 0; i != work_deque.size (); ++i)
        cout << work_deque[i] <<endl;

  return 0;
}
