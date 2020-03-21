#include "Game.h"

namespace lab9
{
	Game::Game(unsigned int seed)
	{
		mObjectPool = new ObjectPool<IceCube>(0);
		srand(seed);
	}

	Game::Game(unsigned int seed, unsigned int poolSize)
		: mPoolSize(poolSize)
	{
		mObjectPool = new ObjectPool<IceCube>(mPoolSize);
		srand(seed);
	}

	Game::~Game()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end(); ++it)
		{
			delete (*it);
		}
		mActiveGameObjects.clear();
		delete mObjectPool;
	}

	void Game::Spawn()
	{
		IceCube* iceCube = mObjectPool->Get();
		iceCube->Initialize(rand() % MAX_FRAME_COUNT_TO_LIVE + 1);
		mActiveGameObjects.push_back(iceCube);
	}

	void Game::Update()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end();)
		{
			IceCube* iceCube = *it;
			iceCube->Animate();

			if (!iceCube->IsActive())
			{
				it = mActiveGameObjects.erase(it);
				mObjectPool->Return(iceCube);
				continue;
			}

			++it;
		}
	}

	const std::vector<IceCube*>& Game::GetActiveGameObjects() const
	{
		return mActiveGameObjects;
	}

	ObjectPool<IceCube>& Game::GetObjectPool() const
	{
		return *mObjectPool;
	}

}