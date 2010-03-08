#pragma once

#include "MotionState.h"

namespace BulletSharp
{
	public ref class DefaultMotionState : BulletSharp::MotionState
	{
	public:
		DefaultMotionState();
		DefaultMotionState(Matrix startTrans);

	internal:
		property btDefaultMotionState* UnmanagedPointer
		{
			btDefaultMotionState* get() new;
		}
	};
};