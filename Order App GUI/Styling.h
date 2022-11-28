#pragma once
#include <wx\wx.h>
#include <unordered_map>


enum class FontStyle {
	// Syntax: FontStyle::TITLE
	TITLE,
	BODY,
	BUTTON,
	HEADER
};

class Styling {
private:
	std::unordered_map<FontStyle, wxFont> fonts;
public:
	Styling();
	/**
	 * @brief Gets a font based on predefined styles.
	 * @param font Name of the style.
	 * @return Pointer to the font.
	*/
	wxFont* getFont(FontStyle font);
	/**
	 * @brief Shifts the element by the given amount.
	 * @param itm The element to shift.
	 * @param x 
	 * @param y 
	*/
	static void Translate(wxStaticText* itm, int x = 0, int y = 0);
	/**
	 * @brief Adjusts the font size and weight.
	 * @param itm The element to adjust the font for.
	 * @param font_size Size in points.
	 * @param weight 
	*/
	static void AdjustFontSize(wxStaticText* itm, int font_size = wxFONTSIZE_MEDIUM, wxFontWeight weight = wxFONTWEIGHT_NORMAL);
	/**
	 * @brief Adjust the font style and other attributes.
	 * @param itm The element to adjust the font for.
	 * @param style The style to use.
	 * @param underline If the text should be underlined.
	 * @param strike If the text should be struck through.
	 * @param family The font family to use.
	*/
	static void AdjustFontStyle(wxStaticText* itm, wxFontStyle style = wxFONTSTYLE_NORMAL, bool underline = false, bool strike = false, wxFontFamily family = wxFONTFAMILY_DEFAULT);
};

