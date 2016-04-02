/****************************************************************************
 *
 *                 THIS IS A GENERATED FILE. DO NOT EDIT!
 *
 * MODULE:         OS
 *
 * COMPONENT:      os_gen.c
 *
 * DATE:           Sat Apr  2 11:09:45 2016
 *
 * AUTHOR:         Jennic RTOS Configuration Tool
 *
 * DESCRIPTION:    RTOS Application Configuration
 *
 ****************************************************************************
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139]. 
 * You, and any third parties must reproduce the copyright and warranty notice 
 * and any other legend of ownership on each  copy or partial copy of the software.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE. 
 *
 * Copyright NXP B.V. 2012. All rights reserved
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <os.h>
#include "os_msg_types.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define OS_TASK_MAGIC                   0xdeadbeef
#define OS_MUTEX_MAGIC                  0xcafebabe
#define OS_MESSAGE_MAGIC                0x00ddba11
#define OS_HWCOUNTER_MAGIC              0x1A2B3C4D
#define OS_SWTIMER_MAGIC                0x4B3C2B1A

#define OS_DIR_POST                     (1)
#define OS_DIR_COLLECT                  (2)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef uint8  tIPL;
typedef uint8  tPriority;
typedef uint32 tIPLMask;
typedef uint32 tPriorityMask;

struct _os_tsTask {
    uint32 u32Magic;
    tPriority u8BasePriority;
    tPriority u8DispatchPriority;
    uint16 u16ActivationCount;
    void (*pfvTaskFunction)(void);
};

typedef struct _os_tsMutex {
    uint32 u32Magic;
    tPriority u8CeilingPriority;
    tIPL u8IPL;
    tPriority u8PrevPriority;
    tIPL u8PrevIPL;
} tsMutex;

typedef struct _os_tsMessage {
    uint32 u32Magic;
    void *pvData;
    uint32 u32In;
    uint32 u32Out;
    uint32 u32NumItems;
    uint32 u32Size;
    uint32 u32ElementSize;
    struct _os_tsTask *psNotifyTask;
    tPriority u8CeilingPriority;
    tIPL u8IPL;
} tsMessage;

struct _os_tsHWCounter;
struct _os_tsSWTimer;
typedef struct _os_tsHWCounter tsHWCounter;
typedef struct _os_tsSWTimer tsSWTimer;

struct _os_tsHWCounter {
    uint32 u32Magic;
    tsSWTimer *psList; /* must be 2nd element of structure */
    bool (*pfvSetCallback)(uint32 u32Time);
    uint32 (*pfu32GetCallback)(void);
    void (*pfvEnableCallback)(void);
    void (*pfvDisableCallback)(void);
    uint16 u16Active;
};

struct _os_tsSWTimer {
    uint32 u32Magic;
    tsSWTimer *psNext;  /* must be 2nd element of structure */
    tsHWCounter *psHWCounter;
    void *pvData;
    void *pvAction;
    uint32 u32MatchTime;
    uint8 eStatus;
    uint8 bCallback;
};

/****************************************************************************/
/***        Function Prototypes                                           ***/
/****************************************************************************/

/* Module ZBPro */

/* Module ZBProAppTemplate */
PUBLIC void os_vzps_taskZPS(void);
PUBLIC void os_vAPP_taskRouter(void);
PUBLIC void os_vAPP_taskMyEndPoint(void);
PUBLIC void os_vButtonScan(void);
PUBLIC void os_vUartCommandExec(void);

PUBLIC bool os_bAPP_cbSetTickTimerCompare(uint32 );
PUBLIC uint32 os_u32APP_cbGetTickTimer(void);
PUBLIC void os_vAPP_cbEnableTickTimer(void);
PUBLIC void os_vAPP_cbDisableTickTimer(void);

/* Module Exceptions */

/* Module UART_Get */

PRIVATE bool os_bStrictCheck(void * , void * , void *, unsigned int );
PUBLIC void os_vzps_isrMAC(void);
PUBLIC void os_vAPP_isrTickTimer(void);
PUBLIC void os_vUart0GetData(void);
PUBLIC uint32 OS_u32GetQueueSize(void * );

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/


/* Tasks */
struct _os_tsTask os_Task_zps_taskZPS = { OS_TASK_MAGIC, 1, 5, 0, os_vzps_taskZPS };
struct _os_tsTask os_Task_APP_taskRouter = { OS_TASK_MAGIC, 4, 5, 1, os_vAPP_taskRouter };
struct _os_tsTask os_Task_APP_taskMyEndPoint = { OS_TASK_MAGIC, 5, 5, 0, os_vAPP_taskMyEndPoint };
struct _os_tsTask os_Task_ButtonScan = { OS_TASK_MAGIC, 3, 5, 1, os_vButtonScan };
struct _os_tsTask os_Task_UartCommandExec = { OS_TASK_MAGIC, 2, 5, 1, os_vUartCommandExec };

/* Mutexs */
tsMutex os_Mutex_mutexZPS = { OS_MUTEX_MAGIC, 5, 0, 0xff, 0xff };
tsMutex os_Mutex_mutexPDUM = { OS_MUTEX_MAGIC, 5, 0, 0xff, 0xff };
tsMutex os_Mutex_mutexMAC = { OS_MUTEX_MAGIC, 5, 7, 0xff, 0xff };

/* Messages */
PRIVATE MAC_tsMlmeVsDcfmInd s_aMessageData_zps_msgMlmeDcfmInd[4];
tsMessage os_Message_zps_msgMlmeDcfmInd = {
    OS_MESSAGE_MAGIC,
    s_aMessageData_zps_msgMlmeDcfmInd,
    0,
    0,
    0,
    4,
    sizeof(MAC_tsMlmeVsDcfmInd),
    &os_Task_zps_taskZPS,
    0,
    7
};

PRIVATE zps_tsTimeEvent s_aMessageData_zps_msgTimeEvents[8];
tsMessage os_Message_zps_msgTimeEvents = {
    OS_MESSAGE_MAGIC,
    s_aMessageData_zps_msgTimeEvents,
    0,
    0,
    0,
    8,
    sizeof(zps_tsTimeEvent),
    &os_Task_zps_taskZPS,
    0,
    7
};

PRIVATE MAC_tsMcpsVsDcfmInd s_aMessageData_zps_msgMcpsDcfmInd[8];
tsMessage os_Message_zps_msgMcpsDcfmInd = {
    OS_MESSAGE_MAGIC,
    s_aMessageData_zps_msgMcpsDcfmInd,
    0,
    0,
    0,
    8,
    sizeof(MAC_tsMcpsVsDcfmInd),
    &os_Task_zps_taskZPS,
    0,
    7
};


/* Messages */
PRIVATE ZPS_tsAfEvent s_aMessageData_APP_msgZpsEvents[1];
tsMessage os_Message_APP_msgZpsEvents = {
    OS_MESSAGE_MAGIC,
    s_aMessageData_APP_msgZpsEvents,
    0,
    0,
    0,
    1,
    sizeof(ZPS_tsAfEvent),
    &os_Task_APP_taskRouter,
    1,
    0
};

PRIVATE ZPS_tsAfEvent s_aMessageData_APP_msgMyEndPointEvents[1];
tsMessage os_Message_APP_msgMyEndPointEvents = {
    OS_MESSAGE_MAGIC,
    s_aMessageData_APP_msgMyEndPointEvents,
    0,
    0,
    0,
    1,
    sizeof(ZPS_tsAfEvent),
    &os_Task_APP_taskMyEndPoint,
    1,
    0
};



/* Timers connected to 'APP_cntrTickTimer' */
tsHWCounter os_HWCounter_APP_cntrTickTimer = { OS_HWCOUNTER_MAGIC, NULL, os_bAPP_cbSetTickTimerCompare, os_u32APP_cbGetTickTimer, os_vAPP_cbEnableTickTimer, os_vAPP_cbDisableTickTimer, 0 };
tsSWTimer os_SWTimer_APP_cntrTickTimer_App_tmr1sec = { OS_SWTIMER_MAGIC, NULL, &os_HWCounter_APP_cntrTickTimer, NULL, &os_Task_APP_taskRouter, 0, OS_E_SWTIMER_STOPPED, FALSE };
tsSWTimer os_SWTimer_APP_cntrTickTimer_ButtonScanTimer = { OS_SWTIMER_MAGIC, NULL, &os_HWCounter_APP_cntrTickTimer, NULL, &os_Task_ButtonScan, 0, OS_E_SWTIMER_STOPPED, FALSE };
tsSWTimer os_SWTimer_APP_cntrTickTimer_UartCommandExecTimer = { OS_SWTIMER_MAGIC, NULL, &os_HWCounter_APP_cntrTickTimer, NULL, &os_Task_UartCommandExec, 0, OS_E_SWTIMER_STOPPED, FALSE };

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/* Task Table */
PRIVATE struct _os_tsTask *s_asTasks[] = {
    &os_Task_zps_taskZPS,
    &os_Task_UartCommandExec,
    &os_Task_ButtonScan,
    &os_Task_APP_taskRouter,
    &os_Task_APP_taskMyEndPoint,
};

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void os_vStart(
    void (*)(void),
    void (*)(void),
    void (*)(OS_teStatus,void *hObject),
    bool (*)(void * , void * , void * , unsigned int ),    
    tPriorityMask ,
    struct _os_tsTask **,
    uint8,
    uint32 *[9],
    uint8 *);
extern uint32 *os_OSMIUM_HwVectTable[9];
extern uint8 os_PIC_ChannelPriorities[16];

extern void os_vRestart(uint32 *[9], uint8 *);
PUBLIC void OS_vStart(void (*prvInitFunction)(void), void (*prvUnclaimedISR)(void), void (*prvErrorHook)(OS_teStatus , void *))
{
    /* Version compatibility check */
    asm(".extern OS_Version_1v2" : ) ;
    asm("b.addi r0,r0,OS_Version_1v2" : );
    asm(".extern APP_TIMER_Version_1v0" : ) ;
    asm("b.addi r0,r0,APP_TIMER_Version_1v0" : );
    os_vStart(prvInitFunction, prvUnclaimedISR, prvErrorHook, os_bStrictCheck, 0x70000000, s_asTasks, 15, os_OSMIUM_HwVectTable, os_PIC_ChannelPriorities);
}

PUBLIC void OS_vRestart(void)
{
    os_vRestart(os_OSMIUM_HwVectTable, os_PIC_ChannelPriorities);
}


/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
PUBLIC uint32 OS_u32GetQueueSize(void *pvHandle )
{
    return (((tsMessage*)(pvHandle))->u32Size);
}

PRIVATE bool os_bStrictCheck(void *hTask, void *prvISR, void *hObject, unsigned int uDir)
{
    bool bOK = FALSE;

    if (prvISR)
    {
        if (prvISR == os_vzps_isrMAC)
        {
            if (*((uint32 *)hObject) == OS_MUTEX_MAGIC)
            {
                if (hObject == &os_Mutex_mutexMAC)
                {
                    bOK = TRUE;
                }            
            }

            if (*((uint32 *)hObject) == OS_MESSAGE_MAGIC)
            {
                if (OS_DIR_POST == uDir)
                {
                    if (hObject == &os_Message_zps_msgMlmeDcfmInd)
                    {
                        bOK = TRUE;
                    }            
                    if (hObject == &os_Message_zps_msgTimeEvents)
                    {
                        bOK = TRUE;
                    }            
                    if (hObject == &os_Message_zps_msgMcpsDcfmInd)
                    {
                        bOK = TRUE;
                    }            
                }
            }

        }


    }
    else if (hTask)
    {
        if (hTask == &os_Task_zps_taskZPS)
        {
            if (*((uint32 *)hObject) == OS_MUTEX_MAGIC)
            {
                if (hObject == &os_Mutex_mutexZPS)
                {
                    bOK = TRUE;
                }            
                if (hObject == &os_Mutex_mutexPDUM)
                {
                    bOK = TRUE;
                }            
                if (hObject == &os_Mutex_mutexMAC)
                {
                    bOK = TRUE;
                }            
            }

            if (*((uint32 *)hObject) == OS_MESSAGE_MAGIC)
            {
                if (OS_DIR_POST == uDir)
                {
                    if (hObject == &os_Message_APP_msgZpsEvents)
                    {
                        bOK = TRUE;
                    }            
                    if (hObject == &os_Message_APP_msgMyEndPointEvents)
                    {
                        bOK = TRUE;
                    }            
                }
                if (OS_DIR_COLLECT == uDir)
                {
                    if (hObject == &os_Message_zps_msgMlmeDcfmInd)
                    {
                        bOK = TRUE;
                    }            
                    if (hObject == &os_Message_zps_msgTimeEvents)
                    {
                        bOK = TRUE;
                    }            
                    if (hObject == &os_Message_zps_msgMcpsDcfmInd)
                    {
                        bOK = TRUE;
                    }            
                }
            }

        }

        if (hTask == &os_Task_APP_taskRouter)
        {
            if (*((uint32 *)hObject) == OS_MUTEX_MAGIC)
            {
                if (hObject == &os_Mutex_mutexZPS)
                {
                    bOK = TRUE;
                }            
                if (hObject == &os_Mutex_mutexPDUM)
                {
                    bOK = TRUE;
                }            
                if (hObject == &os_Mutex_mutexMAC)
                {
                    bOK = TRUE;
                }            
            }

            if (*((uint32 *)hObject) == OS_MESSAGE_MAGIC)
            {
                if (OS_DIR_COLLECT == uDir)
                {
                    if (hObject == &os_Message_APP_msgZpsEvents)
                    {
                        bOK = TRUE;
                    }            
                }
            }

        }

        if (hTask == &os_Task_APP_taskMyEndPoint)
        {
            if (*((uint32 *)hObject) == OS_MUTEX_MAGIC)
            {
                if (hObject == &os_Mutex_mutexZPS)
                {
                    bOK = TRUE;
                }            
                if (hObject == &os_Mutex_mutexPDUM)
                {
                    bOK = TRUE;
                }            
                if (hObject == &os_Mutex_mutexMAC)
                {
                    bOK = TRUE;
                }            
            }

            if (*((uint32 *)hObject) == OS_MESSAGE_MAGIC)
            {
                if (OS_DIR_COLLECT == uDir)
                {
                    if (hObject == &os_Message_APP_msgMyEndPointEvents)
                    {
                        bOK = TRUE;
                    }            
                }
            }

        }


    }
    else
    {
        /* idle task */
        bOK = TRUE;
    }
    
    return bOK;
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
