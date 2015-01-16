/*
 * PIDEncoder.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: rahulsalvi
 */

#include "PIDEncoder.h"

PIDEncoder::PIDEncoder(uint32_t aChannel,
					   uint32_t bChannel,
					   bool useVelocity = true,
					   bool reverseDirection=false,
					   EncodingType encodingType=k4X) :
					   Encoder(aChannel, bChannel, reverseDirection, encodingType), _useVelocity(useVelocity)

{

}

PIDEncoder::~PIDEncoder() {
	~Encoder();
}

double PIDEncoder::PIDGet() {
	if (_useVelocity) {
		return GetRate();
	} else {
		return Get();
	}
}

void PIDEncoder::setMode(bool velocity) {
	_useVelocity = velocity;
}

bool PIDEncoder::getMode() {
	return _useVelocity;
}
