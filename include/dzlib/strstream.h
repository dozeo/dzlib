#ifndef x95bff40b1e4d4cf48714782bc3642182
#define x95bff40b1e4d4cf48714782bc3642182

#include <string>
#include <sstream>

namespace dz
{
	class strstream
	{
		public:
#ifdef _WIN32
			template<typename T>
			friend strstream& operator<< (strstream& out, T what)
			{
				out.m_str << what;
				return out;
			}
#else
			template<typename T>
			friend strstream operator<< (strstream&& out, T what)
			{
				out.m_str << what;
				return std::move(out);
			}
#endif

			operator std::string()
			{
				return m_str.str();
			}

		private:
			std::ostringstream m_str;
	};
}


#endif // x95bff40b1e4d4cf48714782bc3642182
