#ifndef x8d6a0e1838ec4951b2928f9f970acbbd
#define x8d6a0e1838ec4951b2928f9f970acbbd

#include <dzlib/strstream.h>

namespace dz
{
	class exception
	{
		public:
			exception(std::string msg) : m_msg(msg) { }

			std::string msg() const { return m_msg; }

		private:
			std::string m_msg;
	};
}


#endif // x8d6a0e1838ec4951b2928f9f970acbbd
