#ifndef JQLIBRARY_INCLUDE_JQCPUMONITOR_INC_
#define JQLIBRARY_INCLUDE_JQCPUMONITOR_INC_

// .h Headers
#include "cpumonitor.h"

inline QString JQCPUMonitor::cpuUsagePercentageDisplayString()
{
    return QString( "%1%" ).arg( static_cast< int >( cpuUsagePercentage() * 100 ) );
}

#endif//JQLIBRARY_INCLUDE_JQCPUMONITOR_INC_
