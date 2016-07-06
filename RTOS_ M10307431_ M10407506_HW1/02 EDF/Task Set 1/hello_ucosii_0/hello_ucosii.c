/*************************************************************************
* Copyright (c) 2004 Altera Corporation, San Jose, California, USA.      *
* All rights reserved. All use of this software and documentation is     *
* subject to the License Agreement located at the end of this file below.*
**************************************************************************
* Description:                                                           *
* The following is a simple hello world program running MicroC/OS-II.The * 
* purpose of the design is to be a very simple application that just     *
* demonstrates MicroC/OS-II running on NIOS II.The design doesn't account*
* for issues such as checking system call return codes. etc.             *
*                                                                        *
* Requirements:                                                          *
*   -Supported Example Hardware Platforms                                *
*     Standard                                                           *
*     Full Featured                                                      *
*     Low Cost                                                           *
*   -Supported Development Boards                                        *
*     Nios II Development Board, Stratix II Edition                      *
*     Nios Development Board, Stratix Professional Edition               *
*     Nios Development Board, Stratix Edition                            *
*     Nios Development Board, Cyclone Edition                            *
*   -System Library Settings                                             *
*     RTOS Type - MicroC/OS-II                                           *
*     Periodic System Timer                                              *
*   -Know Issues                                                         *
*     If this design is run on the ISS, terminal output will take several*
*     minutes per iteration.                                             *
**************************************************************************/


#include <stdio.h>
#include "includes.h"
#include "system.h"
/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK    task1_stk[TASK_STACKSIZE];
OS_STK    task2_stk[TASK_STACKSIZE];
OS_STK    task3_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      1
#define TASK2_PRIORITY      2
#define TASK3_PRIORITY      3

typedef struct {
    int exec;
    int period;
}task;

void task1(task* pdata)
{
  int start = 0;
  int end;
  int delay;
  OSTCBCur->NoJob = 0;
  OSTCBCur->Period = pdata->period;
  OSTCBCur->Exec = pdata->exec;
  OSTCBCur->ExecTime = pdata->exec;
  OSTCBCur->Start = 0;
  OSTCBCur->Deadline = pdata->period;
  while (1)
  { 
    
    while(OSTCBCur->ExecTime){}
    
    end = OSTimeGet();
    if(end != OSTCBCur->Deadline-OSTCBCur->Period) {    // if finish time = deadline
        delay = pdata->period - (end-start);            // let it delay 1 timetick to avoid running the while loop
    }
    else
        delay =1;
    OSTCBCur->Resp = end-start;
    start += pdata->period; 
    OSTimeDly(delay);
    
  }
}

void task2(task* pdata)
{
  int start = 0;
  int end;
  int delay;
  OSTCBCur->NoJob = 0;
  OSTCBCur->Period = pdata->period;
  OSTCBCur->Exec = pdata->exec;
  OSTCBCur->ExecTime = pdata->exec;
  OSTCBCur->Start = 0;
  OSTCBCur->Deadline = pdata->period;
  while (1)
  { 
    
    while(OSTCBCur->ExecTime){}
    
    end = OSTimeGet();
    if(end != OSTCBCur->Deadline-OSTCBCur->Period) {    // if finish time = deadline
        delay = pdata->period - (end-start);            // let it delay 1 timetick to avoid running the while loop
    }
    else
        delay =1;
    OSTCBCur->Resp = end-start;
    start += pdata->period; 
    OSTimeDly(delay);
    
  }
}

/* The main function creates two task and starts multi-tasking */
int main(void)
{
  task t1 = {1,3};
  task t2 = {3,7};


  OSInit();
  OSTaskCreateExt(task1,
                  &t1,
                  (void *)&task1_stk[TASK_STACKSIZE-1],
                  TASK1_PRIORITY,
                  TASK1_PRIORITY,
                  task1_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
              
               
  OSTaskCreateExt(task2,
                  &t2,
                  (void *)&task2_stk[TASK_STACKSIZE-1],
                  TASK2_PRIORITY,
                  TASK2_PRIORITY,
                  task2_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
                  

                  
  printf("================= EDF Task Set 1 { t1(1,3) , t2(3,7) }========================\n");
  printf("------------------------------------------------------------------------------\n");
  printf("Current Time     Event       From Task ID        To Task ID      Response Time\n");
  printf("------------------------------------------------------------------------------\n");
  OSTimeSet(0);
  OSStart();
  return 0;
}

/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2004 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
* Altera does not recommend, suggest or require that this reference design    *
* file be used in conjunction or combination with any other product.          *
******************************************************************************/
