#pragma once

namespace Laser
{
	namespace Macro
	{
		template<class T>
		struct Release{
			Release(T **ppObj ){
				if( *ppObj ) {
					*ppObj->Release();
				}
			}
		};
	}
}
