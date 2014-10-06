#ifndef x8d6a0e1838ec4951b2928f9f970acbbd
#define x8d6a0e1838ec4951b2928f9f970acbbd

#include <stdexcept>
#include <string>

namespace dz
{
	class exception : public std::runtime_error
	{
		public:
			exception(std::string msg) : runtime_error(msg.c_str()) { }

			//const char* what() const { return m_msg; }

		private:
			//std::string m_msg;
	};
}


#endif // x8d6a0e1838ec4951b2928f9f970acbbd
