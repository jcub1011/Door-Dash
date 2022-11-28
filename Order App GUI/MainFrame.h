#pragma once
#include <wx\wx.h>
#include "Styling.h"

enum IDs {
	NEWORDER = 10,
	OLDORDER = 11
};

class MainFrame : public wxFrame {
private:
	wxFrame* _dummy;
	wxSize* _win_size;
	// Used to hide panels.
	Styling* _style = new Styling;
	// For Home
	wxPanel* _home_panel = nullptr;/*
	wxStaticText* _app_name = nullptr;
	wxButton* _new_order = nullptr;
	wxButton* _old_order = nullptr;*/
	void InitHome();
	void SwitchToHome();
	void StartNewOrder(wxCommandEvent& evt);
	// For Order Screen
	wxPanel* _order_panel = nullptr;/*
	wxStaticText* _restaurants_title = nullptr;
	wxStaticText* _menu_title = nullptr;
	wxStaticLine* _ver_sep = nullptr;*/
	void InitOrderScreen();
	void SwitchToOrder();
	void MacasPressed(wxCommandEvent& evt);
public:
	MainFrame(const wxString& title);
};

