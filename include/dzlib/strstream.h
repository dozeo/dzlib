#ifndef x95bff40b1e4d4cf48714782bc3642182
#define x95bff40b1e4d4cf48714782bc3642182

#include <string>
#include <sstream>

namespace dz
{
	class strstream
	{
		public:
			strstream() { }

			template<typename T>
			friend strstream&& operator<< (strstream&& out, T what);

			operator std::string() { return m_str.str(); }

		private:
			std::ostringstream m_str;
	};

	template<typename T>
	strstream&& operator<< (strstream&& out, T what)
	{
		out.m_str << what;
		return std::move(out);
	}
}


#endif // x95bff40b1e4d4cf48714782bc3642182
