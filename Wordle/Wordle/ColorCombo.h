#pragma once
#include "Color.h";

struct ColorCobmo
{
public :
	ColorCobmo()
	{
		fColor = ForegroundColor::Red;
		bColor = BackgroundColor::Red;
	}
	ColorCobmo(ForegroundColor inFColor, BackgroundColor inBColor) 
	{
		fColor = inFColor;
		bColor = inBColor;
	}
	ForegroundColor fColor;
	BackgroundColor bColor;
};