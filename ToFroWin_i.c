/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Mar 27 12:14:41 2004
 */
/* Compiler settings for D:\Stas\buf\ToFroWin\ToFroWin.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IToFroWinShlExt = {0x81D748F0,0x3A27,0x45FF,{0x88,0xF9,0x17,0x83,0x54,0xD9,0xBD,0x69}};


const IID LIBID_TOFROWINLib = {0xF4BB6D0A,0x5262,0x4342,{0xB4,0x0A,0xD7,0x7B,0xCF,0x3C,0x00,0x3A}};


const CLSID CLSID_ToFroWinShlExt = {0x0FDEEA60,0x1DA5,0x4930,{0x83,0xA8,0x5A,0x75,0xCA,0xD2,0xBB,0xE1}};


#ifdef __cplusplus
}
#endif

