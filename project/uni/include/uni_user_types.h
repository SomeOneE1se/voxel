/*! ############################################################################
 *  \file   uni_user_types.h
 *  \author p@nsk
 *  \date   29.05.2026
 *  \brief  User types.
 *
 * _____________________________________________________________________________
 */
#ifndef UNI_USER_TYPES_H
#define UNI_USER_TYPES_H

/*
 * -------------------------------------------------------------------------- */

template <typename T>
class point
{
    T   x   {};
    T   y   {};
public:
    point (T x, T y) : x(x), y(y)   {}
    ~point () = default;

    void    set_coord(T x, T y)     { this->x = x, this->y = y ;};
    void    get_coord(T& x, T& y)   { x = this->x, y = this->y ;};
};

#endif/*UNI_USER_TYPES_H*/
