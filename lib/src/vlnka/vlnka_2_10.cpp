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

#include "vlnka_internal.h"

namespace V_2_10 {


void Vlnka::lifting_predict( ROZHRANI_VLNKOVE_FUNKCE_PLNE ) {
    assert( (stop-start)%step == 0 );
    assert( (act-start )%step == 0 );
    assert(index_step < 2);


    int add = 1 << ( predict_left_shift(index_step) - 1 );

    switch ( index_step ) {
        case 0:
            for ( int i = act;   i <= stop;   i += step * 2) {
                int value = ROZSIRENI(i-step);

                if ( divide_and_round )
                    if ( reversed )
                        data[i] += value; 
                    else 
                        data[i] -= value;
                else 
                    data[i] += value;
            }
            break;
        case 1:
            for ( int i = act;   i <= stop;   i += step * 2) {
                int value = 22* ( - ROZSIRENI(i-3*step) + ROZSIRENI(i+step) ) +
                            3 * ( - ROZSIRENI(i+3*step) + ROZSIRENI(i-5*step) );
                value -= add;

                if ( divide_and_round )
                    if ( reversed )
                        data[i] += value >> predict_left_shift(1);
                    else 
                        data[i] -= value >> predict_left_shift(1);
                else 
                    data[i] += value;
            }
            break;
        default:
            assert(false);
            break;
    }
}

void Vlnka::lifting_update( ROZHRANI_VLNKOVE_FUNKCE_PLNE ) {
    assert( (stop-start)%step == 0 );
    assert( (act-start )%step == 0 );
    assert(index_step < 2);

    //int add = 1 << ( update_left_shift(index_step) - 1 );

    switch( index_step ) {
        case 0:
            for ( int i = act;   i <= stop;   i += step * 2) {
                int value = ROZSIRENI(i+step);
                //value += add;

                if ( divide_and_round )
                    if ( reversed )
                        data[i] -= value >> update_left_shift(0);
                    else 
                        data[i] += value >> update_left_shift(0);
                else 
                    data[i] += value;
            }
            break;
        case 1:
            // DONE
            break;
        default:
            assert(false);
            break;
    }

}

} // end namespace CDF_9_7_F
