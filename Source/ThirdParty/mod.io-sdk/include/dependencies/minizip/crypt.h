/* crypt.h -- base code for traditional PKWARE encryption
   Version 1.01e, February 12th, 2005

   Copyright (C) 1998-2005 Gilles Vollant
   Modifications for Info-ZIP crypting
     Copyright (C) 2003 Terry Thorsen

   This code is a modified version of crypting code in Info-ZIP distribution

   Copyright (C) 1990-2000 Info-ZIP.  All rights reserved.

   See the Info-ZIP LICENSE file version 2000-Apr-09 or later for terms of use
   which also may be found at: ftp://ftp.info-zip.org/pub/infozip/license.html

   The encryption/decryption parts of this source code (as opposed to the
   non-echoing password parts) were originally written in Europe. The
   whole source package can be freely distributed, including from the USA.
   (Prior to January 2000, re-export from the US was a violation of US law.)

   This encryption code is a direct transcription of the algorithm from
   Roger Schlafly, described by Phil Katz in the file appnote.txt. This
   file (appnote.txt) is distributed with the PKZIP program (even in the
   version without encryption capabilities).

   If you don't need crypting in your application, just define symbols
   NOCRYPT and NOUNCRYPT.
*/

#ifndef MINIZIP_CRYPT
#define MINIZIP_CRYPT

#include <time.h>

#include <iostream>

#define CRC32(c, b) ((*(pcrc_32_tab+(((int)(c) ^ (b)) & 0xff))) ^ ((c) >> 8))

#define zdecode(pkeys,pcrc_32_tab,c) \
    (update_keys(pkeys,pcrc_32_tab,c ^= decrypt_byte(pkeys,pcrc_32_tab)))

#define zencode(pkeys,pcrc_32_tab,c,t) \
    (t=decrypt_byte(pkeys,pcrc_32_tab), update_keys(pkeys,pcrc_32_tab,c), t^(c))

#define INCLUDECRYPTINGCODE_IFCRYPTALLOWED

#ifdef INCLUDECRYPTINGCODE_IFCRYPTALLOWED

#define RAND_HEAD_LEN  12
   /* "last resort" source for second part of crypt seed pattern */
#  ifndef ZCR_SEED2
#    define ZCR_SEED2 3141592654UL     /* use PI as default pattern */
#  endif

int crypthead(const char* passwd,      /* password string */
                     unsigned char* buf,      /* where to write header */
                     int bufSize,
                     unsigned long* pkeys,
                     const unsigned long* pcrc_32_tab,
                     unsigned long crcForCrypting);

/***********************************************************************
* Return the next byte in the pseudo-random sequence
*/
int decrypt_byte(unsigned long* pkeys, const unsigned long* pcrc_32_tab);

/***********************************************************************
* Update the encryption keys with the next byte of plain text
*/
int update_keys(unsigned long* pkeys,const unsigned long* pcrc_32_tab,int c);


/***********************************************************************
* Initialize the encryption keys and the random header according to
* the given password.
*/
void init_keys(const char* passwd,unsigned long* pkeys,const unsigned long* pcrc_32_tab);

#endif

#endif
