/*==============================================================================
 * MODULE: State Machine (SM)
 * DESCRIPTION: Prototypes exported by the SM module
 *============================================================================*/
#ifndef _OT_SM_H_
#define _OT_SM_H_

#ifdef __cplusplus
extern "C"
{
#endif
/*==============================================================================
 * INCLUDES
 *============================================================================*/
/*==============================================================================
 * CONSTANTS
 *============================================================================*/
/*==============================================================================
 * MACROS
 *============================================================================*/
/*==============================================================================
 * TYPEDEFs and STRUCTs
 *============================================================================*/
typedef enum OT_SM_STATE_E {
  OT_SM_STATE_INIT,         // Transient
  //OT_SM_STATE_ARMING,     // Unused
  OT_SM_STATE_READY,
  OT_SM_STATE_PROVISIONAL,
  OT_SM_STATE_CONFIRMED,
#if defined(WAKEUP_BUTTON)
  OT_SM_STATE_SLEEPING,
#endif // WAKEUP_BUTTON
  OT_SM_STATE_MAX           // Not a real state
} OT_SM_STATE_T;

typedef enum OT_SM_EVENT_E {
  OT_SM_EVENT_INIT_COMPLETE,
  OT_SM_EVENT_FLASH_DETECTED,
  OT_SM_EVENT_TIMEOUT,
#if defined(WAKEUP_BUTTON)
  OT_SM_EVENT_BUTTON_PRESS,
#endif // WAKEUP_BUTTON
  OT_SM_EVENT_MAX              // Not a real event
} OT_SM_EVENT_T;
/*==============================================================================
 * GLOBAL (extern) VARIABLES
 *============================================================================*/
/*==============================================================================
 * EXPORTED (GLOBAL) FUNCTIONS
 *============================================================================*/
void OT_SM_init(void);
void OT_SM_execute(OT_SM_EVENT_T event);
OT_SM_STATE_T OT_SM_get_state(void);
/*============================================================================*/
#ifdef __cplusplus
}
#endif

#endif /* _OT_SM_H_ */
