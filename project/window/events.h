#ifndef EVENTS_H
#define EVENTS_H

#include "window.h"
#include <project.h>
class Events
{
public:
    static TBool    *_keys;
    static TUInt32  *_frames;
    static TUInt32  _current;
    static TFloat   deltaX;
    static TFloat   deltaY;
    static TFloat   x;
    static TFloat   y;
    static TBool    _cursor_locked;
    static TBool    _cursor_started;

    static TInt     initialize  ( void);
    static void     pullEvents  ( void);

    static TBool    pressed     ( TInt keycode);
    static TBool    jpressed    ( TInt keycode);
    static TBool    clicked     ( TInt button);
    static TBool    jclicked    ( TInt button);
};

#endif // EVENTS_H
