/*
 * PIDEncoder.h
 *
 *  Created on: Jan 15, 2015
 *      Author: rahulsalvi
 */

#ifndef SRC_UTILITIES_PIDENCODER_H_
#define SRC_UTILITIES_PIDENCODER_H_

#include "WPILib.h"

class PIDEncoder : public Encoder {
private:
	bool _useVelocity;
public:
	PIDEncoder(uint32_t aChannel,
			   uint32_t bChannel,
			   bool useVelocity = true,
			   bool reverseDirection = false,
			   EncodingType encodingType = k4X);
	virtual ~PIDEncoder();
	double PIDGet();
	void setMode(bool velocity);
	bool getMode();
};

#endif /* SRC_UTILITIES_PIDENCODER_H_ */
