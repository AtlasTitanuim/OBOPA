// InDeLes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Widget.h"
#include "InputWidget.h"
#include "TextWidget.h"
#include "BorderDecorator.h"


int main()
{
	Widget* plainWidget = new InputWidget();
	plainWidget->draw();

	Widget* bordered = new BorderDecorator(plainWidget);
	bordered->draw();

	return 0
}
