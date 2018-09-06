#include "interfaces.h"
#include <string>

namespace ruff {
	struct Program : Node {
		Statement statements[];
		std::string TokenLiteral();
	}
}