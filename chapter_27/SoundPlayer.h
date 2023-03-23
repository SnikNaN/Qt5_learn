#pragma once
#include <QWidget>
#include <QMediaPlayer>
#include <QDial>

class QPushButton;
class QSlider;
class QLabel;
class QVBoxLayout;

// ======================================================================
class DialSpeed: public QDial
{
    Q_OBJECT
signals:
    void value_change(qreal);
public slots:
    void changed(int val)
    {
        emit value_change(qreal(val * 0.1f));
    }
public:
    DialSpeed(QWidget* pwgt = 0): QDial(pwgt) {};
};

class SoundPlayer : public QWidget {
    Q_OBJECT
protected:
    QMediaPlayer* m_pmp;
    QVBoxLayout*  m_pvbxMainLayout;

private:
    QPushButton*  m_pcmdPlay;
    QPushButton*  m_pcmdStop;
    QSlider*      m_psldPosition;
    QLabel*       m_plblCurrent;
    QLabel*       m_plblRemain;

    QString msecsToString(qint64 n);

public:
    SoundPlayer(QWidget* pwgt = 0);

private slots:
    void slotOpen             (                   );
    void slotPlay             (                   );
    void slotSetSliderPosition(qint64             );
    void slotSetMediaPosition (int                );
    void slotSetDuration      (qint64             );
    void slotStatusChanged    (QMediaPlayer::State);
};
