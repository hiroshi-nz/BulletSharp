#include "StdAfx.h"

#include "BroadphaseInterface.h"
#include "CollisionConfiguration.h"
#include "ConstraintSolver.h"
#include "DiscreteDynamicsWorld.h"
#include "Dispatcher.h"

DiscreteDynamicsWorld::DiscreteDynamicsWorld(btDiscreteDynamicsWorld* world)
: DynamicsWorld(world)
{
}

DiscreteDynamicsWorld::DiscreteDynamicsWorld(BulletSharp::Dispatcher^ dispatcher,
	BroadphaseInterface^ pairCache, ConstraintSolver^ constraintSolver,
	CollisionConfiguration^ collisionConfiguration)
: DynamicsWorld(new btDiscreteDynamicsWorld(dispatcher->UnmanagedPointer,
		pairCache->UnmanagedPointer, constraintSolver->UnmanagedPointer,
		collisionConfiguration->UnmanagedPointer))
{
	_dispatcher = dispatcher;
	_broadphase = pairCache;
}

// Set gravity by components
void DiscreteDynamicsWorld::SetGravity(btScalar x, btScalar y, btScalar z)
{
	btVector3* gravity = new btVector3(x,y,z);
	UnmanagedPointer->setGravity(*gravity);
	delete gravity;
}

btDiscreteDynamicsWorld* DiscreteDynamicsWorld::UnmanagedPointer::get()
{
	return (btDiscreteDynamicsWorld*)DynamicsWorld::UnmanagedPointer;
}