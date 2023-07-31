#ifndef QTEXAMPLE_H
#define QTEXAMPLE_H


#include <QMainWindow>
#include <mpv/client.h>


class QTextEdit;
class OverlayWidget;
class OverlayLine;
class OverlayText;


class MainWindow : public QMainWindow
{
    Q_OBJECT


    QWidget *mpv_container;
    mpv_handle *mpv;

    QVector<OverlayWidget *> overlayWidgets;
    OverlayLine *overlayLine;
    OverlayText *overlayText;

    void handle_mpv_event(mpv_event *event);
    void open_video_file(const QString &filename);


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    bool event(QEvent *event);
    void resizeEvent(QResizeEvent *event);


private slots:
    void on_mpv_events();


signals:
    void mpv_events();
};


#endif // QTEXAMPLE_H
