/* $Id$
 * 
 * Copyright (C) 2002 Ondrej Zima <amiandrew@volny.cz>
 * Copyright (C) 2002 Stefan Kost <ensonic@sonicpulse.de>
 * Copyright (C) 1993 Jochen Wiedmann and Marcin Orlowski <carlos@wfmh.org.pl>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include "flexcat.h"
#include "readprefs.h"
#include "globals.h"
#include "utils.h"

/// FUNC: ShowError

/* This shows an error message and terminates */
void ShowError ( const char *msg, ... )
{
    va_list args;

//  if(!Quiet)
    {
        va_start ( args, msg );
        vfprintf ( stderr, msg, args );
        putc ( '\n', stderr );
	va_end ( args );
    }

#ifdef __amigados
    NumberOfWarnings++;
#endif

    MyExit ( 10 );
}

//|

/// FUNC: MemError

/* This shows the message: Memory error. */
void MemError ( void )
{
    ShowError ( msgMemoryError, NULL );
}

//|

/// FUNC: ShowWarn

/* This shows a warning */
void ShowWarn ( const char *msg, ... )
{
    va_list args;

    if ( !Quiet )
    {
        va_start ( args, msg );
        fprintf ( stderr, ( char * )msgWarning, ScanFile, ScanLine );
        vfprintf ( stderr, msg, args );
        putc ( '\n', stderr );
	va_end ( args );
    }

    NumberOfWarnings++;
    GlobalReturnCode = 5;
}

//|
