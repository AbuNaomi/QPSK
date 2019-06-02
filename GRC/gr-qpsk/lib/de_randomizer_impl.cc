/* -*- c++ -*- */
/* 
 * Copyright 2019 fociSpectral.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "de_randomizer_impl.h"
#include <iostream>
#include <cstdlib>
#include <math.h>       /* pow */
#include <stdio.h>

extern "C" const unsigned char prdm[] = {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1,1,1,0,0,0,1,1,0,1,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,1,1,0,0,1,0,1,1,1,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,0,1,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,0,0,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,1,1,1,0,1,1,0,1,0,1,0,0,1,1,0,0,0,0,1,1,0,1,0,1,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,1,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,0,0,1,1,0,0,0,0,1,0,1,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0,1,1,1,0,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,0,1,0,1,1,1,0,0,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,0,1,0,1,0,1,0,0,1,1,0,0,1,0,1,0,0,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,1,1,0,0,1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,0,1,1,1,0,1,1,0,1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,1,1,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,1,0,1,1,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,1,1,0,1,1,0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,0,1,1,0,0,0,0,1,0,1,0,1,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,1,0,1,1,1,1,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,1,0,1,0,1,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,0,1,0,1,1,0,1,1,0,0,1,1,1,0,1,1,1,1,1,0,1,1,0,0,1,1,1,1,0,1,0,0,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,0,1,1,1,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,1,0,0,1,0,1,1,0,1,1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,1,1,0,0,1,1,1,0,1,0,0,1,1,0,0,0,1,0,1,1,0,0,0,1,0,1,0,1,0,0,1,1,0,1,1,0,0,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,0,1,1,1,0,0,1,1,0,1,1,0,0,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,0,1,1,0,1,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,0,0,0,1,1,0,0,1,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1,0,1,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,1,1,1,0,0,1,0,1,1,1,0,0,0,0,1,0,0,1,1,1,1,0,1,1,0,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,1,1,1,0,1,1,0,0,1,1,1,0,0,1,1,0,1,0,0,1,0,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,0,0,1,1,0,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,1,1,1,0,0,1,0,0,1,0,0,0,1,0,1,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,1,1,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,1,0,0,0,1,0,1,0,0,1,1,1,1,0,0,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,1,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,1,0,0,1,1,1,0,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,1,0,0,1,1,1,0,1,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,1,1,0,1,1,1,1,0,0,1,0,0,0,0,1,1,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,0,1,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,1,0,1,0,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,0,1,1,0,0,1,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,1,0,0,1,1,0,1,1,1,0,0,0,1,0,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,0,1,0,0,1,0,0,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,1,1,0,1,0,0,0,0,0,1,1,1,0,1,0,1,1,0,1,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,0,0,1,0,1,1,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,1,1,1,0,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,0,1,1,0,0,1};

namespace gr {
  namespace qpsk {

    de_randomizer::sptr
    de_randomizer::make(bool randn)
    {
      return gnuradio::get_initial_sptr
        (new de_randomizer_impl(randn));
    }

    /*
     * The private constructor
     */
    de_randomizer_impl::de_randomizer_impl(bool randn)
      : gr::block("de_randomizer",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
    {
	counter = 0;
	d_randn = randn;
	pBuf = (unsigned char*) malloc(4616*sizeof(unsigned char)); 	//randomizer frame
	dBuf = (unsigned char*) malloc(8*sizeof(unsigned char));		   // byte sync buffer
	for(int i =0; i<4616;i++){
		pBuf[i] = 0;
	}
	for(int i =0; i<8;i++){
		dBuf[i] = 0;
	}
	samp = 0;
	active = 0;
    }

    /*
     * Our virtual destructor.
     */
    de_randomizer_impl::~de_randomizer_impl()
    {
    }

    void
    de_randomizer_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
    unsigned ninputs = ninput_items_required.size ();
    for(unsigned i = 0; i < ninputs; i++)
      ninput_items_required[i] = noutput_items;
    }

    int
    de_randomizer_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
	const unsigned char *in = (const unsigned char *) input_items[0];
    unsigned char *out = (unsigned char *) output_items[0];

      	// Do <+signal processing+>
	if(d_randn){
            for(int i = 0; i < noutput_items; i++)
            {		
		out[i] = in[i] ^ prdm[counter];
        	counter++;
	if(counter == 3072){ //pn sequence reset
		counter = 0;
	}
	    }
	}
	else{	
         for(int i = 0; i < noutput_items; i++)
		{	
			unsigned char val = 0;		//values to be compared against sync bytes
			unsigned char val2 = 0;
			unsigned char val3 = 0;
			unsigned char val4 = 0;
			
			// Implementing circular buffer containing 193 bytes
			if(samp == 4616){
				samp = 0;
			}
			pBuf[samp] = in[i];
			
			// Checking if first byte and last byte are 0x47 and 0x63 sync bytes respectively
			for(int j = 0; j < 8; j++)
			{ 
				int isamp = (samp+8-j) % 4616;
				val = val + pBuf[isamp]*pow(2,j);
				int isamp2 = (samp+4616-j) % 4616;
				val2 = val2 + pBuf[isamp2]*pow(2,j);
				int isamp3 = (samp + 3080 -j) % 4616;
				val3 = val3 + pBuf[isamp3]*pow(2,j);
				int isamp4 = (samp + 1544 -j) % 4616;
				val4 = val4 +pBuf[isamp4]*pow(2,j);
				
			}
			
			// First in byte index in buffer
			int isamp7 = (samp + 8 - 7 ) % 4616 ;
			
			//IS SYNC BYTE ?
			
			if((val == 71) & (val2 ==100) & (val3 == 71) & (val4 == 100)& (counter ==0)){	 
				printf("*");
				counter = 0;
				active = 1;
				byteAlignDelay = 8 - (samp % 8);
			}

			if(active){
				
				for(int j=0; j<byteAlignDelay;j++){			// align byte
					dBuf[j] = dBuf[j+1];
				}
				dBuf[byteAlignDelay] = pBuf[isamp7] ^ prdm[counter];
				out[i] = dBuf[0];
				counter++;
			}
			if(counter == 3072){
				counter = 0;
				active = 0;
			}
			samp++;
	    }
	}
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace qpsk */
} /* namespace gr */

