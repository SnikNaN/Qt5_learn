#include <QOpenGLFunctions>
#include <QtGui>
#include "OGLPyramid.h"

// ----------------------------------------------------------------------
OGLPyramid::OGLPyramid(QWidget* pwgt/*= 0*/) : QOpenGLWidget(pwgt) 
                                             , m_xRotate(0)
                                             , m_yRotate(0)
{
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::initializeGL()
{
    QOpenGLFunctions* pFunc = 
        QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(0.5f, 0.5f, 0.5f, 0.0f);

    pFunc->glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    m_nPyramid = createPyramid(1.5f);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);

    glRotatef(m_xRotate, 1.0, 0.0, 0.0);
    glRotatef(m_yRotate, 0.0, 1.0, 0.0);

    glCallList(m_nPyramid);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::mousePressEvent(QMouseEvent* pe)
{
    m_ptPosition = pe->pos();
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::mouseMoveEvent(QMouseEvent* pe)
{
    m_xRotate += 180 * (GLfloat)(pe->y() - m_ptPosition.y()) / height();
    m_yRotate += 180 * (GLfloat)(pe->x() - m_ptPosition.x()) / width();
    update();

    m_ptPosition = pe->pos();
}

// ----------------------------------------------------------------------
GLuint OGLPyramid::createPyramid(GLfloat fSize/*=1.0f*/)
{
    GLuint n = glGenLists(1);

    glNewList(n, GL_COMPILE);
        glBegin(GL_TRIANGLE_FAN);
            glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
            glVertex3f(0.0, fSize, 0.0);
            glVertex3f(fSize, -fSize, 0);
            glVertex3f(0.7f * fSize, -fSize, -0.7f * fSize);

            glColor4f(1.0f, 1.0f, 0.0f, 0.5f);
            glVertex3f(0, -fSize, -fSize);

            glColor4f(1.0f, 0.0f, 1.0f, 0.5f);
            glVertex3f(-0.7f * fSize, -fSize, -0.7f * fSize);

            glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
            glVertex3f(-fSize, -fSize, 0);

            glColor4f(0.0f, 1.0f, 1.0f, 0.5f);
            glVertex3f(-0.7f * fSize, -fSize, 0.7f * fSize);

            glColor4f(0.5f, 1.0f, 0.5f, 0.5f);
            glVertex3f(0, -fSize, fSize);

            glColor4f(0.5f, 0.0f, 1.0f, 0.5f);
            glVertex3f(0.7f * fSize, -fSize, 0.7f * fSize);

            glColor4f(0.0f, 0.5f, 1.0f, 0.5f);
            glVertex3f(fSize, -fSize, 0);
        glEnd();
    
        glBegin(GL_POLYGON);
            glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
            glVertex3f(fSize, -fSize, 0);
            glVertex3f(0.7f * fSize, -fSize, -0.7f * fSize);
            glVertex3f(0, -fSize, -fSize);
            glVertex3f(-0.7f * fSize, -fSize, -0.7f * fSize);
            glVertex3f(-fSize, -fSize, 0);
            glVertex3f(-0.7f * fSize, -fSize, 0.7f * fSize);
            glVertex3f(0, -fSize, fSize);
            glVertex3f(0.7f * fSize, -fSize, 0.7f * fSize);
        glEnd();
    glEndList();

    return n;
}
