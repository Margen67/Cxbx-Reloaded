// ******************************************************************
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************
#ifndef EMUFS_H
#define EMUFS_H

#include <vector>
#include "common\xbe\Xbe.h"
#include <windows.h>

// initialize fs segment selector emulation
extern void EmuInitFS();

// generate fs segment selector
extern void EmuGenerateFS(Xbe::TLS *pTLS, void *pTLSData, xbox::PVOID Ethread);
// free resources allocated for the thread
void EmuKeFreeThread();
// free kpcr allocated for the thread
void EmuKeFreePcr(xbox::HANDLE UniqueThread);

void EmuKeSetPcr(xbox::KPCR *Pcr);
xbox::KPCR *_stdcall EmuKeGetPcr();

typedef struct
{
	std::vector<uint8_t> data;
	void* functionPtr;
}fs_instruction_t;

#endif
