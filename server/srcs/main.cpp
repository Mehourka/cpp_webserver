#include "Common.hpp"

// #include "TcpListener.hpp"
#include "MultiClientChat.hpp"

int main(void)
{
	MultiClientChat mcc("0.0.0.0", 4242);
	if(mcc.init() != 0)
		return 1;

	mcc.run();
}
