/*
 * Mutex.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#include "../../config.h"
#include "Mutex.h"

Mutex::Mutex()
{
	pthread_mutex_init(&mutex, NULL);
}

void Mutex::Lock()
{
	pthread_mutex_lock(&mutex);
}

void Mutex::Unlock()
{
	pthread_mutex_unlock(&mutex);
}

Mutex::ScopeMutex::ScopeMutex(Mutex &mutex)
	: _mutex(mutex)
{
	_mutex.Lock();
}

Mutex::ScopeMutex::~ScopeMutex()
{
	_mutex.Unlock();
}
