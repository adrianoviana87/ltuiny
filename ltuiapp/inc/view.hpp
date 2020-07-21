#ifndef _LTUI_VIEW_H_
#define _LTUI_VIEW_H_

namespace ltui
{
    struct view
    {
        void show();
        virtual ~view() noexcept = default;
    protected:
        virtual void on_show() = 0;
    };
} // namespace ltui

#endif