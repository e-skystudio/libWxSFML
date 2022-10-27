#include "../include/wxSFMLCanvas.h"

void wxSFMLCanvas::OnIdle(wxIdleEvent& ev)
{
    OnUpdate();
    display();
    ev.RequestMore(true);
}

void wxSFMLCanvas::OnEraseBackground(wxEraseEvent&)
{
}

void wxSFMLCanvas::OnPaint(wxPaintEvent&)
{
    wxPaintDC Dc(this);
    OnUpdate();
    display();
}

void wxSFMLCanvas::OnSize(wxSizeEvent& args)
{
    setSize(sf::Vector2u(args.GetSize().x, args.GetSize().y));
    setView(sf::View(sf::FloatRect(0, 0, args.GetSize().x, args.GetSize().y)));
}

wxSFMLCanvas::wxSFMLCanvas(wxWindow* Parent, wxWindowID Id, const wxPoint& Position, const wxSize& Size, long Style) :
    wxControl(Parent, Id, Position, Size, Style)
{
#ifdef __WXGTK__
    gtk_widget_realize(m_wxwindow);
    GdkWindow* Win = gtk_widget_get_window((GtkWidget*)GetHandle());
    XFlush(GDK_WINDOW_XDISPLAY(Win));
    sf::RenderWindow::create(GDK_WINDOW_XID(Win));
#else
    sf::RenderWindow::create(GetHandle());
    //Bind(wxEVT_SIZE, &wxSFMLCanvas::OnSize, this, (int)wxSFMLCanvasID::ID_Resize);
#endif
    setFramerateLimit(60);
}

BEGIN_EVENT_TABLE(wxSFMLCanvas, wxControl)
EVT_IDLE(wxSFMLCanvas::OnIdle)
EVT_PAINT(wxSFMLCanvas::OnPaint)
EVT_ERASE_BACKGROUND(wxSFMLCanvas::OnEraseBackground)
EVT_SIZE(wxSFMLCanvas::OnSize)
END_EVENT_TABLE()