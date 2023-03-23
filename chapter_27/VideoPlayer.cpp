#include <QtWidgets>
#include <QVideoWidget>

#include "VideoPlayer.h"

// ----------------------------------------------------------------------
VideoPlayer::VideoPlayer(QWidget* pwgt/*=0*/) : SoundPlayer(pwgt)
{

    QVideoWidget* pvw = new QVideoWidget;
    pvw->setMinimumSize(300, 300);

    m_pvbxMainLayout->addWidget(pvw);    

    m_pmp->setVideoOutput(pvw);

//!!! workaround for different resolutions of QMediaPlayer & QVideoWidget
    connect(m_pmp, SIGNAL(stateChanged(QMediaPlayer::State)), 
            SLOT(slotStateChanged(QMediaPlayer::State)));
}

//!!! workaround for different resolutions of QMediaPlayer & QVideoWidget
// ----------------------------------------------------------------------
void 
VideoPlayer::slotStateChanged(QMediaPlayer::State st)
{
    if (st == QMediaPlayer::PlayingState) {
        resize(size() + QSize(1, 1));
        resize(size() - QSize(1, 1));
    }
}
