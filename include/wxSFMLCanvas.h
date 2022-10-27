#pragma once
#include <SFML/Graphics.hpp>
#include <wx/wx.h>
#ifdef __WXGTK__
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#endif
#include <functional>

enum class wxSFMLCanvasID {
    ID_Resize = 1,
};

class wxSFMLCanvas : public wxControl, public sf::RenderWindow
{
public:

    wxSFMLCanvas(wxWindow* Parent = NULL, wxWindowID Id = -1, const wxPoint& Position = wxDefaultPosition,
        const wxSize& Size = wxDefaultSize, long Style = 0);

    virtual ~wxSFMLCanvas() {};

private:
    DECLARE_EVENT_TABLE();
    virtual void OnUpdate() {};
    void OnIdle(wxIdleEvent&);
    void OnPaint(wxPaintEvent&);
    void OnSize(wxSizeEvent& args);
    void OnEraseBackground(wxEraseEvent&);
};