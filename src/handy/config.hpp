
#pragma once

#include <cstdlib>

#define BQ_ABORT(MSG) do{ fprintf(stderr, MSG); std::abort(); } while(0)

#define BQ_ASSERT(TEST) if (!(TEST)) BQ_ABORT(#TEST " failed. ")

