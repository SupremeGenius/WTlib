/*
 *  This file is part of WTlib.
 *
 *  WTlib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  WTlib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with WTlib.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef WT_INTER_HEADER_INCLUDED
#define WT_INTER_HEADER_INCLUDED

#include "wt.h"

using WTlib::WTdata;
using WTlib::WTencoder;
using WTlib::WTdecoder;
using WTlib::WTcommon;
using WTlib::Environment;
using WTlib::OZNACENI_PASMA;
using WTlib::KODOVACI_MOZNOST;
using WTlib::KODER;

enum class SMER {
    KODER, 
    DEKODER
};


//#define N_THREADS_AVAIABLE 16
#define N_THREADS_AVAIABLE 1

#endif // WT_INTER_HEADER_INCLUDED
