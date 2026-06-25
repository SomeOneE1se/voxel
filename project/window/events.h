/** ############################################################################
 *  \file   events.h
 *  \author p@nsk
 *  \date   10.05.2026
 *  \brief
 * _____________________________________________________________________________
 */
#ifndef EVENTS_H
#define EVENTS_H

#include "window.h"
#include <project.h>

/**
 * @brief The Events class
 ******************************************************************************/
class Events
{
private:
    static  TBool       *keys;
    static  TUInt32     *frames;
    static  TUInt32     current;
    static  TFloat      deltaX;
    static  TFloat      deltaY;
    static  TFloat      x;
    static  TFloat      y;
    static  TBool       cursor_locked;
    static  TBool       cursor_started;

    static void cursorPositionCallback (
        GLFWwindow *window,
        TDouble     xpos,
        TDouble     ypos
    );

    static void mouseButtonCallback (
        GLFWwindow *window,
        TInt button,
        TInt action,
        TInt mode
    );

    static void keyCallback (
        GLFWwindow *window,
        TInt key,
        TInt scancode,
        TInt action,
        TInt mode
    );
    Events() = default;

public:
    static  TInt    initialize  ( void);
    static  void    pullEvents  ( void);
    static  TBool   isPressed   ( TInt keycode);
    static  TBool   isJPressed  ( TInt keycode);
    static  TBool   isClicked   ( TInt button);
    static  TBool   isJClicked  ( TInt button);
};

#endif // EVENTS_H
