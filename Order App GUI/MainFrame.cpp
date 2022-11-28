#include "MainFrame.h"
#include <wx\wx.h>
#include "Styling.h"
#include <wx\statline.h>
#include <wx\sizer.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title, wxPoint(400, 200), wxSize(1000, 800)) {
	CreateStatusBar();
	_win_size = new wxSize(this->GetSize());
	_dummy = new wxFrame(this, wxID_ANY, "DUMMY", wxPoint(0,0), wxSize(1,1));
	_dummy->Hide();
	InitHome();
	InitOrderScreen();
	// Show
	this->Show();
	SwitchToHome();
}

void MainFrame::StartNewOrder(wxCommandEvent& evt) {
	wxLogStatus("Starting new order.");
	_home_panel->Hide();
	SwitchToOrder();
}

void MainFrame::InitHome() {
	// Consts
	const int PADDING_TOP = 50;
	// Initialization
	_home_panel = new wxPanel(_dummy, wxID_ANY, wxDefaultPosition, *_win_size);
	auto app_name = new wxStaticText(_home_panel, wxID_ANY, "Order App", wxPoint(-1, -1),
		wxSize(this->GetSize().GetWidth(), -1), wxALIGN_CENTER_HORIZONTAL);
	auto new_order = new wxButton(_home_panel, IDs::NEWORDER, "Start New Order", wxPoint(200, 400),
		wxSize(150, 50));
	auto old_order = new wxButton(_home_panel, wxID_ANY, "View Old Orders", wxPoint(650, 400),
		wxSize(150, 50));
	// Font adjustment
	app_name->SetFont(*_style->getFont(FontStyle::TITLE));
	new_order->SetFont(*_style->getFont(FontStyle::BUTTON));
	old_order->SetFont(*_style->getFont(FontStyle::BUTTON));
	// Padding
	Styling::Translate(app_name, 0, PADDING_TOP);
	// Binds
	new_order->Bind(wxEVT_BUTTON, &MainFrame::StartNewOrder, this);


	_home_panel->Hide();
}

void MainFrame::SwitchToHome() {
	wxLogStatus("Switched to home.");
	_order_panel->Reparent(_dummy);
	_order_panel->Hide();
	_home_panel->Reparent(this);
	_home_panel->Show();
	_home_panel->Refresh();
}

void MainFrame::InitOrderScreen() {
	// Consts
	const int PADDING_TOP = 20;
	// Inits
	_order_panel = new wxPanel(_dummy, wxID_ANY, wxDefaultPosition, *_win_size);
	auto restaurants_title = new wxStaticText(_order_panel, wxID_ANY, "Restaurants", wxPoint(20, PADDING_TOP));
	restaurants_title->SetFont(*_style->getFont(FontStyle::HEADER));
	auto menu_title = new wxStaticText(_order_panel, wxID_ANY, "Menu", wxPoint(350, PADDING_TOP));
	menu_title->SetFont(*_style->getFont(FontStyle::HEADER));
	auto ver_sep = new wxStaticLine(_order_panel, wxID_ANY, wxPoint(320, 0), wxSize(2, _win_size->GetHeight()), wxLI_VERTICAL);
	auto macas = new wxButton(_order_panel, wxID_ANY, "Macas", wxPoint(20, 70));
	auto macas_desc = new wxStaticText(_order_panel, wxID_ANY, 
		"Macas is a popular fast food joint best \nknown for their burgers, nuggets, and fries.", 
		wxPoint(20, 100));
	// Fonts
	macas->SetFont(*_style->getFont(FontStyle::BUTTON));
	macas_desc->SetFont(*_style->getFont(FontStyle::BODY));
	// Binds
	macas->Bind(wxEVT_BUTTON, &MainFrame::MacasPressed, this);

	_order_panel->Hide();
}

void MainFrame::SwitchToOrder() {
	wxLogStatus("Switched to order screen.");
	_home_panel->Reparent(_dummy);
	_home_panel->Hide();
	_order_panel->Reparent(this);
	_order_panel->Show();
	_order_panel->Refresh();
}

void MainFrame::MacasPressed(wxCommandEvent& evt) {
	wxLogStatus("Macas was selected.");
}