#include "overlaywidget.h"


#include <QPoint>
#include <QPainter>


OverlayWidget::OverlayWidget(QWidget *parent)
    : QWidget(parent)
    , m_originOffset(QPoint(0, 0))
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);

    setAttribute(Qt::WA_TransparentForMouseEvents);
}


OverlayWidget::OverlayWidget(OverlayWidget&& wgt)
    : m_originOffset(wgt.m_originOffset)
{
    wgt.destroy();
}


OverlayWidget::OverlayWidget(const OverlayWidget &wgt)
    : m_originOffset(wgt.m_originOffset)
{}


OverlayWidget::OverlayWidget(const QPoint &originOffset, QWidget *parent)
    : OverlayWidget(parent)
{
    m_originOffset = originOffset;
}

OverlayWidget::OverlayWidget(int offset_x, int offset_y, QWidget *parent)
    : OverlayWidget(parent)
{
    m_originOffset = QPoint(offset_x, offset_y);
}


void OverlayWidget::widgetResizeMove(QWidget *origin)
{
    if (this->width() <= origin->width() && this->height() <= origin->height()) {
        this->setWindowOpacity(1);

        QPoint originPos = origin->mapToGlobal(origin->pos());

        this->move(originPos.x() + m_originOffset.x(), originPos.y() + m_originOffset.y());

        this->raise();
    }
    else {
        this->setWindowOpacity(0);
    }
}
