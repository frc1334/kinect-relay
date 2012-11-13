/*
 * Mutex.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef MUTEX_H_
#define MUTEX_H_

#if HAVE_CONFIG_H
#include "../../config.h"
#endif

#include <pthread.h>

class Mutex
{
public:
	Mutex();
	void Lock();
	void Unlock();

	class ScopeMutex
	{
	private:
		Mutex &_mutex;
	public:
		ScopeMutex(Mutex &mutex);
		~ScopeMutex();
	};
private:
	pthread_mutex_t mutex;
};

#endif /* MUTEX_H_ */
