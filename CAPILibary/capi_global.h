#ifndef CAPI_GLOBAL_H
#define CAPI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CAPI_LIBRARY)
#  define CAPISHARED_EXPORT Q_DECL_EXPORT
#else
#  define CAPISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CAPI_GLOBAL_H
