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
#define R1_PRIO             1
#define R2_PRIO             2
#define TASK1_PRIORITY      11
#define TASK2_PRIORITY      12
#define TASK3_PRIORITY      13

OS_EVENT *R1;
OS_EVENT *R2;

OS_CPU_SR cpu_sr;

typedef struct {
    int exec;
    int period;
}task;

void mywait(int tick)
{
    int now, exit;
    OS_ENTER_CRITICAL();
    now = OSTimeGet();
    exit = now + tick;
    OS_EXIT_CRITICAL();
    while(1) {
        if(exit <= OSTimeGet())
            break;
    }
}

void task1(task* pdata)
{
  int start = 0;
  int end;
  int delay;
  INT8U err;
  int arrival = 3;
  OSTCBCur->Period = pdata->period;
  OSTCBCur->Exec = pdata->exec;
  OSTCBCur->ExecTime = pdata->exec;
  OSTCBCur->Start = 0;
  OSTCBCur->Deadline = pdata->period + arrival;
  OSTCBCur->Org_Deadline = pdata->period + arrival;
  OSTimeDly(arrival);
  
  while (1)
  { 
    printf("\t%d\tTask_1\n",OSTimeGet());
    mywait(OSTCBCur->Exec); // CPU time
    printf("\t%d\tTask_1 get R2\t",OSTimeGet());
    OSMutexPend(R2, 0, &err);
    mywait(5); // R2
    printf("\t%d\tTask_1 get R1\t",OSTimeGet());
    OSMutexPend(R1, 0, &err);
    mywait(3); // R1
    printf("\t%d\tTask_1 release R1",OSTimeGet());
    OSMutexPost(R1);
    mywait(0); // R2
    printf("\t%d\tTask_1 release R2",OSTimeGet());
    OSMutexPost(R2);
    
    end = OSTimeGet();
    delay = OSTCBCur->Deadline-end;            // let it delay 1 timetick to avoid running the while loop
    OSTCBCur->Resp = end-start;
    start += pdata->period;
    OSTCBCur->Deadline += OSTCBCur->Period;
    OSTCBCur->Org_Deadline = OSTCBCur->Deadline; 
    OSTimeDly(delay);    
  }
}

void task2(task* pdata)
{
  int start = 0;
  int end;
  int delay;
  INT8U err;
  int arrival = 0;
  OSTCBCur->Period = pdata->period;
  OSTCBCur->Exec = pdata->exec;
  OSTCBCur->ExecTime = pdata->exec;
  OSTCBCur->Start = 0;
  OSTCBCur->Deadline = pdata->period + arrival;
  OSTCBCur->Org_Deadline = pdata->period + arrival;
  OSTimeDly(arrival);

  while (1)
  { 
    printf("\t%d\tTask_2\n",OSTimeGet());
    mywait(OSTCBCur->Exec); // CPU time
    printf("\t%d\tTask_2 get R1\t",OSTimeGet());
    OSMutexPend(R1, 0, &err);
    mywait(5); // R1
    printf("\t%d\tTask_2 get R2\t",OSTimeGet());
    OSMutexPend(R2, 0, &err);
    mywait(5); // R2
    printf("\t%d\tTask_2 release R2",OSTimeGet());
    OSMutexPost(R2);
    mywait(0); // R1
    printf("\t%d\tTask_2 release R1",OSTimeGet());
    OSMutexPost(R1);
    
    end = OSTimeGet();
    delay = OSTCBCur->Deadline-end;            // let it delay 1 timetick to avoid running the while loop
    OSTCBCur->Resp = end-start;
    start += pdata->period; 
    OSTCBCur->Deadline += OSTCBCur->Period;
    OSTCBCur->Org_Deadline = OSTCBCur->Deadline;
    OSTimeDly(delay);
  }
}
/*
void task3(task* pdata)
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
    delay = pdata->period - (end-start);
    OSTCBCur->Resp = end-start;
    start += pdata->period; 
    OSTimeDly(delay);
    
  }
}
*/

/* The main function creates two task and starts multi-tasking */
int main(void)
{
  task t1 = {2,37}; // CPU exec, Period
  task t2 = {2,45};
  
  INT8U err;
  
  OSInit();
  OSTaskCreateExt(task1,
                  &t1,
                  (void *)&task1_stk[TASK_STACKSIZE-1],
                  TASK1_PRIORITY,
                  TASK1_PRIORITY,
                  task1_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0,
                  t1.period);
              
               
  OSTaskCreateExt(task2,
                  &t2,
                  (void *)&task2_stk[TASK_STACKSIZE-1],
                  TASK2_PRIORITY,
                  TASK2_PRIORITY,
                  task2_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0,
                  t2.period);
  /*                
  OSTaskCreateExt(task3,
                  &t3,
                  (void *)&task3_stk[TASK_STACKSIZE-1],
                  TASK3_PRIORITY,
                  TASK3_PRIORITY,
                  task3_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0,
                  t3.period);
  */                
  R1 = OSMutexCreate(R1_PRIO, &err);
  R2 = OSMutexCreate(R2_PRIO, &err);
  
  printf("========== SRP Task Set 1 { t1(3,37) , t2(0,45) } (Arrival,Period) ===========\n");
  printf("------------------------------------------------------------------------------\n");
  printf("Current Time     Event            System Ceiling                              \n");
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
