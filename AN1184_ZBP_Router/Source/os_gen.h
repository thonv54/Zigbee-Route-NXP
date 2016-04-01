/****************************************************************************
 *
 *                 THIS IS A GENERATED FILE. DO NOT EDIT!
 *
 * MODULE:         OS
 *
 * COMPONENT:      os_gen.h
 *
 * DATE:           Fri Apr  1 16:36:27 2016
 *
 * AUTHOR:         Jennic RTOS Configuration Tool
 *
 * DESCRIPTION:    RTOS Application Configuration
 *
 ****************************************************************************
 *
 * This software is owned by Jennic and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on Jennic products. You, and any third parties must reproduce
 * the copyright and warranty notice and any other legend of ownership on each
 * copy or partial copy of the software.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS". JENNIC MAKES NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE,
 * ACCURACY OR LACK OF NEGLIGENCE. JENNIC SHALL NOT, IN ANY CIRCUMSTANCES,
 * BE LIABLE FOR ANY DAMAGES, INCLUDING, BUT NOT LIMITED TO, SPECIAL,
 * INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER.
 *
 * Copyright Jennic Ltd. 2009 All rights reserved
 *
 ****************************************************************************/

#ifndef _OS_GEN_H
#define _OS_GEN_H

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define OS_STRICT_CHECKS

/* Module ZBPro */

/* Mutex Handles */
#define mutexZPS ((OS_thMutex)&os_Mutex_mutexZPS)
#define mutexPDUM ((OS_thMutex)&os_Mutex_mutexPDUM)
#define mutexMAC ((OS_thMutex)&os_Mutex_mutexMAC)

/* Message Handles */
#define zps_msgMlmeDcfmInd ((OS_thMessage)&os_Message_zps_msgMlmeDcfmInd)
#define zps_msgTimeEvents ((OS_thMessage)&os_Message_zps_msgTimeEvents)
#define zps_msgMcpsDcfmInd ((OS_thMessage)&os_Message_zps_msgMcpsDcfmInd)
#define zps_msgMlmeDcfmInd_C_Type MAC_tsMlmeVsDcfmInd
#define zps_msgTimeEvents_C_Type zps_tsTimeEvent
#define zps_msgMcpsDcfmInd_C_Type MAC_tsMcpsVsDcfmInd

/* Module ZBProAppTemplate */

/* Cooperative Task Handles */
#define zps_taskZPS ((OS_thTask)&os_Task_zps_taskZPS)
#define APP_taskRouter ((OS_thTask)&os_Task_APP_taskRouter)
#define APP_taskMyEndPoint ((OS_thTask)&os_Task_APP_taskMyEndPoint)
#define ButtonScan ((OS_thTask)&os_Task_ButtonScan)
#define UartCommandExec ((OS_thTask)&os_Task_UartCommandExec)

/* Message Handles */
#define APP_msgZpsEvents ((OS_thMessage)&os_Message_APP_msgZpsEvents)
#define APP_msgMyEndPointEvents ((OS_thMessage)&os_Message_APP_msgMyEndPointEvents)
#define APP_msgZpsEvents_C_Type ZPS_tsAfEvent
#define APP_msgMyEndPointEvents_C_Type ZPS_tsAfEvent

/* Timer Handles */
#define APP_cntrTickTimer ((OS_thHWCounter)&os_HWCounter_APP_cntrTickTimer)
#define App_tmr1sec ((OS_thSWTimer)&os_SWTimer_APP_cntrTickTimer_App_tmr1sec)
#define ButtonScanTimer ((OS_thSWTimer)&os_SWTimer_APP_cntrTickTimer_ButtonScanTimer)
#define UartCommandExecTimer ((OS_thSWTimer)&os_SWTimer_APP_cntrTickTimer_UartCommandExecTimer)

/* Module Exceptions */

/* Module UART_Get */

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef void (*OS_tprISR)(void);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/


/* Mutex Handles */
extern struct _os_tsMutex os_Mutex_mutexZPS;
extern struct _os_tsMutex os_Mutex_mutexPDUM;
extern struct _os_tsMutex os_Mutex_mutexMAC;

/* Message Handles */
extern struct _os_tsMessage os_Message_zps_msgMlmeDcfmInd;
extern struct _os_tsMessage os_Message_zps_msgTimeEvents;
extern struct _os_tsMessage os_Message_zps_msgMcpsDcfmInd;

/* Cooperative Task Handles */
extern struct _os_tsTask os_Task_zps_taskZPS;
extern struct _os_tsTask os_Task_APP_taskRouter;
extern struct _os_tsTask os_Task_APP_taskMyEndPoint;
extern struct _os_tsTask os_Task_ButtonScan;
extern struct _os_tsTask os_Task_UartCommandExec;

/* Message Handles */
extern struct _os_tsMessage os_Message_APP_msgZpsEvents;
extern struct _os_tsMessage os_Message_APP_msgMyEndPointEvents;

/* Timer Handles */
extern struct _os_tsHWCounter os_HWCounter_APP_cntrTickTimer;
extern struct _os_tsSWTimer os_SWTimer_APP_cntrTickTimer_App_tmr1sec;
extern struct _os_tsSWTimer os_SWTimer_APP_cntrTickTimer_ButtonScanTimer;
extern struct _os_tsSWTimer os_SWTimer_APP_cntrTickTimer_UartCommandExecTimer;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void OS_vStart(void (*)(void), void (*)(void), void (*)(OS_teStatus , void *));
PUBLIC OS_tprISR OS_prGetActiveISR(void);

PUBLIC bool os_bAPP_cbSetTickTimerCompare(uint32 );
PUBLIC uint32 os_u32APP_cbGetTickTimer(void);
PUBLIC void os_vAPP_cbEnableTickTimer(void);
PUBLIC void os_vAPP_cbDisableTickTimer(void);

#endif
