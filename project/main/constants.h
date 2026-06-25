/** ############################################################################
 *  \file   constants.h
 *  \author p@nsk
 *  \date   25.06.2026
 *  \brief  Temp
 * _____________________________________________________________________________
 */
#ifndef CONSTANTS_H
#define CONSTANTS_H

int WIN_WIDTH   = 1280;
int WIN_HEIGHT  = 720;

float  vertices[]  = {
//  vertices             || texture
//  X       Y       Z       U       V
   -1.0f,  -1.0f,   0.0f,   0.0f,   0.0f,
    1.0f,  -1.0f,   0.0f,   1.0f,   0.0f,
   -1.0f,   1.0f,   0.0f,   0.0f,   1.0f,

    1.0f,  -1.0f,   0.0f,   1.0f,   0.0f,
    1.0f,   1.0f,   0.0f,   1.0f,   1.0f,
   -1.0f,   1.0f,   0.0f,   0.0f,   1.0f,
};

#endif // CONSTANTS_H
