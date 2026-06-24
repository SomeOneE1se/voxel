/*! ############################################################################
 *  \file   uni_base_types.h
 *  \author p@nsk
 *  \date   29.05.2026
 *  \brief  Base user types.
 *
 * _____________________________________________________________________________
 */
#ifndef UNI_BASE_TYPES_H
#define UNI_BASE_TYPES_H

/*
 * -------------------------------------------------------------------------- */

using TBool         = bool;
using TChar         = char;
using TShort        = short;
using TInt          = int;
using TLong         = long;
using TFloat        = float;
using TDouble       = double;

using TUInt8        = unsigned char;
using TSInt8        = signed char;
using TUInt16       = unsigned short;
using TSInt16       = signed short;
using TUInt32       = unsigned int;
using TSInt32       = signed int;
using TUInt64       = unsigned long long;
using TSInt64       = signed long long;

/*
 * -------------------------------------------------------------------------- */

/**
 * @brief The TFlag enum
 ******************************************************************************/
enum class TFlag    : bool
{
    FLAG_FALSE  = false,    ///<
    FLAG_TRUE   = true      ///<
};
#define flag_false      TFlag::FLAG_FALSE
#define flag_true       TFlag::FLAG_TRUE

/**
 * @brief The TOperRet enum
 ******************************************************************************/
enum class TOperRet : bool
{
    OPER_SUCCESS    = false,    ///<
    OPER_FAILURE    = true      ///<
};
#define oper_success    TOperRet::OPER_SUCCESS
#define oper_failure    TOperRet::OPER_FAILURE

#endif/*UNI_TYPES_H*/
