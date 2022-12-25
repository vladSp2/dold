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

void
func (uint24_t counter)
{
  auto main_counter = counter_;
                        //--counter
  if (main_counter++ == counter)
    work_deque.push_front(counter);
  else
    work_deque.push_back(counter);
                                    //объединить обработку 13 и 41 в одну ф-цию?
                                    //counter_ == work_deque.front().counter-1
  while (!work_deque.empty () && main_counter == work_deque.front())
    {
        //counter_ = work_deque[0].counter;
        counter_++;
        main_counter++;
        
        cout << "send: " << work_deque.front() << endl;
        work_deque.pop_front();
    }


}

int main ()
{
  uint24_t counter[] = { 0x1, 0x2, 0x3, 0x5, 0x4, 0x6 };
  for (int i = 0; i <= 5; i++)
    {
      func (counter[i]);
    }

  for (size_t i = 0; i != work_deque.size (); ++i)
    cout << work_deque[i];

  return 0;
}
