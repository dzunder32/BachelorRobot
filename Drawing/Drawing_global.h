#ifndef DRAWING_GLOBAL_H
#define DRAWING_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DRAWING_LIBRARY)
#  define DRAWING_EXPORT Q_DECL_EXPORT
#else
#  define DRAWING_EXPORT Q_DECL_IMPORT
#endif

#endif // DRAWING_GLOBAL_H
