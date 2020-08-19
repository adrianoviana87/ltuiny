#ifndef LTUI_NOEXCEPT_H
#define LTUI_NOEXCEPT_H

#ifdef __APPLE__
#define NOEXCEPT
#else
#define NOEXCEPT noexcept
#endif

#endif
