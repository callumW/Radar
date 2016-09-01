#ifndef OBJECT_H
#define OBJECT_H

#include "Graphics.h"

class Object {
public: 
	virtual void render() = 0;
	virtual void update(Uint32 elapsed) = 0;
protected:

};
#endif
