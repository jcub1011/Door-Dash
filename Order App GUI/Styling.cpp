#include "Styling.h"
#include <wx\wx.h>


Styling::Styling() {
	// Initializes the fonts. FontStyle enum class is found in the header file.
	this->fonts[FontStyle::TITLE] = wxFont(wxFontInfo(80).FaceName("Corbel").Bold());
	this->fonts[FontStyle::BODY] = wxFont(wxFontInfo(12).FaceName("Corbel"));
	this->fonts[FontStyle::BUTTON] = wxFont(wxFontInfo(12).FaceName("Corbel").Bold());
	this->fonts[FontStyle::HEADER] = wxFont(wxFontInfo(25).FaceName("Corbel").Bold());
}

wxFont* Styling::getFont(FontStyle font) {
	return &this->fonts[font];
}

void Styling::Translate(wxStaticText* itm, int x, int y) {
	wxPoint point = itm->GetPosition();
	point.x += x;
	point.y += y;
	itm->SetPosition(point);
}

void Styling::AdjustFontSize(wxStaticText* itm, int font_size, wxFontWeight weight) {
	wxFont font = itm->GetFont();
	font.SetPointSize(font_size);
	font.SetWeight(weight);
	itm->SetFont(font);
}

void Styling::AdjustFontStyle(wxStaticText* itm, wxFontStyle style, bool underline, bool strike, wxFontFamily family) {
	wxFont font = itm->GetFont();
	font.SetStyle(style);
	font.SetUnderlined(underline);
	font.SetStrikethrough(strike);
	font.SetFamily(family);
}
