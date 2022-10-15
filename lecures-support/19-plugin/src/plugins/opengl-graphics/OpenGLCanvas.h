#pragma once

#include <ICanvas.h>

namespace sevenide::graphics2d::opengl
{

class OpenGLCanvas : public ICanvas
{
public:
    void drawRectangle(number x, number y, number width, number height) override;
    void drawRoundedRectangle(number x, number y, number width, number height) override;
    void drawEllipse(number x, number y, number verticalRadius, number horizontalRadius) override;
    void drawCircle(number x, number y, number radius) override;
    void drawText(number x, number y, const std::string& text) override;
    void drawLine(number x1, number y1, number x2, number y2) override;
    void drawImage(number x, number y, const IImage& image) override;

public:

};

} // namespace sevenide::graphics2d::opengl
