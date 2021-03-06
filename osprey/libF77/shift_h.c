/*
 * Copyright 2004 PathScale, Inc.  All Rights Reserved.
 */

/*

  Copyright (C) 2000, 2001 Silicon Graphics, Inc.  All Rights Reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2.1 of the GNU Lesser General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it would be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

  Further, this software is distributed without any warranty that it is
  free of the rightful claim of any third person regarding infringement 
  or the like.  Any license provided herein, whether implied or 
  otherwise, applies only to this software file.  Patent licenses, if
  any, provided herein do not apply to combinations of this program with 
  other software, or any other product whatsoever.  

  You should have received a copy of the GNU Lesser General Public 
  License along with this program; if not, write the Free Software 
  Foundation, Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307, 
  USA.

  Contact information:  Silicon Graphics, Inc., 1600 Amphitheatre Pky,
  Mountain View, CA 94043, or:

  http://www.sgi.com

  For further information regarding this notice, see:

  http://oss.sgi.com/projects/GenInfo/NoticeExplan

*/


/* $Header: /proj/osprey/CVS/open64/osprey1.0/libF77/shift_h.c,v 1.1.1.1 2005/10/21 19:00:00 marcel Exp $ */
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	actual or intended publication of such source code.	*/

#include "bit.h"
#include "cmplrs/host.h"
#include "f77defs.h"


/* Logically shift m k-places. If k > NBI, m = undefined.
 * k > 0 => left shift.
 * k < 0 => right shift.
 * k = 0 => no shift.
 */

int16 shft_h(int16 *m,int16 *k)
{
	int16 l, left;

	left = (*k > 0);
	l = left ? *k : -*k;

	if (l > 0 && l < NBSI)
		if (left)
			return(*m << l);
		else
			return( (*m >> l) & F77mask[NBSI - l] );
	else if (l == 0)
		return(*m);
	else return(0);
}
