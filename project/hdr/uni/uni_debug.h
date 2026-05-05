#ifndef UNI_DEBUG_H
#define UNI_DEBUG_H

/*
*******************************************************************************/
#ifdef 		PROJECT_DBG
    #define     dbgput(X)                       puts(X)
    #define 	dbgprint0(F)                    printf(F)
    #define 	dbgprint1(F,P)                  printf(F,P)
    #define 	dbgprint2(F,P1,P2)              printf(F,P1,P2)
    #define 	dbgprint3(F,P1,P2,P3)           printf(F,P1,P2,P3)
#else
    #define 	dbgput(X)
    #define 	dbgprint0(F)
    #define 	dbgprint1(F,P)
    #define 	dbgprint2(F,P1,P2)
    #define 	dbgprint3(F,P1,P2,P3)
#endif  /*PROJECT_DBG*/

#endif/*UNI_DEBUG_H*/
